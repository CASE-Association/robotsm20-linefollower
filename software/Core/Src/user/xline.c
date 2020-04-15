#include "user/xline.h"
#include "main.h"
#include <stdio.h>

extern ADC_HandleTypeDef hadc2;
uint32_t calibrated_max[_num_sensors];
uint32_t calibrated_min[_num_sensors];
uint32_t xline[16];


/**
 * @brief Initialize xline sensors.
 * 
 */
void init_xline(){
	xline_reset_calibration();
}


/**
 * @brief Calibrate sensors by storing maximum and minimum values found in order to provide calibrated data when using xline_read_calibrated().
 * Reads the sensors 10 times and uses the results for calibration. The sensor values are not returned; instead, the maximum and minimum values 
 * found over time are stored internally and used for the xline_read_calibrated() method.
 * 
 * In order to calibrate, call this function repeatedly under a couple seconds (~5s) when moving the sensor over a line.
 */
void xline_calibrate(void){
	//uint32_t sensor_values[_num_sensors] = {0};
	uint32_t max_sensor_values[_num_sensors] = {0};
	uint32_t min_sensor_values[_num_sensors] = {0};

    
	for(uint8_t j = 0; j < 10; j++){
		xline_read();

		for(uint8_t i = 0; i < _num_sensors; i++){
			// set the min we found THIS time
			if(j == 0 || min_sensor_values[i] > xline[i])
				min_sensor_values[i] = xline[i];

			// set the max we found THIS time
			if(j == 0 || max_sensor_values[i] < xline[i])
				max_sensor_values[i] = xline[i];
		}
	}

	// Save the min and max calibration values
	for(uint8_t i = 0 ; i < _num_sensors; i++){
		if(min_sensor_values[i] > calibrated_max[i])
			calibrated_max[i] = min_sensor_values[i];

		if(max_sensor_values[i] < calibrated_min[i])
			calibrated_min[i] = max_sensor_values[i];
	}
}

/**
 * @brief Runs full 5s calibration sequence and print result
 *
 * Calibrates be successively calling xline_calibrate over a 5s period
 * Then prints all min/max recorded values for the user.
 */
void xline_calibration_sequence(void){
	printf("============ CALIBRATING XLINE ==============\r\n");
	printf("\t - Calibrating over 5S\r\n");
	printf("\t - Move the sensor over the line back and forth with a reasonable speed.\r\n");
	for(uint8_t i = 0; i < 100; i++){
		xline_calibrate();
		HAL_Delay(50);
	}
	printf("================ CALIBRATION COMPLETE =============\r\n");
	for(uint8_t i = 0; i < 16; i++){
			printf("Sensor %d: \r\n\t min: %lu\r\n\t max: %lu\r\n", i, calibrated_min[i], calibrated_max[i]);
	}
}



/**
 * @brief Reset calibration values.
 * 
 */
void xline_reset_calibration(void){
    for(uint8_t i = 0 ; i < _num_sensors; i++){
        calibrated_min[i] = 1023;
        calibrated_max[i] = 0;
    }
}


/**
 * @brief Read all sensors and store raw values in supplied array.
 * 
 * @param sensor_values Array to store values. The size needs to be equal or bigger than number of sensors.
 */
void xline_read(void){
    // Reset old values
    for(uint8_t i = 0 ; i < _num_sensors; i++){
        xline[i] = 0;
    }


	for(uint8_t i = 0 ; i < _num_sensors; i++){
		xline_mux_select(i);
       
		HAL_ADC_Start(&hadc2);
		HAL_ADC_PollForConversion(&hadc2, 5);
		uint32_t raw = HAL_ADC_GetValue(&hadc2);
		xline[i] = raw;
		HAL_ADC_Stop(&hadc2);
	}
}

/**
 * @brief Read all sensors and store calibrated values in supplied array.
 * 
 * Returns values calibrated to a value between 0 and 1000, where
 * 0 corresponds to the minimum value read by xline_calibrate() and 1000
 * corresponds to the maximum value.  Calibration values are
 * stored separately for each sensor, so that differences in the
 * sensors are accounted for automatically.
 * @param sensor_values Array to store values.
 */
void xline_read_calibrated(void){
	xline_read();

	for(uint8_t i = 0 ; i < _num_sensors; i++){

		uint32_t denominator = calibrated_max[i] - calibrated_min[i];

		int x = 0;
		if(denominator != 0)
			// Check the real reason for need to cast all to int
			x = ((int)( ((int)xline[i]) - ((int)calibrated_min[i]))) * 1000 / (int)denominator;
		if(x < 0)
			x = 0;
		else if(x > 1000)
			x = 1000;
		// Add additional check when sensor is blocked
		xline[i] = x;
	}
}


/**
 * @brief Reads with calibrated sensor data and estimates position with respect to a black line on white surface. 
 *  
 * The estimate is made using a weighted average.
 * The return value is in the range of 0 to 1000*(N-1)
 * E.g 16 sensors => 0 to 15000 and the line beeing in the center when 7500. 
 * The value is continous and remain at the latest value when leaving a line.
 * E.g Robot drifts away from the line and the rightmost sensor leaving the latest will result in 4500 beeing returned.
 * 
 * The formula is:
 * 
 * 		 0*value0 + 1000*value1 + 2000*value2 + ...
 * 		--------------------------------------------
 * 		     value0  +  value1  +  value2 + ...
 * 
 * @param sensor_values 
 * @return int Estimated position
 */
int xline_read_line(void){
	uint8_t i, on_line = 0;
	unsigned long avg = 0; // weighted total
	unsigned int sum = 0; // this is for the denominator which is <= 64000
	static int last_value = 0; // assume initially that the line is left.
	int return_val = 0;


	xline_read_calibrated();

	for( i = 0; i < _num_sensors; i++) {
		int value = xline[i];
		//if(white_line)
		//	value = 1000 - value;

		// keep track of whether we see the line at all
		if(value > 200) {
			on_line = 1;
		}
		
		// only average in values that are above a noise threshold
		if(value > 50) {
			avg += (long)(value) * (i * 1000);
			sum += value;
		}
	}

	if(!on_line)
	{
		// If it last read to the left of center, return 0.
		if(last_value < (_num_sensors - 1) *1000 /2)
			return_val = 0;
		
		// If it last read to the right of center, return the max.
		else
			return_val = (_num_sensors - 1)*1000;

	}else{
		last_value = avg/sum;
		return_val = last_value;
	}



	return return_val - (16-1)/2.0f * 1000;
};



/**
 * @brief Selecting which sensor to read from via the MUX. (Multiplexer)
 * 
 * @param sensor_n Sensor to active.
 */
void xline_mux_select(uint8_t sensor){
    HAL_GPIO_WritePin(MUX0_GPIO_Port, MUX0_Pin, (sensor & 0b1) > 0);
    HAL_GPIO_WritePin(MUX1_GPIO_Port, MUX1_Pin, (sensor & 0b10) > 0);
    HAL_GPIO_WritePin(MUX2_GPIO_Port, MUX2_Pin, (sensor & 0b100) > 0);
    HAL_GPIO_WritePin(MUX3_GPIO_Port, MUX3_Pin, (sensor & 0b1000) > 0);
};

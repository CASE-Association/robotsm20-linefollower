#include "xline.h"

#include <stdint.h>



uint8_t samples_per_second;


/**
 * @brief Initialize xline sensors.
 * 
 * @param samp_per_sec Number of samples per measurement.
 */
void xline_init(uint8_t samp_per_sec){};



/**
 * @brief Turn off all emitters.  
 * 
 * Done by switcing supply voltage off via mosfet.
 * Save energy when sensors are not needed.
 */
void xline_emitters_off(){};



/**
 * @brief Turn on all emiitters.
 * 
 * Done by switcing supply voltage on via mosfet.
 */
void xline_emitters_on(){};



/**
 * @brief Calibrate sensors to by storing maximum and minimum values found when calibrating in order to provide better data when using xline_read_calibrated().
 * 
 */
void xline_calibrate(){};



/**
 * @brief Reset calibration values.
 * 
 */
void xline_reset_calibration(){};


/**
 * @brief Read all sensors and store raw values in supplied array.
 * 
 * @param sensor_values Array to store values. The size needs to be equal or bigger than number of sensors.
 */
void xline_read(uint16_t *sensor_values){};



/**
 * @brief Reads with calibrated sensors and estimates position with respect to a line. 
 *  
 * The estimate is made using a weighted average of the sensor indices multiplied with 1000.
 * The value is in the range of +- 1000*(N-1)/2 where positiv meaning the line is on the right. 
 * E.g 10 sensors => +- 4500 and the line beeing in the center when 0. 
 * The value is continous and remain at the latest value when leaving a line.
 * E.g Robot drifts away from the line and the rightmost sensor leaving the latest will result in 4500 beeing returned.
 * @param sensor_values 
 * @return int Estimated position
 */
int xline_read_line(uint16_t *sensor_values){};



/**
 * @brief Private method for selecting the input via the MUX. (Multiplexer)
 * 
 * @param sensor_n Sensor number to active.
 */
void _mux_select(uint8_t sensor_n){};
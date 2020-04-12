#include <user/voltmeter.h>
#include "user/oled.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>


extern ADC_HandleTypeDef hadc1;

#define SAMPLES 16		// Number of samples to average
#define NR 2					// Number of ADC channels

uint8_t adc_raw[NR*SAMPLES];																	// Array for raw adc samples
uint8_t nr_indices = (sizeof(adc_raw) / sizeof(adc_raw[0]));	// Number or indices in the raw adc array

void init_voltmeter(void){
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *) adc_raw, nr_indices);
}

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

uint8_t adc_average(uint8_t index){
	// This can be improved by sorting raw values first and then removing a couple of the highest and lowest readings
	// However after inspection the ADC values seem very stable and this is not needed.
	uint8_t average = 0;
	uint32_t sum = 0;

	for(int i = index; i < NR*SAMPLES; i += NR){
		sum += adc_raw[i];
	}

	average = sum / SAMPLES;
	return average;
}


float adc_to_voltage(uint8_t adc_value, uint32_t R1, uint32_t R2){
	//1. Calculate the voltage between R2 and ground (V_out), (reading / resolution) * V_ref
	//2. Calculate actual voltage (V_in) with the voltage divider. (V_out = V_in * R2/(R1 + R2) or (V_in = V_out * (R1 + R2) / R2
	return (adc_value / 256.0f) * 3.3f * (R1 + R2) / (float)R2;

}


float GET_voltage_battery(void){
	return adc_to_voltage(adc_average(1), 20000, 10000);
}


float GET_voltage_boost(void){
	return adc_to_voltage(adc_average(0), 62000, 10000);

}


battery_status_t GET_battery_status(void){
	battery_status_t status = BATTERY_OK;

	if(GET_voltage_battery() > 8.4f){
		oled_error("OVER VOLTAGE");
		status = BATTERY_OVER_VOLTAGE;
	}else if(GET_voltage_battery() < 6.4f){
		oled_error("LOW VOLTAGE");
		status = BATTERY_LOW_VOLTAGE;
	}
	return status;
}




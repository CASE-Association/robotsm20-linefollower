#ifndef VOLTMETER_H
#define VOLTMETER_H

#include "main.h"

typedef enum{
	BATTERY_OK = 0,
	BATTERY_LOW_VOLTAGE = 1,
	BATTERY_OVER_VOLTAGE = 2,
} battery_status_t;

void init_voltmeter(void);
uint8_t adc_average(uint8_t index);
float adc_to_voltage(uint8_t adc_value, uint32_t R1, uint32_t R2);
float GET_voltage_battery(void);
float GET_voltage_boost(void);

battery_status_t GET_battery_status(void);


#endif // VOLTMETER_H

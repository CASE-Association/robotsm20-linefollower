#ifndef XLINE_H
#define XLINE_H

#include <stdint.h>

uint8_t samples_per_second;


// Reads the sensor values into an array.

void xline_init(uint8_t samp_per_sec);
void xline_emitters_off();
void xline_emitters_on();
void xline_calibrate();
void xline_reset_calibration();
void xline_read(uint16_t *sensor_values);
int xline_read_line(uint16_t *sensor_values);

void mux_select(uint8_t sensor_n);



#endif

#ifndef XLINE_H
#define XLINE_H

#include <stdint.h>

#define _num_sensors 16
#define _samples_per_sensor 5

extern uint32_t xline[16];

// Make public for anyone to sanity check
extern uint32_t calibrated_max[_num_sensors];
extern uint32_t calibrated_min[_num_sensors];

void init_xline();
void xline_calibrate();
void xline_calibration_sequence();
void xline_reset_calibration();
void xline_read(uint32_t *sensor_values);
void xline_read_calibrated(uint32_t *sensor_values);
int xline_read_line(uint32_t *sensor_values);
void xline_mux_select(uint8_t sensor);

#endif

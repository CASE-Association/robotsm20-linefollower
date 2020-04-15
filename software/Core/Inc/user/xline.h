#ifndef XLINE_H
#define XLINE_H

#include <stdint.h>

#define _num_sensors 16
#define _samples_per_sensor 5

extern uint32_t xline[16];

// Make public for anyone to sanity check
extern uint32_t calibrated_max[_num_sensors];
extern uint32_t calibrated_min[_num_sensors];

void init_xline(void);
void xline_calibrate(void);
void xline_calibration_sequence(void);
void xline_reset_calibration(void);
void xline_read(void);
void xline_read_calibrated(void);
int xline_read_line(void);
void xline_mux_select(uint8_t sensor);

#endif

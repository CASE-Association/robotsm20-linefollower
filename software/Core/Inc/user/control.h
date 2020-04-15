#ifndef CONTROL_H
#define CONTROL_H

extern int control_loop_enabled;

int speed_to_counts(float speed);
float counts_to_speed(int counts);


void control_loop_enable(void);
void control_loop_disable(void);
void control_loop(void);
void encoder_update(void);


#endif //CONTROL_H

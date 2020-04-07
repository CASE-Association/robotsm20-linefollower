#ifndef MOTOR_H
#define MOTOR_H

void init_motors(void);
int limit_speed(int speed);
void motor_l_set_speed(int speed);
void motor_r_set_speed(int speed);
void motors_stop(void);

void test_motors(void);

#endif //MOTOR_H

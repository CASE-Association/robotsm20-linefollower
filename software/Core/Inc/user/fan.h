#ifndef FAN_H
#define FAN_H

void init_fans(void);
void test_fan(void);
int fan_limit_speed(int speed);
int fan_convert_speed(int speed);
void fan_r_set_speed(int speed);
void fan_l_set_speed(int speed);


#endif //FAN_H

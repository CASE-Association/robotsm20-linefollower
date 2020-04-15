#include "user/control.h"
#include "user/motor.h"
#include "user/xline.h"
#include "main.h"



/***************************** STATE VARIABLES **********************************/
int control_loop_enabled = 0;
int base_speed = 80;
float Kp = 0.013;
/*
int target_speed_x;
int target_speed_w;

int encoder_l;
int encoder_r;
int encoder_l_old;
int encoder_r_old;
*/
/*
int speed_to_counts(float speed){
	return 0;
}
float counts_to_speed(counts){
	return 0;
}

*/

void control_loop_enable(void){
	control_loop_enabled = 1;
}


void control_loop_disable(void){
	motors_stop();
	control_loop_enabled = 0;
}



void control_loop(void){
	if(!control_loop_enabled){
		return;
	}

	// The most basic control loop one can think of
	int error = xline_read_line();

	int speed = Kp*error;

	int left_speed = base_speed - speed;
	int right_speed = base_speed + speed;

	motor_l_set_speed(left_speed);
	motor_r_set_speed(right_speed);
}

/*
void encoder_update(void){

}
*/

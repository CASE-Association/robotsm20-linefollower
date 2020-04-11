#include "user/fan.h"
#include "main.h"


extern TIM_HandleTypeDef htim3;


/**
 * Initialize fans by starting PWM timers and running startup sequence required by the ESCs.
 */
void init_fans(void){
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2); // Right
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1); // Left

	// Startup sequence
	// 1. Start arming by applying a OK signal
	// 2. Finish arming by applying 0 throttle

	TIM3->CCR2 = 1600;
	TIM3->CCR1 = 1600;
	HAL_Delay(3000);

	TIM3->CCR2 = 1500;
	TIM3->CCR1 = 1500;
}

/**
 * Test fans by spinning them and showing directions with LED. Forward = green, Backwards = red
 * 1. Left forward, wait 1s, left backwards, wait 1s.
 * 2. Right forward, wait 1s, right backwards, wait 1s.
 */
void test_fan(void){
	//Left forward
	fan_l_set_speed(10);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);

	//Wait 1s
	fan_l_set_speed(0);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
	HAL_Delay(1000);

	//Left backwards
	fan_l_set_speed(-10);
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);

	//Wait 1s
	fan_l_set_speed(0);
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
	HAL_Delay(1000);




	//Right forward
	fan_r_set_speed(10);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);

	//Wait 1s
	fan_r_set_speed(0);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
	HAL_Delay(1000);

	//Right backwards
	fan_r_set_speed(-10);
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);

	//Wait 1s
	fan_r_set_speed(0);
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
	HAL_Delay(1000);
}

/**
 * Limit speed between [-100,100] (%)
 *
 * @param int speed - Unlimited speed
 *
 * @return int - Limited speed
 */
int fan_limit_speed(int speed){
	if(speed > 100)
		speed = 100;
	if(speed < -100)
		speed = -100;
	return speed;
}

/**
 * Converts a speed from [-100,100] to timer parameter
 * The output range is between [1000, 2000] (uS)
 *
 * @param int speed - Desired speed
 *
 * @return int - Scaled timer value
 */
int fan_convert_speed(int speed){
	return 1500 + speed * 5;
}

/**
 * Set right fan speed between [-100,100] (%)
 *
 * @param int speed - Desired fan speed
 */
void fan_r_set_speed(int speed){
	int limited_speed = fan_limit_speed(speed);
	int CCR_val = fan_convert_speed(limited_speed);
	TIM3->CCR2 = CCR_val;
}

/**
 * Set left fan speed between [-100,100] (%)
 *
 * @param int speed - Desired fan speed
 */
void fan_l_set_speed(int speed){
	int limited_speed = fan_limit_speed(speed);
	int CCR_val = fan_convert_speed(limited_speed);
	TIM3->CCR1 = CCR_val;
}


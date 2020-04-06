#include "motor.h"
#include "tim.h"

void init_motors(void){
    // Start encoder inputs
    HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL); // Right
    HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL); // Left

    // Start PWM generation for motors
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_3); // Right
    HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_4); // Left

    // Put both motors in Hi-Z (high impedance output => rotate freely)
    motors_stop();
}

int limit_speed(int speed){
    if(speed > 1000){
        speed = 1000;
    }else if(speed < -1000){
        speed = -1000;
    }
    return speed;
}


void motor_l_set_speed(int speed){
    int limited_speed = limit_speed(speed);

    if(limited_speed < 0){
        limited_speed = -limited_speed;
        HAL_GPIO_WritePin(MOTOR_L_IN1_GPIO_Port, MOTOR_L_IN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(MOTOR_L_IN2_GPIO_Port, MOTOR_L_IN2_Pin, GPIO_PIN_RESET);
    }else{
        HAL_GPIO_WritePin(MOTOR_L_IN1_GPIO_Port, MOTOR_L_IN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MOTOR_L_IN2_GPIO_Port, MOTOR_L_IN2_Pin, GPIO_PIN_SET);
    }

    TIM4->CCR4 = limited_speed;
}

void motor_r_set_speed(int speed){
    int limited_speed = limit_speed(speed);

    if(limited_speed < 0){
        limited_speed = -limited_speed;
        HAL_GPIO_WritePin(MOTOR_R_IN1_GPIO_Port, MOTOR_R_IN1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(MOTOR_R_IN2_GPIO_Port, MOTOR_R_IN2_Pin, GPIO_PIN_SET);
        
    }else{   
        HAL_GPIO_WritePin(MOTOR_R_IN1_GPIO_Port, MOTOR_R_IN1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(MOTOR_R_IN2_GPIO_Port, MOTOR_R_IN2_Pin, GPIO_PIN_RESET);
    }

    TIM4->CCR3 = limited_speed;
}

void motors_stop(void){
    TIM4->CCR3 = 0;
    HAL_GPIO_WritePin(MOTOR_R_IN1_GPIO_Port, MOTOR_R_IN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_R_IN2_GPIO_Port, MOTOR_R_IN2_Pin, GPIO_PIN_RESET);

    TIM4->CCR4 = 0;
    HAL_GPIO_WritePin(MOTOR_L_IN1_GPIO_Port, MOTOR_L_IN1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(MOTOR_L_IN2_GPIO_Port, MOTOR_L_IN2_Pin, GPIO_PIN_RESET);
};


void test_motors(void){
    for(int i = 0; i <= 300; i = i + 5){
        motor_l_set_speed(i);
        motor_r_set_speed(i);
        HAL_Delay(50);
    }
    for(int i = 300; i >= 0; i = i - 5){
        motor_l_set_speed(i);
        motor_r_set_speed(i);
        HAL_Delay(50);
    }
    
}
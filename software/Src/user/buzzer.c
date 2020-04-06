#include "user/buzzer.h"
#include "tim.h"


void init_buzzer(void){
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

void beep(int duration){
    if(duration > 1000)
        duration = 1000;
    if(duration < 0)
        duration = 0;

    TIM4->CCR4 = 100;
    HAL_Delay(duration);
    TIM4->CCR4 = 0;
}

void test_buzzer(void){
    beep(80);
    HAL_Delay(80);

    beep(80);
    HAL_Delay(80);
}
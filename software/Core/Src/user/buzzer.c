#include "user/buzzer.h"
#include "main.h"
#include <stdlib.h>

extern TIM_HandleTypeDef htim1;



// change this to make the song slower or faster
int tempo = 144;

// notes of the melody followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {

  //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

  NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
  NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

  NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
  NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
  NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
  NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,


  NOTE_E5,2,  NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,2,   NOTE_A4,2,
  NOTE_GS4,2,  NOTE_B4,4,  REST,8,
  NOTE_E5,2,   NOTE_C5,2,
  NOTE_D5,2,   NOTE_B4,2,
  NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
  NOTE_GS5,2,

};


void init_buzzer(void){
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

void beep(int duration){
    if(duration > 1000)
        duration = 1000;
    if(duration < 0)
        duration = 0;

    TIM1->CCR4 = 200;
    HAL_Delay(duration);
    TIM1->CCR4 = 0;
}

/**
 * Plays a frequency for a duration
 *
 * @param int frequency - Hertz [Hz] (MAX 16kHz)
 * @param int duration - miliseconds [ms]
 */
void tone(int frequency, int duration){
	//Check for devision by 0
	if(frequency == 0){
		HAL_Delay(duration);
		return;
	}

	//Calculate prescaler value
	int prescalar = 16000000 / 1000 / frequency;
	TIM1->PSC = prescalar;

	//Play tone
	TIM1->CCR4 = 200;
	int k = prescalar % 6;
	if(k <= 1)
		HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);
	if(k > 1 && k <= 3)
		HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin);
	if(k >= 4)
		HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin);
	HAL_Delay(duration);
	TIM1->CCR4 = 0;

	//Base prescalar
	TIM1->PSC = 4;
}

void play_song(void){
	// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
	// there are two values per note (pitch and duration), so for each note there are four bytes
	int notes=sizeof(melody)/sizeof(melody[0])/2;

	// this calculates the duration of a whole note in ms (60s/tempo)*4 beats
	int wholenote = (60000 * 4) / tempo;
	wholenote = wholenote / 3 * 2;

	int divider = 0, noteDuration = 0;

	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

	    // calculates the duration of each note
	    divider = melody[thisNote + 1];
	    if (divider > 0) {
	      // regular note, just proceed
	      noteDuration = (wholenote) / divider;
	    } else if (divider < 0) {
	      // dotted notes are represented with negative durations!!
	      noteDuration = (wholenote) / abs(divider);
	      noteDuration *= 1.5; // increases the duration in half for dotted notes
	    }

	    // we only play the note for 90% of the duration, leaving 10% as a pause
	    tone(melody[thisNote], noteDuration*0.9);

	    // Wait for the specified duration before playing the next note.
	    HAL_Delay(noteDuration);
	  }
}

void test_buzzer(void){
    beep(50);
    HAL_Delay(50);

    beep(50);
    HAL_Delay(50);
}

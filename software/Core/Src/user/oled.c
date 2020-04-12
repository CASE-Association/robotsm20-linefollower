/**
 * @file oled.c
 * @author Isak Åslund (aslundisak@gmail.com)
 * @brief High level driver for creating and interacting with oled screen
 * @version 0.1
 * @date 2020-04-13
 */

#include "user/oled.h"
#include "user/ssd1306.h"
#include "user/bitmaps.h"
#include "user/buzzer.h"
#include "user/voltmeter.h"
#include "user/xline.h"
#include "user/motor.h"

#include "main.h"

#include <stdio.h>
#include <string.h>

struct menu_item{
	char name[20];												// Menu item display name
	void (*callback)(menu_item_t *self);	// Button press callback on item
	int *pvar;														// Associated variable with item (optional, E.g Kp, Volume etc)
	struct menu_item * pNext;							// Next item
};

typedef struct menu{
    char name[20];									// Menu display name
    struct menu_item * head_item; 	// First menu item of menu (Only menus with items has this parameter)
    struct menu * pNext; 						// Next menu item (E.g Main->SubMenu1->SubMenu2->SubMenu3->NULL)
}menu_t;

// Enumeration for what to render
typedef enum {
	ERROR_ = 0,
	MENU = 1,
	INFO = 2,
	IMAGE = 3,
	EDIT_VAR = 4,
	MESSAGE = 5,
	NOT_IMPLEMENTED = 404
} OLED_SCREEN;

typedef enum {
	TESTS = 0,
	CALIBRATION = 1
}global_function_t;


/***************************** STATE VARIABLES **********************************/
OLED_SCREEN active_screen;					// Current screen
global_function_t global_func;			// Global function to run
int button_pressed_flag = 0;				// Flag for when button is pressed
int go_back_main_flag = 0;					// Flag for going back to main menu
const unsigned char * curr_image;		// Current image to be shown
char *error_message;								// Current error message
char *disp_message;								  // Current display message
uint8_t cursor = 0;									// Cursor index
menu_item_t *edit_var;							// Pointer to current editable variable

// Test variables for showing edit_var functionality
// Remove later
int kp_test = 15;
int ki_test = 5;


/******************************* MENUS ****************************************/
menu_t * curr_submenu = NULL;
menu_t * prev_submenu = NULL;
menu_t main_menu;

menu_t sub_menu_1;
menu_item_t menu_item_back_main;

menu_item_t menu_item_11;
menu_item_t menu_item_12;
menu_item_t menu_item_13;


menu_t sub_menu_2;
menu_item_t menu_item_21;
menu_item_t menu_item_22;
menu_item_t menu_item_23;


menu_t sub_menu_3;
menu_item_t menu_item_31;
menu_item_t menu_item_32;


/****************************** FUNCTIONS **********************************/

/**
 * @brief Calculate number of items in current menu
 *
 * @return uint8_t - Number of items in current menu
 */
uint8_t oled_nr_items(void){
	uint8_t nr_items = 0;

	if(curr_submenu == NULL){
		struct menu * sub_menu = main_menu.pNext;
		while(sub_menu != NULL){
			nr_items++;
			sub_menu = sub_menu->pNext;
		}
	}else{
		struct menu_item * item = curr_submenu->head_item;
		while(item != NULL){
			nr_items++;
			item = item->pNext;
		}
	}

	return nr_items;
}


/**
 * @brief Get edited variable value
 *
 * Calculates a new updated variable value based on how much the right wheel has been turned.
 *
 * @param int val - Base value
 * @return int 		- Updated value
 */
int get_edited_val(int val){
	return val + (int)TIM5->CNT / (float)4096 * 15;
}


/**
	* @brief Initialize the oled screen and a welcome screen. 
	*
	* Initializes the SSD1306 oled driver and draws a image to signal startup.
	* Also initializes all menus/menu items by setting name, callbacks and link them together
*/
void init_oled(void){
	ssd1306_Init();
	
	ssd1306_DrawBitmap(case_head_bmp);
	ssd1306_UpdateScreen();

	HAL_Delay(500);
	
	// Show main menu
	active_screen = MENU;
	
	// Main Menu
	strcpy(main_menu.name, "Main menu");
	main_menu.head_item = NULL; 	// Main menu has no items, only sub menus
	main_menu.pNext  = &sub_menu_1; // Start of submenus
	
	// Back to main menu item
	strcpy(menu_item_back_main.name, "Back");
	menu_item_back_main.pNext = NULL;
	menu_item_back_main.callback = go_back_main;
	
	// Sub menu 1 + items
	strcpy(sub_menu_1.name, "General");
	sub_menu_1.pNext = &sub_menu_2;
	sub_menu_1.head_item = &menu_item_11;
	
	strcpy(menu_item_11.name, "Peripheral info");
	menu_item_11.pNext = &menu_item_12;
	menu_item_11.callback = oled_show_info;
	
	strcpy(menu_item_12.name, "Run tests");
	menu_item_12.pNext = &menu_item_13;
	menu_item_12.callback = oled_run_tests;
	
	strcpy(menu_item_13.name, "Nyx & Iris");
	menu_item_13.pNext = &menu_item_back_main;
	menu_item_13.callback = oled_show_cats;
	
	// Sub menu 2 + items
	strcpy(sub_menu_2.name, "Edit vars");
	sub_menu_2.pNext = &sub_menu_3;
	sub_menu_2.head_item = &menu_item_21;
	
	strcpy(menu_item_21.name, "Kp");
	menu_item_21.pNext = &menu_item_22;
	menu_item_21.pvar = &kp_test;
	menu_item_21.callback = oled_edit_var;
	
	strcpy(menu_item_22.name, "Ki");
	menu_item_22.pNext = &menu_item_23;
	menu_item_22.pvar = &ki_test;
	menu_item_22.callback = oled_edit_var;

	strcpy(menu_item_23.name, "Without callback");
	menu_item_23.pNext = &menu_item_back_main;


	// Sub menu 3 + items
	strcpy(sub_menu_3.name, "Calibration");
	sub_menu_3.pNext = NULL;
	sub_menu_3.head_item = &menu_item_31;
	
	strcpy(menu_item_31.name, "Calibrate XLINE");
	menu_item_31.pNext = &menu_item_32;
	menu_item_31.callback = oled_calibrate_xline;
	
	strcpy(menu_item_32.name, "Item 32");
	menu_item_32.pNext = &menu_item_back_main;
}


/**
	* @brief Update the OLED screen
	*	
	*	Checks flags and active screen to decide which screen gets rendered.
	*	Errors always have priority.
*/
void oled_update(void){



	//Check flag for going back to main menu and reset flag.
	if(go_back_main_flag){
		curr_submenu = NULL;
		prev_submenu = NULL;
		go_back_main_flag = 0;
	}

	if(active_screen == ERROR_){
		oled_error_screen();
	}else if(active_screen == MENU){
		oled_menu_screen();
	}else if(active_screen == INFO){
		oled_info_screen();
	}else if(active_screen == IMAGE){
		ssd1306_DrawBitmap(curr_image);
	}else if(active_screen == EDIT_VAR){
		oled_edit_var_screen();
	}else if(active_screen == MESSAGE){
		oled_message_screen();
	}else if(active_screen == NOT_IMPLEMENTED){
		oled_not_implemented_screen();
	}
	
	ssd1306_UpdateScreen();

	// Check if button has been pressed
	oled_button_check();

	/*
	if(!global_func_flag && !oled_enable_flag){
		if(global_func == TESTS){
			tests_run();
		}else if(global_func == CALIBRATION){
			xline_calibration_sequence();
		}
		global_func_flag = 1;
		oled_enable_flag = 1;
	}
	*/
}


/**
 * @brief Show error message on screen
 *
 * Global function to be called when user wants to display an error message
 *
 * @param pMessage String pointer to the error message.
 */
void oled_error(char *pMessage){
	error_message = pMessage;
	active_screen = ERROR_;
	oled_update();
}


/**
	* @brief Clear the error and update the screen with normal information.
*/
void oled_clear_error(void){
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
	active_screen = MENU;
	oled_update();
}


void oled_button_press(void){
	button_pressed_flag = 1;
}

/**
	* @brief Button press callback
	*
	* Decides what happens after a button click depending on state and cursor
*/
void oled_button_check(void){
	if(!button_pressed_flag){
		return;
	}

	button_pressed_flag = 0;
	if(active_screen == ERROR_){
		oled_clear_error();
		return;
	}else if(active_screen == EDIT_VAR){ // Save new edited value
		*edit_var->pvar = get_edited_val(*edit_var->pvar);
		active_screen = MENU;
		return;
	}else if(active_screen != MENU){
		active_screen = MENU;
		return;
	}
	
	if(curr_submenu == NULL){ // Main menu => Select sub menu
		struct menu * sub_menu = main_menu.pNext;
		int line = 0;
		while(sub_menu != NULL){
			if (line == cursor){
				curr_submenu = sub_menu;
				break;
			}
			line++;
			sub_menu = sub_menu->pNext;
		}
	}else{ // Sub menu => Select menu item == cursor and run it's callback
		struct menu_item * item = curr_submenu->head_item;
		int line = 0;
		while(item != NULL){
			if (line == cursor){
				if(item->callback != NULL){
					item->callback(item);
				}else{
					active_screen = NOT_IMPLEMENTED;
				}
				break;
			}
			line++;
			item = item->pNext;
		}
	}
	TIM5->CNT = 0; // Reset counter to reset cursor location
}


/**
	* @brief Show the menu screen with a cursor
	* 
	* The cursor position can be changed by rotating the wheels
	* You can choose menu or function by pressing the "Select Button" on the board 
	*
*/
void oled_menu_screen(void){
	// Calculate cursor index based on encoder
	float revolutions = TIM5->CNT / (float)4096 * 10;
	cursor = (int) revolutions % oled_nr_items();
	
	ssd1306_Fill(Black);
	
	if(curr_submenu == NULL){ // Main menu => draw sub menus
		ssd1306_SetCursor(0,0);
		ssd1306_WriteString(main_menu.name, Font_11x18, White);
		
		menu_t * sub_menu = main_menu.pNext; // Reference to first submenu
		int line = 0;
		
		while(sub_menu != NULL){
			if(line == cursor){ // Draw cursor
				ssd1306_SetCursor(0, 18 + line*10);
				ssd1306_WriteString(">", Font_7x10, White);
			}
			ssd1306_SetCursor(14, 18 + line*10);
			ssd1306_WriteString(sub_menu->name, Font_7x10, White);
			line++;
			sub_menu = sub_menu->pNext;
		}
	}else{ // Submenu => draw menu items
		ssd1306_SetCursor(0,0);
		ssd1306_WriteString(curr_submenu->name, Font_11x18, White);
		
		menu_item_t * item = curr_submenu->head_item;
		int line = 0;
		while(item != NULL){
			if (line == cursor){
				ssd1306_SetCursor(0, 18 + line*10);
				ssd1306_WriteString(">", Font_7x10, White);
			}

			ssd1306_SetCursor(14, 18 + line*10);
			ssd1306_WriteString(item->name, Font_7x10, White);

			if(item->pvar != NULL){ // Show variable value
				char buff[10];
				ssd1306_SetCursor(80, 18 + line*10);
				snprintf(buff, sizeof(buff), "%d", *item->pvar);
				ssd1306_WriteString(buff, Font_7x10, White);
			}
			line++;
			item = item->pNext;
		}		
	}
}


/**
	* @brief Show an screen with general info about peripherals.
*/
void oled_info_screen(){
	char buff[60];

	ssd1306_Fill(Black);
	ssd1306_SetCursor((128-4*10)/2,0);
	ssd1306_WriteString("INFO", Font_7x10, White);


	snprintf(buff, sizeof(buff), "Battery:  %5.2f V", GET_voltage_battery());
	ssd1306_SetCursor(0,10);
	ssd1306_WriteString(buff, Font_7x10, White);

	snprintf(buff, sizeof(buff), "Boost:    %5.2f V", GET_voltage_boost());
	ssd1306_SetCursor(0,20);
	ssd1306_WriteString(buff, Font_7x10, White);


	snprintf(buff, sizeof(buff), "Enc. R:   %5d", (int)TIM5->CNT);
	ssd1306_SetCursor(0,30);
	ssd1306_WriteString(buff, Font_7x10, White);

	snprintf(buff, sizeof(buff), "Enc. L:   %5d", (int)TIM2->CNT);
	ssd1306_SetCursor(0,40);
	ssd1306_WriteString(buff, Font_7x10, White);

	snprintf(buff, sizeof(buff), "XLINE:    %5d", xline_read_line(xline) - 1000*(16-1)/2);
	ssd1306_SetCursor(0,50);
	ssd1306_WriteString(buff, Font_7x10, White);
}


/**
	* @brief Draws error screen
	*
	* Private function to draw error screen and beep buzzer.
	* Keep the error messages short and concise, e.g "Low batt voltage", MAX 18 characters.
*/
void oled_error_screen(void){
	// Status LED RED + Double beep
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
	beep(50);
	HAL_Delay(50);
	beep(50);
	HAL_Delay(50);

	ssd1306_Fill(White);
	ssd1306_SetCursor((128-5*11)/2, 0);
	ssd1306_WriteString("ERROR", Font_11x18, Black);

	ssd1306_SetCursor(0, 20);
	ssd1306_WriteString(error_message, Font_7x10, Black);

	ssd1306_SetCursor(0, 50);
	ssd1306_WriteString("Press button", Font_7x10, Black);
	//HAL_Delay(1000); // Only for beeping every 1s
}

void oled_message_screen(void){
	//oled_disable();
	ssd1306_Fill(Black);
	ssd1306_SetCursor(0, 32);
	ssd1306_WriteString(disp_message, Font_7x10, White);
}


/**
 * @brief Show edit variable screen
 */
void oled_edit_var_screen(void){
	int new_val = get_edited_val(*edit_var->pvar);

	char buff[10];

	ssd1306_Fill(Black);
	ssd1306_SetCursor(0,0);
	ssd1306_WriteString("Edit", Font_11x18, White);

	ssd1306_SetCursor(0, 40);
	ssd1306_WriteString(edit_var->name, Font_7x10, White);

	ssd1306_SetCursor(80, 40);
	snprintf(buff, sizeof(buff), "%d", new_val);
	ssd1306_WriteString(buff, Font_7x10, White);
}


/**
 * @brief Show "not implemented" screen
 */
void oled_not_implemented_screen(void){
	ssd1306_Fill(Black);
	ssd1306_SetCursor((128-15*7)/2, 32);
	ssd1306_WriteString("NOT IMPLEMENTED", Font_7x10, White);
}


/****************************** ITEM CALLBACKS ******************************************/
// All callbacks must be of the following structure
/*
 * void method_name(menu_item_t *self){
 *
 * }
 */


/**
	* @brief Go back to the main menu
	*
	* @param menu_item_t *self - Pointer to itself
*/
void go_back_main(menu_item_t *self){
	go_back_main_flag = 1;
}


/**
 * @brief Change screen to IMAGE and show case head logo
 *
 * @param menu_item_t *self - Pointer to itself
*/
void oled_show_case(menu_item_t *self){
	active_screen = IMAGE;
	curr_image = case_head_bmp;
}


/**
 * @brief Change screen to IMAGE and show Nyx & Iris
 *
 * @param menu_item_t *self - Pointer to itself
*/
void oled_show_cats(menu_item_t *self){
	active_screen = IMAGE;
	curr_image = cats_bmp;
}


/**
 * @brief Change screen to INFO
 *
 * @param menu_item_t *self - Pointer to itself
*/
void oled_show_info(menu_item_t *self){
	active_screen = INFO;
}


/**
 * @brief Change screen to EDIT
 *
 * @param menu_item_t *self - Pointer to itself
*/
void oled_edit_var(menu_item_t *self){
	active_screen = EDIT_VAR;
	edit_var = self;
}


void oled_run_tests(menu_item_t *self){
  active_screen = MESSAGE;
	disp_message = "Running tests";
	oled_update();
	tests_run();
	active_screen = MENU;
}

void oled_calibrate_xline(menu_item_t *self){
	active_screen = MESSAGE;
	disp_message = "XLINE calibration";
	oled_update();
	xline_calibration_sequence();
	active_screen = MENU;
}








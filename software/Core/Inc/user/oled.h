#ifndef OLED_H
#define OLED_H

#include "main.h"

// Private
void go_back(void);
void go_back_main(void);
uint8_t nr_items(void);


void init_oled(void);
void oled_update(void);
void oled_error(char *pMessage);
void oled_clear_error(void);
void oled_button_press(void);

//Different screens
void oled_info_screen(void);
void oled_menu(void);
void oled_edit_var_screen(void);



// Menu item functions
void oled_show_case(void);
void oled_show_cats(void);
void oled_show_info(void);
void oled_show_edit_var(void);
void oled_edit_var(char *var_name, int *var);

#endif //OLED_H

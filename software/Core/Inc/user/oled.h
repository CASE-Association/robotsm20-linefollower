#ifndef OLED_H
#define OLED_H

#include "main.h"

typedef struct menu_item menu_item_t;

// Private helpers
uint8_t nr_items(void);
int get_edited_val(int val);

// General
void init_oled(void);
void oled_update(void);
void oled_error(char *pMessage);
void oled_clear_error(void);
void oled_button_press(void);
void oled_button_check(void);

//Different screens
void oled_menu_screen(void);
void oled_info_screen(void);
void oled_error_screen(void);
void oled_message_screen(void);
void oled_edit_var_screen(void);
void oled_run_line_follower_screen(void);
void oled_not_implemented_screen(void);

// Callbacks
void go_back_main(menu_item_t *self);
void oled_show_case(menu_item_t *self);
void oled_show_cats(menu_item_t *self);
void oled_show_info(menu_item_t *self);
void oled_show_edit_var(menu_item_t *self);
void oled_edit_var(menu_item_t *self);
void oled_run_tests(menu_item_t *self);
void oled_calibrate_xline(menu_item_t *self);
void oled_run_line_follow(menu_item_t *self);

#endif //OLED_H

// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: rotary test

#ifndef _ROTARY_TEST_UI_H
#define _ROTARY_TEST_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
  #if __has_include("lvgl.h")
    #include "lvgl.h"
  #elif __has_include("lvgl/lvgl.h")
    #include "lvgl/lvgl.h"
  #else
    #include "lvgl.h"
  #endif
#else
  #include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t *ui_Screen1;
extern lv_obj_t *ui_Button_next;
extern lv_obj_t *ui_Button_previous;
extern lv_obj_t *ui_Button_ripple_delete;
extern lv_obj_t *ui_Button_delete;
extern lv_obj_t *ui_Button_cut;
// CUSTOM VARIABLES
extern lv_obj_t *uic_Button_next;
extern lv_obj_t *uic_Button_previous;
extern lv_obj_t *uic_Button_ripple_delete;
extern lv_obj_t *uic_Button_delete;
extern lv_obj_t *uic_Button_cut;

// EVENTS
extern lv_obj_t *ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE( ui_img_images_btn_next_png);   // assets/Images/btn_next.png
LV_IMG_DECLARE( ui_img_images_btn_previous_png);   // assets/Images/btn_previous.png
LV_IMG_DECLARE( ui_img_images_btn_ripple_png);   // assets/Images/btn_ripple.png
LV_IMG_DECLARE( ui_img_images_btn_delete_png);   // assets/Images/btn_delete.png
LV_IMG_DECLARE( ui_img_images_btn_split_png);   // assets/Images/btn_split.png

// UI INIT
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

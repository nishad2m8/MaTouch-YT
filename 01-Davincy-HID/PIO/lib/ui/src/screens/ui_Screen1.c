// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: rotary test

#include "../ui.h"

void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Button_next = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Button_next, &ui_img_images_btn_next_png);
lv_obj_set_width( ui_Button_next, LV_SIZE_CONTENT);  /// 117
lv_obj_set_height( ui_Button_next, LV_SIZE_CONTENT);   /// 117
lv_obj_set_align( ui_Button_next, LV_ALIGN_TOP_RIGHT );
lv_obj_add_flag( ui_Button_next, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Button_next, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Button_previous = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Button_previous, &ui_img_images_btn_previous_png);
lv_obj_set_width( ui_Button_previous, LV_SIZE_CONTENT);  /// 117
lv_obj_set_height( ui_Button_previous, LV_SIZE_CONTENT);   /// 117
lv_obj_add_flag( ui_Button_previous, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Button_previous, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Button_ripple_delete = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Button_ripple_delete, &ui_img_images_btn_ripple_png);
lv_obj_set_width( ui_Button_ripple_delete, LV_SIZE_CONTENT);  /// 117
lv_obj_set_height( ui_Button_ripple_delete, LV_SIZE_CONTENT);   /// 117
lv_obj_set_align( ui_Button_ripple_delete, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_add_flag( ui_Button_ripple_delete, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Button_ripple_delete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Button_delete = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Button_delete, &ui_img_images_btn_delete_png);
lv_obj_set_width( ui_Button_delete, LV_SIZE_CONTENT);  /// 117
lv_obj_set_height( ui_Button_delete, LV_SIZE_CONTENT);   /// 117
lv_obj_set_align( ui_Button_delete, LV_ALIGN_BOTTOM_LEFT );
lv_obj_add_flag( ui_Button_delete, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Button_delete, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_Button_cut = lv_img_create(ui_Screen1);
lv_img_set_src(ui_Button_cut, &ui_img_images_btn_split_png);
lv_obj_set_width( ui_Button_cut, LV_SIZE_CONTENT);  /// 93
lv_obj_set_height( ui_Button_cut, LV_SIZE_CONTENT);   /// 93
lv_obj_set_align( ui_Button_cut, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_Button_cut, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_Button_cut, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

uic_Button_next = ui_Button_next;
uic_Button_previous = ui_Button_previous;
uic_Button_ripple_delete = ui_Button_ripple_delete;
uic_Button_delete = ui_Button_delete;
uic_Button_cut = ui_Button_cut;

}

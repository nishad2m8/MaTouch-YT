SET(SOURCES screens/ui_Screen1.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_images_btn_next_png.c
    images/ui_img_images_btn_previous_png.c
    images/ui_img_images_btn_ripple_png.c
    images/ui_img_images_btn_delete_png.c
    images/ui_img_images_btn_split_png.c)

add_library(ui ${SOURCES})

#include <lvgl.h>
#include <Arduino_GFX_Library.h>
#include "pins.h"
#include "touch.h"

// Global variable for rotation
int screenRotation = 1; // Set the desired rotation (0, 1, 2, 3)

// Screen resolution
static const uint16_t screenWidth = 240;
static const uint16_t screenHeight = 240;

// LVGL display bufferfig
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];

// Initialize display
Arduino_ESP32SPI *bus = new Arduino_ESP32SPI(TFT_DC, TFT_CS, TFT_SCLK, TFT_MOSI, TFT_MISO, HSPI);
Arduino_GFX *gfx = new Arduino_GC9A01(bus, TFT_RES, 0, true);

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
    lv_disp_flush_ready(disp);
}

void remapTouchCoordinates(int rawX, int rawY, int &mappedX, int &mappedY, uint8_t rotation) {
    switch (rotation) {
        case 0:  // No rotation
            mappedX = rawX;
            mappedY = rawY;
            break;
        case 1:  // 90 degrees clockwise
            mappedX = rawY;
            mappedY = screenWidth - rawX;
            break;
        case 2:  // 180 degrees
            mappedX = screenWidth - rawX;
            mappedY = screenHeight - rawY;
            break;
        case 3:  // 270 degrees clockwise
            mappedX = screenHeight - rawY;
            mappedY = rawX;
            break;
        default:
            mappedX = rawX;
            mappedY = rawY;
            break;
    }
}

void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
    int touchX = 0, touchY = 0;

    if (read_touch(&touchX, &touchY) == 1) {
        int adjustedX = 0, adjustedY = 0;
        remapTouchCoordinates(touchX, touchY, adjustedX, adjustedY, screenRotation);

        data->state = LV_INDEV_STATE_PR;
        data->point.x = (uint16_t)adjustedX;
        data->point.y = (uint16_t)adjustedY;

        // Debug touch press
        // Serial.print("Touch Pressed: ");
        // Serial.print("X=");
        // Serial.print(adjustedX);
        // Serial.print(", Y=");
        // Serial.println(adjustedY);
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
}

void setupLVGL() {
    // Initialize display
    gfx->begin();
    gfx->setRotation(screenRotation);

    // Initialize LVGL
    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

    // Initialize display driver
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // Initialize touch input device
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    // Create a label
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello, World with Touch!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

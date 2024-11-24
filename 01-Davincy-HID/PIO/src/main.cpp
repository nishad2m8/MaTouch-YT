#include <Arduino.h>
#include <lvgl.h>
#include <Arduino_GFX_Library.h>
#include <RotaryEncoder.h>
#include <USBHIDKeyboard.h>
#include "USB.h"
#include <ui.h>

#include "touch.h"
#include "pins.h"
#include "lvgl_setup.h"

// Create an instance of RotaryEncoder
RotaryEncoder encoder(ENCODER_CLK, ENCODER_DT, RotaryEncoder::LatchMode::TWO03);

// Create an instance of USBHIDKeyboard
USBHIDKeyboard usbKeyboard;

// Button debounce variables
static bool buttonState = HIGH;
static bool lastButtonState = HIGH;
unsigned long lastButtonDebounceTime = 0;
const unsigned long buttonDebounceDelay = 50;

// Function to send USB HID keyboard commands
void sendKeyPress(uint8_t modifier, uint8_t key) {
    Serial.printf("Sending KeyPress: Modifier=0x%02X, Key=0x%02X\n", modifier, key);
    usbKeyboard.press(modifier);
    usbKeyboard.press(key);
    usbKeyboard.releaseAll();
    Serial.println("Key sent successfully");
}

// Rotary Encoder Handling
void handleRotaryEncoder() {
    static int lastPos = 0;
    encoder.tick();
    int newPos = encoder.getPosition();

    if (newPos != lastPos) {
        if (newPos > lastPos) {
            usbKeyboard.press(KEY_LEFT_ARROW);
            usbKeyboard.release(KEY_LEFT_ARROW);
        } else if (newPos < lastPos) {
            usbKeyboard.press(KEY_RIGHT_ARROW);
            usbKeyboard.release(KEY_RIGHT_ARROW);
        }
        lastPos = newPos;
    }
}

// Handle Button Press (Cut Timeline)
void handleButton() {
    int reading = digitalRead(BUTTON_PIN);
    if (reading != lastButtonState) {
        lastButtonDebounceTime = millis();
    }

    if ((millis() - lastButtonDebounceTime) > buttonDebounceDelay) {
        if (reading != buttonState) {
            buttonState = reading;
            if (buttonState == LOW) {
                sendKeyPress(KEY_LEFT_GUI, 'b');
            }
        }
    }
    lastButtonState = reading;
}

// Touch Button Event Handlers
void uic_button_delete_event_handler(lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        usbKeyboard.press(KEY_BACKSPACE); //  Backspace
        usbKeyboard.release(KEY_BACKSPACE);
    }
}

void uic_button_ripple_delete_event_handler(lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        sendKeyPress(KEY_LEFT_SHIFT, KEY_BACKSPACE); // CMD + Backspace
    }
}

void uic_Button_next_event_handler(lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        sendKeyPress(KEY_LEFT_GUI, KEY_RIGHT_ARROW); // CMD + Right Arrow
    }
}

void uic_Button_previous_event_handler(lv_event_t *e) {
    if (lv_event_get_code(e) == LV_EVENT_CLICKED) {
        sendKeyPress(KEY_LEFT_GUI, KEY_LEFT_ARROW); // CMD + Left Arrow
    }
}


void setup() {
    Serial.begin(115200);

    // Initialize USB HID Keyboard
    usbKeyboard.begin();
    USB.begin();
    Serial.println("USB HID Keyboard initialized");
    delay(1000); // Wait for 1 second

    // Initialize hardware
    pinMode(TFT_BLK, OUTPUT);
    digitalWrite(TFT_BLK, HIGH);

    // Set up touch interface
    Wire.begin(TOUCH_SDA, TOUCH_SCL);

    // Set up encoder pins
    pinMode(ENCODER_CLK, INPUT_PULLUP);
    pinMode(ENCODER_DT, INPUT_PULLUP);

    // Set up button pin
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // Call the LVGL setup function
    setupLVGL();

    // Initialize UI
    ui_init();

    // Attach event handlers to the UI buttons
    lv_obj_add_event_cb(ui_Button_delete, uic_button_delete_event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(ui_Button_ripple_delete, uic_button_ripple_delete_event_handler, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(ui_Button_next, uic_Button_next_event_handler, LV_EVENT_CLICKED, NULL);  // Attach 'next' button event
    lv_obj_add_event_cb(ui_Button_previous, uic_Button_previous_event_handler, LV_EVENT_CLICKED, NULL);  // Attach 'previous' button event


    Serial.println("Setup complete.");
}

void loop() {
    handleRotaryEncoder();
    handleButton();
    lv_timer_handler();
    delay(10);
}

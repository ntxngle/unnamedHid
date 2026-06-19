#include <Arduino.h>
#include <pio_usb.h>
#include "USBHIDKeyboard.h"

USBHIDKeyboard DeviceKeyboard;

String inputBuffer = "";

void handle_keyboard_report(uint8_t dev_addr, uint8_t idx, uint8_t const* report, uint16_t len) {
  if (len < 8) return;

  static uint8_t prev_keys[6] = {0};
  uint8_t const* keys = report + 2;

  for (int i = 0; i < 6; i++) {
    uint8_t key = keys[i];
    if (key == 0) continue;

    bool already_pressed = false;
    for (int j = 0; j < 6; j++) {
      if (key == prev_keys[j]) {
        already_pressed = true;
        break;
      }
    }

    if (!already_pressed) {
      char c = 0;
      if (key >= 4 && key <= 29) {
        c = 'a' + (key - 4);
      }

      if (c != 0) {
        inputBuffer += c;
        if (inputBuffer.length() > 6) {
          inputBuffer.remove(0, 1);
        }

        if (inputBuffer == "banana") {
          
          delay(50); 
          
          for (int b = 0; b < 6; b++) {
            DeviceKeyboard.press(KEY_BACKSPACE);
            DeviceKeyboard.releaseAll();
            delay(10);
          }

          DeviceKeyboard.print("apple");
          
          inputBuffer = "";
        }
      }
    }
  }

  memcpy(prev_keys, keys, 6);
}

static void pio_usb_configuration() {
  static pio_usb_configuration_t config = PIO_USB_DEFAULT_CONFIG;
  config.pin_dp = 16; 
  
  USBHost.begin(&config);
}

void setup() {
  
  DeviceKeyboard.begin();
  
  pio_usb_configuration();
  
}

void loop() {
  USBHost.task();
}

void setup1() {}
void loop1() {
  USBHost.task();
}

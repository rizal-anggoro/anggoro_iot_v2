#include "DeskPixel.h"

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

void DeskPixel::begin() {
  Serial.println("void: DeskPixel -> begin");
  pixel.begin();
  pixel.clear();
  pixel.setBrightness(25);
  pixel.show();
}

void DeskPixel::test(int r, int g, int b) {
  for (int a = 0; a < 50; a++) {
    pixel.setPixelColor(a, pixel.Color(r, g, b));
  }
  pixel.show();
}

void DeskPixel::testByte() {
  uint32_t color = pixel.Color(255, 255, 255);
  Serial.println(color);
}

void DeskPixel::setBrightness(int value) {
  pixel.setBrightness(value);
  pixel.show();
}

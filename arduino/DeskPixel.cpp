#include "DeskPixel.h"

#include <Adafruit_NeoPixel.h>

extern Adafruit_NeoPixel desk_pixel;
void DeskPixel::begin() {
  Serial.println("void: DeskPixel -> begin");
  desk_pixel.begin();
  desk_pixel.clear();
  desk_pixel.setBrightness(25);
  desk_pixel.show();
}

void DeskPixel::test(int r, int g, int b) {
  for (int a = 0; a < 50; a++) {
    desk_pixel.setPixelColor(a, desk_pixel.Color(r, g, b));
  }
  desk_pixel.show();
}

void DeskPixel::setBrightness(int value) {
  desk_pixel.setBrightness(value);
  desk_pixel.show();
}

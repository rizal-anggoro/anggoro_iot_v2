#include "MatrixPixel.h"

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

void MatrixPixel::begin() {
  pixel.begin();
  pixel.setBrightness(25);
  pixel.clear();
  pixel.show();  
}

void MatrixPixel::test(int r, int g, int b) {
  for (int a = 0; a < 77; a++) {
    pixel.setPixelColor(a, pixel.Color(r, g, b));
  }
  pixel.show();
}

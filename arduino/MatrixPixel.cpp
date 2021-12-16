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

void MatrixPixel::displayBitmap(byte bitmap[11]) {
  pixel.clear();
  for (int a = 0; a < 11; a++) {
    byte b = bitmap[a];
    int pin_index = 0;
    for (int c = 6; c >= 0; c--) {
      int pin = matrixs[a][pin_index];
      byte d = bitRead(b, c);
      pixel.setPixelColor(pin, d == 1 ? pixel.Color(255, 0, 255) : 0);
      pin_index++;
    }
  }
  pixel.show();
}

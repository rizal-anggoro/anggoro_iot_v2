#include "MatrixPixel.h"

#include <Adafruit_NeoPixel.h>

extern Adafruit_NeoPixel matrix_pixel;
void MatrixPixel::begin() {
  matrix_pixel.begin();
  matrix_pixel.setBrightness(25);
  matrix_pixel.clear();
  matrix_pixel.show();  
}

void MatrixPixel::test(int r, int g, int b) {
  for (int a = 0; a < 77; a++) {
    matrix_pixel.setPixelColor(a, matrix_pixel.Color(r, g, b));
  }
  matrix_pixel.show();
}

void MatrixPixel::displayBitmap(byte bitmap[11]) {
  matrix_pixel.clear();
  for (int a = 0; a < 11; a++) {
    byte b = bitmap[a];
    int pin_index = 0;
    for (int c = 6; c >= 0; c--) {
      int pin = matrixs[a][pin_index];
      byte d = bitRead(b, c);
      matrix_pixel.setPixelColor(pin, d == 1 ? matrix_pixel.Color(255, 0, 255) : 0);
      pin_index++;
    }
  }
  matrix_pixel.show();
}

void MatrixPixel::setBrightness(int value) {
  matrix_pixel.setBrightness(value);
  matrix_pixel.show();
}

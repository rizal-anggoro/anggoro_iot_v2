#ifndef MatrixPixel_h
#define MatrixPixel_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class MatrixPixel {
  private:
  Adafruit_NeoPixel pixel;
  int matrixs[11][7];
  
  public:
  void begin();
  void test(int r, int g, int b);
  void displayBitmap(byte bitmap[11]);
  void setBrightness(int value);

  MatrixPixel():
  pixel(77, 13, NEO_GRB + NEO_KHZ800),
  matrixs({
    { 0, 11, 22, 33, 44, 55, 66 },
    { 1, 12, 23, 34, 45, 56, 67 },
    { 2, 13, 24, 35, 46, 57, 68 },
    { 3, 14, 25, 36, 47, 58, 69 },
    { 4, 15, 26, 37, 48, 59, 70 },
    { 5, 16, 27, 38, 49, 60, 71 },
    { 6, 17, 28, 39, 50, 61, 72 },
    { 7, 18, 29, 40, 51, 62, 73 },
    { 8, 19, 30, 41, 52, 63, 74 },
    { 9, 20, 31, 42, 53, 64, 75 },
    {10, 21, 32, 43, 54, 65, 76 },
  }) {}
};

#endif

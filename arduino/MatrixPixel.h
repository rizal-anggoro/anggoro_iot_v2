#ifndef MatrixPixel_h
#define MatrixPixel_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class MatrixPixel {
  public:
  void begin();
  void test(int r, int g, int b);

  MatrixPixel():
  pixel(77, 13, NEO_GRB + NEO_KHZ800) {}

  private:
  Adafruit_NeoPixel pixel;
};

#endif

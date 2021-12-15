#ifndef DeskPixel_h
#define DeskPixel_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class DeskPixel {
  public:
  void begin();
  void test(int r, int g, int b);

  DeskPixel():
  pixel(50, 12, NEO_GRB + NEO_KHZ800) {}

  private:
  Adafruit_NeoPixel pixel;
};

#endif

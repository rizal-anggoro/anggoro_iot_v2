#ifndef DeskPixel_h
#define DeskPixel_h

#include <Arduino.h>

class DeskPixel {
  public:
  void begin();
  void test(int r, int g, int b);
  void setBrightness(int value);

  private:
};

#endif

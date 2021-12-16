#ifndef Communication_h
#define Communication_h

#include <Arduino.h>

class Communication {
  public:
  void receiveEvent(int how_many);
  void requestEvent();
  void begin();

  private:
  
};

#endif

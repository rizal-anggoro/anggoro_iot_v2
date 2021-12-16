#ifndef Communication_h
#define Communcation_h

#include <Arduino.h>

class Communication {
  public:
  void begin();
  void sendString(String data);
};

#endif

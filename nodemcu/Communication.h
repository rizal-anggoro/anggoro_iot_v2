#ifndef Communication_h
#define Communcation_h

#pragma once

#include <Arduino.h>

class Communication {
  public:
  void begin();
  void sendString(String data);
  void send(String data_path, String data);
  void sendJson();
};

#endif

#ifndef Wifi_h
#define Wifi_h

#include <Arduino.h>

#include "Communication.h"

class Wifi {
  private:
  String wifi_ssid;
  String wifi_password;

  public:
  void open();
};

#endif

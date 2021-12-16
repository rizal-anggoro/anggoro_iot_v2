#ifndef Ntp_h
#define Ntp_h

#include <Arduino.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

class Ntp {
  private:
  WiFiUDP wifiUdp;
  NTPClient ntpClient;

  public:
  void begin();
  String getHMClock();
  
  Ntp():
  ntpClient(wifiUdp, "id.pool.ntp.org", (7 * 3600)) {}
};

#endif

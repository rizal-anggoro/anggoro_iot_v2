#include "Wifi.h"
#include "Ntp.h"
#include "Communication.h"

Wifi wifi;
Ntp ntp;
Communication communication;
void setup() {
  Serial.begin(115200);

  communication.begin();
  wifi.open();
  ntp.begin();
}

void loop() {
  streamClock();
}

unsigned long previous_millis = 0;
void streamClock() {
  unsigned long current_millis = millis();
  if (current_millis - previous_millis >= 1000) {
    previous_millis = current_millis;
    String data = ntp.getHMClock();
    String s_data = "/clock_data;" + data;
    communication.sendString(s_data);
  }
}

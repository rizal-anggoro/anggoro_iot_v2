#include "Wifi.h"
#include "Ntp.h"
#include "Communication.h"
#include "Database.h"

#include <Wire.h>

Wifi wifi;
Ntp ntp;
Communication communication;
Database database;
void setup() {
  Serial.begin(115200);

  communication.begin();
  wifi.open();
  database.begin();
  ntp.begin();
}

void loop() {
  streamClock();
  database.stream();
  checkSlave();
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

unsigned long check_slave_previous_millis;
void checkSlave() {
  unsigned long current_millis = millis();
  if (current_millis - check_slave_previous_millis >= 1000) {
    check_slave_previous_millis = current_millis;

    Wire.requestFrom(1, 1);
    char data;
    while (Wire.available()) {
      data = Wire.read();
    }

    if (data == 1) {
      // send json data
      communication.sendJson();   
    }
  }
}

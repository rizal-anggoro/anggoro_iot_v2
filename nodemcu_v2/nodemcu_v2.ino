#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <Wire.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

const int map_size = 11;
String map_key[map_size] = {
  "desk_mode",                    // 0
  "desk_brightness",              // 1
  "desk_breathing_red",           // 2
  "desk_breathing_green",         // 3
  "desk_breathing_blue",          // 4
  "desk_breathing_interval",      // 5
  "desk_color_cycle_interval",    // 6
  "desk_rainbow_interval",        // 7
  "desk_static_red",              // 8
  "desk_static_green",            // 9
  "desk_static_blue",             // 10
};
String map_value[map_size] = {
  "off",
  "0",
  "0",
  "0",
  "0",
  "25",
  "25",
  "25",
  "0",
  "0",
  "0",
};

WiFiUDP wifi_udp;
NTPClient ntp_client(wifi_udp, "id.pool.ntp.org", (7 * 3600));

void setup() {
  Serial.begin(115200);
  Wire.begin(5, 4);

  openWiFi();
  beginServer();

  ntp_client.begin();
}

void loop() {
  checkSlave();
  streamNtp();
}

unsigned long check_slave_previous_millis = 0;
void checkSlave() {
  unsigned long current_millis = millis();
  if (current_millis - check_slave_previous_millis >= 1000) {
    check_slave_previous_millis = current_millis;

    Wire.requestFrom(1, 1);
  }
  
  while (Wire.available() > 0) {
    char a = Wire.read();    
    if (a == 1) {
      Serial.println("request: sendAllVariable");
      sendAllVariable();
    }
  }
}

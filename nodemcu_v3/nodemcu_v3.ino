#include <ESP8266WiFi.h>
#include <Wire.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <ESPAsyncWebServer.h>

void setup() {
  Serial.begin(115200);
  Wire.begin(5, 4);

  openWiFi();
  beginNtp();
  beginServer();
}

void loop() {
  streamNtp();
}

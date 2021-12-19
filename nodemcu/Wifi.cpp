#include "Wifi.h"

#include <ESP8266WiFi.h>

extern Communication communication;
void Wifi::open() {
  Serial.println("void: Wifi -> open");

  Serial.print("Connecting");
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    communication.send("/loading", ".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to: ");
  Serial.print(WiFi.localIP());
  Serial.println();
}

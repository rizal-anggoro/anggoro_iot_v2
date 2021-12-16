#include "Wifi.h"
#include "Ntp.h"

Wifi wifi;
Ntp ntp;
void setup() {
  Serial.begin(115200);

  wifi.open();
  ntp.begin();
}

void loop() {
  String a = ntp.getHMClock();
  Serial.println(a);
  delay(1000);
}

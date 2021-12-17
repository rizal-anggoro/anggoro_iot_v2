#include "Communication.h"

#include <Wire.h>

void Communication::begin() {
  Serial.println("void: Communication -> begin");
  Wire.begin(5, 4);
}

void Communication::sendString(String data) {
  Serial.println("void: Communication -> sendString");
  Serial.println(data);
  
  data += ";";
  int str_len = data.length() + 1;
  char buffer[str_len];
  data.toCharArray(buffer, str_len);

  // send data over i2c
  Wire.beginTransmission(1);
  for (int a = 0; a < str_len; a++) {
    Wire.write(buffer[a]);
  }
  Wire.endTransmission();
}

void Communication::send(String data_path, String data) {
  String a = data_path + ";" + data;
  sendString(a);
}

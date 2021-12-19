#include "Communication.h"

#include <Wire.h>

#include "DeskData.h"
#include "MatrixData.h"

void Communication::begin() {
  Serial.println("void: Communication -> begin");
  Wire.begin(5, 4);
}

void Communication::sendString(String data) {
  if (data.indexOf("/clock_data") == -1) {
    Serial.println("void: Communication -> sendString");
    Serial.println(data);
  }
  
  data += ";";
  int str_len = data.length() + 1;
  char buffer[str_len];
  data.toCharArray(buffer, str_len);

  // send data over i2c
  Wire.beginTransmission(1);
  for (int a = 0; a < str_len; a++) {
    Wire.write(buffer[a]);
    delay(1);
  }
  Wire.endTransmission();
}

void Communication::send(String data_path, String data) {
  String a = data_path + ";" + data;
  sendString(a);
}

void Communication::sendJson() {
  if (DeskData::mode != NULL) {
    send("/desk/mode", DeskData::mode);
    send("/desk/brightness", DeskData::brightness);
    send("/desk/breathing/red", DeskData::breathing_red);
    send("/desk/breathing/green", DeskData::breathing_green);
    send("/desk/breathing/blue", DeskData::breathing_blue);
    send("/desk/breathing/interval", DeskData::breathing_interval);
    send("/desk/color_cycle/interval", DeskData::color_cycle_interval);
    send("/desk/rainbow/interval", DeskData::rainbow_interval);
    send("/desk/static/red", DeskData::static_red);
    send("/desk/static/green", DeskData::static_green);
    send("/desk/static/blue", DeskData::static_blue);

    send("/matrix/mode", MatrixData::mode);
    send("/matrix/brightness", MatrixData::brightness);
  }
}

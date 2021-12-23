void sendSerial(String path, String value) {
  String a = path + ";" + value;
  a += ";";

  int b = a.length() + 1;
  char buffer[b];
  a.toCharArray(buffer, b);

  Serial.print("send: ");
  Serial.println(a);
  
  Wire.beginTransmission(1);
  for (int c = 0; c < b; c++) {
    Wire.write(buffer[c]);
    delay(1);
  }
  Wire.endTransmission();
}

void sendAllVariable() {
  for (int a = 0; a < map_size; a++) {
    sendSerial(map_key[a], map_value[a]);
  }
}

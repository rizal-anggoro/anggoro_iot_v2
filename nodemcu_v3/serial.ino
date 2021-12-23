void sendSerial(String path, String value) {
  String a = path + ";" + value;
  a += ";";

  int str_len = a.length() + 1;
  char buffer[str_len];
  a.toCharArray(buffer, str_len);

  //if (path != "matrix_clock_data") {
    Serial.print("sending: ");
    Serial.println(a);
  //}

  Wire.beginTransmission(1);
  for (int b = 0; b < str_len; b++) {
    Wire.write(buffer[b]);
    delay(1);
  }
  Wire.endTransmission();
}

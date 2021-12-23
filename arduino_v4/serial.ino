void receiveEvent(int how_many) {
  char buffer[how_many];
  int index = 0;
  String receive_data = "";

  while (Wire.available() > 0) {
    buffer[index] = Wire.read();
    index++;
    delay(1);
  }

  receive_data = String(buffer);
  receive_data.trim();
  
  // Serial.print("receive data: ");
  // Serial.println(receive_data);

  parse(receive_data);
}

void requestEvent() {
  
}

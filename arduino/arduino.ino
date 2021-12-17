#include "DeskPixel.h"
#include "MatrixPixel.h"
#include "Segment.h"
#include "Communication.h"

#include <Wire.h>

DeskPixel deskPixel;
MatrixPixel matrixPixel;
Segment segment;
void setup() {
  Serial.begin(115200);

  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  
  deskPixel.begin();
  matrixPixel.begin();

  deskPixel.test(255, 0, 255);
}

void loop() {
}

bool contains(String a, String b) {
  return a.indexOf(b) != -1;
}

void receiveEvent(int how_many) {
  char buffer[how_many];
  int index = 0;
  while (Wire.available() > 0) {
    char data = Wire.read();
    buffer[index] = data;
    index++;
  }
  String receive_data = String(buffer);
  receive_data.trim();

  parseSerial(receive_data);
}

void parseSerial(String data) {
  int a = data.indexOf(";");
  int b = data.lastIndexOf(";");
  String c = data.substring(0, a);
  String d = data.substring((a + 1), b);

  if (c == "/clock_data") {
    byte bitmap[11];
    segment.getBitmapFromData(d, bitmap);
    matrixPixel.displayBitmap(bitmap);
  }
}

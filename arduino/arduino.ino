#include "DeskPixel.h"
#include "MatrixPixel.h"
#include "Segment.h"

DeskPixel deskPixel;
MatrixPixel matrixPixel;
Segment segment;
void setup() {
  Serial.begin(115200);

  deskPixel.begin();
  matrixPixel.begin();
  
//  deskPixel.test(255, 0, 255);
//  matrixPixel.test(0, 255, 255);

  String data = "0123";
  byte a = segment.getData(segment.getCharIndex(segment.getChar(data, 0)), 1);
  Serial.println(a);
  
//  byte a = B00000000;
//  byte b = B00000111;
//  byte c = B00000101;
//  a = (b << 4) | (c);
//  for (int i = 7; i >= 0; i--) {
//    Serial.print(bitRead(a, i));
//  }
//  Serial.println();
}

void loop() {
}

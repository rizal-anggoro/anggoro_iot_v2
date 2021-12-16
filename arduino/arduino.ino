#include "DeskPixel.h"
#include "MatrixPixel.h"

DeskPixel deskPixel;
MatrixPixel matrixPixel;
void setup() {
  Serial.begin(115200);

  deskPixel.begin();
  matrixPixel.begin();
  
//  deskPixel.test(255, 0, 255);
//  matrixPixel.test(0, 255, 255);

  byte a = B00000000;
  byte b = B00000111;
  byte c = B00000101;
  a = (b << 4) | (c);
  for (int i = 7; i >= 0; i--) {
    Serial.print(bitRead(a, i));
  }
  Serial.println();
}

void loop() {
}

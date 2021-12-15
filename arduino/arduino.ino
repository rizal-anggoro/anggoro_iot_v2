#include "DeskPixel.h"
#include "MatrixPixel.h"

DeskPixel deskPixel;
MatrixPixel matrixPixel;
void setup() {
  Serial.begin(115200);

  deskPixel.begin();
  matrixPixel.begin();
  
  deskPixel.test(255, 0, 255);
  matrixPixel.test(0, 255, 255);
}

void loop() {
}

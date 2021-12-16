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

  String data = "0164";
  byte bitmap[11];
  segment.getBitmapFromData(data, bitmap);
  matrixPixel.displayBitmap(bitmap);
}

void loop() {
}

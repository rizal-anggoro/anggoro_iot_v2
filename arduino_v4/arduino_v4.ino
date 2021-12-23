#include <Wire.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel desk_pixel(50, 12, NEO_GRB + NEO_KHZ800), 
  matrix_pixel(77, 13, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);

  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  desk_pixel.begin();
  matrix_pixel.begin();

  desk_pixel.setBrightness(25);
  matrix_pixel.setBrightness(50);

  desk_pixel.show();
  matrix_pixel.show();
}

void loop() {
  parseDesk();
  parseMatrix();
}

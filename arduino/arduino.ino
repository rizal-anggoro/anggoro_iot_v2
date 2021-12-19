//#include "DeskPixel.h"
#include "MatrixPixel.h"
#include "Segment.h"

#include <Wire.h>
#include <Adafruit_NeoPixel.h>

// desk data
String desk_mode = "";
String desk_brightness = "";
String desk_breathing_red = "";
String desk_breathing_green = "";
String desk_breathing_blue = "";
String desk_breathing_interval = "";
String desk_color_cycle_interval = "";
String desk_rainbow_interval = "";
String desk_static_red = "";
String desk_static_green = "";
String desk_static_blue = "";

// matrix data
String matrix_mode = "";
String matrix_brightness = "";

//DeskPixel deskPixel;
MatrixPixel matrixPixel;
Segment segment;

//desk_pixel(50, 12, NEO_GRB + NEO_KHZ800),
Adafruit_NeoPixel  matrix_pixel(77, 13, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);

  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

//  desk_pixel.begin();
//  desk_pixel.clear();
//  desk_pixel.setBrightness(25);
//  desk_pixel.show();
  
  matrix_pixel.begin();
  matrix_pixel.setBrightness(25);
  matrix_pixel.clear();
  matrix_pixel.show();  
  
//  deskPixel.begin();
//  matrixPixel.begin();

//  deskPixel.test(255, 0, 255);
}

void loop() {
}

void receiveEvent(int how_many) {
  char buffer[how_many];
  int index = 0;
  while (Wire.available() > 0) {
    char data = Wire.read();
    buffer[index] = data;
    index++;
    delay(1);
  }
  String receive_data = String(buffer);
  receive_data.trim();

  parseSerial(receive_data);
}

void requestEvent() {
  if (desk_mode == "") {
    Wire.write(1);
  } else {
//    Serial.println(desk_mode);
  }
}

void parseSerial(String receive_data) {
  if (receive_data.indexOf("/clock_data") == -1) {
    Serial.println(receive_data);
  }
  
  int a = receive_data.indexOf(";");
  int b = receive_data.lastIndexOf(";");
  String path = receive_data.substring(0, a);
  String data = receive_data.substring((a + 1), b);

  if (path == "/clock_data") {
    byte bitmap[11];
    segment.getBitmapFromData(data, bitmap);
    matrixPixel.displayBitmap(bitmap);
  }

  else if (path == "/desk/mode") {
    desk_mode = data;
  } else if (path == "/desk/brightness") {
    desk_brightness = data;
  } else if (path == "/desk/breathing/red") {
    desk_breathing_red = data;
  } else if (path == "/desk/breathing/green") {
    desk_breathing_green = data;
  } else if (path == "/desk/breathing/blue") {
    desk_breathing_blue = data;
  } else if (path == "/desk/breathing/interval") {
    desk_breathing_interval = data;
  } else if (path == "/desk/color_cycle/interval") {
    desk_color_cycle_interval = data;
  } else if (path == "/desk/rainbow/interval") {
    desk_rainbow_interval = data;
  } else if (path == "/desk/static/red") {
    desk_static_red = data;
  } else if (path == "/desk/static/green") {
    desk_static_green = data;
  } else if (path == "/desk/static/blue") {
    desk_static_blue = data;
  }

  else if (path == "/matrix/mode") {
    matrix_mode = data;
  } else if (path == "/matrix/brightness") {
    matrix_brightness = data;
  }
}

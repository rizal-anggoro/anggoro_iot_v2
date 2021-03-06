#include <Adafruit_NeoPixel.h>
#include <Wire.h>

const String segment_chars = "0123456789-";
const byte segment_data[11][5] = {
  { B00000111, B00000101, B00000101, B00000101, B00000111 }, // 0
  { B00000001, B00000011, B00000001, B00000001, B00000001 }, // 1
  { B00000111, B00000001, B00000111, B00000100, B00000111 }, // 2
  { B00000111, B00000001, B00000111, B00000001, B00000111 }, // 3
  { B00000101, B00000101, B00000111, B00000001, B00000001 }, // 4
  { B00000111, B00000100, B00000111, B00000001, B00000111 }, // 5
  { B00000111, B00000100, B00000111, B00000101, B00000111 }, // 6
  { B00000111, B00000001, B00000001, B00000001, B00000001 }, // 7
  { B00000111, B00000101, B00000111, B00000101, B00000111 }, // 8
  { B00000111, B00000101, B00000111, B00000001, B00000111 }, // 9
  { B00000000, B00000000, B00000000, B00000000, B00000000 }, // -
};
const uint8_t matrix_pins[11][7] = {
  { 0, 11, 22, 33, 44, 55, 66 },
  { 1, 12, 23, 34, 45, 56, 67 },
  { 2, 13, 24, 35, 46, 57, 68 },
  { 3, 14, 25, 36, 47, 58, 69 },
  { 4, 15, 26, 37, 48, 59, 70 },
  { 5, 16, 27, 38, 49, 60, 71 },
  { 6, 17, 28, 39, 50, 61, 72 },
  { 7, 18, 29, 40, 51, 62, 73 },
  { 8, 19, 30, 41, 52, 63, 74 },
  { 9, 20, 31, 42, 53, 64, 75 },
  {10, 21, 32, 43, 54, 65, 76 },
};

const int map_size = 11;
String map_key[map_size] = {
  "desk_mode",                    // 0
  "desk_brightness",              // 1
  "desk_breathing_red",           // 2
  "desk_breathing_green",         // 3
  "desk_breathing_blue",          // 4
  "desk_breathing_interval",      // 5
  "desk_color_cycle_interval",    // 6
  "desk_rainbow_interval",        // 7
  "desk_static_red",              // 8
  "desk_static_green",            // 9
  "desk_static_blue",             // 10
};
String map_value[map_size] = {};
String matrix_clock_data = "0000";

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
}

void receiveEvent(int how_many) {
  char buffer[how_many];
  int index = 0;
  String receive_data = "";
  while (Wire.available() > 0) {
    char c = Wire.read();
    buffer[index] = c;
    index++;
  }
  receive_data = String(buffer);
  receive_data.trim();

  parser(receive_data);
}

void requestEvent() {
//  _printMap();
  if (map_value[0].length() == 0) {
    Wire.write(1);
  }
}

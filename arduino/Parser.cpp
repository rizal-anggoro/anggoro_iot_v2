#include "Parser.h"

extern String desk_mode;
extern String desk_brightness;
extern String desk_breathing_red;
extern String desk_breathing_green;
extern String desk_breathing_blue;
extern String desk_breathing_interval;
extern String desk_color_cycle_interval;
extern String desk_rainbow_interval;
extern String desk_static_red;
extern String desk_static_green;
extern String desk_static_blue;

extern String matrix_mode;
extern String matrix_brightness;

void Parser::let(String receive_data) {
  if (receive_data.indexOf("/clock_data") == -1) {
    Serial.println(receive_data);
  }
  
  int a = receive_data.indexOf(";");
  int b = receive_data.lastIndexOf(";");
  String path = receive_data.substring(0, a);
  String data = receive_data.substring((a + 1), b);

  if (path == "/desk/mode") {
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

void parseDesk() {
  _desk_brightness();
  
  // mode -> off
  if (desk_mode == "off") {
    desk_pixel.clear();
    desk_pixel.show();
  }

  // mode -> static
  else if (desk_mode == "static") {
    _desk_static();
  }

  // mode -> rainbow
  else if (desk_mode == "rainbow") {
    _desk_rainbow();
  }
}

void _desk_brightness() {
  if (desk_pixel.getBrightness() != desk_brightness.toInt()) {
    desk_pixel.setBrightness(desk_brightness.toInt());
    desk_pixel.show();
  }
}

bool _desk_is_static = false;
void _desk_static() {
  if (!_desk_is_static) {
    _desk_is_static = true;
    Serial.println("set static success");

    String red = desk_static.substring(0, desk_static.indexOf(";"));
    String green = desk_static.substring(desk_static.indexOf(";") + 1, desk_static.indexOf(";;"));
    String blue = desk_static.substring(desk_static.indexOf(";;") + 2, desk_static.length());

    desk_pixel.clear();
    desk_pixel.fill(desk_pixel.Color(
      red.toInt(), green.toInt(), blue.toInt()
    ), 0, 50);
    desk_pixel.show();
  }
}

long _desk_rainbow_first_pixel_hue = 0;
unsigned long _desk_rainbow_previous_millis = 0;
void _desk_rainbow() {
  unsigned long current_millis = millis();
  if (current_millis - _desk_rainbow_previous_millis >= 10) {
    _desk_rainbow_previous_millis = current_millis;

    for (int a = 0; a < desk_pixel.numPixels(); a++) {
      int pixel_hue = _desk_rainbow_first_pixel_hue + 
        (a * 65536L / desk_pixel.numPixels());
        desk_pixel.setPixelColor(a, desk_pixel.gamma32(
          desk_pixel.ColorHSV(pixel_hue)));
    }
    desk_pixel.show();

    if (_desk_rainbow_first_pixel_hue < 5 * 65536) {
      _desk_rainbow_first_pixel_hue += 256;
    } else {
      _desk_rainbow_first_pixel_hue = 0;
    }
  }
}

uint32_t _desk_wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return desk_pixel.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return desk_pixel.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return desk_pixel.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

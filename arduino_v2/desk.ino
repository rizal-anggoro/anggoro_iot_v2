void deskTest() {
  desk_pixel.clear();
  for (int a = 0; a < 50; a++) {
    desk_pixel.setPixelColor(a, desk_pixel.Color(100, 0, 255));
  }
  desk_pixel.show();
}

String _desk_current_mode = "";

unsigned long _desk_breathing_previous_millis;
bool _desk_breathing_state_up = true;

void parseDesk() {
  // parse brightness
  if (desk_mode == "static" || desk_mode == "rainbow") {
    if (desk_pixel.getBrightness() != desk_brightness.toInt()) {
      desk_pixel.setBrightness(desk_brightness.toInt());
      desk_pixel.show();
    }
  }

  // parse mode
  // mode -> off
  if (desk_mode == "off") {
    desk_pixel.clear();
    desk_pixel.show();
  } 

  // mode -> static
  else if (desk_mode == "static") {
    if (_desk_current_mode != "static") {
      _desk_current_mode = "static";
      desk_pixel.clear();
      desk_pixel.fill(desk_pixel.Color(
        desk_static_red.toInt(),
        desk_static_green.toInt(),
        desk_static_blue.toInt()
      ), 0, 50);
      desk_pixel.show();
    }
  } 

  // mode -> breathing
  else if (desk_mode == "breathing") {
    unsigned long current_millis = millis();
    if (current_millis - _desk_breathing_previous_millis >= desk_breathing_interval.toInt()) {
      _desk_breathing_previous_millis = current_millis;

      desk_pixel.fill(desk_pixel.Color(
        desk_breathing_red.toInt(),
        desk_breathing_green.toInt(),
        desk_breathing_blue.toInt()
      ), 0, 50);
      
      int brightness = desk_pixel.getBrightness();
      if (_desk_breathing_state_up) {
        if (brightness < 255) {
          brightness++;
          desk_pixel.setBrightness(brightness);
          desk_pixel.show();
        } else if (brightness == 255) {
          _desk_breathing_state_up = false;
        }
      } else {
        if (brightness > 0) {
          brightness--;
          desk_pixel.setBrightness(brightness);
          desk_pixel.show();
        } else if (brightness == 0) {
          _desk_breathing_state_up = true;
        }
      }
    }
  }

  // mode -> color cycle
  else if (desk_mode == "color_cycle") {
    
  }

  // mode -> raibow
  else if (desk_mode == "rainbow") {
    _desk_rainbow();
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

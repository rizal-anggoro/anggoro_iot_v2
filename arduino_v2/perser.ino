void parser(String receive_data) {
  int a = receive_data.indexOf(";");
  int b = receive_data.lastIndexOf(";");
  String path = receive_data.substring(0, a);
  String data = receive_data.substring((a + 1), b);

  if (path != "/clock_data") {
    Serial.println(receive_data);
  }

  if (path == "/clock_data") {
    if (matrix_clock_data != data) {
      matrix_clock_data = data;
      byte bitmap[11];
      getBitmap(data, bitmap);
      matrixDisplayBitmap(bitmap);
    }
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

  // refresh desk pixel
  if (path.indexOf("/desk") != -1) {
    _desk_current_mode = "";
  }
}

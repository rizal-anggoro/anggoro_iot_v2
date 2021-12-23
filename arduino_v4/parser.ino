void parse(String receive_data) {
  int a = receive_data.indexOf(";");
  int b = receive_data.lastIndexOf(";");
  String path = receive_data.substring(0, a);
  String value = receive_data.substring((a + 1), b);

  // device -> desk
  if (path == "desk_mode") {
    desk_mode = value;
    if (value == "static") _desk_is_static = false;
  } else if (path == "desk_brightness") {
    desk_brightness = value;
  } else if (path == "desk_static") {
    desk_static = value;
    _desk_is_static = false;

  // device -> matrix
  } else if (path == "matrix_brightness") {
    matrix_brightness = value;
  } else if (path == "matrix_clock_data") {
    if (matrix_clock_data != value) {
      _matrix_is_clock_set = false;
      matrix_clock_data = value;
    }
  }
}

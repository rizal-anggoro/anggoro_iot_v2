void parseMatrix() {
  _matrix_brightness();
  
  // mode -> off
  if (matrix_mode == "off") {
    matrix_pixel.clear();
    matrix_pixel.show();
  }

  // mode -> clock
  else if (matrix_mode == "clock") {
    _matrix_clock();
  }
}

void _matrix_brightness() {
  if (matrix_pixel.getBrightness() != matrix_brightness.toInt()) {
    matrix_pixel.setBrightness(matrix_brightness.toInt());
    matrix_pixel.show();
  }
}

bool _matrix_is_clock_set = false;
void _matrix_clock() {
  if (!_matrix_is_clock_set) {
    _matrix_is_clock_set = true;
    
    byte bitmap[11];
    getBitmap(matrix_clock_data, bitmap);
    matrixDisplayBitmap(bitmap);
  }
}

void matrixDisplayBitmap(byte bitmap[11]) {
  matrix_pixel.clear();
  for (int a = 0; a < 11; a++) {
    byte b = bitmap[a];
    int c = 0;
    for (int d = 6; d >= 0; d--) {
      int e = matrix_pins[a][c];
      byte f = bitRead(b, d);
      matrix_pixel.setPixelColor(e, f == 1 ? matrix_pixel.Color(100, 0, 255) : 0);
      c++;
    }
  }
  matrix_pixel.show();
}

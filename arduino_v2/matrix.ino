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

void parser(String receive_data) {
  int a = receive_data.indexOf(";");
  int b = receive_data.lastIndexOf(";");
  String path = receive_data.substring(0, a);
  String data = receive_data.substring((a + 1), b);

  if (path == "/clock_data") {
    if (matrix_clock_data != data) {
      matrix_clock_data = data;
      byte bitmap[11];
      getBitmap(data, bitmap);
      matrixDisplayBitmap(bitmap);
    }
  }
}

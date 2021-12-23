void parser(String receive_data) {
  int a = receive_data.indexOf(";");
  int b = receive_data.lastIndexOf(";");
  String path = receive_data.substring(0, a);
  String value = receive_data.substring((a + 1), b);

  Serial.print("receive data: ");
  Serial.println(receive_data);

  if (path.length() > 0) {
    if (path == "matrix_clock_data") {
      if (matrix_clock_data != value) {
        matrix_clock_data = value;
        byte bitmap[11];
        getBitmap(matrix_clock_data, bitmap);
        matrixDisplayBitmap(bitmap);
      }
    } else {
      int key_index = _indexOfMapKey(path);
      map_value[key_index] = value;
  
//      _printMap(); 
    }
  }
}

int _indexOfMapKey(String s) {
  int a = -1;
  int b = sizeof(map_key) / sizeof(map_key[0]);
  for (int c = 0; c < b; c++) {
    if (map_key[c] == s) {
      a = c;
      break;
    }
  }
  return a;
}

void _printMap() {
  for (int a = 0; a < map_size; a++) {
    Serial.print(map_key[a]);
    Serial.print(": ");
    Serial.println(map_value[a]);
  }
}

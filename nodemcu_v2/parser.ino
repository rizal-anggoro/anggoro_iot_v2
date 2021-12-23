void parse(String path, String value) {
  int key_index = _indexOfMapKey(path);
  if (key_index != -1) {
    map_value[key_index] = value;
    
    // if path exists, send path and value to arduino
    sendSerial(path, value);
  }
  _printMap();
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
  int a = sizeof(map_key) / sizeof(map_key[0]);
  for (int b = 0; b < a; b++) {
    Serial.print(map_key[b]);
    Serial.print(": ");
    Serial.println(map_value[b]);
  }
}

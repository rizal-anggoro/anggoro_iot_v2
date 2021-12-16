#include "Segment.h"

#include <Arduino.h>

String Segment::getChar(String c, int i) {
  return c.substring(i, (i + 1));
}

int Segment::getCharIndex(String c) {
  return segment_chars.indexOf(c);
}

byte Segment::getData(int cIndex, int col) {
  return segment_data[cIndex][col];
}

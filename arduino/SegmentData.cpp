#include "SegmentData.h"

#include <Arduino.h>

String SegmentData::getChar(String c, int i) {
  return c.substring(i, (i + 1));
}

int SegmentData::getCharIndex(String c) {
  return segment_chars.indexOf(c);
}

byte SegmentData::getData(int cIndex, int col) {
  return segment_data[cIndex][col];
}

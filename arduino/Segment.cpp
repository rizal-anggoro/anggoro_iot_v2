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

void Segment::getBitmapFromData(String data, byte result[11]) {
  // clear result
  for (int a = 0; a < 11; a++) {
    result[a] = B00000000;
  }

  int index = 0;
  for (int a = 0; a < 3; a++) {
    // a == 0 --> segment top
    // a == 1 --> divider
    // a == 2 --> segment bottom
    if (a == 1) {
      result[index] = B00000000;
      index++;
    } else {
      for (int b = 0; b < 5; b++) {
        byte segment_per_row = B00000000;
        for (int c = 0; c < 3; c++) {
          // c == 0 --> segment left
          // c == 1 --> divider
          // c == 2 --> segment right

          int char_num = 
            a == 0 && c == 0 ? 0 : 
            a == 0 && c == 2 ? 1 :
            a == 2 && c == 0 ? 2 : 3;
            
          String ch = getChar(data, char_num);
          int ch_index = getCharIndex(ch);
          byte segment_value = getData(ch_index, b);
          
          if (c == 0) {
            segment_per_row |= segment_value;
          } else if (c == 1) {
            segment_per_row <<= 4;
          } else if (c == 2) {
            segment_per_row |= segment_value;
          }
        }
        result[index] = segment_per_row;
        index++;
      }
    }
  }
}

#ifndef SegmentData_h
#define SegmentData_h

#include <Arduino.h>

class SegmentData {
  private:
  String segment_chars;
  byte segment_data[2][5];
  
  public:
  String getChar(String c, int i);
  int getCharIndex(String c);
  byte getData(int cIndex, int col);
  
  SegmentData():
  segment_chars("0123456789-"),
  segment_data({
    {B00000111, B00000101, B00000101, B00000101, B00000111}, // 0
    {B00000001, B00000001, B00000001, B00000001, B00000001}, // 1
  }) {}
};

#endif

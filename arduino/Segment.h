#ifndef Segment_h
#define Segment_h

#include <Arduino.h>

class Segment {
  private:
  String segment_chars;
  byte segment_data[2][5];
  
  public:
  String getChar(String c, int i);
  int getCharIndex(String c);
  byte getData(int cIndex, int col);
  
  Segment():
  segment_chars("0123456789-"),
  segment_data({
    {B00000111, B00000101, B00000101, B00000101, B00000111}, // 0
    {B00000001, B00000001, B00000001, B00000001, B00000001}, // 1
    {B00000111, B00000001, B00000111, B00000100, B00000111}, // 2
    {B00000111, B00000001, B00000111, B00000001, B00000111}, // 3
    {B00000101, B00000101, B00000111, B00000001, B00000001}, // 4
    {B00000111, B00000100, B00000111, B00000001, B00000111}, // 5
    {B00000111, B00000100, B00000111, B00000101, B00000111}, // 6
    {B00000111, B00000001, B00000001, B00000001, B00000001}, // 7
    {B00000111, B00000101, B00000111, B00000101, B00000111}, // 8
    {B00000111, B00000101, B00000111, B00000001, B00000111}, // 9
    {B00000000, B00000000, B00000000, B00000000, B00000000}, // -
  }) {}
};

#endif

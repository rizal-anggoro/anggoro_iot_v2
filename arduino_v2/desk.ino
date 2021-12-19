void deskTest() {
  desk_pixel.clear();
  for (int a = 0; a < 50; a++) {
    desk_pixel.setPixelColor(a, desk_pixel.Color(100, 0, 255));
  }
  desk_pixel.show();
}

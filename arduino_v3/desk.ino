String _desk_current_mode = "";
void parseDesk() {
  String desk_mode = map_value[0];

  // mode -> off
  if (desk_mode == "off") {
    desk_pixel.clear();
    desk_pixel.show();
  }

  // mode -> static
  else if (desk_mode == "static") {
    if (_desk_current_mode != "static") {
      _desk_current_mode = "static";
      desk_pixel.clear();
      desk_pixel.fill(
        desk_pixel.Color(
          map_value[8].toInt(),
          map_value[9].toInt(),
          map_value[10].toInt()
        ),
        0, 50  
      );
      desk_pixel.show();
    }
  }

  // mode -> breathing
  else if (desk_mode == "breathing") {
    
  }
}

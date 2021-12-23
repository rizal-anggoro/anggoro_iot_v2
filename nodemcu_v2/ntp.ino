void beginNtp() {
  ntp_client.begin();
}

unsigned long _stream_ntp_previous_millis = 0;
void streamNtp() {
  unsigned long current_millis = millis();
  if (current_millis - _stream_ntp_previous_millis >= 1000) {
    _stream_ntp_previous_millis = current_millis;

    ntp_client.update();

    int hours = ntp_client.getHours();
    int minutes = ntp_client.getMinutes();
  
    String s_hours = "";
    if (hours < 10) s_hours = "-" + String(hours);
    else s_hours = String(hours);
    
    String s_minutes = "";
    if (minutes < 10) s_minutes = "0" + String(minutes);
    else s_minutes = String(minutes);
    
    String clock_data = s_hours + s_minutes;
    sendSerial("matrix_clock_data", clock_data);
  }
}

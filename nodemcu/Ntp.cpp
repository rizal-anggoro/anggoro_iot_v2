#include "Ntp.h"

void Ntp::begin() {
  ntpClient.begin();
}

String Ntp::getHMClock() {
  // update ntp client
  ntpClient.update();

  int hours = ntpClient.getHours();
  int minutes = ntpClient.getMinutes();

  String s_hours = "";
  if (hours < 10) s_hours = "-" + String(hours);
  else s_hours = String(hours);
  
  String s_minutes = "";
  if (minutes < 10) s_minutes = "0" + String(minutes);
  else s_minutes = String(minutes);
  
  String clock_data = s_hours + s_minutes;
  return clock_data;
}

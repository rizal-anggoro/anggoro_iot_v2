#ifndef Database_h
#define Database_h

#include <Arduino.h>
#include <FirebaseESP8266.h>

#include "Communication.h"

class Database {
  private:
  char* database_secret;
  char* database_url;
  FirebaseData firebase_data;
  FirebaseAuth firebase_auth;
  FirebaseConfig firebase_config;
  Communication communication;
    
  public:
  void begin();
  void stream();
  
  Database():
  database_secret("3xwIrBD1K77LowSPRd2OF7qLi49fwZlUVavSyyzG"),
  database_url("anggoro-iot-default-rtdb.firebaseio.com")
  {}
};

#endif

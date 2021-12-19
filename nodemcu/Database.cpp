#include "Database.h"

void Database::begin() {
  Serial.println("void: Database -> begin");
  
  firebase_config.database_url = database_url;
  firebase_config.signer.tokens.legacy_token = database_secret;
  
  Firebase.reconnectWiFi(true);
  Firebase.begin(&firebase_config, &firebase_auth);

  // begin firebase stream
  if (!Firebase.beginStream(firebase_data, "/bedroom")) {
    Serial.println("Firebase: begin stream error");
  }
}

void Database::stream() {
  if (Firebase.ready()) {
    if (!Firebase.readStream(firebase_data)) {
      Serial.println("Firebase: read stream error");
    }
    if (firebase_data.streamAvailable()) {
      String data_type = firebase_data.dataType();
      String data_path = firebase_data.dataPath();
      String data = String(firebase_data.stringData());

      if (data_type != "json") {
        // remove quote from data
        data.replace("\"", "");

        // add data path and data to private variable
        data_path_to_parse = data_path;
        data_to_parse = data;
        communication.send(data_path, data);

        DeskData::mode                  = parse("/desk/mode", DeskData::mode);
        DeskData::brightness            = parse("/desk/brightness", DeskData::brightness);
        DeskData::breathing_red         = parse("/desk/breathing/red", DeskData::breathing_red);
        DeskData::breathing_green       = parse("/desk/breathing/green", DeskData::breathing_green);
        DeskData::breathing_blue        = parse("/desk/breathing/blue", DeskData::breathing_blue);
        DeskData::breathing_interval    = parse("/desk/breathing/interval", DeskData::breathing_interval);
        DeskData::color_cycle_interval  = parse("/desk/color_cycle/interval", DeskData::color_cycle_interval);
        DeskData::rainbow_interval      = parse("/desk/rainbow/interval", DeskData::rainbow_interval);
        DeskData::static_red            = parse("/desk/static/red", DeskData::static_red);
        DeskData::static_green          = parse("/desk/static/green", DeskData::static_green);
        DeskData::static_blue           = parse("/desk/static/blue", DeskData::static_blue);
        
        MatrixData::mode                = parse("/matrix/mode", MatrixData::mode);
        MatrixData::brightness          = parse("/matrix/brightness", MatrixData::brightness);
      } else {
        parseJson(data);
      }
    }
  }
}

String Database::parse(String key, String def) {
  String a = def;
  if (data_path_to_parse.indexOf(key) != -1) {
    a = data_to_parse;
  }
  return a;
}

void Database::parseJson(String json) {
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, json);

  DeskData::mode                  = doc["desk"]["mode"].as<String>();
  DeskData::brightness            = doc["desk"]["brightness"].as<String>();
  DeskData::breathing_red         = doc["desk"]["breathing"]["red"].as<String>();
  DeskData::breathing_green       = doc["desk"]["breathing"]["green"].as<String>();
  DeskData::breathing_blue        = doc["desk"]["breathing"]["blue"].as<String>();
  DeskData::breathing_interval    = doc["desk"]["breathing"]["interval"].as<String>();
  DeskData::color_cycle_interval  = doc["desk"]["color_cycle"]["interval"].as<String>();
  DeskData::rainbow_interval      = doc["desk"]["rainbow"]["interval"].as<String>();
  DeskData::static_red            = doc["desk"]["static"]["red"].as<String>();
  DeskData::static_green          = doc["desk"]["static"]["green"].as<String>();
  DeskData::static_blue           = doc["desk"]["static"]["blue"].as<String>();
  
  MatrixData::mode                = doc["matrix"]["mode"].as<String>();
  MatrixData::brightness          = doc["matrix"]["brightness"].as<String>();
}

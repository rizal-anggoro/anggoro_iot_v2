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

        MatrixData::mode = parse("/matrix/mode");
        MatrixData::brightness = parse("/matrix/brightness");
      }

//      Serial.println("data type: " + data_type);
//      Serial.println("data path: " + data_path);
//      Serial.println("data: " + data);
    }
  }
}

String Database::parse(String key) {
  String a = "";
  if (data_path_to_parse.indexOf(key) != -1) {
    a = data_to_parse;
  }
  return a;
}

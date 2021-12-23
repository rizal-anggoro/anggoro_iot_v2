AsyncWebServer server(1306); // server port: 1306
void beginServer() {
  _streamServer();
  server.begin();
}

void _streamServer() {
  server.on("/bedroom", HTTP_GET, _handleRequest);
}

void _handleRequest(AsyncWebServerRequest *request) {
  if (request->hasParam("p") && request->hasParam("v")) {
    String path = request->getParam("p")->value();
    String value = request->getParam("v")->value();
    request->send(200);

    sendSerial(path, value);
  }
}

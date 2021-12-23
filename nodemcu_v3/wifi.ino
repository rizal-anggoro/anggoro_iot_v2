#define wifi_ssid "CELOSIA"
#define wifi_password "031298031298"

IPAddress local_ip(192, 168, 1, 136);   // ip   : 192.168.1.136
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 0, 0);
IPAddress dns(8, 8, 8, 8); 

void openWiFi() {
  if (!WiFi.config(local_ip, gateway, subnet, dns)) {
    Serial.println("STA failed to configure");
  }
  
  WiFi.begin(wifi_ssid, wifi_password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to: ");
  Serial.println(WiFi.localIP());
}

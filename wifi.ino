void wifiStart() {

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    if (MDNS.begin("esp8266")) {  //Start mDNS with name esp8266
      Serial.println("MDNS started");
    }
    return;
  }

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
};
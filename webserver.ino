const char *PARAM_MESSAGE = "message";
AsyncWebSocketClient *globalClient = NULL;

void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

String processor(const String &var) {
  //Serial.println(var);
  if (var == "IP_OF_PAGE") {
    String ip = WiFi.localIP().toString();
    return ip;
  }
  return String();
}



void onWsEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {

  if (type == WS_EVT_CONNECT) {

    Serial.println("Websocket client connection received");
    globalClient = client;

  } else if (type == WS_EVT_DISCONNECT) {

    Serial.println("Websocket client connection finished");
    globalClient = NULL;
  }
}


void sendWS() {
  if (globalClient) {
 
  StaticJsonDocument<384> wsData_;
String JsonStr="";
wsData_["name"] = sensorData.name;
wsData_["status"] = sensorData.status;
wsData_["temp"] = sensorData.temp;
wsData_["hum"] = sensorData.hum;

serializeJson(wsData_, JsonStr);


    globalClient->text(JsonStr);
  }
  // String randomNumber = String(random(0,20));
}


void serverHandle() {



  ws.onEvent(onWsEvent);
  server.addHandler(&ws);

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", webpage, processor);
  });

  // Send a GET request to <IP>/get?message=<message>
  server.on("/get", HTTP_GET, [](AsyncWebServerRequest *request) {
    String message;
    if (request->hasParam(PARAM_MESSAGE)) {
      message = request->getParam(PARAM_MESSAGE)->value();
    } else {
      message = "No message sent";
    }
    request->send(200, "text/plain", "Hello, GET: " + message);
  });

  // Send a POST request to <IP>/post with a form field message set to <message>
  server.on("/post", HTTP_POST, [](AsyncWebServerRequest *request) {
    String message;
    if (request->hasParam(PARAM_MESSAGE, true)) {
      message = request->getParam(PARAM_MESSAGE, true)->value();
    } else {
      message = "No message sent";
    }
    request->send(200, "text/plain", "Hello, POST: " + message);
  });

  server.onNotFound(notFound);

  server.begin();
}
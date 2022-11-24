#include <ArduinoOTA.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h>
#include "webPage.h"
#include <Wire.h>
#include <AHTxx.h>
#include <ArduinoJson.h>
#include <Timers.h>

Timers<4> timers;

String hostname = "ESP_Sensor";
const char* ssid = "|oioioio|";
const char* password = "pmgana921";


 struct __attribute__((packed)) dataStruct {
//struct wsDataStruct{
   String name;
   String status;
   int temp;
   int hum;
}sensorData;


float ahtValue;  //to store T/RH result

// config AHT board
AHTxx aht10(AHTXX_ADDRESS_X38, AHT1x_SENSOR);  //sensor address, sensor type

// config webserwer and websocket 
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void wifiStart();
void otaStart();
void serverHandle();
void printStatus();
void sendWS();
void ahtBegin();
void readSensorsAHT();

// int ahtTemp =0;
// int ahtHum = 0;
// String ahtState="initial";
// String ahtRoom= "kuchnia";



void setup() {

int interval= 3000;

  Serial.begin(115200);

  pinMode(0, OUTPUT);
  digitalWrite(0, LOW);

  wifiStart();
  otaStart();
  //serverHandle();
  ahtBegin();

  // setup timers multitasking 
  //timers.attach(0,interval*3,sendWS); 
  timers.attach(1,interval*2,readSensorsAHT); 

}

void loop() {

  ArduinoOTA.handle();
  timers.process();

}



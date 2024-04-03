#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Wire.h>

#define PINS_LED1 D4
#define PINS_LED2 D3

#define GY521_ADDRESS 0x68

const char* ssid = "NodeMCU AP";
const char* password = "nodemcu";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  Serial.print("Creating AP ");
  boolean result = WiFi.softAP(ssid, password);
  if (result == true) {
    Serial.println("Ready");
  } else {
    Serial.println("Failed!");
  }
}

void loop() {}
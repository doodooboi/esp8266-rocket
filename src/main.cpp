#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>

#include "html.h"

#define PINS_LED1 D4
#define PINS_LED2 D3

#define GY521_ADDRESS 0x68

const char* ssid = "NodeMCU AP";
const char* password = "nodemcu1234";

ESP8266WebServer server(80);

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

void handleRoot() {
	String page = MAIN_page;
	server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
	WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

	server.on("/", handleRoot);
	server.onNotFound(handle_NotFound);
	server.begin();
}

void loop() {
	server.handleClient();
}
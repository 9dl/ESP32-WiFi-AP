#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

const int blueLED = 2;

WebServer server(80);
DNSServer dnsServer;

const char *ssid = "HackThePlanet";
const char *password = "";

const char* webpage = "<html><body style='display: flex; justify-content: center; align-items: center; height: 100vh; margin: 0;'><h1 style='color:blue; font-size: 48px;'>Hack the Planet</h1></body></html>";

void handleRoot() {
  server.send(200, "text/html", webpage);
  digitalWrite(blueLED, HIGH);
}

void setup() {
  Serial.begin(115200);
  pinMode(blueLED, OUTPUT);
  digitalWrite(blueLED, LOW);
  
  WiFi.softAP(ssid, password);

  dnsServer.start(53, "*", WiFi.softAPIP());

  server.on("/", HTTP_GET, handleRoot);

  server.begin();
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();

  static bool isConnected = false;
  if (WiFi.softAPgetStationNum() > 0) {
    if (!isConnected) {
      digitalWrite(blueLED, HIGH);
      isConnected = true;
    }
  } else {
    if (isConnected) {
      digitalWrite(blueLED, LOW);
      isConnected = false;
    }
  }
}

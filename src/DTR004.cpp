#include "DTR004.h"

DTR004::DTR004(const char* ip, uint16_t port) {
  _ip = ip;
  _port = port;
}

void DTR004::setRelay(uint8_t relay, uint8_t state) {
  WiFiClient client;
  if (!client.connect(_ip, _port)) {
    Serial.println("DTR004: Relay command failed - Busy");
    return;
  }

  client.print(String("GET /relay_cgi.cgi?type=0&relay=") + relay +
               "&on=" + state + "&time=0&pwd= HTTP/1.1\r\n" +
               "Host: " + _ip + "\r\n" +
               "Connection: close\r\n\r\n");

  unsigned long timeout = millis();
  while (client.connected() && millis() - timeout < 2000) {
    while (client.available()) { client.read(); }
  }
  client.stop();
  delay(100); 
}

String DTR004::getInputs() {
  WiFiClient client;
  if (!client.connect(_ip, _port)) {
    return "Error: Unreachable";
  }

  client.print(String("GET /input.cgi HTTP/1.1\r\n") +
               "Host: " + _ip + "\r\n" +
               "Connection: close\r\n\r\n");

  String response = "";
  unsigned long timeout = millis();
  while (client.connected() && millis() - timeout < 2000) {
    while (client.available()) {
      response += (char)client.read();
    }
  }
  client.stop();

  int bodyStart = response.indexOf("\r\n\r\n");
  if (bodyStart != -1) {
    String body = response.substring(bodyStart + 4);
    body.trim();
    return body;
  }
  return "Error: No Data";
}

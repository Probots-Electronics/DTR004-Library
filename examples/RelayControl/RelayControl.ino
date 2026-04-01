#include <WiFi.h>
#include "DTR004.h"

const char* WIFI_SSID = "dtrelay65905";
const char* WIFI_PASS = "dtpassword";

// Create the relay object
DTR004 myRelay("192.168.7.1");

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print(".");}

  // Simple connection confirmation
  Serial.println("\nWiFi Connected"); 
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Use the library method
  myRelay.setRelay(0, 1); 
}

void loop() {
  // Check inputs every 2 seconds
  String status = myRelay.getInputs();
  Serial.println("Input Status: " + status);
  delay(2000);
}

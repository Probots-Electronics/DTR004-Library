# DTR004-Library

"Arduino/ESP32 library for the DT-R004 4-Channel WiFi/Ethernet Relay Module".

This library provides a simple interface to control relays and read digital inputs from the DT-R004 module using HTTP GET requests.

## Features
* **Relay Control**: Turn any of the 4 relays ON or OFF.
* **Input Status**: Read the real-time status of digital inputs.
* **Timeout Protection**: Built-in 2-second timeout to prevent code hangs during network issues.

  ## Example Usage

This basic sketch demonstrates how to initialize the module and toggle a relay. For more complex logic, see the [examples](https://github.com/Probots-Electronics/DTR004-Library/tree/main/examples) folder.

```cpp
#include <DTR004.h>

// Initialize with the device IP (Default: 192.168.1.100)
DTR004 relayBoard("192.168.1.100");

void setup() {
  Serial.begin(115200);
  
  // Turn ON Relay 1
  // Parameters: (relay_number, state) -> 1 is ON, 0 is OFF
  relayBoard.setRelay(1, 1); 
  Serial.println("Relay 1 has been activated.");
}

void loop() {
  // Fetch digital input states from the module
  String inputs = relayBoard.getInputs();
  Serial.println("Current Input Status: " + inputs);
  
  delay(5000); // Wait 5 seconds between polls
}

## Installation
1. Download this repository as a [.ZIP file](https://github.com/Darshan-BS-1/DTR004-Library/archive/refs/heads/main.zip).
2. In the Arduino IDE, go to **Sketch** > **Include Library** > **Add .ZIP Library...**.
3. Select the downloaded file.

#ifndef DTR004_H
#define DTR004_H

#include <Arduino.h>
#include <WiFi.h>

class DTR004 {
  private:
    const char* _ip;
    uint16_t _port;

  public:
    // Constructor
    DTR004(const char* ip, uint16_t port = 80);

    // Methods
    void setRelay(uint8_t relay, uint8_t state);
    String getInputs();
};

#endif

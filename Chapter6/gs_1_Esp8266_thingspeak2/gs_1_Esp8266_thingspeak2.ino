
#include "ESP8266.h"

#define SSID        "Jonghwa"
#define PASSWORD    "12345678"


ESP8266 wifi(Serial3);

void setup(void)
{
    Serial.begin(9600);
    Serial.print("setup begin\r\n");

    Serial.print("FW Version: ");
    Serial.println(wifi.getVersion().c_str());
    
    if (wifi.setOprToStation()) {
        Serial.print("to station ok\r\n");
    } else {
        Serial.print("to station err\r\n");
    }

    if (wifi.joinAP(SSID, PASSWORD)) {
        Serial.print("Join AP success\r\n");
        Serial.print("IP: ");       
        Serial.println(wifi.getLocalIP().c_str());
    } else {
        Serial.print("Join AP failure\r\n");
    }
    wifi.disableMUX();
    Serial.print("setup end\r\n");

    delay(3000);
}
#define HOST_NAME "api.thingspeak.com"
#define KEY "BSKHCTCNBDBLGFXM"
#define HOST_PORT (80)
int sendValue;
void loop(void)
{
   uint8_t buffer[1024] = {0};
   if (wifi.createTCP(HOST_NAME, HOST_PORT)) {
        Serial.print("create tcp ok\r\n");
   } else {
        Serial.print("create tcp err\r\n");
        return;
    }
    sendValue += 100;
    String http = String();
    http += "GET /update?key=";
    http += KEY;
    http += "&field1=" + String(sendValue);
    http += " HTTP/1.1\r\n";
    http += "Host: api.thingspeak.com\r\n";
    http += "Connection: close\r\n\r\n";

    Serial.println(http);
    wifi.send((const uint8_t*)http.c_str(), http.length());

    uint32_t len = wifi.recv(buffer, sizeof(buffer), 10000);
    if (len > 0) {
        Serial.print("Received:[");
        for(uint32_t i = 0; i < len; i++) {
            Serial.print((char)buffer[i]);
        }
        Serial.print("]\r\n");
    }

    if (wifi.releaseTCP()) {
        Serial.print("release tcp ok\r\n");
    } else {
        Serial.print("release tcp err\r\n");
    }
   
    delay(5000);
}

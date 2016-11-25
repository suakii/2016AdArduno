 
#include "ESP8266.h"
#define SSID        "Jonghwa"
#define PASSWORD    "12345678"

ESP8266 wifi(Serial3);
void setup()
{
  Serial.begin(115200);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);

  Serial.print("FW Version:");
  Serial.println(wifi.getVersion().c_str());

    if (wifi.setOprToStationSoftAP()) {
        Serial.print("to station + softap ok\r\n");
    } else {
        Serial.print("to station + softap err\r\n");
    }
    
    
    if (wifi.setSoftAPParam("minaGSHS", "12345678")) {
        Serial.print("to station + softap ok\r\n");
    } else {
        Serial.print("to station + softap err\r\n");
    }
    

    
    delay(500);    
    if (wifi.joinAP(SSID, PASSWORD)) {
        Serial.print("Join AP success\r\n");
        Serial.print("IP: ");
        Serial.println(wifi.getLocalIP().c_str());    
    } else {
        Serial.print("Join AP failure\r\n");
    }
    delay(500);
    
    if (wifi.enableMUX()) {
        Serial.print("multiple ok\r\n");
    } else {
        Serial.print("multiple err\r\n");
    }
    
    if (wifi.startTCPServer(8090)) {
        Serial.print("start tcp server ok\r\n");
    } else {
        Serial.print("start tcp server err\r\n");
    }
    
    if (wifi.setTCPServerTimeout(10)) { 
        Serial.print("set tcp server timout 10 seconds\r\n");
    } else {
        Serial.print("set tcp server timout err\r\n");
    }
    
    Serial.print("setup end\r\n"); 
}
 
void loop()
{
char buffer[256] = {0};
    uint8_t mux_id;
    uint32_t len = wifi.recv(&mux_id, buffer, sizeof(buffer), 100);
    if (len > 0) {
        Serial.print("Status:[");
        Serial.print(wifi.getIPStatus().c_str());
        Serial.println("]");
        
        Serial.print("Received from :");
        Serial.print(mux_id);
        Serial.print("[");
        /*
          Received from :0[GET /?pin=13 HTTP/1.1
        */
        for(uint32_t i = 0; i < len; i++) {
            Serial.print(buffer[i]);
        }
        Serial.print("]\r\n");
        //
        String str(buffer);
        int start = str.indexOf("pin=");
        int pinNumber = (str[start+4] -'0')*10;
        pinNumber += (str[start+5] -'0');
        Serial.print("Pin Number: ");
        Serial.println(pinNumber);
        if (0< pinNumber && pinNumber < 14)
          digitalWrite(pinNumber, !digitalRead(pinNumber)); // toggle pin    
      
        //
        
        
        if (wifi.releaseTCP(mux_id)) {
            Serial.print("release tcp ");
            Serial.print(mux_id);
            Serial.println(" ok");
        } else {
            Serial.print("release tcp");
            Serial.print(mux_id);
            Serial.println(" err");
        }
        
        Serial.print("Status:[");
        Serial.print(wifi.getIPStatus().c_str());
        Serial.println("]");
    }

  
}


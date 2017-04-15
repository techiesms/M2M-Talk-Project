/*
   I have made this project using

   ESP8266 module,PIR module and a piezo buzzer.

   Watch out it's DIY project video on my YouTube Channel

   Search for "techiesms" on YouTube.

*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define pir 2  //GPIO 2
const char* ssid ="ESPap";
const char* password ="thereisnospoon";
void setup() {

    Serial.begin(115200);
   // Serial.setDebugOutput(true);

    Serial.println();
    Serial.println();
    Serial.println();

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }
      WiFi.mode(WIFI_STA);
      WiFi.disconnect(true);
    WiFi.begin(ssid,password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");

    pinMode(pir,INPUT);
    delay(15000);
    Serial.println("Connected");
  }

}

void loop() {
    // wait for WiFi connection
    if((WiFi.status() == WL_CONNECTED)) {

        HTTPClient http;

        if(digitalRead(pir) == HIGH)
        {
          
        
        Serial.print("[HTTP] begin...\n");
        // requesting required link 
        http.begin("http://192.168.4.1/pir"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        http.end();
        } 

        
    }
    }

   



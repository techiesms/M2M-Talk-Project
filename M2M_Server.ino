/*
   I have made this project using

   ESP8266 module,PIR module and a piezo buzzer.

   Watch out it's DIY project video on my YouTube Channel

   Search for "techiesms" on YouTube.

*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "thereisnospoon";

ESP8266WebServer server(80);

/*
    waiting for the link 192.168.4.1/pir
*/
void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected</h1>");
}

void led()
{
  Serial.println("Link Requested from one of the device");

  for (int i = 0; i < 5; i++)
  {
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(500);
  }

}
void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);
  pinMode(2, OUTPUT); //GPIO 2
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/led", led);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  Serial.println("Waiting for the link");
  server.handleClient();
}

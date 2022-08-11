/**
 * author - Rahul Chandrashekar
 * General Public License v3.0
 * (c) 2022 - all rights reserved
 * 
*/

// Libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiManager.h> 

#include "index.h";

// webserver
ESP8266WebServer server ( 80 );

void setup() {

  WiFi.mode(WIFI_STA); 
  WiFiManager wm;
  // Start serial, you can choose the baud-rate based on your requirement
  Serial.begin(19200);
  delay(10);

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  bool res;
    res = wm.autoConnect("MyKit"); // accesspoint

    if(!res) {
        Serial.println("Failed to connect");
    } 
    else {
      // set new WiFi SSID and Password
      String ssid = wm.getWiFiSSID();
      String pass = wm.getWiFiPass();
        Serial.println(WiFi.macAddress ());
        Serial.println();
        Serial.println();
        Serial.print("Connecting to ");
        Serial.println(ssid);
        Serial.println("");
        Serial.println("WiFi connected");  
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());

        //get browser status
        server.on("/status",getBrowserStatus);

        server.begin();
    }

}//setup

void loop() {
server.handleClient();

}//loop

/**
 * this method broadcasts message from the browser and activty every 1 sec.
 * User can use this method and implement based on your requirement
 */
void getBrowserStatus(){
  String browserStatus = server.arg("active");
  Serial.println(browserStatus);
   
}//getBrowserStatus

/*
 * ESP8266 workshop
 * 
 * First module / First activity
 * 
 * Overview:
 * How to scan wifi, connect to it, and
 * 
 * Requires:
 * ESP8266
 * OLED screen
 * 
 * Written by nacosta-cl for LR
 */
#include<ESP8266WiFi.h>

void setup(){
  Serial.begin(115200);
  Serial.println("[i] Alive!");
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
}

void loop(){
  Serial.println("[i] Scanning networks");
  int n = WiFi.scanNetworks();
  Serial.println("[i] Scan done");
  if (n == 0)  {
    Serial.println("[!] No networks found, searching for more");
    return;
  } else {
    Serial.println("[i] ");
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i){
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  Serial.println("[i] Choose network"); 
  while(!Serial.available()) int k = 0;
  String ssid = Serial.readString();
  Serial.println("[i] Password");
  while(!Serial.available()) int k = 0;
  String pass = Serial.readString();
  
  WiFi.begin(ssid.c_str(), pass.c_str());
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("[+] Connected");
  while(true){
    yield();
  }
}


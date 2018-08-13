/*
 * ESP8266 workshop
 * 
 * First module / First activity
 * 
 * Write hello world on the OLED
 * Overview:
 * How to use wifi, scan networks, and connect to an API
 * 
 * Requires:
 * ESP8266
 * OLED screen
 * 
 * Written by nacosta-cl for LR
 */
#include <ESP8266WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Ajustar Adafruit_SSD1306.h a 64x48

Adafruit_SSD1306 display(99);

const char* ssid     = "Qdeli";
const char* password = "lr134679";
void setup(){
  Serial.begin(115200);
  Serial.println("[i] Alive!");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(1,0);
  display.println("Iniciado");
  //Modo cliente
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  bool spinner = false;
  display.setCursor(0,1);
  //Conectarme
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    display.clearDisplay();
    display.setCursor(0,1);
    if(spinner){
      display.print("|");
    }else{
      display.print("-");
    }
    display.display();
    spinner = !spinner;
  }
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Conectado!");
  display.println(WiFi.localIP());
  display.display();
  //Request
  //String url = "/input/";
  /*url += streamId;
  url += "?private_key=";
  url += privateKey;
  url += "&value=";
  url += value;*/
  //Conexion a cliente
  WiFiClientSecure client;
  const int httpsPort = 443;  
  const char* host = "catfact.ninja";
  if (!client.connect(host,httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  Serial.print("Requesting URL: ");
  
  String url = "/fact";
  
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
}

void loop(){
  
}


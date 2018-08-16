/*
 * ESP8266 workshop
 * 
 * First module / First activity
 * 
 * Write hello world on the OLED
 * Overview:
 * How to connect to a wifi, and connect to an API
 * 
 * Requires:
 * ESP8266
 * OLED screen
 * 
 * Written by nacosta-cl for LR
 */

 //For example, a ESP8266 has 4KB of stack memory.
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Ajustar Adafruit_SSD1306.h a 64x48
DynamicJsonBuffer jsonBuffer;
Adafruit_SSD1306 display(99);

const char* ssid     = "Qdeli";
const char* password = "lr134679";
void setup(){
  Serial.begin(115200);
  Serial.println("");
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
    Serial.println("loop");
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
  //Fabricamos la URL
  Serial.print("URL: ");
  String url = "/fact?max_length=60";
  //url = "/fact?max_length=25";
  Serial.println(url);
  String request = String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n";
  // Enviamos el request
  client.print(request);
  
  unsigned long timeout = millis();
  
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println("[!] Timeout");
      client.stop();
      return;
    }
  }
  String ans; //Lineas
  String json; //Respuesta final
  // Read all the lines of the reply from server and print them to Serial
  timeout = millis() + 1000;
  while(client.available()){
    ans = client.readStringUntil('\r');
    if(ans.indexOf('{')!=-1){
      json = ans;
      break;
    }
    if(timeout < millis()){
      Serial.println("done");
      break;
    }
    Serial.print(ans);
  }
  
  Serial.print("STATUS = ");
  Serial.println(client.status());
  client.stop();
  Serial.println(json.indexOf('{'));
  String response = json.substring(json.indexOf("{"));
  //Serial.print("Respuesta: ");
  //Serial.println(response);

  Serial.println("Conexion cerrada");
  JsonObject& root = jsonBuffer.parseObject(response);
  if (!root.success()) {
    Serial.println(F("JSON mal formateado"));
  }
  // Extract values
  Serial.println(F("Respuesta:"));
  Serial.println(root["fact"].as<char*>());
  Serial.println(root["length"].as<char*>());
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(root["fact"].as<char*>());
  display.display();
  /*
  Serial.println(root["time"].as<char*>());
  Serial.println(root["data"][0].as<char*>());
  Serial.println(root["data"][1].as<char*>());
  */

  
}

void loop(){
  
}


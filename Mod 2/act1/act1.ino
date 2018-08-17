/*
 * 
 * 
 * 
 * Requirements:
 * ESP8266
 * OLED
 * Telegram bot:
 *  Ask botfather for this
 */
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266HTTPClient.h>

//Ajustar Adafruit_SSD1306.h a 64x48
DynamicJsonBuffer jsonBuffer;
Adafruit_SSD1306 display(99);

const char* ssid     = "test";
const char* password = "testtest";

HTTPClient http;

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
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  /*
   * We got to grab our fingerprint from the certificate in telegram website
   */
  bool result = http.begin("https://api.telegram.org/bot623979786:AAHbuCHdRIQn4lSHbz_T20uzGtX8NGJW60U/getMe", "bbdc452a07e34a71334032dabe81f7726f4a2b6b");
  int httpCode = http.sendRequest("GET");
  delay(1500);
  Serial.println("[i] Init");
  Serial.println(result);
  Serial.println(httpCode);
  String response = http.getString();
  Serial.println(response);
  JsonObject& root = jsonBuffer.parseObject(response);
  if (!root.success()) {
    Serial.println(F("JSON mal formateado"));
  }
  // Extract values
  Serial.println(F("Respuesta:"));
  Serial.println(root["result"]["first_name"].as<char*>());
  Serial.println(root["result"]["username"].as<char*>());
  Serial.println(root["ok"].as<char*>());
  Serial.println("----");
  http.end();
}

void loop(){
  
}


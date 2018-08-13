/*
 * ESP8266 workshop
 * 
 * First module / First activity
 * 
 * Write hello world on the OLED
 * Overview:
 * This activity intends to show the student on how to use the Arduino IDE, and to load a program to ESP
 * Also, it will show you how to avoid common errors on the ESP8266 programming
 * Requires:
 * ESP8266
 * OLED screen
 * 
 * Written by nacosta-cl for LR
 */
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Ajustar Adafruit_SSD1306.h a 64x48

Adafruit_SSD1306 display(99);

void setup(){
  char buff[15];
  Serial.begin(115200);
  Serial.println("[i] Alive!");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Exito!");
  snprintf(buff,sizeof(buff),"Mem=%i",ESP.getFreeHeap());
  display.println(buff);
  memset(buff,0,sizeof(buff));
  display.println(ESP.getChipId());
  display.println(ESP.getFlashChipRealSize());
  display.println(ESP.getCoreVersion());
  display.println("-----o-----");
  display.display();
  while(true){ //Loop de la muerte
    Serial.println("loop");
    //yield();
  }
  delay(50000);
  ESP.reset(); //HARD
  ESP.restart(); //soft
//ms,mode!  
}
void loop(){
  
}
 

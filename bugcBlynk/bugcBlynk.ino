#define BLYNK_TEMPLATE_ID           "TMPLvWx7Es3n"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "xqa25zWWyklwSAAJ_HalX3ZTntyd66nz"

#define BLYNK_PRINT Serial

#include <M5StickC.h>
#include <WiFi.h>
//#include <rpcWiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "bugC.h"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "yourssid";
char pass[] = "yourpasswd";

int frontValue = 0;
int backValue = 0;
int leftValue = 0;
int rightValue = 0;

int speedValue = 0;

void setup() 
{
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    
    M5.begin();
    Wire.begin(0, 26); //for BUGC
    
    // if add battery, need increase charge current
    M5.Axp.SetChargeCurrent(CURRENT_360MA);

    M5.Lcd.setRotation(3); 
    M5.Lcd.setCursor(0, 0, 4);
    M5.Lcd.print("BUGC");
}

BLYNK_WRITE(V0)
{
  frontValue = param.asInt(); // assigning incoming value from pin V0 to a variable

  Serial.print("V0: ");
  Serial.println(frontValue);
}

BLYNK_WRITE(V2)
{
  backValue = param.asInt(); // assigning incoming value from pin V2 to a variable

  Serial.print("V2: ");
  Serial.println(backValue);
}

BLYNK_WRITE(V3)
{
  leftValue = param.asInt(); // assigning incoming value from pin V3 to a variable

  Serial.print("V3: ");
  Serial.println(leftValue);
}

BLYNK_WRITE(V4)
{
  rightValue = param.asInt(); // assigning incoming value from pin V4 to a variable

  Serial.print("V4: ");
  Serial.println(rightValue);
}

BLYNK_WRITE(V1)
{
  speedValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  Serial.print("V1 Slider value is: ");
  Serial.println(speedValue);
}

void loop() 
{
  Blynk.run();
  M5.update();

  if (M5.BtnB.wasPressed()) {
    M5.Axp.PowerOff();
  }

  if(frontValue){
    BugCSetColor(0x100000, 0x001000);
    BugCSetAllSpeed(-1*speedValue, speedValue, -1*speedValue, speedValue);
    delay(100);
  }else if(backValue){
    BugCSetColor(0x100000, 0x001000);
    BugCSetAllSpeed(speedValue, -1*speedValue, speedValue, -1*speedValue);
    delay(100);
  }else if(leftValue){
    BugCSetColor(0x100000, 0x001000);
    BugCSetAllSpeed(-1*speedValue, -1*speedValue, speedValue, speedValue);
    delay(100);
  }else if(rightValue){
    BugCSetColor(0x100000, 0x001000);
    BugCSetAllSpeed(speedValue, speedValue, -1*speedValue, -1*speedValue);
    delay(100);
  }else{
    BugCSetColor(0x000000, 0x000000);
    BugCSetAllSpeed(0, 0, 0, 0);
    delay(100);
  }
}

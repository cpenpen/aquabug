//-------------------------------------------------------------------------------
// This is a test sketch for the DLS 2.0 shield
// Dead Bug Protorypes
// 07.02.2014
//-------------------------------------------------------------------------------
// revised by andzer, 15.10.2019

#include <Wire.h>
#include <SD.h>
#include <OneWire.h>
#include <SFE_BMP180.h>
#define DS1337_ADDRESS      0x68
#define ONE_WIRE_BUS        4
#define SD_CHIPSELECT       8
#define POWEROFF            7

String strLogline = "";

void setup()
{
  Serial.begin(9600);
  pinMode(POWEROFF, OUTPUT);
  digitalWrite(POWEROFF, HIGH);
  delay(1000);
  GetDate();
  getTemp();
  GetPressure();
  GetHeight();
  WriteSD();
}

void loop()
{
  while (true)
  {
    SetAlarmMin(60); // Set the wakeup to 60 minutes
    digitalWrite(POWEROFF, LOW);
    delay(500);
  }

}

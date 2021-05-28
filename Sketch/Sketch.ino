/*
 Name:		Sketch.ino
 Created:	3/29/2020 2:18:03 PM
 Author:	Liam
*/
#include <LiquidCrystal.h>
#include "HardwareSerial.h"
#include "lever.h"
#include "turnout.h"

const int leverCount = 6;
const int leverStartPin = 22;

const int turnoutCount = 6;
const int turnoutStartPin = 2;
const int LEDStartPin = 32;

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

byte thrownChar[] = {
  B10010,
  B10010,
  B00010,
  B00100,
  B01000,
  B10000,
  B10000,
  B10000
};

byte closedChar[] = {
  B10010,
  B10010,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
};

lever levers[leverCount] = {
    {0 + leverStartPin},
    {1 + leverStartPin},
    {2 + leverStartPin}
};

turnout turnouts[turnoutCount] = {
    {0, levers[0], 0 + turnoutStartPin, 0 + LEDStartPin},
    {1, levers[1], 1 + turnoutStartPin, 1 + LEDStartPin},
    {2, levers[2], 2 + turnoutStartPin, 2 + LEDStartPin}
};

// the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < turnoutCount; i++)
    {
        turnouts[i].setup();
    }

    for (int i = 0; i < leverCount; i++)
    {
        levers[i].setup();
    }

    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("0 1 2 3 4 5");

    lcd.createChar(0, thrownChar);
    lcd.createChar(1, closedChar);
}

// loop function runs over and over again until power down or reset
void loop()
{
    if (Serial.available() > 0)
    {
        int i = atoi(Serial.readString().c_str());
        turnouts[i].toggle();
    }

    for (int i = 0; i < turnoutCount; i++)
    {
        turnouts[i].checkInputs();
        
        lcd.setCursor(2 * i, 1);
        if (turnouts[i].getState())
        {
          
          lcd.write(byte(0));
        }
        else
        {
          lcd.write(byte(1));
        }
    }
}

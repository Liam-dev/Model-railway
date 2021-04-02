/*
 Name:		Sketch.ino
 Created:	3/29/2020 2:18:03 PM
 Author:	Liam
*/
#include "HardwareSerial.h"
#include "lever.h"
#include "turnout.h"

const int leverCount = 4;
const int turnoutCount = 4;
const int turnoutStartPin = 10;
const int leverStartPin = 2;

lever levers[leverCount] = {{0 + leverStartPin}, {1 + leverStartPin}, {2 + leverStartPin}, {3 + leverStartPin}};
turnout turnouts[turnoutCount] = {{0 + turnoutStartPin, &levers[0], 6}, {1 + turnoutStartPin, &levers[1], 0}, {2 + turnoutStartPin, &levers[2], 0}, {3 + turnoutStartPin, &levers[3], 0}};

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
    }
}
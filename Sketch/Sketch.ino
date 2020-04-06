/*
 Name:		Sketch.ino
 Created:	3/29/2020 2:18:03 PM
 Author:	Liam
*/
#include "Switch.h"
#include "Turnout.h"

const int switchCount = 4;
const int turnoutCount = 4;
const int turnoutStartPin = 10;
const int switchStartPin = 2;

Switch switches[switchCount] = {{0 + switchStartPin}, {1 + switchStartPin}, {2 + switchStartPin}, {3 + switchStartPin}};
Turnout turnouts[turnoutCount] = {{0 + turnoutStartPin, &switches[0]}, {1 + turnoutStartPin, &switches[1]}, {2 + turnoutStartPin, &switches[2]}, {3 + turnoutStartPin, &switches[3]}};


// the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < turnoutCount; i++)
    {
        turnouts[i].setup();
    }

    for (int i = 0; i < switchCount; i++)
    {
        switches[i].setup();
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

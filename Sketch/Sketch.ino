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
Turnout turnouts[turnoutCount] = {{0 + turnoutStartPin, switches[0]}, {1 + turnoutStartPin, switches[1]}, {2 + turnoutStartPin, switches[2]}, {3 + turnoutStartPin, switches[3]}};


// the setup function runs once when you press reset or power the board
void setup()
{
    Serial.begin(9600);
    Serial.println("Serial working!");

    for (int i = 0; i < switchCount; i++)
    {
        switches[i].setup();
    }

    for (int i = 0; i < turnoutCount; i++)
    {
        turnouts[i].setup();
    }

}

// loop function runs over and over again until power down or reset
void loop()
{

    for (int i = 0; i < turnoutCount; i++)
    {
        turnouts[i].main();
    }
}

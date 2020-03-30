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

Switch switches [switchCount] = {Switch(0), Switch(1), Switch(2), Switch(3)};
Turnout turnouts [turnoutCount] = {Turnout(0, switches[0]), Turnout(1, switches[1]), Turnout(2, switches[2]), Turnout(3, switches[3])};

// the setup function runs once when you press reset or power the board
void setup()
{
    for (Switch s : switches)
    {
        s.setup();
    }

    for (Turnout t : turnouts)
    {
        t.setup();
    }
}

// the loop function runs over and over again until power down or reset
void loop()
{
    for (Turnout t : turnouts)
    {
        t.main();
    }
}

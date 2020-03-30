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

// the setup function runs once when you press reset or power the board
void setup()
{
    Switch switches [switchCount] = {Switch(), Switch(), Switch(), Switch()};
    Turnout turnouts [turnoutCount] = {Turnout(), Turnout(), Turnout(), Turnout()};
}

// the loop function runs over and over again until power down or reset
void loop()
{
    for (Turnout t : turnouts)
    {
        t.main();
    }
}

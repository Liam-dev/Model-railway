/*
 Name:		Sketch.ino
 Created:	3/29/2020 2:18:03 PM
 Author:	Liam
*/
#include "Switch.cpp";
#include "Turnout.cpp";

const int switchCount = 4;
const int turnoutCount = 4;
const int turnoutStartPin = 10;
const int switchStartPin = 2;
/*
Switch switches [switchCount] = {{0}, {1}, {2}, {3}};
Turnout turnouts [turnoutCount] = {{0, switches[0]}, {1, switches[1]}, {2, switches[2]}, {3, switches[3]}};
*/

// the setup function runs once when you press reset or power the board
void setup()
{
    /*
    for (Switch s : switches)
    {
        s.setup();
    }

    for (Turnout t : turnouts)
    {
        t.setup();
    }
    */
}

// loop function runs over and over again until power down or reset
void loop()
{
    /*
    for (Turnout t : turnouts)
    {
        t.main();
    }
    */
}

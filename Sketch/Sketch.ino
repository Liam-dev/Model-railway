/*
 Name:		Sketch.ino
 Created:	3/29/2020 2:18:03 PM
 Author:	Liam
*/

const int switchCount;
const int turnoutCount;
const int turnoutStartPin;
const int switchStartPin;

Switch switches [switchCount];
Turnout turnouts [turnoutCount];

// the setup function runs once when you press reset or power the board
void setup()
{
    switches = {Switch, Switch, Switch, Switch};
    turnouts = {Turnout, Turnout, Turnout, Turnout};
}

// the loop function runs over and over again until power down or reset
void loop()
{
    for (Turnout t : turnouts)
    {
        t.main();
    }
}

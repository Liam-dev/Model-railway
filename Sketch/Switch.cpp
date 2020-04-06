#include "Switch.h"

Switch::Switch()
{
    pin = 0;
    powered = false;
    readDelay = 50;
}

Switch::Switch(int n)
{
    pin = n;
    powered = false;
    readDelay = 50;
}

void Switch::setup()
{
    pinMode(pin, INPUT);
    powered = digitalRead(pin);
}

void Switch::setReadDelay(int delay)
{
    readDelay = delay;
}

bool Switch::detectChange()
{
    bool change = false;
    bool reading = digitalRead(pin);
    change = (reading != powered);
    delay(readDelay);

    powered = reading;
    return change;
}

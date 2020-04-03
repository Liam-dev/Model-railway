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
    Serial.print("Switch ");
    Serial.print(pin);
    Serial.println(" setup!");
    Serial.println(powered);
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

    if (change)
    {
        delay(50);
        Serial.print("Change detected on ");
        Serial.println(pin);
    }

    powered = reading;

    return change;
}

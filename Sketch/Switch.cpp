#include "Switch.h"

Switch::Switch()
{
    pin = 0;
    powered = false;
}

Switch::Switch(int n)
{
    pin = n;
    powered = false;
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

bool Switch::detectChange()
{
    bool change = false;
    bool reading = digitalRead(pin);
    change = (reading != powered);

    if (change)
    {
        Serial.print("Change detected on ");
        Serial.println(pin);
    }

    powered = reading;
    delay(50);
    return change;
}

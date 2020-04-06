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
}

void Switch::setReadDelay(int delay)
{
    readDelay = delay;
}

bool Switch::detectChange()
{
    Serial.println(powered);
    bool change = false;
    bool reading = digitalRead(pin);
    change = (reading != powered);
    delay(readDelay);
    //Serial.print("Switch ");
    //Serial.println(pin);
    //Serial.println(powered);
    Serial.println(reading);
    Serial.println(change);
    
    powered = reading;

    return change;
}

bool Switch::isPowered()
{
    return powered;
}

#include "lever.h"

lever::lever()
{
    pin_ = 0;
    bPowered_ = false;
    readDelay_ = 50;
}

lever::lever(int pin)
{
    pin_ = pin;
    bPowered_ = false;
    readDelay_ = 50;
}

void lever::setup()
{
    pinMode(pin_, INPUT);
    bPowered_ = digitalRead(pin_);
}

void lever::setReadDelay(int delay)
{
    readDelay_ = delay;
}

bool lever::detectChange()
{
    bool change = false;
    bool reading = digitalRead(pin_);
    change = (reading != bPowered_);
    delay(readDelay_);

    bPowered_ = reading;
    return change;
}
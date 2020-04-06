#include "Turnout.h"

Turnout::Turnout()
{
    pin = 0;
    number = 0;
}

Turnout::Turnout(int n, Switch* s)
{
    pin = n;
    number = n;
    lever = s;
}

void Turnout::saveToEEPROM()
{
    EEPROM.write(number, thrown);
}

void Turnout::readFromEEPROM()
{
    bool state = EEPROM.read(number);
    set(state);
}

void Turnout::writePins()
{
    digitalWrite(pin, thrown);
}

void Turnout::update()
{
    writePins();
    saveToEEPROM();
}

void Turnout::checkSwitch()
{
    if (lever->detectChange())
    {
        toggle();
    }
}

void Turnout::checkSerial()
{
    /*
    if (Serial.available() > 0)
    {
        if (Serial.read() == number)
        {
            toggle();
        }
    }
    */
}

void Turnout::setup()
{
    pinMode(pin, OUTPUT);
    readFromEEPROM();
}

void Turnout::set(bool state)
{
    thrown = state;
    update();
}

void Turnout::toggle()
{
    thrown = !thrown;
    update();
    Serial.print("Turnout ");
    Serial.print(number);
    Serial.println(" toggled");
}

void Turnout::checkInputs()
{
    checkSwitch();
    checkSerial();
}

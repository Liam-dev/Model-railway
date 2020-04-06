#include "Turnout.h"

Turnout::Turnout()
{
    pin = 0;
    number = 0;
    lever = Switch();
}

Turnout::Turnout(int n, Switch s)
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
    Serial.println(lever.isPowered());
    if (lever.detectChange())
    {
        Serial.print("Turnout ");
        Serial.print(number);
        Serial.println(" toggled!");
        toggle();
    }
}

void Turnout::checkSerial()
{
    {}
}

void Turnout::setup()
{
    pinMode(pin, OUTPUT);
    readFromEEPROM();
    Serial.print("Turnout ");
    Serial.print(number);
    Serial.println(" setup!");
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
}

void Turnout::checkInputs()
{
    Serial.println(lever.isPowered());
    checkSwitch();
    checkSerial();
}

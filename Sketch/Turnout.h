#ifndef Turnout_h
#define Turnout_h

#include <Arduino.h>
#include <EEPROM.h>
#include "Switch.h"

class Turnout
{
    private:
        int pin;
        bool thrown;
        int number;
        Switch lever;

        void saveToEEPROM();
        void readFromEEPROM();

        void writePins();

        void update();

        void checkSwitch();
        void checkSerial();


    public:
        Turnout();
        Turnout(int n, Switch s);

        void setup();

        void set(bool state);
        void toggle();

        void checkInputs();

        void main();
};
#endif

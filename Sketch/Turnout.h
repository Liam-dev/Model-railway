#ifndef turnout_h
#define turnout_h

#include <Arduino.h>
#include <EEPROM.h>
#include <Servo.h>
#include "lever.h"

class turnout
{
    private:
        int id_;
        int LEDPin_;
        int servoPin_;
        bool bThrown_;
        lever* plever_;
        Servo servo_;

        void saveToEEPROM();
        void readFromEEPROM();

        void writePins();

        void update();

        void checkLever();
        void checkSerial();


    public:
        turnout();
        turnout(int id, lever* l, int servo);

        void setup();

        void set(bool state);
        void toggle();

        void checkInputs();

        void main();
};
#endif

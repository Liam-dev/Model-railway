#include <EEPROM.h>;
#include "Switch.cpp";

class Turnout
{
    private:
        int pin;
        bool thrown;
        int number;
        Switch lever;

        void saveToEEPROM()
        {
            EEPROM.write(number, thrown);
        }

        void readFromEEPROM()
        {
            bool state = EEPROM.read(number);
            set(state);
        }

        void writePins()
        {
            digitalWrite(pin, thrown);
        }

        void update()
        {
            writePins();
            saveToEEPROM();
        }

        void checkSwitch()
        {
            if (lever.detectChange())
            {
                toggle();
            }
        }

        void checkSerial()
        {
            {}
        }

    public:
		Turnout(int n, Switch s)
        {
            pin = n;
            number = n;
            lever = s;
        }

        void setup()
        {
          pinMode(pin, OUTPUT);
            readFromEEPROM();
        }

        void set(bool state)
        {
            thrown = state;
            update();
        }

        void toggle()
        {
            thrown = !thrown;
            update();
        }

        void checkInputs()
        {
            checkSwitch();
            checkSerial();
        }

        void main()
        {
            checkInputs();
            saveToEEPROM();
        }
};

#include <EEPROM.h>;

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
        };

        void readFromEEPROM()
        {
            bool state = EEPROM.read(number);
            set(state);
        };

        void writePins()
        {
            digitalWrite(pin, thrown);
        };

        void update()
        {
            writePins();
            saveToEEPROM();
        };

        void checkSwitch()
        {
            if (lever.detectChange())
            {
                toggle();
            }
        };

        void checkSerial()
        {
            {}
        };

    public:

		Turnout()
        {
            pinMode(pin, OUTPUT);
            bool state = readFromEEPROM();
            set(state);
        };

        void set(bool state)
        {
            thrown = state;
            update();
        };

        void toggle()
        {
            thrown = !thrown;
            update();
        };

        void checkInputs()
        {
            checkSwitch();
            checkSerial();
        };

        void main()
        {
            checkInputs();
            saveToEEPROM();
        };
};

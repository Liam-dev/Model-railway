#include <EEPROM.h>;

class Turnout
{
    private:
        bool thrown;
        int number;
        Switch switch;

        void saveToEEPROM()
        {
            EEPROM.write(number, thrown);
        };

        void readFromEEPROM()
        {
            bool state = EEPROM.read(number);
            throw(state);
        };

        void writePins()
        {
            digitalWrite(number + startPin, thrown);
        };

        void update()
        {
            writePins();
            saveToEEPROM();
        };

        void checkSwitch()
        {
            if (switch.detectChange())
            {
                toggle();
            }
        };

        void checkSerial()
        {
            {}
        };

    public:
        static int startPin;

		Turnout(bool state) { set(state); };

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

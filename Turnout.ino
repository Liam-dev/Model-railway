#include <EEPROM.h>;

class Turnout
{
    private:
        bool thrown;
        int number;
        
    public:
        static int startPin;

        Turnout(bool state) { throw(state)};

        void saveToEEPROM()
        {
            EEPROM.write(number, thrown);
        }

        void readFromEEPROM()
        {
            bool state = EEPROM.read(number);
            throw(state);
        }

        void writePins()
        {
            digitalWrite(number + startPin, thrown);
        }

        void update()
        {
            writePins();
            saveToEEPROM();
        }

        void throw(bool state)
        { 
            thrown = state;
            update();
        };

        void toggle()
        { 
            thrown = !thrown;
            update();
        };
};

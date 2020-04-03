#ifndef Switch_h
#define Switch_h
#include <Arduino.h>

class Switch
{
    private:
        int pin;
        bool powered;

    public:
        Switch();
        Switch(int n);

        void setup();
        bool detectChange();
};
#endif

#ifndef Switch_h
#define Switch_h
#include <Arduino.h>

class Switch
{
    private:
        int pin;
        bool powered;
        int readDelay;

    public:
        Switch();
        Switch(int n);

        void setup();
        void setReadDelay(int delay);
        bool detectChange();
};
#endif

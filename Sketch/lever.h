#ifndef lever_h
#define lever_h
#include <Arduino.h>

class lever
{
    private:
        int pin_;
        bool bPowered_;
        int readDelay_;

    public:
        lever();
        lever(int pin);

        void setup();
        void setReadDelay(int delay);
        bool detectChange();
};
#endif

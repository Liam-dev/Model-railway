class Switch
{
    private:
        int pin;
        bool powered;

    public:
        Switch(int n)
        {
            pin = n;
        };

        void setup()
        {
            pinMode(pin, INPUT);
        };

        bool detectChange()
        {
            bool change = false;
            bool reading = digitalRead(pin);

            if (reading != powered)
            {
                change = true;
            }
            else
            {
                change = false;
            }

            powered = reading;
            return change;
        };
};

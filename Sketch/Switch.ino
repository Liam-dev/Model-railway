class Switch
{
    private:
        bool powered;

    public:
        static int startPin;
        Switch(/* args */);

        bool detectChange()
        {
            bool change = false;
            bool reading = digitalRead(j + startPin);

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
        }
};

class Flag
{
public:
    void toggle();
    void turn_on();
    void turn_off();
    bool get_state();

private:
    bool state = false;
};
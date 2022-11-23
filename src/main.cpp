
#include "main.h"

Control_system control;
Instruction_observer inst_obs;
Temperature_observer temp_obs;
Moisture_observer mois_obs;
void int0_callback()
{
    cli();
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();

    if (interrupt_time - last_interrupt_time > DEBOUNCE_CONSTANT)
    {
        if (control.is_off())
        {
            control.wake();
        }
        else
        {

            control.set_next_step_flag(true);
        }
    }
    last_interrupt_time = interrupt_time;

    sei();
}
ISR(TIMER1_COMPA_vect)
{
    cli();
    control.set_poll_sensors_flag(true);
    sei();
}
void setup()
{
    // cli();
    Serial.begin(9600);
    pinMode(ONE_WIRE_BUS, INPUT);
    setup_timer1_interrupt();
    setup_int0_interrupt(BUTTON_PIN, INPUT_PULLUP, int0_callback, HIGH);

    control.init_display();
    control.attach(&inst_obs);
    control.attach(&temp_obs);
    control.attach(&mois_obs);
    //   sei();
}
void loop()
{
    control.update();
};
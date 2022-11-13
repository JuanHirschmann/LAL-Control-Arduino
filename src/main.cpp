#include "main.h"
Control_system control = Control_system();
Temperature_observer temp_obs;
Instruction_observer inst_obs;
void int0_callback()
{
    // cli();
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > DEBOUNCE_CONSTANT)
    {
        control.show_next_step = true;
        control.poll_sensors = true;
    }
    last_interrupt_time = interrupt_time;
    // sei();
}
ISR(TIMER1_COMPA_vect)
{
    // cli();
    control.poll_sensors = true;
    // sei();
}
void setup()
{

    // cli();
    control.attach(&temp_obs);
    control.attach(&inst_obs);
    pinMode(ONE_WIRE_BUS, INPUT);
    setup_int0_interrupt(BUTTON_PIN, INPUT_PULLUP, int0_callback, HIGH);
    setup_timer1_interrupt();

    Serial.begin(DEFAULT_BAUD_RATE);
    control.init();

    // sei();
    //    delay(1000);
}
void loop()
{

    control.update();
    // delay(1000);
};
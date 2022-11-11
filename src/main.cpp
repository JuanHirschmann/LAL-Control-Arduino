#include "main.h"
Control_system *control = new Control_system;
void int0_callback()
{
    // cli();
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    if (interrupt_time - last_interrupt_time > DEBOUNCE_CONSTANT)
    {
        control->show_next_step.turn_on();
    }
    last_interrupt_time = interrupt_time;
    // sei();
}
ISR(TIMER1_COMPA_vect)
{
    cli();
    control->update_temperature.turn_on();
    sei();
}
void setup()
{
    cli();
    pinMode(ONE_WIRE_BUS, INPUT);
    setup_int0_interrupt(BUTTON_PIN, INPUT_PULLUP, int0_callback, HIGH);
    setup_timer1_interrupt();
    sei();
    Serial.begin(DEFAULT_BAUD_RATE);
    // delay(1000);
}
void loop()
{

    control->update();
    delay(1000);
};

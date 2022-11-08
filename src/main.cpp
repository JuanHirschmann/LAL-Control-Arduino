#include "main.h"
Control_system *control;
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
/* ISR(TIMER1_COMPA_vect)
{
    cli();
    control->update_temperature.turn_on();
    sei();
}
void setup_timer1_interrupt()
{

    // set timer1 interrupt at 1Hz
    TCCR1A = 0; // set entire TCCR1A register to 0
    TCCR1B = 0; // same for TCCR1B
    TCNT1 = 0;  // initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 15624; // = (16*10^6) / (1*1024) - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
} */
void setup()
{
    // cli();
    pinMode(ONE_WIRE_BUS, INPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), int0_callback, HIGH);
    TwoWire temp_sensor_interface;
    control = new Control_system(&temp_sensor_interface);
    // sei();
    //  Serial.begin(DEFAULT_BAUD_RATE);
    // delay(1000);
}
void loop()
{

    control->update();
    delay(1000);
};
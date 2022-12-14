
#include "main.h"

Control_system control;
Temperature_observer temp_obs;
Moisture_observer mois_obs;
Cooler_observer cooler_obs;
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

            control.request_next_step();
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
ISR(PCINT0_vect)
{
    cli();
    control.count_cooler_rotation();
    sei();
}
void setup()
{
    // cli();
    Serial.begin(9600);
    pinMode(ONE_WIRE_BUS, INPUT);
    setup_timer1_interrupt();
    setup_int0_interrupt(BUTTON_PIN, INPUT_PULLUP, int0_callback, HIGH);
    setup_pinct_portb_interrupt();
    control.init();
    control.attach(&temp_obs);
    control.attach(&mois_obs);
    control.attach(&cooler_obs);
    //   sei();
}
void loop()
{
    control.update();
    //  delay(1000);
    //  Serial.println("Vivo");
};
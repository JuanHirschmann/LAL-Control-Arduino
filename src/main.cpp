
#include "main.h"

Control_system control;
Temperature_observer temp_obs;
Moisture_observer mois_obs;
Cooler_observer cooler_obs;

void int0_callback()
{
    cli();
    bool current_state = digitalRead(BUTTON_PIN);
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();
    unsigned long time_diff = interrupt_time - last_interrupt_time;
    if (time_diff > DEBOUNCE_CONSTANT && current_state == HIGH)
    {
        if (control.is_off())
        {
            control.wake();
        }
        else
        {

            control.request_next_step();
        }
        last_interrupt_time = interrupt_time;
    }

    sei();
}
/* void wake_up_call()
{
    control.wake();
} */
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
    setup_int0_interrupt(BUTTON_PIN, INPUT_PULLUP, int0_callback, CHANGE);
    setup_pinct_portb_interrupt();
    // LowPower.attachInterruptWakeup(digitalPinToInterrupt(BUTTON_PIN), wake_up_call, CHANGE);
    control.init();
    control.attach(&temp_obs);
    control.attach(&mois_obs);
    control.attach(&cooler_obs);
    //   sei();
}
void loop()
{
    control.update();
    // control.update();
    //   delay(1000);
    //   Serial.println("Vivo");
};
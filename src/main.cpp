
#include "main.h"
Control_system control;
Instruction_observer inst_obs;
Temperature_observer temp_obs;
void int0_callback()
{
    cli();
    static unsigned long last_interrupt_time = 0;
    unsigned long interrupt_time = millis();

    if (interrupt_time - last_interrupt_time > DEBOUNCE_CONSTANT)
    {
        // control.next_step();
        if (!control.is_alarm_requested())
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
    if (control.is_alarm_requested())
    {
        control.trigger_buzzer_alarm();
    }
    sei();
}
void setup()
{
    // cli();
    pinMode(ONE_WIRE_BUS, INPUT);
    setup_timer1_interrupt();
    setup_int0_interrupt(BUTTON_PIN, INPUT_PULLUP, int0_callback, HIGH);
    Serial.begin(9600);
    control.init_display();
    control.attach(&inst_obs);
    control.attach(&temp_obs);
    //   sei();
}
void loop()
{
    // Serial.println("Vivo");
    // control.trigger_buzzer_alarm();
    control.update();
    // delay(1000);
    // Serial.println("Update");
    // control.update();
};
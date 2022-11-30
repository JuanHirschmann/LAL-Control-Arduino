
#include "main.h"

Control_system control;
Instruction_observer inst_obs;
Temperature_observer temp_obs;
Moisture_observer mois_obs;
Cooler cooler(FAN_1_CONTROL_PIN, FAN_1_SPEED_MEAS_PIN);
Cooler cooler2(FAN_2_CONTROL_PIN, FAN_2_SPEED_MEAS_PIN);
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
ISR(PCINT0_vect)
{
    if (cooler.rotation_detected() == HIGH)
    {
        cooler.count_rotation();
    }
    /* if (cooler2.rotation_detected())
    {
        cooler2.count_rotation();
    } */
}
void count_rotation()
{
    cli();
    Serial.print("ACA");
    // cooler.count_rotation();
    sei();
}
void setup()
{
    // cli();
    Serial.begin(9600);
    pinMode(ONE_WIRE_BUS, INPUT);
    setup_timer1_interrupt();
    pinMode(FAN_1_SPEED_MEAS_PIN, INPUT_PULLUP);
    setup_int0_interrupt(BUTTON_PIN, INPUT_PULLUP, int0_callback, HIGH);
    setup_pinct_portb_interrupt();
    control.init_display();
    control.attach(&inst_obs);
    control.attach(&temp_obs);
    control.attach(&mois_obs);
    cooler2.turn_off();
    cooler.turn_off();
    //   sei();
}
void loop()
{
    control.update();
    static int i = 50;
    delay(1000);
    cooler.turn_on(i / 100.0);
    Serial.println(cooler.get_speed());
    i++;
    if (i > 100)
    {
        i = 50;
    }
};
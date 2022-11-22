#include "Alarm_state.h"
#include "Arduino.h"
void Alarm_state::update(Control_system *machine)
{
    machine->buzzer.toggle();
}
void Alarm_state::enter(Control_system *machine)
{
    machine->context.override_next_step = true;
    Serial.println(F("Estado de alarma"));
    char buf[MAX_MESSAGE_LENGTH];
    strncpy_P(buf, ERROR_MESSAGES[machine->context.current_alarm], MAX_MESSAGE_LENGTH);
    machine->display.set_text(buf);
    machine->motor_status_led.turn_red();
}
void Alarm_state::exit(Control_system *machine)
{
    machine->context.override_next_step = false;
    machine->buzzer.turn_off();
    //  machine->context.alarm_request = false;
}
Abstract_state *Alarm_state::transition(Control_system *machine)
{
    if (!machine->context.alarm_request)
    {

        if (machine->context.warning_request)
        {
            this->exit(machine);
            return new Warning_state();
        }
        else
        {
            this->exit(machine);
            return new Idle_state();
        }
    }
    else
    {

        if (machine->context.temperature > OVERTEMP_ALARM_THRESHOLD * 1.1)
        {
            this->exit(machine);
            return new Motor_control_state();
        }
    }

    return nullptr;
}
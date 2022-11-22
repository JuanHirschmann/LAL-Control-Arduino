#include "Warning_state.h"
#include "Arduino.h"
void Warning_state::update(Control_system *machine)
{
    machine->motor_status_led.turn_yellow();
    char buf[MAX_MESSAGE_LENGTH];
    strncpy_P(buf, PROCEDURE_MESSAGES[machine->context.current_step], MAX_MESSAGE_LENGTH);
    machine->display.set_text(buf);
}
void Warning_state::enter(Control_system *machine)
{
    Serial.println(F("Estado de advertencia"));
    machine->motor_status_led.turn_yellow();
}
void Warning_state::exit(Control_system *machine)
{
    machine->motor_status_led.turn_off();
    machine->context.warning_request = false;
}
Abstract_state *Warning_state::transition(Control_system *machine)
{
    if (machine->context.alarm_request)
    {

        this->exit(machine);
        return new Alarm_state();
    }
    else if (!machine->context.warning_request)
    { /*Estado de warning*/
        this->exit(machine);
        return new Idle_state();
    }
    else if (machine->context.shutdown_request)
    {
        /*Estado de apagado de sistema*/
    }
    else if (machine->context.current_step >= MOTOR_ON_STEP && machine->context.current_step <= MOTOR_COOLDOWN_STEP)
    {
        this->exit(machine);
        return new Motor_control_state();
    }

    return nullptr;
}
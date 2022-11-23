#include "Idle_state.h"
#include "Arduino.h"
void Idle_state::enter(Control_system *machine)
{

    Serial.println(F("Estado idle"));
    machine->motor_status_led.turn_green();
    char buf[MAX_MESSAGE_LENGTH];
    strncpy_P(buf, PROCEDURE_MESSAGES[machine->context.current_step], MAX_MESSAGE_LENGTH);
    machine->display.set_text(buf);
}
void Idle_state::update(Control_system *machine)
{
    char buf[MAX_MESSAGE_LENGTH];
    strncpy_P(buf, PROCEDURE_MESSAGES[machine->context.current_step], MAX_MESSAGE_LENGTH);
    machine->display.set_text(buf);
    machine->notify_observers();
    machine->display.update();
}
void Idle_state::exit(Control_system *machine)
{
    machine->buzzer.turn_off();
    machine->motor_status_led.turn_off();
}
Abstract_state *Idle_state::transition(Control_system *machine)
{

    if (machine->context.warning_request || machine->context.alarm_request)
    { /*Estado de warning*/

        this->exit(machine);
        return new Motor_control_state();
    }
    else if ((machine->context.current_step >= MOTOR_ON_STEP && machine->context.current_step < MOTOR_COOLDOWN_STEP))
    {
        this->exit(machine);
        return new Motor_control_state();
    }
    else if (machine->context.shutdown_request)
    {
        this->exit(machine);
        return new Shutdown_state();
    }
    return nullptr;
}

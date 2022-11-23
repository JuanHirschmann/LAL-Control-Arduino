#include "Shutdown_state.h"
void Shutdown_state::update(Control_system *machine)
{
}
void Shutdown_state::enter(Control_system *machine)
{

    Serial.println("Estado shutdown");
    machine->display.turn_off();
    machine->context.wake_request = false;
    machine->motor_status_led.turn_off();
    machine->motor.turn_off();
}
void Shutdown_state::exit(Control_system *machine)
{
    machine->reset_context();
    machine->init_display();
    machine->context.shutdown_request = false;
    machine->display.turn_on();
    machine->motor_status_led.turn_on();
}
Abstract_state *Shutdown_state::transition(Control_system *machine)
{
    if (machine->context.wake_request)
    {
        this->exit(machine);
        return new Idle_state();
    }
    return nullptr;
}
#include "machine_state_pattern/machine_states/Shutdown_state.h"
#include "Arduino.h"
void Shutdown_state::update(Control_system *machine)
{

    // LowPower.deepSleep(10000);
}
void Shutdown_state::enter(Control_system *machine)
{

    // poner no bloqueante
    Serial.println(F("Estado shutdowm"));
    machine->display.turn_off();
    machine->motor_status_led.turn_off();
    machine->rear_cooler.turn_off();
    machine->rear_cooler_led.turn_off();
    machine->front_cooler.turn_off();
    machine->front_cooler_led.turn_off();
    machine->water_intake_led.turn_off();
    machine->buzzer.turn_off();
    if (machine->motor.is_active())
    {
        machine->motor.turn_off();
    }
    // LowPower.deepSleep(10000);
}
void Shutdown_state::exit(Control_system *machine)
{
    machine->reset();
    machine->init_display();

    // machine->display.turn_on();
    // machine->motor_status_led.turn_on();
}
Abstract_state *Shutdown_state::transition(Control_system *machine)
{
    if (!machine->context.shutdown_request)
    {
        this->exit(machine);
        return new Idle_state();
    }
    return nullptr;
}
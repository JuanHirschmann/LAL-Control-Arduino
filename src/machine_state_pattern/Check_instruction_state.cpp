#include "machine_state_pattern/machine_states/Check_instruction_state.h"
#include "Arduino.h"
void Check_instruction_state::exit(Control_system *machine){
    // machine->context.override_next_step = false;
};
void Check_instruction_state::update(Control_system *machine)
{
    if (machine->context.shutdown_request)
    {
        machine->reset();
    }

    machine->notify_observers();
    machine->display.update();
};
void Check_instruction_state::enter(Control_system *machine)
{
    Serial.println(F("Estado check instruction"));
    switch (machine->context.current_step)
    {
    case WELCOME_STEP:
        machine->rear_cooler.turn_off();
        machine->front_cooler.turn_off();
        machine->water_intake_led.turn_red();
        break;
    case WATER_ON_STEP:

        machine->water_intake_led.turn_green();

        break;
    case MOTOR_ON_STEP:
        if (!machine->context.warning_request)
        {
            machine->set_cooler_speed(0.5, 0.5);
        }
        if (!machine->context.alarm_request)
        {
            machine->motor_status_led.turn_green();
            machine->motor.turn_on();
        }
        break;

    case MOTOR_OFF_STEP:
        if (!machine->context.warning_request)
        {
            machine->set_cooler_speed(1, 1);
        }
        machine->motor.turn_off();
        break;
    case MOTOR_COOLDOWN_STEP:
        machine->context.override_next_step = true;
        if (!machine->context.warning_request)
        {
            machine->context.override_next_step = false;
        }

        break;
    case WATER_OFF_STEP:
        machine->set_cooler_speed(0, 0);
        machine->water_intake_led.turn_red();
    default:
        break;
    }
    machine->next_step();
}
Abstract_state *Check_instruction_state::transition(Control_system *machine)
{
    if (!machine->is_next_step_requested())
    {

        this->exit(machine);

        return new Idle_state();
    }
    return nullptr;
}
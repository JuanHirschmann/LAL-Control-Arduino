#include "Motor_control_state.h"
#include "Arduino.h"
void Motor_control_state::enter(Control_system *machine)
{

    Serial.println(F("Estado motor control"));
    // machine->motor_status_led.turn_green();

    char buf[MAX_MESSAGE_LENGTH];
    strncpy_P(buf, PROCEDURE_MESSAGES[machine->context.current_step], MAX_MESSAGE_LENGTH);
    if (machine->context.temperature < OVERTEMP_ALARM_THRESHOLD)
    {
        machine->display.set_text(buf);
        this->overtemp_override = false;
    }
    else
    {
        this->overtemp_override = true;
    }
}
void Motor_control_state::update(Control_system *machine)
{
    // machine->motor_status_led.toggle();
    if (machine->context.temperature > OVERTEMP_ALARM_THRESHOLD)
    {
        machine->motor.turn_off();
        machine->context.current_step = MOTOR_COOLDOWN_STEP;
        this->overtemp_override = true;
    }
    else
    {
        char buf[MAX_MESSAGE_LENGTH];
        strncpy_P(buf, PROCEDURE_MESSAGES[machine->context.current_step], MAX_MESSAGE_LENGTH);
        machine->display.set_text(buf);
        if (machine->is_next_step_requested())
        {
            switch (machine->context.current_step)
            {
            case MOTOR_ON_STEP:
                machine->motor.turn_on();
                break;

            case MOTOR_OFF_STEP:
                machine->motor.turn_off();
                break;
            case MOTOR_COOLDOWN_STEP:
                machine->context.override_next_step = true;
                if (machine->context.temperature < OVERTEMP_ALARM_THRESHOLD * HYSTERESIS_PERCENT)
                {
                    machine->context.override_next_step = false;
                    machine->next_step();
                }

            default:
                break;
            }
        }
    }
}
void Motor_control_state::exit(Control_system *machine)
{
    machine->motor_status_led.turn_off();
    machine->buzzer.turn_off();
}
Abstract_state *Motor_control_state::transition(Control_system *machine)
{

    if (machine->context.current_step > MOTOR_COOLDOWN_STEP)
    {
        Serial.println(machine->context.current_step);
        this->exit(machine);
        return new Idle_state();
    }
    return nullptr;
}

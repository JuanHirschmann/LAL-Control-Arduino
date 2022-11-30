#include "machine_state_pattern/machine_states/Motor_control_state.h"
#include "Arduino.h"
void Motor_control_state::enter(Control_system *machine)
{

    Serial.println(F("Estado motor control"));
    machine->motor_status_led.turn_green();

    char buf[MAX_MESSAGE_LENGTH];
    strncpy_P(buf, PROCEDURE_MESSAGES[machine->context.current_step], MAX_MESSAGE_LENGTH);
    if (machine->context.temperature < OVERTEMP_ALARM_THRESHOLD)
    {
        machine->display.set_text(buf);
        this->alarm_override = false;
    }
    else
    {
        this->alarm_override = true;
    }
}
void Motor_control_state::update(Control_system *machine)
{

    if (machine->context.alarm_request)
    {
        machine->buzzer.toggle();
        machine->motor_status_led.turn_red();
        machine->motor.turn_off();
        machine->context.current_step = MOTOR_COOLDOWN_STEP;
        char buf[MAX_MESSAGE_LENGTH];
        strncpy_P(buf, ERROR_MESSAGES[machine->context.current_alarm], MAX_MESSAGE_LENGTH);
        this->alarm_override = true;
        Serial.println(buf);
        switch (machine->context.current_alarm)
        {
        case OVERTEMP_ALARM:
            machine->context.shutdown_request = true;
            machine->display.set_text(buf);
            break;

        case HUMIDITY_ALARM:
            machine->context.shutdown_request = true;
            machine->display.set_text(buf);
            break;
        case HALTED_FAN_ALARM:
            machine->context.shutdown_request = true;
            machine->display.set_text(buf);
            break;
        case NO_TEMP_SENSOR_ALARM:
            machine->display.set_text(buf);
        case OVERTEMP_WARNING:
            break;
        case SLOW_FAN_WARNING:
            break;
        case NO_ALARM:
            break;
        default:
            machine->display.set_text("No se reconoció el error");
            break;
        }
    }
    else if (machine->context.warning_request)
    {
        machine->buzzer.turn_off();
        machine->motor_status_led.turn_yellow();
    }
    else
    {
        machine->motor_status_led.turn_green();
    }

    if (machine->is_next_step_requested() || this->alarm_override)
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
            if (!machine->context.alarm_request)
            {
                machine->context.override_next_step = false;
                machine->next_step();
            }
        case LAST_STEP:
            machine->context.shutdown_request = true;
        default:
            break;
        }
    }
    machine->notify_observers();
    machine->display.update();
}
void Motor_control_state::exit(Control_system *machine)
{
    machine->motor_status_led.turn_off();
    machine->buzzer.turn_off();
}
Abstract_state *Motor_control_state::transition(Control_system *machine)
{

    if ((machine->context.current_step < MOTOR_ON_STEP || machine->context.current_step > MOTOR_COOLDOWN_STEP) && !(machine->context.warning_request || machine->context.alarm_request))
    {
        Serial.println(machine->context.current_step);
        this->exit(machine);
        return new Idle_state();
    }
    else if (machine->context.shutdown_request)
    {
        unsigned long current_millis_call = millis();
        static unsigned long prev_millis_call = current_millis_call;
        if (prev_millis_call != 0 && current_millis_call - prev_millis_call > 5000)
        {
            prev_millis_call = current_millis_call;
            this->exit(machine);
            return new Shutdown_state();
        }
    }
    return nullptr;
}

#include "machine_state_pattern/machine_states/Alarm_state.h"
#include "Arduino.h"
void Alarm_state::enter(Control_system *machine)
{
    Serial.println(F("Estado alarm state"));
}
void Alarm_state::update(Control_system *machine)
{
    // machine->context.override_next_step = true;
    if (!machine->context.alarm_request)
    {
        // machine->context.override_next_step = false;
        if (!machine->context.warning_request)
        {
            machine->context.current_alarm = NO_ALARM;
            machine->motor_status_led.turn_green();
        }

        machine->show_current_step();
    }
    else
    {
        machine->buzzer.turn_on();
        // machine->context.override_next_step = true;
    }
    machine->handle_alarm();
    machine->notify_observers();
    machine->display.update();
}
void Alarm_state::exit(Control_system *machine)
{
    machine->buzzer.turn_off();
}
Abstract_state *Alarm_state::transition(Control_system *machine)
{

    if (!machine->context.alarm_request)
    {
        if (machine->context.next_step_request)
        {
            this->exit(machine);
            return new Check_instruction_state();
        }
        else if (machine->context.current_alarm == NO_ALARM)
        {
            machine->set_cooler_speed(0, 0);
            this->exit(machine);
            return new Idle_state();
        }
    }
    else if (machine->context.shutdown_request)
    {
        // unsigned long current_millis_call = millis();
        // static unsigned long prev_millis_call = current_millis_call;
        // if (prev_millis_call != 0 && current_millis_call - prev_millis_call > 5000)
        //{
        //     prev_millis_call = current_millis_call;
        this->exit(machine);
        return new Shutdown_state();
        //}
    }
    return nullptr;
}

#include "Control_system.h"
/* Control_system::Control_system(const Control_system &control)
{
    this->current_step = control.current_step;
} */
Control_system::Control_system(/* args */) : temp_sensor(ONE_WIRE_BUS), buzzer(BUZZER_PIN, BUZZER_HIGH_FREQ)
{
}

Control_system::~Control_system()
{
}
void Control_system::print(const char *string_out)
{
    this->display.print(string_out);
}
void Control_system::init_display()
{

    this->display.init();
    this->display.set_text(PROCEDURE_MESSAGES[current_step]);
}
void Control_system::update()
{

    if (this->shutdown_request)
    {
        this->buzzer.turn_off();
        this->display.turn_off();
        // apagar arduino;
    }
    this->notify_observers();
    this->display.update();
}
void Control_system::next_step()
{
    this->buzzer.turn_on(100);
    this->current_step++;
    if (this->current_step < MAX_PROCEDURE_STEPS - 1)
    {

        this->display.set_text(PROCEDURE_MESSAGES[this->current_step]);
    }
    else
    {
        this->shutdown_request = true;
    }
}
void Control_system::notify_observers()
{
    for (int i = 0; i < this->current_observers; i++)
    {
        static_cast<System_observer *>(this->observers[i])->update(this);
    }
};
float Control_system::measure_temperature()
{
    float new_temperature = this->temp_sensor.get_reading();
    this->display.set_temp(new_temperature);
    return new_temperature;
}

void Control_system::set_next_step_flag(bool new_state)
{
    this->next_step_request = new_state;
}
bool Control_system::is_next_step_requested()
{
    return this->next_step_request;
}
void Control_system::set_poll_sensors_flag(bool new_state)
{
    this->poll_sensors_request = new_state;
}
bool Control_system::is_poll_sensors_requested()
{
    return this->poll_sensors_request;
}
void Control_system::set_alarm_flag(bool new_state)
{
    this->alarm_request = new_state;
}
bool Control_system::is_alarm_requested()
{
    return this->alarm_request;
}
void Control_system::request_alarm(ALARM_TYPES type_of_alarm)
{
    switch (type_of_alarm)
    {
    case OVERTEMP_ALARM:
        Serial.print("Exceso de temperatura");
        break;

    default:
        break;
    }
}
void Control_system::trigger_buzzer_alarm()
{
    this->buzzer.toggle();
}
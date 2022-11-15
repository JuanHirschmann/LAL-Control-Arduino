#include "Control_system.h"
/* Control_system::Control_system(const Control_system &control)
{
    this->current_step = control.current_step;
} */
Control_system::Control_system(/* args */) : temp_sensor(ONE_WIRE_BUS)
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
        // apagar arduino;
    }
    this->notify_observers();
    this->display.update();
}
void Control_system::next_step()
{
    this->current_step++;
    if (this->current_step < MAX_PROCEDURE_STEPS)
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
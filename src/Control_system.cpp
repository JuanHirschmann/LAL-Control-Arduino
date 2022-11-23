#include "Control_system.h"
/* Control_system::Control_system(const Control_system &control)
{
    this->current_step = control.current_step;
} */
Control_system::Control_system(/* args */) : temp_sensor(ONE_WIRE_BUS), buzzer(BUZZER_PIN, BUZZER_HIGH_FREQ), motor_status_led(MOTOR_GREEN_LED_PIN, MOTOR_RED_LED_PIN), motor(MOTOR_CONTROL_PIN), mois_sensor(MOISTURE_SENSOR_PIN)
{
}

void Control_system::print(const char *string_out)
{
    this->display.print(string_out);
}
void Control_system::init_display()
{

    this->display.init();

    this->current_state = new Idle_state();
    this->current_state->enter(this);
}
void Control_system::update()
{
    this->transition_state();
    this->current_state->update(this);
    if (this->context.shutdown_request)
    {
        this->buzzer.turn_off();
        this->display.turn_off();
        this->motor_status_led.turn_off();
        // apagar arduino;
    }
    else
    {

        this->notify_observers();
        this->display.update();
        this->set_poll_sensors_flag(false);
    }
}
void Control_system::next_step()
{

    this->buzzer.turn_on(100); // Esto rompe el color del led

    this->context.current_step++;
    if (this->context.current_step < MAX_PROCEDURE_STEPS)
    {

        char buf[MAX_MESSAGE_LENGTH];
        strncpy_P(buf, PROCEDURE_MESSAGES[this->context.current_step], MAX_MESSAGE_LENGTH);
        this->display.set_text(buf);
        this->context.next_step_request = false;
    }
    else
    {
        this->context.shutdown_request = true;
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
    this->context.temperature = new_temperature;
    this->display.set_temp(new_temperature);
    return new_temperature;
}
int Control_system::measure_moisture()
{
    return this->mois_sensor.get_reading();
}
void Control_system::set_next_step_flag(bool new_state)
{
    if (!this->is_alarm_requested())
    {

        this->context.next_step_request = new_state;
    }
}
bool Control_system::is_next_step_requested()
{
    return this->context.next_step_request;
}
void Control_system::set_poll_sensors_flag(bool new_state)
{
    this->context.poll_sensors_request = new_state;
}
bool Control_system::is_poll_sensors_requested()
{
    return this->context.poll_sensors_request;
}
void Control_system::set_alarm_flag(bool new_state)
{
    if (this->context.alarm_request != new_state)
    {
        this->context.alarm_request = new_state;
    }
}
bool Control_system::is_alarm_requested()
{
    return this->context.alarm_request;
}
void Control_system::request_alarm(ALARM_TYPES type_of_alarm)
{
    this->context.alarm_request = true;
    this->context.current_alarm = type_of_alarm;
}
void Control_system::request_warning(ALARM_TYPES type_of_warning)
{
    this->context.warning_request = true;
    this->context.current_alarm = type_of_warning;
}
void Control_system::set_warning_flag(bool new_state)
{
    if (this->context.warning_request != new_state)
    {

        this->context.warning_request = new_state;
    }
}
bool Control_system::is_warning_requested()
{
    return this->context.warning_request;
}
void Control_system::transition_state()
{
    Abstract_state *state = this->current_state->transition(this);
    if (state != nullptr)
    {
        delete this->current_state;
        this->current_state = state;
        this->current_state->enter(this);
    }
}
Control_system::~Control_system()
{
    if (this->current_state != nullptr)
    {
        delete this->current_state;
    }
}

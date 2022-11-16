#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H
#include "Subject.h"
#include "Display.h"
#include "user_messages.h"
#include "System_observer.h"
#include "Temperature_sensor.h"
#include "types.h"
#include "Buzzer.h"

class Control_system : public Subject
{
private:
    Display display;
    int current_step = 0;
    bool shutdown_request = false;
    Buzzer buzzer;

public:
    bool alarm_request = false;
    bool next_step_request = false;
    bool poll_sensors_request = false;
    Temperature_sensor temp_sensor;
    void update();
    void next_step();
    void print(const char *string_out);
    void init_display();
    Control_system(/* args */);
    ~Control_system();
    void notify_observers() override;
    float measure_temperature();
    void set_next_step_flag(bool new_state);
    bool is_next_step_requested();
    void set_poll_sensors_flag(bool new_state);
    bool is_poll_sensors_requested();
    void set_alarm_flag(bool new_state);
    bool is_alarm_requested();
    void request_alarm(ALARM_TYPES type_of_alarm);
    void trigger_buzzer_alarm();
    void request_warning(WARNING_TYPES type_of_warning);
};

#endif
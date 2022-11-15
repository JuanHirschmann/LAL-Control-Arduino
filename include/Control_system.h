#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H
#include "Subject.h"
#include "Display.h"
#include "user_messages.h"
#include "System_observer.h"
#include "Temperature_sensor.h"
class Control_system : public Subject
{
private:
    Display display;
    int current_step = 0;
    bool shutdown_request = false;

public:
    bool next_step_request = false;
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
};

#endif
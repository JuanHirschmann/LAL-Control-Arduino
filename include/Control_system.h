#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H
#include "Subject.h"
#include "Machine.h"
#include "Display.h"
#include "user_messages.h"
#include "System_observer.h"
#include "Temperature_sensor.h"
#include "Moisture_sensor.h"
#include "types.h"
#include "Buzzer.h"
#include "Motor.h"
#include "Dual_led.h"
#include "Idle_state.h"
#include "utils.h"
class Control_system : public Subject, public Machine
{
    friend class Idle_state;
    friend class Motor_control_state;

public:
    void update();
    void next_step();
    void print(const char *string_out);
    void init_display();
    Control_system(/* args */);
    void notify_observers() override;
    float measure_temperature();
    int measure_moisture();
    void set_next_step_flag(bool new_state);
    bool is_next_step_requested();
    void set_poll_sensors_flag(bool new_state);
    bool is_poll_sensors_requested();
    void set_alarm_flag(bool new_state);
    bool is_alarm_requested();
    void request_alarm(ALARM_TYPES type_of_alarm);
    // void trigger_buzzer_alarm();
    void request_warning(ALARM_TYPES type_of_warning);
    void set_warning_flag(bool new_state);
    bool is_warning_requested();
    void transition_state();
    Context_t get_context() { return this->context; };
    ~Control_system();
    bool is_next_step_overriden() { return this->context.override_next_step; };

private:
    Context_t context;

    Display display;

    Temperature_sensor temp_sensor;
    Buzzer buzzer;
    Motor motor;
    Moisture_sensor mois_sensor;
    // Dual_LED water_status_led;
    Dual_LED motor_status_led;
};

#endif
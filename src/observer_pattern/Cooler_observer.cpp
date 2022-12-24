#include "observer_pattern/observers/Cooler_observer.h"
#include <stdlib.h>

void Cooler_observer::update(Control_system *subject)
{
    if (subject->is_poll_sensors_requested())
    {
        this->update_speed(subject);
        for (int i = 0; i < TOTAL_COOLERS; i++)
        {

            if (this->speed[i] == 0 && subject->is_cooler_active(static_cast<COOLER_TYPES>(i)) == true)
            {
                delay(DEFAULT_DELAY * 10);
                this->update_speed(subject);
                if (this->speed[i] == 0 && subject->is_cooler_active(static_cast<COOLER_TYPES>(i)) == true)
                {
                    subject->request_alarm(HALTED_FAN_ALARM);
                }
            }
        }
    }
};
void Cooler_observer::update_speed(Control_system *subject)
{
    static unsigned long previous_call_time = 0;
    unsigned long current_call_time = millis();
    unsigned long time_diff = current_call_time - previous_call_time;
    if (time_diff > SAMPLE_PERIOD)
    {
        this->speed[REAR_COOLER] = float(subject->get_cooler_count(REAR_COOLER) * 0.25) / time_diff;
        this->speed[FRONT_COOLER] = float(subject->get_cooler_count(FRONT_COOLER) * 0.25) / time_diff;
    }
    Serial.println(time_diff);
    previous_call_time = current_call_time;

    subject->display_cooler_speed(this->speed[REAR_COOLER], speed[FRONT_COOLER]);
}
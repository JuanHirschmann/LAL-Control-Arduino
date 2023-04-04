#include "observer_pattern/observers/Moisture_observer.h"
void Moisture_observer::update(Control_system *subject)
{
    if (subject->is_poll_sensors_requested())
    {
        bool is_water_leaking = subject->measure_moisture();

        if (is_water_leaking)
        {

            subject->request_alarm(HUMIDITY_ALARM);
        }
    }
};
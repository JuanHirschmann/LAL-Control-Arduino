#include "observer_pattern/observers/Moisture_observer.h"
void Moisture_observer::update(Control_system *subject)
{
    if (subject->is_poll_sensors_requested())
    {

        int moisture = subject->measure_moisture();
        subject->set_alarm_flag(false);
        if (moisture < MOISTURE_ALARM_THRESHOLD)
        {

            subject->request_alarm(HUMIDITY_ALARM);
        }
    }
};
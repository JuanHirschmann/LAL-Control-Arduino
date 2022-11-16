/**
 * @file Temperature_observer.cpp
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Temperature_observer.h"
void update(Control_system *subject)
{
    if (subject->is_poll_sensors_requested())
    {
        float temperature = subject->measure_temperature();
        subject->set_alarm_flag(false);
        if (temperature > OVERTEMP_ALARM_THRESHOLD)
        {
            subject->request_alarm(OVERTEMP_ALARM);
            subject->set_alarm_flag(true);
        }
        else if (temperature > OVERTEMP_WARNING_THRESHOLD)
        {
            Serial.print("CALORCITO");
        }
        subject->set_poll_sensors_flag(false);
    }

    // subject->display.set_temp(temperature);
};
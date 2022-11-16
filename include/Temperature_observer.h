/**
 * @file Temperature_observer.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef TEMPERATURE_OBSERVER_H
#define TEMPERATURE_OBSERVER_H
#include "System_observer.h"
#include "Arduino.h"
#include "Control_system.h"
#include "system_settings.h"
#include "types.h"
/**
 * @brief Clase heredera de System_observer, creada para observar
 *  el estado de los sensores de temperatura.
 *
 */
class Temperature_observer : public System_observer
{
public:
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
    };

private:
};
#endif
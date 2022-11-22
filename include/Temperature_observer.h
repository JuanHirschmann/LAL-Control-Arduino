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
        if (subject->is_poll_sensors_requested()) // Agregar histéresis?
        {

            float temperature = subject->measure_temperature();
            if (temperature < HYSTERESIS_PERCENT * OVERTEMP_ALARM_THRESHOLD || temperature < HYSTERESIS_PERCENT * OVERTEMP_WARNING_THRESHOLD) // Hysteresis
            {

                subject->set_alarm_flag(false);
                subject->set_warning_flag(false);
            }
            if (temperature == ERROR_TEMPERATURE)
            {
                subject->request_alarm(NO_TEMP_SENSOR_ALARM);
            }
            else if (temperature > OVERTEMP_ALARM_THRESHOLD)
            {
                subject->request_alarm(OVERTEMP_ALARM);
            }
            else if (temperature > OVERTEMP_WARNING_THRESHOLD)
            {
                subject->request_warning(OVERTEMP_WARNING);
            }
            subject->set_poll_sensors_flag(false);
        }
    };

private:
};
#endif
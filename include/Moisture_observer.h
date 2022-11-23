#ifndef MOISTURE_OBSERVER_H
#define MOISTURE_OBSERVER_H
#include "System_observer.h"
#include "Arduino.h"
#include "Control_system.h"
#include "system_settings.h"
#include "types.h"
/**
 * @brief Clase heredera de System_observer, creada para observar
 *  el estado de los sensores de humedad.
 *
 */
class Moisture_observer : public System_observer
{
public:
    void update(Control_system *subject)
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

private:
};
#endif
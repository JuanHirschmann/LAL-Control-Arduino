#include "observer_pattern/observers/Temperature_observer.h"
void Temperature_observer::update(Control_system *subject)
{
    if (subject->is_poll_sensors_requested()) // Agregar histéresis?
    {

        float temperature = subject->measure_temperature();
        // Serial.print(millis());
        // Serial.print(",");
        // Serial.println(temperature);
        if (temperature == ERROR_TEMPERATURE)
        {
            subject->request_alarm(NO_TEMP_SENSOR_ALARM);
        }
        else if (temperature < HYSTERESIS_PERCENT * OVERTEMP_WARNING_THRESHOLD)
        {
            subject->set_warning_flag(false);
        }
        else if (temperature > OVERTEMP_ALARM_THRESHOLD)
        {
            // Serial.println(temperature);
            subject->request_alarm(OVERTEMP_ALARM);
        }
        else if (temperature > OVERTEMP_WARNING_THRESHOLD)
        {
            subject->request_warning(OVERTEMP_WARNING);
        }
    }
};
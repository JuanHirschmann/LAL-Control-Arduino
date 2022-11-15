#ifndef TEMPERATURE_OBSERVER_H
#define TEMPERATURE_OBSERVER_H
#include "System_observer.h"
#include "Arduino.h"
#include "Control_system.h"
const float OVERTEMP_WARNING_THRESHOLD = 30;
const float OVERTEMP_ERROR_THRESHOLD = 120;

class Temperature_observer : public System_observer
{
public:
    void update(Control_system *subject)
    {
        float temperature = subject->measure_temperature();
        if (temperature > OVERTEMP_WARNING_THRESHOLD)
        {
            Serial.print("CALORCITO");
        }
        // subject->display.set_temp(temperature);
    };

private:
};
#endif
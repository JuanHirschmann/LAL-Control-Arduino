#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H
#include "Arduino.h"
class Moisture_sensor
{
public:
    Moisture_sensor(int analog_pin)
    {
        this->sensor_pin = analog_pin;
    }
    void update_reading()
    {
        this->reading = analogRead(this->sensor_pin);
    }
    int get_reading()
    {
        this->update_reading();
        return this->reading;
    }

private:
    int sensor_pin = 0;
    int reading = 0;
};

#endif
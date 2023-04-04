#include "drivers/Moisture_sensor.h"
Moisture_sensor::Moisture_sensor(int digital_pin)
{
    this->sensor_pin = digital_pin;
}
void Moisture_sensor::update_reading()
{
    this->water_detected = digitalRead(this->sensor_pin);
}
bool Moisture_sensor::get_reading()
{
    this->update_reading();
    return this->water_detected;
}
/**
 * @file Cooler.cpp
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief
 * @version 0.1
 * @date 2022-12-27
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Drivers/Cooler.h"
Cooler::Cooler(int power_pin, int speed_measurement_pin)
{
    this->power_pin = power_pin;
    this->speed_measurement_pint = speed_measurement_pin;
    pinMode(power_pin, OUTPUT);
    pinMode(speed_measurement_pin, INPUT_PULLUP);
}
void Cooler::turn_on(float duty_cycle = 1.0)
{
    if (duty_cycle < FAN_MINIMUM_DUTY_CYCLE) //
    {
        Serial.println("Te apague");
        this->turn_off();
    }
    else
    {
        if (!this->is_on && duty_cycle < FAN_AUTONOMOUS_DUTY_CYCLE)
        {

            Serial.println("Te ayudé");
            this->turn_on(1.0); // Necesita inercia
            delay(DEFAULT_DELAY);
        }
        this->is_on = true;
        this->current_duty_cycle = duty_cycle;
        analogWrite(this->power_pin, int(MAX_ANALOG_WRITE_VALUE * this->current_duty_cycle));
    }
}
void Cooler::turn_off()
{
    this->is_on = false;
    analogWrite(this->power_pin, 0);
}
unsigned long int Cooler::get_rotation_count()
{
    unsigned long int value = this->rotations_in_sample_period / 2;
    this->reset_count();
    return value;
}
bool Cooler::rotation_detected()
{
    return digitalRead(this->speed_measurement_pint);
}
void Cooler::reset_count()
{
    this->rotations_in_sample_period = 0;
}
void Cooler::count_rotation()
{
    this->rotations_in_sample_period++;
}
bool Cooler::is_active()
{
    return this->is_on;
}

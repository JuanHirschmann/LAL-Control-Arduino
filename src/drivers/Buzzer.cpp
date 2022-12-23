/**
 * @file Buzzer.cpp
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "drivers/Buzzer.h"
Buzzer::Buzzer(int buzzer_pin) // Tiene que tener pwm en el pinout
{
    pinMode(buzzer_pin, OUTPUT);
    this->buzzer_pin = buzzer_pin;
}
void Buzzer::turn_on(unsigned long duration)
{
    this->is_ringing = true;
    digitalWrite(this->buzzer_pin, HIGH);
    if (duration != 0)
    {
        delay(duration);
        this->turn_off();
    }
};
void Buzzer::turn_off()
{
    this->is_ringing = false;
    digitalWrite(this->buzzer_pin, LOW);
};
void Buzzer::toggle(unsigned int duration = 0)
{
    if (!this->is_ringing)
    {
        this->turn_on(duration);
    }
    else
    {
        this->turn_off();
    }
};
bool Buzzer::is_active()
{
    return this->is_ringing;
};
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
#include "Buzzer.h"
Buzzer::Buzzer(int buzzer_pin, unsigned int frequency) // Tiene que tener pwm en el pinout
{
    pinMode(buzzer_pin, OUTPUT);
    this->buzzer_pin = buzzer_pin;
    this->frequency = frequency;
}
void Buzzer::turn_on(unsigned long duration = 0)
{
    this->is_ringing = true;
    tone(this->buzzer_pin, this->frequency, duration);
};
void Buzzer::turn_off()
{
    this->is_ringing = false;
    noTone(this->buzzer_pin);
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
void Buzzer::set_frequency(unsigned int new_frequency)
{
    noTone(this->buzzer_pin);
    this->frequency = new_frequency;
};
bool Buzzer::is_active()
{
    return this->is_ringing;
}
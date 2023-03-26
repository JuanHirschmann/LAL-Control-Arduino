#include <Arduino.h>
#include "unity.h"
const int SPEED_PIN = 2;
const int PWM_PIN = 3;
const int SPEED_PIN_2 = 6;
const int PWM_PIN_2 = 5;
const int PWM_VAL = int(255 * 0.75);
void setup()
{
    delay(2000);
    pinMode(SPEED_PIN, INPUT_PULLUP);
    pinMode(PWM_PIN, OUTPUT);
    pinMode(SPEED_PIN_2, INPUT_PULLUP);
    pinMode(PWM_PIN_2, OUTPUT);
}
void loop()
{
    analogWrite(PWM_PIN, PWM_VAL);
    analogWrite(PWM_PIN_2, PWM_VAL);
}
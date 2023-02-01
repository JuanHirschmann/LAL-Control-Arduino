#include <Arduino.h>
#include "unity.h"
unsigned long previousRPMMillis;
unsigned long previousMillis;
float RPM;

unsigned long interval = 1000;
byte pwmValue = 125;
byte pwmInterval = 5;
const byte pwmMax = 255;
const byte pwmMin = 0;
const int FRONT_COOLER_CONTROL_PIN = 5; // Con PWM
const int REAR_COOLER_CONTROL_PIN = 6;  // Con PWM
const int REAR_COOLER_SPEED_MEAS_PIN = 8;
const int FRONT_COOLER_SPEED_MEAS_PIN = 9;
const int reedPin = 2;
const int fanPin = 6;

volatile unsigned long pulses = 0;
unsigned long lastRPMmillis = 0;

void countPulse()
{
    // just count each pulse we see
    // ISRs should be short, not like
    // these comments, which are long.
    pulses++;
}

unsigned long calculateRPM()
{
    unsigned long RPM;
    noInterrupts();
    float elapsedMS = (millis() - lastRPMmillis) / 1000.0;
    unsigned long revolutions = pulses / 2;
    float revPerMS = revolutions / elapsedMS;
    RPM = revPerMS * 60.0;
    lastRPMmillis = millis();
    pulses = 0;
    interrupts();
    /*Serial.print(F("elpasedMS = ")); Serial.println(elapsedMS);
    Serial.print(F("revolutions = ")); Serial.println(revolutions);
    Serial.print(F("revPerMS = ")); Serial.println(revPerMS); */
    return RPM;
}

void setup_pinct_portb_interrupt()
{
    cli();
    PCICR |= 0x01;  // Port b
    PCMSK0 |= 0x03; // Pines D9 y D8;
    sei();
}
ISR(PCINT0_vect)
{
    cli();
    static bool rear_cooler_previous_state = false;
    bool rear_cooler_current_state = digitalRead(REAR_COOLER_SPEED_MEAS_PIN);
    if (rear_cooler_previous_state != rear_cooler_current_state && rear_cooler_current_state == LOW) // Falling edge
    {
        countPulse();
    }

    sei();
}

void setup()
{
    delay(2000);
    UNITY_BEGIN();
    TEST_MESSAGE("log this");
    pinMode(REAR_COOLER_SPEED_MEAS_PIN, INPUT_PULLUP);
    setup_pinct_portb_interrupt();
    // attachInterrupt(digitalPinToInterrupt(reedPin), countPulse, FALLING);

    pinMode(REAR_COOLER_CONTROL_PIN, OUTPUT); // probably PWM */
}
void loop()
{
    pwmValue = 155;
    analogWrite(fanPin, pwmValue);
    delay(1000);
    char str[100];
    if (millis() - previousMillis > interval)
    {
        TEST_MESSAGE("RPM=");
        sprintf(str, "%d", calculateRPM());
        TEST_MESSAGE(str);
        sprintf(str, "%d", pwmValue);
        TEST_MESSAGE(" @ PWM=");
        TEST_MESSAGE(str);
        previousMillis = millis();
    }
    delay(5000);
    UNITY_END();
}
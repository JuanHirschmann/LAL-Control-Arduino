#ifndef INTERRUPTS_H
#define INTERRUPTS_H
#include <Arduino.h>
void setup_int0_interrupt(uint8_t pin, uint8_t mode, void (*callback)(), int interrupt_mode);
void setup_timer1_interrupt();
#endif
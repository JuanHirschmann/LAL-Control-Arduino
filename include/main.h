/**
 * @file main.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Archivo principal del programa.
 * @version 0.1
 * @date 2022-11-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef MAIN_H
#define MAIN_H
#include <Arduino.h>
// #include "ArduinoLowPower.h"
#include "Control_system.h"
#include "system_settings.h"
#include "interrupts.h"
#include "observer_pattern/observers/Temperature_observer.h"
#include "observer_pattern/observers/Moisture_observer.h"
#include "observer_pattern/observers/Cooler_observer.h"
#endif
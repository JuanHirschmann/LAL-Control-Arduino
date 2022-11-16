/**
 * @file system_settings.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Archivo para la definición de constantes del sistema
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef SYSTEM_SETTINGS_H
#define SYSTEM_SETTINGS_H
/* Constantes temporales*/
const int DEBOUNCE_CONSTANT = 200; //[ms]
const int DEFAULT_DELAY = 100;
/* Comunicación serie*/
const int DEFAULT_BAUD_RATE = 9600;
const bool DEBUGGING = true;
/* Tonos del buzzer*/
const int BUZZER_HIGH_FREQ = 1500;
const int BUZZER_LOW_FREQ = 200;
/* Sensor de temperatura*/
const int MAX_SENSORS = 10;
const float OVERTEMP_WARNING_THRESHOLD = 30;
const float OVERTEMP_ALARM_THRESHOLD = 31;
#endif
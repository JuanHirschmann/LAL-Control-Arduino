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
const float OVERTEMP_ALARM_THRESHOLD = 33;
const float ERROR_TEMPERATURE = -127;
const float HYSTERESIS_PERCENT = 0.95;
const int FAN_SPEED_SAMPLE_PERIOD = 1000; //[ms]

/* Sensor de humedad*/
const int MOISTURE_ALARM_THRESHOLD = 255;

/* LED dual*/
const float RED_COLOR_DUTY_CYCLE[] = {0, 1}; //{0, 1};
const float YELLOW_COLOR_DUTY_CYCLE[] = {0.5, 0.5};
const float GREEN_COLOR_DUTY_CYCLE[] = {1, 0}; //{1, 0};
const int MAX_ANALOG_WRITE_VALUE = 255;

const float FAN_MINIMUM_DUTY_CYCLE = 0.3;     // Ciclo de trabajo a partir del cual el cooler puede mantener su rotación si ya estaba encendido.
const float FAN_AUTONOMOUS_DUTY_CYCLE = 0.77; // Ciclo de trabajo a partir del cual el cooler puede mantener su rotación partiendo del reposo.
const int TOTAL_COOLERS = 2;
const float SPEED_VARIATION_UPDATE_THRESHOLD = 0.01; // Umbral porcentual para actualizar la velocidad
#endif
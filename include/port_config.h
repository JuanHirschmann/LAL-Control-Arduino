/**
 * @file port_config.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Archivo de configuración para los puertos de la placa donde se implementará el sistema.
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PORT_CONFIG_H
#define PORT_CONFIG_H

const int BUTTON_PIN = 2;               // D3, tiene que corresponder a una interrupción externa
const int MOTOR_CONTROL_PIN = 3;        // reservo PWM para posible control de temperatura.
const int FRONT_COOLER_CONTROL_PIN = 5; // Con PWM
const int REAR_COOLER_CONTROL_PIN = 6;  // Con PWM
const int ONE_WIRE_BUS = 7;             // D9 como digital in
const int REAR_COOLER_SPEED_MEAS_PIN = 8;
const int FRONT_COOLER_SPEED_MEAS_PIN = 9;
const int BUZZER_PIN = 12; // D8, no necesita PWM

const int MOISTURE_SENSOR_PIN = 4;

const int MOTOR_RED_LED_PIN = A2;      // D10 
const int MOTOR_GREEN_LED_PIN = A1;    // D11, Ambos con PWM rojo 2
const int WATER_INTAKE_RED_LED = 10;   // 
const int WATER_INTAKE_GREEN_LED = A3; // 
const int REAR_COOLER_GREEN_LED = A0;  // 
const int REAR_COOLER_RED_LED = A6;    // 
const int FRONT_COOLER_RED_LED = 13;   // 
const int FRONT_COOLER_GREEN_LED = 11; // 

#endif
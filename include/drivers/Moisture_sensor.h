/**
 * @file Moisture_sensor.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Controlador de sensor de humedad digital.
 * @version 0.1
 * @date 2022-11-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef MOISTURE_SENSOR_H
#define MOISTURE_SENSOR_H
#include "Arduino.h"
/**
 * @brief Clase para el manejo del sensor de humedad digital.
 *
 */
class Moisture_sensor
{
public:
    /**
     * @brief Construye un nuevo objecto Moisture_sensor
     *
     * @param analog_pin pin digital donde se conecto el sensor
     */
    Moisture_sensor(int digital_pin);
    /**
     * @brief Devuelve la lectura realizada
     *
     * @return int lectura analógica realizada (0 indica conductividad completa, 1023 indica resistividad completa)
     */
    bool get_reading();

private:
    /**
     * @brief actualiza el valor de la lectura a realizar.
     *
     */
    void update_reading();
    /**
     * @brief pin digital donde se conectó el sensor.
     *
     */
    int sensor_pin = 0;
    /**
     * @brief lectura realizada.
     *
     */
    bool water_detected = false;
};

#endif
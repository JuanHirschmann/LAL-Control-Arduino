/**
 * @file Buzzer.h
 * @author Juan Hirschmann (jhirschmann@gmail.com)
 * @brief Controlador de Buzzer de 12 milimetros.
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef BUZZER_H
#define BUZZER_H
#include "Arduino.h"
#include "port_config.h"

class Buzzer
/**
 * @brief Clase para el manejo del buzzer por PWM manual,
 *  no utiliza pines PWM de Arduino. Sólo admite pines digitales.
 *
 */
{
public:
    /**
     * @brief Construye un nuevo objecto Buzzer
     *
     * @param buzzer_pin Pin elegido para conectar el buzzer, sólo sálida digital.
     * @param frequency Frecuencia del tono a emitir.
     */
    Buzzer(int buzzer_pin);
    /**
     * @brief Enciende el buzzer con con una duración en milisegundos duration,
     *  por defecto enciende el buzzer por un tiempo indefinido.
     *
     * @param duration Duración del encendido en milisegundos.
     */
    void turn_on(unsigned long duration = 0);
    /**
     * @brief Apaga el buzzer.
     *
     */
    void turn_off();
    /**
     * @brief Permuta el estado del led, si estaba encendido pasará a apagado
     * y viceversa.
     *
     * @param duration Duración del encendido en milisegundos.
     */
    void toggle(unsigned int duration = 0);
    /**
     * @brief Devuelve el estado del buzzer
     *
     * @return true El buzzer está activo.
     * @return false El buzzer está inactivo.
     */
    bool is_active();

private:
    bool is_ringing = false;
    int buzzer_pin;
};
#endif
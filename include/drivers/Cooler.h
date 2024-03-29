/**
 * @file Cooler.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Controlador de ventilador de 12 volts y 5 milímteros.
 * @version 0.1
 * @date 2022-11-30
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Arduino.h"
#include "system_settings.h"
/**
 * @brief Clase para el control de un ventilador de 3 terminales.
 *
 */
class Cooler
{
public:
    /**
     * @brief Construye un nuevo objecto Cooler
     *
     * @param power_pin Pin de control de velocidad del ventilador
     * @param speed_measurement_pin Pin de medición de velocidad del ventilador
     */
    Cooler(int power_pin, int speed_measurement_pin);
    /**
     * @brief Enciende el ventilador. Si el ciclo de trabajo deseado es menor que
     * FAN_MINIMUM_DUTY_CYCLE apaga el ventilador. Si el ciclo de trabajo es mayor al
     * umbral mínimo pero menor a FAN_AUTONOMOUS_DUTY_CYCLE enciende el ventilador durante
     * DEFAULT_DELAY milisegundos a máximo ciclo de trabajo (bloqueante) y luego reduce la velocidad.
     *
     * @param duty_cycle Ciclo de trabajo
     */
    void turn_on(float duty_cycle = 1.0);
    /**
     * @brief Apaga el ventilador
     *
     */
    void turn_off();
    /**
     * @brief Devuelve la cantidad de rotaciones desde el último llamado de la función
     *
     * @return Rotaciones desde último llamado.
     */
    unsigned long int get_rotation_count();
    /**
     * @brief Lectura el pin de medición de velocidad.
     *
     * @return true El pin de medición de rotación está en estado alto.
     * @return false El pin de medición de rotación está en estado bajo.
     */
    bool rotation_detected();
    /**
     * @brief Increment el contador de mediciones.
     *
     */
    void count_rotation();
    /**
     * @brief Estado del ventilador. No utiliza la medición de velocidad si no que,
     * si se llamó a la función turn_on(), el estado del ventilador será true independientemente de
     * si este está rotando o no.
     *
     * @return true El ventilador esta encendido.
     * @return false El ventilador está apagado.
     */
    bool is_active();

private:
    bool is_on = false;
    unsigned long int pulses_in_sample_period = 0;
    int power_pin;
    int speed_measurement_pint;
    float current_duty_cycle = 0;
    /**
     * @brief Devuelve a 0 las rotaciones contadas desde el último llamado.
     *
     */
    void reset_count();
};
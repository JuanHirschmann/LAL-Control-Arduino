/**
 * @file Display.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Controlador de LCD hd44780 por interfaz I2C
 * @version 0.1
 * @date 2022-11-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef _DISPLAY_H
#define _DISPLAY_H
#include "Wire.h"
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include "display_settings.h"
#include "system_settings.h"
/**
 * @brief Clase Display, internamente utiliza la clase hd44780ioClass para resolver
 * la interfaz i2c con el monitor.
 *
 */
class Display
{
public:
    /**
     * @brief Método para inicializar el objeto, sólo se puede luego o en setup().
     *
     */
    void init();
    /**
     * @brief Construye un nuevo objecto Display
     *
     */
    Display();
    /**
     * @brief Fija el valor de temperatura a actualizar (no la imprime en pantalla), la ubicación se da con
     * las constantes de offset de temperatura definidas en display_settings.h
     *
     * @param new_temperature Nueva temperatura a fijar.
     */
    void set_temp(float new_temperature);
    /**
     * @brief Fija la velocidad en RPS, no lo imprie en pantalla excepto que la variación de velocidades
     * sea lo suficientemente grande. La ubicación se da con
     * las constantes de offset de velocidad definidas en display_settings.h
     *
     * @param back_speed_pct Velocidad ventilador trasero [RPS]
     * @param front_speed_pct Velocidad ventilador delantero [RPS]
     */
    void set_fan_speed_pct(float back_speed_pct, float front_speed_pct);
    /**
     * @brief Fija el el texto a actualizar, no lo imprime en pantalla. La ubicación se da con
     * las constantes de offset de temperatura definidas en display_settings.h
     *
     * @param string_out Nuevo texto a fijar, no puede exceder el máximo establecido en display_settings.h
     */
    void set_text(const char *string_out);
    /**
     * @brief Actualiza los valores en pantalla con los parámetros previamente fijados. Solo actualiza la pantalla
     * cuando uno o más valores hayan cambiado.
     *
     */
    void update();
    /**
     * @brief limpia los caracteres de la pantalla y apaga la retroiluminación, no inhibe la escritura en pantalla.
     *
     */
    void turn_off();
    /**
     * @brief Enciende la retroiluminación y limpia los caracteres de la pantalla.
     *
     */
    void turn_on();

private:
    /**
     * @brief Objeto hd44780_I2Cexp
     *
     */
    hd44780_I2Cexp screen_interface;
    /**
     * @brief variable para saber cuando es necesario actualizar la pantalla con nuevos valores.
     *
     */
    bool update_needed = false;
    char on_screen_text[MAX_DISPLAY_STRING_LENGTH];
    /**
     * @brief Medición de temperatura visualizada en pantalla
     *
     */
    float on_screen_temp = 0.0;
    /**
     * @brief Velocidades de los ventiladores visualizadas en pantalla [RPS].
     *
     */
    float on_screen_fan_speed_pct[TOTAL_COOLERS] = {0, 0};
};
#endif
/**
 * @file user_messages.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Archivo para la configuración de interfaz con el usuario.
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef USER_MESSAGES_H
#define USER_MESSAGES_H
#include <avr/pgmspace.h>
const int MAX_MESSAGE_LENGTH = 70;
/**
 * @brief Maxima cantidad de carácteres en un mensaje
 * 
 */
const int MAX_PROCEDURE_STEPS = 8;
/**
 * @brief Cantidad total de pasos en el procedimeinto
 * 
 */
const int ERROR_TYPES = 6;
/**
 * @brief Cantidad total de errores posibles 
 * 
 */
static const char PROCEDURE_MESSAGES[MAX_PROCEDURE_STEPS][MAX_MESSAGE_LENGTH] PROGMEM = {
    {"LAL: Sistema de control de procedimiento.\0"},
    {"Confirmar funcionamiento de canilla de agua.\0"},
    {"Abrir valvula de vacio/extraccion.\0"},
    {"Encender extractor.\0"},
    {"Apagar extractor.\0"},
    {"Motor apagado.Esperando a que baje la temperatura.\0"},
    {"Cierre la llave de agua\0"},
    {"CONFIRMAR APAGADO\0"},
};
/**
 * @brief Instrucciones al operador
 * 
 */
/*enum ALARM_TYPES
{
    NO_ALARM=0,
    OVERTEMP_ALARM,
    HUMIDITY_ALARM,
    HALTED_FAN_ALARM,
    NO_TEMP_SENSOR_ALARM,
    OVERTEMP_WARNING,
    SLOW_FAN_WARNING,
}; RESPETAR EL ORDEN DE LOS ERROR_MESSAGES SEGÚN EL ORDEN DE LOS ALARM TYPES*/

static const char ERROR_MESSAGES[ERROR_TYPES][MAX_MESSAGE_LENGTH] PROGMEM = {
    {"No hay alarma\0"},
    {"Exceso de temperatura.\0"},
    {"Humedad en motor.\0"},
    {"Ventilador frontal detenido.\0"},
    {"Ventilador tasero detenido.\0"},
    {"Sensor de temperatura no detectado.\0"},
};
/**
 * @brief Mensajes de error.
 * 
 */
#endif
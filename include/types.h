/**
 * @file types.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Archivo de definición de tipos de dato.
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef TYPES_H
#define TYPES_H
enum ALARM_TYPES
{
    OVERTEMP_ALARM,
    HUMIDITY_ALARM,
    HALTED_FAN_ALARM,
    NO_TEMP_SENSOR_ALARM,
};
enum WARNING_TYPES
{
    OVERTEMP_WARNING,
    SLOW_FAN_WARNING,
};
#endif
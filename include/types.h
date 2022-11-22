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
    NO_ALARM = 0,
    OVERTEMP_ALARM,
    HUMIDITY_ALARM,
    HALTED_FAN_ALARM,
    NO_TEMP_SENSOR_ALARM,
    OVERTEMP_WARNING,
    SLOW_FAN_WARNING,
};
typedef struct
{
    float temperature;
    int current_step;
    bool shutdown_request;
    bool warning_request;
    bool alarm_request;
    bool next_step_request;
    bool poll_sensors_request;
    bool override_next_step;
    ALARM_TYPES current_alarm;

} Context_t;

enum COLOR_TYPES
{
    RED,
    YELLOW,
    GREEN,

};
#endif
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
const int DEBOUNCE_CONSTANT = 100; //[ms]
/**
 * @brief Constante de filtro de antirebote para el pulsador de avance
 * 
 */
const int DEFAULT_DELAY = 100; //[ms]
/**
 * @brief Duración del retardo por defecto
 * 
 */
const int SWITCH_TIMEOUT_CONSTANT = 2000; //[ms]
/**
 * @brief Duración del pulsado del botón necesaria para rechazar el pulsado 
 * 
 */
/* Comunicación serie*/
const int DEFAULT_BAUD_RATE = 9600;
/**
 * @brief Velocidad de comunicación serie por defecto. 
 * 
 */

/* Sensor de temperatura*/
const int MAX_SENSORS = 10;
/**
 * @brief Cantidad de sensores de temperatura máxima
 * 
 */
const float OVERTEMP_WARNING_THRESHOLD = 50; //°C
/**
 * @brief Umbral de advertencia para temperaturas elevadas
 * 
 */
const float OVERTEMP_ALARM_THRESHOLD = 70; //°C
/**
 * @brief Umbral de advertencia para temperatura excesivas
 * 
 */
const float ERROR_TEMPERATURE = -127; //°C
/**
 * @brief Valor de la lectura errónea del DS18B20
 * 
 */
const float HYSTERESIS_PERCENT = 0.95;
/**
 * @brief Porcentaje de histéresis de la advertencia de temperatura elevada. Si la temperatura excede el umbral, la advertencia 
se descarta cuando la temperatura es menor a HYSTERESIS_PERCENT*OVERTEMP_WARNING_THRESHOLD
 * 
 */
const int FAN_SPEED_SAMPLE_PERIOD = 1000; //[ms]
/**
 * @brief Periodo de muestro de velocidad para el ventilador
 * 
 */

/* LED dual*/
const float RED_COLOR_DUTY_CYCLE[] = {0, 1}; //{0, 1};
/**
 * @brief Valor del ciclo de trabajo para generar el color rojo
 * 
 */
const float YELLOW_COLOR_DUTY_CYCLE[] = {0.9, 0.9};
/**
 * @brief Valor del ciclo de trabajo para generar el color amarillo
 * 
 */
const float GREEN_COLOR_DUTY_CYCLE[] = {1, 0}; //{1, 0};
/**
 * @brief Valor del ciclo de trabajo para generar el color verde
 * 
 */
const int MAX_ANALOG_WRITE_VALUE = 255;
/**
 * @brief Maximo valor de escritura analógica para el Arduino Nano
 * 
 */

const float FAN_MINIMUM_DUTY_CYCLE = 0.3;
/**
 * @brief Ciclo de trabajo a partir del cual el cooler puede mantener su rotación si ya estaba encendido
 * 
 */
const float FAN_AUTONOMOUS_DUTY_CYCLE = 0.77; 
/**
 * @brief Ciclo de trabajo a partir del cual el cooler puede mantener su rotación partiendo del reposo.
 * 
 */
const int TOTAL_COOLERS = 2;
/**
 * @brief Cantidad de Coolers del sistema
 * 
 */
const float SPEED_VARIATION_UPDATE_THRESHOLD = 0.01;
/**
 * @brief Umbral porcentual para actualizar la velocidad
 * 
 */
#endif
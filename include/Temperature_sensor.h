/**
 * @file Temperature_sensor.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Módulo de gestión de sensores de temperatura por interfaz OneWire
 * @version 0.1
 * @date 2022-11-02
 *
 */
#ifndef TEMPERATURE_SENSOR
#define TEMPERATURE_SENSOR

#include "port_config.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class Temperature_sensor
{
  /**
   * @brief Clase para el control del sensor de temperatura por interfaz OneWire
   *
   */
public:
  Temperature_sensor(){};
  /**
   * @brief Construye un objeto Temperature_sensor.
   *
   * @param one_wire_bus Número de pin a utilizar como interfaz OneWire.
   */
  Temperature_sensor(int one_wire_bus);
  /**
   * @brief Obtiene la Temperatura de todos los sensores como un promedio simple (Celsius).
   *
   * @return float Temperatura promediado de los sensores (Celsius).
   */
  float get_reading();

private:
  /**
   * @brief Inicializa todos los sensores disponibles en la interaz
   *
   * @param one_wire_bus Número de pin a utilizar como interfaz OneWire.
   */
  void init_sensors(int one_wire_bus);
  /**
   * @brief Actualiza el vector de temperaturas del objeto.
   *
   */
  void update_readings();
  /**
   * @brief Cantidad de sensores ds18 detectados en la interfaz OneWire
   *
   */
  int available_ds18_devices = 0;
  /**
   * @brief Vector de temperaturas leídas.
   *
   */
  float readings[MAX_SENSORS];
  /**
   * @brief Objeto OneWire, utilizado para la interfaz de conexión.
   *
   */
  OneWire one_wire_interface;
  /**
   * @brief Objeto DallasTemperature, utilizado para la interacción con sensores.
   *
   */
  DallasTemperature DS18B20_sensor;
};
#endif
/**
 * @file Temperature_sensor.cpp
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "drivers/Temperature_sensor.h"
// Uso -127 para avisar error
Temperature_sensor::Temperature_sensor(int one_wire_bus) : one_wire_interface(one_wire_bus), DS18B20_sensor(&one_wire_interface)
{
  this->init_sensors(one_wire_bus);
}
float Temperature_sensor::get_reading()
{
  //  ¿SMA?
  this->update_readings();
  // float var = 0;
  float mean = 0;
  int count = this->available_ds18_devices;
  if (count <= 0)
  {
    mean = -127;
  }
  for (int i = 0; i < count; i++)
  {
    mean += this->readings[i];
  }
  mean = mean / count;
  return mean;
}
void Temperature_sensor::update_readings()
{
  this->available_ds18_devices = this->DS18B20_sensor.getDeviceCount();
  this->DS18B20_sensor.requestTemperatures();
  for (int i = 0; i < this->available_ds18_devices; i++)
  {
    this->readings[i] = this->DS18B20_sensor.getTempCByIndex(i);
  }
}
void Temperature_sensor::init_sensors(int one_wire_bus)
{
  this->DS18B20_sensor.begin();
  this->available_ds18_devices = this->DS18B20_sensor.getDeviceCount();
}

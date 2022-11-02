#include "Temperature_sensor.h"
// Uso -127 para avisar error
Temperature_sensor::Temperature_sensor(int one_wire_bus)
{
  this->init_sensors(one_wire_bus);
}
float Temperature_sensor::get_reading()
{
  // Agregar criterios para considerar mediciones (Descartar -127 y outliers) ¿SMA?
  this->update_readings();
  float var = 0;
  float mean = 0;
  int count = this->max_ds18_devices;
  if (count <= 0)
  {
    mean = -127;
  }
  for (int i = 0; i < count; i++)
  {
    mean += this->readings[i];
    var += this->readings[i];
  }
  mean = mean / count;
  var += mean;
  var = var / count;
  return mean;
}
void Temperature_sensor::update_readings()
{
  this->max_ds18_devices = this->DS18B20_sensor->getDeviceCount();
  this->DS18B20_sensor->requestTemperatures();
  char string_out[24];
  int max_devices = this->max_ds18_devices;
  for (int i = 0; i < this->max_ds18_devices; i++)
  {
    this->readings[i] = this->DS18B20_sensor->getTempCByIndex(i);
  }
}
void Temperature_sensor::init_sensors(int one_wire_bus)
{
  // OneWire *one_wire_aux=
  this->one_wire_interface = new OneWire(one_wire_bus);
  this->DS18B20_sensor = new DallasTemperature(this->one_wire_interface);
  this->DS18B20_sensor->begin();
  this->max_ds18_devices = this->DS18B20_sensor->getDeviceCount();
}
void Temperature_sensor::serial_print(const HardwareSerial *serial_port)
{
  // this->DS18B20_sensor->requestTemperatures();
  this->update_readings();
  char string_out[24];
  for (int i = 0; i < this->max_ds18_devices; i++)
  {

    sprintf(string_out, "Temperatura en el sensor %d: ", i);
    serial_port->print(string_out);
    serial_port->println(this->DS18B20_sensor->getTempCByIndex(i));
  }
}
Temperature_sensor::~Temperature_sensor()
{
  delete this->one_wire_interface;
  delete this->DS18B20_sensor;
}

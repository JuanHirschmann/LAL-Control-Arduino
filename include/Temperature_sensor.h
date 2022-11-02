#ifndef TEMP_SENSOR
#define TEMP_SENSOR

#include "config.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class Temperature_sensor
{
  public: 
    Temperature_sensor(int one_wire_bus);
    void serial_print(const HardwareSerial* serial_port);
    float get_reading();
    void update_readings();
    ~Temperature_sensor();
  private :
    int max_ds18_devices=0;
    float readings[MAX_SENSORS];
    OneWire *one_wire_interface;
    DallasTemperature *DS18B20_sensor;
    void init_sensors(int one_wire_bus);

};
#endif
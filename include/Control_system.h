#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H
#include "Temperature_sensor.h"
#include "Display_LCM2004.h"
#include "Instruction_list.h"
#include "Wire.h"
#include "config.h"
#include "Flag.h"

class Control_system
{
public:
    Control_system(TwoWire *two_wire);
    void update();
    ~Control_system();
    Flag show_next_step;
    Flag temperature_warning;
    Flag temperature_alarm;
    Flag update_temperature;
    Flag humidity_alarm;

private:
    // void init_interrupt(int pin, void(*callback), int mode);
    void init_instructions();
    Instruction_list procedure_list;
    Temperature_sensor *temp_sensor;
    Display_LCM2004 *display = nullptr;
    //   char **current_step_pointer = nullptr;
};
#endif
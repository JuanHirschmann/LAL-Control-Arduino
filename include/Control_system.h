#ifndef CONTROL_SYSTEM_H
#define CONTROL_SYSTEM_H
#include "Temperature_sensor.h"
#include "Display.h"
#include "List.h"
#include "config.h"
#include "Flag.h"
#include "Instruction_node.h"

#include "Subject.h"
class Control_system : public Subject
{
public:
    Control_system();
    void update();
    ~Control_system();
    void print(char *text)
    {
        display.print(text);
    }
    void init()
    {
        display.init();
    }
    Flag show_next_step;
    Flag temperature_warning;
    Flag temperature_alarm;
    Flag update_temperature;
    Flag humidity_alarm;
    // void attach_observer(Observer *obs);
    // void notify();

private:
    // void init_interrupt(int pin, void(*callback), int mode);
    // List</*class*/ Observer *> sensor_observers;

    void init_instructions();
    List<Instruction_node> procedure_list;
    Temperature_sensor *temp_sensor = nullptr;
    Display display;
    //    char **current_step_pointer = nullptr;
};
#endif
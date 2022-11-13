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
    float get_temperature_reading()
    {
        return this->temp_sensor->get_reading();
    }
    bool poll_sensors = false;
    bool show_next_step = false;
    // void attach_observer(Observer *obs);
    // void notify();
    Display display;             // = nullptr;
    void show_next_instruction() // probs cambiar a error_type
    {
        this->procedure_list.get_next();
        Serial.println(strlen(this->procedure_list.get_current()->get_text()));
        Serial.println(this->procedure_list.get_current()->get_text());
        this->display.set_text(this->procedure_list.get_current()->get_text());
    };

private:
    void notify_observers(Control_system *control);
    void init_instructions();
    List<Instruction_node> procedure_list;
    Temperature_sensor *temp_sensor = nullptr;
    //    char **current_step_pointer = nullptr;
};
#endif
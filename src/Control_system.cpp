#include "Control_system.h"
#include "System_observer.h"
Control_system::Control_system()
{
    this->init_instructions();
    //this->display =new Di
    this->temp_sensor = new Temperature_sensor(ONE_WIRE_BUS);
    this->display.set_fan_speed_pct(10);
}

void Control_system::init_instructions()
{
    const char *OPERATION_PROCEDURE[] = {
        "Paso 1",
        "Paso 2",
        "Paso 3",
        "Paso 4",
        "Paso 5",
        "Paso 6",
        "Paso 7",
        "FIN",
    };
    int n_rows = sizeof OPERATION_PROCEDURE / sizeof OPERATION_PROCEDURE[0];
    Instruction_node aux;
    for (int i = 0; i < n_rows; i++)
    {
        aux.set_text(OPERATION_PROCEDURE[i], strlen(OPERATION_PROCEDURE[i]));
        this->procedure_list.append(aux);
    }
    this->display.set_text(this->procedure_list.get_current()->get_text());
}
void Control_system::update()
{
    if (this->poll_sensors)
    {
        Serial.println("Avise");
        this->notify_observers(this);
        this->poll_sensors = false;
    }
    this->display.update();
}
void Control_system::notify_observers(Control_system *control)
{
    Serial.println(this->current_observers);
    for (int i = 0; i < this->current_observers + 1; i++)
    {
        static_cast<System_observer *>(this->observers[i])->update(control);
    }
};
Control_system::~Control_system()
{
    // delete this->display;
    delete this->temp_sensor;
}
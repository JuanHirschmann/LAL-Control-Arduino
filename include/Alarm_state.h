#ifndef ALARM_STATE_H
#define ALARM_STATE_H
#include "Control_system.h"
#include "Idle_state.h"
#include "Motor_control_state.h"
class Alarm_state : public Abstract_state
{
public:
    virtual void update(Control_system *machine);
    virtual void enter(Control_system *machine);
    virtual void exit(Control_system *machine);
    virtual Abstract_state *transition(Control_system *machine);
};
#endif
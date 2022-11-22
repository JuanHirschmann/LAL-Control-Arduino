#ifndef MOTOR_CONTROL_STATE_H
#define MOTOR_CONTROL_STATE_H
#include "Control_system.h"
#include "Abstract_state.h"
#include "Alarm_state.h"
#include "Warning_state.h"
#include "Idle_state.h"
class Motor_control_state : public Abstract_state
{
private:
    bool overtemp_override = false;

public:
    virtual void update(Control_system *machine);
    virtual void enter(Control_system *machine);
    virtual void exit(Control_system *machine);
    virtual Abstract_state *transition(Control_system *machine);
};
#endif
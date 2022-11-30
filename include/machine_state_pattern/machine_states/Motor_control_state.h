#ifndef MOTOR_CONTROL_STATE_H
#define MOTOR_CONTROL_STATE_H
#include "Control_system.h"
#include "machine_state_pattern/machine_states/Abstract_state.h"
#include "machine_state_pattern/machine_states/Idle_state.h"
class Motor_control_state : public Abstract_state
{
private:
    bool alarm_override = false;

public:
    virtual void update(Control_system *machine);
    virtual void enter(Control_system *machine);
    virtual void exit(Control_system *machine);
    virtual Abstract_state *transition(Control_system *machine);
};
#endif
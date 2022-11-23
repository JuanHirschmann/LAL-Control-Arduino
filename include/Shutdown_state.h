#ifndef SHUTDOWN_STATE_H
#define SHUTDOWN_STATE_H
#include "Control_system.h"
#include "Abstract_state.h"
#include "Idle_state.h"
class Shutdown_state : public Abstract_state
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
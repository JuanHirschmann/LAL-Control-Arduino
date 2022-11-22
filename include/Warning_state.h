#ifndef WARNING_STATE_H
#define WARNING_STATE_H
#include "Control_system.h"
#include "Idle_state.h"
#include "Alarm_state.h"
class Warning_state : public Abstract_state
{
public:
    virtual void update(Control_system *machine);
    virtual void enter(Control_system *machine);
    virtual void exit(Control_system *machine);
    virtual Abstract_state *transition(Control_system *machine);
};
#endif
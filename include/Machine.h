#ifndef MACHINE_H
#define MACHINE_H
#include "Abstract_state.h"

class Machine
{
public:
    Machine();
    virtual void transition_state() = 0;
    virtual ~Machine() = 0;

protected:
    Abstract_state *current_state = nullptr;
};
#endif

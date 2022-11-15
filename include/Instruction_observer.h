#ifndef INSTRUCTION_OBSERVER_H
#define INSTRUCTION_OBSERVER_H
#include "System_observer.h"
class Instruction_observer : public System_observer
{
public:
    void update(Control_system *subject)
    {
        if (subject->is_next_step_requested())
        {
            subject->next_step();
            subject->set_next_step_flag(false);
        }
    };

private:
};
#endif
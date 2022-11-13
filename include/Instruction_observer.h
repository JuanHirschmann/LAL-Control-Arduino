#ifndef INSTRUCTION_OBSERVER_H
#define INSTRUCTION_OBSERVER_H
#include "System_observer.h"
class Instruction_observer : public System_observer
{
public:
    void update(Control_system *subject)
    {
        if (subject->show_next_step)
        {
            subject->show_next_instruction();
        }
        subject->show_next_step = false;
    };

private:
};
#endif
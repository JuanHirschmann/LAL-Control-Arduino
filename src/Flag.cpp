#include "Flag.h"
void Flag::toggle()
{
    this->state = !this->state;
}
void Flag::turn_on()
{
    this->state = true;
}
void Flag::turn_off()
{
    this->state = false;
}
bool Flag::get_state()
{
    return this->state;
}
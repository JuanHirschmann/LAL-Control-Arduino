#ifndef SYSTEM_OBSERVER_H
#define SYSTEM_OBSERVER_H
#include "Observer.h"
class Control_system;
class System_observer : public Observer
{
public:
    virtual void update(Control_system *subject) = 0;

private:
};
#endif
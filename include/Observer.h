#ifndef _CHILD_OBSERVER_H_
#define _CHILD_OBSERVER_H_
#include "Subject_interface.h"
#include "Observer_interface.h"
class Observer : public Observer_interface
{
public:
    virtual void update(Subject_interface *subject_interface){};
};

#endif
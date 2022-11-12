#ifndef _OBSERVER_INTERFACE_H_
#define _OBSERVER_INTERFACE_H_
class Subject_interface;
class Observer_interface
{
public:
    virtual void update(Subject_interface *subject_interface) = 0;
};
#endif
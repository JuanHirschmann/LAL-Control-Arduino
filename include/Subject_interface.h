#ifndef _SUBJECT_INTERFACE_H_
#define _SUBJECT_INTERFACE_H_
const int MAX_OBSERVERS = 10;
class Observer_interface;
class Subject_interface
{
protected:
    Observer_interface *observers[MAX_OBSERVERS];

public:
    virtual void attach(Observer_interface *obs) = 0;
    virtual void notify_observers() = 0;
};
#endif
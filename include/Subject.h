#ifndef _CHILD_SUBJECT_H_
#define _CHILD_SUBJECT_H_

#include "Subject_interface.h"
#include "Observer_interface.h"
class Subject : public Subject_interface
{
public:
    void attach(Observer_interface *obs);
    void notify_observers();
};

#endif
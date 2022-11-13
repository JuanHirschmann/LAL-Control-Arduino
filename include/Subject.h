#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include "Subject_interface.h"
#include "Observer_interface.h"
#include "Arduino.h"
class Subject : public Subject_interface
{
public:
    void attach(Observer_interface *obs);
    void notify_observers(Subject_interface *subject);

protected:
    int current_observers = 0;
};

#endif
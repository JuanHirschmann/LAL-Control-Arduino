#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "Subject_interface.h"
#include "Observer_interface.h"
#include "Arduino.h"
class Observer : public Observer_interface
{
public:
    virtual void update(Subject_interface *subject_interface) { Serial.print("Respondí yo"); };
};

#endif
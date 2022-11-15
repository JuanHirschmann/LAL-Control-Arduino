#include "Subject.h"
void Subject::attach(Observer_interface *obs)
{

    this->observers[this->current_observers] = obs;
    this->current_observers++;
};
void Subject::notify_observers()
{
    for (int i = 0; i <= this->current_observers; i++)
    {
        this->observers[i]->update(this);
    }
};
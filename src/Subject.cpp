#include "Subject.h"
void Subject::attach(Observer_interface *obs)
{

    this->observers[this->current_observers] = obs;
    this->current_observers++;
};
void Subject::notify_observers(Subject_interface *subj)
{
    for (int i = 0; i < this->current_observers + 1; i++)
    {
        this->observers[i]->update(subj);
    }
};
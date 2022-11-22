#ifndef ABSTRACT_STATE_H
#define ABSTRACT_STATE_H
class Control_system;
class Abstract_state
{
public:
    virtual void update(Control_system *machine) = 0;
    virtual void enter(Control_system *machine) = 0;
    virtual void exit(Control_system *machine) = 0;
    virtual Abstract_state *transition(Control_system *machine) = 0;
    virtual ~Abstract_state(){};

private:
};
#endif
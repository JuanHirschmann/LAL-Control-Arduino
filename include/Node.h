#ifndef NODE_H
#define NODE_H
#include "stdio.h"
#include <string.h>
class Node
{
public:
    Node();
    virtual ~Node();
    virtual Node *get_next();
    virtual void link_next(Node *next_step);

protected:
    virtual void clear_node() = 0;

private:
    Node *next = nullptr;
};
#endif
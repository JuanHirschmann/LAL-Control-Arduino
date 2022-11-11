#include "Node.h"
Node::~Node()
{
    this->next = nullptr;
}
Node::Node()
{
    this->next = nullptr;
}
Node *Node::get_next()
{
    return this->next;
}
void Node::link_next(Node *next_step)
{
    this->next = next_step;
}
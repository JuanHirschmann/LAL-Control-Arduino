#ifndef LIST_H
#define LIST_H
#include "stdio.h"
#include <string.h>
template <typename Data>
class List
{
public:
    List()
    {
        this->first_element = nullptr;
        this->current_element = nullptr;
        this->last_element = nullptr;
    };
    List(Data first_element)
    {

        this->append(first_element);
    }
    List(const List &target_list)
    {
        this->copy(target_list);
    };
    void operator=(const List &target_list)
    {

        this->copy(target_list);
    }
    ~List()
    {
        this->clear_list();
    };

    void append(const Data last_element)
    {
        if (this->first_element == nullptr)
        {
            this->last_element = new Data;
            *this->last_element = last_element;
            this->first_element = this->last_element;
            this->current_element = this->last_element;
        }
        else
        {
            this->last_element->link_next(new Data);
            *this->last_element->get_next() = last_element;
            this->last_element = this->last_element->get_next();
        }
    };
    void reset()
    {
        this->current_element = this->first_element;
    };
    Data *get_current()
    {
        return this->current_element;
    };
    void get_next()
    {
        if (this->is_last() != true)
        {
            this->current_element = this->current_element->get_next();
        }
    }
    bool is_last()
    {

        return this->current_element->get_next() == nullptr;
    };

    void print()
    {
        Data *aux_pointer = this->first_element;
        while (aux_pointer != nullptr)
        {
            aux_pointer = aux_pointer->get_next();
        }
    };

private:
    Data *first_element = nullptr;
    Data *current_element = nullptr;
    Data *last_element = nullptr;
    void clear_list()
    {
        Data *aux_pointer;
        aux_pointer = this->first_element;
        while (aux_pointer != nullptr)
        {
            this->first_element = this->first_element->get_next();
            delete aux_pointer;
            aux_pointer = this->first_element;
        }
    };
    void copy(const List &target_list)
    { // RESETEA CURRENT_POINTER
        this->clear_list();
        Data *aux_pointer_target = target_list.first_element;
        while (aux_pointer_target != nullptr)
        {

            this->append(*aux_pointer_target);
            aux_pointer_target = aux_pointer_target->get_next();
        }
        this->reset();
    };
};
#endif
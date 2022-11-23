/**
 * @file System_observer.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef SYSTEM_OBSERVER_H
#define SYSTEM_OBSERVER_H
#include "Observer.h"
#include "Control_system.h"
/**
 * @brief Clase interfaz para implementar observadores para sujetos de
 * la clase Control_system
 *
 */
class System_observer : public Observer
{
public:
    virtual void update(Control_system *subject) = 0;

private:
};
#endif
#ifndef _COOLER_OBSERVER_H
#define _COOLER_OBSERVER_H
#include "observer_pattern/observers/System_observer.h"
#include "Control_system.h"
const int SAMPLE_PERIOD = 1; //[s]
/**
 * @brief Clase heredera de System_observer, creada para observar
 *  el estado de las instrucciones.
 *
 */
class Cooler_observer : public System_observer
{

public:
    Cooler_observer(){};
    /**
     * @brief Si el indicador de próximo paso del usuario está activo y
     * el acceso a la próxima instrucción no esté bloqueado, avanza hacia la siguiente instrucción.
     *
     * @param subject sujeto a observar.
     */
    void update(Control_system *subject);
    void update_speed(Control_system *subject);

private:
    double speed[TOTAL_COOLERS] = {0, 0};
};
#endif
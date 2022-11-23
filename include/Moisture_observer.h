#ifndef MOISTURE_OBSERVER_H
#define MOISTURE_OBSERVER_H
#include "System_observer.h"
#include "Arduino.h"
#include "Control_system.h"
#include "system_settings.h"
#include "types.h"
/**
 * @brief Clase heredera de System_observer, creada para observar
 *  el estado de los sensores de humedad.
 *
 */
class Moisture_observer : public System_observer
{
public:
    /**
     * @brief Actualización del observador, mide la humedad y, si excede el umbral
     * MOISTURE_ALARM_THRESHOLD, solicita una alarma del tipo HUMIDITY_ALARM.
     *
     * @param subject sujeto a observar
     */
    void update(Control_system *subject);

private:
};
#endif
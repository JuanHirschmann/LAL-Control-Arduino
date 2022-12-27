
#ifndef CHECK_INSTRUCTION_STATE_H
#define CHECK_INSTRUCTION_STATE_H
#include "Control_system.h"
#include "machine_state_pattern/machine_states/Abstract_state.h"
#include "machine_state_pattern/machine_states/Alarm_state.h"

class Check_instruction_state : public Abstract_state
{
public:
    /**
     * @brief Actualización de estado, si existe una solicitud de
     * apagado el sistema se resetea.
     *
     * @param machine Máquina de estados
     */
    virtual void update(Control_system *machine);
    /**
     * @brief Entrada del estado, resuelve las instrucciones a realizar en cada paso:
     *  -WELCOME_STEP: Primer paso, apaga ventiladores y enciende en rojo el led de suministro de agua.
     *  -WATER_ON_STEP: Enciende led de suministro de agua.
     *  -MOTOR_ON_STEP: Si no hay alarmas ni advertencia enciende los ventiladores a velocidad baja. Si sólo hay una advertencia
     *   enciende el motor. Si hay algun tipo de alarma no enciende el motor.
     *  -MOTOR_OFF_STEP: Enciende los ventiladores a velocidad máxima.
     *  -MOTOR_COOLDOWN_STEP: Bloquea la entrada de usuario hasta que el motor se haya enfriado (no haya advertencia de exceso de temperatura).
     *  -WATER_OFF_STEP: Apaga ambos ventiladores
     *
     * @param machine Máquina de estados.
     */
    virtual void enter(Control_system *machine);
    /**
     * @brief Salida del estado. No realiza ninguna acción.
     *
     * @param machine Máquina de estados.
     */
    virtual void exit(Control_system *machine);
    /**
     * @brief Transición de estados. Sólo permite la transición a estado neutro si existe una solicitud
     * de paso siguiente.
     *
     * @param machine Máquina de estados
     * @return Abstract_state* Nuevo estado
     */
    virtual Abstract_state *transition(Control_system *machine);
};
#endif
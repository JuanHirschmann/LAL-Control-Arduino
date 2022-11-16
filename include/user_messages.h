/**
 * @file user_messages.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Archivo para la configuración de interfaz con el usuario.
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef USER_MESSAGES_H
#define USER_MESSAGES_H
const int MAX_MESSAGE_LENGTH = 40;
const char PROCEDURE_MESSAGES[][MAX_MESSAGE_LENGTH] = {"HOLA",
                                                       "COMO",
                                                       "ESTAS",
                                                       "MENSAJE MAS LARGO PARA VER SI SIGUE",
                                                       "MENSAJE PICOMA",
                                                       "TEXTO MEDIANO",
                                                       "TEXTO MACROMA 12345678890",
                                                       "UNO MAS",
                                                       "OTRO MAS",
                                                       "CONFIRMAR APAGADO"};
const int MAX_PROCEDURE_STEPS = 10;
#endif
/**
 * @file display_config.h
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief Módulo de definición de constantes y mensajes para el display LCM2004
 * @version 0.1
 * @date 2022-11-02
 *
 */
#ifndef DISPLAY_CONFIG_H
#define DISPLAY_CONFIG_H
#include <stdint.h>
const int MAX_CHAR_DISPLAY = 50;
const int MAX_BUFFER_SIZE = 32;
const int CHARACTER_DISPLAY_RESOLUTION[] = {20, 4};
const int DISPLAY_I2C_ADDRESS = 0x27;

const char CELSIUS_CHARACTER = 223;
const char PERCENTAGE_SIGN = 37;
const char OVERTEMP_WARNING_MESSAGE[] = "Exceso de temperatura";
const int DISPLAY_TEMP_DECIMALS = 1;

const int MAX_PROCEDURE_STEPS = 7;
const int HOME_CURSOR_OFFSET[] = {0, 0};
const int TEMP_INDICATOR_CURSOR_OFFSET[] = {0, 3};
const int FAN_INDICATOR_CURSOR_OFFSET[] = {10, 3};
const uint8_t TEMP_SYMBOL_CHARACTER[] = {
    0b01110,
    0b001010,
    0b01010,
    0b01010,
    0b01110,
    0b11111,
    0b11111,
    0b01110};
const uint8_t NEG_TEMP_SYMBOL_CHARACTER[] = {
    0b10001,
    0b10101,
    0b10101,
    0b10101,
    0b10001,
    0b00000,
    0b00000,
    0b10001};
const uint8_t FAN_SYMBOL_CHARACTER[] = {
    0x04,
    0x0A,
    0x0A,
    0x0A,
    0x0E,
    0x1F,
    0x1F,
    0x0E};
#endif
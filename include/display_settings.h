#ifndef DISPLAY_SETTINGS_H
#define DISPLAY_SETTINGS_H
enum display_symbols
{
    TEMP_SYMBOL = 0,
    NEG_TEMP_SYMBOL,
    FAN_SYMBOL,
};
const int MAX_DISPLAY_STRING_LENGTH = 32;
const char CELSIUS_CHARACTER = 223;
const char PERCENTAGE_SIGN = 37;
const int LCD_DISPLAY_RESOLUTION[2] = {20, 4};
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
#ifndef CONFIG
#define CONFIG

const int ONE_WIRE_BUS = 5; // D5 como digital in
const int MAX_SENSORS = 10;
const int DEFAULT_BAUD_RATE = 9600;
const bool DEBUGGING = true;
const int DEFAULT_DELAY=100;
const int MAX_CHAR_DISPLAY=200;
const unsigned char TEMP_SYMBOL_CHARACTER[] = {
  0b01110,
  0b001010,
  0b01010,
  0b01010,
  0b01110,
  0b11111,
  0b11111,
  0b01110
};
const unsigned char NEG_TEMP_SYMBOL_CHARACTER[] = {
  0b10001,
  0b10101,
  0b10101,
  0b10101,
  0b10001,
  0b00000,
  0b00000,
  0b10001
};
const unsigned char FAN_SYMBOL_CHARACTER[]=
{
  0b00000,
  0b00100,
  0b10101,
  0b01110,
  0b11111,
  0b01110,
  0b10101,
  0b00100
};
const char CELSIUS_CHARACTER=223;

const char PERCENTAGE_SIGN='%';

const char OVERTEMP_WARNING_MESSAGE[]="Exceso de temperatura";
#endif
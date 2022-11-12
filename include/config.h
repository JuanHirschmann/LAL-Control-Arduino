#ifndef CONFIG_H
#define CONFIG_H
const int ONE_WIRE_BUS = 5; // D5 como digital in
const int BUTTON_PIN = 3;   // D3 como digital in
const int MAX_SENSORS = 10;
const int DEFAULT_BAUD_RATE = 9600;
const bool DEBUGGING = true;
const int DEFAULT_DELAY = 100;
const int DEBOUNCE_CONSTANT = 200; //[ms]

#endif
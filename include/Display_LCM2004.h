
#ifndef DISPLAY_LCM2004
#define DISPLAY_LCM2004
#include "config.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "utils.h"
enum display_symbols 
{   TEMP_SYMBOL,
    NEG_TEMP_SYMBOL,
    FAN_SYMBOL,
    //autumn = 8,
    //winter = 12
};

class Display_LCM2004
{
  //INTERFAZ i2c
  public:
    void display(const char string_out[]);
    Display_LCM2004();
    ~Display_LCM2004();
    //void turn_on();
    void set_temp(float new_temperature);
    void set_fan_speed_pct(int new_speed_pct);
    void trigger_humidity_warning();
    void trigger_overtemp_warning();
    void trigger_overtemp_error();
    void set_text(char string_out[]);
    void update_display();    
    //void blink_screen();
    //void blink_temperature_indicator();
    //void blink_humidity_indicator();
  private:
    bool blink_temp_indicator=false;
    void init_display();
    void update_temperature();
    void update_fan_speed();
    void update_text();
    LiquidCrystal_I2C *lcd_display;
    float on_screen_temp; //Temperatura visualizada
    char on_screen_text[MAX_CHAR_DISPLAY];//Texto en pantalla
    //bool on_screen_humidity; //Presencia de humedad en motor (True es humedo, false no)
    int on_screen_fan_speed_pct; //Porcentaje de velocidad en el ventilador (100 es máximo, 0 es apagado)
};

#endif
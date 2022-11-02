
#ifndef DISPLAY_LCM2004
#define DISPLAY_LCM2004
#include "display_config.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "utils.h"
enum display_symbols
{
  TEMP_SYMBOL,
  NEG_TEMP_SYMBOL,
  FAN_SYMBOL,
  // autumn = 8,
  // winter = 12
};

class Display_LCM2004
{
  // INTERFAZ i2c
public:
  void display(const char string_out[]);
  Display_LCM2004();
  ~Display_LCM2004();
  // void turn_on();
  void set_temp(float new_temperature);
  void set_fan_speed_pct(int new_speed_pct);
  void trigger_humidity_warning();
  void trigger_overtemp_warning();
  void trigger_overtemp_error();
  void set_text(const char string_out[]);
  void update_display();
  // void blink_screen();
  // void blink_temperature_indicator();
  // void blink_humidity_indicator();
private:
  bool blink_temp_indicator = false;
  void init_display();
  void update_temperature();

  void update_fan_speed();
  void update_text();

  char on_screen_text[MAX_CHAR_DISPLAY]; // Texto en pantalla
  /**
   * @brief Objeto LiquidCrystal_I2C, utilizado para controlar el display LCM2004 por interfaz I2C
   *
   */
  LiquidCrystal_I2C *lcd_display;
  /**
   * @brief Medición de temperatura visualizada en pantalla
   *
   */
  float on_screen_temp;
  /**
   * @brief Velocidad del ventilador visualizada en pantalla. 100 es máxima velocidad, 0 es apagado.
   *
   */
  int on_screen_fan_speed_pct; // Porcentaje de velocidad en el ventilador (100 es máximo, 0 es apagado)
};

#endif
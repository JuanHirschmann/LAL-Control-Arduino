#include "Display_LCM2004.h"
Display_LCM2004::Display_LCM2004()
{
  this->init_display();
  // this->lcd_display->createChar(TEMP_SYMBOL, TEMP_SYMBOL_CHARACTER);
  // this->lcd_display->createChar(NEG_TEMP_SYMBOL, NEG_TEMP_SYMBOL_CHARACTER);
  // this->lcd_display->createChar(FAN_SYMBOL, reinterpret_cast<const char *>(FAN_SYMBOL_CHARACTER));
};

void Display_LCM2004::init_display()
{
  this->lcd_display = new LiquidCrystal_I2C(DISPLAY_I2C_ADDRESS, CHARACTER_DISPLAY_RESOLUTION[0], CHARACTER_DISPLAY_RESOLUTION[1]); //, this->wire_interface);
  this->lcd_display->init();
  this->lcd_display->setCursor(0, 0);
  this->lcd_display->backlight();
  this->lcd_display->noCursor();
}
void Display_LCM2004::update_display()
{
  this->lcd_display->clear(); // Titila
  this->update_text();
  this->update_temperature();
  this->update_fan_speed();
}
void Display_LCM2004::update_text()
{
  this->lcd_display->setCursor(HOME_CURSOR_OFFSET[0], HOME_CURSOR_OFFSET[1]);
  this->lcd_display->print(this->on_screen_text);
}
void Display_LCM2004::update_temperature() // Ver como agregar celsius de una manera linda
{
  this->lcd_display->setCursor(TEMP_INDICATOR_CURSOR_OFFSET[0], TEMP_INDICATOR_CURSOR_OFFSET[1]);
  if (blink_temp_indicator)
  {
    // this->lcd_display->write(NEG_TEMP_SYMBOL);
    this->blink_temp_indicator = false;
  }
  else
  {
    // this->lcd_display->write(TEMP_SYMBOL);
  }
  this->lcd_display->setCursor(TEMP_INDICATOR_CURSOR_OFFSET[0] + 1, TEMP_INDICATOR_CURSOR_OFFSET[1]);
  char buf[MAX_BUFFER_SIZE];
  ftoa(this->on_screen_temp, buf, DISPLAY_TEMP_DECIMALS);
  strncat(buf, &CELSIUS_CHARACTER, 1);
  this->lcd_display->print(buf);
}
void Display_LCM2004::update_fan_speed()
{
  this->lcd_display->setCursor(FAN_INDICATOR_CURSOR_OFFSET[0], FAN_INDICATOR_CURSOR_OFFSET[1]);
  // this->lcd_display->write(FAN_SYMBOL);
  this->lcd_display->setCursor(FAN_INDICATOR_CURSOR_OFFSET[0] + 1, FAN_INDICATOR_CURSOR_OFFSET[1]);
  char buf[MAX_BUFFER_SIZE];
  sprintf(buf, "%d", this->on_screen_fan_speed_pct);
  strcat(buf, &PERCENTAGE_SIGN);

  this->lcd_display->print(buf);
}
void Display_LCM2004::set_temp(float new_temperature)
{
  this->on_screen_temp = new_temperature;
}
void Display_LCM2004::set_text(const char string_out[])
{
  strcpy(this->on_screen_text, string_out);
}
void Display_LCM2004::set_fan_speed_pct(int new_speed_pct)
{
  this->on_screen_fan_speed_pct = new_speed_pct;
}
void Display_LCM2004::trigger_overtemp_warning()
{
  this->lcd_display->setCursor(FAN_INDICATOR_CURSOR_OFFSET[0], FAN_INDICATOR_CURSOR_OFFSET[1]);
  this->blink_temp_indicator = true;
  // this->lcd_display->clear();
  // this->set_text(OVERTEMP_WARNING_MESSAGE);
}
void Display_LCM2004::trigger_overtemp_error()
{
  this->lcd_display->clear();
  this->set_text(OVERTEMP_WARNING_MESSAGE); // const_char elimina warning
}
Display_LCM2004::~Display_LCM2004()
{
  delete this->lcd_display; // LiquidCrystal_I2C no implementó destructor vitual, no puedo eliminar el warning sin modificar la biblioteca
};
#include "Display_LCM2004.h"
Display_LCM2004::Display_LCM2004()
{
  this->init_display();
  this->lcd_display->createChar(TEMP_SYMBOL, TEMP_SYMBOL_CHARACTER);
  this->lcd_display->createChar(NEG_TEMP_SYMBOL, NEG_TEMP_SYMBOL_CHARACTER);
  this->lcd_display->createChar(FAN_SYMBOL, FAN_SYMBOL_CHARACTER);
};
void Display_LCM2004::init_display()
{
  this->lcd_display = new LiquidCrystal_I2C(0x27, 20, 4);
  this->lcd_display->init();
  this->lcd_display->setCursor(0, 0);
  this->lcd_display->backlight();
}
void Display_LCM2004::update_display()
{
  this->lcd_display->clear();
  this->update_text();
  this->update_temperature();
  this->update_fan_speed();
}
void Display_LCM2004::update_text()
{
  this->lcd_display->setCursor(0, 0);
  this->lcd_display->print(this->on_screen_text);
}
void Display_LCM2004::update_temperature() // Ver como agregar celsius de una manera linda
{
  this->lcd_display->setCursor(0, 3);
  if (blink_temp_indicator)
  {
    this->lcd_display->write(NEG_TEMP_SYMBOL);
    this->blink_temp_indicator = false;
  }
  else
  {
    this->lcd_display->write(TEMP_SYMBOL);
  }
  this->lcd_display->setCursor(1, 3);
  char buf[32];
  ftoa(this->on_screen_temp, buf, 1);
  strncat(buf, &CELSIUS_CHARACTER, 1);
  this->lcd_display->print(buf);
}
void Display_LCM2004::update_fan_speed() // Ver como agregar celsius de una manera linda
{
  this->lcd_display->setCursor(10, 3);
  this->lcd_display->write(FAN_SYMBOL);
  this->lcd_display->setCursor(11, 3);
  char buf[32];
  sprintf(buf, "%d", this->on_screen_fan_speed_pct);
  strcat(buf, &PERCENTAGE_SIGN);
  this->lcd_display->print(buf);
}
void Display_LCM2004::set_temp(float new_temperature)
{
  this->on_screen_temp = new_temperature;
}
void Display_LCM2004::set_text(char string_out[])
{
  strcpy(this->on_screen_text, string_out);
}
void Display_LCM2004::set_fan_speed_pct(int new_speed_pct)
{
  this->on_screen_fan_speed_pct = new_speed_pct;
}
void Display_LCM2004::trigger_overtemp_warning()
{
  this->lcd_display->setCursor(10, 3);
  this->blink_temp_indicator = true;
  // this->lcd_display->clear();
  // this->set_text(OVERTEMP_WARNING_MESSAGE);
}
void Display_LCM2004::trigger_overtemp_error()
{
  this->lcd_display->clear();
  this->set_text(const_cast<char *>(OVERTEMP_WARNING_MESSAGE)); // const_char elimina warning
}
Display_LCM2004::~Display_LCM2004()
{
  delete this->lcd_display;
};
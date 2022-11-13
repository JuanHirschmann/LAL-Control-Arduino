#include "Display.h"
void Display::init()
{
    this->screen_interface.begin(20, 4);
    // this->screen_interface.createChar(TEMP_SYMBOL, TEMP_SYMBOL_CHARACTER);
};
void Display::print(char *string_out)
{
    this->screen_interface.print(string_out);
}
void Display::update()
{
    this->update_needed = true;
    if (this->update_needed)
    {
        this->screen_interface.clear(); // Titila
        this->update_text();
        this->update_temperature();
        this->update_fan_speed();
        this->update_needed = false;
    }
}
void Display::update_text()
{
    this->screen_interface.setCursor(HOME_CURSOR_OFFSET[0], HOME_CURSOR_OFFSET[1]);
    this->screen_interface.print(this->on_screen_text);
}
void Display::update_temperature() // Ver como agregar celsius de una manera linda
{
    this->screen_interface.setCursor(TEMP_INDICATOR_CURSOR_OFFSET[0], TEMP_INDICATOR_CURSOR_OFFSET[1]);
    if (blink_temp_indicator)
    {
        // this->screen_interface.write(NEG_TEMP_SYMBOL);
        this->blink_temp_indicator = false;
    }
    else
    {
        // this->screen_interface.write(TEMP_SYMBOL);
    }
    this->screen_interface.setCursor(TEMP_INDICATOR_CURSOR_OFFSET[0] + 1, TEMP_INDICATOR_CURSOR_OFFSET[1]);
    char buf[MAX_BUFFER_SIZE];
    ftoa(this->on_screen_temp, buf, DISPLAY_TEMP_DECIMALS);
    strncat(buf, &CELSIUS_CHARACTER, 1);
    this->screen_interface.print(buf);
}
void Display::update_fan_speed()
{
    this->screen_interface.setCursor(FAN_INDICATOR_CURSOR_OFFSET[0], FAN_INDICATOR_CURSOR_OFFSET[1]);
    // this->screen_interface.write(FAN_SYMBOL);
    this->screen_interface.setCursor(FAN_INDICATOR_CURSOR_OFFSET[0] + 1, FAN_INDICATOR_CURSOR_OFFSET[1]);
    char buf[MAX_BUFFER_SIZE];
    clear_string(buf);
    sprintf(buf, "%d", this->on_screen_fan_speed_pct);
    strcat(buf, &PERCENTAGE_SIGN);
    // Serial.println(buf); // arregla el porcentaje en la pantalla
    this->screen_interface.print(buf);
}
void Display::set_temp(float new_temperature)
{
    if (new_temperature != this->on_screen_temp)
    {
        this->on_screen_temp = new_temperature;
        update_needed = true;
    }
}
void Display::set_text(const char string_out[])
{
    if (true) //! strncmp(this->on_screen_text, string_out, 20))
    {
        strcpy(this->on_screen_text, string_out);
        char aux_null = '\0';
        strncat(this->on_screen_text, &aux_null, 1);
        update_needed = true;
    }
}
void Display::set_fan_speed_pct(int new_speed_pct)
{
    if (new_speed_pct != this->on_screen_fan_speed_pct)
    {
        this->on_screen_fan_speed_pct = new_speed_pct;
        update_needed = true;
    }
}
void Display::trigger_overtemp_warning()
{
    this->screen_interface.setCursor(FAN_INDICATOR_CURSOR_OFFSET[0], FAN_INDICATOR_CURSOR_OFFSET[1]);
    this->blink_temp_indicator = true;
    // this->screen_interface.clear();
    // this->set_text(OVERTEMP_WARNING_MESSAGE);
}
void Display::trigger_overtemp_error()
{
    this->screen_interface.clear();
    this->set_text(OVERTEMP_WARNING_MESSAGE); // const_char elimina warning
}
/**
 * @file Display.cpp
 * @author Juan Hirschmann (jhirschmann@fi.uba.ar)
 * @brief
 * @version 0.1
 * @date 2022-11-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "drivers/Display.h"
Display::Display()
{
    // No inicializar objecto de interfaz de pantalla en el constructor.
}
void Display::init()
{

    this->screen_interface.begin(20, 4);
    this->screen_interface.lineWrap();
    this->screen_interface.home();
}
void Display::set_temp(float new_temp)
{
    if (this->on_screen_temp != new_temp)
    {

        this->on_screen_temp = new_temp;
        this->update_needed = true;
    }
}
void Display::set_fan_speed_pct(float back_speed_pct, float front_speed_pct)
{
    float cooler_speed_variation = 1;
    if (back_speed_pct != 0)
    {
        cooler_speed_variation = abs(this->on_screen_fan_speed_pct[0] - back_speed_pct) / back_speed_pct;
    }
    else if (this->on_screen_fan_speed_pct[0] == 0)
    {
        cooler_speed_variation = 0;
    }
    if (cooler_speed_variation > SPEED_VARIATION_UPDATE_THRESHOLD)
    {
        this->on_screen_fan_speed_pct[0] = back_speed_pct;
        this->update_needed = true;
    }
    if (front_speed_pct != 0)
    {
        cooler_speed_variation = abs(this->on_screen_fan_speed_pct[1] - front_speed_pct) / front_speed_pct;
    }
    else if (this->on_screen_fan_speed_pct[1] == 0)
    {
        cooler_speed_variation = 0;
    }
    if (cooler_speed_variation > SPEED_VARIATION_UPDATE_THRESHOLD)
    {
        this->on_screen_fan_speed_pct[1] = front_speed_pct;
        this->update_needed = true;
    }
}
void Display::set_text(const char *string_out)
{

    if (strncmp(string_out, this->on_screen_text, MAX_DISPLAY_STRING_LENGTH) != 0)
    {
        strncpy(this->on_screen_text, string_out, MAX_DISPLAY_STRING_LENGTH);
        this->update_needed = true;
    }
}
void Display::update()
{
    if (this->on_screen_timer)
    {
        this->update_timer();
    }
    if (this->update_needed)
    {
        this->screen_interface.clear();
        this->screen_interface.home();

        this->screen_interface.print(this->on_screen_text);
        this->screen_interface.setCursor(TEMP_INDICATOR_CURSOR_OFFSET[0], TEMP_INDICATOR_CURSOR_OFFSET[1]);
        this->screen_interface.print(this->on_screen_temp, 1);
        this->screen_interface.setCursor(FAN_INDICATOR_CURSOR_OFFSET[0], FAN_INDICATOR_CURSOR_OFFSET[1]);
        this->screen_interface.print(this->on_screen_fan_speed_pct[0], 0);
        this->screen_interface.setCursor(FAN_INDICATOR_CURSOR_OFFSET[0] + 7, FAN_INDICATOR_CURSOR_OFFSET[1]);

        this->screen_interface.print(this->on_screen_fan_speed_pct[1], 0);

        if (this->on_screen_timer)
        {
            this->screen_interface.setCursor(TIMER_CURSOR_OFFSET[0], TIMER_CURSOR_OFFSET[1]);
            if (this->on_screen_minutes < 10)
            {
                this->screen_interface.print(0);
            }
            this->screen_interface.print(this->on_screen_minutes);
            this->screen_interface.print(":");
            if (this->on_screen_seconds < 10)
            {
                this->screen_interface.print(0);
            }
            this->screen_interface.print(this->on_screen_seconds);
        }
        this->update_needed = false;
    }
}
void Display::turn_off()
{
    this->screen_interface.clear();
    this->screen_interface.noBacklight();
}
void Display::turn_on()
{
    this->screen_interface.clear();
    this->screen_interface.backlight();
}
void Display::update_timer()
{
    unsigned long current_call = millis();
    unsigned long timer_delta = current_call - this->millis_on_timer_call;

    int seconds_elapsed = int(timer_delta / 1000);
    if (seconds_elapsed != 0)
    {
        this->update_needed = true;
        int minutes_elapsed = int(seconds_elapsed / 60);
        seconds_elapsed = seconds_elapsed - minutes_elapsed * 60;
        this->on_screen_minutes = this->on_screen_minutes + minutes_elapsed;
        this->on_screen_seconds = this->on_screen_seconds + seconds_elapsed;
        if (this->on_screen_seconds >= 60)
        {
            this->on_screen_minutes++;
            this->on_screen_seconds = 0;
        }
        this->millis_on_timer_call = current_call;
    }
}
void Display::show_timer()
{
    this->on_screen_timer = true;
    this->millis_on_timer_call = millis();
    this->update_needed = true;
}
void Display::hide_timer()
{
    this->on_screen_timer = false;
}
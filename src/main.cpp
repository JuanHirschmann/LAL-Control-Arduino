#include <Arduino.h>
#include "config.h"
#include "Temperature_sensor.h"
#include "Display_LCM2004.h"
#include "stdio.h"
#include "utils.h"
//
Display_LCM2004 *LCD_display; // No se puede declarar directo en global scope
Temperature_sensor temp_sensor(ONE_WIRE_BUS);
int i = 0;
void setup()
{

  LCD_display = new Display_LCM2004();
  pinMode(ONE_WIRE_BUS, INPUT);
  if (DEBUGGING)
  {
  }
  Serial.begin(DEFAULT_BAUD_RATE);
}
void loop()
{
  if (DEBUGGING)
  {
  }
  float temperature = temp_sensor.get_reading();
  LCD_display->set_temp(temperature);
  LCD_display->set_text("Instrucción");
  LCD_display->set_fan_speed_pct(i % 10);
  if (i % 10 > 7)
  { // and i%10>9){
    LCD_display->trigger_overtemp_warning();
  }
  LCD_display->update_display();
  Serial.println(temperature);
  // delay(DEFAULT_DELAY);
  i++;
};
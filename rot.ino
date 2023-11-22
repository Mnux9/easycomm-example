#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,8,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#include <Wire.h>
#include "globals.h"
#include "easycomm.h"


easycomm comm;


enum _rotator_error homing(int32_t seek_az, int32_t seek_el);
int32_t deg2step(float deg);
float step2deg(int32_t step);

void setup() {
    // Homing switch

    // Serial Communication
    comm.easycomm_init();

      lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("meow :3");




}

void loop() {

    // Run easycomm implementation
    comm.easycomm_proc();

    // Get position of both axis
    lcd.setCursor(0,0);
    lcd.print(control_az.setpoint);
    control_el.input = 7;

}

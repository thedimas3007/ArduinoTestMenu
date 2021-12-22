#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.clear();
  lcd.print("LoL");
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

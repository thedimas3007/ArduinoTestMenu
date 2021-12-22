#include "LiquidCrystal_I2C.h"

#define UP 11
#define DOWN 12
// #define DOWN 10

LiquidCrystal_I2C lcd(0x27, 20, 4);

char *elements[] = {"Element 1", "Element 2", "Element 3", "Element 4"};
byte amount = 4;
byte elementsWithBool[] {3};
byte elementsWithNum[] {1, 4};

bool boolValues[] = {false};
byte numValues[] = {0, 10};

bool selPressed = false;
bool upPressed = false;
bool downPressed = false;
bool downState = false;
bool pressed = false;

bool doUpdate = false;
byte line = 0;

void setup() {
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);

  lcd.begin();
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
    downState = !digitalRead(DOWN);
  
  if (downState && !downPressed) {
    downPressed = true;
    line = line < 3 ? line + 1 : 0;
    doUpdate = true;
  }
  if (!downState && downPressed) {
    downState = false;
  }

  if (millis() % 1000 == 0 || doUpdate) {
    lcd.clear();
    lcd.setCursor(0, line);
    lcd.print(">");
    for (byte x = 0; x < amount; x++) {
        lcd.setCursor(1, x);
      lcd.print(elements[x]);
    }
    doUpdate = false;
  }

  if (upPressed && digitalRead(UP)) {
    pressed = false;
    upPressed = false;
  }
  else if (downPressed && digitalRead(DOWN)) {
    pressed = false;
    downPressed = false;
  }
}

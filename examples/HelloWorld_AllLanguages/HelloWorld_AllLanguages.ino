#include <ALLCD.h>

ALLCD lcd(0x27, 16, 2); // адрес I2C, размер дисплея

void setup() {
  lcd.begin();
  lcd.loadFont("azerbaijani");
  lcd.printUnicode("Salam, çöğü!");
}

void loop() {}

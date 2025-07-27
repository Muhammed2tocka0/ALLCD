#ifndef ALLCD_H
#define ALLCD_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class ALLCD {
public:
    ALLCD(uint8_t lcd_addr, uint8_t cols, uint8_t rows);
    void begin();
    void loadFont(const String& lang);
    void printUnicode(const String& text);

private:
    LiquidCrystal_I2C lcd;
    void loadCustomChar(byte index, const byte data[8]);
    byte getCustomCharIndex(char c);
};

#endif

#include "ALLCD.h"
#include "fonts/azerbaijani.h"
#include "fonts/latin.h"
#include "fonts/cyrillic.h"

ALLCD::ALLCD(uint8_t lcd_addr, uint8_t cols, uint8_t rows)
    : lcd(lcd_addr, cols, rows) {}

void ALLCD::begin() {
    lcd.init();
    lcd.backlight();
}

void ALLCD::loadCustomChar(byte index, const byte data[8]) {
    lcd.createChar(index, data);
}

void ALLCD::loadFont(const String& lang) {
    if (lang == "azerbaijani") {
        loadCustomChar(0, CHAR_C_CEDILLA);
        loadCustomChar(1, CHAR_G_BREVE);
        loadCustomChar(2, CHAR_I_DOTLESS);
        loadCustomChar(3, CHAR_O_UMLAUT);
        loadCustomChar(4, CHAR_S_CEDILLA);
        loadCustomChar(5, CHAR_U_UMLAUT);
        // максимум 8!
    } else if (lang == "latin") {
        // загрузка латинских символов с диакритикой
    } else if (lang == "cyrillic") {
        // загрузка кириллических символов
    }
}

byte ALLCD::getCustomCharIndex(char c) {
    switch (c) {
        case 'ç': return 0;
        case 'ğ': return 1;
        case 'ı': return 2;
        case 'ö': return 3;
        case 'ş': return 4;
        case 'ü': return 5;
        default: return '?'; // unknown char
    }
}

void ALLCD::printUnicode(const String& text) {
    for (char c : text) {
        if (c >= 0 && c < 128) {
            lcd.write(c);  // обычные ASCII
        } else {
            byte index = getCustomCharIndex(c);
            lcd.write(index);  // кастомные символы
        }
    }
}

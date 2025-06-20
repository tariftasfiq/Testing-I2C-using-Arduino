#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 or 0x3F depending on your module
LiquidCrystal_I2C lcd(0x27, 16, 2);  // (address, columns, rows)

void setup() {
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.setCursor(0, 0);             // Set cursor to column 0, row 0
  lcd.print("I2C LCD Working!");   // Print message
  lcd.setCursor(0, 1);             
  lcd.print("Hello, Arduino!");
}

void loop() {
  // Nothing to do here
}

#include <LiquidTWI2.h>


LiquidTWI2 lcd(0x20);

uint8_t fullscreen [8] = {
  0b00000, 
  0b01010, 
  0b00000, 
  0b00000,
  0b10001, 
  0b01110, 
  0b00000, 
  0b00000,
};

void setup() {
  lcd.begin(16, 2);
  lcd.clear();  

  had();
}

void loop() {

}

void had() {
  lcd.setCursor(0, 0); 
  
  for(int i = 0; i < 16; i++ ) {
    lcd.setCursor(i, 0);
    lcd.write((uint8_t)0);
    delay(500);
    lcd.clear();
  }

  lcd.setCursor(15, 1);
  lcd.write((uint8_t)0);
  delay(500);
  lcd.clear();
  
  for(int i = 0; i > 15; i--) {
    lcd.setCursor(i, 1);
    lcd.write((uint8_t)0);
    delay(500);
    lcd.clear();
  }
}
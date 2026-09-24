#include <Wire.h>
#include <LiquidTWI2.h>

LiquidTWI2 lcd(0x20);


const int button9 = 9;
const int button8 = 8;
int buttonState9 = 9;
int buttonState8 = 8;

int lastButtonState9 = LOW; 
int stavy = 0;

uint8_t fullscreen [8] = {
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111, 
  0b11111, 
};

void setup() {
  pinMode(button9, INPUT);
  pinMode(button8, INPUT);

  lcd.begin(16, 2);
  lcd.clear();  
  
  lcd.setCursor(0, 0);
  lcd.print("VYPNUTO");
}

void loop() {
  buttonState9 = digitalRead(button9);
  buttonState8 = digitalRead(button8);

  if (buttonState9 == HIGH && lastButtonState9 == LOW) {
    
    stavy++; 
    if (stavy > 3) {
      stavy = 0; 
    }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    
    switch (stavy) {
      case 0:
        lcd.print("VYPNUTO"); 
        break;
      case 1:
        lcd.print("HAD");     
        had();
        break; 
      case 2:
        lcd.print("KOSTKA");
        break; 
      case 3:
        lcd.print("RULETA");
        break; 
    }
    
    delay(50);
  }
  
  lastButtonState9 = buttonState9; 

}

void had() {
  lcd.setCursor(0, 0); 
  for(int i = 5; i < 16; i++ ) {
    lcd.setCursor(i, 0);
    lcd.write((uint8_t)0);
    delay(100);
    lcd.clear();
  }
  for(int i = 15; i >= 0; i--) {
    lcd.setCursor(i, 1);
    lcd.write((uint8_t)0);
    delay(100);
    lcd.clear();
  }
}

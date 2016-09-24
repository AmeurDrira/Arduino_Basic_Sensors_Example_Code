#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define buttonBleu 3
#define Bleu 7
int axeX;
int axeY;
void setup() {
 
  pinMode(Bleu, OUTPUT);
  
  pinMode(buttonBleu, INPUT_PULLUP);
  
  
  lcd.begin(16, 2);
  lcd.clear();

}

void loop() {
  axeX=analogRead(A1);
  axeY=analogRead(A0);

  lcd.setCursor(0, 0) ;
  lcd.print("Etatled ") ;
  lcd.setCursor(0, 1) ;
  lcd.print("X:") ;
  lcd.setCursor(7, 1) ;
  lcd.print("Y:") ;
  
  if (digitalRead(buttonBleu) == LOW)
  {
    lcd.setCursor(7, 0) ;
    lcd.print(" ON ") ;
    digitalWrite(Bleu, HIGH);
  }
  else
  {
    lcd.setCursor(7, 0) ;
    lcd.print(" OFF") ;
    digitalWrite(Bleu, LOW);
  }
    lcd.setCursor(2, 1) ;
    lcd.print(axeX) ;
    delay(500);
    lcd.setCursor(9, 1) ;
    lcd.print(axeY) ;
        delay(500);

   
    
  
}

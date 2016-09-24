#include <LiquidCrystal.h>
#define  tempC A0

float temp = 0.0;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  pinMode(tempC, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  temp = analogRead(tempC) ;
  float celsius = temp * 0.48;
  float fahrenheit = ((celsius * 9) / 5) + 32;

  lcd.setCursor(0, 0);
  lcd.print("T = ");
  lcd.setCursor(4, 0 );
  lcd.print(celsius);
  lcd.setCursor(10, 0 );
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("T = ");
  lcd.setCursor(6, 1 );
  lcd.print(fahrenheit);
  lcd.setCursor(10, 1);
  lcd.print("F");
  
  delay(2000);

}



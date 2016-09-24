#include <LiquidCrystal.h>
#define  tempC A0
#define BLEU 9
#define RED 10
#define YELLOW 8
#define buzzer 11



float temp = 0.0;
int celsius = 0;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  pinMode(tempC, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLEU, OUTPUT);
  pinMode(buzzer,OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  temp = analogRead(tempC) ;
  celsius = temp * 0.48;

  if (celsius > 15 && celsius < 25)
  {
    lcd.setCursor(0, 0);
    lcd.print("T = ");
    lcd.setCursor(4, 0 );
    lcd.print(celsius);
    lcd.setCursor(10, 0 );
    lcd.print("C");
    digitalWrite(YELLOW, HIGH);
    digitalWrite(BLEU, LOW);
    digitalWrite(RED, LOW);
     analogWrite(buzzer,0);

    lcd.setCursor(0, 1);
    lcd.print("Etat Normal");
  }
  if (celsius >= 25 && celsius < 30)
  {
    lcd.setCursor(0, 0);
    lcd.print("T = ");
    lcd.setCursor(4, 0 );
    lcd.print(celsius);
    lcd.setCursor(10, 0 );
    lcd.print("C");
     analogWrite(buzzer,0);
    digitalWrite(BLEU, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
    

    lcd.setCursor(0, 1);
    lcd.print("Allumer le Clim");
  }

  if (celsius >= 30 )
  {
    lcd.setCursor(0, 0);
    lcd.print("T = ");
    lcd.setCursor(4, 0 );
    lcd.print(celsius);
    lcd.setCursor(10, 0 );
    lcd.print("C");
     
    digitalWrite(RED, HIGH);
    digitalWrite(BLEU, LOW);
    digitalWrite(YELLOW, LOW);
    analogWrite(buzzer,200);

    lcd.setCursor(0, 1);
    lcd.print("Appelez Pompiers");
  }



}



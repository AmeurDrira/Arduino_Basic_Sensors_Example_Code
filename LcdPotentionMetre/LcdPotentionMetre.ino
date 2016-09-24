#include <LiquidCrystal.h>
#define lenght 16.0

double percent = 100.0;
unsigned char b;
unsigned int peace;

LiquidCrystal lcd(8, 9, 2, 3, 4, 5);

byte p1[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};
byte p2[8] = {
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000
};
byte p3[8] = {
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100
};

byte p4[8] = {
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110
};
byte p5[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
void setup()
{
  lcd.createChar(0, p1);
  lcd.createChar(0, p2);
  lcd.createChar(0, p3);
  lcd.createChar(0, p4);
  lcd.createChar(0, p5);

  lcd.begin(16, 2);

}

void loop()
{
  lcd.setCursor(0, 0);
  unsigned int value = analogRead(A0);
  percent = value / 1024.0 * 100.0;
  lcd.print(value);
  lcd.print(" - ");
  lcd.print(percent);
  lcd.print(" % ");
  lcd.setCursor(0, 1);
  double a = lenght / 100 * percent;
  if (a >= 1)
  {
    for (int i = 1; i < a; i++)
    {
      lcd.write((byte)4);
      b = i;
    }
    a = a - b;
  }
  peace = a * 5;
  switch (peace) {
    case 0:
      break;
    case 1:
      lcd.write((byte)0);
      break;
    case 2:
      lcd.write((byte)1);
      break;
    case 3:
      lcd.write((byte)2);
      break;
    case 4:
      lcd.write((byte)3);
      break;

  }
  for (int i = 0; i < lenght - b; i++)
  {
    lcd.print(" ");
  }
  ;
}

#include <LiquidCrystal.h>
#include <Keypad.h>
#define  RED 9
#define  YELLOW 10
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*', '0', '#'}};
byte rowPins[ROWS] = {A5, A4, A3, A2};
byte colPins[COLS] = {A1, A0, 8};
Keypad monclavier = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
char tabMaster [] = "1234";
char tabSlave [6];
byte i = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);

  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {




  char key = monclavier.getKey();
  if (key != NO_KEY)
  {
    if (key != '#' && i < 4)
    {
      tabSlave[i] = key;
      lcd.setCursor(i, 0);
      lcd.print(tabSlave[i]) ;
      i++;
    }
    if (key == '*')
    {
      clearData();


    }
    if (key == '#')
    {
      lcd.setCursor(0, 1);
      if (strcmp(tabSlave, tabMaster) == 0)
      {
        lcd.print("vrai");
        digitalWrite(RED, LOW);
        digitalWrite(YELLOW, HIGH);
        delay(3000);
        clearData();

      }
      else
        lcd.print("faux");
    }
  }
}

void clearData()
{
   digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);

  lcd.clear();
  while (i != 0)
  {
    tabSlave[i--] = 0;
  }

  return;
}

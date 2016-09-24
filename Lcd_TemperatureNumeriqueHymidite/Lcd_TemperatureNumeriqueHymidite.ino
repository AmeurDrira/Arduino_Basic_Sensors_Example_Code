#include <LiquidCrystal.h>
#include<DHT.h>
#define  DHTPIN 12
#define DHTTYPE DHT11
#define Water A1
#define LDR A0
#define buzzer 9
#define relay 8
#define Led1 10
#define Led2 11
#define LedWater 13

DHT dht(DHTPIN, DHTTYPE);

int temp = 0;
int hymd = 0;
float ldr = 0;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  pinMode(buzzer, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(LedWater, OUTPUT);
  pinMode(Water, INPUT);
  lcd.begin(16, 2);
  dht.begin();
  lcd.clear();
}

void loop() {

  ldr = analogRead(LDR);
  temp = dht.readTemperature() ;
  hymd = dht.readHumidity();

  allumer_Led(ldr);
  alert_buzzer(hymd);
  allumer_relay( temp);
  niveau_eau();


  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.setCursor(2, 0 );
  lcd.print(temp);
  lcd.setCursor(4, 0 );
  lcd.print(" ");
  lcd.setCursor(5, 0 );
  lcd.print("H:");
  lcd.setCursor(7, 0);
  lcd.print(hymd);
  lcd.setCursor(9, 0);
  lcd.print(" ");
  lcd.setCursor(10, 0);
  lcd.print("L:");
  lcd.setCursor(12, 0);
  lcd.print((int)ldr);

}
void allumer_Led(float ldr)
{
  if (ldr > 200)
  {
    digitalWrite(Led1, HIGH);
    digitalWrite(Led2, HIGH);
    lcd.setCursor(9, 1);
    lcd.print("Nuit");
  }
  else
  {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, LOW);
    lcd.setCursor(9, 1);
    lcd.print("Jour");
  }
}
void alert_buzzer(int hymd)
{
  if (hymd > 80)
  {
    analogWrite(buzzer, 255);
  }
  else
  {
    analogWrite(buzzer, 0);
  }
}

void allumer_relay(int temp)
{
  if (temp > 29)
  {
    digitalWrite(relay, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Chaud");
  }

  else
  {
    digitalWrite(relay, LOW);
    lcd.setCursor(0, 1);
    lcd.print("froid");
  }
}
void niveau_eau()
{
  if (digitalRead(Water) == LOW)
  {
    digitalWrite(LedWater, HIGH);

  } else {
    digitalWrite(LedWater, LOW);
  }
}





#include <Servo.h>
#include<DHT.h>
#define DHTTYPE DHT11
#define DHTPIN A0
#define light A1
Servo myservo;
DHT dht(DHTPIN, DHTTYPE);
int inputPin = A2;
int pirState = LOW;
int val = 0;
float temp = 0;
float hymd = 0;
int led = 0;

void setup() {
  myservo.attach(3);
  pinMode(light, INPUT);
  pinMode(inputPin, INPUT_PULLUP);
  dht.begin();
  Serial.begin(9600);

}

void loop() {
  Serial.flush();
  campteurMouvement();
  while (Serial.available() > 0)
  {
    char data = Serial.read();
    if (data == 'l')
    {
      readLight();
    }

    if (data == 't')
    {
      readTemperature();
    }

    if (data == 'h')
    {
      readHumidity();
    }
    if (data == 'm')
    {
      commandeServo();
    }

  }
}

void readTemperature()
{
  temp = dht.readTemperature() ;
  Serial.print("Temperature : " );
  Serial.println(temp);
}
void readHumidity()
{
  hymd = dht.readHumidity();
  Serial.print("humidity : " );
  Serial.println(hymd);
}
void readLight()
{
  led = analogRead(light);

  if ( led < 200)
  {
    Serial.print("Mode Jour  " );
    Serial.println(analogRead(led) );
  }
  else
  {
    Serial.print("Mode Nuit  ");
    Serial.println(analogRead(led) );
  }

}
void commandeServo()
{

  myservo.write(0);
  delay(1000);
  myservo.write(180);


}
void campteurMouvement()
{
  val = digitalRead(inputPin);
  //if (val == HIGH) 
  //{
    Serial.print("Servo :   ");
    Serial.println(analogRead(val) );
    //commandeServo();
  //}
}



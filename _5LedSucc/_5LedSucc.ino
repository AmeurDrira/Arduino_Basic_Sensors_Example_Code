int m=50;
void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);


}

void loop() {

alumer(2);
alumer(3);
alumer(4);
alumer(5);
alumer(6);


}

void alumer(int pin)
{
 digitalWrite(pin,HIGH);
delay(m);
digitalWrite(pin,LOW); 
  }

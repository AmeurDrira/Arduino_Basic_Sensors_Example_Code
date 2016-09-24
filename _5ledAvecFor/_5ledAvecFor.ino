int m=250;
void setup() {
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);


}

void loop() {

for (int i=2; i<=6; i++){ 
  alumer(i);
}
  
for (int i=6; i >= 2; i--){ 
  alumer(i);
}

}

void alumer(int pin)
{
 digitalWrite(pin,HIGH);
delay(m);
digitalWrite(pin,LOW); 
  }


#define pin 13

void setup() {
pinMode(pin,OUTPUT);

}

void loop() {
digitalWrite(pin,HIGH);
delay(100);
digitalWrite(pin,LOW);
delay(100);
}

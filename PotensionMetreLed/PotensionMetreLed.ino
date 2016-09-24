int val=0;

void setup() {
pinMode(3,OUTPUT);
}

void loop() {

 val = analogRead(A0);
allumer(3,val/4);

}

void allumer(int pin,int i)
{
    analogWrite(pin,i);
}





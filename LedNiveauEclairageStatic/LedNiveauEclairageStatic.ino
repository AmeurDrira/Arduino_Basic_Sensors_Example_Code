int m=5;
void setup() {
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);


}

void loop() {

alumer(3);
alumer(5);
alumer(6);
alumer(10);
alumer(11);



}

void alumer(int pin)
{
  for (int i=0; i <= 255; i++){ 
      analogWrite(pin,i);
       delay(m);
      }
      
 

}





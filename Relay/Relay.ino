#define relay 2
#define ledR 3
#define button 4



void setup() {
  pinMode(button, INPUT);
  pinMode(ledR, OUTPUT);
  digitalWrite(ledR,HIGH);
    
  pinMode(relay, OUTPUT);

  
}

void loop() {
  
if(digitalRead(button)==HIGH)
{
  digitalWrite(relay,HIGH);
   
}else
digitalWrite(relay,LOW);
  



}




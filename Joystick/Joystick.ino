#define X A2
#define Y A1
#define button 2
#define ledh 10
#define ledb 11
#define ledg 12
#define ledd 13
int axeX ;
int axeY;



void setup() {
  pinMode(ledh,OUTPUT);
  pinMode(ledb,OUTPUT);
  pinMode(ledg,OUTPUT);
  pinMode(ledd,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  Serial.begin(9600);
 }

void loop() {
 axeX=analogRead(A2);
  axeY=analogRead(A1);
  

  if(digitalRead(button)==LOW)
  {
    digitalWrite(ledh,HIGH);
    digitalWrite(ledb,HIGH);
    digitalWrite(ledg,HIGH);
    digitalWrite(ledd,HIGH);
    
    }
    else 
    {
    digitalWrite(ledd,LOW);
    digitalWrite(ledh,LOW);
    digitalWrite(ledb,LOW);
    digitalWrite(ledg,LOW);
    }

    if(axeX>= 500 && axeY>=1000)
       digitalWrite(ledd,HIGH);      
      else
          digitalWrite(ledd,LOW);
          
    if(axeX<= 520 && axeY<=1)
       digitalWrite(ledg,HIGH);      
      else
          digitalWrite(ledg,LOW);
          
    if(axeX>=1000 && axeY<=550)
       digitalWrite(ledh,HIGH);      
      else
          digitalWrite(ledh,LOW);

     if(axeX<=1 && axeY<=550)
       digitalWrite(ledb,HIGH);      
      else
          digitalWrite(ledb,LOW);
    

}

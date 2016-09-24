#define buzzerA 5
#define buzzerB 3
#define ButtonA 2
#define ButtonB 4
#define ButtonC 7



void setup() {

  
  pinMode(buzzerA,OUTPUT);
  pinMode(buzzerB,OUTPUT);
  
  pinMode(ButtonA,INPUT_PULLUP);
   pinMode(ButtonB,INPUT_PULLUP);
    pinMode(ButtonC,INPUT_PULLUP);
 


}

void loop() {
  
   if(digitalRead(ButtonA)==LOW)
   {
    analogWrite(buzzerA,50);
    delay(1000);
    analogWrite(buzzerA,0);
    
    }
    if(digitalRead(ButtonB)==LOW)
   {
    analogWrite(buzzerA,100);
    delay(1000);
    analogWrite(buzzerA,0);
    
    }
    if(digitalRead(ButtonC)==LOW)
   {
    analogWrite(buzzerA,200);
    delay(1000);
    analogWrite(buzzerA,0);
    
    }
 

}




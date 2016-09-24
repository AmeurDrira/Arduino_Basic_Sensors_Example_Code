
int etatInter;
int etatInterrupteur1;
int randNumber;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  
  pinMode(7, OUTPUT);
  
   pinMode(3, INPUT_PULLUP); // Enable internal pull-up resistor on pin 5
   digitalWrite(3,HIGH);
   
    pinMode(2, INPUT_PULLUP); // Enable internal pull-up resistor on pin 5
   digitalWrite(2,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  etatInter = digitalRead(3);
  etatInterrupteur1 = digitalRead(2);
  
  if ( etatInterrupteur1 == LOW ) 
        {
                randNumber = random(0,4);
               digitalWrite(7,HIGH);               
               delay(randNumber*1000000);
               digitalWrite(7,LOW);
               
              digitalWrite(13,HIGH);
              delay(2000);
              digitalWrite(13,LOW);
              delay(10);
              
        } 

        if ( etatInter == LOW ) 
        {                   
              digitalWrite(13,HIGH);             
        } 
         if ( etatInter == HIGH ) 
        {                   
              digitalWrite(13,LOW);             
        } 
  

}

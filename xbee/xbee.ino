int etatInter;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(7, OUTPUT);
  
   pinMode(3, INPUT_PULLUP); // Enable internal pull-up resistor on pin 5
   digitalWrite(3,HIGH);
   

}

void loop() {
  // put your main code here, to run repeatedly:
  etatInter = digitalRead(3);
 

        if ( etatInter == LOW ) 
        {                   
              digitalWrite(7,HIGH);             
        } 
         if ( etatInter == HIGH ) 
        {                   
              digitalWrite(7,LOW);             
        } 
  

}

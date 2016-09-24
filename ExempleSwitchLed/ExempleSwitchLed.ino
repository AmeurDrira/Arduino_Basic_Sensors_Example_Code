
int etatInter;
void setup() {
pinMode(3,OUTPUT);

  pinMode(2, INPUT_PULLUP); 
   
}

void loop() {
  etatInter = digitalRead(2);

      
         if ( etatInter == HIGH ) 
        {                   
            digitalWrite(3,LOW);           
        } 
        else 
        {
        digitalWrite(3,HIGH); 
        }
}

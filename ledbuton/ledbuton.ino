
#define B 6
#define buttonR 2



void setup() {
  pinMode(buttonR,INPUT_PULLUP);
 
  pinMode(B,OUTPUT);


}

void loop() {
    
  if(digitalRead(buttonR)==HIGH)
  { 
    digitalWrite(B,HIGH);
 
  } 
  else
   { 
    digitalWrite(B,LOW);
   }

}




#define R 5
#define G 3
#define B 6
#define buttonR 2
#define buttonG 4
#define buttonB 7
#define Pot A0
int val;

void setup() {
  pinMode(buttonR,INPUT_PULLUP);
  
  pinMode(buttonG,INPUT_PULLUP);
  
  pinMode(buttonB,INPUT_PULLUP);
  
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);


}

void loop() {
    
  //troisbutton(); 
  val = analogRead(A0);
  allumer(3,val/4);

}



void allumer(int pin,int i)
{    
  analogWrite(R,i);
  analogWrite(G,i/2);
  analogWrite(B,i/3);
}

void troisbutton()
{
  
  if(digitalRead(buttonR)==LOW)
  {
  digitalWrite(R,HIGH);
  
  } 
 
  else
{
  digitalWrite(R,LOW);
  
  }
  
   if(digitalRead(buttonB)==LOW)
  { 
    digitalWrite(B,HIGH);
 
  } 
  else
   { 
    digitalWrite(B,LOW);
 
  } 
   if(digitalRead(buttonG)==LOW)
  {
    digitalWrite(G,HIGH);  
   } 
  else
  {
    digitalWrite(G,LOW);  
   } 
  }

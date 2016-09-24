#define ledOFF 13
#define ledON 12

#define inter 2
volatile boolean state=LOW;
void setup() {
  pinMode(ledON,OUTPUT);
    pinMode(ledOFF,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(inter),buttonChange,CHANGE);
}

void loop() {
  
  digitalWrite(ledON,state);
   digitalWrite(ledOFF,!state);



}
void buttonChange()
{
  state=!state;
  }

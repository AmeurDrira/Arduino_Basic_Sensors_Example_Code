
#define relay 2
#define button 3

volatile boolean state = LOW;

void setup() {
  
 
  attachInterrupt(digitalPinToInterrupt(button), buttonChange, CHANGE);
  pinMode(relay, OUTPUT);


}

void loop() {

  digitalWrite(relay, state);

}
void buttonChange()
{
  state = !state;
}



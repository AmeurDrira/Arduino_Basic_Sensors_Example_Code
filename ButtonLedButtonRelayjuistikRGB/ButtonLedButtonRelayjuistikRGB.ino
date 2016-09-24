#define LedYellew 3
#define ButtonLed 4
#define ButtonRelay 5
#define Relay 6
#define LedR 10
#define LedB 9
#define LedG 8
#define bts 2
volatile boolean state = LOW;


void setup() {
  pinMode(LedYellew, OUTPUT);
  pinMode(ButtonLed, INPUT);
  pinMode(ButtonRelay, INPUT);
  pinMode(Relay, OUTPUT);
  pinMode(LedR, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(LedG, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(bts), buttonChange, CHANGE);

}

void loop() {

  if (digitalRead(ButtonLed) == HIGH)
    digitalWrite(LedYellew, HIGH);
  else
    digitalWrite(LedYellew, LOW);

  if (digitalRead(ButtonRelay) == HIGH)
    digitalWrite(Relay, HIGH);
  else
    digitalWrite(Relay, LOW);

    digitalWrite(LedB, state);

}
void buttonChange()
{
  state = !state;
}



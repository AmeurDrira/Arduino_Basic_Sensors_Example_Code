#define LedR 2
#define LedJ 4
#define LedB 7
#define pile A0
float valeur = 0;




void setup() {


  pinMode(LedR, OUTPUT);
  pinMode(LedJ, OUTPUT);
  pinMode(LedB, OUTPUT);
  Serial.begin(9600);



}

void loop() {
  Serial.println(analogRead(pile));
  valeur = analogRead(pile) * 0.0048;

  Serial.println(valeur);

  if (valeur != 0)
  {
    if (valeur > 1.6)
    {
      digitalWrite(LedB, HIGH);
    }
    else
    {
      digitalWrite(LedB, LOW);
    }

    if (valeur > 1.4 && valeur < 1.6)
    {
      digitalWrite(LedJ, HIGH);
    }
    else
      digitalWrite(LedJ, LOW);

    if (valeur <= 1.4)
    {
      digitalWrite(LedR, HIGH);
    } else
    {
      digitalWrite(LedR, LOW);
    }
  }
  else
  {
    digitalWrite(LedR, LOW);
    digitalWrite(LedB, LOW);
    digitalWrite(LedJ, LOW);
  }


}




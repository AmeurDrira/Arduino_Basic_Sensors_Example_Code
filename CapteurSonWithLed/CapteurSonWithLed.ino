#define LED 2
#define CapteurSon A0

void setup()
{
  Serial.begin(9600);
  
   pinMode(LED, OUTPUT);
}

void loop()
{
  Serial.println(analogRead(CapteurSon));
  Serial.println("------------------");
  delay(500);
if(digitalRead(CapteurSon)== HIGH)
   {
   digitalWrite(LED, HIGH);
   
   }
else
   {
   digitalWrite(LED, LOW);
   }
}

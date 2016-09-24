//Connect the LED Grove module to Pin8, Digital 8
const int thresholdvalue = 10;       //The threshold for which the LED should turn on.
float Rsensor; //Resistance of sensor in K
void setup() {
  Serial.begin(9600);                //Start the Serial connection
  //Set the LED on Digital 8 as an OUTPUT
}
void loop() {
  int sensorValue = analogRead(A0);
   Serial.println("Valeur himidite : ");
  Serial.println(sensorValue);
  
  Serial.println("valeur ligth ");
  Serial.println(analogRead(A1));
  
  delay(1000);
}

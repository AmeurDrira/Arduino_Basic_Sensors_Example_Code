int humidite;
void setup() {

Serial.begin(9600);
 

}

void loop() {
 humidite=analogRead(A0);
 Serial.print("LA valeur est ");
 Serial.println(humidite);
 delay(2000);

}

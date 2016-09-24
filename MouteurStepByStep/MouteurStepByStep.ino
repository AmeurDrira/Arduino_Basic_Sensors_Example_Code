#include <Stepper.h>

const int stepsPerRevolution =200;  

Stepper myStepper= Stepper(stepsPerRevolution, 8, 2, 3, 4);

void setup() {
  
  myStepper.setSpeed(100);
 
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  //Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  //Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  //delay(500);
}

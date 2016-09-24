#include <SPI.h>
#include <Servo.h>
#include <RFID.h>
#include <Stepper.h>

#define buzzerA 5
#define LedVert 7
#define LedRouge 6
Servo myservo;
const int stepsPerRevolution = 200;
Stepper myStepper = Stepper(stepsPerRevolution, 8, 2, 3, 4);
RFID monModuleRFID(10, 9);

int UID[5] = {};
int MASTERKEY[5] = {153, 84, 196, 165, 172};
int stepCount = 0;
void setup()
{

  myservo.attach(3);
  Serial.begin(9600);
  SPI.begin();
  myStepper.setSpeed(100);
  monModuleRFID.init();
  pinMode(buzzerA, OUTPUT);
  pinMode(LedVert, OUTPUT);
  pinMode(LedRouge, OUTPUT);

}

void loop()
{


  if (monModuleRFID.isCard())
  {

    if (monModuleRFID.readCardSerial())
    {
      //Serial.print("L'UID est: ");
      for (int i = 0; i <= 4; i++)
      {
        UID[i] = monModuleRFID.serNum[i];
        // Serial.print(UID[i], DEC);
        //Serial.print(".");
      }

    }

    if (UID[0] == MASTERKEY[0]
        && UID[1] == MASTERKEY[1]
        && UID[2] == MASTERKEY[2]
        && UID[3] == MASTERKEY[3]
        && UID[4] == MASTERKEY[4])
    {
      Serial.print("Code ok");
      analogWrite(buzzerA, 200);
      digitalWrite(LedVert, HIGH);
      digitalWrite(LedRouge, LOW);
      //myStepper.step(stepsPerRevolution);
      //delay(500);
      //myStepper.step(-stepsPerRevolution);
      commandeServoGO();
    }
  }
  else
  {
    delay(3000);
    commandeServoBack();
    Serial.print("Code nnnn");
    analogWrite(buzzerA, 0);
    digitalWrite(LedVert, LOW);
    digitalWrite(LedRouge, HIGH);
  }
  monModuleRFID.halt();
  memset(UID, 0, sizeof(UID));

}
void commandeServoGO()
{
  myservo.write(180);
}
void commandeServoBack()
{
    myservo.write(0);
}


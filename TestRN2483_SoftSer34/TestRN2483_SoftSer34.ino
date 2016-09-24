// RN2483_temperature.ino - Simple LoRaWAN temperature sensor using Microchip RN2483 module
#include "SoftwareSerial.h"


SoftwareSerial lora(3, 4); // RX, TX



void sendCmd( char *cmd) {
  Serial.write( cmd );
  Serial.write("\n");
  lora.write(cmd);
  lora.write("\r\n");
  while (!lora.available() ) {
    delay(100);
  }
  while (lora.available())
    Serial.write(lora.read());
}

void waitForResponse() {
  while (!lora.available() ) {
    delay(100);
  }
  while (lora.available())
    Serial.write(lora.read());
}

char getHexHi( char ch ) {
  char nibble = ch >> 4;
  return (nibble > 9) ? nibble + 'A' - 10 : nibble + '0';
}
char getHexLo( char ch ) {
  char nibble = ch & 0x0f;
  return (nibble > 9) ? nibble + 'A' - 10 : nibble + '0';
}

void sendData( char *data) {
  Serial.write( "mac tx uncnf 1 " );
  lora.write( "mac tx uncnf 1 " );
  // Write data as hex characters
  char *ptr = data;
  int idiotCount = 50;
  while (*ptr && idiotCount ) {
    lora.write( getHexHi( *ptr ) );
    lora.write( getHexLo( *ptr ) );

    Serial.write( getHexHi( *ptr ) );
    Serial.write( getHexLo( *ptr ) );

    ptr++;
    idiotCount--;
  }
  lora.write("\r\n");
  Serial.write("\n");
  delay(5000);

  while (lora.available())
    Serial.write(lora.read());
}

void setup()
{
  Serial.begin(57600);
  lora.begin(57600);
  Serial.println("RN2483 Test");



//  waitForResponse();


  sendCmd("sys factoryRESET");
  sendCmd("sys get hweui");
  sendCmd("mac get deveui");

  // For TTN
  sendCmd("mac set devaddr 02BBCCDD");  // Set own address
  sendCmd("mac set appskey 1533B69B0EFDCD498391C6F9EA0A3515");
  sendCmd("mac set nwkskey 24E95ED1F9EC97AE082F0A21E90B73BA");
  sendCmd("mac set adr off");
  sendCmd("mac set rx2 4 869525000");
  sendCmd("mac join abp");
  sendCmd("mac get status");
  sendCmd("mac get devaddr");
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = 25.0;

 
  Serial.println(temperature);
  char msgBuf[40];
  sprintf(msgBuf, "{\"temp\":%d.%01d}", (int)temperature, (int)(temperature * 10) % 10);
  Serial.println(msgBuf);

  sendData(msgBuf);
  delay(5000);
  while (lora.available())
    Serial.write(lora.read());

  delay(30000);

}


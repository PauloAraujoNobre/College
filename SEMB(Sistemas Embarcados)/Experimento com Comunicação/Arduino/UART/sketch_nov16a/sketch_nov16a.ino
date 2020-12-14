#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2);

void setup()
{
  Serial.begin(57600);
 
  Serial.println("Entrada");

  mySerial.begin(38400);
  mySerial.println("Saida");
}

void loop()
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}

#include <SPI.h>

void setup (void)
{
  digitalWrite(SS, HIGH);  // ensure SS stays high for now
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop (void)
{
  char c;
  
  digitalWrite(SS, LOW);    // SS is pin 10

  for (const char * p = "Experimento SPI\n" ; c = *p; p++)
    SPI.transfer (c);

  digitalWrite(SS, HIGH);

  delay (1000);
}

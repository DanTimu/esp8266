#include <Arduino.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("\n");
  Serial.println("Welcome to Serial Input config.");
  // Serial.println("Please enter a value: ");
  Serial.println("Running Setup");
  Serial.print("LED_BUILTIN = ");
  Serial.println(LED_BUILTIN, DEC);
  Serial.print("LED_BUILTIN_AUX = ");
  Serial.println(LED_BUILTIN_AUX, DEC);
  Serial.print("Press a number(0-9): ");
  pinMode(D0, OUTPUT);
  pinMode(D4, OUTPUT);
  digitalWrite(D0, HIGH);
  digitalWrite(D4, HIGH);
}

char rx_byte = 0;

void loop()
{
  if (Serial.available() > 0)
  {                          // is a character available?
    rx_byte = Serial.read(); // get the character
    
    // check if a number was received
    if ((rx_byte >= '0') && (rx_byte <= '9'))
    {
      Serial.print("Number received: ");
      Serial.println(rx_byte);
      for(int i = 0; i < 5; i++){
        digitalWrite(D0, LOW);
        delay(50);
        digitalWrite(D0, HIGH);
        delay(50);
      }
    }
    else
    {
      Serial.println("Not a number.");
      for(int i = 0; i < 5; i++){
        digitalWrite(D4, LOW);
        delay(50);
        digitalWrite(D4, HIGH);
        delay(50);
      }
    }
  } // end: if (Serial.available() > 0)
}
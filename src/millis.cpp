#include <Arduino.h>

#define Task1 1000
#define Task2 5000

unsigned long millis_1 = 0;
unsigned long millis_2 = 0;

int led_state1 = 1;
int led_state2 = 1;

void displayTime(unsigned long);

void setup() 
{
    Serial.begin(115200);
    pinMode(LED_BUILTIN_AUX, OUTPUT); 
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN_AUX, HIGH); //D0
    digitalWrite(LED_BUILTIN, HIGH); //D4
}

void loop() 
{
    if(millis() > millis_1 + Task1)
    {
        millis_1 = millis();
        displayTime(millis_1);
        Serial.println("1");
        digitalWrite(LED_BUILTIN, led_state1);
        led_state1 = !led_state1;
    }
    if(millis() > millis_2 + Task2)
    {
        millis_2 = millis();
        displayTime(millis_2);
        Serial.println("2");
        digitalWrite(LED_BUILTIN_AUX, led_state2);
        led_state2 = !led_state2;
    }
}
void displayTime(unsigned long time_millis)
{
    Serial.print("Time: ");
    Serial.print(time_millis/1000);
    Serial.print("s - ");
}
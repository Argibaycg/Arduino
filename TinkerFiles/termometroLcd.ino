#include <LiquidCrystal.h>

#define TMPinput A0

long val;
LiquidCrystal myLCD(8, 9, 4, 5, 6, 7);

void setup()
{
    myLCD.begin(16, 1);
    myLCD.print("TEMPERATURA");
    Serial.begin(9600);
}

void loop()
{
    val = map(analogRead(TMPinput), 20, 358, -40, 125);
    myLCD.setCursor(13, 1);
    myLCD.print(val);
    myLCD.print("   ");
}
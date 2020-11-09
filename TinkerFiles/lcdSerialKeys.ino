#include <LiquidCrystal.h>

#define input A0

LiquidCrystal myLCD(8, 9, 4, 5, 6, 7);
char keyPress[16];

void setup()
{
    myLCD.begin(16, 2);
    myLCD.print("TECLA PRESIONADA");
    Serial.begin(9600);
}

void loop()
{
    Serial.print("Input:");
    Serial.println(analogRead(input));
    myLCD.setCursor(0, 2);
    keyPressed(analogRead(input));
    myLCD.print(keyPress);
}

char keyPressed(int input)
{
    switch (input)
    {
    case 0:
        strcpy(keyPress, "LEFT KEY        ");
        break;
    case 145:
        strcpy(keyPress, "RIGHT KEY       ");
        break;
    case 329:
        strcpy(keyPress, "UP KEY        ");
        break;
    case 505:
        strcpy(keyPress, "RESET           ");
        break;
    case 741:
        strcpy(keyPress, "DOWN KEY        ");
        break;
    default:
        strcpy(keyPress, "NO KEY          ");
        break;
    }
}
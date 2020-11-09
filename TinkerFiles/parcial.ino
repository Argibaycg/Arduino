#define analogPin A0
#define displayOne A3
#define displayTen A4
#define displayHundred A5
#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10

long output;
int hundred;
int ten;
int one;
int delayTime = 25;

void setup()
{
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(displayOne, OUTPUT);
    pinMode(displayTen, OUTPUT);
    pinMode(displayHundred, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    output = map(analogRead(analogPin), 0, 1023, 0, 100);
    Serial.print("Salida: ");
    Serial.println(output);

    hundred = output / 100;
    ten = (output - (hundred * 100)) / 10;
    one = output - (hundred * 100 + ten * 10);

    Serial.print("Centena: ");
    Serial.println(hundred);
    Serial.print("Decena: ");
    Serial.println(ten);
    Serial.print("Unidad: ");
    Serial.println(one);

    displayOff();

    displayHundredFunction();
    sevenDisplay(hundred);

    displayTenFunction();
    sevenDisplay(ten);

    displayOneFunction();
    sevenDisplay(one);
}

void displayHundredFunction()
{
    displayOff();
    digitalWrite(displayHundred, LOW);
    digitalWrite(displayTen, HIGH);
    digitalWrite(displayOne, HIGH);
}

void displayTenFunction()
{
    displayOff();
    digitalWrite(displayHundred, HIGH);
    digitalWrite(displayTen, LOW);
    digitalWrite(displayOne, HIGH);
}

void displayOneFunction()
{
    displayOff();
    digitalWrite(displayHundred, HIGH);
    digitalWrite(displayTen, HIGH);
    digitalWrite(displayOne, LOW);
}

void displayOff()
{
    delay(delayTime);
    digitalWrite(displayHundred, HIGH);
    digitalWrite(displayTen, HIGH);
    digitalWrite(displayOne, HIGH);
}

void sevenDisplay(int number)
{
    switch (number)
    {
    case 1:
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        break;
    case 2:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, LOW);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        break;
    case 3:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        break;
    case 4:
        digitalWrite(A, LOW);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 5:
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 6:
        digitalWrite(A, HIGH);
        digitalWrite(B, LOW);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 7:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        break;
    case 8:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 9:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, LOW);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 0:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, LOW);
        break;
    }
}
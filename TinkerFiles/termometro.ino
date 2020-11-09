
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

long val;
int hundred;
int ten;
int one;
int delayTime = 100;

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
    val = map(analogRead(analogPin), 20, 358, -40, 125);
    hundred = val / 100;
    ten = (val - (hundred * 100)) / 10;
    one = val - (hundred * 100 + ten * 10);

    displayOff();

    if (val >= 100)
    {
        displayHundredFunction();
        sevenDisplay(hundred);

        displayTenFunction();
        sevenDisplay(ten);

        displayOneFunction();
        sevenDisplay(one);
    }

    if (val >= 0 && val < 100)
    {
        displayOff();
        displayTenFunction();
        sevenDisplay(ten);
        displayOneFunction();
        sevenDisplay(one);
    }

    if (val < 0)
    {
        displayHundredFunction();
        sevenDisplay(-1);

        displayTenFunction();
        sevenDisplay(abs(ten));

        displayOneFunction();
        sevenDisplay(abs(one));
    }
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
    case -1:
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, HIGH);
        break;
    case 10:
        digitalWrite(A, LOW);
        digitalWrite(B, LOW);
        digitalWrite(C, LOW);
        digitalWrite(D, LOW);
        digitalWrite(E, LOW);
        digitalWrite(F, LOW);
        digitalWrite(G, LOW);
        break;
    }
}
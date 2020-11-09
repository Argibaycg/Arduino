const int A = 12;
const int B = 13;
const int C = 7;
const int D = 8;
const int E = 9;
const int F = 11;
const int G = 10;

const int increaseNumber = 4;
const int decreaseNumber = 3;
const int reset = 5;

int buffer = 0;
int buttonAdd;
int buttonAddState;
int buttonSubstract;
int buttonSubstractState;
int buttonReset;
int buttonResetState;

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
    default:
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

void setup()
{
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(increaseNumber, INPUT_PULLUP);
    pinMode(decreaseNumber, INPUT_PULLUP);
    pinMode(reset, INPUT_PULLUP);

    Serial.begin(9600);
}

int checkButtonStatus()
{

    buttonAdd = digitalRead(increaseNumber);
    buttonSubstract = digitalRead(decreaseNumber);
    buttonReset = digitalRead(reset);

    if (buttonAdd)
    {
        buttonAddState = 1;
    }
    if (buttonSubstract)
    {
        buttonSubstractState = 1;
    }
    if (reset)
    {
        buttonResetState = 1;
    }

    if (!buttonAdd && buttonAdd != buttonAddState)
    {
        buttonAddState = buttonAdd;
        return increaseNumber;
    }
    if (!buttonSubstract && buttonSubstract != buttonSubstractState)
    {
        buttonSubstractState = buttonSubstract;
        return decreaseNumber;
    }
    if (!buttonReset && buttonReset != buttonResetState)
    {
        buttonResetState = buttonReset;
        return reset;
    }

    return 0;
}

void loop()
{

    int button = checkButtonStatus();
    if (button == increaseNumber)
    {
        if (buffer >= 9)
        {
            buffer = 0;
        }
        else
        {
            buffer++;
        }
    }

    if (button == decreaseNumber)
    {
        if (buffer <= 0)
        {
            buffer = 9;
        }
        else
        {
            buffer--;
        }
    }

    if (button == reset)
    {
        buffer = 0;
    }
    sevenDisplay(buffer);
}

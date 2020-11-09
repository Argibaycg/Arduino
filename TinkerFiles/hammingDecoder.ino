#define bitOneInput A3
#define bitTwoInput A2
#define bitThreeInput A1
#define bitFourInput A0
#define patiryOneInput 2
#define parityTwoInput A5
#define parityThreeInput A4
#define d4 12
#define d3 11
#define d2 10
#define p3 9
#define d1 8
#define p2 7
#define p1 6
#define error1 3
#define error2 4
#define error3 5

int even = 1;

int bitOne;
int bitTwo;
int bitThree;
int bitFour;

int parity1;
int parity2;
int parity3;

int errorParity1;
int errorParity2;
int errorParity3;

void setup()
{
    pinMode(bitOneInput, INPUT_PULLUP);
    pinMode(bitTwoInput, INPUT_PULLUP);
    pinMode(bitThreeInput, INPUT_PULLUP);
    pinMode(bitFourInput, INPUT_PULLUP);
    pinMode(patiryOneInput, INPUT_PULLUP);
    pinMode(parityTwoInput, INPUT_PULLUP);
    pinMode(parityThreeInput, INPUT_PULLUP);
    pinMode(d4, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(p3, OUTPUT);
    pinMode(d1, OUTPUT);
    pinMode(p2, OUTPUT);
    pinMode(p1, OUTPUT);
    pinMode(error1, OUTPUT);
    pinMode(error2, OUTPUT);
    pinMode(error3, OUTPUT);
    Serial.begin(9600);
}

void loop()
{

    bitOne = !digitalRead(bitOneInput);
    bitTwo = !digitalRead(bitTwoInput);
    bitThree = !digitalRead(bitThreeInput);
    bitFour = !digitalRead(bitFourInput);

    parity1 = !digitalRead(patiryOneInput);
    parity2 = !digitalRead(parityTwoInput);
    parity3 = !digitalRead(parityThreeInput);

    bitOne ? digitalWrite(d1, HIGH) : digitalWrite(d1, LOW);
    bitTwo ? digitalWrite(d2, HIGH) : digitalWrite(d2, LOW);
    bitThree ? digitalWrite(d3, HIGH) : digitalWrite(d3, LOW);
    bitFour ? digitalWrite(d4, HIGH) : digitalWrite(d4, LOW);
    parity1 ? digitalWrite(p1, HIGH) : digitalWrite(p1, LOW);
    parity2 ? digitalWrite(p2, HIGH) : digitalWrite(p2, LOW);
    parity3 ? digitalWrite(p3, HIGH) : digitalWrite(p3, LOW);

    Serial.print("BIT 1: ");
    Serial.println(bitOne);
    Serial.print("BIT 2: ");
    Serial.println(bitTwo);
    Serial.print("BIT 3: ");
    Serial.println(bitThree);
    Serial.print("BIT 4: ");
    Serial.println(bitFour);

    Serial.print("PAR 1: ");
    Serial.println(parity1);
    Serial.print("PAR 2: ");
    Serial.println(parity2);
    Serial.print("PAR 3: ");
    Serial.println(parity3);

    errorParity1 = (parity1 + bitOne + bitTwo + bitFour) % 2;
    errorParity2 = (parity2 + bitOne + bitThree + bitFour) % 2;
    errorParity3 = (parity3 + bitTwo + bitThree + bitFour) % 2;

    Serial.print("ERROR 1: ");
    Serial.println(errorParity1);
    Serial.print("ERROR 2: ");
    Serial.println(errorParity2);
    Serial.print("ERROR 3: ");
    Serial.println(errorParity3);

    if (even)
    {
        errorParity1 ? digitalWrite(error1, HIGH) : digitalWrite(error1, LOW);
        errorParity2 ? digitalWrite(error2, HIGH) : digitalWrite(error2, LOW);
        errorParity3 ? digitalWrite(error3, HIGH) : digitalWrite(error3, LOW);
    }
    else
    {
        parity1 ? digitalWrite(p1, LOW) : digitalWrite(p1, HIGH);
        parity2 ? digitalWrite(p2, LOW) : digitalWrite(p2, HIGH);
        parity3 ? digitalWrite(p3, LOW) : digitalWrite(p3, HIGH);
    }
}
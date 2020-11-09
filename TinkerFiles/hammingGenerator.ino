
#define tipeOfParity A1
#define bitOneInput A5
#define bitTwoInput A4
#define bitThreeInput A3
#define bitFourInput A2
#define d4 12
#define d3 11
#define d2 10
#define p3 9
#define d1 8
#define p2 7
#define p1 6

int even;

int bitOne;
int bitTwo;
int bitThree;
int bitFour;

int parity1;
int parity2;
int parity3;

void setup()
{
    pinMode(tipeOfParity, INPUT_PULLUP);
    pinMode(bitOneInput, INPUT_PULLUP);
    pinMode(bitTwoInput, INPUT_PULLUP);
    pinMode(bitThreeInput, INPUT_PULLUP);
    pinMode(bitFourInput, INPUT_PULLUP);
    pinMode(d4, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(p3, OUTPUT);
    pinMode(d1, OUTPUT);
    pinMode(p2, OUTPUT);
    pinMode(p1, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    even = !digitalRead(tipeOfParity);

    bitOne = !digitalRead(bitOneInput);
    bitTwo = !digitalRead(bitTwoInput);
    bitThree = !digitalRead(bitThreeInput);
    bitFour = !digitalRead(bitFourInput);

    parity1 = (bitOne + bitTwo + bitFour) % 2;
    parity2 = (bitOne + bitThree + bitFour) % 2;
    parity3 = (bitTwo + bitThree + bitFour) % 2;

    bitOne ? digitalWrite(d1, HIGH) : digitalWrite(d1, LOW);
    bitTwo ? digitalWrite(d2, HIGH) : digitalWrite(d2, LOW);
    bitThree ? digitalWrite(d3, HIGH) : digitalWrite(d3, LOW);
    bitFour ? digitalWrite(d4, HIGH) : digitalWrite(d4, LOW);

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

    if (even)
    {
        parity1 ? digitalWrite(p1, HIGH) : digitalWrite(p1, LOW);
        parity2 ? digitalWrite(p2, HIGH) : digitalWrite(p2, LOW);
        parity3 ? digitalWrite(p3, HIGH) : digitalWrite(p3, LOW);
    }
    else
    {
        parity1 ? digitalWrite(p1, LOW) : digitalWrite(p1, HIGH);
        parity2 ? digitalWrite(p2, LOW) : digitalWrite(p2, HIGH);
        parity3 ? digitalWrite(p3, LOW) : digitalWrite(p3, HIGH);
    }
}
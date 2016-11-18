//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595 
int dataPin = 11;

byte leds = 0;  
int currentLED = 0;

void setup()  
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);

    leds = 0;
}

void loop()  
{
    leds = 0;

    if (currentLED == 7)
        currentLED = 0;
    else
        currentLED++;

    bitSet(leds, currentLED);

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, leds);
    digitalWrite(latchPin, HIGH);

    delay(250);
}

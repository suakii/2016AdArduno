#include "pitches.h"


int value;

const int pingPin = 7;


int melody[] = {
 NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_B3, 
 NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4,
 NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5,
};

void setup() 
{
        Serial.begin(9600);
        pinMode(7, OUTPUT); //Trigger  tx
  pinMode(6, INPUT);  //Echo     rx
}


void loop()
{

        long duration, inches, cm;

        digitalWrite(7, HIGH);
        delayMicroseconds(10);
        digitalWrite(7, LOW);
        cm =pulseIn(6,HIGH)/58;
        //받아진 펄스입력은 해당되는 값의 범위로 바꾸어줌.
        Serial.print(cm);
        Serial.print(" : ");
        cm = map(cm,0,100,0,22);
        Serial.println(cm);
        tone(9, melody[cm], 100);// pin, frequency, duration
               
        delay(10);
}



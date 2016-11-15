
#include <Servo.h>

Servo myservo;
int val;
void setup() {
   Serial.begin(9600);
   myservo.attach(2);
}
void loop() 
{
  delay(100);
  if(Serial.available()) {
    val = val*10 + (Serial.read() - '0');
  }

  myservo.write(val);
  delay(100);
  
}

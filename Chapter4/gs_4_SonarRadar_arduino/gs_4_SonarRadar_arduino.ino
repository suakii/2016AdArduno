
#include <Servo.h>

Servo servo;
int trigPin = 13;
int echoPin = 12;
int servoPin = 11;
int numReading = 10;
float total;
 


void setup() {
  Serial.begin(115200);
  pinMode(servoPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(servoPin);
}

void loop() {
  for (int rotation = 0; rotation < 90; rotation++) {
    if (rotation <= 45)
      servo.write(rotation);
    else
      servo.write(90-rotation);

    //sendData(rotation, getDistance());
    sendAverage(rotation);
  }
}
void sendAverage(int rotation) {
    for (int i = 0; i < numReading; i++) {
      total = total + getDistance();
    }
    int average = total/numReading;
    sendData(rotation, average);
    total = 0;
}
void sendData(int rotation, int dist) {
    Serial.print(rotation);
    Serial.print(",");
    Serial.print(dist);
    Serial.print('\n');
    delay(30);
}
int getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    //calculate the distacne (in cm) based on the speed of sound;
    int distance = (duration / 2 ) / 29.1;
    return distance;
}


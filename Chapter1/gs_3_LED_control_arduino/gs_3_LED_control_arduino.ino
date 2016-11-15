
const char HEADER = 'H';
const int TOTAL_BYTES = 6;

const char LED_TAG = 'L';

const int LED4 = 4;
const int LED5 = 5;
const int LED6 = 6;
const int LED7 = 7;

const int ON = 1;
const int OFF = 0;
 
const int LED4_pin = 4;
const int LED5_pin = 5;
const int LED6_pin = 6;
const int LED7_pin = 7;

int led_port = 0;
int button_state = 0;
int randNumber;

void setup() {
  Serial.begin(9600);
  pinMode(LED4_pin,OUTPUT);
  pinMode(LED5_pin,OUTPUT);
  pinMode(LED6_pin,OUTPUT);
  pinMode(LED7_pin,OUTPUT);

  digitalWrite(LED4_pin, HIGH);
  digitalWrite(LED5_pin, HIGH);
  digitalWrite(LED6_pin, HIGH);
  digitalWrite(LED7_pin, HIGH);
  delay(100);
  digitalWrite(LED4_pin, LOW);
  digitalWrite(LED5_pin, LOW);
  digitalWrite(LED6_pin, LOW);
  digitalWrite(LED7_pin, LOW);

    randomSeed(analogRead(0));
}

void loop() 
{
    randNumber = random(4, 8);
    digitalWrite(randNumber, HIGH);
    
    Serial.print(randNumber);
    Serial.print(",");
    Serial.print(1,DEC);
    Serial.print(",");
    Serial.println();
    delay(100);
    digitalWrite(randNumber, LOW);
    Serial.print(randNumber);
    Serial.print(",");
    Serial.print(0,DEC);
    Serial.print(",");
    Serial.println();
    delay(100);  
}

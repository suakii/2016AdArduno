
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
}

void loop() 
{
  if(Serial.available() >= TOTAL_BYTES)
  {
    if(Serial.read() == HEADER)
     {
       char tag = Serial.read();
       if(tag == LED_TAG)
       {
         int led = Serial.read();
         led = led + Serial.read();
         int button = Serial.read();
         button = button + Serial.read();
         if(led == LED4 && button == ON)
         {
           led_port = LED4_pin;
           button_state = HIGH;
         }
         else if(led == LED4 && button == OFF)
         {
           led_port = LED4_pin;
           button_state = LOW;
         }
         else if(led == LED5 && button == ON)
         {
           led_port = LED5_pin;
           button_state = HIGH;
         }
         else if(led == LED5 && button == OFF)
         {
           led_port = LED5_pin;
           button_state = LOW;
         }
         else if(led == LED6 && button == ON)
         {
           led_port = LED6_pin;
           button_state = HIGH;
         }
         else if(led == LED6 && button == OFF)
         {
           led_port = LED6_pin;
           button_state = LOW;
         }
         else if(led == LED7 && button == ON)
         {
           led_port = LED7_pin;
           button_state = HIGH;
         }
         else if(led == LED7 && button == OFF)
         {
           led_port = LED7_pin;
           button_state = LOW;
         }
         digitalWrite(led_port, button_state);
       } // (tag == LED_TAG)
     }
  }
  
  delay(100);
  
}


int first = 4;
int last  = 13; 
void setup() 
{
  for (int i = first; i <=last; i++)
    pinMode(i, OUTPUT); 
} 
  
void loop() 
{ 
       for (int i=first; i<=last; i++) {
                digitalWrite(i, HIGH); delay(del);             
                digitalWrite(i, LOW); delay(del);             
        }
 
        for (int i=last-1; i>=first+1; i--) {
                digitalWrite(i, HIGH);   
                delay(del);              
                digitalWrite(i, LOW);    
        }
} 

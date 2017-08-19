#include <Servo.h>

const int servoPin = 9;
const int redLedPin = 11;
const int greenLedPin = 12;
const int commandLedPin = 13;

Servo servo;

void setup() {
  Serial.begin(9600);  
  servo.attach(servoPin);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(commandLedPin, OUTPUT);
  testLeds();
  
  Serial.write("start");
}

void testLeds() {
  digitalWrite(redLedPin, HIGH);   
  digitalWrite(greenLedPin, HIGH);   
  digitalWrite(commandLedPin, HIGH); 
  delay(100);   
  digitalWrite(redLedPin, LOW);   
  digitalWrite(greenLedPin, LOW);   
  digitalWrite(commandLedPin, LOW); 
  delay(100); 
}

void loop() {  
   if (Serial.available() > 0) {
      byte bt = Serial.read();
      delay(2);
      
      if (bt == 0) {
        int angle = Serial.read();
        servo.write(angle); 
      } else {
        int state = Serial.read();
        
        if (state == 0 || state == 3)
          digitalWrite(greenLedPin, LOW);
        else
          digitalWrite(greenLedPin, HIGH);
        
        if (state == 0 || state == 2)
          digitalWrite(redLedPin, LOW);
        else
          digitalWrite(redLedPin, HIGH);
      }
      
      digitalWrite(commandLedPin, HIGH);   
      delay(100);             
      digitalWrite(commandLedPin, LOW); 
      delay(100); 
   } 
}

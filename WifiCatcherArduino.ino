#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600);  
  servo.attach(9);
  pinMode(13, OUTPUT);
    Serial.write("started");
}

void loop() {
   if (Serial.available() > 0) {
      int pos = Serial.read();
      delay(2);
      
      servo.write(pos);   
      pos = 10;
      Serial.write(pos);
      
      digitalWrite(13, HIGH);   
      delay(100);             
      digitalWrite(13, LOW); 
      delay(100); 
   } 
}

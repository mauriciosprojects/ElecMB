#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(10);
}

void loop() {
    myservo.write(50);
    delay(500);

    myservo.write(90);
    delay(500);
    
    myservo.write(90);
    delay(500);
}


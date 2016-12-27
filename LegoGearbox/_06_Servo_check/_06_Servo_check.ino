#include <Servo.h>
Servo servo;

#define SERVO_PIN 4

void setup() 
{
  servo.attach(SERVO_PIN);
}

void loop() 
{
    servo.write(0);
    delay(500);

    servo.write(40);
    delay(500);
    
    servo.write(80);
    delay(500);
    
    servo.write(120);
    delay(2000);
}


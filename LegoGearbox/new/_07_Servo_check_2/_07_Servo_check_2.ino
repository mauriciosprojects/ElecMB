//PROGRAM 7: SERVO CALIBRATION

//Setup: Connect Arduino digital pin 4 to servo motor control line
//First run program and open Serial Monitor
//Then manually shift gear shifter to third gear
//Then attach servo motor to gear shifter
//Input numerical values to determine servo positions for each gear

#include <Servo.h>
Servo shifter;

#define SHIFTER_SERVO_PIN 4

void setup() 
{
  Serial.begin(9600);
  Serial.println("Input gear shifter servo position and press <Enter>");
  shifter.attach(SHIFTER_SERVO_PIN);
}

int pos = 0;

void loop() 
{
  if (Serial.available() > 0) 
  {
    pos = Serial.parseInt();
    Serial.println(pos);
    shifter.write(pos);
  }
  
  delay(200);
}


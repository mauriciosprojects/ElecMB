//PROGRAM 7: SERVO POSITIONS FOR GEAR SHIFTER

//Setup:
// 1. Connect servo motor control line to Arduino digital pin 4
// 2. Do not attach servo motor to gear shifter yet
// Use:
// 3. Upload program and open Serial Monitor
// 4. Manually shift gear shifter to third gear
// 5. Attach servo motor to gear shifter
// 6. Input numerical valuess to determine servo positions for each gear
// Note: Re-run this program if servo motor is detached and reattached

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


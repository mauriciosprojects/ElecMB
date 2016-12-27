//PROGRAM 10: DC MOTOR CONTROL CHECK

//Setup:
// 1. Connect DC motor control line to Arduino digital pin 3
// 2. Connect battery pack to DC motor power rail on breadboard
// 3. Connect DC motor power plug to motor control output pins
// Use:
// 4. Upload program and open Serial Monitor
// 5. Input numerical values to set DC motor control voltage


#define MOTOR_CONTROL_PIN 3


void setup() 
{
  Serial.begin(9600);
  Serial.println("Input motor speed (0 to 255) and press <Enter>");
  pinMode(MOTOR_CONTROL_PIN, OUTPUT);
}


int motor_speed = 0;


void loop() 
{
  if (Serial.available() > 0) 
  {
    motor_speed = Serial.parseInt();
    Serial.println(motor_speed);
    analogWrite(MOTOR_CONTROL_PIN, motor_speed);
  }
  
  delay(200);
}


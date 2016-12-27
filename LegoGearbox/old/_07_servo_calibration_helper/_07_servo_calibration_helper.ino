#include <Servo.h>

Servo myservo;


//1st: 0
//2nd: 50
//3rd: 120

int x = 0;
int inByte;

void setup() 
{
  Serial.begin(9600);
  Serial.println("[H] [J] [K] [L]");
  Serial.println("-10 -5   +5 +10");
  Serial.println();
  
  myservo.attach(4);

  myservo.write(0);
  delay(100);
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    int inByte = Serial.read();

    if (inByte == 'H') x = x - 10;
    if (inByte == 'J') x = x - 5;
    if (inByte == 'K') x = x + 5;
    if (inByte == 'L') x = x + 10;

    Serial.print("x = ");
    Serial.println(x);
    myservo.write(x);
    delay(50);
  }
}


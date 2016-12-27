
int motorPin = 3;
int ledPin = 13;
 
void setup() 
{ 
  pinMode(ledPin,OUTPUT);
  pinMode(motorPin, OUTPUT);
} 
 
 
void loop() 
{ 
    int d = 2000;
    Set_Motor_Speed(100);
    delay(d);

    Set_Motor_Speed(50);
    delay(d);

    Set_Motor_Speed(100);
    delay(d);

    Set_Motor_Speed(150);
    delay(d);

    Set_Motor_Speed(200);
    delay(d);

    Set_Motor_Speed(250);
    delay(d);

    Set_Motor_Speed(200);
    delay(d);

    Set_Motor_Speed(150);
    delay(d);

    Set_Motor_Speed(100);
    delay(d);
}


void Set_Motor_Speed(int motorSpeed)
{
    digitalWrite(ledPin,HIGH); delay(100);
    digitalWrite(ledPin,LOW);
    analogWrite(motorPin, motorSpeed);
}


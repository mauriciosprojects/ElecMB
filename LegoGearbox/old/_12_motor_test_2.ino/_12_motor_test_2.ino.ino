
int motorPin = 3;
 
void setup() 
{ 
  //pinMode(13,OUTPUT);
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
} 
 
 
void loop() 
{ 
  //if (Serial.available())
  {
    int i;
    int speed;

    Serial.println(">>> SPEEDING UP >>>");
    for(speed = 50; speed <= 250; speed += 50)
    {
      analogWrite(motorPin, speed);
      Serial.println(speed);
      digitalWrite(13,HIGH);
      delay(250);
      digitalWrite(13,LOW);
      delay(5000);
    }

    Serial.println("<<< SLOWING DOWN <<<");
    for(speed = 200; speed >= 0; speed -= 50)
    {
      analogWrite(motorPin, speed);
      Serial.println(speed);
      digitalWrite(13,HIGH);
      delay(250);
      digitalWrite(13,LOW);
      delay(5000);
    }
  }
}



int motorPin = 3;
int ledPin = 4;
 
void setup() 
{ 
  pinMode(ledPin,OUTPUT);
  pinMode(motorPin, OUTPUT);
  //Serial.begin(9600);
  while (! Serial);
} 
 
 
void loop() 
{ 
  //if (Serial.available())
  {
    int i;
    int speed;

    //Serial.println("Motor speed up and speed down");

    digitalWrite(ledPin,HIGH); delay(250);
    digitalWrite(ledPin,LOW);
    //Serial.println(">> 100");
    analogWrite(motorPin, 100); delay(5000);

    digitalWrite(ledPin,HIGH); delay(250);
    digitalWrite(ledPin,LOW);
    //Serial.println(">> 150");
    analogWrite(motorPin, 150); delay(5000);

    digitalWrite(ledPin,HIGH); delay(250);
    digitalWrite(ledPin,LOW);
    //Serial.println(">> 200");
    analogWrite(motorPin, 200); delay(5000);

    digitalWrite(ledPin,HIGH); delay(250);
    digitalWrite(ledPin,LOW);
    //Serial.println(">> 250");
    analogWrite(motorPin, 250); delay(5000);

    digitalWrite(ledPin,HIGH); delay(250);
    digitalWrite(ledPin,LOW);
    //Serial.println("<< 200");
    analogWrite(motorPin, 200); delay(5000);

    digitalWrite(ledPin,HIGH); delay(250);
    digitalWrite(ledPin,LOW);
    //Serial.println("<< 150");
    analogWrite(motorPin, 150); delay(5000);
  }
}


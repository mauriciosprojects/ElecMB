#include <Servo.h>

Servo myservo;

//1st gear: 0
//2nd gear: 90
//3rd gear: 160


int gearpos1 = 0;
int gearpos2 = 50;
int gearpos3 = 120;


void setup() 
{
  myservo.attach(10);

  myservo.write(gearpos1);
  delay(2000);
}

void loop() 
{
    myservo.write(gearpos1);
    delay(3000);

    myservo.write(gearpos2);
    delay(3000);

    myservo.write(gearpos3);
    delay(3000);

    myservo.write(gearpos2);
    delay(3000);
}


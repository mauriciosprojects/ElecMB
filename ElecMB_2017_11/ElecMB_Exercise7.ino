
//========== Electronics MB Class Exercise 7 ==========

//Purpose: Demostration with 9g micro servo motor
//Date: November 4, 2017


#include <Servo.h>
Servo servo1;


//---------- Setup routine to run once ----------

void setup() 
{
    //Servo control pin connected to Arduino pin D7
    servo1.attach(7);
}


//---------- Loop routine that runs repeatedly ----------

void loop() 
{
    //Move to 90 degrees, 0 degrees and 180 degrees
    
    servo1.write(90);
    delay(3000);

    servo1.write(0);
    delay(1000);

    servo1.write(180);
    delay(1000);
}


//========== Electronics MB Class Exercise 5 ==========

//Purpose: Read photoresistor input and print to serial monitor
//Date: November 4, 2016


//---------- Setup routine to run once ----------

void setup()  
{ 
  //Serial communication with computer over USB
  Serial.begin(9600);
}


//---------- Loop routine that runs repeatedly ----------

void loop()  
{
  //Read analog input A1 from photoresistor
  int light = analogRead(A1);

  //Send light variable value to print on Serial Monitor
  Serial.println(light);
  delay(100);
}



//========== Electronics MB Class Exercise 1 ==========

//Purpose: LEDs blink in sequence
//Date: November 4, 2016


//--- Constant definitions ---
#define LED1 9
#define LED2 10
#define LED3 11
#define LED4 12


//---------- Setup routine to run once ----------

void setup()  
{ 
  //Set up pins to use
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
}


//--- Global variable ---
int counter = 1;


//---------- Loop routine that runs repeatedly ----------

void loop()  
{
  //Turn on one LED according to counter
  if(counter==1) digitalWrite(LED1,HIGH);
  if(counter==2) digitalWrite(LED2,HIGH);
  if(counter==3) digitalWrite(LED3,HIGH);
  if(counter==4) digitalWrite(LED4,HIGH);
  delay(200);

  //Increment counter variable
  counter = counter + 1;
  if(counter > 4) counter = 1;

  //Turn off all LEDs for an instant (no delay)
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
}


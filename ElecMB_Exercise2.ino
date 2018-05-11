
//========== Electronics MB Class Exercise 2 ==========

//Purpose: LEDs move according to one button input
//Date: November 4, 2017


//--- Constant definitions ---
#define LED1 12
#define LED2 11
#define LED3 10
#define LED4 9
#define BTN1 2
#define BTN2 3


//---------- Setup routine to run once ----------

void setup()  
{ 
  //Set up pins to use
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);
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

  //Check button 1 and change counter accordingly
  if(digitalRead(BTN1)==LOW)
  {
      //If button is pressed, decrement counter variable and wrap
      counter = counter - 1;
      if(counter < 1) counter = 4;
  }
  else
  {
      //Otherwise if not pressed, increment counter variable and wrap
      counter = counter + 1;
      if(counter > 4) counter = 1;
  }

  //Turn off all LEDs for an instant (no delay)
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
}


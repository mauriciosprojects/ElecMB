
//========== Electronics MB Class Exercise 4 ==========

//Purpose: LED moves according to one button input
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

  //Serial communication with computer over USB
  Serial.begin(9600);
  Serial.println("Hello");
  delay(1000);
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

  //Send counter variable value to print on Serial Monitor
  Serial.print(counter);
  Serial.print(" --- ");

  //Check button 1 and change counter accordingly
  Serial.print("Checking button... ");
  if(digitalRead(BTN1)==LOW)
  {
      //If button is pressed, decrement counter variable and wrap
      Serial.print("Going backwards... ");
      counter = counter - 1;
      if(counter < 1) 
      {
        Serial.print("Reset!");
        counter = 4;
      }
  }
  else
  {
      //Otherwise if not pressed, increment counter variable and wrap
      Serial.print("Going forward... ");
      counter = counter + 1;
      if(counter > 4) 
      {
        Serial.println("Reset!");
        counter = 1;
      }
  }

  //"print" statements up now all on same line, "println" ends line
  Serial.println();

  //Turn off all LEDs for an instant (no delay)
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
}


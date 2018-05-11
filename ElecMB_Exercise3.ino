
//========== Electronics MB Class Exercise 3 ==========

//Purpose: LED moves according to two button input
//Date: November 4, 2017


//--- Constant definitions ---
#define LED1 9
#define LED2 10
#define LED3 11
#define LED4 12
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
  Serial.begin(115200);
  Serial.println("Hello");
}


//--- Global variable ---
int position = 2;


//---------- Loop routine that runs repeatedly ----------

void loop()  
{
  //Check button 1
  if(digitalRead(BTN1)==LOW)
  {
    //If pressed, decrement counter variable and limit
    position = position - 1;
    if(position<1) position = 1;
  }

  //Check button 2
  if(digitalRead(BTN2)==LOW)
  {
    //If pressed, increment counter variable and limit
    position = position + 1;
    if(position>4) position = 4; 
  }

  //Turn on one LED according to counter variable
  if(position==1) digitalWrite(LED1,HIGH);
  if(position==2) digitalWrite(LED2,HIGH);
  if(position==3) digitalWrite(LED3,HIGH);
  if(position==4) digitalWrite(LED4,HIGH);
  delay(200);

  //Send position variable value to print on computer Serial Monitor
  Serial.println(position);

  //Turn off all LEDs for an instant (no delay)
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
}


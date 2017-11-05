
//========== Electronics MB Class Exercise 6 ==========

//Purpose: LEDs blink according to photoresistor input
//Date: November 4, 2016


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
  Serial.begin(9600);
  Serial.println("Yummy~");
}


//--- Global variables ---
int position = 2;
int light = 0;


//---------- Loop routine that runs repeatedly ----------

void loop()  
{
  //Check if value of light variable
  if(light > 700)
  {
    //Increment position variable
    position = position + 1;
    if(position>4) position = 1; 
  }

  //Turn on one LED according to position variable
  if(position==1) digitalWrite(LED1,HIGH);
  if(position==2) digitalWrite(LED2,HIGH);
  if(position==3) digitalWrite(LED3,HIGH);
  if(position==4) digitalWrite(LED4,HIGH);
  delay(100);

  //Read analog input A1 from photoresistor
  light = analogRead(A1);

  //Send position, light variable values to print on Serial Monitor
  Serial.print(position);
  Serial.print(" --- ");
  Serial.println(light);

  //Turn off all LEDs for an instant (no delay)
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
}


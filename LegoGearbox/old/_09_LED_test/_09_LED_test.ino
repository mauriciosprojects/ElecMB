
#define BTN1   12
#define BTN2   13
#define LED1   6
#define LED2   5
#define LED3   4
#define LEDRED 7

void setup() 
{
  Serial.begin(9600);
  Serial.println("Hello");

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LEDRED,OUTPUT);

  pinMode(BTN1,INPUT);
  pinMode(BTN2,INPUT);
}


void loop() 
{
  //Turn on one by one with delay
  int d = 500; //ms
  digitalWrite(LEDRED,HIGH); delay(d);
  digitalWrite(LED1,HIGH); delay(d);
  digitalWrite(LED2,HIGH); delay(d);
  digitalWrite(LED3,HIGH); delay(d);
  
  //All off
  digitalWrite(LEDRED,LOW);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  delay(d);
}


  
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

int LEDset = 1;

void loop() 
{
  int b1 = digitalRead(BTN1);
  int b2 = digitalRead(BTN2);

  Serial.print  (b1);
  Serial.print  (" ");
  Serial.println(b2);
  
  if (b1 == HIGH)
  {
    LEDset = 1;
  }

  if (b2 == HIGH)
  {
    LEDset = 2;
  }

  if (LEDset == 1)
  {
    digitalWrite(LEDRED,LOW);
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,HIGH);    
  }
  if (LEDset == 2)
  {
    digitalWrite(LEDRED,HIGH);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);    
  }

  delay(100);
}



#define LED1   A0
#define LED2   A1
#define LED3   A2
#define LEDRED A3
#define BTN1   11
#define BTN2   10
#define BTN3    9


void setup() 
{
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LEDRED,OUTPUT);
  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);
  pinMode(BTN3,INPUT_PULLUP);
}

int pos = 3;
int counter = 0;

void loop() 
{
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);

  if (pos == 1) digitalWrite(LED1,HIGH);
  if (pos == 2) digitalWrite(LED2,HIGH);
  if (pos == 3) digitalWrite(LED3,HIGH);

  //if (digitalRead(BTN1) == LOW) pos = pos + 1;
  //if (digitalRead(BTN3) == LOW) pos = pos - 1;

  if (digitalRead(BTN1) == LOW) pos = 1;
  if (digitalRead(BTN2) == LOW) pos = 2;
  if (digitalRead(BTN3) == LOW) pos = 3;

  if (pos > 3) pos = 1;
  if (pos < 1) pos = 3;

  if (counter < 10)
    digitalWrite(LEDRED,LOW);
  else
    digitalWrite(LEDRED,HIGH);

  counter++;
  if (counter > 20) counter = 0;
  delay(100);
}

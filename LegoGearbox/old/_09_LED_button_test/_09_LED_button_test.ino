//PROGRAM 4: BUTTON INPUT TO CONTROL LEDS

//Setup: Connect LEDs to Arduino digital pins A1, A2, A3, A4
//Run program and open Serial Monitor or Serial Plotter
//Drive gearbox with DC motor and shift gears
 
#define LED1   A1
#define LED2   A2
#define LED3   A3
#define LEDRED A4

#define BTN1   11
#define BTN2   10
#define BTN3   9


void setup() 
{
  Serial.begin(9600);

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LEDRED,OUTPUT);

  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);
  pinMode(BTN3,INPUT_PULLUP);
}

int LED_selected = 1;

void loop() 
{
  int b1 = digitalRead(BTN1);
  int b2 = digitalRead(BTN2);
  int b3 = digitalRead(BTN3);

  if (b1 == LOW) LED_selected = 1;
  if (b2 == LOW) LED_selected = 2;
  if (b3 == LOW) LED_selected = 3;

  if (LED_selected == 1)
  {
    digitalWrite(LED1,HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);    
    digitalWrite(LEDRED,LOW);
  }
  if (LED_selected == 2)
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);    
    digitalWrite(LEDRED,LOW);
  }
  if (LED_selected == 3)
  {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);    
    digitalWrite(LEDRED,LOW);
  }

  Serial.print(b1); Serial.print(" ");
  Serial.print(b2); Serial.print(" ");
  Serial.print(b3); Serial.print(" ");
  Serial.println();
  
  delay(200);
}


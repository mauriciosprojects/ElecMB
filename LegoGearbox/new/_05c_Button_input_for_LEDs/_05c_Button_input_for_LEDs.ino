//PROGRAM 4: BUTTON INPUT TO CONTROL LEDS

//Setup: Connect LEDs to Arduino digital pins A1, A2, A3, A4
//Connect buttons to Arduino digital pins 9, 10, 11
//Run program and open Serial Monitor
 
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
int LED_direction = +1;

void loop() 
{
  int b1 = digitalRead(BTN1);
  int b2 = digitalRead(BTN2);
  int b3 = digitalRead(BTN3);

  if (b1 == LOW) LED_direction = -1;
  if (b2 == LOW) LED_direction =  0;
  if (b3 == LOW) LED_direction = +1;

  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);    
  digitalWrite(LEDRED,LOW);
  
  if (LED_selected == 1) digitalWrite(LED1,HIGH);
  if (LED_selected == 2) digitalWrite(LED2,HIGH);
  if (LED_selected == 3) digitalWrite(LED3,HIGH);
  if (LED_selected == 4) digitalWrite(LEDRED,HIGH);

  LED_selected = LED_selected + LED_direction;
  if (LED_selected < 1) LED_selected = 4;
  if (LED_selected > 4) LED_selected = 1;
  
  Serial.print(LED_selected);
  Serial.print(" ");
  Serial.println(LED_direction);
  
  delay(200);
}


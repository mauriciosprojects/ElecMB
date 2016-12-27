//PROGRAM 4A: BUTTON INPUT TO CONTROL LEDS

// Setup: 
// 1. Connect LEDs to Arduino digital pins A1, A2, A3, A4
// 2. Connect buttons to Arduino digital pins 9, 10, 11
// Usage:
// 3. Upload program and open Serial Monitor
// 4. Press buttons and observe LEDs

 
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

  if (LED_selected == 1) digitalWrite(LED1,HIGH);
  if (LED_selected == 2) digitalWrite(LED2,HIGH);
  if (LED_selected == 3) digitalWrite(LED3,HIGH);

  Serial.println(LED_selected);
  
  delay(200);
}


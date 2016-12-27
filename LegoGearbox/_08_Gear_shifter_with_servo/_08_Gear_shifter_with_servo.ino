//PROGRAM 8: GEAR SHIFTER WITH SERVO

// Setup: 
// 1. Connect LEDs to Arduino digital pins A1, A2, A3, A4
// 2. Connect buttons to Arduino digital pins 9, 10, 11
// 3. Connect servo motor control line to Arduino digital pin 4
// 4. Set SHIFTER_GEAR_1,2,3 to values obtained with Program 7 
// Usage:
// 5. Upload program and open Serial Monitor
// 6. Turn DC motor on
// 7. Press buttons and confirm gear shifting

 
#define LED1   A1
#define LED2   A2
#define LED3   A3
#define LEDRED A4

#define BTN1   11
#define BTN2   10
#define BTN3   9


#define SHIFTER_SERVO_PIN 4


#include <Servo.h>
Servo shifter;
int shifter_pos = 3;

#define SHIFTER_GEAR_1 120
#define SHIFTER_GEAR_2 45
#define SHIFTER_GEAR_3 0


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
  
  shifter.attach(SHIFTER_SERVO_PIN);
}


int gear_selected = 1;


void loop() 
{
  int b1 = digitalRead(BTN1);
  int b2 = digitalRead(BTN2);
  int b3 = digitalRead(BTN3);

  if (b1 == LOW) gear_selected = 1;
  if (b2 == LOW) gear_selected = 2;
  if (b3 == LOW) gear_selected = 3;

  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);    
  digitalWrite(LEDRED,LOW);

  if (gear_selected == 1)
  {
    digitalWrite(LED1,HIGH);
    shifter.write(SHIFTER_GEAR_3);
  }
  if (gear_selected == 2)
  {
    digitalWrite(LED2,HIGH);
    shifter.write(SHIFTER_GEAR_2);
  }
  if (gear_selected == 3)
  {
    digitalWrite(LED3,HIGH);    
    shifter.write(SHIFTER_GEAR_1);
  }

  Serial.print("Gear selected: ");
  Serial.println(gear_selected);

  delay(200);
}


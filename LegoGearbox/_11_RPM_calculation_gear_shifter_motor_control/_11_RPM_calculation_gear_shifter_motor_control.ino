//PROGRAM 11: RPM CALCULATION, GEAR SHIFTER AND DC MOTOR CONTROL

// Setup: 
// 1. Connect LEDs to Arduino digital pins A1, A2, A3, A4
// 2. Connect buttons to Arduino digital pins 9, 10, 11
// 3. Connect servo motor control line to Arduino digital pin 4
// 4. Set SHIFTER_GEAR_1,2,3 to values obtained with Program 7 
// Usage:
// 5. Upload program and open Serial Plotter (or Serial Monitor)
// 6. Turn DC motor on
// 7. Confirm RPM calculation is working
// 8. Press buttons to shift gears
// 9. Observe gearbox output RPM with different gears

 
const int MAG_SENSOR_PIN = 2;
volatile int mag_counter;
volatile int mag_spin_time;
volatile long mag_prev_timer;

#define LED1   A1
#define LED2   A2
#define LED3   A3
#define LEDRED A4

#define BTN1   11
#define BTN2   10
#define BTN3   9

#define SHIFTER_SERVO_PIN 4

#define MOTOR_CONTROL_PIN 3


#include <Servo.h>
Servo shifter;
int shifter_pos = 3;

#define SHIFTER_GEAR_1 120
#define SHIFTER_GEAR_2 45
#define SHIFTER_GEAR_3 0


void setup() 
{
  Serial.begin(9600);

  pinMode(MAG_SENSOR_PIN, INPUT);
  mag_counter = 0;
  attachInterrupt(digitalPinToInterrupt(MAG_SENSOR_PIN), RPM_interrupt, FALLING);

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LEDRED,OUTPUT);

  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);
  pinMode(BTN3,INPUT_PULLUP);
  
  shifter.attach(SHIFTER_SERVO_PIN);

  pinMode(MOTOR_CONTROL_PIN, OUTPUT);
}


float rpm;
int gear_selected = 1;
int motor_speed = 0;

int counter = 0;


void loop() 
{
  RPM_calculation();
  Gear_shifter_processing();

  motor_speed = 255;
  if (counter > 100) motor_speed = 200;
  if (counter > 200) motor_speed = 150;
  if (counter > 300) motor_speed = 100;
  if (counter > 400) counter = 0;
    
  analogWrite(MOTOR_CONTROL_PIN, motor_speed);

  Serial.print("RPM: ");
  Serial.print(rpm);
  Serial.print(" 1000 2000 3000 ");

  Serial.print("Gear: ");
  Serial.print(gear_selected);
  Serial.print(" ");

  Serial.print("Motor: ");
  Serial.println(motor_speed);

  delay(50);
  counter++;
}


void RPM_interrupt() 
{
  long timer_now = millis();
  mag_spin_time = timer_now - mag_prev_timer;
  mag_counter++;

  mag_prev_timer = timer_now;
}


void RPM_calculation() 
{
  //Variables
  int n;
  int dt;
  long prev_timer;
  float rev_per_sec;
  
  //Part 1: Get data from interrupt function
  noInterrupts();
  n = mag_counter;
  dt = mag_spin_time;
  prev_timer = mag_prev_timer;
  interrupts();

  //Part 2: Set dt to zero if stopped more than 1 second
  long timer_now = millis();
  if ((timer_now - mag_prev_timer) > 1000) dt = 0;

  //Part 3: Calculate RPM revolutions per minute
  if ((dt > 0) && (dt <= 1000))
    rev_per_sec = 1000.0 / dt;
  else if (dt > 1000)
    rev_per_sec = 1.0;
  else
    rev_per_sec = 0.0;
  rpm = rev_per_sec * 60;
}


void Gear_shifter_processing() 
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
}


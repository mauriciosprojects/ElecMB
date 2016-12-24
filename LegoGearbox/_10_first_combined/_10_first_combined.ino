#include <Servo.h>
Servo myservo;


#define BTN1   12
#define BTN2   13
#define LED1   6
#define LED2   5
#define LED3   4
#define LEDRED 7


//1st gear: 0
//2nd gear: 90
//3rd gear: 160


int gearpos1 = 0;
int gearpos2 = 50;
int gearpos3 = 120;


const byte sensorPin = 2;
volatile int sensor_counter;
volatile long sensor_prev_t;
volatile int sensor_dt_sum;
volatile int dt;
volatile int avg_dt;

int stopped_count = 0;

void setup() 
{
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LEDRED,OUTPUT);

  pinMode(BTN1,INPUT);
  pinMode(BTN2,INPUT);

  myservo.attach(10);
  myservo.write(gearpos1);
  delay(100);

  sensor_counter = 0;
  sensor_prev_t = millis();
  sensor_dt_sum = 0;
  avg_dt = 0;
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), SensorInterrupt, FALLING);

  Serial.begin(9600);
}


int currentpos = gearpos1;
int currentgear = 1;


void loop() 
{
  int b1 = digitalRead(BTN1);
  int b2 = digitalRead(BTN2);

  if (b1 == HIGH) currentgear = currentgear - 1;
  if (b2 == HIGH) currentgear = currentgear + 1;
  if (currentgear < 1) currentgear = 1;
  if (currentgear > 3) currentgear = 3;

  if (currentgear == 1) currentpos = gearpos1;
  if (currentgear == 2) currentpos = gearpos2;
  if (currentgear == 3) currentpos = gearpos3;
  myservo.write(currentpos);

  noInterrupts();
  long local_sensor_prev_t = sensor_prev_t;
  int local_dt = dt;
  int local_avg_dt = avg_dt;
  interrupts();
  
  if ((millis() - local_sensor_prev_t) > 500)
  {
    local_dt = 0;
    local_avg_dt = 0;
  }

  float v;
  float avg_v;

  if ((local_dt > 0) && (local_dt < 1000))
    v = 1000.0 / local_dt;
  else
    v = 0;
  v = v * 60;

  if ((local_avg_dt > 0) && (local_avg_dt < 1000))
    avg_v = 1000.0 / local_avg_dt;
  else
    avg_v = 0;
  avg_v = avg_v * 60;

  if (avg_v > 0)
  { 
    digitalWrite(LEDRED,LOW);
    
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    if (avg_v > 1000) 
      digitalWrite(LED3,HIGH);
    else if (avg_v > 500) 
      digitalWrite(LED2,HIGH);
    else if (avg_v > 100) 
      digitalWrite(LED1,HIGH);
  }
  else
  {
    digitalWrite(LEDRED,HIGH);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
  }

  if (avg_v == 0)
    stopped_count++;
  else
    stopped_count = 0;

  if (stopped_count == 25) currentgear = 1;
    
  if (stopped_count < 25)
  {
    Serial.print(v);     Serial.print(" ");
    Serial.println(avg_v); //Serial.print(" ");
  }  
  
  delay(200);
}


void SensorInterrupt() 
{
  long t = millis();
  long dt0 = t - sensor_prev_t;

  if (dt0 > 10)
  {
    dt = dt0;
    sensor_counter++;
    sensor_dt_sum += dt;

    if(sensor_counter >= 8)
    {
      avg_dt = sensor_dt_sum >> 3;
      sensor_dt_sum = 0;
      sensor_counter = 0;
    }

    sensor_prev_t = t;
  }
}

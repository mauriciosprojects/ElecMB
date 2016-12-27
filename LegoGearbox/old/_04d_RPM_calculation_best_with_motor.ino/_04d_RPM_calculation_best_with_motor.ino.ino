#include <Servo.h>

Servo myservo;

const byte sensorPin = 2;
volatile long sensor_prev_t;
volatile long dt;

int motorPin = 3;

void setup()
{
  
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), SensorInterrupt, RISING);

  pinMode(motorPin, OUTPUT);
  analogWrite(motorPin, 70);

  myservo.attach(4);


  Serial.begin(9600);
  sensor_prev_t = millis();
}

int c = 0;
float v;
float avg_v;

void loop()
{
  noInterrupts();
  long local_sensor_prev_t = sensor_prev_t;
  int local_dt = dt;
  interrupts();

  if ((millis() - local_sensor_prev_t) > 1000)
    local_dt = 0;

  if (local_dt > 1000) local_dt = 1000;

  if ((local_dt > 0) && (local_dt <= 1000))
    v = 1000.0 / local_dt;
  else
    v = 0;

  //Serial.print("0 100 200 ");
  //Serial.println(local_dt);     Serial.print(" ");
  Serial.print("0 1000 2000 3000 ");
  Serial.println(v * 60);

  if (c < 200) analogWrite(motorPin, 75);
  //else if (c < 300) analogWrite(motorPin, 75);
  else if (c < 400) analogWrite(motorPin, 100);
  //else if (c < 500) analogWrite(motorPin, 125);
  else if (c < 600) analogWrite(motorPin, 150);
  //else if (c < 700) analogWrite(motorPin, 175);
  else if (c < 800) analogWrite(motorPin, 200);
  //else if (c < 900) analogWrite(motorPin, 225);
  else if (c < 1000) analogWrite(motorPin, 255);
  else if (c < 1200) c = 0;
  c++;

  myservo.write((v*60)/3000.0*180);
  delay(50);
}


void SensorTriggeredFn()
{
  long triggered_time = millis();
  int time_diff = triggered_time - previous_triggered_time;

  if (time_diff > 1)
  {
    REVOLUTION_TIME = time_diff;
    prev_triggered_time = triggered_time;
  }
}


void SensorTriggeredFn()
{
  long t = millis();
  int dt = t - prev_t;

  if (dt > 1)
  {
    REVOLUTION_TIME = dt;
    prev_t = t;
  }
}




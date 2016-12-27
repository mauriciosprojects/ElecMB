
const byte sensorPin = 2;
volatile int sensor_counter;
volatile long sensor_prev_t;
volatile int sensor_dt_sum;
volatile int dt;
volatile int avg_dt;

int motorPin = 3;

void setup()
{
  sensor_counter = 0;
  sensor_prev_t = millis();
  sensor_dt_sum = 0;
  avg_dt = 0;
  pinMode(sensorPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensorPin), SensorInterrupt, FALLING);

  pinMode(motorPin, OUTPUT);

  Serial.begin(9600);
}

int c = 0;
float v;
float avg_v;

void loop()
{
  noInterrupts();
  long local_sensor_prev_t = sensor_prev_t;
  int local_dt = dt;
  int local_avg_dt = avg_dt;
  interrupts();

  if ((millis() - local_sensor_prev_t) > 1000)
  {
    local_dt = 0;
    local_avg_dt = 0;
  }

  if ((local_dt > 0) && (local_dt < 1000))
    v = 1000.0 / local_dt;
  else
    v = 0;

  if ((local_avg_dt > 0) && (local_avg_dt < 1000))
    avg_v = 1000.0 / local_avg_dt;
  else
    avg_v = 0;

  //Serial.print(local_dt);     Serial.print(" ");
  Serial.println(v * 60);     Serial.print(" ");
  //Serial.print(local_avg_dt); Serial.print(" ");
  Serial.println(avg_v * 60); //Serial.print(" ");
  //Serial.print(millis()); Serial.print(" ");
  //Serial.println(local_sensor_prev_t);
  //Serial.println();

  if (c < 100) analogWrite(motorPin, 50);
  else if (c < 200) analogWrite(motorPin, 100);
  else if (c < 300) analogWrite(motorPin, 200);
  else if (c < 400) analogWrite(motorPin, 100);
  else if (c < 500) c = 0;
  c++;

  delay(500);
}


void SensorInterrupt()
{
  long t = millis();
  int dt0 = t - sensor_prev_t;

  if (dt0 > 10)
  {
    dt = dt0;
    sensor_counter++;
    sensor_dt_sum += dt;

    if (sensor_counter >= 16)
    {
      avg_dt = sensor_dt_sum >> 4;
      sensor_dt_sum = 0;
      sensor_counter = 0;
    }

    sensor_prev_t = t;
  }
  /*
    if (dt > 1000)
    {
    sensor_dt_sum = 0;
    sensor_counter = 0;
    dt = 0;
    avg_dt = 0.0;
    }*/
}



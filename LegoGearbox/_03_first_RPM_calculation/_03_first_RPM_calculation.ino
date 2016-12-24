const byte interruptPin = 2;
volatile byte state = LOW;


volatile int counter1;
volatile int counter2;
volatile int t;
volatile int prev_t;
volatile int dt;
volatile int cum_dt;
int avg_dt;

void setup() {
  counter1 = 0;
  counter2 = 0;
  prev_t = millis();
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), isr, FALLING);
  Serial.begin(9600);
}

float v;
float avg_v;
int loop_t;
int loop_prev_t;

void loop() {
  loop_t = millis();
  if ((loop_t - prev_t) > 1000)
  {
    dt = 0;
    avg_dt = 0;
  }
  
  //Serial.print(counter1);  Serial.print(" ");
  //Serial.print(counter2);  Serial.print(" ");
  //Serial.print(dt);        Serial.print(" ");
  //Serial.print(avg_dt);    Serial.print(" ");
  //Serial.println();
  if (dt > 0)
  {
    if (dt < 1000) v = 1000.0 / dt;
  }
  else
    v = 0;
    
  if (avg_dt > 0)
  {
    if (avg_dt < 1000) avg_v = 1000.0 / avg_dt;
  }
  else
    avg_v = 0;
    
  Serial.print(v*60);     Serial.print(" ");
  Serial.print(avg_v*60); Serial.print(" ");
  Serial.println();
  delay(100);
}

void isr() {
  t = millis();
  dt = t - prev_t;
  prev_t = t;

  counter1++;

  if(dt < 1000)
  {
    counter2++;
    cum_dt += dt;
  }
  else
  {
    cum_dt = 0;
    counter2 = 0;
  }

  if(counter2 >= 5)
  {
    avg_dt = cum_dt / 5;
    cum_dt = 0;
    counter2 = 0;
  }
}


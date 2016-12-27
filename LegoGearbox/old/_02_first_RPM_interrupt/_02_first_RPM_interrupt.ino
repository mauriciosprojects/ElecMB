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

void loop() {
  //noInterrupts();
  int local_counter1 = counter1;
  int local_counter2 = counter2;
  int local_dt = dt;
  int local_avg_dt = avg_dt;
  int local_cum_dt = cum_dt;
  //interrupts();
  Serial.print(local_counter1);  Serial.print(" ");
  Serial.print(local_counter2);  Serial.print(" ");
  Serial.print(local_dt);        Serial.print(" ");
  Serial.print(local_avg_dt);    Serial.print(" ");
  Serial.print("\n");
  delay(200);
  if(local_counter2 > 10)
  {
    local_avg_dt = local_cum_dt / 10;
    counter2 = 0;
  }
}

void isr() {
  counter1++;
  counter2++;

  t = millis();
  dt = t - prev_t;
  prev_t = t;
  cum_dt += dt;
}


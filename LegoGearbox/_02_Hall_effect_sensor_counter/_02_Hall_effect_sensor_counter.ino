//PROGRAM 2: HALL EFFECT MAGNETIC SENSOR COUNTER

// Setup:
// 1. Connect sensor output to Arduino digital pin 2
// Usage:
// 1. Upload program and open Serial Monitor or Serial Plotter
// 2. Spin gearbox output shaft manually or attach DC motor


const int MAG_SENSOR_PIN = 2;
volatile int counter;


void setup() 
{
  Serial.begin(9600);
  pinMode(MAG_SENSOR_PIN, INPUT);
  
  counter = 0;
  attachInterrupt(digitalPinToInterrupt(MAG_SENSOR_PIN), interrupt, FALLING);
}


void interrupt() 
{
  counter++;
}


void loop() 
{
  int n;
  noInterrupts();
  n = counter;
  interrupts();
  
  Serial.println(n);
  delay(200);
}


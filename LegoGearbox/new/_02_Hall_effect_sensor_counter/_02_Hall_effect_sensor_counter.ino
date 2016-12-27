//PROGRAM 2: HALL EFFECT MAGNETIC SENSOR COUNTER

//Setup: Connect sensor output to Arduino digital pin 2
//Run program and open Serial Monitor or Serial Plotter
//Move gearbox output shaft past sensor manually or attach DC motor

const int MAG_SENSOR_PIN = 2;
volatile int counter;

void setup() 
{
  Serial.begin(9600);
  pinMode(MAG_SENSOR_PIN, INPUT);
  
  counter = 0;
  attachInterrupt(digitalPinToInterrupt(MAG_SENSOR_PIN), interrupt, FALLING);
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

void interrupt() 
{
  counter++;
}


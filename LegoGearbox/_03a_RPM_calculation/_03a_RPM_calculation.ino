//PROGRAM 3B: RPM CALCULATION

// Setup:
// 1. Connect sensor output to Arduino digital pin 2
// Usage:
// 1. Upload program and open Serial Monitor or Serial Plotter
// 2. Run gearbox with DC motor
// 3. Shift gearbox and observe DT readings


const int MAG_SENSOR_PIN = 2;
volatile int mag_counter;
volatile int mag_spin_time;
volatile long mag_prev_timer;


void setup() 
{
  Serial.begin(9600);
  pinMode(MAG_SENSOR_PIN, INPUT);
  
  mag_counter = 0;
  attachInterrupt(digitalPinToInterrupt(MAG_SENSOR_PIN), interrupt, FALLING);
}


void interrupt() 
{
  long timer_now = millis();
  mag_spin_time = timer_now - mag_prev_timer;
  mag_counter++;

  mag_prev_timer = timer_now;
}


void loop() 
{
  //Variables
  int n;
  int dt;
  long prev_timer;
  
  //Part 1: Get data from interrupt function
  noInterrupts();
  n = mag_counter;
  dt = mag_spin_time;
  prev_timer = mag_prev_timer;
  interrupts();

  //Part 2: Print spin time value and also plot some gridlines
  Serial.print(dt);
  Serial.println(" 100 75 50 25");

  delay(200);
}


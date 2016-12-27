//PROGRAM 3: RPM CALCULATION

//Setup: Connect sensor output to Arduino digital pin 2
//Run program and open Serial Monitor or Serial Plotter
//Drive gearbox with DC motor and shift gears

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


void loop() 
{
  //Variables
  int n;
  int dt;
  long prev_timer;
  float rpm;
  
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
    rpm = 1000.0 / dt;
  else if (dt > 1000)
    rpm = 1.0;
  else
    rpm = 0.0;
  rpm = rpm * 60;
    
  //Part 3: Print RPM value and plot gridlines
  Serial.print(rpm);
  Serial.println(" 1000 2000 3000");

  delay(200);
}


void interrupt() 
{
  long timer_now = millis();
  mag_spin_time = timer_now - mag_prev_timer;
  mag_counter++;

  mag_prev_timer = timer_now;
}


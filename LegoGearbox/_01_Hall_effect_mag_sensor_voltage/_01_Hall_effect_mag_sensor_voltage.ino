//PROGRAM 1: READ HALL EFFECT MAGNETIC SENSOR VOLTAGE

// Setup:
// 1. Connect sensor output to Arduino analog input pin A0
// Usage:
// 1. Upload program and open Serial Monitor or Serial Plotter
// 2. Spin gearbox output shaft manually to move magnet past sensor


const int MAG_SENSOR_PIN = A0;


void setup() 
{
  Serial.begin(9600);
  pinMode(MAG_SENSOR_PIN, INPUT);
}


void loop() 
{
  float x;
  x = analogRead(MAG_SENSOR_PIN);
  x = (x / 1024.0) * 5.0; //convert to volts
  Serial.println(x);
  delay(200);
}


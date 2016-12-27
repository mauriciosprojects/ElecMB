//PROGRAM 1A: READ HALL EFFECT MAGNETIC SENSOR VOLTAGE

//Setup: Connect sensor output to Arduino analog input pin A0
//Run program and open Serial Monitor or Serial Plotter
//Move gearbox output shaft past sensor manually


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


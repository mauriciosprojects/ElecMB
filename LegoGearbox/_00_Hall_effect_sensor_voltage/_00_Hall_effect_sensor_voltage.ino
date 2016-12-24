const byte interruptPin = 2;


volatile int counter;

void setup() {
  pinMode(interruptPin, INPUT);
  pinMode(14, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(analogRead(14));
  Serial.print(" ");
  Serial.println(digitalRead(2));
  delay(200);
}


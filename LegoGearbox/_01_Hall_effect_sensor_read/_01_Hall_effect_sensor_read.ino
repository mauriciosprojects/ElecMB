const byte interruptPin = 2;
volatile byte state = LOW;


volatile int counter;

void setup() {
  counter = 0;
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), isr, FALLING);
  Serial.begin(9600);
}

void loop() {
  Serial.println(counter);
  delay(1000);
}

void isr() {
  counter++;
}

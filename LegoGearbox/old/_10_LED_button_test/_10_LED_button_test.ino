
void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);

  digitalWrite(15,HIGH);
  delay(2000);
  digitalWrite(15,LOW);
}

int pos = 0;

void loop() {
  int b1 = digitalRead(8);
  int b2 = digitalRead(9);
  Serial.print(b1);
  Serial.print(" ");
  Serial.print(b2);
  Serial.print(" ");
  Serial.println(pos);

  if(b1) pos = pos-1;
  if(b2) pos = pos+1;
  if(pos < 0) pos = 0;  
  if(pos > 2) pos = 2;  

  if(pos==0)
  {
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    digitalWrite(14,HIGH);
  }

  if(pos==1)
  {
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    digitalWrite(14,LOW);
  }

  if(pos==2)
  {
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(14,LOW);
  }

  delay(250);
}


int enableA = 9;
int Pin1 = 8;
int Pin2 = 10;
int enableB = 11;
int Pin3 = 12;
int Pin4 = 13;

void setup() {
  pinMode(enableA, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Move the DC motor forward
  analogWrite(enableA, 150);
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, LOW);
  
  analogWrite(enableB, 150);
  digitalWrite(Pin3, HIGH);
  digitalWrite(Pin4, LOW);
  
  delay(1000); 
  
  // Stop the motor
  analogWrite(enableA, 0);
  analogWrite(enableB, 0);
  
  delay(1000); 
  
  // Move the DC motor backward
  analogWrite(enableA, 150);
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, HIGH);
  
  analogWrite(enableB, 150);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, HIGH);
  
  delay(1000); 
  
  // Stop the motor
  analogWrite(enableA, 0);
  analogWrite(enableB, 0);
  
  delay(1000);
}

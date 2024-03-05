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
  analogWrite(enableA, 300);
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, LOW);
  
  analogWrite(enableB, 300);
  digitalWrite(Pin3, HIGH);
  digitalWrite(Pin4, LOW);
  
  delay(2000);

    // Turn the car right
  analogWrite(enableA, 140); // Adjust speed 
  digitalWrite(Pin1, HIGH);  // Set motor A direction 1
  digitalWrite(Pin2, LOW);   // Set motor A direction 2
  
  analogWrite(enableB, 140); // Adjust speed 
  digitalWrite(Pin3, LOW);   // Set motor B direction 1
  digitalWrite(Pin4, HIGH);  // Set motor B direction 2
  delay(2000);

  // Stop the motor
  analogWrite(enableA, 0);
  analogWrite(enableB, 0);
  
  delay(1000); 

    // Move the DC motor forward
  analogWrite(enableA, 300);
  digitalWrite(Pin1, HIGH);
  digitalWrite(Pin2, LOW);
  
  analogWrite(enableB, 300);
  digitalWrite(Pin3, HIGH);
  digitalWrite(Pin4, LOW);
  
  delay(2000);

      // Turn the car right
  analogWrite(enableA, 140); // Adjust speed 
  digitalWrite(Pin1, HIGH);  // Set motor A direction 1
  digitalWrite(Pin2, LOW);   // Set motor A direction 2
  
  analogWrite(enableB, 140); // Adjust speed 
  digitalWrite(Pin3, LOW);   // Set motor B direction 1
  digitalWrite(Pin4, HIGH);  // Set motor B direction 2
  delay(2000);

    // Stop the motor
  analogWrite(enableA, 0);
  analogWrite(enableB, 0);
  delay(1000);

}

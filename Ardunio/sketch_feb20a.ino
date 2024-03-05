int enableA = 9;
int Pin1 = 8;
int Pin2 = 10;
int enableB = 11;
int Pin3 = 12;
int Pin4 = 13;
int trigPin = 2; 
int echoPin = 3;
long duration;
int distance;

void setup() {
  pinMode(enableA, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  
  pinMode(trigPin, OUTPUT); // Set trig pin as output
  pinMode(echoPin, INPUT);  // Set echo pin as input

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
  
  delay(2000);

  // Check distance
  int dist = checkDistance();
  
  // If obstacle detected within 15cm, stop the car
  if (dist <= 20) {
    analogWrite(enableA, 0);
    analogWrite(enableB, 0);
    delay(1000); // Brief delay to stop the car completely
  }
}

int checkDistance() {
  // Trigger ultrasonic sensor to send out pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse received by the echo pin
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Print distance for debugging (optional)
  Serial.print("Distance: ");
  Serial.println(distance);
  
  return distance;
}

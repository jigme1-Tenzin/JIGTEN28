#define WATER_SENSOR_PIN A0
#define LED_PIN_2 2
#define LED_PIN_3 3
#define LED_PIN_4 4
#define BUZZER_PIN 5

void setup() {
  pinMode(WATER_SENSOR_PIN, INPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int waterLevel = analogRead(WATER_SENSOR_PIN);
  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  // Check if water level is above a certain threshold to ring the buzzer
  if (waterLevel > 700) {
    tone(BUZZER_PIN, 1000); // Turn on the buzzer with a frequency of 1000 Hz
    delay(5000); // Ring the buzzer for 1 second
    noTone(BUZZER_PIN); // Turn off the buzzer
  }

  // Check water level and change LED behavior accordingly
  if (waterLevel > 700) {
    // If water level is very high, turn on all LEDs
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, HIGH);
  } else if (waterLevel > 500) {
    // If water level is high, turn on LED_PIN_2, turn off LED_PIN_3 and LED_PIN_4
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, LOW);
  } else if (waterLevel > 300) {
    // If water level is medium, turn on LED_PIN_3, turn off LED_PIN_2 and LED_PIN_4
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(LED_PIN_4, LOW);
  } else {
    // If water level is low, turn on LED_PIN_4, turn off LED_PIN_2 and LED_PIN_3
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(LED_PIN_4, HIGH);
  }

  delay(500); // Delay between each reading
}

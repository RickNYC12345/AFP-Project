
// Define relay pin
const int relayPin = D0; // Replace YOUR_RELAY_PIN with the actual pin number for Relay 1

// Delay time in milliseconds (5 seconds)
const int DELAY_TIME = 5000;

// Variable to store received data and timer
int serialData;
unsigned long lastReceivedTime = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize relay pin as output
  pinMode(relayPin, OUTPUT);

  // Set initial relay state to HIGH
  digitalWrite(relayPin, HIGH);

  // Set initial last received time to current time
  lastReceivedTime = millis();
}

void loop() {
  // Check if serial data is available
  if (Serial.available() > 0) {
    serialData = Serial.read();

    // Update last received time if data is received
    lastReceivedTime = millis();

    // If received data is "1", keep the relay on
    if (serialData == '1') {
      digitalWrite(relayPin, HIGH);
    }
  } else {
    // Check if 5 seconds have passed since last data received
    if (millis() - lastReceivedTime >= DELAY_TIME) {
      // Turn off the relay after 5 seconds of no data
      digitalWrite(relayPin, LOW);
    }
  }
}

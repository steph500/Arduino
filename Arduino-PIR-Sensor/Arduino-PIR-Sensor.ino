// Define pins
const int pirPin = 9;    // PIR sensor output pin
const int ledPin = 13;   // LED pin (built-in LED on most Arduino boards)

// Variables
int pirState = LOW;      // Start with no motion detected
int val = 0;             // Variable to store PIR sensor status

void setup() {
  pinMode(pirPin, INPUT);   // Set PIR pin as input
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Start serial communication for debugging
}

void loop() {

  val = digitalRead(pirPin);  // Read PIR sensor value

  if (val == HIGH) {          // Motion detected
    digitalWrite(ledPin, HIGH);  // Turn LED on
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;        // Update state
    }
  } else {   
    digitalWrite(ledPin, LOW);   // Turn LED off
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;         // Update state
    }
  }
  delay(500);                 // Small delay to avoid overwhelming the serial port
}
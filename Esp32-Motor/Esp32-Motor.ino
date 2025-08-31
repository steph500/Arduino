un#include <ESP32Servo.h>

Servo myServo;  // Create a servo object

void setup() {
  Serial.begin(115200);
  myServo.attach(13);  // Attach servo to GPIO 13 (PWM-capable)
  Serial.println("Servo attached to GPIO 13");
}

void loop() {
  myServo.write(0);   // Move to 0 degrees
  Serial.println("Moving to 0 degrees");
  delay(1000);
  myServo.write(90);  // Move to 90 degrees
  Serial.println("Moving to 90 degrees");
  delay(1000);
  myServo.write(180); // Move to 180 degrees
  Serial.println("Moving to 180 degrees");
  delay(1000);
}
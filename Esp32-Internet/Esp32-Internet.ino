#include <WiFi.h>
#include <WebServer.h>

// Replace with your Wi-Fi credentials
const char* ssid = "Tsavo-A510";
const char* password = "SJuma@123";

// Initialize the web server on port 80
WebServer server(80);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define web server route
  server.on("/", []() {
    server.send(200, "text/plain", "Hello from ESP32!");
  });

  // Start the server
  server.begin();
  Serial.println("Web server started");
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}
#include <ESP8266WiFi.h>

const char* ssid = "Pijush_Wifi";
const char* password = "roni12345";
const int triggerPin = D5;
const int echoPin = D6;
WiFiClient client;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  long duration, distance;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (client.connect("192.168.0.107", 80)) {
    String postData = "distance=" + String(distance);
    client.println("POST /data HTTP/1.1");
    client.println("Host: 192.168.0.107");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println("Content-Length: " + String(postData.length()));
    client.println();
    client.print(postData);
    client.stop();
    Serial.println("Data sent");
  } else {
    Serial.println("Connection failed");
  }
  delay(500);
}

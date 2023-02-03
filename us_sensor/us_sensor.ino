#include <ESP8266WiFi.h>

const char* ssid = "Pijush_Wifi";
const char* password = "roni12345";
const int trigPin = D5;
const int echoPin = D6;
const int serverPort = 80;

WiFiServer server(serverPort);

long duration;
long distance;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected()) {
      long duration, distance;
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      // Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
    
      // Calculating the distance
      distance = duration * 0.034/2;
      client.println(distance);
      break;
    }
    client.stop();
  }
}

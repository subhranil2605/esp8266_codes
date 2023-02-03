#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN  "2I4HledezgtsKiatcpCIqOGV9Dn_BKRh"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Pijush_Wifi";
char pass[] = "roni12345";


BLYNK_WRITE(V0) {
  digitalWrite(D0, param.asInt());
}
BLYNK_WRITE(V1) {
  digitalWrite(D1, param.asInt());
}
BLYNK_WRITE(V2) {
  digitalWrite(D2, param.asInt());
}

void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}


void loop() {
  Blynk.run();
}

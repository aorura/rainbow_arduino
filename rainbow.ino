#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1);  // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  Serial.println("Good Morning.");

  BTSerial.begin(115200);
  BTSerial.println("Hello, World!");

  pinMode(13, OUTPUT);
}

void loop() {
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}

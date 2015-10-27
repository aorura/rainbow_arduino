#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1);  // RX, TX
byte cmd[2];
int CMD_SIZE = 2;
int RED_IO = 10, GREEN_IO = 11, BLUE_IO = 12, YELLOW_IO = 13, WHITE_IO = 14;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  Serial.println("Good Morning.");

  BTSerial.begin(115200);
  BTSerial.println("Hello, World!");

  pinMode(RED_IO, OUTPUT);
  pinMode(GREEN_IO, OUTPUT);
  pinMode(BLUE_IO, OUTPUT);
  pinMode(YELLOW_IO, OUTPUT);
  pinMode(WHITE_IO, OUTPUT);
}

void turnOffLeds()
{
  digitalWrite(RED_IO,LOW);
  digitalWrite(GREEN_IO, LOW);
  digitalWrite(BLUE_IO,LOW);
  digitalWrite(YELLOW_IO,LOW);
  digitalWrite(WHITE_IO, LOW);
}

void loop() {
  if (BTSerial.available()) {
    BTSerial.readBytes(cmd, CMD_SIZE);
    if (cmd[0] == 0x16) {
      turnOffLeds();
      if (cmd[1] & 0x01) { // Blue
          digitalWrite(BLUE_IO, HIGH);
      }
      if (cmd[1] & 0x02)  { // Green
          digitalWrite(GREEN_IO, HIGH);
      }
      if (cmd[1] & 0x04) {  // Red
          digitalWrite(RED_IO, HIGH);
      }
      if (cmd[1] & 0x08) { // Yellow
          digitalWrite(YELLOW_IO, HIGH);
      }
      if (cmd[1] & 0x10) {  // white
          digitalWrite(WHITE_IO, HIGH);
      } 
    }
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}

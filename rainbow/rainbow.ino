#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1);  // RX, TX
byte cmd[2];
int CMD_SIZE = 2;
int RED_IO = 9, GREEN_IO = 10, BLUE_IO = 11, YELLOW_IO = 12, WHITE_IO = 13;
int SECOND_DIGIT = 9, FIRST_DIGIT = 12, C_OR_F = 8;
int A = 11, B = 7, C = 4, D = 2, E = 1, F = 10, G = 5, DP = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  Serial.println("Good Morning.");

  BTSerial.begin(115200);
  BTSerial.println("Hello, World!");

//  pinMode(RED_IO, OUTPUT);
//  pinMode(GREEN_IO, OUTPUT);
//  pinMode(BLUE_IO, OUTPUT);
//  pinMode(YELLOW_IO, OUTPUT);
  pinMode(WHITE_IO, OUTPUT);

  // FND Setting
  pinMode(SECOND_DIGIT, OUTPUT);
  pinMode(FIRST_DIGIT, OUTPUT);
  pinMode(C_OR_F, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
}

void turnOffLeds()
{
//  digitalWrite(RED_IO,LOW);
//  digitalWrite(GREEN_IO, LOW);
//  digitalWrite(BLUE_IO,LOW);
//  digitalWrite(YELLOW_IO,LOW);
//  digitalWrite(WHITE_IO, LOW);
  delayMicroseconds(50);
}

void loop() {
  if (BTSerial.available()) {
    BTSerial.readBytes(cmd, CMD_SIZE);
    if (cmd[0] == 0x16) {
      turnOffLeds();
      // cmd[1] has a color of led.
      // cmd[1] has 8 bits. The order is ...WYRGB
/*      if (cmd[1] & 0x01) { // Blue
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
      }*/
      if (cmd[1] & 0x10) {  // white
          digitalWrite(WHITE_IO, HIGH);
      } 
    }
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}

void showTemp(int pos, char num)
{
  position(pos);
//  turn(num);
//  off();
}

//int SECOND_DIGIT = 9, FIRST_DIGIT = 12, C_OR_F = 8;
//int A = 11, B = 7, C = 4, D = 2, E = 1, F = 10, G = 5, DP = 3;
void position(int pos)
{
  if (pos == SECOND_DIGIT) {
    
  }
}


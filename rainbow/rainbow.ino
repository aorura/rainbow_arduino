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
  showNum(num);
  fndOff();
}

//int SECOND_DIGIT = 9, FIRST_DIGIT = 12, C_OR_F = 8;
//int A = 11, B = 7, C = 4, D = 2, E = 1, F = 10, G = 5, DP = 3;
void position(int pos)
{
  if (pos == SECOND_DIGIT) {
    digitalWrite(SECOND_DIGIT,  LOW);
    digitalWrite(FIRST_DIGIT, HIGH);
    digitalWrite(C_OR_F, HIGH);
  } else if (pos == FIRST_DIGIT) {
    digitalWrite(SECOND_DIGIT, HIGH);
    digitalWrite(FIRST_DIGIT, LOW);
    digitalWrite(C_OR_F, HIGH);
  } else if (pos ==  C_OR_F) {
    digitalWrite(SECOND_DIGIT, HIGH);
    digitalWrite(FIRST_DIGIT, HIGH);
    digitalWrite(C_OR_F, LOW);
  }
}

void fndOff()
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DP, LOW);
  delayMicroseconds(50);
}

void showNum(int num)
{
  if (num ==  0) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 1) {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 2) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 3) {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 4) {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 5) {
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 6) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 7) {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 8) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 9) {
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
    delay(1);
  }  else if (num == 10) {  // Celsius
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
    delay(1);
  }  else if (num == 11) {  // Fahrenheit
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(DP, HIGH);
    delay(1);
  }
}  


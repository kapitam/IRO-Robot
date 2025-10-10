void ServoOpen() {
  MotorStop();
  Servo(1, OpenL);
  Servo(2, OpenR);
}

void ServoClose() {
  MotorStop();
  Servo(1, CloseL);
  Servo(2, CloseR);
  delay(100);
}

void ServoCloseSmall() {
  MotorStop();
  Servo(1, CloseLSmall);
  Servo(2, CloseRSmall);
  delay(200);
}

void ServoUp() {
  MotorStop();
  Servo(0, Up);
}

void ServoUp45() {
  MotorStop();
  Servo(0, Up45);
}

void ServoDown() {
  MotorStop();
  Servo(0, Down);
  delay(150);
}





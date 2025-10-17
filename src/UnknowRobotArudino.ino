#include <UnknowStormXIGathering2.h>
void setup() {
  RobotSetup();
  // CalibrateSensor();  // >> Calibrate Robot Senso99r <<
  LightValue_FrontSensor(57, 57, 56, 56, 53, 56, 53, 58, 665, 733, 603, 694, 550, 590, 558, 718);
  LightValue_BackSensor(61, 57, 58, 55, 56, 56, 58, 57, 797, 733, 732, 621, 717, 629, 733, 677);
  LightValue_CenterSensor(53, 57, 54, 52, 55, 55, 573, 717, 653, 526, 665, 544);
  RefLineValue(300);        // ค่าในการจับเส้น เซนเซอร์หน้า หลัง
  RefCenterLineValue(300);  // ค่าในการจับเส้น เซนเซอร์คู่กลาง

  SetToCenterSpeed(40);      // ความเร็วเข้ากลางหุ่น
  SetTurnSpeed(35);          // ความเร็วเลี้ยวเข้าแยก
  SetRobotPID(0.014, 0.04);  // ค่า PID

  TurnSpeedLeft(25, 80, 50);
  TurnSpeedRight(80, 25, 50);

  BalanceMotorLeft = 0;
  BalanceMotorRight = 0;

  setOpen(125, 55);
  setClose(30, 150);
  setCloseSmall(73, 107); // left side less is close right side more is close
  setUpDowm(180, 80, 80);

  ////////////////////////////////////////////////////////////////////
  //////////////////////////////เช็คค่าเซนเซอร์/////a/////////////////////
  // SerialDistance();                // Serial Monitor เซนเซอร์วัดระยะ
  // Serial_FrontSensor();            // Serial Monitor เซนเซอร์หน้า
  // Serial_BackSensor();             // Serial Monitor เซนเซอร์หลัง
  // Serial_CenterSensor();           // Serial Monitor เซนเซอร์กลาง
  // SerialCalibrate_FrontSensor();   // Serial Monitor เซนเซอร์หน้า คาริเบทแล้ว
  // SerialCalibrate_BackSensor();    // Serial Monitor เซนเซอร์หลัง คาริเบทแล้ว
  // SerialCalibrate_CenterSensor();  // Serial Monitor เซนเซอร์กลาง คาริเบทแล้ว
  ////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////

  ServoOpen();
  ServoUp();

//Calibration

//spin('R',180);
OK();
Program3();
OK();
Program1();
OK();
Program2();


/*
OK();
  FF(30, 's');
  movement(0.04);
  spin('R', 90);
  movement(0.08);
  spin('L', 90);
  movement(0.10);
  release();
  spin('R', 180);
  movement(0.07);
  spin('R', 90);
  movement(0.08);
  spin('L',90);
  movement(0.05);

  //PUSHING1

*/

OK();
FF(30,'s');
  //circle
  delay(100);
  movement(0.05);
  spin('R', 45);
  movement(0.14);
  spin('L', 42);
  movement(0.45);
  spin('L', 90);
  movement(0.23);
  spin('L', 90);


  release();
  spin('R', 90);
  movement(-0.23);
  spin('R', 90);
  movement(-0.45);
  spin('R', 90);
  movement(-0.14);
  spin('L', 45);
  movement(-0.05);
  FFL(50, 'l');
  //circle




OK();
Program3();
//delay(700);
//Program3();
}

void loop() {
  while (1) {
    MotorStop();
    delay(100);
  }
}
//for small wave
void wavesmall() {
  FF(60,'p');
  go(25,0.32);
}

//for big wave, char is first turn
void wavebig(char direction) {
  if (direction == 'R') {
  FFL(60, 'l');
  FFR(60, 'R');
  FFL(60, 'l');
  } else if (direction == 'L') {
  FFR(60, 'r');
  FFL(60, 'L');
  FFR(60, 'r');
  } else {
    // do nothing 
  }
}

//for zigzag, char is first turn
void zigzag(char direction) {
  if (direction == 'R') {
  FFL(60, 'L');
  FFR(50, 'R');
  } else if (direction == 'L') {
  FFR(60, 'R');
  FFL(50, 'L');
  } else {
    // do nothing 
  }
}

// move on line for certain meters at certain speed, 60 for default
void go(double speed, double meters) {
  if (meters > 0) {
    FFtimer(speed, meters * 65600 / (speed));
  }
  else if (meters < 0) {
    BBtimer(speed, -meters * 65600 / (speed));
  }
  MotorStop();
}

// pick up object
void pickup() {
  movement(-0.01);
  ServoOpen();
  delay(300);
  ServoDown();
  delay(400);
  ServoClose();
  delay(400);
  ServoUp();
  delay(100);
}

void pick2() {
  ServoUp45();
  delay(200);
  ServoOpen();
  delay(400);
  movement(0.1);
  ServoClose();
  delay(400);
  ServoUp();
  movement(-0.1);
}
// release outer object
void releasefirst() {
  ServoDown();
  delay(200);
  ServoOpen();
  delay(100);
  movement(-0.03);
  ServoClose();
  delay(100);
  ServoUp();
  delay(100);
}

void release() {
  ServoDown();
  delay(100);
  ServoOpen();
  delay(100);
  ServoUp();
  delay(100);
  ServoClose();
  delay(100);
}

void pickupfirst() {
  ServoDown();
  delay(300);
  ServoOpen();
  movement(0.09);
  ServoCloseSmall();
  delay(300);
  ServoUp();
  delay(300);
}

// move forward/backward outside line for certain meters
void movement (double distance) {
  if (distance < 0) {
    Move(-15*k, -15*k, -distance * 6870);
    MotorStop();
    delay(50);
    return;
  }
  Move(15*k, 15*k, distance * 6870);
  MotorStop();
  delay(50);
}

//spin direction, degrees
void spin(char direction, double angle) {
  if (direction == 'R') {
  Move(30*k*21/20, -30*k*21/20, angle * 2.665);
  MotorStop();
  delay(50);
  } else if (direction == 'L') {
  Move(-30*k*21/20, 30*k*21/20, angle * 2.665);
  MotorStop();
  delay(50);
  } else {
    // do nothing 
  }
  MotorStop();
}

void S(char direction) {
  if (direction == 'L') {
  FFR(50, 'r');
  FFL(50, 'l');
  } else if (direction == 'R') {
  FFL(50, 'l'); 
  FFR(50, 'r');
  } else {
    // do nothing 
  }
}

void hook(char direction) {
  if (direction == 'L') {
  FFR(55, 'R');
  FFL(55, 'L');
  } else if (direction == 'R') {
  FFL(55, 'L'); 
  FFR(55, 'R');
  } else {
    // do nothing 
  }
}


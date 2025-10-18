#include <UnknowStormXIGathering2.h>
// forward-declare functions defined in other .ino files

void _R(int angle = 90);

float voltage() {
  float a = analogRead(A3);
  a = a / 1023.0 * 5.0;
  float m = 11.1/a;
  return m;
}

void setup() {
  float j = voltage();
  setk(0.895*20/21*1.0635);
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

  setOpen(105, 75);
  setClose(140, 45);
  setCloseSmall(73, 107); // left side less is close right side more is close
  setUpDowm(180, 130, 85);

  ////////////////////////////////////////////////////////////////////
  //////////////////////////////เช็คค่าเซนเซอร์//////////////////////////
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
  ServoClose();
  ServoUp();
  while (1) {
    // refresh sensor values used by OK_PUSH/START_PUSH
    ReadSensorRaw();

    if (OK_PUSH() == 0) { // pressed (returns 0 when pressed)
      delay(200); // debounce
      break;
    }

    if (START_PUSH() == 0) { // pressed
      delay(200); // debounce
      _R(180);
    }
  }



//CODE START HERE






  Program1();
OK() ;
Program1();
OK() ;
  Program1();


}










































void loop() {
  while (1) {
    MotorStop();
    delay(100);
  }
  
}






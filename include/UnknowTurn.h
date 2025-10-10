#define CFL 0
#define CCL 1
#define CBL 2

#define CFR 3
#define CCR 4
#define CBR 5

int tct, bct, tspd;
int LTurnSpdL, LTurnSpdR, TurnDelayL;
int RTurnSpdL, RTurnSpdR, TurnDelayR;
float PID_KP, PID_KD;

void SetRobotPID(float Kp, float Kd) {
  PID_KP = Kp;
  PID_KD = Kd;
}


void SetToCenterSpeed(int tctv) {
  tct = tctv;
  bct = tctv;
}

void SetTurnSpeed(int tspdv) {
  tspd = tspdv;
}

void TurnSpeedLeft(int l, int r, int de) {
  LTurnSpdL = l;
  LTurnSpdR = r;
  TurnDelayL = de;
}

void TurnSpeedRight(int l, int r, int de) {
  RTurnSpdL = l;
  RTurnSpdR = r;
  TurnDelayR = de;
}


void ToCenter() {
  Motor(tct, tct);
  delay(20);
  while (1) {
    Motor(tct, tct);
    ReadSensor();
    if (C[CFL] >= RefC || C[CFR] >= RefC) {
      Motor(-tct, -tct);
      delay(5);
      MotorStop();
      break;
    }
  }
}

void ToCenterC() {
  Motor(tct, tct);
  delay(20);
  while (1) {
    Motor(tct, tct);
    ReadSensor();
    if (C[CCL] >= RefC || C[CCR] >= RefC) {
      Motor(-tct, -tct);
      delay(5);
      MotorStop();
      break;
    }
  }
}

void ToCenterCB() {
  Motor(tct, tct);
  delay(20);
  while (1) {
    Motor(tct, tct);
    ReadSensor();
    if (C[CBL] >= RefC || C[CBR] >= RefC) {
      Motor(-tct, -tct);
      delay(5);
      MotorStop();
      break;
    }
  }
}

void ToCenterL() {
  Motor(tct, tct);
  delay(20);
  while (1) {
    Motor(tct, tct);
    ReadSensor();
    if (C[CFL] >= RefC) {
      Motor(-tct, -tct);
      delay(5);
      MotorStop();
      break;
    }
  }
}

void ToCenterCL() {
  Motor(tct - 5, tct - 5);
  delay(20);
  while (1) {
    Motor(tct - 5, tct - 5);
    ReadSensor();
    if (C[CCL] >= RefC) {
      Motor(-tct, -tct);
      delay(5);
      MotorStop();
      break;
    }
  }
}

void ToCenterR() {
  Motor(tct, tct);
  delay(20);
  while (1) {
    Motor(tct, tct);
    ReadSensor();
    if (C[CFR] >= RefC) {
      Motor(-tct, -tct);
      delay(5);
      MotorStop();
      break;
    }
  }
}
void ToCenterCR() {
  Motor(tct - 5, tct - 5);
  delay(20);
  while (1) {
    Motor(tct - 5, tct - 5);
    ReadSensor();
    if (C[CCR] >= RefC) {
      Motor(-tct, -tct);
      delay(5);
      MotorStop();
      break;
    }
  }
}

void BackCenter() {
  Motor(-bct, -bct);
  delay(20);
  while (1) {
    Motor(-bct, -bct);
    ReadSensor();
    if (C[CBL] >= RefC || C[CBR] >= RefC) {
      Motor(tct, tct);
      delay(10);
      MotorStop();
      break;
    }
  }
}

void BackCenterC() {
  Motor(-bct, -bct);
  delay(20);
  while (1) {
    Motor(-bct, -bct);
    ReadSensor();
    if (C[CCL] >= RefC || C[CCR] >= RefC) {
      Motor(tct, tct);
      delay(10);
      MotorStop();
      break;
    }
  }
}

void TurnLeft() {
  Motor(-LTurnSpdL, LTurnSpdR);
  delay(TurnDelayL);
  while (1) {
    Motor(-LTurnSpdL, LTurnSpdR);
    ReadCalibrateF();
    if (F[2] >= Ref) {
      MotorStop();
      break;
    }
  }
}

void TurnRight() {
  Motor(RTurnSpdL, -RTurnSpdR);
  delay(TurnDelayR);
  while (1) {
    Motor(RTurnSpdL, -RTurnSpdR);
    ReadCalibrateF();
    if (F[5] >= Ref) {
      MotorStop();
      break;
    }
  }
}

void SpinL() {
  MotorStop();
  delay(10);
  Motor(-tspd, tspd);
  delay(60);
  while (1) {
    ReadCalibrateF();
    Motor(-tspd, tspd);
    if (F[2] >= Ref) {
      Motor(tspd, -tspd);
      delay(5);
      MotorStop();
      break;
    }
  }
}

void SpinL2() {
  MotorStop();
  delay(10);
  Motor(-tspd, tspd);
  delay(20);
  while (1) {
    ReadCalibrateF();
    Motor(-tspd, tspd);
    if (F[2] >= Ref) {
      break;
    }
  }
  Motor(-tspd, tspd);
  delay(50);
  while (1) {
    ReadCalibrateF();
    Motor(-tspd, tspd);
    if (F[2] >= Ref) {
      Motor(tspd, -tspd);
      delay(5);
      MotorStop();
      break;
    }
  }
}

void SpinR() {
  MotorStop();
  delay(10);
  Motor(tspd, -tspd);
  delay(60);
  while (1) {
    ReadCalibrateF();
    Motor(tspd, -tspd);
    if (F[5] >= Ref) {
      Motor(-tspd, tspd);
      delay(5);
      MotorStop();
      break;
    }
  }
}

void SpinR2() {
  MotorStop();
  delay(10);
  Motor(tspd, -tspd);
  delay(20);
  while (1) {
    ReadCalibrateF();
    Motor(tspd, -tspd);
    if (F[5] >= Ref) {
      break;
    }
  }
  Motor(tspd, -tspd);
  delay(50);
  while (1) {
    ReadCalibrateF();
    Motor(tspd, -tspd);
    if (F[5] >= Ref) {
      Motor(-tspd, tspd);
      delay(5);
      MotorStop();
      break;
    }
  }
}

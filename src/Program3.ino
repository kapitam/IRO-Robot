void Program3() {
    FFR(50, 'R');
  //go(20, 0.04);
  pickupfirst();
  wavesmall();
  FFL(60, 'l');
  FFL(60, 'L');
  FF(60, 's');
  spin('L', 30);
  delay(100);
  movement(0.06);
  spin('R', 30);
  delay(100);
  movement(0.3);
  release();
}
void Program1() {
  // Move(30,0,500);
  // Move(0,30,500);
  // MotorStop();
  // FFL(60, 'l');
  // FF(60, 's');
  // Move(40, 20, 500);
  // SpinL();
  

  //FFR(55, 'R');
  //FFL(35, 'l');





  OK();

  FFL(50, 'l');
  FFR(35, 'R');
  FFL(60, 'L');
  

  S('L');

  FFL(50, 'l');
  FFL(60, 'l');

  hook('L');

  FFR(40, 'R');
  FFL(60, 'L');
  FFR(60, 'r');
  FFL(60, 'l');
  FFL(60, 'l');

  go(50,0.85);
  
}
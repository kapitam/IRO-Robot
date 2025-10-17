void Program2() {
    FFR(60,'r');
  FFL(60,'l');
  FFR(50,'p');
  FFR(50,'r');
  FFR(60,'r');




  //afterwave STRAIGHT hook
  FFL(60,'p');
  FFR(60, 'r');

  //hook to circle
  go(50, 0.32);
  FFR(10, 's');
  pickup();
  spin('R', 180);

  //circle RIGHT hook
  go(50, 0.45);
  FFL(50, 'R');

  //pick in hook
  go(10,-0.055);
  pick2();
  spin('R', 180);
  FFL(60,'p');


  //hook FORWARD afterwave
  FFR(60, 'r');
  FF(60,'p');

  //afterwave to pushing
  FFL(60, 'l');
  FFL(55, 'l');
  FFL(50, 'p');
  FFR(50, 'R');
  FFL(40, 'L');
  FF(30, 's');


  //PUSHING1
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
}


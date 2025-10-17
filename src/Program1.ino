void Program1() {
  FFL(50, 'L');
  go(10,0.10);
  pickup();
  spin('R',180);

  //
  FFR(40,'r');
  FFL(55, 'l');

  FFR(50,'R');
  go(40,0.29);
  pick2();
  spin('R',180);
  
  FFR(50, 'R');
  FFR(50, 'R');
  FFL(40, 'L');
  FF(30,'s');

  /*
  //PUSHING2
  movement(0.04);
  spin('R', 90);
  movement(0.08);
  spin('L', 90);
  movement(0.20);
  release();
  spin('R', 180);
  movement(0.17);
  spin('R', 90);
  movement(0.08);
  spin('L',90);
  movement(0.05);
  //PUSHING2
  */

  //PUSHING2v2
  movement(0.04);
  spin('R', 90);
  movement(0.08);
  spin('L', 90);
  movement(0.24);
  spin('L', 45);
  movement(0.10);
  release();

  movement(-0.10);
  spin('R', 45);
  movement(-0.24);
  spin('R', 90);
  movement(-0.06);
  spin('R', 90);
  //PUSHING2v2

  

  FFR(60,'r');
  FFL(50,'l');
  FFR(40,'R');
  go(30,0.43);
  pickup();
  spin('R',180);
  FFR(50,'R');

  //
  FFL(50,'l');
  FFR(50,'R');
  pick2();
  SpinR();
  FFL(50,'l');
  FFL(55,'L');


  //d6 to circle
  FFR(50,'r');
  FFR(60,'r');

  //afterwave STRAIGHT hook
  FFL(60,'p');
  FFR(60, 'r');

  //hook to circle
  go(50, 0.32);
  FFR(30, 's');

  //CIRCLE
  movement(0.05);
  spin('R', 45);
  movement(0.14);
  spin('L', 40);
  movement(0.40);
  spin('L', 90);
  movement(0.22);
  spin('L', 90);


  release();
  spin('L', 90);
  movement(0.1);
  spin('R', 90);
  movement(0.50);
  spin('R', 90);
  FFL(50, 'l');
  //CIRCLE

//cirlce to d2
  go(50, 0.45);
  FFL(60, 'l');

  //hook RIGHT afterwave
  FFR(60, 'r');
  FF(60,'r');

  //wavesmall RIGHT first intersection
  wavesmall();
  FFR(50,'R');
  FFL(40,'L');
  FFR(40,'R');
  FFR(60,'l');

  //
  zigzag('L');
  go(10,0.2);
  pickup();
  spin('R', 180);
  zigzag('L');
  FFL(50,'L');


  //after inter
  FFL(50, 'L');
  FFR(35, 'R');
  FFL(55, 'L');
  go(30, 0.45);
  FFL(60,'l');

  //afterwave to circle
  FFL(60,'p');
  FFR(60, 'r');

  //hook to circle
  go(50, 0.32);
  FFR(10, 's');

  //CIRCLE2


  //CIRCLE2

  //circle to
  go(50, 0.45);
  FFL(60, 'l');

  //hook RIGHT afterwave
  FFR(60, 'r');
  FF(60,'p');
  FFL(60,'l');
  FFL(50,'L');
  FFR(50, 'R');
  FFR(60, 'R');
  S('L');
  FFR(60,'s');
  movement(0.2);
}
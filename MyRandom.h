#ifndef MYRANDOM_H
#define MYRANDOM_H

#include "TRandom3.h"
#include "TFile.h"
#include "TH1.h"




class MyRandom : public TRandom3
{

 public:

  MyRandom();
  MyRandom(int seed);

  virtual ~MyRandom();
                  
  double Theta();						  //varia tra -pi/2 e pi/2;
  double Phi();                           //varia tra 0 e 2pi;


 private:


  int s;


  ClassDef(MyRandom,1)

};

#endif

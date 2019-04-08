
#include "TMath.h"
#include "TH1.h"
#include "TRandom3.h"
#include "MyRandom.h"



ClassImp(MyRandom)



MyRandom::MyRandom():TRandom3(0),
s(0)
{

}



MyRandom::MyRandom(int seed):TRandom3(seed),
  s(seed){
}



MyRandom::~MyRandom(){
}



//_____________________________________________________________________________
//_____________________________________________________________________________




double MyRandom::Theta(){
  return TMath::ACos(1-2*(this->Rndm()));
}

double MyRandom::Phi(){
  return 2*TMath::Pi()*(this->Rndm());
}





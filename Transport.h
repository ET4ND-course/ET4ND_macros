#ifndef TRANSPORT_H
#define TRANSPORT_H

#include "MyRandom.h"
#include "Riostream.h"
#include "TMath.h"
#include "Neutron.h"
#include "TH1F.h"

class Transport : public Neutron
{

public:
  Transport();
  Transport(TH1F *absC, TH1F *absH, TH1F *elC, TH1F *elH, Neutron n0);
  virtual ~Transport();

  float GetRadius(){return Rsphere;}
  void SetStartN(Neutron a){n0=a;}
  void SetThick(int thick){fthick=thick;}

  Neutron Interact();
  float IntSphere(Neutron n);
  void Check(){
    cout << n0.GetX() << " x del neutrone \t" << endl;
    fabsC->Draw();
  }

private:
  void Rotate(float &theta, float thetap, float phip);

  TH1F   *fabsC, *fabsH, *felC, *felH;
  Neutron n0;

  float fthick=10.;
  const float fwide=50.;						//half dimentions of the target block in cm
  const float  zsphere=5., Rsphere=1., fdensity=0.95;

ClassDef(Transport,1)

};

#endif

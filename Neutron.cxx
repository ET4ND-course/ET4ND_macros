
#include "TMath.h"
#include "TH1.h"
#include "MyRandom.h"
#include "Neutron.h"



ClassImp(MyRandom)



Neutron::Neutron(){
	fx=0.;
	fy=0.;
	fz=0.;
	ftheta=0.;
	fphi=0.;
	fenergy=1.;
}



Neutron::Neutron(float x,float y,float z,float theta, float phi, float energy)
{
	fx=x;
	fy=y;
	fz=z;
	ftheta=theta;
	fphi=phi;
	fenergy=energy;
}

Neutron::Neutron(Neutron &n)
{
	fx=n.GetX();
	fy=n.GetY();
	fz=n.GetZ();
	ftheta=n.GetTheta();
	fphi=n.GetPhi();
	fenergy=n.GetEnergy();
}


Neutron& Neutron::operator=(const Neutron& source)
{
  if(this != &source){
    fx = source.fx;
    fy = source.fy;
    fz = source.fz;
		fenergy = source.fenergy;
		fphi = source.fphi;
		ftheta = source.ftheta;
  }
  return *this;
}


Neutron::~Neutron(){
}



//_____________________________________________________________________________
//_____________________________________________________________________________

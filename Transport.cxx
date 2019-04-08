#include "Transport.h"
#include "TMath.h"
#include "TCanvas.h"


Transport::Transport():Neutron(),
  fabsC(0),
  fabsH(0),
  felC(0),
  felH(0){
}

Transport::Transport(TH1F *absC, TH1F *absH, TH1F *elC, TH1F *elH, Neutron n0):Neutron(n0),
  fabsC(absC),
  fabsH(absH),
  felC(elC),
  felH(elH){
}

Transport::~Transport(){
  delete fabsC;
  delete fabsH;
  delete felC;
  delete felH;
}



//_____________________________________________________________________________
//_____________________________________________________________________________


// ricordarsi di implementare in Neutron la massa del neutrone in Mev
Neutron Transport::Interact(){            //aggiungere TH1I &side - salvataggio dell'istogramma con i valori dei side
  bool debug=false;
  Neutron n=n0;
  if(debug)cout<< " 0000 Starting Neutron values:  energy=" << n.GetEnergy() << "   phi="<< n.GetPhi() << endl;
  const float PiH=TMath::Pi()/2.;
  float d=0.;
  float sigma=0., N=fdensity*6.022*0.1/28.;
  float sigmabsC, sigmabsH, sigmaelC, sigmaelH;
  float x,y,z, theta, phi, energy;
  float rndm, rndm1, rnnn;

  int side=0;       // 1  per uscito dalla parte giusta, 2 uscito dalle altre facce, 3 assorbito, 4 el with H, 5 el with C
  int count4=0, count5=0;
  int bin=0;

  while(side==0||side==4||side==5){
    
    energy=n.GetEnergy();
    bin=fabsC->FindBin(energy);
    sigmabsC=fabsC->GetBinContent(bin)*N*1./3.;
    bin=fabsH->FindBin(energy);
    sigmabsH=fabsH->GetBinContent(bin)*N*2./3.;
    bin=felH->FindBin(energy);
    sigmaelH=felH->GetBinContent(bin)*N*2./3.;
    bin=felC->FindBin(energy);
    sigmaelC=felC->GetBinContent(bin)*N*1./3.;

    sigma= sigmabsC+sigmaelC+sigmabsH+sigmaelH;
    rnnn=gRandom->Rndm();
    d=(-1./sigma)*TMath::Log(1-rnnn);
    theta=n.GetTheta();
    phi=n.GetPhi();
    if(debug)cout<< "\nNeutron values:  energy=" << energy << "   phi="<< phi << endl;
    x=n.GetX()+d*TMath::Sin(theta)*TMath::Cos(phi);
    y=n.GetY()+d*TMath::Sin(theta)*TMath::Sin(phi);
    z=n.GetZ()+d*TMath::Cos(theta);

    if(debug){
      cout<<"Sezioni d'urto:  "<< sigmabsC << " -- absC " << sigmabsH << " -- absH " << sigmaelC << " -- elC " << sigmabsH << " -- absH " <<endl;
      cout << d << " -- d      " << theta<<" -- theta      " << sigma << " -- sigma" << endl;
    }


    if(z<0.|| x>fwide || x< (-fwide) || y>fwide || y< (-fwide) )side=2;
    if(z>fthick)side=1;
    if(side==0||side==4||side==5){
      rndm=gRandom->Rndm();
      if(rndm<(sigmabsC+sigmabsH)/sigma*1.){side=3; break;}               //-----absorption
      else{
        n.SetX(x);
        n.SetY(y);
        n.SetZ(z);
        rndm1=gRandom->Rndm()*2.-1.;
        if(rndm<(sigmaelH+sigmabsC+sigmabsH)/sigma*1.){            //-----elastic with H
          side=4;
          n.SetEnergy(n.GetEnergy()*(2.+2.*rndm1)/4.);
          theta=(rndm1+1.)/TMath::Sqrt(2.+2.*rndm1);               //uses theta for cos(theta')
          count4++;
          }
        else {
          side=5;
          n.SetEnergy(n.GetEnergy()*(144.+24.*rndm1+1.)/169.);     //-----elastic with C, anisotropic
          theta=(12.*rndm1+1.)/TMath::Sqrt(144.+24.*rndm1+1.);     //uses theta for cos(theta')
          count5++;
          }
        theta=TMath::ACos(theta);
        Rotate(theta,n.GetTheta(),n.GetPhi());
        n.SetTheta(theta);
      }

    }

  } // chiude il while

  if(side==1&&debug){
      cout << "\n si hanno  " << count4 << " scattering H e "<< count5 <<" scattering C\n\n" << endl;
      //cout <<"    " << n.GetX() <<"    " << n. GetY() <<"    " << n. GetZ() << endl;
    }

  return n;
}


void Transport::Rotate(float &theta, float thetap, float phip){

    float phi=0.;
    float mr[3][3];
    float cdp[3];
    float cd[3];


    mr[0][0]=-TMath::Sin(phi);
    mr[1][0]=TMath::Cos(phi);
    mr[2][0]=0.;
    mr[0][1]=-TMath::Cos(phi)*TMath::Cos(theta);
    mr[1][1]=-TMath::Cos(theta)*TMath::Sin(phi);
    mr[2][1]=TMath::Sin(theta);
    mr[0][2]=TMath::Sin(theta)*TMath::Cos(phi);
    mr[1][2]=TMath::Sin(theta)*TMath::Sin(phi);
    mr[2][2]=TMath::Cos(theta);

    cdp[0]=TMath::Sin(thetap)*TMath::Cos(phip);
    cdp[1]=TMath::Sin(thetap)*TMath::Sin(phip);
    cdp[2]=TMath::Cos(thetap);

    for(int i=0;i<3;i++){
      cd[i]=0.;
      for(int j=0;j<3;j++){
        cd[i]+=mr[i][j]*cdp[j];
      }
    }
    theta=TMath::ACos(cd[2]);
    phi=TMath::ATan2(cd[1],cd[0]);
  }

  //-----------------------------------------------------
  //			Intersezione con la sfera
  //-----------------------------------------------------

  float Transport::IntSphere(Neutron n){

  	float a=1.,b,c,t1,t2;
    float x=n.GetX(), y=n.GetY(), z=n.GetZ();
    float theta=n.GetTheta(), phi=n.GetPhi();
  	float vx=TMath::Sin(theta)*TMath::Cos(phi), vy=TMath::Sin(theta)*TMath::Sin(phi), vz=TMath::Cos(theta);
    float shift=zsphere+fthick;

  	b=2*(vx*x+vy*y+vz*z-vz*shift);
  //  cout << "b=" << b <<endl;
  	c=x*x+y*y+z*z+shift*shift-1.-2*z*shift;
  //  cout << "c=" << c << endl;
    float delta=b*b-4.*a*c;
  //  cout << delta << " delta " << endl;
    if(delta>0){
  	    t1=(-1.*b+TMath::Sqrt(b*b-4.*a*c))/(2.*a);
  	    t2=(-1.*b-TMath::Sqrt(b*b-4.*a*c))/(2.*a);
        //cout << t1 << " 1° e "<<t2 << " 2° risultato eq" << endl;
        return t1>t2?(t1-t2):(t2-t1);
      }
      else {
        return -1.;
      }

  	}

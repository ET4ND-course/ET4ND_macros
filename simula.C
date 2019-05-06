
#if !defined(__CINT__) || defined(__MAKECINT__)
#include "TMath.h"
#include "TH1I.h"
#include "TH1F.h"
#include "Riostream.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TRandom3.h"
#include "TString.h"
#include "TMath.h"
#include <string>
#include <vector>
#include "Neutron.h"
#include "Transport.h"
//#include "Sigma.h"
#endif

using namespace std;

//////////////////////////////////////////////////////////
////                                                  ////
////   created by Luca Menzio and Oriol Sansplanell   ////
////    January 2019                                  ////
////                                                  ////
//////////////////////////////////////////////////////////

float beamsize=10.;     //area where the neutrons are generated

void GetStartingPoint(float &x,float &y){
  x=(gRandom->Rndm()-0.5)*beamsize;
  y=(gRandom->Rndm()-0.5)*beamsize;
  }

TH1F GetHist(TString filename){
  TFile F(filename+".root", "READ");
//  TH1F *h_Cabs=dynamic_cast<TH1F*>(f0->Get("C_absorption"));
  TH1F *hist = (TH1F*)F.Get(filename);
  hist->SetDirectory(0);
  //disteta->SetMinimum(0);
  return *hist;
  F.Close();

}

//double simula(int npart=1, float energy=1000000, float thick=10.){   // spessore in cm e energia in eV
double simula(Long64_t npart, float energy, float thick, vector<float> &vec_length){   // spessore in cm e energia in eV


  // 1, 10, 50 cm
  // 10, 100, 1000 keV
  bool verbose=false;
  //  const int seed=0;
  const int nbin=110, enmin=0, enmax=(int) (energy+energy*0.1);
  int count=0;
  float x=0.,y=0.,length=-2., totlength=0.;
  float fluence;

  delete gRandom;
  gRandom=new TRandom3(0);

  TString filename[4]={"CC","HC","CS","HS"};


  Neutron *n0=new Neutron(), nfin;
  n0->SetEnergy(energy);

  TFile *f0=new TFile(filename[0]+".root","READ");
  TFile *f1=new TFile(filename[1]+".root","READ");
  TFile *f2=new TFile(filename[2]+".root","READ");
  TFile *f3=new TFile(filename[3]+".root","READ");

  TH1F *h_Cabs=dynamic_cast<TH1F*>(f0->Get(filename[0]));
  TH1F *h_Habs=dynamic_cast<TH1F*>(f1->Get(filename[1]));
  TH1F *h_Cscatt=dynamic_cast<TH1F*>(f2->Get(filename[2]));
  TH1F *h_Hscatt=dynamic_cast<TH1F*>(f3->Get(filename[3]));

  auto *histen=new TH1I("histen","histen", nbin, enmin, enmax);

  Transport *trans=new Transport(h_Cabs,h_Habs,h_Cscatt,h_Hscatt, *n0);
  trans->SetThick(thick);
  const float radius=trans->GetRadius();
  const float volume=4./3.*TMath::Pi()*(radius)*(radius)*(radius);

 for(Long64_t i=0; i<npart; i++){
    GetStartingPoint(x,y);
    n0=new Neutron(x,y,0.,0.,0.,energy);     //implementare in neutron il creatore con x,y,z e direz fissa iniziale (lungo z)
    trans->SetStartN(*n0);
  //  if(verbose)trans->Check();
    nfin=trans->Interact();
    length=trans->IntSphere(nfin);
    if(length>0.) {
      vec_length.push_back(length);
      totlength+=length;
      count++;
      //histen->Fill(nfin.GetEnergy());
    }
  }
  fluence=totlength/volume/npart;

  // TString title="starting energy = "+std::to_string((int) energy/1000)+ " keV";
  // histen->SetTitle(title);
  // histen->GetYaxis()->SetTitle("Number of Neutrons");
  // histen->GetXaxis()->SetTitle("Energy (MeV)");
  // histen->Draw("hist");

  cout << "--------------------------------------------------------\n\t\t\t RISULTATI \n--------------------------------------------------------" << endl;
  cout << " Lunghezza tot  " << totlength << "\tcount= "<< count << endl;
  cout << " Fluenza  " << fluence << endl;

  return fluence;
}


void fakemain(){

  // ------------------------------------
  TH1D* hFluenza = new TH1D("hFluenza","hFluenza",20,0.008,0.009);
  TH1F* hLength  = new TH1F("hLength", "hLength", 50,0.,2.);
  
  
  for(int i=0; i<10; i++){

    vector<float> vec_length;
    vec_length.clear();

    hFluenza->Fill(simula(2000000, 10000, 1.,vec_length));
    for(UInt_t j=0; j<vec_length.size();j++){
      hLength->Fill(vec_length[j]);
    }
    
  }

  TFile* fOut = new TFile("f_200Mparticles_10KeV_1cm_prova.root", "recreate");
  fOut->cd();
  hFluenza->Write("hFluenza"); delete hFluenza;
  hLength->Write("hLength");   delete hLength;
  fOut->Close();
  delete fOut;
  // ------------------------------------



  


}

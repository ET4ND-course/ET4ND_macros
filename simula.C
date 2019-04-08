
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
#include "Neutron.h"
#include "Transport.h"
//#include "Sigma.h"
#endif

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
double simula(int npart, float energy, float thick, vector<float> &vec_length){   // spessore in cm e energia in eV


  // 1, 10, 50 cm
  // 10, 100, 1000 keV
  bool verbose=false;
  const int seed=0;
  const int nbin=110, enmin=0, enmax=(int) (energy+energy*0.1);
  int count=0;
  float x=0.,y=0.,length=-2., totlength=0.;
  float fluence;

  delete gRandom;
  gRandom=new TRandom3(seed);

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

 for(int i=0; i<npart; i++){
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

  TString title="starting energy = "+std::to_string((int) energy/1000)+ " keV";
  histen->SetTitle(title);
  histen->GetYaxis()->SetTitle("Number of Neutrons");
  histen->GetXaxis()->SetTitle("Energy (MeV)");
  histen->Draw("hist");

  cout << "--------------------------------------------------------\n\t\t\t RISULTATI \n--------------------------------------------------------" << endl;
  cout << " Lunghezza tot  " << totlength << "\tcount= "<< count << endl;
  cout << " Fluenza  " << fluence << endl;

  return fluence;
}


void fakemain(){

  // ------------------------------------
  // --- 2Million particles, 1 Mev, 10 cm
  TH1D* hFluenza_2M_1Mev_10cm = new TH1D("hFluenza_2M_1Mev_10cm","hFluenza_2M_1Mev_10cm",50,0.005,0.006);
  TH1F* hLength_2M_1Mev_10cm  = new TH1F("hLength_2M_1Mev_10cm", "hLength_2M_1Mev_10cm", 50,0.,2.);
  
  
  for(int i=0; i<1; i++){

    vector<float> vec_length;
    vec_length.clear();

    hFluenza_2M_1Mev_10cm->Fill(simula(2000000, 1000000, 10.,vec_length));
    for(UInt_t j=0; j<vec_length.size();j++){
      hLength_2M_1Mev_10cm->Fill(vec_length[j]);
    }
    
  }

  TCanvas* cFluenza_2M_1Mev_10cm = new TCanvas("cFluenza_2M_1Mev_10cm","cFluenza_2M_1Mev_10cm");
  cFluenza_2M_1Mev_10cm->cd();
  hFluenza_2M_1Mev_10cm->Draw();
  cFluenza_2M_1Mev_10cm->SaveAs("Fluenza_2M_1Mev_10cm.png");

  TCanvas* cLength_2M_1Mev_10cm = new TCanvas("cLength_2M_1Mev_10cm","cLength_2M_1Mev_10cm");
  cLength_2M_1Mev_10cm->cd();
  hLength_2M_1Mev_10cm->Draw();
  cLength_2M_1Mev_10cm->SaveAs("Length_2M_1Mev_10cm.png");



  // ---------------------------------------
  // --- 2Million particles, 0.1 Mev, 20 cm
  TH1D* hFluenza_2M_100Kev_20cm = new TH1D("hFluenza_2M_100Kev_20cm","hFluenza_2M_100Kev_20cm",50,0.,0.01);
  TH1F* hLength_2M_100Kev_20cm  = new TH1F("hLength_2M_100Kev_20cm", "hLength_2M_100Kev_20cm", 50,0.,2.);
  
  
  for(int i=0; i<1; i++){

    vector<float> vec_length;
    vec_length.clear();

    hFluenza_2M_100Kev_20cm->Fill(simula(2000000, 100000, 20.,vec_length));
    for(UInt_t j=0; j<vec_length.size();j++){
      hLength_2M_100Kev_20cm->Fill(vec_length[j]);
    }
    
  }

  TCanvas* cFluenza_2M_100Kev_20cm = new TCanvas("cFluenza_2M_100Kev_20cm","cFluenza_2M_100Kev_20cm");
  cFluenza_2M_100Kev_20cm->cd();
  hFluenza_2M_100Kev_20cm->Draw();
  cFluenza_2M_100Kev_20cm->SaveAs("Fluenza_2M_100Kev_20cm.png");

  TCanvas* cLength_2M_100Kev_20cm = new TCanvas("cLength_2M_100Kev_20cm","cLength_2M_100Kev_20cm");
  cLength_2M_100Kev_20cm->cd();
  hLength_2M_100Kev_20cm->Draw();
  cLength_2M_100Kev_20cm->SaveAs("Length_2M_100Kev_20cm.png");
  // ------------------------


  // ---------------------------------------
  // --- 2Million particles, 0.1 Mev, 20 cm
  TH1D* hFluenza_2M_100Kev_50cm = new TH1D("hFluenza_2M_100Kev_50cm","hFluenza_2M_100Kev_50cm",50,0.,0.01);
  TH1F* hLength_2M_100Kev_50cm  = new TH1F("hLength_2M_100Kev_50cm", "hLength_2M_100Kev_50cm", 50,0.,2.);
  
  
  for(int i=0; i<1; i++){

    vector<float> vec_length;
    vec_length.clear();

    hFluenza_2M_100Kev_50cm->Fill(simula(2000000, 100000, 20.,vec_length));
    for(UInt_t j=0; j<vec_length.size();j++){
      hLength_2M_100Kev_50cm->Fill(vec_length[j]);
    }
    
  }

  TCanvas* cFluenza_2M_100Kev_50cm = new TCanvas("cFluenza_2M_100Kev_50cm","cFluenza_2M_100Kev_50cm");
  cFluenza_2M_100Kev_50cm->cd();
  hFluenza_2M_100Kev_50cm->Draw();
cFluenza_2M_100Kev_50cm->SaveAs("Fluenza_2M_100Kev_50cm.png");

  TCanvas* cLength_2M_100Kev_50cm = new TCanvas("cLength_2M_100Kev_50cm","cLength_2M_100Kev_50cm");
  cLength_2M_100Kev_50cm->cd();
  hLength_2M_100Kev_50cm->Draw();
  cLength_2M_100Kev_50cm->SaveAs("Length_2M_100Kev_50cm.png");
  // ------------------------
  


}

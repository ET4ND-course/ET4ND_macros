// ***************************************
//
// run with:
//      root -l -b -q plotFluence.C++
//
// ***************************************

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

#include "TString.h"
#include "TLegend.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TMath.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TTree.h"
#include "TAxis.h"
#include "TF1.h"
#include "TGraph.h"
#include "TLine.h"
#include "TPaveText.h"
#include "TRandom3.h"
#include "TPaveText.h"



using namespace std;



void plotFluence(){

  TString plotOutputPath = "outputPlots";  
  gSystem->Exec(("mkdir -p "+plotOutputPath));


  // read file f_100x2Mparticles_10KeV_1cm
  TFile *inFile_100x2Mparticles_10KeV_1cm = TFile::Open("output/f_100x2Mparticles_10KeV_1cm.root");

  TH1F* hFluenza_100x2Mparticles_10KeV_1cm = (TH1F*)inFile_100x2Mparticles_10KeV_1cm->Get("hFluenza");
  TH1F* hLength_100x2Mparticles_10KeV_1cm  = (TH1F*)inFile_100x2Mparticles_10KeV_1cm->Get("hLength");

  TCanvas* cFluenza_100x2Mparticles_10KeV_1cm = new TCanvas("cFluenza_100x2Mparticles_10KeV_1cm","cFluenza_100x2Mparticles_10KeV_1cm");
  cFluenza_100x2Mparticles_10KeV_1cm->cd();
  hFluenza_100x2Mparticles_10KeV_1cm->SetTitle("Fluence 100x2Mparticles 10KeV 1cm");
  hFluenza_100x2Mparticles_10KeV_1cm->SetLineColor(kRed);
  hFluenza_100x2Mparticles_10KeV_1cm->SetLineWidth(2);
  hFluenza_100x2Mparticles_10KeV_1cm->Draw();
  cFluenza_100x2Mparticles_10KeV_1cm->SaveAs((plotOutputPath + "/Fluence_100x2Mparticles_10KeV_1cm.png"));

  TCanvas* cLength_100x2Mparticles_10KeV_1cm = new TCanvas("cLength_100x2Mparticles_10KeV_1cm","cLength_100x2Mparticles_10KeV_1cm");
  cLength_100x2Mparticles_10KeV_1cm->cd();
  hLength_100x2Mparticles_10KeV_1cm->SetTitle("Length 100x2Mparticles 10KeV 1cm");
  hLength_100x2Mparticles_10KeV_1cm->SetLineColor(kRed);
  hLength_100x2Mparticles_10KeV_1cm->SetLineWidth(2);
  hLength_100x2Mparticles_10KeV_1cm->Draw();
  cLength_100x2Mparticles_10KeV_1cm->SaveAs((plotOutputPath + "/Length_100x2Mparticles_10KeV_1cm.png"));


  // read file f_100x2Mparticles_100KeV_1cm
  TFile *inFile_100x2Mparticles_100KeV_1cm = TFile::Open("output/f_100x2Mparticles_100KeV_1cm.root");

  TH1F* hFluenza_100x2Mparticles_100KeV_1cm = (TH1F*)inFile_100x2Mparticles_100KeV_1cm->Get("hFluenza");
  TH1F* hLength_100x2Mparticles_100KeV_1cm  = (TH1F*)inFile_100x2Mparticles_100KeV_1cm->Get("hLength");

  TCanvas* cFluenza_100x2Mparticles_100KeV_1cm = new TCanvas("cFluenza_100x2Mparticles_100KeV_1cm","cFluenza_100x2Mparticles_100KeV_1cm");
  cFluenza_100x2Mparticles_100KeV_1cm->cd();
  hFluenza_100x2Mparticles_100KeV_1cm->SetTitle("Fluence 100x2Mparticles 100KeV 1cm");
  hFluenza_100x2Mparticles_100KeV_1cm->SetLineColor(kRed);
  hFluenza_100x2Mparticles_100KeV_1cm->SetLineWidth(2);
  hFluenza_100x2Mparticles_100KeV_1cm->Draw();
  cFluenza_100x2Mparticles_100KeV_1cm->SaveAs((plotOutputPath + "/Fluence_100x2Mparticles_100KeV_1cm.png"));

  TCanvas* cLength_100x2Mparticles_100KeV_1cm = new TCanvas("cLength_100x2Mparticles_100KeV_1cm","cLength_100x2Mparticles_100KeV_1cm");
  cLength_100x2Mparticles_100KeV_1cm->cd();
  hLength_100x2Mparticles_100KeV_1cm->SetTitle("Length 100x2Mparticles 100KeV 1cm");
  hLength_100x2Mparticles_100KeV_1cm->SetLineColor(kRed);
  hLength_100x2Mparticles_100KeV_1cm->SetLineWidth(2);
  hLength_100x2Mparticles_100KeV_1cm->Draw();
  cLength_100x2Mparticles_100KeV_1cm->SaveAs((plotOutputPath + "/Length_100x2Mparticles_100KeV_1cm.png"));


  // read file f_100x2Mparticles_1000KeV_1cm
  TFile *inFile_100x2Mparticles_1000KeV_1cm = TFile::Open("output/f_100x2Mparticles_1000KeV_1cm.root");

  TH1F* hFluenza_100x2Mparticles_1000KeV_1cm = (TH1F*)inFile_100x2Mparticles_1000KeV_1cm->Get("hFluenza");
  TH1F* hLength_100x2Mparticles_1000KeV_1cm  = (TH1F*)inFile_100x2Mparticles_1000KeV_1cm->Get("hLength");

  TCanvas* cFluenza_100x2Mparticles_1000KeV_1cm = new TCanvas("cFluenza_100x2Mparticles_1000KeV_1cm","cFluenza_100x2Mparticles_1000KeV_1cm");
  cFluenza_100x2Mparticles_1000KeV_1cm->cd();
  hFluenza_100x2Mparticles_1000KeV_1cm->SetTitle("Fluence 100x2Mparticles 1000KeV 1cm");
  hFluenza_100x2Mparticles_1000KeV_1cm->SetLineColor(kRed);
  hFluenza_100x2Mparticles_1000KeV_1cm->SetLineWidth(2);
  hFluenza_100x2Mparticles_1000KeV_1cm->Draw();
  cFluenza_100x2Mparticles_1000KeV_1cm->SaveAs((plotOutputPath + "/Fluence_100x2Mparticles_1000KeV_1cm.png"));

  TCanvas* cLength_100x2Mparticles_1000KeV_1cm = new TCanvas("cLength_100x2Mparticles_1000KeV_1cm","cLength_100x2Mparticles_1000KeV_1cm");
  cLength_100x2Mparticles_1000KeV_1cm->cd();
  hLength_100x2Mparticles_1000KeV_1cm->SetTitle("Length 100x2Mparticles 1000KeV 1cm");
  hLength_100x2Mparticles_1000KeV_1cm->SetLineColor(kRed);
  hLength_100x2Mparticles_1000KeV_1cm->SetLineWidth(2);
  hLength_100x2Mparticles_1000KeV_1cm->Draw();
  cLength_100x2Mparticles_1000KeV_1cm->SaveAs((plotOutputPath + "/Length_100x2Mparticles_1000KeV_1cm.png"));

  
  // ------------------------------

  // read file f_10x2Mparticles_10KeV_10cm
  TFile *inFile_10x2Mparticles_10KeV_10cm = TFile::Open("output/f_10x2Mparticles_10KeV_10cm.root");

  TH1F* hFluenza_10x2Mparticles_10KeV_10cm = (TH1F*)inFile_10x2Mparticles_10KeV_10cm->Get("hFluenza");
  TH1F* hLength_10x2Mparticles_10KeV_10cm  = (TH1F*)inFile_10x2Mparticles_10KeV_10cm->Get("hLength");

  TCanvas* cFluenza_10x2Mparticles_10KeV_10cm = new TCanvas("cFluenza_10x2Mparticles_10KeV_10cm","cFluenza_10x2Mparticles_10KeV_10cm");
  cFluenza_10x2Mparticles_10KeV_10cm->cd();
  hFluenza_10x2Mparticles_10KeV_10cm->SetTitle("Fluence 10x2Mparticles 10KeV 10cm");
  hFluenza_10x2Mparticles_10KeV_10cm->SetLineColor(kRed);
  hFluenza_10x2Mparticles_10KeV_10cm->SetLineWidth(2);
  hFluenza_10x2Mparticles_10KeV_10cm->Draw();
  cFluenza_10x2Mparticles_10KeV_10cm->SaveAs((plotOutputPath + "/Fluence_10x2Mparticles_10KeV_10cm.png"));

  TCanvas* cLength_10x2Mparticles_10KeV_10cm = new TCanvas("cLength_10x2Mparticles_10KeV_10cm","cLength_10x2Mparticles_10KeV_10cm");
  cLength_10x2Mparticles_10KeV_10cm->cd();
  hLength_10x2Mparticles_10KeV_10cm->SetTitle("Length 10x2Mparticles 10KeV 10cm");
  hLength_10x2Mparticles_10KeV_10cm->SetLineColor(kRed);
  hLength_10x2Mparticles_10KeV_10cm->SetLineWidth(2);
  hLength_10x2Mparticles_10KeV_10cm->Draw();
  cLength_10x2Mparticles_10KeV_10cm->SaveAs((plotOutputPath + "/Length_10x2Mparticles_10KeV_10cm.png"));


  // read file f_10x2Mparticles_100KeV_10cm
  TFile *inFile_10x2Mparticles_100KeV_10cm = TFile::Open("output/f_10x2Mparticles_100KeV_10cm.root");

  TH1F* hFluenza_10x2Mparticles_100KeV_10cm = (TH1F*)inFile_10x2Mparticles_100KeV_10cm->Get("hFluenza");
  TH1F* hLength_10x2Mparticles_100KeV_10cm  = (TH1F*)inFile_10x2Mparticles_100KeV_10cm->Get("hLength");

  TCanvas* cFluenza_10x2Mparticles_100KeV_10cm = new TCanvas("cFluenza_10x2Mparticles_100KeV_10cm","cFluenza_10x2Mparticles_100KeV_10cm");
  cFluenza_10x2Mparticles_100KeV_10cm->cd();
  hFluenza_10x2Mparticles_100KeV_10cm->SetTitle("Fluence 10x2Mparticles 100KeV 10cm");
  hFluenza_10x2Mparticles_100KeV_10cm->SetLineColor(kRed);
  hFluenza_10x2Mparticles_100KeV_10cm->SetLineWidth(2);
  hFluenza_10x2Mparticles_100KeV_10cm->Draw();
  cFluenza_10x2Mparticles_100KeV_10cm->SaveAs((plotOutputPath + "/Fluence_10x2Mparticles_100KeV_10cm.png"));

  TCanvas* cLength_10x2Mparticles_100KeV_10cm = new TCanvas("cLength_10x2Mparticles_100KeV_10cm","cLength_10x2Mparticles_100KeV_10cm");
  cLength_10x2Mparticles_100KeV_10cm->cd();
  hLength_10x2Mparticles_100KeV_10cm->SetTitle("Length 10x2Mparticles 100KeV 10cm");
  hLength_10x2Mparticles_100KeV_10cm->SetLineColor(kRed);
  hLength_10x2Mparticles_100KeV_10cm->SetLineWidth(2);
  hLength_10x2Mparticles_100KeV_10cm->Draw();
  cLength_10x2Mparticles_100KeV_10cm->SaveAs((plotOutputPath + "/Length_10x2Mparticles_100KeV_10cm.png"));

 
  // read file f_10x2Mparticles_1000KeV_10cm
  TFile *inFile_10x2Mparticles_1000KeV_10cm = TFile::Open("output/f_10x2Mparticles_1000KeV_10cm.root");

  TH1F* hFluenza_10x2Mparticles_1000KeV_10cm = (TH1F*)inFile_10x2Mparticles_1000KeV_10cm->Get("hFluenza");
  TH1F* hLength_10x2Mparticles_1000KeV_10cm  = (TH1F*)inFile_10x2Mparticles_1000KeV_10cm->Get("hLength");

  TCanvas* cFluenza_10x2Mparticles_1000KeV_10cm = new TCanvas("cFluenza_10x2Mparticles_1000KeV_10cm","cFluenza_10x2Mparticles_1000KeV_10cm");
  cFluenza_10x2Mparticles_1000KeV_10cm->cd();
  hFluenza_10x2Mparticles_1000KeV_10cm->SetTitle("Fluence 10x2Mparticles 1000KeV 10cm");
  hFluenza_10x2Mparticles_1000KeV_10cm->SetLineColor(kRed);
  hFluenza_10x2Mparticles_1000KeV_10cm->SetLineWidth(2);
  hFluenza_10x2Mparticles_1000KeV_10cm->Draw();
  cFluenza_10x2Mparticles_1000KeV_10cm->SaveAs((plotOutputPath + "/Fluence_10x2Mparticles_1000KeV_10cm.png"));

  TCanvas* cLength_10x2Mparticles_1000KeV_10cm = new TCanvas("cLength_10x2Mparticles_1000KeV_10cm","cLength_10x2Mparticles_1000KeV_10cm");
  cLength_10x2Mparticles_1000KeV_10cm->cd();
  hLength_10x2Mparticles_1000KeV_10cm->SetTitle("Length 10x2Mparticles 1000KeV 10cm");
  hLength_10x2Mparticles_1000KeV_10cm->SetLineColor(kRed);
  hLength_10x2Mparticles_1000KeV_10cm->SetLineWidth(2);
  hLength_10x2Mparticles_1000KeV_10cm->Draw();
  cLength_10x2Mparticles_1000KeV_10cm->SaveAs((plotOutputPath + "/Length_10x2Mparticles_1000KeV_10cm.png"));


  // -----------------------------------------------------

  // read file f_10x2Mparticles_10KeV_50cm
  TFile *inFile_10x2Mparticles_10KeV_50cm = TFile::Open("output/f_10x2Mparticles_10KeV_50cm.root");

  TH1F* hFluenza_10x2Mparticles_10KeV_50cm = (TH1F*)inFile_10x2Mparticles_10KeV_50cm->Get("hFluenza");
  TH1F* hLength_10x2Mparticles_10KeV_50cm  = (TH1F*)inFile_10x2Mparticles_10KeV_50cm->Get("hLength");

  TCanvas* cFluenza_10x2Mparticles_10KeV_50cm = new TCanvas("cFluenza_10x2Mparticles_10KeV_50cm","cFluenza_10x2Mparticles_10KeV_50cm");
  cFluenza_10x2Mparticles_10KeV_50cm->cd();
  hFluenza_10x2Mparticles_10KeV_50cm->SetTitle("Fluence 10x2Mparticles 10KeV 50cm");
  hFluenza_10x2Mparticles_10KeV_50cm->SetLineColor(kRed);
  hFluenza_10x2Mparticles_10KeV_50cm->SetLineWidth(2);
  hFluenza_10x2Mparticles_10KeV_50cm->Draw();
  cFluenza_10x2Mparticles_10KeV_50cm->SaveAs((plotOutputPath + "/Fluence_10x2Mparticles_10KeV_50cm.png"));

  TCanvas* cLength_10x2Mparticles_10KeV_50cm = new TCanvas("cLength_10x2Mparticles_10KeV_50cm","cLength_10x2Mparticles_10KeV_50cm");
  cLength_10x2Mparticles_10KeV_50cm->cd();
  hLength_10x2Mparticles_10KeV_50cm->SetTitle("Length 10x2Mparticles 10KeV 50cm");
  hLength_10x2Mparticles_10KeV_50cm->SetLineColor(kRed);
  hLength_10x2Mparticles_10KeV_50cm->SetLineWidth(2);
  hLength_10x2Mparticles_10KeV_50cm->Draw();
  cLength_10x2Mparticles_10KeV_50cm->SaveAs((plotOutputPath + "/Length_10x2Mparticles_10KeV_50cm.png"));


  // read file f_10x2Mparticles_100KeV_50cm
  TFile *inFile_10x2Mparticles_100KeV_50cm = TFile::Open("output/f_10x2Mparticles_100KeV_50cm.root");

  TH1F* hFluenza_10x2Mparticles_100KeV_50cm = (TH1F*)inFile_10x2Mparticles_100KeV_50cm->Get("hFluenza");
  TH1F* hLength_10x2Mparticles_100KeV_50cm  = (TH1F*)inFile_10x2Mparticles_100KeV_50cm->Get("hLength");

  TCanvas* cFluenza_10x2Mparticles_100KeV_50cm = new TCanvas("cFluenza_10x2Mparticles_100KeV_50cm","cFluenza_10x2Mparticles_100KeV_50cm");
  cFluenza_10x2Mparticles_100KeV_50cm->cd();
  hFluenza_10x2Mparticles_100KeV_50cm->SetTitle("Fluence 10x2Mparticles 100KeV 50cm");
  hFluenza_10x2Mparticles_100KeV_50cm->SetLineColor(kRed);
  hFluenza_10x2Mparticles_100KeV_50cm->SetLineWidth(2);
  hFluenza_10x2Mparticles_100KeV_50cm->Draw();
  cFluenza_10x2Mparticles_100KeV_50cm->SaveAs((plotOutputPath + "/Fluence_10x2Mparticles_100KeV_50cm.png"));

  TCanvas* cLength_10x2Mparticles_100KeV_50cm = new TCanvas("cLength_10x2Mparticles_100KeV_50cm","cLength_10x2Mparticles_100KeV_50cm");
  cLength_10x2Mparticles_100KeV_50cm->cd();
  hLength_10x2Mparticles_100KeV_50cm->SetTitle("Length 10x2Mparticles 100KeV 50cm");
  hLength_10x2Mparticles_100KeV_50cm->SetLineColor(kRed);
  hLength_10x2Mparticles_100KeV_50cm->SetLineWidth(2);
  hLength_10x2Mparticles_100KeV_50cm->Draw();
  cLength_10x2Mparticles_100KeV_50cm->SaveAs((plotOutputPath + "/Length_10x2Mparticles_100KeV_50cm.png"));

 
  // read file f_10x2Mparticles_1000KeV_50cm
  TFile *inFile_10x2Mparticles_1000KeV_50cm = TFile::Open("output/f_10x2Mparticles_1000KeV_50cm.root");

  TH1F* hFluenza_10x2Mparticles_1000KeV_50cm = (TH1F*)inFile_10x2Mparticles_1000KeV_50cm->Get("hFluenza");
  TH1F* hLength_10x2Mparticles_1000KeV_50cm  = (TH1F*)inFile_10x2Mparticles_1000KeV_50cm->Get("hLength");

  TCanvas* cFluenza_10x2Mparticles_1000KeV_50cm = new TCanvas("cFluenza_10x2Mparticles_1000KeV_50cm","cFluenza_10x2Mparticles_1000KeV_50cm");
  cFluenza_10x2Mparticles_1000KeV_50cm->cd();
  hFluenza_10x2Mparticles_1000KeV_50cm->SetTitle("Fluence 10x2Mparticles 1000KeV 50cm");
  hFluenza_10x2Mparticles_1000KeV_50cm->SetLineColor(kRed);
  hFluenza_10x2Mparticles_1000KeV_50cm->SetLineWidth(2);
  hFluenza_10x2Mparticles_1000KeV_50cm->Draw();
  cFluenza_10x2Mparticles_1000KeV_50cm->SaveAs((plotOutputPath + "/Fluence_10x2Mparticles_1000KeV_50cm.png"));

  TCanvas* cLength_10x2Mparticles_1000KeV_50cm = new TCanvas("cLength_10x2Mparticles_1000KeV_50cm","cLength_10x2Mparticles_1000KeV_50cm");
  cLength_10x2Mparticles_1000KeV_50cm->cd();
  hLength_10x2Mparticles_1000KeV_50cm->SetTitle("Length 10x2Mparticles 1000KeV 50cm");
  hLength_10x2Mparticles_1000KeV_50cm->SetLineColor(kRed);
  hLength_10x2Mparticles_1000KeV_50cm->SetLineWidth(2);
  hLength_10x2Mparticles_1000KeV_50cm->Draw();
  cLength_10x2Mparticles_1000KeV_50cm->SaveAs((plotOutputPath + "/Length_10x2Mparticles_1000KeV_50cm.png"));



}

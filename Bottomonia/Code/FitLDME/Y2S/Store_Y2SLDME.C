#ifndef __CINT__
#endif
#include "TLatex.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TAxis.h"
#include "TH1.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1D.h"
#include "TF1.h"
#include "TH1I.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TMath.h"
#include "TVector3.h"
#include "TString.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "TObjArray.h"
#include "TGaxis.h"
#include "TLine.h"
#include "TColor.h"
#include "TStyle.h"
#include <iostream>
#include <iomanip>
#include "TGraphAsymmErrors.h"
#include "TMinuit.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TGraphErrors.h"
#include "TAxis.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TMath.h"

const Double_t mB = 1.6;
//==================== Common Branching Ratios =======================//
Double_t BRY3SToY2S =0.199;
Double_t BRY3SToMuMu =0.0218;
Double_t BRY2SToMuMu =0.0193;




//=================== Fitted LDMEs ==================================//
//========= Our Values of fitted Psi(2S) LDME =========//
Double_t Y3S_LDME_3S1_1 = 1.0;  
Double_t Y3S_LDME_1S0_8 = 0.02639;
Double_t Y3S_LDME_3S1_8 = 0.00190;

//Double_t Y3S_LDME_1S0_8 = 0.02260;
//Double_t Y3S_LDME_3S1_8 = 0.00210;

Double_t Y3S_LDME_3P0_8 = mB*mB*Y3S_LDME_1S0_8;
Double_t Y3S_LDME_3P1_8 = 3.0*Y3S_LDME_3P0_8;
Double_t Y3S_LDME_3P2_8 = 5.0*Y3S_LDME_3P0_8;

Double_t Scale_Pt(Double_t Y2SPt);
TGraph *Add_QCDSigma(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3,TGraph *InGraph4);
TGraph *Scale_QCDSigma(TGraph *InGraph, Double_t LDME);


//================== ATLAS1212: open the calculated root file ===========================================//
TFile *file_ATLAS1212_RootS7TeV_Y2SCrossSection =  new TFile("rootFiles/ATLASMidRap/Y2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");

//================== ATLAS12225: open the calculated root file ===========================================//
TFile *file_ATLAS12225_RootS7TeV_Y2SCrossSection =  new TFile("rootFiles/ATLASRap12225/Y2SCrossSection_Rap12225.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");

//================== CMS24: open the calculated root file ===========================================//
TFile *file_CMS24_RootS7TeV_Y2SCrossSection =  new TFile("rootFiles/CMS24/Y2SCrossSection_Rap24.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CMS24_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");

//******************************************************************************
//******************************************************************************

//================================== root Files for FeedDown calculations =================================//
//================== Y(3S): open the calculated root file ATLAS1212===========================================//

TFile *file_ATLAS1212_RootS7TeV_Y3SCrossSection =  new TFile("rootFiles/ATLASMidRap/Y3SCrossSection0012.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS1212_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS1212_RootS7TeV_Y3S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS1212_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS1212_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS1212_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS1212_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS1212_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");

//================== Y(3S): open the calculated root file ATLAS12225===========================================//

TFile *file_ATLAS12225_RootS7TeV_Y3SCrossSection =  new TFile("rootFiles/ATLASRap12225/Y3SCrossSection_Rap12225.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS12225_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS12225_RootS7TeV_Y3S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS12225_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS12225_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS12225_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS12225_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS12225_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");

//================== Y(3S): open the calculated root file CMS24===========================================//

TFile *file_CMS24_RootS7TeV_Y3SCrossSection =  new TFile("rootFiles/CMS24/Y3SCrossSection_Rap24.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS24_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CMS24_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCMS24_RootS7TeV_Y3S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCMS24_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCMS24_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCMS24_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCMS24_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CMS24_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");




Double_t ATLAS1212_FitLDME(Double_t *x, Double_t *par);
Double_t ATLAS12225_FitLDME(Double_t *x, Double_t *par);
Double_t CMS24_FitLDME(Double_t *x, Double_t *par);
Double_t ATLAS1212_Y3S_FeedDown(Double_t Pt);
Double_t ATLAS12225_Y3S_FeedDown(Double_t Pt);
Double_t CMS24_Y3S_FeedDown(Double_t Pt);
TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt();
TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt();
TGraphAsymmErrors *Data_CMS_D2NDPtDy_Y2S_Rap24_Pt();



//TGraph *Grf_ATLAS1212_Y3S_FeedDown(TGraph *InGraph);


void Y2SLDME()
{
 gROOT->SetStyle("Plain");
  gStyle->SetPalette(1);
  gStyle->SetOptTitle(0);
  //gStyle->SetOptStat("nmr");
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(0);
  
  gStyle->SetTitleFillColor(0);
  gStyle->SetStatColor(0);

  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameFillColor(0);
  gStyle->SetFrameLineColor(kBlack);

  gStyle->SetCanvasColor(0);
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasBorderSize(0);

  gStyle->SetPadColor(0);
  gStyle->SetPadBorderMode(0);
  gStyle->SetPadBorderSize(0);

  gStyle->SetTextSize(0.04);
  gStyle->SetTextFont(42);
  gStyle->SetLabelFont(42,"xyz");
  gStyle->SetTitleFont(42,"xyz");
  gStyle->SetTitleSize(0.048,"xyz");
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadTopMargin(0.03);
  gStyle->SetPadRightMargin(0.065);
  gStyle->SetPadLeftMargin(0.12);

  //gStyle->SetTitleXOffset(1.15);
  //gStyle->SetTitleYOffset(1.2);

  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);

  gStyle->SetCanvasDefH(600);
  gStyle->SetCanvasDefW(600);
  gStyle->SetHistMinimumZero(kTRUE);
  gStyle->SetErrorX(0);   
  gStyle->SetEndErrorSize(0);

  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(1.3);

  gROOT->ForceStyle();



  char OutTextFile[100];
  sprintf(OutTextFile,"LDME_Y2S.txt");
  ofstream dataFile(Form(OutTextFile),ios::app);

  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING ATLAS DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  cout<<" getting Data Graph ATLAS |y| < 1.2: "<<endl;
   

  TGraphAsymmErrors *grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt=new TGraphAsymmErrors();
  grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt=Data_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt();
  
  new TCanvas ;
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt->Draw("AP");
  //*************************************************
  //*************************************************
  cout<<" getting Data Graph ATLAS 1.2 < |y| < 2.25: "<<endl;
   

  TGraphAsymmErrors *grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt=new TGraphAsymmErrors();
  grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt=Data_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt();
  
  new TCanvas ;
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt->Draw("AP");


  //******************************************************
  //******************************************************

  cout<<" getting Data Graph CMS |y| < 2.4: "<<endl;
   

  TGraphAsymmErrors *grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt=new TGraphAsymmErrors();
  grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt=Data_CMS_D2NDPtDy_Y2S_Rap24_Pt();
  
  new TCanvas ;
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt->Draw("AP");


  //******************************************************
  //******************************************************



  TF1 *ATLAS1212_FitFunctionLDME = new TF1("ATLAS1212_FitFunctionLDME", ATLAS1212_FitLDME, 10.0, 70, 3);
  ATLAS1212_FitFunctionLDME->SetLineColor(2);
  ATLAS1212_FitFunctionLDME->FixParameter(0,1);                         
  grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt->Fit("ATLAS1212_FitFunctionLDME","Q0","MER", 10, 70);
  
  Double_t ATLAS1212_Chi2 = ATLAS1212_FitFunctionLDME->GetChisquare();
  Double_t ATLAS1212_NDF = ATLAS1212_FitFunctionLDME->GetNDF();
  Double_t ATLAS1212_Prob = ATLAS1212_FitFunctionLDME->GetProb();
  
  Double_t ATLAS1212_LDME_3S1_1 = ATLAS1212_FitFunctionLDME->GetParameter(0);
  Double_t ATLAS1212_LDME_1S0_8 = ATLAS1212_FitFunctionLDME->GetParameter(1);
  Double_t ATLAS1212_LDME_3S1_8 = ATLAS1212_FitFunctionLDME->GetParameter(2);
  
  Double_t ATLAS1212_LDME_3P0_8 = ATLAS1212_LDME_1S0_8*mB*mB;
  Double_t ATLAS1212_LDME_3P1_8 = 3.0*ATLAS1212_LDME_3P0_8;
  Double_t ATLAS1212_LDME_3P2_8 = 5.0*ATLAS1212_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<ATLAS1212_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<ATLAS1212_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<ATLAS1212_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<ATLAS1212_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<ATLAS1212_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<ATLAS1212_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<ATLAS1212_Chi2<<"/"<<ATLAS1212_NDF<<" Prob: "<<ATLAS1212_Prob<<endl<<endl;
  /*
  dataFile<<"Fitting ATLAS1212_ Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<ATLAS1212_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<ATLAS1212_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<ATLAS1212_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<ATLAS1212_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<ATLAS1212_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<ATLAS1212_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<ATLAS1212_Chi2<<"/"<<ATLAS1212_NDF<<" Prob: "<<ATLAS1212_Prob<<endl<<endl;
  */


  TGraph *Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, ATLAS1212_LDME_3S1_1);
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, ATLAS1212_LDME_1S0_8);
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, ATLAS1212_LDME_3S1_8);
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, ATLAS1212_LDME_3P0_8);
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, ATLAS1212_LDME_3P1_8);
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, ATLAS1212_LDME_3P2_8);
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);


  TLegend *lgd_ATLAS1212_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  
  lgd_ATLAS1212_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_ATLAS1212_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_ATLAS1212_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_ATLAS1212_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_ATLAS1212_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLAS1212_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_ATLAS1212_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_ATLAS1212_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_ATLAS1212_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_ATLAS1212_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt->Draw("zAP");  
  grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt->Draw("zAP");
  grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  gPad->Update();
  ATLAS1212_FitFunctionLDME->Draw("same");
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_ATLAS1212_DSigmaDPtDY_Pt->Draw("same");
  
  gPad->SaveAs("Plots/ATLAS_D2NDPtDy_Y2S_Y1212_Pt_All.pdf");
  gPad->SaveAs("Plots/ATLAS_D2NDPtDy_Y2S_Y1212_Pt_All.png");




  TGraph *Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_ATLAS1212_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_ATLAS1212_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_ATLAS1212_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_ATLAS1212_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_ATLAS1212_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_ATLAS1212_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLAS1212_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_ATLAS1212_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt->Draw("zAP");
  grfData_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  ATLAS1212_FitFunctionLDME->Draw("same");
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_ATLAS1212_DSigmaDPtDY_Pt1->Draw("same");
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.pdf");
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.png");

  //***********************************************************
  //***********************************************************


  TF1 *ATLAS12225_FitFunctionLDME = new TF1("ATLAS12225_FitFunctionLDME", ATLAS12225_FitLDME, 10.0, 70, 3);
  ATLAS12225_FitFunctionLDME->SetLineColor(4);
  ATLAS12225_FitFunctionLDME->FixParameter(0,1);                         
  grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt->Fit("ATLAS12225_FitFunctionLDME","Q0","MER", 10, 70);
  
  Double_t ATLAS12225_Chi2 = ATLAS12225_FitFunctionLDME->GetChisquare();
  Double_t ATLAS12225_NDF = ATLAS12225_FitFunctionLDME->GetNDF();
  Double_t ATLAS12225_Prob = ATLAS12225_FitFunctionLDME->GetProb();
  
  Double_t ATLAS12225_LDME_3S1_1 = ATLAS12225_FitFunctionLDME->GetParameter(0);
  Double_t ATLAS12225_LDME_1S0_8 = ATLAS12225_FitFunctionLDME->GetParameter(1);
  Double_t ATLAS12225_LDME_3S1_8 = ATLAS12225_FitFunctionLDME->GetParameter(2);
  
  Double_t ATLAS12225_LDME_3P0_8 = ATLAS12225_LDME_1S0_8*mB*mB;
  Double_t ATLAS12225_LDME_3P1_8 = 3.0*ATLAS12225_LDME_3P0_8;
  Double_t ATLAS12225_LDME_3P2_8 = 5.0*ATLAS12225_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<ATLAS12225_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<ATLAS12225_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<ATLAS12225_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<ATLAS12225_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<ATLAS12225_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<ATLAS12225_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<ATLAS12225_Chi2<<"/"<<ATLAS12225_NDF<<" Prob: "<<ATLAS12225_Prob<<endl<<endl;
  /*
  dataFile<<"Fitting ATLAS12225_ Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<ATLAS12225_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<ATLAS12225_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<ATLAS12225_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<ATLAS12225_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<ATLAS12225_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<ATLAS12225_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<ATLAS12225_Chi2<<"/"<<ATLAS12225_NDF<<" Prob: "<<ATLAS12225_Prob<<endl<<endl;
  */


  TGraph *Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, ATLAS12225_LDME_3S1_1);
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(2);
  TGraph *Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, ATLAS12225_LDME_1S0_8);
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(5);
  TGraph *Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, ATLAS12225_LDME_3S1_8);
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(7);
  TGraph *Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, ATLAS12225_LDME_3P0_8);
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(9);
  TGraph *Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, ATLAS12225_LDME_3P1_8);
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(10);
  TGraph *Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, ATLAS12225_LDME_3P2_8);
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(47);


  TLegend *lgd_ATLAS12225_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  
  lgd_ATLAS12225_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_ATLAS12225_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_ATLAS12225_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_ATLAS12225_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_ATLAS12225_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLAS12225_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_ATLAS12225_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_ATLAS12225_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_ATLAS12225_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_ATLAS12225_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt->Draw("zAP");  
  grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt->Draw("zAP");
  grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt->GetYaxis()->SetTitleOffset(1.6);
  grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  gPad->Update();
  ATLAS12225_FitFunctionLDME->Draw("same");
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_ATLAS12225_DSigmaDPtDY_Pt->Draw("same");
  
  gPad->SaveAs("Plots/ATLAS_D2NDPtDy_Y2S_Y12225_Pt_All.pdf");
  gPad->SaveAs("Plots/ATLAS_D2NDPtDy_Y2S_Y12225_Pt_All.png");




  TGraph *Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(5);
  
  
  TLegend *lgd_ATLAS12225_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_ATLAS12225_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_ATLAS12225_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_ATLAS12225_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_ATLAS12225_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_ATLAS12225_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLAS12225_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_ATLAS12225_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt->Draw("zAP");
  grfData_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  ATLAS12225_FitFunctionLDME->Draw("same");
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_ATLAS12225_DSigmaDPtDY_Pt1->Draw("same");
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.pdf");
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.png");

  //***********************************************************
  //***********************************************************

  TF1 *CMS24_FitFunctionLDME = new TF1("CMS24_FitFunctionLDME", CMS24_FitLDME, 10.0, 70, 3);
  CMS24_FitFunctionLDME->SetLineColor(6);
  CMS24_FitFunctionLDME->FixParameter(0,1);                         
  grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt->Fit("CMS24_FitFunctionLDME","Q0","MER", 10, 70);
  
  Double_t CMS24_Chi2 = CMS24_FitFunctionLDME->GetChisquare();
  Double_t CMS24_NDF = CMS24_FitFunctionLDME->GetNDF();
  Double_t CMS24_Prob = CMS24_FitFunctionLDME->GetProb();
  
  Double_t CMS24_LDME_3S1_1 = CMS24_FitFunctionLDME->GetParameter(0);
  Double_t CMS24_LDME_1S0_8 = CMS24_FitFunctionLDME->GetParameter(1);
  Double_t CMS24_LDME_3S1_8 = CMS24_FitFunctionLDME->GetParameter(2);
  
  Double_t CMS24_LDME_3P0_8 = CMS24_LDME_1S0_8*mB*mB;
  Double_t CMS24_LDME_3P1_8 = 3.0*CMS24_LDME_3P0_8;
  Double_t CMS24_LDME_3P2_8 = 5.0*CMS24_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<CMS24_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<CMS24_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<CMS24_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<CMS24_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<CMS24_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<CMS24_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<CMS24_Chi2<<"/"<<CMS24_NDF<<" Prob: "<<CMS24_Prob<<endl<<endl;
  /*
  dataFile<<"Fitting CMS24_ Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<CMS24_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<CMS24_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<CMS24_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<CMS24_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<CMS24_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<CMS24_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<CMS24_Chi2<<"/"<<CMS24_NDF<<" Prob: "<<CMS24_Prob<<endl<<endl;
  */


  TGraph *Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, CMS24_LDME_3S1_1);
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(3);
  TGraph *Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, CMS24_LDME_1S0_8);
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(6);
  TGraph *Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, CMS24_LDME_3S1_8);
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(8);
  TGraph *Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, CMS24_LDME_3P0_8);
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(10);
  TGraph *Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, CMS24_LDME_3P1_8);
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(11);
  TGraph *Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, CMS24_LDME_3P2_8);
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(48);


  TLegend *lgd_CMS24_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  
  lgd_CMS24_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_CMS24_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_CMS24_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_CMS24_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_CMS24_DSigmaDPtDY_Pt->AddEntry(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_CMS24_DSigmaDPtDY_Pt->AddEntry(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_CMS24_DSigmaDPtDY_Pt->AddEntry(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_CMS24_DSigmaDPtDY_Pt->AddEntry(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_CMS24_DSigmaDPtDY_Pt->AddEntry(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_CMS24_DSigmaDPtDY_Pt->AddEntry(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt->Draw("zAP");  
  grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt->Draw("zAP");
  grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt->GetYaxis()->SetTitleOffset(1.6);
  grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  gPad->Update();
  CMS24_FitFunctionLDME->Draw("same");
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_CMS24_DSigmaDPtDY_Pt->Draw("same");
  
  gPad->SaveAs("Plots/CMS_D2NDPtDy_Y2S_Y24_Pt_All.pdf");
  gPad->SaveAs("Plots/CMS_D2NDPtDy_Y2S_Y24_Pt_All.png");




  TGraph *Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(5);
  
  
  TLegend *lgd_CMS24_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_CMS24_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_CMS24_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_CMS24_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_CMS24_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_CMS24_DSigmaDPtDY_Pt1->AddEntry(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_CMS24_DSigmaDPtDY_Pt1->AddEntry(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_CMS24_DSigmaDPtDY_Pt1->AddEntry(Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt->Draw("zAP");
  grfData_CMS_D2NDPtDy_Y2S_Rap24_Pt->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  CMS24_FitFunctionLDME->Draw("same");
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_CMS24_DSigmaDPtDY_Pt1->Draw("same");
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.pdf");
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.png");

  //***********************************************************
  //***********************************************************


}

TGraph *Scale_QCDSigma(TGraph *InGraph, Double_t LDME)
{
  
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph->GetN();++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=LDME*yy;
    SGraph ->SetPoint(j,xx,zz);  
    
  }

  SGraph->SetLineStyle(7);
  SGraph->SetLineWidth(2);

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;


}


TGraph *Add_QCDSigma(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3,TGraph *InGraph4)
{
  
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx1,yy1,zz1;
    Double_t xx2,yy2;
    Double_t xx3,yy3;
    Double_t xx4,yy4;

    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);
    InGraph3->GetPoint(j,xx3,yy3);
    InGraph4->GetPoint(j,xx4,yy4);
    zz1=yy1+yy2+yy3+yy4;
    SGraph->SetPoint(j,xx1,zz1);  
    
  }

  SGraph->SetLineStyle(7);
  SGraph->SetLineWidth(2);

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;


}










//*******************************************************
//*******************************************************

Double_t ATLAS1212_FitLDME(Double_t *x, Double_t *par)
{

  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  //Double_t LDME_3P0_8;
  //Double_t LDME_3P1_8;
  //Double_t LDME_3P2_8;
  
  //LDME_3P0_8 = mB*mB*LDME_1S0_8;
  //LDME_3P1_8=3.0*LDME_3P0_8;
  //LDME_3P2_8=5.0*LDME_3P0_8;
  

  Double_t SigmaDirect = (LDME_3S1_1*grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) 
			  + LDME_3S1_8*grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])  
			  + LDME_1S0_8*5.0*grATLAS1212_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]));

  Double_t SigmaFeedDown = ATLAS1212_Y3S_FeedDown(x[0]) ;
  //+ ATLAS1212_Chic0_FeedDown(x[0]) + ATLAS1212_Chic1_FeedDown(x[0]) + ATLAS1212_Chic2_FeedDown(x[0]);
  
  Double_t Sigma = SigmaDirect + SigmaFeedDown;
  return Sigma;
  
}

Double_t ATLAS12225_FitLDME(Double_t *x, Double_t *par)
{

  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  //Double_t LDME_3P0_8;
  //Double_t LDME_3P1_8;
  //Double_t LDME_3P2_8;
  
  //LDME_3P0_8 = mB*mB*LDME_1S0_8;
  //LDME_3P1_8=3.0*LDME_3P0_8;
  //LDME_3P2_8=5.0*LDME_3P0_8;
  
  Double_t Fac_calc_one_side_Rap=2.0;
  Double_t SigmaDirect = Fac_calc_one_side_Rap*(LDME_3S1_1*grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) 
			  + LDME_3S1_8*grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])  
			  + LDME_1S0_8*5.0*grATLAS12225_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]));

  Double_t SigmaFeedDown = ATLAS12225_Y3S_FeedDown(x[0]) ;
  //+ ATLAS12225_Chic0_FeedDown(x[0]) + ATLAS12225_Chic1_FeedDown(x[0]) + ATLAS12225_Chic2_FeedDown(x[0]);
  
  Double_t Sigma = SigmaDirect + SigmaFeedDown;
  return Sigma;
  
}

//*******************************************************
//*******************************************************
Double_t CMS24_FitLDME(Double_t *x, Double_t *par)
{

  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  //Double_t LDME_3P0_8;
  //Double_t LDME_3P1_8;
  //Double_t LDME_3P2_8;
  
  //LDME_3P0_8 = mB*mB*LDME_1S0_8;
  //LDME_3P1_8=3.0*LDME_3P0_8;
  //LDME_3P2_8=5.0*LDME_3P0_8;
  

  Double_t SigmaDirect = (LDME_3S1_1*grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) 
			  + LDME_3S1_8*grCMS24_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])  
			  + LDME_1S0_8*5.0*grCMS24_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]));

  Double_t SigmaFeedDown = CMS24_Y3S_FeedDown(x[0]) ;
  //+ CMS24_Chic0_FeedDown(x[0]) + CMS24_Chic1_FeedDown(x[0]) + CMS24_Chic2_FeedDown(x[0]);
  
  Double_t Sigma = SigmaDirect + SigmaFeedDown;
  return Sigma;
  
}

//*******************************************************
//*******************************************************





Double_t ATLAS1212_Y3S_FeedDown(Double_t Pt)
{
  
  //Scale Y3S Pt for Y2S
  Double_t Y3SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Y3S_LDME_3S1_1*grATLAS1212_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Y3SPt) 
		    + Y3S_LDME_3S1_8*grATLAS1212_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Y3SPt)
		    + Y3S_LDME_1S0_8*5.0*grATLAS1212_RootS7TeV_Y3S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Y3SPt)); 



  //Double_t BRY3SToY2S =0.199;
  //Double_t BRY3SToMuMu =0.0218;
  //Double_t BRY2SToMuMu =0.0193;
		      
  Double_t BRCorr =  (BRY3SToY2S*BRY2SToMuMu)/BRY3SToMuMu;
  Sigma = Sigma*BRCorr;
  
  return Sigma;
}

//*******************************************************
//*******************************************************
Double_t ATLAS12225_Y3S_FeedDown(Double_t Pt)
{
  
  //Scale Y3S Pt for Y2S
  Double_t Y3SPt = Scale_Pt(Pt);
  Double_t Fac_calc_one_side_Rap=2.0;
  

  Double_t Sigma = Fac_calc_one_side_Rap*(Y3S_LDME_3S1_1*grATLAS12225_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Y3SPt) 
		    + Y3S_LDME_3S1_8*grATLAS12225_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Y3SPt)
		    + Y3S_LDME_1S0_8*5.0*grATLAS12225_RootS7TeV_Y3S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Y3SPt)); 



  //Double_t BRY3SToY2S =0.199;
  //Double_t BRY3SToMuMu =0.0218;
  //Double_t BRY2SToMuMu =0.0193;
		      
  Double_t BRCorr =  (BRY3SToY2S*BRY2SToMuMu)/BRY3SToMuMu;
  Sigma = Sigma*BRCorr;
  
  return Sigma;
}

//*******************************************************
//*******************************************************
Double_t CMS24_Y3S_FeedDown(Double_t Pt)
{
  
  //Scale Y3S Pt for Y2S
  Double_t Y3SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Y3S_LDME_3S1_1*grCMS24_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Y3SPt) 
		    + Y3S_LDME_3S1_8*grCMS24_RootS7TeV_Y3S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Y3SPt)
		    + Y3S_LDME_1S0_8*5.0*grCMS24_RootS7TeV_Y3S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Y3SPt)); 



  //Double_t BRY3SToY2S =0.199;
  //Double_t BRY3SToMuMu =0.0218;
  //Double_t BRY2SToMuMu =0.0193;
		      
  Double_t BRCorr =  (BRY3SToY2S*BRY2SToMuMu)/BRY3SToMuMu;
  Sigma = Sigma*BRCorr;
  
  return Sigma;
}

//*******************************************************
//*******************************************************






Double_t Scale_Pt(Double_t Y2SPt)
{



  //currently it is using relation between psi(2S) and J/psi pT --> should be changed for final calculations
  Double_t Y3SPt;
  Double_t MM = 0.0;
  Double_t CC = 0.0;
  MM=1.154; CC = 0.1413;
  Y3SPt  = MM * Y2SPt + CC;
  
  return Y3SPt;
}



TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_Y2S_Rap0012_Pt()
{
  // D2(SIG)/DPT/DYRAP IN FB/GEV http://hepdata.cedar.ac.uk/view/ins1204994/first
  const int NN = 25;
  
  Double_t p8319_d1x1y1_xval[NN] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0, 
    29.0, 31.0, 34.0, 38.0, 45.0, 60.0};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 
    1.0, 1.0, 2.0, 2.0, 5.0, 10.0};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 
    1.0, 1.0, 2.0, 2.0, 5.0, 10.0};
  
  Double_t p8319_d1x1y1_yval[NN] = {14099.19, 37169.61, 43895.41, 53632.18, 51016.7, 41440.45, 35410.02, 29636.38, 22632.57, 
    19053.93, 12611.54, 7939.33, 5343.06, 3309.25, 2072.13, 1337.29, 897.91, 608.07, 418.21, 
    296.1, 209.3, 128.9, 74.37, 31.83, 7.51 }; 

  // Double_t p8319_d1x1y1_yerrminus[NN] = {3915.9007974794254, 10660.241072564917, 12853.494024929563, 14293.457798353062, 13238.90561274987, 11292.63679040905, 9961.513892185263, 8653.921212323346, 6430.445462843145, 
  //    5246.714875557847, 3297.1416707960852, 1967.388458693402, 1217.0259453273788, 705.8831526534685, 410.33545277004765, 246.36233255106188, 157.04912002300426, 101.24744243683392, 67.16017048816954, 
  //  44.87941398904402, 31.301439264033853, 17.62770830255595, 10.05802167426577, 3.9284348028190563, 1.1434159348198711};
  
  //Double_t p8319_d1x1y1_yerrplus[NN] = {3584.398011884283, 14539.50576821647, 48442.20717914285, 101196.61661934454, 106239.46591437947, 80524.4152455173, 58953.63710351805, 39473.663513499734, 22059.308130478617, 
  // 13904.259904140888, 7055.801357018209, 3287.4933701225923, 1749.2841637652814, 920.9084363279554, 497.0995806676968, 286.2217689135472, 173.65078692594514, 108.14296371008149, 70.38218595639098, 
  //  47.09316192399911, 32.442011343318406, 17.764475787368454, 10.074691062260918, 3.9676315353117153, 1.162497311824849};


  Double_t p8319_d1x1y1_yerrminus_syst[NN] = {964.76, 2312.76, 2868.30, 2121.16, 2570.79, 1950.95, 2072.88, 2140.29, 1532.72, 1025.33, 547.18, 437.05, 119.26, 77.34, 32.81, 22.57, 15.91, 12.89, 13.90, 9.53, 7.17, 2.51, 2.15, 1.06, 0.76};
  
  Double_t p8319_d1x1y1_yerrplus_syst[NN] = {964.76, 2312.76, 2868.30, 2121.16, 2570.79, 1950.95, 2072.88, 2140.29, 1532.72, 1025.33, 547.18, 437.05, 119.26, 77.34, 32.81, 22.57, 15.91, 12.89, 13.90, 9.53, 7.17, 2.51, 2.15, 1.06, 0.76};


  Double_t p8319_d1x1y1_yerrminus_stat[NN] = {462.5, 901.0, 1013.67, 1219.81, 1122.06, 989.2, 818.33, 1227.45, 664.19, 
    465.43, 283.93, 153.6, 82.14, 59.1, 43.89, 33.56, 27.06, 21.34, 18.39, 
    14.47, 12.56, 6.82, 5.13, 2.21, 0.67};
  
  Double_t p8319_d1x1y1_yerrplus_stat[NN] = {462.5, 901.0, 1013.67, 1219.81, 1122.06, 989.2, 818.33, 1227.45, 664.19, 
    465.43, 283.93, 153.6, 82.14, 59.1, 43.89, 33.56, 27.06, 21.34, 18.39, 
    14.47, 12.56, 6.82, 5.13, 2.21, 0.67};

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t DeltaY = 1;
   
  Double_t FeftoBarnToPicoBarn = 0.001;
  Double_t BR_Y3SToMuMu = 0.0218;

  Double_t Fac = FeftoBarnToPicoBarn;

  //Fac =1;

  for(int j=0;j<NN;j++)
    {
      p8319_d1x1y1_yval[j] =((p8319_d1x1y1_yval[j])/DeltaY)*Fac;
      

            yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j] + p8319_d1x1y1_yerrminus_stat[j]*p8319_d1x1y1_yerrminus_stat[j]);
            yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j] + p8319_d1x1y1_yerrplus_stat[j]*p8319_d1x1y1_yerrplus_stat[j]); 
      //      yerr_minus[j]=p8319_d1x1y1_yerrminus_stat[j];
      //      yerr_plus[j]=p8319_d1x1y1_yerrplus_stat[j]; 
      

      yerr_minus[j]=(yerr_minus[j]/DeltaY)*Fac;
      yerr_plus[j]=(yerr_plus[j]/DeltaY)*Fac;
      
  
    }
  
  TGraphAsymmErrors *Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
											 p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerStyle(21);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerColor(1);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerSize(1.6);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetTitleOffset(1.6);
  //Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetRangeUser(0.000001,0.1);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetRangeUser(0.0001,100);
  
  TAxis *Xaxis1 = Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
  
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->CenterTitle();
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis()->CenterTitle();
  
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis()->SetTitle("p_{T}[GeV]");
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}#timesB(#mu^{+}#mu^{-})[pb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt;
  return OutGraph;
  
}

//*******************************************************
//*******************************************************
TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_Y2S_Rap12225_Pt()
{
  // D2(SIG)/DPT/DYRAP IN FB/GEV http://hepdata.cedar.ac.uk/view/ins1204994/first
  const int NN = 25;
  
  Double_t p8319_d1x1y1_xval[NN] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 
    9.5, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0, 
    29.0, 31.0, 34.0, 38.0, 45.0};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
    0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 
    1.0, 1.0, 2.0, 2.0, 5.0};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
    0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 
    1.0, 1.0, 2.0, 2.0, 5.0};
  
  Double_t p8319_d1x1y1_yval[NN] = {20172.01, 55920.85, 40941.32, 58286.08, 60111.3, 51690.28, 45008.54, 35739.85, 28268.04, 
    21814.99, 15238.53, 9156.52, 5854.1, 3272.03, 2019.04, 1366.64, 788.9, 685.27, 497.98, 
    263.42, 209.42, 145.07, 62.53, 31.98 }; 

  // Double_t p8319_d1x1y1_yerrminus[NN] = {3915.9007974794254, 10660.241072564917, 12853.494024929563, 14293.457798353062, 13238.90561274987, 11292.63679040905, 9961.513892185263, 8653.921212323346, 6430.445462843145, 
  //    5246.714875557847, 3297.1416707960852, 1967.388458693402, 1217.0259453273788, 705.8831526534685, 410.33545277004765, 246.36233255106188, 157.04912002300426, 101.24744243683392, 67.16017048816954, 
  //  44.87941398904402, 31.301439264033853, 17.62770830255595, 10.05802167426577, 3.9284348028190563, 1.1434159348198711};
  
  //Double_t p8319_d1x1y1_yerrplus[NN] = {3584.398011884283, 14539.50576821647, 48442.20717914285, 101196.61661934454, 106239.46591437947, 80524.4152455173, 58953.63710351805, 39473.663513499734, 22059.308130478617, 
  // 13904.259904140888, 7055.801357018209, 3287.4933701225923, 1749.2841637652814, 920.9084363279554, 497.0995806676968, 286.2217689135472, 173.65078692594514, 108.14296371008149, 70.38218595639098, 
  //  47.09316192399911, 32.442011343318406, 17.764475787368454, 10.074691062260918, 3.9676315353117153, 1.162497311824849};


  Double_t p8319_d1x1y1_yerrminus_syst[NN] = {1959.99, 7520.86, 4774.27, 8610.77, 5348.66, 3105.15, 1846.77, 1237.76, 755.17, 509.60, 359.40, 189.82, 103.57, 102.00, 44.81, 27.83, 16.31, 14.92, 12.85, 8.87, 6.84, 4.18, 2.76, 1.44, 0.0};
  
  Double_t p8319_d1x1y1_yerrplus_syst[NN] = {1959.99, 7520.86, 4774.27, 8610.77, 5348.66, 3105.15, 1846.77, 1237.76, 755.17, 509.60, 359.40, 189.82, 103.57, 102.00, 44.81, 27.83, 16.31, 14.92, 12.85, 8.87, 6.84, 4.18, 2.76, 1.44, 0.0};


  Double_t p8319_d1x1y1_yerrminus_stat[NN] = {713.38, 1479.21, 1989.83, 2433.03, 1808.08, 1532.13, 1281.64, 1033.83, 831.67, 
    713.14, 379.55, 245.98, 173.28, 139.9, 98.54, 62.35, 51.14, 48.35, 38.21, 
    32.8, 31.67, 14.22, 10.03, 4.73};
  
  Double_t p8319_d1x1y1_yerrplus_stat[NN] = {713.38, 1479.21, 1989.83, 2433.03, 1808.08, 1532.13, 1281.64, 1033.83, 831.67, 
    713.14, 379.55, 245.98, 173.28, 139.9, 98.54, 62.35, 51.14, 48.35, 38.21, 
    32.8, 31.67, 14.22, 10.03, 4.73};

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t DeltaY = 1;
   
  Double_t FeftoBarnToPicoBarn = 0.001;
  Double_t BR_Y3SToMuMu = 0.0218;

  Double_t Fac = FeftoBarnToPicoBarn;

  //Fac =1;

  for(int j=0;j<NN;j++)
    {
      p8319_d1x1y1_yval[j] =((p8319_d1x1y1_yval[j])/DeltaY)*Fac;
      

            yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j] + p8319_d1x1y1_yerrminus_stat[j]*p8319_d1x1y1_yerrminus_stat[j]);
            yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j] + p8319_d1x1y1_yerrplus_stat[j]*p8319_d1x1y1_yerrplus_stat[j]); 
      //      yerr_minus[j]=p8319_d1x1y1_yerrminus_stat[j];
      //      yerr_plus[j]=p8319_d1x1y1_yerrplus_stat[j]; 
      

      yerr_minus[j]=(yerr_minus[j]/DeltaY)*Fac;
      yerr_plus[j]=(yerr_plus[j]/DeltaY)*Fac;
      
  
    }
  
  TGraphAsymmErrors *Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
											 p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerStyle(21);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerColor(1);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerSize(1.6);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetTitleOffset(1.6);
  //Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetRangeUser(0.000001,0.1);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetRangeUser(0.0001,100);
  
  TAxis *Xaxis1 = Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
  
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->CenterTitle();
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis()->CenterTitle();
  
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis()->SetTitle("p_{T}[GeV]");
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}#timesB(#mu^{+}#mu^{-})[pb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt;
  return OutGraph;
  
}



//******************************************************************
//******************************************************************
TGraphAsymmErrors *Data_CMS_D2NDPtDy_Y2S_Rap24_Pt()
{
  // D2(SIG)/DPT/DYRAP IN FB/GEV http://hepdata.cedar.ac.uk/view/ins1204994/first
  const int NN = 16;

  Double_t pT_bin_val[NN] = {1.0, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 2.0, 1.5, 2.5, 4.0, 16.0};
  Double_t p8319_d1x1y1_xval[NN] = {0.656, 1.785, 3.214, 4.708, 6.217, 7.711, 9.206, 10.691, 12.213, 
    13.698, 15.222, 16.875, 18.757, 20.647, 23.688, 31.3};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.656, 0.7849999999999999, 0.714, 0.7080000000000002, 0.7169999999999996, 0.7110000000000003, 0.7059999999999995, 0.6910000000000007, 0.7129999999999992, 
    0.6980000000000004, 0.7219999999999995, 0.875, 0.7570000000000014, 1.1469999999999985, 1.6879999999999988, 5.300000000000001};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.344, 0.7150000000000001, 0.786, 0.7919999999999998, 0.7830000000000004, 0.7889999999999997, 0.7940000000000005, 0.8089999999999993, 0.7870000000000008, 
    0.8019999999999996, 0.7780000000000005, 1.125, 0.7429999999999986, 1.3530000000000015, 2.312000000000001, 10.7};
  
  Double_t p8319_d1x1y1_yval[NN] = {0.0829, 0.331, 0.409, 0.362, 0.286, 0.212, 0.146, 0.1123, 0.0765, 
    0.0519, 0.0376, 0.0373, 0.0159, 0.0204, 0.0158, 0.0126}; 

  Double_t p8319_d1x1y1_yerrminus[NN] = {0.008792041856133307, 0.024596747752497684, 0.02996664812754339, 0.025942243542145693, 0.021470910553583886, 0.014422205101855958, 0.01, 0.007402702209328699, 0.00562227711874824, 
    0.00412310562561766, 0.003996248240537617, 0.0032015621187164245, 0.0017691806012954132, 0.0021260291625469297, 0.0017029386365926401, 0.0014866068747318507};
  
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.00929623579735368, 0.03860051813123756, 0.03827531841800927, 0.030463092423455636, 0.022360679774997897, 0.018788294228055936, 0.012529964086141668, 0.009752948272189288, 0.006351377803280167, 
    0.004360045871318328, 0.003420526275297414, 0.0033600595232822885, 0.0017691806012954132, 0.0021260291625469297, 0.0017029386365926401, 0.0015620499351813306};


  Double_t p8319_d1x1y1_yerrminus_stat[NN] = {0.0049, 0.011, 0.013, 0.012, 0.01, 0.008, 0.006, 0.0046, 0.0035, 
    0.0026, 0.0021, 0.002, 0.0012, 0.0014, 0.0011, 0.001};
  
  Double_t p8319_d1x1y1_yerrplus_stat[NN] = {0.0049, 0.011, 0.013, 0.012, 0.01, 0.008, 0.006, 0.0046, 0.0035, 
    0.0026, 0.0021, 0.002, 0.0012, 0.0014, 0.0011, 0.001};

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t DeltaY = 4.8;
   
  Double_t FeftoBarnToPicoBarn = 0.001;
  Double_t NanoBarnToPicoBarn = 1000.0;
  Double_t BR_Y3SToMuMu = 0.0218;

  //  Double_t Fac = FeftoBarnToPicoBarn;
  Double_t Fac = NanoBarnToPicoBarn;
    //*PicoBarnToNanoBarn;

  //Fac =1;

  for(int j=0;j<NN;j++)
    {
      p8319_d1x1y1_yval[j] =((p8319_d1x1y1_yval[j])/(pT_bin_val[j]*DeltaY))*Fac;
      

            yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus[j]*p8319_d1x1y1_yerrminus[j] + p8319_d1x1y1_yerrminus_stat[j]*p8319_d1x1y1_yerrminus_stat[j]);
            yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus[j]*p8319_d1x1y1_yerrplus[j] + p8319_d1x1y1_yerrplus_stat[j]*p8319_d1x1y1_yerrplus_stat[j]); 
      //      yerr_minus[j]=p8319_d1x1y1_yerrminus_stat[j];
      //      yerr_plus[j]=p8319_d1x1y1_yerrplus_stat[j]; 
      

	    yerr_minus[j]=(yerr_minus[j]/(pT_bin_val[j]*DeltaY))*Fac;
	    yerr_plus[j]=(yerr_plus[j]/(pT_bin_val[j]*DeltaY))*Fac;

      
  
    }
  
  TGraphAsymmErrors *Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
											 p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerStyle(46);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerColor(2);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerSize(2.0);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetTitleOffset(1.6);
  //Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetRangeUser(0.000001,0.1);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetRangeUser(0.001,1000);
  
  TAxis *Xaxis1 = Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
  
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->CenterTitle();
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis()->CenterTitle();
  
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis()->SetTitle("p_{T}[GeV]");
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}#timesB(#mu^{+}#mu^{-})[pb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt;
  return OutGraph;
  
}


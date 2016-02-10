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

const Double_t mC = 1.6;
//=================== Fitted LDMEs ==================================//
//========= Our Values of fitted Psi(2S) LDME =========//
Double_t Psi2S_LDME_3S1_1 = 1.0;  
Double_t Psi2S_LDME_1S0_8 = 0.02639;
Double_t Psi2S_LDME_3S1_8 = 0.00190;

Double_t Psi2S_LDME_3P0_8 = mC*mC*Psi2S_LDME_1S0_8;
Double_t Psi2S_LDME_3P1_8 = 3.0*Psi2S_LDME_3P0_8;
Double_t Psi2S_LDME_3P2_8 = 5.0*Psi2S_LDME_3P0_8;
//========= Our Values of fitted Chic LDME =========//
Double_t Chic0_LDME_3P0_1 = 1.0;
Double_t Chic0_LDME_3S1_8 = 0.00160;
Double_t Chic1_LDME_3P1_1 = 1.0;
Double_t Chic1_LDME_3S1_8 = 0.00160;
Double_t Chic2_LDME_3P2_1 = 1.0;
Double_t Chic2_LDME_3S1_8 = 0.00160;
//=========================== BR =================//
Double_t BR_JPsiToMuMu = 0.0593;
Double_t BR_Psi2SToMuMu = 0.0078;
Double_t BR_Psi2SToJPsi = 0.595;
Double_t BR_ChiC0ToJPsi = 0.0116;
Double_t BR_ChiC1ToJPsi = 0.344;
Double_t BR_ChiC2ToJPsi = 0.195;



TGraphAsymmErrors *Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt();

void JPsiTotal()
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
  

  TLegend *legd0 = new TLegend(0.16,0.64,0.97,0.93);
  legd0->SetBorderSize(0);
  legd0->SetFillStyle(0);
  legd0->SetFillColor(0);
  legd0->SetTextSize(0.040);
  

  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);




 
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== GETTING LHCb 13 TeV DATA DATA ==========================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  TGraphAsymmErrors *grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt=new TGraphAsymmErrors();
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt=Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt();
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt->Draw("zAP");
  gPad->Update();





 
}











TGraphAsymmErrors *Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt()
{
  //
  const int NN = 14;
  // X value (pT)
  Double_t p8319_d1x1y1_xval[NN] = {0.0};
  Double_t p8319_d1x1y1_xvallow[NN] = {0.00, 1.00, 2.00, 3.00, 4.00, 5.00, 6.00, 7.00, 8.00, 9.00, 10.00, 11.00, 12.00, 13.00};
  Double_t p8319_d1x1y1_xvalhigh[NN] = {1.00, 2.00, 3.00, 4.00, 5.00, 6.00, 7.00, 8.00, 9.00, 10.00, 11.00, 12.00, 13.00, 14.00};
  
  // Y Value (B*dSigma/dpT)  
  Double_t p8319_d1x1y1_yval[NN] = {2198.00, 4237.00, 3600.00, 2301.00, 1326.00, 731.80, 394.90, 214.60, 121.60, 71.80, 42.60, 25.90, 16.40, 10.60};
  Double_t p8319_d1x1y1_ystatminus[NN] = {11.00, 15.00, 12.00, 9.00, 6.00, 4.00, 2.70, 1.90, 1.40, 1.00, 0.80, 0.60, 0.50, 0.40};
  Double_t p8319_d1x1y1_ystatplus[NN] = {11.00, 15.00, 12.00, 9.00, 6.00, 4.00, 2.70, 1.90, 1.40, 1.00, 0.80, 0.60, 0.50, 0.40};
  
  Double_t p8319_d1x1y1_ysystminus1[NN] = {17.00, 13.00, 13.00, 99.00, 96.00, 3.10, 3.80, 2.10, 0.90, 0.70, 0.40, 0.30, 0.20, 0.20};
  Double_t p8319_d1x1y1_ysystplus1[NN] = {17.00, 13.00, 13.00, 99.00, 96.00, 3.10, 3.80, 2.10, 0.90, 0.70, 0.40, 0.30, 0.20, 0.20};
  Double_t p8319_d1x1y1_ysystminus2[NN] = {127.00, 245.00, 202.00, 125.00, 69.00, 37.90, 20.30, 10.90, 6.20, 3.60, 2.20, 1.30, 0.80, 0.50};
  Double_t p8319_d1x1y1_ysystplus2[NN] = {127.00, 245.00, 202.00, 125.00, 69.00, 37.90, 20.30, 10.90, 6.20, 3.60, 2.20, 1.30, 0.80, 0.50};


  
  Double_t p8319_d1x1y1_ysystminus[NN] = {0.0};
  Double_t p8319_d1x1y1_ysystplus[NN] = {0.0};
  
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] =  {0.0};

  Double_t p8319_d1x1y1_xerrminus[NN]={0.0};
  Double_t p8319_d1x1y1_xerrplus[NN]={0.0};

  
  Double_t pbTonb =1.0;
  Double_t DeltaY = 2.5;
  
  for(int j=0;j<NN;j++){
    
    p8319_d1x1y1_xval[j]= 0.5*(p8319_d1x1y1_xvallow[j] + p8319_d1x1y1_xvalhigh[j]);
    p8319_d1x1y1_yval[j] =p8319_d1x1y1_yval[j];

    p8319_d1x1y1_xerrminus[j] = p8319_d1x1y1_xval[j] - p8319_d1x1y1_xvallow[j]; 
    p8319_d1x1y1_xerrplus[j] = p8319_d1x1y1_xvalhigh[j]-p8319_d1x1y1_xval[j];
    
    
    p8319_d1x1y1_ysystminus[j] = TMath::Sqrt((p8319_d1x1y1_ysystminus1[j]*p8319_d1x1y1_ysystminus1[j])+(p8319_d1x1y1_ysystminus2[j]*p8319_d1x1y1_ysystminus2[j]));
    p8319_d1x1y1_ysystplus[j] = TMath::Sqrt((p8319_d1x1y1_ysystplus1[j]*p8319_d1x1y1_ysystplus1[j])+(p8319_d1x1y1_ysystplus2[j]*p8319_d1x1y1_ysystplus2[j]));
    
    p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j]) + (p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
    p8319_d1x1y1_yerrplus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j]) + (p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
  
    p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j]*pbTonb)/DeltaY;
    p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j]*pbTonb)/DeltaY;
    p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j]*pbTonb)/DeltaY;
    p8319_d1x1y1_ystatminus[j]= (p8319_d1x1y1_ystatminus[j]*pbTonb)/DeltaY;
    p8319_d1x1y1_ystatplus[j]=(p8319_d1x1y1_ystatplus[j]*pbTonb)/DeltaY;
  }


  TGraphAsymmErrors *Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->SetMarkerStyle(22);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->SetMarkerColor(8);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->SetMarkerSize(1.6);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetRangeUser(1.0,10000.0);
  
  TAxis *Xaxis1 = Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,15.0);
   

  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt;
  return OutGraph;
  
}

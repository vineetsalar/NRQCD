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

void Draw_CMS_D2NDPtDy_PromptJPsi_Y0012_Latest_Pt(TLegend *lgd);
void Draw_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt(TLegend *lgd);
void Draw_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt(TLegend *lgd);

void Draw_ATLAS_D2NDPtDy_PromptJPsi_Y00075_Pt(TLegend *lgd);

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


  //=========================== BR =================//
  Double_t BR_JPsiToMuMu = 0.0593;
  Double_t BR_Psi2SToMuMu = 0.0078;

  Double_t BR_Psi2SToJPsi = 0.595;
  Double_t BR_ChiC0ToJPsi = 0.0116;
  Double_t BR_ChiC1ToJPsi = 0.344;
  Double_t BR_ChiC2ToJPsi = 0.195;

  

  TFile *file_JPsiCrossSection =  new TFile("JPsiCrossSection.root","R");

  

  TGraph *JPsi_grDSigmaDPtDY_ModY090_Pt =(TGraph*)file_JPsiCrossSection->Get("grDSigmaDPtDY_ModY090_Pt");
  JPsi_grDSigmaDPtDY_ModY090_Pt->SetName("JPsi_grDSigmaDPtDY_ModY090_Pt");
  JPsi_grDSigmaDPtDY_ModY090_Pt->SetTitle("JPsi_grDSigmaDPtDY_ModY090_Pt");
  JPsi_grDSigmaDPtDY_ModY090_Pt->SetLineWidth(2);
  JPsi_grDSigmaDPtDY_ModY090_Pt->SetLineColor(4);
  JPsi_grDSigmaDPtDY_ModY090_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  JPsi_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  
  
  TGraph *TotalJPsi_grDSigmaDPtDY_ModY090_Pt=(TGraph*)JPsi_grDSigmaDPtDY_ModY090_Pt->Clone();
  TotalJPsi_grDSigmaDPtDY_ModY090_Pt->SetName("JPsi_grDSigmaDPtDY_ModY090_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY090_Pt->SetTitle("JPsi_grDSigmaDPtDY_ModY090_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY090_Pt->SetLineWidth(2);
  TotalJPsi_grDSigmaDPtDY_ModY090_Pt->SetLineColor(2);
  TotalJPsi_grDSigmaDPtDY_ModY090_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalJPsi_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");

  
  //grDSigmaDPtDY_ModY075_Pt
  
  TGraph *JPsi_grDSigmaDPtDY_ModY075_Pt =(TGraph*)file_JPsiCrossSection->Get("grDSigmaDPtDY_ModY075_Pt");
  JPsi_grDSigmaDPtDY_ModY075_Pt->SetName("JPsi_grDSigmaDPtDY_ModY075_Pt");
  JPsi_grDSigmaDPtDY_ModY075_Pt->SetTitle("JPsi_grDSigmaDPtDY_ModY075_Pt");
  JPsi_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  JPsi_grDSigmaDPtDY_ModY075_Pt->SetLineColor(4);
  JPsi_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  JPsi_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  
  TGraph *TotalJPsi_grDSigmaDPtDY_ModY075_Pt=(TGraph*)JPsi_grDSigmaDPtDY_ModY075_Pt->Clone();
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->SetName("JPsi_grDSigmaDPtDY_ModY075_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->SetTitle("JPsi_grDSigmaDPtDY_ModY075_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->SetLineColor(2);
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");

  //grDSigmaDPtDY_ModY075To24_Pt

  TGraph *JPsi_grDSigmaDPtDY_ModY075To24_Pt =(TGraph*)file_JPsiCrossSection->Get("grDSigmaDPtDY_ModY075To24_Pt");
  JPsi_grDSigmaDPtDY_ModY075To24_Pt->SetName("JPsi_grDSigmaDPtDY_ModY075To24_Pt");
  JPsi_grDSigmaDPtDY_ModY075To24_Pt->SetTitle("JPsi_grDSigmaDPtDY_ModY075To24_Pt");
  JPsi_grDSigmaDPtDY_ModY075To24_Pt->SetLineWidth(2);
  JPsi_grDSigmaDPtDY_ModY075To24_Pt->SetLineColor(4);
  JPsi_grDSigmaDPtDY_ModY075To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  JPsi_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  
  TGraph *TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt=(TGraph*)JPsi_grDSigmaDPtDY_ModY075To24_Pt->Clone();
  TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->SetName("JPsi_grDSigmaDPtDY_ModY075To24_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->SetTitle("JPsi_grDSigmaDPtDY_ModY075To24_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->SetLineWidth(2);
  TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->SetLineColor(2);
  TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");


  //grDSigmaDPtDY_ModY090To24_Pt

  TGraph *JPsi_grDSigmaDPtDY_ModY090To24_Pt =(TGraph*)file_JPsiCrossSection->Get("grDSigmaDPtDY_ModY090To24_Pt");
  JPsi_grDSigmaDPtDY_ModY090To24_Pt->SetName("JPsi_grDSigmaDPtDY_ModY090To24_Pt");
  JPsi_grDSigmaDPtDY_ModY090To24_Pt->SetTitle("JPsi_grDSigmaDPtDY_ModY090To24_Pt");
  JPsi_grDSigmaDPtDY_ModY090To24_Pt->SetLineWidth(2);
  JPsi_grDSigmaDPtDY_ModY090To24_Pt->SetLineColor(4);
  JPsi_grDSigmaDPtDY_ModY090To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  JPsi_grDSigmaDPtDY_ModY090To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  
  TGraph *TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt=(TGraph*)JPsi_grDSigmaDPtDY_ModY090To24_Pt->Clone();
  TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->SetName("JPsi_grDSigmaDPtDY_ModY090To24_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->SetTitle("JPsi_grDSigmaDPtDY_ModY090To24_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->SetLineWidth(2);
  TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->SetLineColor(2);
  TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");




  //grDSigmaDPtDY_Y25To40_Pt

  TGraph *JPsi_grDSigmaDPtDY_Y25To40_Pt =(TGraph*)file_JPsiCrossSection->Get("grDSigmaDPtDY_Y25To40_Pt");
  JPsi_grDSigmaDPtDY_Y25To40_Pt->SetName("JPsi_grDSigmaDPtDY_Y25To40_Pt");
  JPsi_grDSigmaDPtDY_Y25To40_Pt->SetTitle("JPsi_grDSigmaDPtDY_Y25To40_Pt");
  JPsi_grDSigmaDPtDY_Y25To40_Pt->SetLineWidth(2);
  JPsi_grDSigmaDPtDY_Y25To40_Pt->SetLineColor(4);
  JPsi_grDSigmaDPtDY_Y25To40_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  JPsi_grDSigmaDPtDY_Y25To40_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  
  TGraph *TotalJPsi_grDSigmaDPtDY_Y25To40_Pt=(TGraph*)JPsi_grDSigmaDPtDY_Y25To40_Pt->Clone();
  TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->SetName("JPsi_grDSigmaDPtDY_Y25To40_Pt");
  TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->SetTitle("JPsi_grDSigmaDPtDY_Y25To40_Pt");
  TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->SetLineWidth(2);
  TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->SetLineColor(2);
  TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");




  //================================================= Get All Graphs from Psi(2S) =====================================//


  TFile *file_Psi2SCrossSection =  new TFile("Psi2SCrossSection.root","R");

  TGraph *Psi2S_grDSigmaDPtDY_ModY090_Pt =(TGraph*)file_Psi2SCrossSection->Get("grDSigmaDPtDY_ModY090_Pt");
  Psi2S_grDSigmaDPtDY_ModY090_Pt->SetName("Psi2S_grDSigmaDPtDY_ModY090_Pt");
  Psi2S_grDSigmaDPtDY_ModY090_Pt->SetTitle("Psi2S_grDSigmaDPtDY_ModY090_Pt");
  Psi2S_grDSigmaDPtDY_ModY090_Pt->SetLineWidth(2);
  Psi2S_grDSigmaDPtDY_ModY090_Pt->SetLineColor(6);
  Psi2S_grDSigmaDPtDY_ModY090_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  Psi2S_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");



 //grDSigmaDPtDY_ModY075_Pt
  
  TGraph *Psi2S_grDSigmaDPtDY_ModY075_Pt =(TGraph*)file_Psi2SCrossSection->Get("grDSigmaDPtDY_ModY075_Pt");
  Psi2S_grDSigmaDPtDY_ModY075_Pt->SetName("Psi2S_grDSigmaDPtDY_ModY075_Pt");
  Psi2S_grDSigmaDPtDY_ModY075_Pt->SetTitle("Psi2S_grDSigmaDPtDY_ModY075_Pt");
  Psi2S_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  Psi2S_grDSigmaDPtDY_ModY075_Pt->SetLineColor(6);
  Psi2S_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  Psi2S_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  //grDSigmaDPtDY_ModY075To24_Pt

  TGraph *Psi2S_grDSigmaDPtDY_ModY075To24_Pt =(TGraph*)file_Psi2SCrossSection->Get("grDSigmaDPtDY_ModY075To24_Pt");
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->SetName("Psi2S_grDSigmaDPtDY_ModY075To24_Pt");
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->SetTitle("Psi2S_grDSigmaDPtDY_ModY075To24_Pt");
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->SetLineWidth(2);
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->SetLineColor(6);
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  //grDSigmaDPtDY_ModY090To24_Pt

  TGraph *Psi2S_grDSigmaDPtDY_ModY090To24_Pt =(TGraph*)file_Psi2SCrossSection->Get("grDSigmaDPtDY_ModY090To24_Pt");
  Psi2S_grDSigmaDPtDY_ModY090To24_Pt->SetName("Psi2S_grDSigmaDPtDY_ModY090To24_Pt");
  Psi2S_grDSigmaDPtDY_ModY090To24_Pt->SetTitle("Psi2S_grDSigmaDPtDY_ModY090To24_Pt");
  Psi2S_grDSigmaDPtDY_ModY090To24_Pt->SetLineWidth(2);
  Psi2S_grDSigmaDPtDY_ModY090To24_Pt->SetLineColor(6);
  Psi2S_grDSigmaDPtDY_ModY090To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  Psi2S_grDSigmaDPtDY_ModY090To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  


  //grDSigmaDPtDY_Y25To40_Pt

  TGraph *Psi2S_grDSigmaDPtDY_Y25To40_Pt =(TGraph*)file_Psi2SCrossSection->Get("grDSigmaDPtDY_Y25To40_Pt");
  Psi2S_grDSigmaDPtDY_Y25To40_Pt->SetName("Psi2S_grDSigmaDPtDY_Y25To40_Pt");
  Psi2S_grDSigmaDPtDY_Y25To40_Pt->SetTitle("Psi2S_grDSigmaDPtDY_Y25To40_Pt");
  Psi2S_grDSigmaDPtDY_Y25To40_Pt->SetLineWidth(2);
  Psi2S_grDSigmaDPtDY_Y25To40_Pt->SetLineColor(6);
  Psi2S_grDSigmaDPtDY_Y25To40_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  Psi2S_grDSigmaDPtDY_Y25To40_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  





 
 
  TFile *file_ChiC0CrossSection =  new TFile("Chic0_1PCrossSection.root","R");

  TGraph *ChiC0_grDSigmaDPtDY_ModY090_Pt =(TGraph*)file_ChiC0CrossSection->Get("grDSigmaDPtDY_ModY090_Pt");
  ChiC0_grDSigmaDPtDY_ModY090_Pt->SetName("ChiC0_grDSigmaDPtDY_ModY090_Pt");
  ChiC0_grDSigmaDPtDY_ModY090_Pt->SetTitle("ChiC0_grDSigmaDPtDY_ModY090_Pt");
  ChiC0_grDSigmaDPtDY_ModY090_Pt->SetLineWidth(2);
  ChiC0_grDSigmaDPtDY_ModY090_Pt->SetLineColor(7);
  ChiC0_grDSigmaDPtDY_ModY090_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC0_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");




 //grDSigmaDPtDY_ModY075_Pt
  
  TGraph *ChiC0_grDSigmaDPtDY_ModY075_Pt =(TGraph*)file_ChiC0CrossSection->Get("grDSigmaDPtDY_ModY075_Pt");
  ChiC0_grDSigmaDPtDY_ModY075_Pt->SetName("ChiC0_grDSigmaDPtDY_ModY075_Pt");
  ChiC0_grDSigmaDPtDY_ModY075_Pt->SetTitle("ChiC0_grDSigmaDPtDY_ModY075_Pt");
  ChiC0_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  ChiC0_grDSigmaDPtDY_ModY075_Pt->SetLineColor(7);
  ChiC0_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC0_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  //grDSigmaDPtDY_ModY075To24_Pt

  TGraph *ChiC0_grDSigmaDPtDY_ModY075To24_Pt =(TGraph*)file_ChiC0CrossSection->Get("grDSigmaDPtDY_ModY075To24_Pt");
  ChiC0_grDSigmaDPtDY_ModY075To24_Pt->SetName("ChiC0_grDSigmaDPtDY_ModY075To24_Pt");
  ChiC0_grDSigmaDPtDY_ModY075To24_Pt->SetTitle("ChiC0_grDSigmaDPtDY_ModY075To24_Pt");
  ChiC0_grDSigmaDPtDY_ModY075To24_Pt->SetLineWidth(2);
  ChiC0_grDSigmaDPtDY_ModY075To24_Pt->SetLineColor(7);
  ChiC0_grDSigmaDPtDY_ModY075To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC0_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  //grDSigmaDPtDY_ModY090To24_Pt

  TGraph *ChiC0_grDSigmaDPtDY_ModY090To24_Pt =(TGraph*)file_ChiC0CrossSection->Get("grDSigmaDPtDY_ModY090To24_Pt");
  ChiC0_grDSigmaDPtDY_ModY090To24_Pt->SetName("ChiC0_grDSigmaDPtDY_ModY090To24_Pt");
  ChiC0_grDSigmaDPtDY_ModY090To24_Pt->SetTitle("ChiC0_grDSigmaDPtDY_ModY090To24_Pt");
  ChiC0_grDSigmaDPtDY_ModY090To24_Pt->SetLineWidth(2);
  ChiC0_grDSigmaDPtDY_ModY090To24_Pt->SetLineColor(7);
  ChiC0_grDSigmaDPtDY_ModY090To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC0_grDSigmaDPtDY_ModY090To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  


  //grDSigmaDPtDY_Y25To40_Pt

  TGraph *ChiC0_grDSigmaDPtDY_Y25To40_Pt =(TGraph*)file_ChiC0CrossSection->Get("grDSigmaDPtDY_Y25To40_Pt");
  ChiC0_grDSigmaDPtDY_Y25To40_Pt->SetName("ChiC0_grDSigmaDPtDY_Y25To40_Pt");
  ChiC0_grDSigmaDPtDY_Y25To40_Pt->SetTitle("ChiC0_grDSigmaDPtDY_Y25To40_Pt");
  ChiC0_grDSigmaDPtDY_Y25To40_Pt->SetLineWidth(2);
  ChiC0_grDSigmaDPtDY_Y25To40_Pt->SetLineColor(7);
  ChiC0_grDSigmaDPtDY_Y25To40_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC0_grDSigmaDPtDY_Y25To40_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  



  

  TFile *file_ChiC1CrossSection =  new TFile("Chic1_1PCrossSection.root","R");

  TGraph *ChiC1_grDSigmaDPtDY_ModY090_Pt =(TGraph*)file_ChiC1CrossSection->Get("grDSigmaDPtDY_ModY090_Pt");
  ChiC1_grDSigmaDPtDY_ModY090_Pt->SetName("ChiC1_grDSigmaDPtDY_ModY090_Pt");
  ChiC1_grDSigmaDPtDY_ModY090_Pt->SetTitle("ChiC1_grDSigmaDPtDY_ModY090_Pt");
  ChiC1_grDSigmaDPtDY_ModY090_Pt->SetLineWidth(2);
  ChiC1_grDSigmaDPtDY_ModY090_Pt->SetLineColor(9);
  ChiC1_grDSigmaDPtDY_ModY090_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC1_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");



 //grDSigmaDPtDY_ModY075_Pt
  
  TGraph *ChiC1_grDSigmaDPtDY_ModY075_Pt =(TGraph*)file_ChiC1CrossSection->Get("grDSigmaDPtDY_ModY075_Pt");
  ChiC1_grDSigmaDPtDY_ModY075_Pt->SetName("ChiC1_grDSigmaDPtDY_ModY075_Pt");
  ChiC1_grDSigmaDPtDY_ModY075_Pt->SetTitle("ChiC1_grDSigmaDPtDY_ModY075_Pt");
  ChiC1_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  ChiC1_grDSigmaDPtDY_ModY075_Pt->SetLineColor(9);
  ChiC1_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC1_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  //grDSigmaDPtDY_ModY075To24_Pt

  TGraph *ChiC1_grDSigmaDPtDY_ModY075To24_Pt =(TGraph*)file_ChiC1CrossSection->Get("grDSigmaDPtDY_ModY075To24_Pt");
  ChiC1_grDSigmaDPtDY_ModY075To24_Pt->SetName("ChiC1_grDSigmaDPtDY_ModY075To24_Pt");
  ChiC1_grDSigmaDPtDY_ModY075To24_Pt->SetTitle("ChiC1_grDSigmaDPtDY_ModY075To24_Pt");
  ChiC1_grDSigmaDPtDY_ModY075To24_Pt->SetLineWidth(2);
  ChiC1_grDSigmaDPtDY_ModY075To24_Pt->SetLineColor(9);
  ChiC1_grDSigmaDPtDY_ModY075To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC1_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  //grDSigmaDPtDY_ModY090To24_Pt

  TGraph *ChiC1_grDSigmaDPtDY_ModY090To24_Pt =(TGraph*)file_ChiC1CrossSection->Get("grDSigmaDPtDY_ModY090To24_Pt");
  ChiC1_grDSigmaDPtDY_ModY090To24_Pt->SetName("ChiC1_grDSigmaDPtDY_ModY090To24_Pt");
  ChiC1_grDSigmaDPtDY_ModY090To24_Pt->SetTitle("ChiC1_grDSigmaDPtDY_ModY090To24_Pt");
  ChiC1_grDSigmaDPtDY_ModY090To24_Pt->SetLineWidth(2);
  ChiC1_grDSigmaDPtDY_ModY090To24_Pt->SetLineColor(9);
  ChiC1_grDSigmaDPtDY_ModY090To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC1_grDSigmaDPtDY_ModY090To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  


  //grDSigmaDPtDY_Y25To40_Pt

  TGraph *ChiC1_grDSigmaDPtDY_Y25To40_Pt =(TGraph*)file_ChiC1CrossSection->Get("grDSigmaDPtDY_Y25To40_Pt");
  ChiC1_grDSigmaDPtDY_Y25To40_Pt->SetName("ChiC1_grDSigmaDPtDY_Y25To40_Pt");
  ChiC1_grDSigmaDPtDY_Y25To40_Pt->SetTitle("ChiC1_grDSigmaDPtDY_Y25To40_Pt");
  ChiC1_grDSigmaDPtDY_Y25To40_Pt->SetLineWidth(2);
  ChiC1_grDSigmaDPtDY_Y25To40_Pt->SetLineColor(9);
  ChiC1_grDSigmaDPtDY_Y25To40_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC1_grDSigmaDPtDY_Y25To40_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  




  TFile *file_ChiC2CrossSection =  new TFile("Chic2_1PCrossSection.root","R");

  TGraph *ChiC2_grDSigmaDPtDY_ModY090_Pt =(TGraph*)file_ChiC2CrossSection->Get("grDSigmaDPtDY_ModY090_Pt");
  ChiC2_grDSigmaDPtDY_ModY090_Pt->SetName("ChiC2_grDSigmaDPtDY_ModY090_Pt");
  ChiC2_grDSigmaDPtDY_ModY090_Pt->SetTitle("ChiC2_grDSigmaDPtDY_ModY090_Pt");
  ChiC2_grDSigmaDPtDY_ModY090_Pt->SetLineWidth(2);
  ChiC2_grDSigmaDPtDY_ModY090_Pt->SetLineColor(12);
  ChiC2_grDSigmaDPtDY_ModY090_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC2_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");


//grDSigmaDPtDY_ModY075_Pt
  
  TGraph *ChiC2_grDSigmaDPtDY_ModY075_Pt =(TGraph*)file_ChiC2CrossSection->Get("grDSigmaDPtDY_ModY075_Pt");
  ChiC2_grDSigmaDPtDY_ModY075_Pt->SetName("ChiC2_grDSigmaDPtDY_ModY075_Pt");
  ChiC2_grDSigmaDPtDY_ModY075_Pt->SetTitle("ChiC2_grDSigmaDPtDY_ModY075_Pt");
  ChiC2_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  ChiC2_grDSigmaDPtDY_ModY075_Pt->SetLineColor(12);
  ChiC2_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC2_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  //grDSigmaDPtDY_ModY075To24_Pt

  TGraph *ChiC2_grDSigmaDPtDY_ModY075To24_Pt =(TGraph*)file_ChiC2CrossSection->Get("grDSigmaDPtDY_ModY075To24_Pt");
  ChiC2_grDSigmaDPtDY_ModY075To24_Pt->SetName("ChiC2_grDSigmaDPtDY_ModY075To24_Pt");
  ChiC2_grDSigmaDPtDY_ModY075To24_Pt->SetTitle("ChiC2_grDSigmaDPtDY_ModY075To24_Pt");
  ChiC2_grDSigmaDPtDY_ModY075To24_Pt->SetLineWidth(2);
  ChiC2_grDSigmaDPtDY_ModY075To24_Pt->SetLineColor(12);
  ChiC2_grDSigmaDPtDY_ModY075To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC2_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  //grDSigmaDPtDY_ModY090To24_Pt

  TGraph *ChiC2_grDSigmaDPtDY_ModY090To24_Pt =(TGraph*)file_ChiC2CrossSection->Get("grDSigmaDPtDY_ModY090To24_Pt");
  ChiC2_grDSigmaDPtDY_ModY090To24_Pt->SetName("ChiC2_grDSigmaDPtDY_ModY090To24_Pt");
  ChiC2_grDSigmaDPtDY_ModY090To24_Pt->SetTitle("ChiC2_grDSigmaDPtDY_ModY090To24_Pt");
  ChiC2_grDSigmaDPtDY_ModY090To24_Pt->SetLineWidth(2);
  ChiC2_grDSigmaDPtDY_ModY090To24_Pt->SetLineColor(12);
  ChiC2_grDSigmaDPtDY_ModY090To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC2_grDSigmaDPtDY_ModY090To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  


  //grDSigmaDPtDY_Y25To40_Pt

  TGraph *ChiC2_grDSigmaDPtDY_Y25To40_Pt =(TGraph*)file_ChiC2CrossSection->Get("grDSigmaDPtDY_Y25To40_Pt");
  ChiC2_grDSigmaDPtDY_Y25To40_Pt->SetName("ChiC2_grDSigmaDPtDY_Y25To40_Pt");
  ChiC2_grDSigmaDPtDY_Y25To40_Pt->SetTitle("ChiC2_grDSigmaDPtDY_Y25To40_Pt");
  ChiC2_grDSigmaDPtDY_Y25To40_Pt->SetLineWidth(2);
  ChiC2_grDSigmaDPtDY_Y25To40_Pt->SetLineColor(12);
  ChiC2_grDSigmaDPtDY_Y25To40_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  ChiC2_grDSigmaDPtDY_Y25To40_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");


  //==========================================================================================================//
  //======================================= Plot 1 ==========================================================//
  //========================================================================================================//

  for (int j=0; j < JPsi_grDSigmaDPtDY_ModY090_Pt->GetN();++j){
    
    Double_t Pt, DirectJPsi,DirectPsi2S,DirectChiC0, DirectChiC1,DirectChiC2;
    Double_t TotalJPsi;
    
    JPsi_grDSigmaDPtDY_ModY090_Pt->GetPoint(j,Pt,DirectJPsi);
    Psi2S_grDSigmaDPtDY_ModY090_Pt->GetPoint(j,Pt,DirectPsi2S);

    ChiC0_grDSigmaDPtDY_ModY090_Pt->GetPoint(j,Pt,DirectChiC0);
    ChiC1_grDSigmaDPtDY_ModY090_Pt->GetPoint(j,Pt,DirectChiC1);
    ChiC2_grDSigmaDPtDY_ModY090_Pt->GetPoint(j,Pt,DirectChiC2);

    Double_t DY = 1.8;
    TotalJPsi = (DirectJPsi*BR_JPsiToMuMu + DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu + DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu 
		 + DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu+DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu)/DY;
    
    TotalJPsi_grDSigmaDPtDY_ModY090_Pt->SetPoint(j,Pt,TotalJPsi);
    
    JPsi_grDSigmaDPtDY_ModY090_Pt->SetPoint(j,Pt,DirectJPsi*BR_JPsiToMuMu/DY);
    Psi2S_grDSigmaDPtDY_ModY090_Pt->SetPoint(j,Pt,DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu/DY);
    
    ChiC0_grDSigmaDPtDY_ModY090_Pt->SetPoint(j,Pt,DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu/DY);
    ChiC1_grDSigmaDPtDY_ModY090_Pt->SetPoint(j,Pt,DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu/DY);
    ChiC2_grDSigmaDPtDY_ModY090_Pt->SetPoint(j,Pt,DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu/DY);
  }

  TLegend *lgd_DSigmaDPtDY_ModY090_Pt = new TLegend(0.40,0.60,0.90,0.92);
  lgd_DSigmaDPtDY_ModY090_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_ModY090_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_ModY090_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_ModY090_Pt->SetTextSize(0.03);
  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  
  Draw_CMS_D2NDPtDy_PromptJPsi_Y0012_Latest_Pt(lgd_DSigmaDPtDY_ModY090_Pt);
  //Draw_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt(lgd_DSigmaDPtDY_ModY090_Pt);

  lgd_DSigmaDPtDY_ModY090_Pt->AddEntry(TotalJPsi_grDSigmaDPtDY_ModY090_Pt,"NRQCD, Prompt J/#psi","L");
  lgd_DSigmaDPtDY_ModY090_Pt->AddEntry(JPsi_grDSigmaDPtDY_ModY090_Pt,"NRQCD, Direct J/#psi","L");
  lgd_DSigmaDPtDY_ModY090_Pt->AddEntry(Psi2S_grDSigmaDPtDY_ModY090_Pt,"NRQCD, J/#psi from #psi(2S)","L");
  lgd_DSigmaDPtDY_ModY090_Pt->AddEntry(ChiC0_grDSigmaDPtDY_ModY090_Pt,"NRQCD, J/#psi from #chi_{c0}","L");
  lgd_DSigmaDPtDY_ModY090_Pt->AddEntry(ChiC1_grDSigmaDPtDY_ModY090_Pt,"NRQCD, J/#psi from #chi_{c1}","L");
  lgd_DSigmaDPtDY_ModY090_Pt->AddEntry(ChiC2_grDSigmaDPtDY_ModY090_Pt,"NRQCD, J/#psi from #chi_{c2}","L");


  TotalJPsi_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitleOffset(1.6);
   
  TotalJPsi_grDSigmaDPtDY_ModY090_Pt->Draw("Csame");
  JPsi_grDSigmaDPtDY_ModY090_Pt->Draw("Csame");
  Psi2S_grDSigmaDPtDY_ModY090_Pt->Draw("Csame");
  
  ChiC0_grDSigmaDPtDY_ModY090_Pt->Draw("Csame");
  ChiC1_grDSigmaDPtDY_ModY090_Pt->Draw("Csame");
  ChiC2_grDSigmaDPtDY_ModY090_Pt->Draw("Csame");
  lgd_DSigmaDPtDY_ModY090_Pt->Draw("same");
  gPad->SaveAs("Fig1a_JPsi_CMS_Y090_S7TeV.pdf");



  //==========================================================================================================//
  //======================================= Plot 2 ==========================================================//
  //========================================================================================================//

  for (int j=0; j < JPsi_grDSigmaDPtDY_ModY075_Pt->GetN();++j){
    
    Double_t Pt, DirectJPsi,DirectPsi2S,DirectChiC0, DirectChiC1,DirectChiC2;
    Double_t TotalJPsi;
    
    JPsi_grDSigmaDPtDY_ModY075_Pt->GetPoint(j,Pt,DirectJPsi);
    Psi2S_grDSigmaDPtDY_ModY075_Pt->GetPoint(j,Pt,DirectPsi2S);

    ChiC0_grDSigmaDPtDY_ModY075_Pt->GetPoint(j,Pt,DirectChiC0);
    ChiC1_grDSigmaDPtDY_ModY075_Pt->GetPoint(j,Pt,DirectChiC1);
    ChiC2_grDSigmaDPtDY_ModY075_Pt->GetPoint(j,Pt,DirectChiC2);

    Double_t DY = 1.5;
    TotalJPsi = (DirectJPsi*BR_JPsiToMuMu + DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu + DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu 
		 + DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu+DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu)/DY;
    
    TotalJPsi_grDSigmaDPtDY_ModY075_Pt->SetPoint(j,Pt,TotalJPsi);
    
    JPsi_grDSigmaDPtDY_ModY075_Pt->SetPoint(j,Pt,DirectJPsi*BR_JPsiToMuMu/DY);
    Psi2S_grDSigmaDPtDY_ModY075_Pt->SetPoint(j,Pt,DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu/DY);
    
    ChiC0_grDSigmaDPtDY_ModY075_Pt->SetPoint(j,Pt,DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu/DY);
    ChiC1_grDSigmaDPtDY_ModY075_Pt->SetPoint(j,Pt,DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu/DY);
    ChiC2_grDSigmaDPtDY_ModY075_Pt->SetPoint(j,Pt,DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu/DY);
  }

  TLegend *lgd_DSigmaDPtDY_ModY075_Pt = new TLegend(0.40,0.60,0.90,0.92);
  lgd_DSigmaDPtDY_ModY075_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_ModY075_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_ModY075_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_ModY075_Pt->SetTextSize(0.03);
  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);

  Draw_ATLAS_D2NDPtDy_PromptJPsi_Y00075_Pt(lgd_DSigmaDPtDY_ModY075_Pt);
  
  lgd_DSigmaDPtDY_ModY075_Pt->AddEntry(TotalJPsi_grDSigmaDPtDY_ModY075_Pt,"NRQCD, Prompt J/#psi","L");
  lgd_DSigmaDPtDY_ModY075_Pt->AddEntry(JPsi_grDSigmaDPtDY_ModY075_Pt,"NRQCD, Direct J/#psi","L");
  lgd_DSigmaDPtDY_ModY075_Pt->AddEntry(Psi2S_grDSigmaDPtDY_ModY075_Pt,"NRQCD, J/#psi from #psi(2S)","L");
  lgd_DSigmaDPtDY_ModY075_Pt->AddEntry(ChiC0_grDSigmaDPtDY_ModY075_Pt,"NRQCD, J/#psi from #chi_{c0}","L");
  lgd_DSigmaDPtDY_ModY075_Pt->AddEntry(ChiC1_grDSigmaDPtDY_ModY075_Pt,"NRQCD, J/#psi from #chi_{c1}","L");
  lgd_DSigmaDPtDY_ModY075_Pt->AddEntry(ChiC2_grDSigmaDPtDY_ModY075_Pt,"NRQCD, J/#psi from #chi_{c2}","L");


  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitleOffset(1.6);
   
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->Draw("Csame");
  JPsi_grDSigmaDPtDY_ModY075_Pt->Draw("Csame");
  Psi2S_grDSigmaDPtDY_ModY075_Pt->Draw("Csame");
  
  ChiC0_grDSigmaDPtDY_ModY075_Pt->Draw("Csame");
  ChiC1_grDSigmaDPtDY_ModY075_Pt->Draw("Csame");
  ChiC2_grDSigmaDPtDY_ModY075_Pt->Draw("Csame");
  lgd_DSigmaDPtDY_ModY075_Pt->Draw("same");
  gPad->SaveAs("Fig1b_JPsi_ATLAS_Y075_S7TeV.pdf");



  //grDSigmaDPtDY_ModY075To24_Pt
  //==========================================================================================================//
  //======================================= Plot 3 ==========================================================//
  //========================================================================================================//


  for (int j=0; j < JPsi_grDSigmaDPtDY_ModY075To24_Pt->GetN();++j){
    
    Double_t Pt, DirectJPsi,DirectPsi2S,DirectChiC0, DirectChiC1,DirectChiC2;
    Double_t TotalJPsi;
    
    JPsi_grDSigmaDPtDY_ModY075To24_Pt->GetPoint(j,Pt,DirectJPsi);
    Psi2S_grDSigmaDPtDY_ModY075To24_Pt->GetPoint(j,Pt,DirectPsi2S);

    ChiC0_grDSigmaDPtDY_ModY075To24_Pt->GetPoint(j,Pt,DirectChiC0);
    ChiC1_grDSigmaDPtDY_ModY075To24_Pt->GetPoint(j,Pt,DirectChiC1);
    ChiC2_grDSigmaDPtDY_ModY075To24_Pt->GetPoint(j,Pt,DirectChiC2);

    Double_t DY = 3.3;
    TotalJPsi = (DirectJPsi*BR_JPsiToMuMu + DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu + DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu 
		 + DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu+DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu)/DY;
    
    TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->SetPoint(j,Pt,TotalJPsi);
    
    JPsi_grDSigmaDPtDY_ModY075To24_Pt->SetPoint(j,Pt,DirectJPsi*BR_JPsiToMuMu/DY);
    Psi2S_grDSigmaDPtDY_ModY075To24_Pt->SetPoint(j,Pt,DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu/DY);
    
    ChiC0_grDSigmaDPtDY_ModY075To24_Pt->SetPoint(j,Pt,DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu/DY);
    ChiC1_grDSigmaDPtDY_ModY075To24_Pt->SetPoint(j,Pt,DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu/DY);
    ChiC2_grDSigmaDPtDY_ModY075To24_Pt->SetPoint(j,Pt,DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu/DY);
  }

  TLegend *lgd_DSigmaDPtDY_ModY075To24_Pt = new TLegend(0.40,0.60,0.90,0.92);
  lgd_DSigmaDPtDY_ModY075To24_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_ModY075To24_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_ModY075To24_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_ModY075To24_Pt->SetTextSize(0.03);
  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Draw_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt(lgd_DSigmaDPtDY_ModY075To24_Pt);

  lgd_DSigmaDPtDY_ModY075To24_Pt->AddEntry(TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt,"NRQCD, Prompt J/#psi","L");
  lgd_DSigmaDPtDY_ModY075To24_Pt->AddEntry(JPsi_grDSigmaDPtDY_ModY075To24_Pt,"NRQCD, Direct J/#psi","L");
  lgd_DSigmaDPtDY_ModY075To24_Pt->AddEntry(Psi2S_grDSigmaDPtDY_ModY075To24_Pt,"NRQCD, J/#psi from #psi(2S)","L");
  lgd_DSigmaDPtDY_ModY075To24_Pt->AddEntry(ChiC0_grDSigmaDPtDY_ModY075To24_Pt,"NRQCD, J/#psi from #chi_{c0}","L");
  lgd_DSigmaDPtDY_ModY075To24_Pt->AddEntry(ChiC1_grDSigmaDPtDY_ModY075To24_Pt,"NRQCD, J/#psi from #chi_{c1}","L");
  lgd_DSigmaDPtDY_ModY075To24_Pt->AddEntry(ChiC2_grDSigmaDPtDY_ModY075To24_Pt,"NRQCD, J/#psi from #chi_{c2}","L");


  TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitleOffset(1.6);
   
  TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->Draw("Csame");
  JPsi_grDSigmaDPtDY_ModY075To24_Pt->Draw("Csame");
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->Draw("Csame");
  
  ChiC0_grDSigmaDPtDY_ModY075To24_Pt->Draw("Csame");
  ChiC1_grDSigmaDPtDY_ModY075To24_Pt->Draw("Csame");
  ChiC2_grDSigmaDPtDY_ModY075To24_Pt->Draw("Csame");
  lgd_DSigmaDPtDY_ModY075To24_Pt->Draw("same");
  gPad->SaveAs("Fig2a_JPsi_CMS_ModY075To24_S7TeV.pdf");




  //grDSigmaDPtDY_ModY090To24_Pt
  //==========================================================================================================//
  //======================================= Plot 4 ==========================================================//
  //========================================================================================================//

  
  for (int j=0; j < JPsi_grDSigmaDPtDY_ModY090To24_Pt->GetN();++j){
    
    Double_t Pt, DirectJPsi,DirectPsi2S,DirectChiC0, DirectChiC1,DirectChiC2;
    Double_t TotalJPsi;
    
    JPsi_grDSigmaDPtDY_ModY090To24_Pt->GetPoint(j,Pt,DirectJPsi);
    Psi2S_grDSigmaDPtDY_ModY090To24_Pt->GetPoint(j,Pt,DirectPsi2S);

    ChiC0_grDSigmaDPtDY_ModY090To24_Pt->GetPoint(j,Pt,DirectChiC0);
    ChiC1_grDSigmaDPtDY_ModY090To24_Pt->GetPoint(j,Pt,DirectChiC1);
    ChiC2_grDSigmaDPtDY_ModY090To24_Pt->GetPoint(j,Pt,DirectChiC2);

    Double_t DY = 3.0;
    TotalJPsi = (DirectJPsi*BR_JPsiToMuMu + DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu + DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu 
		 + DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu+DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu)/DY;
    
    TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->SetPoint(j,Pt,TotalJPsi);
    
    JPsi_grDSigmaDPtDY_ModY090To24_Pt->SetPoint(j,Pt,DirectJPsi*BR_JPsiToMuMu/DY);
    Psi2S_grDSigmaDPtDY_ModY090To24_Pt->SetPoint(j,Pt,DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu/DY);
    
    ChiC0_grDSigmaDPtDY_ModY090To24_Pt->SetPoint(j,Pt,DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu/DY);
    ChiC1_grDSigmaDPtDY_ModY090To24_Pt->SetPoint(j,Pt,DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu/DY);
    ChiC2_grDSigmaDPtDY_ModY090To24_Pt->SetPoint(j,Pt,DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu/DY);
  }

  TLegend *lgd_DSigmaDPtDY_ModY090To24_Pt = new TLegend(0.40,0.60,0.90,0.92);
  lgd_DSigmaDPtDY_ModY090To24_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_ModY090To24_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_ModY090To24_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_ModY090To24_Pt->SetTextSize(0.03);
  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Draw_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt(lgd_DSigmaDPtDY_ModY090To24_Pt);

  lgd_DSigmaDPtDY_ModY090To24_Pt->AddEntry(TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt,"NRQCD, Prompt J/#psi","L");
  lgd_DSigmaDPtDY_ModY090To24_Pt->AddEntry(JPsi_grDSigmaDPtDY_ModY090To24_Pt,"NRQCD, Direct J/#psi","L");
  lgd_DSigmaDPtDY_ModY090To24_Pt->AddEntry(Psi2S_grDSigmaDPtDY_ModY090To24_Pt,"NRQCD, J/#psi from #psi(2S)","L");
  lgd_DSigmaDPtDY_ModY090To24_Pt->AddEntry(ChiC0_grDSigmaDPtDY_ModY090To24_Pt,"NRQCD, J/#psi from #chi_{c0}","L");
  lgd_DSigmaDPtDY_ModY090To24_Pt->AddEntry(ChiC1_grDSigmaDPtDY_ModY090To24_Pt,"NRQCD, J/#psi from #chi_{c1}","L");
  lgd_DSigmaDPtDY_ModY090To24_Pt->AddEntry(ChiC2_grDSigmaDPtDY_ModY090To24_Pt,"NRQCD, J/#psi from #chi_{c2}","L");


  TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->GetYaxis()->SetTitleOffset(1.6);
   
  TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->Draw("Csame");
  JPsi_grDSigmaDPtDY_ModY090To24_Pt->Draw("Csame");
  Psi2S_grDSigmaDPtDY_ModY090To24_Pt->Draw("Csame");
  
  ChiC0_grDSigmaDPtDY_ModY090To24_Pt->Draw("Csame");
  ChiC1_grDSigmaDPtDY_ModY090To24_Pt->Draw("Csame");
  ChiC2_grDSigmaDPtDY_ModY090To24_Pt->Draw("Csame");
  lgd_DSigmaDPtDY_ModY090To24_Pt->Draw("same");
  gPad->SaveAs("Fig2a_JPsi_CMS_ModY090To24_S7TeV.pdf");






  //grDSigmaDPtDY_Y25To40_Pt
  //==========================================================================================================//
  //======================================= Plot 5 ==========================================================//
  //========================================================================================================//

  
  for (int j=0; j < JPsi_grDSigmaDPtDY_Y25To40_Pt->GetN();++j){
    
    Double_t Pt, DirectJPsi,DirectPsi2S,DirectChiC0, DirectChiC1,DirectChiC2;
    Double_t TotalJPsi;
    
    JPsi_grDSigmaDPtDY_Y25To40_Pt->GetPoint(j,Pt,DirectJPsi);
    Psi2S_grDSigmaDPtDY_Y25To40_Pt->GetPoint(j,Pt,DirectPsi2S);

    ChiC0_grDSigmaDPtDY_Y25To40_Pt->GetPoint(j,Pt,DirectChiC0);
    ChiC1_grDSigmaDPtDY_Y25To40_Pt->GetPoint(j,Pt,DirectChiC1);
    ChiC2_grDSigmaDPtDY_Y25To40_Pt->GetPoint(j,Pt,DirectChiC2);

    Double_t DY = 1.5;
    TotalJPsi = (DirectJPsi*BR_JPsiToMuMu + DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu + DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu 
		 + DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu+DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu)/DY;
    
    TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->SetPoint(j,Pt,TotalJPsi);
    
    JPsi_grDSigmaDPtDY_Y25To40_Pt->SetPoint(j,Pt,DirectJPsi*BR_JPsiToMuMu/DY);
    Psi2S_grDSigmaDPtDY_Y25To40_Pt->SetPoint(j,Pt,DirectPsi2S*BR_Psi2SToJPsi*BR_JPsiToMuMu/DY);
    
    ChiC0_grDSigmaDPtDY_Y25To40_Pt->SetPoint(j,Pt,DirectChiC0*BR_ChiC0ToJPsi*BR_JPsiToMuMu/DY);
    ChiC1_grDSigmaDPtDY_Y25To40_Pt->SetPoint(j,Pt,DirectChiC1*BR_ChiC1ToJPsi*BR_JPsiToMuMu/DY);
    ChiC2_grDSigmaDPtDY_Y25To40_Pt->SetPoint(j,Pt,DirectChiC2*BR_ChiC2ToJPsi*BR_JPsiToMuMu/DY);
  }

  TLegend *lgd_DSigmaDPtDY_Y25To40_Pt = new TLegend(0.40,0.60,0.90,0.92);
  lgd_DSigmaDPtDY_Y25To40_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_Y25To40_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_Y25To40_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_Y25To40_Pt->SetTextSize(0.03);
  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Draw_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt(lgd_DSigmaDPtDY_Y25To40_Pt);

  lgd_DSigmaDPtDY_Y25To40_Pt->AddEntry(TotalJPsi_grDSigmaDPtDY_Y25To40_Pt,"NRQCD, Prompt J/#psi","L");
  lgd_DSigmaDPtDY_Y25To40_Pt->AddEntry(JPsi_grDSigmaDPtDY_Y25To40_Pt,"NRQCD, Direct J/#psi","L");
  lgd_DSigmaDPtDY_Y25To40_Pt->AddEntry(Psi2S_grDSigmaDPtDY_Y25To40_Pt,"NRQCD, J/#psi from #psi(2S)","L");
  lgd_DSigmaDPtDY_Y25To40_Pt->AddEntry(ChiC0_grDSigmaDPtDY_Y25To40_Pt,"NRQCD, J/#psi from #chi_{c0}","L");
  lgd_DSigmaDPtDY_Y25To40_Pt->AddEntry(ChiC1_grDSigmaDPtDY_Y25To40_Pt,"NRQCD, J/#psi from #chi_{c1}","L");
  lgd_DSigmaDPtDY_Y25To40_Pt->AddEntry(ChiC2_grDSigmaDPtDY_Y25To40_Pt,"NRQCD, J/#psi from #chi_{c2}","L");


  TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->GetYaxis()->SetTitleOffset(1.6);
   
  TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->Draw("Csame");
  JPsi_grDSigmaDPtDY_Y25To40_Pt->Draw("Csame");
  Psi2S_grDSigmaDPtDY_Y25To40_Pt->Draw("Csame");
  
  ChiC0_grDSigmaDPtDY_Y25To40_Pt->Draw("Csame");
  ChiC1_grDSigmaDPtDY_Y25To40_Pt->Draw("Csame");
  ChiC2_grDSigmaDPtDY_Y25To40_Pt->Draw("Csame");
  lgd_DSigmaDPtDY_Y25To40_Pt->Draw("same");
  gPad->SaveAs("Fig3a_JPsi_CMS_Y25To40_S7TeV.pdf");



  TFile *OutFile = new TFile("TotalJPsiCrossSection.root","Recreate");


  TotalJPsi_grDSigmaDPtDY_ModY090_Pt->Write();
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->Write();
  TotalJPsi_grDSigmaDPtDY_ModY075To24_Pt->Write();
  TotalJPsi_grDSigmaDPtDY_ModY090To24_Pt->Write();
  TotalJPsi_grDSigmaDPtDY_Y25To40_Pt->Write();

  OutFile->Write();
  OutFile->Close();




}


//==============================================================================================//
//=========================== DATA FUNCTIONS ===================================================//
//=============================================================================================//


void Draw_CMS_D2NDPtDy_PromptJPsi_Y0012_Latest_Pt(TLegend *lgd)
{
  
  const int NN = 31;

  Double_t p8319_d1x1y1_xval[NN] = {10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 
    19.5, 20.5, 21.5, 22.5, 23.5, 24.5, 25.5, 26.5, 27.5, 28.5, 
    29.5, 30.9, 32.9, 35.0, 37.0, 39.8, 43.8, 47.9, 54.2, 66.0, 
    82.9, 104.1};
  
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
					 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
					 0.5, 0.8999999999999986, 0.8999999999999986, 1.0, 1.0, 1.7999999999999972, 1.7999999999999972, 
					 1.8999999999999986, 4.200000000000003, 6.0, 7.900000000000006, 9.099999999999994};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
					0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
					0.5, 1.1000000000000014, 1.1000000000000014, 1.0, 1.0, 2.200000000000003, 2.200000000000003, 
					2.1000000000000014, 5.799999999999997, 9.0, 12.099999999999994, 15.900000000000006};
  Double_t p8319_d1x1y1_yval[NN] = {1010.0, 609.0, 382.0, 247.0, 165.0, 114.0, 78.4, 56.6, 41.3, 
				    30.5, 23.0, 17.6, 13.5, 10.5, 8.35, 6.75, 5.35, 4.31, 3.57, 
				    2.86, 2.21, 1.55, 1.11, 0.822, 0.533, 0.302, 0.186, 0.0875, 0.0278, 
				    0.00797, 0.00196};

  Double_t p8319_d1x1y1_yerrminus[NN] = {83.06172403700756, 38.142674316308764, 20.962204655045234, 12.820285332238125, 8.348539033866944, 5.632643784227794, 
					 3.8344751922525195, 2.7562730271146947, 2.003614982974524, 1.4864753613834305, 1.1239555151339398, 0.8612573424941004, 
					 0.6607900120310536, 0.5179313564556601, 0.4131646645104104, 0.33393107073167055, 0.26628526057594704, 0.21565678751200948, 
					 0.1795763347437518, 0.1456978036896919, 0.11152506444741468, 0.0792367339054305, 0.05773603727309314, 0.05766064515768099, 
					 0.03728996647893371, 0.021372678821336366, 0.013454887587787569, 0.009870830765442188, 0.003266365717429694, 
					 0.0010090956347145695, 3.093777787753995E-4 };
  Double_t p8319_d1x1y1_yerrplus[NN] = {83.06172403700756, 38.142674316308764, 20.962204655045234, 12.820285332238125, 8.348539033866944, 5.632643784227794, 3.8344751922525195, 
					2.7562730271146947, 2.003614982974524, 1.4864753613834305, 1.1239555151339398, 0.8612573424941004, 0.6607900120310536, 0.5179313564556601, 
					0.4131646645104104, 0.33393107073167055, 0.26628526057594704, 0.21565678751200948, 0.1795763347437518,0.1456978036896919, 0.11152506444741468, 
					0.0792367339054305, 0.05773603727309314, 0.05766064515768099, 0.03728996647893371, 0.021372678821336366, 0.013454887587787569, 0.009870830765442188, 
					0.003266365717429694, 0.0010090956347145695, 3.093777787753995E-4};
  Double_t p8319_d1x1y1_ystatminus[NN] = {1.4, 0.902, 0.618, 0.454, 0.348, 0.274, 0.22, 0.179, 0.147, 
					  0.125, 0.106, 0.0911, 0.0788, 0.0683, 0.0602, 0.0536, 0.0472, 0.0422, 0.0379, 
					  0.0338, 0.0208, 0.0173, 0.0146, 0.0125, 0.00704, 0.00533, 0.00424, 0.00187, 8.99E-4, 
					  4.32E-4, 2.09E-4 };
  Double_t p8319_d1x1y1_ystatplus[NN] = {1.4, 0.902, 0.618, 0.454, 0.348, 0.274, 0.22, 0.179, 0.147, 
					 0.125, 0.106, 0.0911, 0.0788, 0.0683, 0.0602, 0.0536, 0.0472, 0.0422, 0.0379, 
					 0.0338, 0.0208, 0.0173, 0.0146, 0.0125, 0.00704, 0.00533, 0.00424, 0.00187, 8.99E-4, 
					 4.32E-4, 2.09E-4};
  Double_t pbTonb =1.0/1000.0;


  for(int j=0;j<NN;j++){
    p8319_d1x1y1_yval[j] = p8319_d1x1y1_yval[j]*pbTonb;
    p8319_d1x1y1_yerrminus[j]= p8319_d1x1y1_yerrminus[j]*pbTonb;
    p8319_d1x1y1_yerrplus[j]=p8319_d1x1y1_yerrplus[j]*pbTonb;
    p8319_d1x1y1_ystatminus[j]= p8319_d1x1y1_ystatminus[j]*pbTonb;
    p8319_d1x1y1_ystatplus[j]=p8319_d1x1y1_ystatplus[j]*pbTonb;
  }






  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt->SetMarkerColor(kBlack+0);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt->Draw("AP");

  
  TBox *SystErr[NN];
 
  for(int j=0;j<NN;j++){
    SystErr[j] = new TBox(p8319_d1x1y1_xval[j]-0.5, p8319_d1x1y1_yval[j]-p8319_d1x1y1_ystatminus[j], p8319_d1x1y1_xval[j]+0.5, p8319_d1x1y1_yval[j]+p8319_d1x1y1_ystatplus[j]);
  }
  for(int j=0;j<NN;j++){
    SystErr[j]->SetFillStyle(9001);
    SystErr[j]->SetLineColor(kBlack);
    SystErr[j]->Draw("same"); 
  }
  


  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  tb->DrawLatex(0.21,0.25,"pp #sqrt{s_{_{NN}}} = 7.0 TeV");
  tb->DrawLatex(0.21,0.20,"|y| #leq 1.2");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptJPsi_Y0012_Pt,"CMS prompt J/#psi", "P");
  
  
  
}










void Draw_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt(TLegend *lgd)
{
  
  Double_t p8319_d1x1y1_xval[10] = { 8.569, 9.515, 10.494, 11.485, 12.711, 14.206, 16.329, 21.77, 35.03, 52.7 };
  
  Double_t p8319_d1x1y1_xerrminus[10] = { 0.5690000000000008, 0.5150000000000006, 0.4939999999999998, 0.48499999999999943, 
				       0.7110000000000003, 0.7059999999999995, 1.3290000000000006, 3.7699999999999996, 
				      5.030000000000001, 7.700000000000003 };
  Double_t p8319_d1x1y1_xerrplus[10] = { 0.43099999999999916, 0.48499999999999943, 0.5060000000000002, 0.5150000000000006, 
				      0.7889999999999997, 0.7940000000000005, 1.6709999999999994, 8.23, 9.969999999999999,
				      17.299999999999997 };
  Double_t p8319_d1x1y1_yval[10] = { 2.54, 1.56, 0.96, 0.612, 0.351, 0.184, 0.0841, 0.0139, 7.8E-4, 7.0E-5 };

  Double_t p8319_d1x1y1_yerrminus[10] = { 0.13601470508735444, 0.11224972160321824, 0.06, 0.0366742416417845, 0.020024984394500785, 
				      0.009486832980505138, 0.004423799272118932, 8.062257748298549E-4, 5.1961524227066324E-5, 
				      1.862793601019716E-5 };
  Double_t p8319_d1x1y1_yerrplus[10] = { 0.13601470508735444, 0.11224972160321824, 0.06, 0.0366742416417845, 0.020024984394500785, 
				     0.009486832980505138, 0.004423799272118932, 8.062257748298549E-4, 5.1961524227066324E-5,
				     1.862793601019716E-5 };
  Double_t p8319_d1x1y1_ystatminus[10] = {0.07, 0.03, 0.02, 0.012, 0.006, 0.004, 0.0015, 2.0E-4, 3.0E-5, 7.0E-6 };
  Double_t p8319_d1x1y1_ystatplus[10] = {0.07, 0.03, 0.02, 0.012, 0.006, 0.004, 0.0015, 2.0E-4, 3.0E-5, 7.0E-6 };


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt = new TGraphAsymmErrors(10,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->SetMarkerColor(kBlack+0);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->Draw("AP");

  
  TBox *SystErr[10];
 
  for(int j=0;j<10;j++){
    SystErr[j] = new TBox(p8319_d1x1y1_xval[j]-0.5, p8319_d1x1y1_yval[j]-p8319_d1x1y1_ystatminus[j], p8319_d1x1y1_xval[j]+0.5, p8319_d1x1y1_yval[j]+p8319_d1x1y1_ystatplus[j]);
  }
  for(int j=0;j<10;j++){
    SystErr[j]->SetFillStyle(9001);
    SystErr[j]->SetLineColor(kBlack);
    SystErr[j]->Draw("same"); 
  }
  


  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  tb->DrawLatex(0.21,0.25,"pp #sqrt{s_{_{NN}}} = 7.0 TeV");
  tb->DrawLatex(0.21,0.20,"|y| #leq 0.9");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt,"CMS prompt J/#psi", "P");
  
  
  
}


void Draw_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt(TLegend *lgd)
{
  
  double p8319_d2x1y1_xval[6] = { 8.524, 9.491, 10.921, 13.312, 18.95, 34.7 };
  double p8319_d2x1y1_xerrminus[6] = { 0.5239999999999991, 0.49099999999999966, 0.9209999999999994, 1.3119999999999994, 3.9499999999999993, 4.700000000000003 };
  double p8319_d2x1y1_xerrplus[6] = { 0.47600000000000087, 0.5090000000000003, 1.0790000000000006, 1.6880000000000006, 11.05, 10.299999999999997 };
  double p8319_d2x1y1_yval[6] = { 2.62, 1.55, 0.75, 0.248, 0.0264, 6.7E-4 };
  double p8319_d2x1y1_yerrminus[6] = { 0.1972308292331602, 0.14317821063276354, 0.053851648071345036, 0.01746424919657298, 0.0014352700094407323, 8.366600265340756E-5 };
  double p8319_d2x1y1_yerrplus[6] = { 0.1972308292331602, 0.14317821063276354, 0.053851648071345036, 0.01746424919657298, 0.0014352700094407323, 8.366600265340756E-5 };
  double p8319_d2x1y1_ystatminus[6] = { 0.08, 0.05, 0.02, 0.006, 6.0E-4, 6.0E-5 };
  double p8319_d2x1y1_ystatplus[6] = { 0.08, 0.05, 0.02, 0.006, 6.0E-4, 6.0E-5 };


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt = new TGraphAsymmErrors(6,p8319_d2x1y1_xval, p8319_d2x1y1_yval, p8319_d2x1y1_xerrminus, 
										  p8319_d2x1y1_xerrplus, p8319_d2x1y1_yerrminus, p8319_d2x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->SetMarkerColor(kBlack+0);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->Draw("AP");

  
  TBox *SystErr[6];
 
  for(int j=0;j<6;j++){
    SystErr[j] = new TBox(p8319_d2x1y1_xval[j]-0.5, p8319_d2x1y1_yval[j]-p8319_d2x1y1_ystatminus[j], 
			  p8319_d2x1y1_xval[j]+0.5, p8319_d2x1y1_yval[j]+p8319_d2x1y1_ystatplus[j]);
  }
  for(int j=0;j<6;j++){
    SystErr[j]->SetFillStyle(9001);
    SystErr[j]->SetLineColor(kBlack);
    SystErr[j]->Draw("same"); 
  }
  

  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  tb->DrawLatex(0.21,0.25,"pp #sqrt{s_{_{NN}}} = 7.0 TeV");
  tb->DrawLatex(0.21,0.20,"0.9 #leq |y| #leq 1.2");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt,"CMS prompt J/#psi", "P");
  
   
}








void Draw_ATLAS_D2NDPtDy_PromptJPsi_Y00075_Pt(TLegend *lgd)
{
  const int NN = 14;

  Double_t p8319_d1x1y1_xval[NN] = {7.3, 7.8, 8.3, 8.8, 9.2, 9.8, 10.5, 11.5, 12.9, 14.9, 16.9, 19.7, 25.0, 37.2};
  
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.2999999999999998, 0.2999999999999998, 0.3000000000000007, 0.3000000000000007, 0.1999999999999993, 0.3000000000000007, 0.5, 0.5, 0.9000000000000004, 
    0.9000000000000004, 0.8999999999999986, 1.6999999999999993, 3.0, 7.200000000000003};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.20000000000000018, 0.20000000000000018, 0.1999999999999993, 0.1999999999999993, 0.3000000000000007, 0.1999999999999993, 0.5, 0.5, 1.0999999999999996, 
    1.0999999999999996, 1.1000000000000014, 2.3000000000000007, 5.0, 32.8};



  Double_t p8319_d1x1y1_yval[NN] = {6.8, 5.9, 3.3, 2.6, 2.2, 1.5, 1.04, 0.71, 0.34, 
    0.163, 0.076, 0.035, 0.0078, 4.0E-4};
  
  Double_t p8319_d1x1y1_yerrminus[NN] = {2.5865034312755126, 2.1863211109075444, 1.118033988749895, 0.9165151389911681, 0.7, 0.45825756949558405, 0.31416556144810015, 
					 0.21748563170931548, 0.09899494936611665,0.04604345773288536, 0.020591260281974, 0.009433981132056603, 0.00189208879284245, 
					 1.414213562373095E-4 };
  Double_t p8319_d1x1y1_yerrplus[NN] = { 4.509988913511872, 2.9086079144497976, 1.392838827718412, 1.004987562112089, 0.9695359714832659, 0.5477225575051661, 0.3420526275297414, 
					 0.2083266665599966, 0.09, 0.040644802865803145, 0.018027756377319945, 0.0078102496759066544, 0.0016186414056238644, 1.414213562373095E-4};
  
  Double_t p8319_d1x1y1_ystatminus[NN] = { 0.8, 0.6, 0.3, 0.2, 0.2, 0.1, 0.05, 0.03, 0.01, 0.01, 0.006, 0.003, 9.0E-4, 1.0E-4};
  Double_t p8319_d1x1y1_ystatplus[NN] = {0.8, 0.6, 0.3, 0.2, 0.2, 0.1, 0.05, 0.03, 0.01, 0.01, 0.006, 0.003, 9.0E-4, 1.0E-4 };


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt->SetMarkerColor(kBlack+0);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt->Draw("AP");

  
  TBox *SystErr[NN];
 
  for(int j=0;j<NN;j++){
    SystErr[j] = new TBox(p8319_d1x1y1_xval[j]-0.5, p8319_d1x1y1_yval[j]-p8319_d1x1y1_ystatminus[j], p8319_d1x1y1_xval[j]+0.5, p8319_d1x1y1_yval[j]+p8319_d1x1y1_ystatplus[j]);
  }
  for(int j=0;j<NN;j++){
    SystErr[j]->SetFillStyle(9001);
    SystErr[j]->SetLineColor(kBlack);
    SystErr[j]->Draw("same"); 
  }
  


  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  tb->DrawLatex(0.21,0.25,"pp #sqrt{s_{_{NN}}} = 7.0 TeV");
  tb->DrawLatex(0.21,0.20,"|y| #leq 0.75");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptJPsi_Y0075_Pt,"ATLAS prompt J/#psi", "P");
  
  
  
}

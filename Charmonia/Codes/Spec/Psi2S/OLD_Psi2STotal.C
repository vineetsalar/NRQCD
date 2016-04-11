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

void Draw_CMS_D2NDPtDy_PromptPsi2S_Y0012_Pt(TLegend *lgd);
void Draw_CMS_D2NDPtDy_PromptPsi2S_Y1216_Pt(TLegend *lgd);
void Draw_CMS_D2NDPtDy_PromptPsi2S_Y1624_Pt(TLegend *lgd);

void Draw_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt(TLegend *lgd);
void Draw_CMS_New_D2NDPtDy_PromptPsi2S_Y1216_Pt(TLegend *lgd);
void Draw_CMS_New_D2NDPtDy_PromptPsi2S_Y1624_Pt(TLegend *lgd);


void Draw_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt(TLegend *lgd);

void Psi2STotal()
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

  
 
  //================================================= Get All Graphs from Psi(2S) =====================================//


  TFile *file_Psi2SCrossSection =  new TFile("Psi2SCrossSection.root","R");

  //grDSigmaDPtDY_ModY075_Pt
  TGraph *Psi2S_grDSigmaDPtDY_ModY075_Pt =(TGraph*)file_Psi2SCrossSection->Get("grDSigmaDPtDY_ModY075_Pt");
  Psi2S_grDSigmaDPtDY_ModY075_Pt->SetName("Psi2S_grDSigmaDPtDY_ModY075_Pt");
  Psi2S_grDSigmaDPtDY_ModY075_Pt->SetTitle("Psi2S_grDSigmaDPtDY_ModY075_Pt");
  Psi2S_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  Psi2S_grDSigmaDPtDY_ModY075_Pt->SetLineColor(6);
  Psi2S_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  Psi2S_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  TGraph *TotalPsi2S_grDSigmaDPtDY_ModY075_Pt =(TGraph*)Psi2S_grDSigmaDPtDY_ModY075_Pt->Clone();
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetName("TotalPsi2S_grDSigmaDPtDY_ModY075_Pt");
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetTitle("TotalPsi2S_grDSigmaDPtDY_ModY075_Pt");
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetLineColor(2);
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");







  //1.2 |y| <1.6

  TGraph *Psi2S_grDSigmaDPtDY_ModY090_Pt =(TGraph*)file_Psi2SCrossSection->Get("grDSigmaDPtDY_ModY090_Pt");
  Psi2S_grDSigmaDPtDY_ModY090_Pt->SetName("Psi2S_grDSigmaDPtDY_ModY090_Pt");
  Psi2S_grDSigmaDPtDY_ModY090_Pt->SetTitle("Psi2S_grDSigmaDPtDY_ModY090_Pt");
  Psi2S_grDSigmaDPtDY_ModY090_Pt->SetLineWidth(2);
  Psi2S_grDSigmaDPtDY_ModY090_Pt->SetLineColor(6);
  Psi2S_grDSigmaDPtDY_ModY090_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  Psi2S_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");

  
  TGraph *TotalPsi2S_grDSigmaDPtDY_ModY090_Pt =(TGraph*)Psi2S_grDSigmaDPtDY_ModY090_Pt->Clone();
  TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->SetName("TotalPsi2S_grDSigmaDPtDY_ModY090_Pt");
  TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->SetTitle("TotalPsi2S_grDSigmaDPtDY_ModY090_Pt");
  TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->SetLineWidth(2);
  TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->SetLineColor(2);
  TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");



  //1.6 |y| <2.4

  //grDSigmaDPtDY_ModY075To24_Pt

  TGraph *Psi2S_grDSigmaDPtDY_ModY075To24_Pt =(TGraph*)file_Psi2SCrossSection->Get("grDSigmaDPtDY_ModY075To24_Pt");
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->SetName("Psi2S_grDSigmaDPtDY_ModY075To24_Pt");
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->SetTitle("Psi2S_grDSigmaDPtDY_ModY075To24_Pt");
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->SetLineWidth(2);
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->SetLineColor(6);
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  Psi2S_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  

  TGraph *TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt =(TGraph*)Psi2S_grDSigmaDPtDY_ModY075To24_Pt->Clone();
  TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->SetName("TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt");
  TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->SetTitle("TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt");
  TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->SetLineWidth(2);
  TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->SetLineColor(2);
  TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");



  //==========================================================================================================//
  //======================================= Plot 1 ==========================================================//
  //========================================================================================================//

  //This is |y| < 1.2
  for (int j=0; j < Psi2S_grDSigmaDPtDY_ModY075_Pt->GetN();++j){
    
    Double_t Pt, DirectPsi2S;
    Double_t TotalPsi2S;
    
    Psi2S_grDSigmaDPtDY_ModY075_Pt->GetPoint(j,Pt,DirectPsi2S);

    Double_t DY = 2.4;
    
    TotalPsi2S = (DirectPsi2S*BR_Psi2SToMuMu)/DY;
    TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetPoint(j,Pt,TotalPsi2S);
  }

  TLegend *lgd_DSigmaDPtDY_ModY075_Pt = new TLegend(0.22,0.78,0.78,0.94);
  lgd_DSigmaDPtDY_ModY075_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_ModY075_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_ModY075_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_ModY075_Pt->SetTextSize(0.045);
  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);

  //Draw_CMS_D2NDPtDy_PromptPsi2S_Y0012_Pt(lgd_DSigmaDPtDY_ModY075_Pt);
  //
  Draw_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt(lgd_DSigmaDPtDY_ModY075_Pt);
  Draw_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt(lgd_DSigmaDPtDY_ModY075_Pt);
  lgd_DSigmaDPtDY_ModY075_Pt->AddEntry(TotalPsi2S_grDSigmaDPtDY_ModY075_Pt,"Prompt #psi(2S)","L");
  
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitleOffset(1.6);

  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(3);
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetLineStyle(1);
 
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->Draw("Csame");
  lgd_DSigmaDPtDY_ModY075_Pt->Draw("same");

  gPad->SaveAs("Fig2a_Psi2S_CMS_Y012_S7TeV.pdf");


  //==========================================================================================================//
  //======================================= Plot 2 ==========================================================//
  //========================================================================================================//

  
  
 //This is 1.2 < |y| < 1.6
  for (int j=0; j < Psi2S_grDSigmaDPtDY_ModY090_Pt->GetN();++j){
    
    Double_t Pt, DirectPsi2S;
    Double_t TotalPsi2S;
    
    Psi2S_grDSigmaDPtDY_ModY090_Pt->GetPoint(j,Pt,DirectPsi2S);

    Double_t DY = 0.8;
    
    TotalPsi2S = (DirectPsi2S*BR_Psi2SToMuMu)/DY;
    TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->SetPoint(j,Pt,TotalPsi2S);
  }

  TLegend *lgd_DSigmaDPtDY_ModY090_Pt = new TLegend(0.40,0.82,0.90,0.93);
  lgd_DSigmaDPtDY_ModY090_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_ModY090_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_ModY090_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_ModY090_Pt->SetTextSize(0.03);
  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);

  Draw_CMS_D2NDPtDy_PromptPsi2S_Y1216_Pt(lgd_DSigmaDPtDY_ModY090_Pt);
  lgd_DSigmaDPtDY_ModY090_Pt->AddEntry(TotalPsi2S_grDSigmaDPtDY_ModY090_Pt,"NRQCD, Prompt #psi(2S)","L");
  
  TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->GetYaxis()->SetTitleOffset(1.6);
   
  TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->Draw("Csame");
  lgd_DSigmaDPtDY_ModY090_Pt->Draw("same");

  gPad->SaveAs("Fig2b_Psi2S_CMS_Y1216_S7TeV.pdf");




 //==========================================================================================================//
  //======================================= Plot 3 ==========================================================//
  //========================================================================================================//

  
  
  //This is 1.6 < |y| < 2.4
  for (int j=0; j < Psi2S_grDSigmaDPtDY_ModY075To24_Pt->GetN();++j){
    
    Double_t Pt, DirectPsi2S;
    Double_t TotalPsi2S;
    
    Psi2S_grDSigmaDPtDY_ModY075To24_Pt->GetPoint(j,Pt,DirectPsi2S);

    Double_t DY = 1.6;
    
    TotalPsi2S = (DirectPsi2S*BR_Psi2SToMuMu)/DY;
    TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->SetPoint(j,Pt,TotalPsi2S);
  }

  TLegend *lgd_DSigmaDPtDY_ModY075To24_Pt = new TLegend(0.40,0.82,0.90,0.93);
  lgd_DSigmaDPtDY_ModY075To24_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_ModY075To24_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_ModY075To24_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_ModY075To24_Pt->SetTextSize(0.03);
  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);

  Draw_CMS_D2NDPtDy_PromptPsi2S_Y1624_Pt(lgd_DSigmaDPtDY_ModY075To24_Pt);
  lgd_DSigmaDPtDY_ModY075To24_Pt->AddEntry(TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt,"NRQCD, Prompt #psi(2S)","L");
  
  TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->GetYaxis()->SetTitleOffset(1.6);
   
  TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->Draw("Csame");
  lgd_DSigmaDPtDY_ModY075To24_Pt->Draw("same");

  gPad->SaveAs("Fig2c_Psi2S_CMS_Y1624_S7TeV.pdf");

  TFile *OutFile = new TFile("TotalPsi2SCrossSection.root","Recreate");

  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->Write();
  TotalPsi2S_grDSigmaDPtDY_ModY090_Pt->Write();
  TotalPsi2S_grDSigmaDPtDY_ModY075To24_Pt->Write();

  OutFile->Write();
  OutFile->Close();





}


//==============================================================================================//
//=========================== DATA FUNCTIONS ===================================================//
//=============================================================================================//


void Draw_CMS_D2NDPtDy_PromptPsi2S_Y0012_Pt(TLegend *lgd)
{
  const int NN = 9;

  Double_t p8319_d1x1y1_xval[NN] = {7.6, 8.54, 9.5, 10.5, 11.48, 12.72, 14.23, 16.3, 21.92};
  Double_t p8319_d1x1y1_xerrminus[NN] = {1.0999999999999996, 0.5399999999999991, 0.5, 0.5, 0.4800000000000004, 0.7200000000000006, 0.7300000000000004, 1.3000000000000007, 3.9200000000000017};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.40000000000000036, 0.46000000000000085, 0.5, 0.5, 0.5199999999999996, 0.7799999999999994, 0.7699999999999996, 1.6999999999999993, 8.079999999999998};
  
  
  Double_t p8319_d1x1y1_yval[NN] = {0.148, 0.083, 0.061, 0.0368, 0.0217, 0.0141, 0.0077, 0.00368, 6.6E-4};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.03573513677041128, 0.010440306508910549, 0.00670820393249937, 0.004141255848169731, 0.0030430248109405878, 0.0016031219541881396, 
					 9.695359714832658E-4, 3.760319135392633E-4, 7.681145747868608E-5};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.03573513677041128, 0.010440306508910549, 0.00670820393249937, 0.004141255848169731, 0.0030430248109405878, 0.0016031219541881396, 
					9.695359714832658E-4, 3.760319135392633E-4, 7.681145747868608E-5};

  Double_t p8319_d1x1y1_ystatminus[NN] = {0.029, 0.008, 0.005, 0.0031, 0.0019, 0.0011, 7.0E-4, 3.0E-4, 5.0E-5};
  Double_t p8319_d1x1y1_ystatplus[NN] = {0.029, 0.008, 0.005, 0.0031, 0.0019, 0.0011, 7.0E-4, 3.0E-4, 5.0E-5};


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerColor(kBlack+0);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->Draw("AP");

  
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
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt,"CMS prompt #psi(2S)", "P");
  
  
  
}

void Draw_CMS_D2NDPtDy_PromptPsi2S_Y1216_Pt(TLegend *lgd)
{
  const int NN = 7;

  Double_t p8319_d1x1y1_xval[NN] = {6.15, 7.36, 8.49, 9.5, 10.97, 13.32, 19.07};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.6500000000000004, 0.8600000000000003, 0.4900000000000002, 0.5, 0.9700000000000006, 1.3200000000000003, 4.07};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.34999999999999964, 0.6399999999999997, 0.5099999999999998, 0.5, 1.0299999999999994, 1.6799999999999997, 10.93};
  
  Double_t p8319_d1x1y1_yval[NN] = {0.62, 0.187, 0.078, 0.058, 0.0264, 0.0109, 0.00132};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.31464265445104544, 0.024556058315617347, 0.012449899597988732, 0.011, 0.003849675310984032, 0.0019519221295943134, 1.7748239349298848E-4};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.31464265445104544, 0.024556058315617347, 0.012449899597988732, 0.011, 0.003849675310984032, 0.0019519221295943134, 1.7748239349298848E-4};

  Double_t p8319_d1x1y1_ystatminus[NN] = {0.31, 0.023, 0.011, 0.009, 0.0031, 0.0013, 1.3E-4};
  Double_t p8319_d1x1y1_ystatplus[NN] = {0.31, 0.023, 0.011, 0.009, 0.0031, 0.0013, 1.3E-4};


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt->SetMarkerColor(kBlack+0);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt->Draw("AP");

  
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
  tb->DrawLatex(0.21,0.20,"1.2 #leq |y| #leq 1.6");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptPsi2S_1216_Pt,"CMS prompt #psi(2S)", "P");
  
  
  
}




void Draw_CMS_D2NDPtDy_PromptPsi2S_Y1624_Pt(TLegend *lgd)
{
  const int NN = 7;

  Double_t p8319_d1x1y1_xval[NN] = {6.2, 7.25, 8.48, 9.52, 10.88, 13.38, 19.01};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.7000000000000002, 0.75, 0.4800000000000004, 0.5199999999999996, 0.8800000000000008, 1.3800000000000008, 4.010000000000002};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.2999999999999998, 0.75, 0.5199999999999996, 0.4800000000000004, 1.1199999999999992, 1.6199999999999992, 10.989999999999998};
  
  Double_t p8319_d1x1y1_yval[NN] = {0.43, 0.185, 0.078, 0.049, 0.0219, 0.009, 9.3E-4};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.19949937343260005, 0.03472751070837068, 0.01392838827718412, 0.010816653826391968, 0.003925557285278105, 0.0014177446878757827, 1.4966629547095766E-4};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.19949937343260005, 0.03472751070837068, 0.01392838827718412, 0.010816653826391968, 0.003925557285278105, 0.0014177446878757827, 1.4966629547095766E-4};

  Double_t p8319_d1x1y1_ystatminus[NN] = {0.15, 0.031, 0.011, 0.008, 0.0028, 0.0011, 1.2E-4};
  Double_t p8319_d1x1y1_ystatplus[NN] = {0.15, 0.031, 0.011, 0.008, 0.0028, 0.0011, 1.2E-4};


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt->SetMarkerColor(kBlack+0);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt->Draw("AP");

  
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
  tb->DrawLatex(0.21,0.20,"1.6 #leq |y| #leq 2.4");
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptPsi2S_1624_Pt,"CMS prompt #psi(2S)", "P");
  
  
  
}






void Draw_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt(TLegend *lgd)
{
  //This data is from 1111.1557
  const int NN = 7;

  Double_t p8319_d1x1y1_xval[NN] = {6.15, 7.36, 8.49, 9.5, 10.97, 13.32, 19.07};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.6500000000000004, 0.8600000000000003, 0.4900000000000002, 0.5, 0.9700000000000006, 1.3200000000000003, 4.07};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.34999999999999964, 0.6399999999999997, 0.5099999999999998, 0.5, 1.0299999999999994, 1.6799999999999997, 10.93};
  
  
  Double_t p8319_d1x1y1_yval[NN] = {0.62, 0.187, 0.078, 0.058, 0.0264, 0.0109, 0.00132};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.31464265445104544, 0.024556058315617347, 0.012449899597988732, 0.011, 0.003849675310984032, 0.0019519221295943134, 1.7748239349298848E-4};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.31464265445104544, 0.024556058315617347, 0.012449899597988732, 0.011, 0.003849675310984032, 0.0019519221295943134, 1.7748239349298848E-4};

  Double_t p8319_d1x1y1_ystatminus[NN] = {0.31, 0.023, 0.011, 0.009, 0.0031, 0.0013, 1.3E-4 };
  Double_t p8319_d1x1y1_ystatplus[NN] = {0.31, 0.023, 0.011, 0.009, 0.0031, 0.0013, 1.3E-4};


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerStyle(21);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerColor(4);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->Draw("zAP");

  
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
  //tb->DrawLatex(0.21,0.25,"pp #sqrt{s_{_{NN}}} = 7.0 TeV");
  //tb->DrawLatex(0.21,0.20,"|y| #leq 1.2");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt,"CMS prompt #psi(2S), low p_{T}", "P");
  
  
  
}
void Draw_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt(TLegend *lgd)
{
  //
  const int NN = 19;

  Double_t p8319_d1x1y1_xval[NN] = {10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 
    19.5, 21.1, 23.6, 26.1, 28.7, 32.2, 37.2, 45.5, 62.4, 84.1};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
					 0.5, 1.1000000000000014, 1.1000000000000014, 1.1000000000000014, 1.1999999999999993, 2.200000000000003, 
					 2.200000000000003, 5.5, 7.399999999999999, 9.099999999999994};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
					0.5, 1.3999999999999986, 1.3999999999999986, 1.3999999999999986, 1.3000000000000007, 2.799999999999997, 2.799999999999997, 
					9.5, 12.600000000000001, 15.900000000000006};
  
  
  Double_t p8319_d1x1y1_yval[NN] = {38.0, 24.1, 15.4, 10.2, 7.15, 4.79, 3.48, 2.52, 1.87, 
    1.34, 0.857, 0.461, 0.269, 0.165, 0.0842, 0.0347, 0.0102, 0.00235, 5.62E-4};
  Double_t p8319_d1x1y1_yerrminus[NN] = {2.994346673316234, 1.4998589933723767, 0.872326773634743, 0.5494606446325342, 0.38020278799609036, 0.26125627265196905, 
					 0.18547174987043175, 0.13869340287122528, 0.1012699856818396, 0.07589519088848778, 0.049967989753441154, 
					 0.027793704323101662, 0.018381689258607326, 0.011822664674260198, 0.006161671851048221, 0.0034377709347773594, 
					 0.0010926362615253074, 4.183390490977384E-4, 1.5471069775552045E-4};
  Double_t p8319_d1x1y1_yerrplus[NN] = {2.994346673316234, 1.4998589933723767, 0.872326773634743, 0.5494606446325342, 0.38020278799609036, 0.26125627265196905, 
					0.18547174987043175, 0.13869340287122528, 0.1012699856818396, 0.07589519088848778, 0.049967989753441154, 0.027793704323101662, 
					0.018381689258607326, 0.011822664674260198, 0.006161671851048221, 0.0034377709347773594, 0.0010926362615253074, 4.183390490977384E-4, 
					1.5471069775552045E-4};

  Double_t p8319_d1x1y1_ystatminus[NN] = {0.296, 0.194, 0.137, 0.101, 0.0796, 0.0622, 0.0511, 0.0419, 0.0352, 
					  0.0294, 0.0144, 0.0102, 0.00772, 0.00607, 0.00299, 0.002, 6.66E-4, 2.99E-4, 1.37E-4};
  Double_t p8319_d1x1y1_ystatplus[NN] = { 0.296, 0.194, 0.137, 0.101, 0.0796, 0.0622, 0.0511, 0.0419, 0.0352, 
					  0.0294, 0.0144, 0.0102, 0.00772, 0.00607, 0.00299, 0.002, 6.66E-4, 2.99E-4, 1.37E-4};

  Double_t pbTonb =1.0/1000.0;


for(int j=0;j<NN;j++){
    p8319_d1x1y1_yval[j] = p8319_d1x1y1_yval[j]*pbTonb;
    p8319_d1x1y1_yerrminus[j]= p8319_d1x1y1_yerrminus[j]*pbTonb;
    p8319_d1x1y1_yerrplus[j]=p8319_d1x1y1_yerrplus[j]*pbTonb;
    p8319_d1x1y1_ystatminus[j]= p8319_d1x1y1_ystatminus[j]*pbTonb;
    p8319_d1x1y1_ystatplus[j]=p8319_d1x1y1_ystatplus[j]*pbTonb;
  }



  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerColor(kBlack);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,100.0);
   

  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->Draw("zPsame");

  
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
  //tb->DrawLatex(0.21,0.25,"pp #sqrt{s_{_{NN}}} = 7.0 TeV");
  //tb->DrawLatex(0.21,0.20,"|y| #leq 1.2");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt,"CMS prompt #psi(2S), high p_{T}", "P");
  
  
  
}



void Draw_CMS_New_D2NDPtDy_PromptPsi2S_Y1216_Pt(TLegend *lgd)
{
  //This data is from 1111.1557
  const int NN = 7;

  Double_t p8319_d1x1y1_xval[NN] = {};
  Double_t p8319_d1x1y1_xerrminus[NN] = {};
  Double_t p8319_d1x1y1_xerrplus[NN] = {};
  
  
  Double_t p8319_d1x1y1_yval[NN] = {};
  Double_t p8319_d1x1y1_yerrminus[NN] = {};
  Double_t p8319_d1x1y1_yerrplus[NN] = {};

  Double_t p8319_d1x1y1_ystatminus[NN] = {};
  Double_t p8319_d1x1y1_ystatplus[NN] = {};


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerStyle(21);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerColor(kBlue+0);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->Draw("Psame");

  
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
  tb->DrawLatex(0.21,0.20," 1.2 #leq |y| #leq 1.6");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt,"CMS prompt #psi(2S)", "P");
  
  
  
}


void Draw_CMS_New_D2NDPtDy_PromptPsi2S_Y1624_Pt(TLegend *lgd)
{
  //This data is from 1111.1557
  const int NN = 7;

  Double_t p8319_d1x1y1_xval[NN] = {};
  Double_t p8319_d1x1y1_xerrminus[NN] = {};
  Double_t p8319_d1x1y1_xerrplus[NN] = {};
  
  
  Double_t p8319_d1x1y1_yval[NN] = {};
  Double_t p8319_d1x1y1_yerrminus[NN] = {};
  Double_t p8319_d1x1y1_yerrplus[NN] = {};

  Double_t p8319_d1x1y1_ystatminus[NN] = {};
  Double_t p8319_d1x1y1_ystatplus[NN] = {};


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerStyle(21);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerColor(kBlue+0);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->Draw("Psame");

  
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
  tb->DrawLatex(0.21,0.20,"1.6 #leq |y| #leq 2.4");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt,"CMS prompt #psi(2S)", "P");
  
  
  
}

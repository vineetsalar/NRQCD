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


void Draw_CMS_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt(TLegend *lgd);

void CharmoniaRatio()
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

  
  TFile *file_JPsiCrossSection =  new TFile("TotalJPsiCrossSection.root","R");
  

  TGraph *TotalJPsi_grDSigmaDPtDY_ModY075_Pt =(TGraph*)file_JPsiCrossSection->Get("TotalJPsi_grDSigmaDPtDY_ModY075_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->SetName("TotalJPsi_grDSigmaDPtDY_ModY075_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->SetTitle("TotalJPsi_grDSigmaDPtDY_ModY075_Pt");
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->SetLineColor(4);
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalJPsi_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  


  
  TGraph *RatioJPsi_grDSigmaDPtDY_ModY075_Pt=(TGraph*)TotalJPsi_grDSigmaDPtDY_ModY075_Pt->Clone();
  RatioJPsi_grDSigmaDPtDY_ModY075_Pt->SetName("RatioJPsi_grDSigmaDPtDY_ModY075_Pt");
  RatioJPsi_grDSigmaDPtDY_ModY075_Pt->SetTitle("RatioJPsi_grDSigmaDPtDY_ModY075_Pt");
  RatioJPsi_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  RatioJPsi_grDSigmaDPtDY_ModY075_Pt->SetLineColor(2);
  RatioJPsi_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  RatioJPsi_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy^{#psi(2S)}/d^{2}#sigma/dp_{T}dy^{J/#psi}");

  
  

  TFile *file_Psi2SCrossSection =  new TFile("TotalPsi2SCrossSection.root","R");
  

  TGraph *TotalPsi2S_grDSigmaDPtDY_ModY075_Pt =(TGraph*)file_Psi2SCrossSection->Get("TotalPsi2S_grDSigmaDPtDY_ModY075_Pt");
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetName("TotalPsi2S_grDSigmaDPtDY_ModY075_Pt");
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetTitle("TotalPsi2S_grDSigmaDPtDY_ModY075_Pt");
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetLineWidth(2);
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->SetLineColor(4);
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");
  


  

  //==========================================================================================================//
  //======================================= Plot 1 ==========================================================//
  //========================================================================================================//

  for (int j=0; j < TotalJPsi_grDSigmaDPtDY_ModY075_Pt->GetN();++j){
    
    
    Double_t Pt, TotalJPsi, TotalPsi2S;
    
    Double_t RatioJPsi;
    
    TotalJPsi_grDSigmaDPtDY_ModY075_Pt->GetPoint(j,Pt,TotalJPsi);
    TotalPsi2S_grDSigmaDPtDY_ModY075_Pt->GetPoint(j,Pt,TotalPsi2S);

    RatioJPsi = (TotalPsi2S)/(TotalJPsi);
    
    Double_t AbsToPercent = 100.0;
    RatioJPsi =RatioJPsi*AbsToPercent;

    RatioJPsi_grDSigmaDPtDY_ModY075_Pt->SetPoint(j,Pt,RatioJPsi);
  

    cout<<Pt<<"   "<<(TotalPsi2S)<<"   "<<(TotalJPsi)<<endl;
}

  TLegend *lgd_DSigmaDPtDY_ModY075_Pt = new TLegend(0.24,0.79,0.87,0.91);
  lgd_DSigmaDPtDY_ModY075_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_ModY075_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_ModY075_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_ModY075_Pt->SetTextSize(0.03);
  
  new TCanvas; 
  gPad->SetTicks();
  //gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  
  Draw_CMS_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt(lgd_DSigmaDPtDY_ModY075_Pt);

  lgd_DSigmaDPtDY_ModY075_Pt->AddEntry(RatioJPsi_grDSigmaDPtDY_ModY075_Pt,"NRQCD, Prompt #psi(2S)/ Prompt J/#psi","L");
  


  RatioJPsi_grDSigmaDPtDY_ModY075_Pt->GetYaxis()->SetTitleOffset(1.6);
   
  RatioJPsi_grDSigmaDPtDY_ModY075_Pt->Draw("Csame");
  lgd_DSigmaDPtDY_ModY075_Pt->Draw("same");
  gPad->SaveAs("Fig3_RatioJPsi_CMS_Y0012_S7TeV.pdf");



}


//==============================================================================================//
//=========================== DATA FUNCTIONS ===================================================//
//=============================================================================================//


void Draw_CMS_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt(TLegend *lgd)
{
  
  const int NN =19;

  Double_t p8319_d1x1y1_xval[NN] = {10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 
				    19.5, 21.1, 23.6, 26.1, 28.7, 32.2, 37.2, 45.5, 62.3, 82.9};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
					 0.5, 1.1000000000000014, 1.1000000000000014, 1.1000000000000014, 1.1999999999999993, 
					 2.200000000000003, 2.200000000000003, 5.5, 7.299999999999997, 7.900000000000006};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.3999999999999986, 1.3999999999999986, 
					1.3999999999999986, 1.3000000000000007, 2.799999999999997, 2.799999999999997, 9.5, 12.700000000000003, 
					17.099999999999994  };
  

  Double_t p8319_d1x1y1_yval[NN] = {3.75, 3.93, 4.04, 4.11, 4.3, 4.2, 4.39, 4.42, 4.45, 
				    4.37, 4.49, 4.58, 4.69, 4.85, 4.84, 4.47, 4.47, 6.08, 7.64 };

  Double_t p8319_d1x1y1_yerrminus[NN] = {0.11401754250991379, 0.11401754250991379, 0.11704699910719625, 0.11704699910719625, 0.13, 0.12529964086141668, 
					 0.13892443989449804, 0.14422205101855956, 0.15, 0.14866068747318506, 0.09433981132056604, 0.1118033988749895, 
					 0.14560219778561037, 0.18681541692269404, 0.18681541692269404, 0.26476404589747454, 0.3026549190084311, 0.8089499366462675, 
					 2.022003956474863};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.11401754250991379, 0.11401754250991379, 0.11704699910719625, 0.11704699910719625, 0.13, 0.12529964086141668, 
					0.13892443989449804, 0.14422205101855956, 0.15, 0.14866068747318506, 0.09433981132056604, 0.1118033988749895, 
					0.14560219778561037, 0.18681541692269404, 0.18681541692269404, 0.26476404589747454, 0.3026549190084311, 0.8089499366462675, 
					2.022003956474863};
  Double_t p8319_d1x1y1_ystatminus[NN] = {0.03, 0.03, 0.04, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 
					  0.1, 0.08, 0.1, 0.14, 0.18, 0.18, 0.26, 0.3, 0.8, 1.98};
  Double_t p8319_d1x1y1_ystatplus[NN] = { 0.03, 0.03, 0.04, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 
					  0.1, 0.08, 0.1, 0.14, 0.18, 0.18, 0.26, 0.3, 0.8, 1.98};


  TGraphAsymmErrors *Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->SetMarkerStyle(20);
  Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->SetMarkerColor(kBlack+0);
  Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->SetMarkerSize(1.6);
  Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->GetYaxis()->SetRangeUser(0.01,15.0);
  
  TAxis *Xaxis1 = Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,100.0);
   

  Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  //Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");

  Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->GetYaxis()->SetTitle("[B #sigma(#psi(2S))]/[B #sigma(J/#psi)][%]");
  
  Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt->Draw("AP");

  
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
 
  lgd->AddEntry(Grf_Ratio_PromptPsi2S_PromptJPsi_Y0012_Pt,"CMS Prompt #psi(2S)/ Prompt J/#psi", "P");
  
  
  
}



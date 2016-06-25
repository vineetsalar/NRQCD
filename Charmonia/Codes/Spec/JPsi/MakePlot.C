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
void MakePlot()
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
  

  TLegend *legd0 = new TLegend(0.27,0.74,0.86,0.94);
  legd0->SetBorderSize(0);
  legd0->SetFillStyle(0);
  legd0->SetFillColor(0);
  legd0->SetTextSize(0.040);
  

  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  
  
  TFile *file_JPsiCrossSection_13TeV =  new TFile("Out_JPsiCrossSection_13TeV.root","R");
  TFile *file_JPsiCrossSection_5TeV =  new TFile("Out_JPsiCrossSection_5TeV.root","R");
  TFile *file_JPsiCrossSection_18TeV =  new TFile("Out_JPsiCrossSection_18TeV.root","R");

  TGraph *grATLAS_2525_RootS13TeV_Psi_JPsi_Pt =(TGraph*)file_JPsiCrossSection_13TeV->Get("Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");
  grATLAS_2525_RootS13TeV_Psi_JPsi_Pt->SetLineColor(2);
  grATLAS_2525_RootS13TeV_Psi_JPsi_Pt->SetLineWidth(4);
  grATLAS_2525_RootS13TeV_Psi_JPsi_Pt->SetLineStyle(1);
  
  TGraph *grATLAS_2525_RootS5TeV_Psi_JPsi_Pt =(TGraph*)file_JPsiCrossSection_5TeV->Get("Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");
  
  grATLAS_2525_RootS5TeV_Psi_JPsi_Pt->SetLineColor(1);
  grATLAS_2525_RootS5TeV_Psi_JPsi_Pt->SetLineWidth(2);
  grATLAS_2525_RootS5TeV_Psi_JPsi_Pt->SetLineStyle(9);


  TGraph *grATLAS_2525_RootS18TeV_Psi_JPsi_Pt =(TGraph*)file_JPsiCrossSection_18TeV->Get("Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");
  
  grATLAS_2525_RootS18TeV_Psi_JPsi_Pt->SetLineColor(4);
  grATLAS_2525_RootS18TeV_Psi_JPsi_Pt->SetLineWidth(2);
  grATLAS_2525_RootS18TeV_Psi_JPsi_Pt->SetLineStyle(7);

  
  TLegend *lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi = new TLegend(0.27,0.74,0.86,0.94);
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetBorderSize(0);
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetFillStyle(0);
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetFillColor(0);
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetTextSize(0.04);
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->AddEntry(grATLAS_2525_RootS18TeV_Psi_JPsi_Pt,"pp #surds=1.8 TeV, |y| #leq 2.5","L");
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->AddEntry(grATLAS_2525_RootS5TeV_Psi_JPsi_Pt,"pp #surds=5 TeV, |y| #leq 2.5","L");
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->AddEntry(grATLAS_2525_RootS13TeV_Psi_JPsi_Pt,"pp #surds=13 TeV, |y| #leq 2.5","L");



  new TCanvas;
  gPad->SetTicks();
  gPad->SetLeftMargin(0.22);
  grATLAS_2525_RootS13TeV_Psi_JPsi_Pt->GetYaxis()->SetTitleOffset(1.8);
  grATLAS_2525_RootS13TeV_Psi_JPsi_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  grATLAS_2525_RootS13TeV_Psi_JPsi_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma^{#psi(2S)}}{dp_{T}dy}/B.#frac{d^{2}#sigma^{J/#psi}}{dp_{T}dy}");
  grATLAS_2525_RootS13TeV_Psi_JPsi_Pt->GetYaxis()->SetRangeUser(0.02,0.085);
  grATLAS_2525_RootS13TeV_Psi_JPsi_Pt->GetXaxis()->SetRangeUser(10.0,80.0);
  grATLAS_2525_RootS13TeV_Psi_JPsi_Pt->Draw("AL");
  grATLAS_2525_RootS5TeV_Psi_JPsi_Pt->Draw("Lsame");
  grATLAS_2525_RootS18TeV_Psi_JPsi_Pt->Draw("Lsame");
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->Draw("same");
  
  tb->DrawLatex(0.35,0.20,"(a)");
  gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_DirectPsi_DirectJPsi_Y2525.pdf");
  gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_DirectPsi_DirectJPsi_Y2525.png");



  

  TGraph *grALICE_2045_RootS13TeV_Psi_JPsi_Pt =(TGraph*)file_JPsiCrossSection_13TeV->Get("Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");
  grALICE_2045_RootS13TeV_Psi_JPsi_Pt->SetLineColor(2);
  grALICE_2045_RootS13TeV_Psi_JPsi_Pt->SetLineWidth(4);
  grALICE_2045_RootS13TeV_Psi_JPsi_Pt->SetLineStyle(1);
  
  TGraph *grALICE_2045_RootS5TeV_Psi_JPsi_Pt =(TGraph*)file_JPsiCrossSection_5TeV->Get("Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");
  grALICE_2045_RootS5TeV_Psi_JPsi_Pt->SetLineColor(1);
  grALICE_2045_RootS5TeV_Psi_JPsi_Pt->SetLineWidth(2);
  grALICE_2045_RootS5TeV_Psi_JPsi_Pt->SetLineStyle(9);


  TGraph *grALICE_2045_RootS18TeV_Psi_JPsi_Pt =(TGraph*)file_JPsiCrossSection_18TeV->Get("Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");
  grALICE_2045_RootS18TeV_Psi_JPsi_Pt->SetLineColor(4);
  grALICE_2045_RootS18TeV_Psi_JPsi_Pt->SetLineWidth(2);
  grALICE_2045_RootS18TeV_Psi_JPsi_Pt->SetLineStyle(7);


  TLegend *lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi = new TLegend(0.26,0.75,0.90,0.93);
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetBorderSize(0);
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetFillStyle(0);
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetFillColor(0);
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetTextSize(0.04);
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->AddEntry(grALICE_2045_RootS18TeV_Psi_JPsi_Pt,"pp #surds=1.8 TeV, 2.0 #leq y #leq 4.5","L");
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->AddEntry(grALICE_2045_RootS5TeV_Psi_JPsi_Pt,"pp #surds=5 TeV, 2.0 #leq y #leq 4.5","L");
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->AddEntry(grALICE_2045_RootS13TeV_Psi_JPsi_Pt,"pp #surds=13 TeV, 2.0 #leq y #leq 4.5","L");




  new TCanvas;
  gPad->SetTicks();
  gPad->SetLeftMargin(0.22);
  grALICE_2045_RootS13TeV_Psi_JPsi_Pt->GetYaxis()->SetTitleOffset(1.8);
  grALICE_2045_RootS13TeV_Psi_JPsi_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  grALICE_2045_RootS13TeV_Psi_JPsi_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma^{#psi(2S)}}{dp_{T}dy}/B.#frac{d^{2}#sigma^{J/#psi}}{dp_{T}dy}");
  grALICE_2045_RootS13TeV_Psi_JPsi_Pt->GetYaxis()->SetRangeUser(0.01,0.08);
  grALICE_2045_RootS13TeV_Psi_JPsi_Pt->GetXaxis()->SetRangeUser(5.0,40.0);
  grALICE_2045_RootS13TeV_Psi_JPsi_Pt->Draw("AL");
  grALICE_2045_RootS5TeV_Psi_JPsi_Pt->Draw("Lsame");
  grALICE_2045_RootS18TeV_Psi_JPsi_Pt->Draw("Lsame");
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->Draw("same");

  tb->DrawLatex(0.35,0.20,"(b)");
  gPad->SaveAs("Plots/Fig_ALICE_2045_RootS5TeV_Psi_JPsi_Pt.pdf");
  gPad->SaveAs("Plots/Fig_ALICE_2045_RootS5TeV_Psi_JPsi_Pt.png");






}

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


//================== CMS: open the calculated root file ===========================================//
TFile *file_CMS_RootS7TeV_Psi2SCrossSection =  new TFile("CMS_RootS7TeV_Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//
TGraphAsymmErrors *Data_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt();
TGraphAsymmErrors *Data_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt();




//================== ATLAS: open the calculated root file ===========================================//
TFile *file_ATLAS_RootS7TeV_Psi2SCrossSection =  new TFile("ATLAS_RootS7TeV_Y0025_Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//
TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_PromptPsi2S_Y0025_Pt();



//================== CDF: open the calculated root file ===========================================//
TFile *file_CDF_RootS196TeV_Psi2SCrossSection =  new TFile("CDF_RootS196TeV_Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//
TGraphAsymmErrors *Data_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt();


//================== LHCb: open the calculated root file ===========================================//
TFile *file_LHCb_RootS7TeV_Psi2SCrossSection =  new TFile("LHCb_RootS7TeV_Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//
TGraphAsymmErrors *Data_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt();






Double_t CMS_FitLDME(Double_t *x, Double_t *par);
Double_t ATLAS_FitLDME(Double_t *x, Double_t *par);
Double_t CDF_FitLDME(Double_t *x, Double_t *par);
Double_t LHCb_FitLDME(Double_t *x, Double_t *par);


//================ Global Fittings ================================//
Double_t fcn1(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn2(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);


TGraphAsymmErrors *gr1;
TGraphAsymmErrors *gr2;
TGraphAsymmErrors *gr3;
TGraphAsymmErrors *gr4;


TGraph *Scale_QCDSigma(TGraph *InGraph, Double_t LDME);
TGraph *Add_QCDSigma(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3,TGraph *InGraph4);

const Double_t mC = 1.6;

void Psi2SLDME()
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
  cout<<" ===================== FITTING CMS DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  cout<<" getting Data Graph 1: "<<endl;
  TGraphAsymmErrors *grfData_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt=new TGraphAsymmErrors();
  grfData_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt=Data_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt();

  cout<<" getting Data Graph 2: "<<endl;
  TGraphAsymmErrors *grfData_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt=new TGraphAsymmErrors();
  grfData_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt=Data_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt();


  TMultiGraph *mg = new TMultiGraph();
  mg->Add(grfData_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt);
  //mg->Add(grfData_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt);
  //mg->Add(grfData_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt);
  mg->SetTitle("title;p_{T}[GeV/c]; #frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  mg->Draw("zAP");
  mg->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();

  

  TF1 *CMSFitFunctionLDME = new TF1("CMSFitFunctionLDME", CMS_FitLDME, 5.0, 100, 3);
  CMSFitFunctionLDME->SetLineColor(2);

  //  0       1     2      3       4     5
  // 3S1_1, 1S0_8, 3S1_8, 3P0_8, 3P1_8, 3P2_8
  CMSFitFunctionLDME->FixParameter(0,1);                         
  CMSFitFunctionLDME->SetParameter(1,0.0080);                         
  CMSFitFunctionLDME->SetParameter(2,0.0033);                          
  
  //CMSFitFunctionLDME->FixParameter(1,0.027);                         
  //CMSFitFunctionLDME->FixParameter(2,0.002);

  //CMSFitFunctionLDME->SetParLimits(0,0.5,20.0);
  

  
  
  /*
  CMSFitFunctionLDME->FixParameter(1,0.0080);                         
  CMSFitFunctionLDME->FixParameter(2,0.0033);                          
  CMSFitFunctionLDME->FixParameter(3,0.0080*mC*mC);                    
  CMSFitFunctionLDME->FixParameter(4,3.0*0.0080*mC*mC);                    
  CMSFitFunctionLDME->FixParameter(5,5.0*0.0080*mC*mC);       
  */

  //grfData_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt->Fit("FitFunctionLDME","Q0","MER", 10, 100);

  mg->Fit("CMSFitFunctionLDME","Q0","MER", 5, 100);
  


  Double_t CMS_Chi2 = CMSFitFunctionLDME->GetChisquare();
  Double_t CMS_NDF = CMSFitFunctionLDME->GetNDF();
  Double_t CMS_Prob = CMSFitFunctionLDME->GetProb();
  
  Double_t CMS_LDME_3S1_1 = CMSFitFunctionLDME->GetParameter(0);
  Double_t CMS_LDME_1S0_8 = CMSFitFunctionLDME->GetParameter(1);
  Double_t CMS_LDME_3S1_8 = CMSFitFunctionLDME->GetParameter(2);
  
  Double_t CMS_LDME_3P0_8 = CMS_LDME_1S0_8*mC*mC;
  Double_t CMS_LDME_3P1_8 = 3.0*CMS_LDME_3P0_8;
  Double_t CMS_LDME_3P2_8 = 5.0*CMS_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<CMS_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<CMS_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<CMS_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<CMS_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<CMS_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<CMS_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<CMS_Chi2<<"/"<<CMS_NDF<<" Prob: "<<CMS_Prob<<endl<<endl;


  TGraph *Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, CMS_LDME_3S1_1);
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, CMS_LDME_1S0_8);
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, CMS_LDME_3S1_8);
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, CMS_LDME_3P0_8);
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, CMS_LDME_3P1_8);
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, CMS_LDME_3P2_8);
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  TLegend *lgd_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  lgd_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  mg->Draw("zAP");
  CMSFitFunctionLDME->Draw("same");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_Pt->Draw("same");




  TGraph *Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_DSigmaDPtDY_Pt1->AddEntry(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_DSigmaDPtDY_Pt1->AddEntry(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt1->AddEntry(Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  mg->Draw("zAP");
  CMSFitFunctionLDME->Draw("same");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_Pt1->Draw("same");




  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING ATLAS DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  cout<<" getting ATLAS Data Graph: "<<endl;
  TGraphAsymmErrors *grfData_ATLAS_Latest_D2NDPtDy_PromptPsi2S_Y0025_Pt=new TGraphAsymmErrors();
  grfData_ATLAS_Latest_D2NDPtDy_PromptPsi2S_Y0025_Pt=Data_ATLAS_D2NDPtDy_PromptPsi2S_Y0025_Pt();

 

  TF1 *ATLASFitFunctionLDME = new TF1("ATLASFitFunctionLDME", ATLAS_FitLDME, 5.0, 100, 3);
  ATLASFitFunctionLDME->SetLineColor(2);

  //  0       1     2      3       4     5
  // 3S1_1, 1S0_8, 3S1_8, 3P0_8, 3P1_8, 3P2_8
  ATLASFitFunctionLDME->FixParameter(0,1);                         
  
  //ATLASFitFunctionLDME->SetParameter(1,0.0080);                         
  //ATLASFitFunctionLDME->SetParameter(2,0.0033);                          
  //ATLASFitFunctionLDME->SetParLimits(0,0.5,20.0);
  
  //ATLASFitFunctionLDME->FixParameter(1,0.027);                         
  //ATLASFitFunctionLDME->FixParameter(2,0.002);

  grfData_ATLAS_Latest_D2NDPtDy_PromptPsi2S_Y0025_Pt->Fit("ATLASFitFunctionLDME","Q0","MER", 5, 100);
  
  Double_t ATLAS_Chi2 = ATLASFitFunctionLDME->GetChisquare();
  Double_t ATLAS_NDF = ATLASFitFunctionLDME->GetNDF();
  Double_t ATLAS_Prob = ATLASFitFunctionLDME->GetProb();
  
  Double_t ATLAS_LDME_3S1_1 = ATLASFitFunctionLDME->GetParameter(0);
  Double_t ATLAS_LDME_1S0_8 = ATLASFitFunctionLDME->GetParameter(1);
  Double_t ATLAS_LDME_3S1_8 = ATLASFitFunctionLDME->GetParameter(2);
  
  Double_t ATLAS_LDME_3P0_8 = ATLAS_LDME_1S0_8*mC*mC;
  Double_t ATLAS_LDME_3P1_8 = 3.0*ATLAS_LDME_3P0_8;
  Double_t ATLAS_LDME_3P2_8 = 5.0*ATLAS_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<ATLAS_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<ATLAS_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<ATLAS_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<ATLAS_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<ATLAS_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<ATLAS_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<ATLAS_Chi2<<"/"<<ATLAS_NDF<<" Prob: "<<ATLAS_Prob<<endl<<endl;


  TGraph *Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, ATLAS_LDME_3S1_1);
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, ATLAS_LDME_1S0_8);
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, ATLAS_LDME_3S1_8);
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, ATLAS_LDME_3P0_8);
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, ATLAS_LDME_3P1_8);
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, ATLAS_LDME_3P2_8);
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  TLegend *lgd_ATLASDSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  lgd_ATLASDSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_ATLASDSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_ATLASDSigmaDPtDY_Pt->SetFillColor(0);
  lgd_ATLASDSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_ATLASDSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLASDSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_ATLASDSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_ATLASDSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_ATLASDSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_ATLASDSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");



  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_Latest_D2NDPtDy_PromptPsi2S_Y0025_Pt->Draw("zAP");
  ATLASFitFunctionLDME->Draw("same");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_ATLASDSigmaDPtDY_Pt->Draw("same");




  TGraph *Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_ATLASDSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_ATLASDSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_ATLASDSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_ATLASDSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_ATLASDSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_ATLASDSigmaDPtDY_Pt1->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLASDSigmaDPtDY_Pt1->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_ATLASDSigmaDPtDY_Pt1->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_Latest_D2NDPtDy_PromptPsi2S_Y0025_Pt->Draw("zAP");
  ATLASFitFunctionLDME->Draw("same");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_ATLASDSigmaDPtDY_Pt1->Draw("same");




 
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING CDF DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  cout<<" getting CDF Data Graph : "<<endl;
  TGraphAsymmErrors *grfData_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt=new TGraphAsymmErrors();
  grfData_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt=Data_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt();
  
  TF1 *CDFFitFunctionLDME = new TF1("CDFFitFunctionLDME", CDF_FitLDME, 5.0, 100, 3);
  CDFFitFunctionLDME->SetLineColor(2);
  CDFFitFunctionLDME->FixParameter(0,1.0);     

  //CDFFitFunctionLDME->FixParameter(1,0.027);                         
  //CDFFitFunctionLDME->FixParameter(2,0.002);

  //CDFFitFunctionLDME->SetParLimits(0,0.5,20.0);                         

  //CDFFitFunctionLDME->FixParameter(0,CMS_LDME_1S0_8);                         
  //CDFFitFunctionLDME->FixParameter(1,CMS_LDME_3S1_8);                          
  
  grfData_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->Fit("CDFFitFunctionLDME","Q0","MER", 5.0, 100.0);
  
  Double_t CDF_LDME_3S1_1 = CDFFitFunctionLDME->GetParameter(0);
  Double_t CDF_LDME_1S0_8 = CDFFitFunctionLDME->GetParameter(1);
  Double_t CDF_LDME_3S1_8 = CDFFitFunctionLDME->GetParameter(2);
  Double_t CDF_LDME_3P0_8 = CDF_LDME_1S0_8*mC*mC;
  Double_t CDF_LDME_3P1_8 = 3.0*CDF_LDME_3P0_8;
  Double_t CDF_LDME_3P2_8 = 5.0*CDF_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<CDF_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<CDF_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<CDF_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<CDF_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<CDF_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<CDF_LDME_3P2_8<<endl<<endl;

  
  TGraph *Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit, CDF_LDME_3S1_1);
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit, CDF_LDME_1S0_8);
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit, CDF_LDME_3S1_8);
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit, CDF_LDME_3P0_8);
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit, CDF_LDME_3P1_8);
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit, CDF_LDME_3P2_8);
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  TLegend *lgd_DSigmaDPtDY_Pt2 = new TLegend(0.65,0.57,0.88,0.93);
  lgd_DSigmaDPtDY_Pt2->SetBorderSize(0);
  lgd_DSigmaDPtDY_Pt2->SetFillStyle(0);
  lgd_DSigmaDPtDY_Pt2->SetFillColor(0);
  lgd_DSigmaDPtDY_Pt2->SetTextSize(0.03);
  
  lgd_DSigmaDPtDY_Pt2->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_DSigmaDPtDY_Pt2->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt2->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt2->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt2->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt2->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->Draw("zAP");
  CDFFitFunctionLDME->Draw("same");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_Pt2->Draw("same");



  TGraph *Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  


  TLegend *lgd_DSigmaDPtDY_Pt3 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_DSigmaDPtDY_Pt3->SetBorderSize(0);
  lgd_DSigmaDPtDY_Pt3->SetFillStyle(0);
  lgd_DSigmaDPtDY_Pt3->SetFillColor(0);
  lgd_DSigmaDPtDY_Pt3->SetTextSize(0.03);

  lgd_DSigmaDPtDY_Pt3->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_DSigmaDPtDY_Pt3->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt3->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->Draw("zAP");
  CDFFitFunctionLDME->Draw("same");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_Pt3->Draw("same");


  
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING LHCb DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  cout<<" getting LHCbData Graph : "<<endl;
  TGraphAsymmErrors *grfData_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt=new TGraphAsymmErrors();
  grfData_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt=Data_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt();

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt->Draw("zAP");
  grfData_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();

  
  TF1 *LHCbFitFunctionLDME = new TF1("LHCbFitFunctionLDME", LHCb_FitLDME, 5.0, 100, 3);
  LHCbFitFunctionLDME->SetLineColor(2);
  LHCbFitFunctionLDME->FixParameter(0,1.0);   

  //LHCbFitFunctionLDME->FixParameter(1,0.027);                         
  //LHCbFitFunctionLDME->FixParameter(2,0.002);

  //  0       1     2      3       4     5
  // 3S1_1, 1S0_8, 3S1_8, 3P0_8, 3P1_8, 3P2_8
  //
  //LHCbFitFunctionLDME->FixParameter(1,CMS_LDME_3S1_8);   

  grfData_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt->Fit("LHCbFitFunctionLDME","Q0","MER", 5, 100);
  
  Double_t LHCb_LDME_3S1_1 = LHCbFitFunctionLDME->GetParameter(0);
  Double_t LHCb_LDME_1S0_8 = LHCbFitFunctionLDME->GetParameter(1);
  Double_t LHCb_LDME_3S1_8 = LHCbFitFunctionLDME->GetParameter(2);
  Double_t LHCb_LDME_3P0_8 = LHCb_LDME_1S0_8*mC*mC;
  Double_t LHCb_LDME_3P1_8 = 3.0*LHCb_LDME_3P0_8;
  Double_t LHCb_LDME_3P2_8 = 5.0*LHCb_LDME_3P0_8;
  
  cout<<"LDME : 3S1_1 "<<LHCb_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<LHCb_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<LHCb_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<LHCb_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<LHCb_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<LHCb_LDME_3P2_8<<endl<<endl;
  
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, LHCb_LDME_3S1_1);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, LHCb_LDME_1S0_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, LHCb_LDME_3S1_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, LHCb_LDME_3P0_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, LHCb_LDME_3P1_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, LHCb_LDME_3P2_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);
  
  TLegend *lgd_DSigmaDPtDY_Pt4 = new TLegend(0.50,0.50,0.88,0.94);
  lgd_DSigmaDPtDY_Pt4->SetBorderSize(0);
  lgd_DSigmaDPtDY_Pt4->SetFillStyle(0);
  lgd_DSigmaDPtDY_Pt4->SetFillColor(0);
  lgd_DSigmaDPtDY_Pt4->SetTextSize(0.03);
  
  lgd_DSigmaDPtDY_Pt4->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_DSigmaDPtDY_Pt4->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt4->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt4->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt4->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt4->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt->Draw("zAP");
  LHCbFitFunctionLDME->Draw("same");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_Pt4->Draw("same");
  

  
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_DSigmaDPtDY_Pt5 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_DSigmaDPtDY_Pt5->SetBorderSize(0);
  lgd_DSigmaDPtDY_Pt5->SetFillStyle(0);
  lgd_DSigmaDPtDY_Pt5->SetFillColor(0);
  lgd_DSigmaDPtDY_Pt5->SetTextSize(0.03);

  lgd_DSigmaDPtDY_Pt5->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_DSigmaDPtDY_Pt5->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_DSigmaDPtDY_Pt5->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt->Draw("zAP");
  LHCbFitFunctionLDME->Draw("same");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_Pt5->Draw("same");


    
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== COMBINED FITTING ========================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;


  gr1=new TGraphAsymmErrors();
  gr1=Data_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt();

  gr2=new TGraphAsymmErrors();
  gr2=Data_ATLAS_D2NDPtDy_PromptPsi2S_Y0025_Pt();

  gr3=new TGraphAsymmErrors();
  gr3=Data_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt();

  gr4=new TGraphAsymmErrors(); 
  gr4=Data_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt();



  //---------------------------------------------------------------------
  //     Blocks for fitting procedure
  //---------------------------------------------------------------------
  const Int_t npars = 3;
  TMinuit *gMinuit = new TMinuit(npars);  //initialize TMinuit with a maximum of 3 params
  gMinuit->SetFCN(fcn);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  arglist[0] = 1;
  gMinuit->mnexcm("SET ERR", arglist, 1, ierflg);
  
  // Set starting values and step sizes for parameters
  static Double_t vstart[] = {1.0,0.0080,0.0033};
  static Double_t step[]   = {0.0001,0.00001 , 0.00001};


  gMinuit->mnparm(0, "3S1_1", vstart[0], step[0], 0, 0, ierflg);
  gMinuit->mnparm(1, "1S0_8", vstart[1], step[1], 0, 0, ierflg);
  gMinuit->mnparm(2, "3S1_8", vstart[2], step[2], 0, 0, ierflg);
    
  gMinuit->FixParameter(0);
  // Now ready for minimization step
  arglist[0] = 500;
  arglist[1] = 1.;
  gMinuit->mnexcm("MIGRAD", arglist, 2, ierflg);
  
  // Print results
  Double_t amin,edm,errdef;
  Int_t nvpar,nparx,icstat;
  gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);

  Int_t iuext;
  TString chnam;   // The name of the parameter
  Double_t val;    // The current (external) value of the parameter 
  Double_t errl;   // The current estimate of the parameter uncertainty  
  Double_t xlolim; // The lower bound (or zero if no limits)
  Double_t xuplim; // The upper bound (or zero if no limits)
  Int_t iuint;     // The internal parameter number 
 
 Int_t i = 0;
  Double_t currentPar[npars] = {0};
  for (i=0; i< npars;i++) {
    gMinuit->mnpout(i, chnam, currentPar[i], errl, xlolim, xuplim, iuint);
  }

  TMultiGraph *gl_mg = new TMultiGraph();
  gl_mg->Add(gr1);
  gl_mg->Add(gr2);
  //gl_mg->Add(gr3);
  gl_mg->SetTitle("title;p_{T}[GeV/c]; #frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gl_mg->Draw("zAP");
  gl_mg->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();

  TF1 *fun_1=new TF1("fun_1",CMS_FitLDME, 5.0, 100, 3); 	
  fun_1->SetParameters(currentPar);
  fun_1->SetLineColor(kBlue);
  fun_1->SetLineStyle(1);
  fun_1->SetLineWidth(2);
  //fun_1->Draw("same");
  
  TF1 *fun_2=new TF1("fun_2",ATLAS_FitLDME, 5.0, 100, 3);
  fun_2->SetParameters(currentPar);
  fun_2->SetLineColor(kRed);
  fun_2->SetLineStyle(1);
  fun_2->SetLineWidth(4);
  //fun_2->Draw("same");

  
  TF1 *fun_3=new TF1("fun_2",CDF_FitLDME, 4.0, 30, 3);
  fun_3->SetParameters(currentPar);
  fun_3->SetLineColor(kGreen);
  fun_3->SetLineStyle(1);
  fun_3->SetLineWidth(4);
  //fun_3->Draw("same");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gl_mg->Draw("zAP");
  gl_mg->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_1->Draw("same");
  fun_2->Draw("same");
  //fun_3->Draw("same");


  cout<<endl<<endl;
  cout<<" combined fitting perameters "<<endl;
  cout<<"LDME : 3S1_1 "<<currentPar[0]<<endl;
  cout<<"LDME : 1S0_8 "<<currentPar[1]<<endl;
  cout<<"LDME : 3S1_8 "<<currentPar[2]<<endl;





  /*
  //================ Draw All Data Graphs ======================//
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  TMultiGraph *data_mg = new TMultiGraph();
  data_mg->Add(grfData_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt);
  data_mg->Add(grfData_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt);
  data_mg->Add(grfData_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt);
  data_mg->Add(grfData_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt);
  data_mg->Add(grfData_ATLAS_D2NDPtDy_PromptPsi2S_Y0025_Pt);
  data_mg->SetTitle("title;p_{T}[GeV/c]; #frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  data_mg->Draw("zAP");
  data_mg->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_PromptPsi2S_Y0025_Pt->Draw("zAP");
  */


  return;







}


Double_t CMS_FitLDME(Double_t *x, Double_t *par)
{

 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  //Double_t Norm = par[3];

  Double_t LDME_3P0_8;
  Double_t LDME_3P1_8;
  Double_t LDME_3P2_8;

  LDME_3P0_8 = mC*mC*LDME_1S0_8;
  LDME_3P1_8=3.0*LDME_3P0_8;
  LDME_3P2_8=5.0*LDME_3P0_8;
  
  Double_t Sigma = (LDME_3S1_1*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_1S0_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]) + 
		    LDME_3S1_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) + LDME_3P0_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Eval(x[0]) + 
		    LDME_3P1_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Eval(x[0])+ LDME_3P2_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Eval(x[0]));
  
  return Sigma;
  
}



Double_t ATLAS_FitLDME(Double_t *x, Double_t *par)
{

 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  //Double_t Norm = par[3];

  Double_t LDME_3P0_8;
  Double_t LDME_3P1_8;
  Double_t LDME_3P2_8;

  LDME_3P0_8 = mC*mC*LDME_1S0_8;
  LDME_3P1_8=3.0*LDME_3P0_8;
  LDME_3P2_8=5.0*LDME_3P0_8;
  
  Double_t Sigma = (LDME_3S1_1*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_1S0_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]) + 
		    LDME_3S1_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) + LDME_3P0_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Eval(x[0]) + 
		    LDME_3P1_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Eval(x[0])+ LDME_3P2_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Eval(x[0]));
  
  return Sigma;
  
}






Double_t CDF_FitLDME(Double_t *x, Double_t *par)
{

  Double_t LDME_3S1_1 = par[0];
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
    
  Double_t LDME_3P0_8;
  Double_t LDME_3P1_8;
  Double_t LDME_3P2_8;

  LDME_3P0_8 = mC*mC*LDME_1S0_8;
  LDME_3P1_8=3.0*LDME_3P0_8;
  LDME_3P2_8=5.0*LDME_3P0_8;

  Double_t Sigma = LDME_3S1_1*grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_1S0_8*grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0])+ 
    LDME_3S1_8*grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) + LDME_3P0_8*grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Eval(x[0]) + 
    LDME_3P1_8*grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Eval(x[0])+ LDME_3P2_8*grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Eval(x[0]);
  
  return Sigma;
  
}

Double_t LHCb_FitLDME(Double_t *x, Double_t *par)
{
  Double_t LDME_3S1_1 = par[0];
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  Double_t LDME_3P0_8;
  Double_t LDME_3P1_8;
  Double_t LDME_3P2_8;

   
  LDME_3P0_8 = mC*mC*LDME_1S0_8;
  LDME_3P1_8=3.0*LDME_3P0_8;
  LDME_3P2_8=5.0*LDME_3P0_8;
  
  Double_t Sigma = LDME_3S1_1*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_1S0_8*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]) + 
    LDME_3S1_8*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) + LDME_3P0_8*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Eval(x[0]) + 
    LDME_3P1_8*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Eval(x[0])+ LDME_3P2_8*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Eval(x[0]);
  
  return Sigma;
  
}


//______________________________________________________________________________
Double_t fcn1(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag)
{
  const Int_t nbins = gr1->GetN();
  Int_t i;
  Double_t xx1[nbins];
  Double_t yy1[nbins];
  Double_t erryy1[nbins];
  
  
  for (Int_t j=0;j<nbins; j++) 
    {
      gr1->GetPoint(j,xx1[j],yy1[j]);
      erryy1[j]= gr1->GetErrorY(j);
    }

  //calculate chisquare
  Double_t chisq = 0;
  for (i=0;i<  nbins; i++) {
    Double_t delta  = (yy1[i]-CMS_FitLDME(&xx1[i],par))/erryy1[i];
    chisq += delta*delta;
  }
  return chisq;
}

//______________________________________________________________________________
Double_t fcn2(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag)
{ 
  
  const Int_t nbins = gr2->GetN();
  Int_t i;
  
  Double_t xx2[nbins]; 
  Double_t yy2[nbins];
  Double_t erryy2[nbins];

  for (Int_t j=0;j<nbins; j++) 
    {
      gr2->GetPoint(j,xx2[j],yy2[j]);
      erryy2[j]= gr2->GetErrorY(j);
    }

 //calculate chisquare
  Double_t chisq = 0;
  for (i=0;i<  nbins; i++) {
    //Double_t delta  = (y2[i]-myFunc_2(&x2[i],par))/ey2[i];
    Double_t delta  = (yy2[i]-ATLAS_FitLDME(&xx2[i],par))/erryy2[i];
    chisq += delta*delta;
  }
  return chisq;
}


//______________________________________________________________________________
Double_t fcn3(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag)
{ 
  
  const Int_t nbins = gr3->GetN();
  Int_t i;
  
  Double_t xx3[nbins]; 
  Double_t yy3[nbins];
  Double_t erryy3[nbins];

  for (Int_t j=0;j<nbins; j++) 
    {
      gr3->GetPoint(j,xx3[j],yy3[j]);
      erryy3[j]= gr3->GetErrorY(j);
    }

 //calculate chisquare
  Double_t chisq = 0;
  for (i=0;i<nbins; i++) {
    //Double_t delta  = (y2[i]-myFunc_2(&x2[i],par))/ey2[i];
    Double_t delta  = (yy3[i]-CDF_FitLDME(&xx3[i],par))/erryy3[i];
    chisq += delta*delta;
  }
  return chisq;
}



//______________________________________________________________________________
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
  f = fcn1(npar,gin,par, iflag) + fcn2(npar,gin, par, iflag);
  //f = fcn1(npar,gin,par, iflag) + fcn3(npar,gin, par, iflag);
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




TGraphAsymmErrors *Data_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt()
{
  //
  const int NN = 19;

  // X value (pT)
  Double_t p8319_d1x1y1_xval[NN] = {10.5, 11.5, 12.5, 13.5, 14.5, 15.5, 16.5, 17.5, 18.5, 
    19.5, 21.1, 23.6, 26.1, 28.7, 32.2, 37.2, 45.5, 62.4, 84.1};
  
  
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.1000000000000014, 
					 1.1000000000000014, 1.1000000000000014, 1.1999999999999993, 2.200000000000003, 
					 2.200000000000003, 5.5, 7.399999999999999, 9.099999999999994};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1.3999999999999986, 1.3999999999999986, 
					1.3999999999999986, 1.3000000000000007, 2.799999999999997, 2.799999999999997, 9.5, 12.600000000000001, 
					15.900000000000006};
  
  // Y Value (B*d2Sigma/dpTdy)  
  Double_t p8319_d1x1y1_yval[NN] = {38.0, 24.1, 15.4, 10.2, 7.15, 4.79, 3.48, 2.52, 1.87, 
    1.34, 0.857, 0.461, 0.269, 0.165, 0.0842, 0.0347, 0.0102, 0.00235, 5.62E-4};
  
  
  // could not comform these values
  /*
  Double_t p8319_d1x1y1_yerrminus[NN] = {2.994346673316234, 1.4998589933723767, 0.872326773634743, 0.5494606446325342, 0.38020278799609036, 0.26125627265196905, 
					 0.18547174987043175, 0.13869340287122528, 0.1012699856818396, 0.07589519088848778, 0.049967989753441154, 
					 0.027793704323101662, 0.018381689258607326, 0.011822664674260198, 0.006161671851048221, 0.0034377709347773594, 
					 0.0010926362615253074, 4.183390490977384E-4, 1.5471069775552045E-4};
  
  Double_t p8319_d1x1y1_yerrplus[NN] = {2.994346673316234, 1.4998589933723767, 0.872326773634743, 0.5494606446325342, 0.38020278799609036, 0.26125627265196905, 
					0.18547174987043175, 0.13869340287122528, 0.1012699856818396, 0.07589519088848778, 0.049967989753441154, 0.027793704323101662, 
					0.018381689258607326, 0.011822664674260198, 0.006161671851048221, 0.0034377709347773594, 0.0010926362615253074, 4.183390490977384E-4, 
					1.5471069775552045E-4};
  */
  
  Double_t p8319_d1x1y1_ystatminus[NN] = {0.296, 0.194, 0.137, 0.101, 0.0796, 0.0622, 0.0511, 0.0419, 0.0352, 
					  0.0294, 0.0144, 0.0102, 0.00772, 0.00607, 0.00299, 0.002, 6.66E-4, 2.99E-4, 1.37E-4};
  Double_t p8319_d1x1y1_ystatplus[NN] = { 0.296, 0.194, 0.137, 0.101, 0.0796, 0.0622, 0.0511, 0.0419, 0.0352, 
					  0.0294, 0.0144, 0.0102, 0.00772, 0.00607, 0.00299, 0.002, 6.66E-4, 2.99E-4, 1.37E-4};
  
  
  Double_t p8319_d1x1y1_ysystminus[NN] = {2.86000, 1.39000, 0.79200, 0.49100, 0.33700, 0.23100, 0.16100, 0.12000, 0.08560, 0.06340, 0.04400, 
					  0.02380, 0.01560, 0.00947, 0.00506, 0.00269, 0.00084, 0.00029, 0.00007};
  
  Double_t p8319_d1x1y1_ysystplus[NN] = {2.86000, 1.39000, 0.79200, 0.49100, 0.33700, 0.23100, 0.16100, 0.12000, 0.08560, 0.06340, 0.04400, 
					  0.02380, 0.01560, 0.00947, 0.00506, 0.00269, 0.00084, 0.00029, 0.00007};
  
  
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] =  {0.0};


  Double_t pbTonb =1.0/1000.0;
  Double_t DeltaY = 1.0;

for(int j=0;j<NN;j++){

  p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j]) + (p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
  p8319_d1x1y1_yerrplus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j]) + (p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
  
  p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_ystatminus[j]= (p8319_d1x1y1_ystatminus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_ystatplus[j]=(p8319_d1x1y1_ystatplus[j]*pbTonb)/DeltaY;
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
  
  /*
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
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt,"CMS prompt #psi(2S), high p_{T}", "P");
  */
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt;
  return OutGraph;
  
}





TGraphAsymmErrors *Data_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt()
{
  //This data is from 1111.1557
  const int NN = 9;

  Double_t p8319_d1x1y1_xval[NN] = {7.6, 8.54, 9.5, 10.5, 11.48, 12.72, 14.23, 16.3, 21.92};
  Double_t p8319_d1x1y1_xvallow[NN]={6.50, 8.00, 9.00, 10.00, 11.00, 12.00, 13.50, 15.00, 18.00};
  Double_t p8319_d1x1y1_xvalhigh[NN]={8.00, 9.00, 10.00, 11.00, 12.00, 13.50, 15.00, 18.00, 30.00};

  //========== d2Sigma/dpT*dy  
  Double_t p8319_d1x1y1_yval[NN] = {0.148, 0.083, 0.061, 0.0368, 0.0217, 0.0141, 0.0077, 0.00368, 6.6E-4};
  double p8319_d1x1y1_ystatminus[NN] = { 0.029, 0.008, 0.005, 0.0031, 0.0019, 0.0011, 7.0E-4, 3.0E-4, 5.0E-5 };
  double p8319_d1x1y1_ystatplus[NN] = { 0.029, 0.008, 0.005, 0.0031, 0.0019, 0.0011, 7.0E-4, 3.0E-4, 5.0E-5 };

  double p8319_d1x1y1_ysystminus[NN] = {0.02000, 0.00600, 0.00400, 0.00230, 0.00220, 0.00100, 0.00060, 0.00017, 0.00005};
  double p8319_d1x1y1_ysystplus[NN] = {0.02000, 0.00600, 0.00400, 0.00230, 0.00220, 0.00100, 0.00060, 0.00017, 0.00005};


  Double_t p8319_d1x1y1_xerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.0};


  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.0};

  //Double_t DeltaY = 2.4;
  
  for(int j=0;j<NN;j++){
    
    p8319_d1x1y1_xerrminus[j] = p8319_d1x1y1_xval[j] - p8319_d1x1y1_xvallow[j]; 
    p8319_d1x1y1_xerrplus[j] = p8319_d1x1y1_xvalhigh[j]-p8319_d1x1y1_xval[j];
    
    p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j]) + (p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
    p8319_d1x1y1_yerrplus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j]) + (p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
    
    p8319_d1x1y1_yval[j] = p8319_d1x1y1_yval[j];
    p8319_d1x1y1_yerrminus[j]= p8319_d1x1y1_yerrminus[j];
    p8319_d1x1y1_yerrplus[j]= p8319_d1x1y1_yerrplus[j];
   
  }
 


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerStyle(21);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerColor(4);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,30.0);
   

  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  /*
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
  */
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt;
  return OutGraph;
 
}





TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_PromptPsi2S_Y0025_Pt()
{
  //This data is from 1512.03657
  const int NN = 21;

  Double_t p8319_d1x1y1_xval[NN] = {8.25,8.75,9.25,9.75,10.25,10.75,11.25,11.75,12.5,13.5,14.5,15.5,16.5,17.5,19.0,21.0,23.0,25.0,28.0,35.0,50.0};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.5,0.5,0.5,0.5,0.5,0.5,1.0,1.0,1.0,1.0,2.0,5.0,10.0};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.5,0.5,0.5,0.5,0.5,0.5,1.0,1.0,1.0,1.0,2.0,5.0,10.0};
  
  
  Double_t p8319_d1x1y1_yval[NN] = {0.1045,0.08281,0.07253,0.05651,0.04059,0.03447,0.02581,0.02077,0.01460,0.01012,0.006342,0.004370,
				    0.003078,0.002171, 0.001429,0.0009215,0.0005173,0.0003584,0.0002468,0.00005755,0.000006824};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0059,0.00337,0.00253,0.00183,0.00147,0.00114,0.00098,0.00080,0.00045,0.00035,0.000251,
					 0.000204,0.000161,0.000140,0.000076,0.0000590,0.0000445,0.0000383,0.0000206,0.00000735,0.000001772};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.0059,0.00337,0.00253,0.00183,0.00147,0.00114,0.00098,0.00080,0.00045,0.00035,0.000251,
					0.000204,0.000161,0.000140,0.000076,0.0000590,0.0000445,0.0000383,0.0000206,0.00000735,0.000001772};
  //Double_t BRPsi2SToMuMu = 0.00772;
  Double_t BRPsi2SToMuMu = 1.0;
  Double_t DeltaY = (1.0); 
  
for(int j=0;j<NN;j++){
  p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j]*BRPsi2SToMuMu)/DeltaY;
  p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j]*BRPsi2SToMuMu)/DeltaY;
  p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j]*BRPsi2SToMuMu)/DeltaY;
  
  }
  
  TGraphAsymmErrors *Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt->SetMarkerStyle(34);
  Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt->SetMarkerColor(6);
  Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt->SetMarkerSize(1.6);
  Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt->GetYaxis()->SetRangeUser(0.000001,1000.0);
  
  TAxis *Xaxis1 = Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,60.0);
   

  Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt->GetYaxis()->SetTitle("#frac{d#sigma}{dp_{T}}[nb/GeV]");
  
   
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_D2NDPtDy_PromptPsi2S_0025_Pt;
  return OutGraph;
 
}



TGraphAsymmErrors *Data_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt()
{
  //Data Link
  //http://hepdata.cedar.ac.uk/view/ins820328/d1/root;jsessionid=ktowo4y2rrzg
  const int NN = 25;

  Double_t p8319_d1x1y1_xval[NN] = {2.25, 2.75, 3.25, 3.75, 4.25, 4.75, 5.25, 5.75, 6.25, 
				    6.75, 7.25, 7.75, 8.25, 8.75, 9.25, 9.75, 10.5, 11.5, 12.5, 
				    13.5, 14.5, 16.375, 18.875, 22.5, 27.5};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 
					 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.5, 0.5, 0.5, 
					 0.5, 0.5, 1.375, 1.125, 2.5, 2.5};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 
					0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.5, 0.5, 0.5, 
					0.5, 0.5, 1.375, 1.125, 2.5, 2.5};
  
  
  Double_t p8319_d1x1y1_yval[NN] = {953.0, 946.0, 856.0, 630.0, 483.0, 383.0, 248.0, 204.0, 143.0, 
				    111.0, 77.1, 59.8, 42.1, 30.5, 21.8, 17.2, 11.4, 7.72, 4.56, 
				    				    2.85, 1.93, 0.85, 0.35, 0.15, 0.053};
  /*
  Double_t p8319_d1x1y1_yerrminus[NN] = {125.23977004130916, 100.90094152187085, 90.24965373894794, 63.60031446463138, 50.695167422546305, 
					 40.26164427839479, 24.041630560342615, 19.924858845171276, 13.601470508735444, 10.44030650891055, 
					 7.561084578286372, 5.88727441181401, 4.254409477236529, 2.9966648127543394, 2.195449840010015, 
					 1.8027756377319946, 1.1364858116140297, 0.8130190649671137, 0.518555686498567, 0.3538361202590827, 
					 0.25612496949731395, 0.1140175425099138, 0.0670820393249937, 0.03162277660168379, 0.043462627624201465};
  Double_t p8319_d1x1y1_yerrplus[NN] = {25.23977004130916, 100.90094152187085, 90.24965373894794, 63.60031446463138, 50.695167422546305, 
					40.26164427839479, 24.041630560342615, 19.924858845171276, 13.601470508735444,10.44030650891055, 
					7.561084578286372, 5.88727441181401, 4.254409477236529, 2.9966648127543394, 2.195449840010015, 
					1.8027756377319946, 1.1364858116140297, 0.8130190649671137, 0.518555686498567, 0.3538361202590827, 
					0.25612496949731395, 0.1140175425099138, 0.0670820393249937, 0.03162277660168379, 0.043462627624201465};
  
  */

  Double_t p8319_d1x1y1_ystatminus[NN] = {54.0, 34.0, 24.0, 18.0, 13.0, 10.0, 7.0, 6.0, 4.0, 
					  3.0, 2.6, 2.1, 1.7, 1.3, 1.1, 1.0, 0.54, 0.43, 0.33, 
					  0.26, 0.2, 0.09, 0.06, 0.03, 0.017};
  Double_t p8319_d1x1y1_ystatplus[NN] = {54.0, 34.0, 24.0, 18.0, 13.0, 10.0, 7.0, 6.0, 4.0, 
					 3.0, 2.6, 2.1, 1.7, 1.3, 1.1, 1.0, 0.54, 0.43, 0.33, 
					 0.26, 0.2, 0.09, 0.06, 0.03, 0.017};
  

  Double_t p8319_d1x1y1_ysystminus[NN]={113,95,87,61,49,39,23,19,13,10,7.1,5.5,3.9,2.7,1.9,1.5,1.0,0.69,0.40,0.24,0.16,0.07,0.03,0.01,0.040};
  Double_t p8319_d1x1y1_ysystplus[NN]={113,95,87,61,49,39,23,19,13,10,7.1,5.5,3.9,2.7,1.9,1.5,1.0,0.69,0.40,0.24,0.16,0.07,0.03,0.01,0.040};

  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.0};

  Double_t pbTonb =1.0/1000.0;
  Double_t DeltaY = 1.2;
  
for(int j=0;j<NN;j++){
  p8319_d1x1y1_yerrminus[j]=TMath::Sqrt((p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j])+(p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
  p8319_d1x1y1_yerrplus[j]=TMath::Sqrt((p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j])+(p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
  
  p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j]*pbTonb)/DeltaY;

 }
 
  
 TGraphAsymmErrors *Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										      p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
 Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->SetMarkerStyle(22);
 Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->SetMarkerColor(8);
 Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->SetMarkerSize(1.6);
 Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->GetYaxis()->SetTitleOffset(1.6);
 Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
 
 TAxis *Xaxis1 = Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->GetXaxis();
 Xaxis1->SetLimits(0.0,30.0);
 
 
 Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
 Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
 
 
  /*
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
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptPsi2S_0012_Pt,"CMS prompt #psi(2S), high p_{T}", "P");
  */
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt;
  return OutGraph;
  
}


TGraphAsymmErrors *Data_LHCb_D2NDPtDy_PromptPsi2S_Y2045_Pt()
{
  //This data is from 1204.1258
  const int NN = 12;

  Double_t p8319_d1x1y1_xval[NN] = {0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,11,14};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,1.0,2.0};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,0.25,1.0,2.0};
  
  
  Double_t p8319_d1x1y1_yval[NN] = {188.0,387.0,317,224,135,77,46,25,14,8.3,4.3,1.5};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.0};

  Double_t p8319_d1x1y1_statyerrminus[NN] = {6,8,7,6,4,2,1,1,1,0.4,0.3,0.1};
  Double_t p8319_d1x1y1_statyerrplus[NN] = {6,8,7,6,4,2,1,1,1,0.4,0.3,0.1};

  Double_t p8319_d1x1y1_systyerrminus[NN] = {18,37,26,24,13,7,4,2,1,0.7,0.4,0.2};
  Double_t p8319_d1x1y1_systyerrplus[NN] = {18,37,26,24,13,7,4,2,1,0.7,0.4,0.};
  
  

  Double_t BRPsi2SToMuMu = 0.0077;
  Double_t DeltaY = (4.5-2.0); 
  
  for(int j=0;j<NN;j++){
    
    p8319_d1x1y1_yerrminus[j] = TMath::Sqrt((p8319_d1x1y1_statyerrminus[j]*p8319_d1x1y1_statyerrminus[j]) 
					    + (p8319_d1x1y1_systyerrminus[j]*p8319_d1x1y1_systyerrminus[j]));


    p8319_d1x1y1_yerrplus[j] = TMath::Sqrt((p8319_d1x1y1_statyerrplus[j]*p8319_d1x1y1_statyerrplus[j]) 
					    + (p8319_d1x1y1_systyerrplus[j]*p8319_d1x1y1_systyerrplus[j]));
    p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j]*BRPsi2SToMuMu)/DeltaY;
    p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j]*BRPsi2SToMuMu)/DeltaY;
    p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j]*BRPsi2SToMuMu)/DeltaY;
    
  }

  TGraphAsymmErrors *Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt->SetMarkerStyle(21);
  Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt->SetMarkerColor(8);
  Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt->SetMarkerSize(1.6);
  Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt->GetYaxis()->SetRangeUser(0.001,1000.0);
  
  TAxis *Xaxis1 = Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,20.0);
   

  Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt->GetYaxis()->SetTitle("#frac{d#sigma}{dp_{T}}[nb/GeV]");
  
  /*
  Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt->Draw("zAP");
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
  lgd->AddEntry(Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt,"LHCb prompt #psi(2S), low p_{T}", "P");
  */
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_LHCb_D2NDPtDy_PromptPsi2S_2045_Pt;
  return OutGraph;
 
}









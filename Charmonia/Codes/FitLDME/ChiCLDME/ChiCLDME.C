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
#include <TFitResult.h>

//================== CDF: 1.8 TeV  Chic0 calculated root file ===========================================//
TFile *file_CDF_Chic0_RootS180TeV_CrossSection =  new TFile("rootFiles/CDF_Chic0_RootS180TeV_Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_CDF_Chic0_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_Chic0_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");



//================== CDF: 1.8 TeV  Chic1 calculated root file ===========================================//
TFile *file_CDF_Chic1_RootS180TeV_CrossSection =  new TFile("rootFiles/CDF_Chic1_RootS180TeV_Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_CDF_Chic1_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_Chic1_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");



//================== CDF: 1.8 TeV  Chic2 calculated root file ===========================================//
TFile *file_CDF_Chic2_RootS180TeV_CrossSection =  new TFile("rootFiles/CDF_Chic2_RootS180TeV_Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_CDF_Chic2_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_Chic2_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//==================  ATLAS 7 TeV  Chic0 calculated root file ===========================================//
TFile *file_ATLAS_Chic0_RootS7TeV_Y0075_CrossSection =  new TFile("rootFiles/ATLAS_RootS7TeV_Y0075_Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_Chic0_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_ATLAS_Chic0_RootS7TeV_Y0075_CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grATLAS_Chic0_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_Chic0_RootS7TeV_Y0075_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

//==================  ATLAS 7 TeV  Chic1 calculated root file ===========================================//
TFile *file_ATLAS_Chic1_RootS7TeV_Y0075_CrossSection =  new TFile("rootFiles/ATLAS_RootS7TeV_Y0075_Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_ATLAS_Chic1_RootS7TeV_Y0075_CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_Chic1_RootS7TeV_Y0075_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

//==================  ATLAS 7 TeV  Chic2 calculated root file ===========================================//
TFile *file_ATLAS_Chic2_RootS7TeV_Y0075_CrossSection =  new TFile("rootFiles/ATLAS_RootS7TeV_Y0075_Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_ATLAS_Chic2_RootS7TeV_Y0075_CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_Chic2_RootS7TeV_Y0075_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

//==================  CMS 7 TeV  Chic1 calculated root file ===========================================//
TFile *file_CMS_Chic1_RootS7TeV_Y1010_CrossSection =  new TFile("rootFiles/CMS_RootS7TeV_Y1010_Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_Chic1_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_CMS_Chic1_RootS7TeV_Y1010_CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grCMS_Chic1_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_Chic1_RootS7TeV_Y1010_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
//==================  CMS 7 TeV  Chic2 calculated root file ===========================================//
TFile *file_CMS_Chic2_RootS7TeV_Y1010_CrossSection =  new TFile("rootFiles/CMS_RootS7TeV_Y1010_Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_Chic2_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_CMS_Chic2_RootS7TeV_Y1010_CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grCMS_Chic2_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_Chic2_RootS7TeV_Y1010_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//==================  LHCb 7 TeV  Chic1 calculated root file ===========================================//
TFile *file_LHCb_Chic1_RootS7TeV_Y2045_CrossSection =  new TFile("rootFiles/LHCb_RootS7TeV_Y2045_Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_Chic1_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_LHCb_Chic1_RootS7TeV_Y2045_CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grLHCb_Chic1_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_Chic1_RootS7TeV_Y2045_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

//==================  LHCb 7 TeV  Chic2 calculated root file ===========================================//
TFile *file_LHCb_Chic2_RootS7TeV_Y2045_CrossSection =  new TFile("rootFiles/LHCb_RootS7TeV_Y2045_Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_Chic2_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_LHCb_Chic2_RootS7TeV_Y2045_CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grLHCb_Chic2_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_Chic2_RootS7TeV_Y2045_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");



Double_t ATLAS_RootS7TeV_Chic1_FitLDME(Double_t *x, Double_t *par);
Double_t ATLAS_RootS7TeV_Chic2_FitLDME(Double_t *x, Double_t *par);


Double_t LHCb_RootS7TeV_RatioChiC2ChiC1_FitLDME(Double_t *x, Double_t *par);
Double_t CMS_RootS7TeV_RatioChiC2ChiC1_FitLDME(Double_t *x, Double_t *par);




//======== Data Graphs =============================//
TGraphAsymmErrors *Data_CDF_180_D2NDPtDy_Chic1Chic2ToJPsi_Y0006_Pt();
TGraphAsymmErrors *Data_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt();
TGraphAsymmErrors *Data_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt();

TGraphAsymmErrors *Data_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_ChiPt();
TGraphAsymmErrors *Data_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_ChiPt();


TGraphAsymmErrors *Data_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt();
TGraphAsymmErrors *Data_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt();

Double_t CDF_180_Chic1Chic2_FitLDME(Double_t *x, Double_t *par);
Double_t CDF_180_Chic0_FitLDME(Double_t *x, Double_t *par);


TGraph *Scale_QCDSigma(TGraph *InGraph, Double_t LDME);
TGraph *Add_QCDSigma(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3,TGraph *InGraph4);
TGraphAsymmErrors *CutGraph(TGraph *InGraph, Double_t XMin);

Double_t Scale_Pt(Double_t JPsiPt, Int_t Par);
TGraph *Scale_QCDSigma_Pt(TGraph *InGraph, Double_t LDME, Int_t Par);


TGraphAsymmErrors *gr0;
TGraphAsymmErrors *gr1;
TGraphAsymmErrors *gr2;
TGraphAsymmErrors *gr3;
TGraphAsymmErrors *gr4;
TGraphAsymmErrors *gr4_t;

Double_t fcn0(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn1(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn2(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn3(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn4(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);

void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);

const Double_t mC = 1.6;
Double_t CalcChi2(TGraphAsymmErrors *InGrf, TF1 *InFunc);



TGraph *ThRatio_ChiC2ChiC1(TGraph *InGraph1, Double_t Fac1, TGraph *InGraph2, Double_t Fac2, TGraph *InGraph3, Double_t Fac3, TGraph *InGraph4, Double_t Fac4);
void ChiCLDME()
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
  


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit->Draw("AL");
  grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit->Draw("LPsame");
  grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P2_1_Fit->Draw("Psame");



  TGraph *Out_ThRatio_ChiC2ChiC1 = ThRatio_ChiC2ChiC1(grLHCb_Chic1_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3P1_1_Fit,1.0,grLHCb_Chic1_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3S1_8_Fit,3.0*0.00017,
						      grLHCb_Chic2_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3P2_1_Fit,1.0,grLHCb_Chic2_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3S1_8_Fit,5.0*0.00017);

  new TCanvas;
  gPad->SetTicks();
  //gPad->SetLogy(1);
  Out_ThRatio_ChiC2ChiC1->Draw("AL");


  //TGraph *ThRatio_ChiC2ChiC1(TGraph *InGraph1, Double_t Fac1, TGraph *InGraph2, Double_t Fac2, TGraph *InGraph3, Double_t Fac3, TGraph *InGraph4, Double_t Fac4)




  //return;


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING CDF RootS 1.8 TeV DATA FOR LDME ================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  cout<<" getting CDF RootS 1.8 TeV Data  Graph : "<<endl;
  
  TGraphAsymmErrors *grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt=new TGraphAsymmErrors();
  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt=Data_CDF_180_D2NDPtDy_Chic1Chic2ToJPsi_Y0006_Pt();
  
  TF1 *CDF_180_Chic0_FitFunctionLDME = new TF1("CDF_180_Chic0_FitFunctionLDME", CDF_180_Chic0_FitLDME, 5.0, 20, 2);
  

  CDF_180_Chic0_FitFunctionLDME->SetLineColor(2);
  CDF_180_Chic0_FitFunctionLDME->FixParameter(0,1.0);     
  //CDF_180_Chic0_FitFunctionLDME->FixParameter(2,1.0);     

  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->Fit("CDF_180_Chic0_FitFunctionLDME","Q0","MER", 7.0, 18.0);
  
  Double_t CDF_180_Chic0_Chi2 = CDF_180_Chic0_FitFunctionLDME->GetChisquare();
  Double_t CDF_180_Chic0_NDF =  CDF_180_Chic0_FitFunctionLDME->GetNDF();
  Double_t CDF_180_Chic0_Prob = CDF_180_Chic0_FitFunctionLDME->GetProb();
  Double_t CDF_180_Chic0_LDME_3P0_1 = CDF_180_Chic0_FitFunctionLDME->GetParameter(0);
  Double_t CDF_180_Chic0_LDME_3S1_8 = CDF_180_Chic0_FitFunctionLDME->GetParameter(1);
  
  cout<<"LDME : 3P0_1 "<<CDF_180_Chic0_LDME_3P0_1<<endl;
  cout<<"LDME : 3S1_8 "<<CDF_180_Chic0_LDME_3S1_8<<endl;
  cout<<"Chi2/NDF : "<<CDF_180_Chic0_Chi2<<"/"<<CDF_180_Chic0_NDF<<" Prob: "<<CDF_180_Chic0_Prob<<endl<<endl;
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->Draw("zAP");
  CDF_180_Chic0_FitFunctionLDME->Draw("same");

  TGraph *Out_grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3P0_1_Fit=Scale_QCDSigma(grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3P0_1_Fit,CDF_180_Chic0_LDME_3P0_1);
  Out_grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3P0_1_Fit->SetLineColor(6);

  TGraph *Out_grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,CDF_180_Chic0_LDME_3S1_8);
  Out_grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(8);
  
  TLegend *lgd_DSigmaDPtDY_CDF_180_Chic0 = new TLegend(0.64,0.78,0.87,0.92);
  lgd_DSigmaDPtDY_CDF_180_Chic0->SetBorderSize(0);
  lgd_DSigmaDPtDY_CDF_180_Chic0->SetFillStyle(0);
  lgd_DSigmaDPtDY_CDF_180_Chic0->SetFillColor(0);
  lgd_DSigmaDPtDY_CDF_180_Chic0->SetTextSize(0.04);
  
  lgd_DSigmaDPtDY_CDF_180_Chic0->AddEntry(Out_grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3P0_1_Fit,"^{3}P_{0}^{[1]}","L");  
  lgd_DSigmaDPtDY_CDF_180_Chic0->AddEntry(Out_grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
    
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->Draw("zAP");
  CDF_180_Chic0_FitFunctionLDME->Draw("same");
  Out_grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3P0_1_Fit->Draw("Lsame");
  Out_grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_CDF_180_Chic0->Draw("same");

    
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ============= FITTING CDF RootS 1.8 TeV DATA FOR LDME (Chic1 & Chic2)=========="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
   
  TF1 *CDF_180_Chic1Chic2_FitFunctionLDME = new TF1("CDF_180_Chic1Chic2_FitFunctionLDME", CDF_180_Chic1Chic2_FitLDME, 5.0, 20, 2);
  
  CDF_180_Chic1Chic2_FitFunctionLDME->SetLineColor(2);

  CDF_180_Chic1Chic2_FitFunctionLDME->FixParameter(0,1.0);     
  //CDF_180_Chic1Chic2_FitFunctionLDME->FixParameter(2,1.0);     

  //CDF_180_Chic1Chic2_FitFunctionLDME->FixParameter(0,1.1);     
  //CDF_180_Chic1Chic2_FitFunctionLDME->FixParameter(2,1.1);     
  //CDF_180_Chic1Chic2_FitFunctionLDME->SetParLimits(1,0.0,10.0);     
  TFitResultPtr r = grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->Fit("CDF_180_Chic1Chic2_FitFunctionLDME","0S","MER", 7.0, 18.0);
  
  //double p0err_low = r->LowerError(1); 
  //double p0err_up = r->UpperError(1);
  //cout<<p0err_low<<"   "<<p0err_up<<endl;


  Double_t CDF_180_Chic1Chic2_Chi2 = CDF_180_Chic1Chic2_FitFunctionLDME->GetChisquare();
  Double_t CDF_180_Chic1Chic2_NDF =  CDF_180_Chic1Chic2_FitFunctionLDME->GetNDF();
  Double_t CDF_180_Chic1Chic2_Prob = CDF_180_Chic1Chic2_FitFunctionLDME->GetProb();
  Double_t CDF_180_Chic1Chic2_LDME_3P1_1 = CDF_180_Chic1Chic2_FitFunctionLDME->GetParameter(0);
  
  Double_t CDF_180_Chic1Chic2_LDME_3S1_8 = CDF_180_Chic1Chic2_FitFunctionLDME->GetParameter(1);
  Double_t Err_CDF_180_Chic1Chic2_LDME_3S1_8 = CDF_180_Chic1Chic2_FitFunctionLDME->GetParError(1);
  
  //Double_t CDF_180_Chic1Chic2_LDME_3P2_1 = CDF_180_Chic1Chic2_FitFunctionLDME->GetParameter(2);

  cout<<"LDME : 3P1_1 "<<CDF_180_Chic1Chic2_LDME_3P1_1<<endl;
  cout<<"LDME : 3S1_8 "<<CDF_180_Chic1Chic2_LDME_3S1_8<<" pm: "<<Err_CDF_180_Chic1Chic2_LDME_3S1_8<<endl;
  //cout<<"LDME : 3P2_1 "<<CDF_180_Chic1Chic2_LDME_3P2_1<<endl;
  
  cout<<"Chi2/NDF : "<<CDF_180_Chic1Chic2_Chi2<<"/"<<CDF_180_Chic1Chic2_NDF<<" Prob: "<<CDF_180_Chic1Chic2_Prob<<endl<<endl;
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);

  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->Draw("zAP");
  CDF_180_Chic1Chic2_FitFunctionLDME->Draw("same");


  //Double_t TotalChi2 = CalcChi2(grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt,CDF_180_Chic1Chic2_FitFunctionLDME);
  //Double_t TotalNDF = (grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetN() - 2 );
  //cout<<" Total Chi2 "<<TotalChi2<<"/"<<TotalNDF<<"   "<<(TotalChi2/TotalNDF)<<endl;


  //return;
  

  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ============= FITTING ATLAS RootS 7 TeV DATA FOR LDME (Chic1)=========="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  //=====================================================================//
  //=================== Fitting ATLAS Data =============================//
  //===================================================================//

  TGraphAsymmErrors *grfData_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt=new TGraphAsymmErrors();
  //grfData_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt=Data_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt();
  grfData_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt=Data_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_ChiPt();
  grfData_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt->SetMarkerStyle(25);
  grfData_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt->SetMarkerColor(1);
  grfData_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt->SetMarkerSize(1.8);
  

  TF1 *ATLAS_RootS7TeV_Chic1_FitFunctionLDME = new TF1("ATLAS_RootS7TeV_Chic1_FitFunctionLDME", ATLAS_RootS7TeV_Chic1_FitLDME, 5.0, 30, 2);
  
  ATLAS_RootS7TeV_Chic1_FitFunctionLDME->SetLineColor(2);
  ATLAS_RootS7TeV_Chic1_FitFunctionLDME->FixParameter(0,1.0);     
    
  TFitResultPtr r1 = grfData_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt->Fit("ATLAS_RootS7TeV_Chic1_FitFunctionLDME","0S","MER", 10.0, 30.0);
  
  Double_t ATLAS_Chic1_RootS7TeV_Y0075_3P1_1 = ATLAS_RootS7TeV_Chic1_FitFunctionLDME->GetParameter(0);
  Double_t ATLAS_Chic1_RootS7TeV_Y0075_3S1_8 = ATLAS_RootS7TeV_Chic1_FitFunctionLDME->GetParameter(1);
  Double_t Err_ATLAS_Chic1_RootS7TeV_Y0075_3S1_8 = ATLAS_RootS7TeV_Chic1_FitFunctionLDME->GetParError(1);

  cout<<" ATLAS RootS 7 TeV Chic1 Data : "<<endl;
  cout<<"LDME : 3P1_1 "<< ATLAS_Chic1_RootS7TeV_Y0075_3P1_1 <<endl;
  cout<<"LDME : 3S1_8 "<< ATLAS_Chic1_RootS7TeV_Y0075_3S1_8 <<" pm: "<<Err_ATLAS_Chic1_RootS7TeV_Y0075_3S1_8<<endl;
 
 
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt->Draw("zAP");

  ATLAS_RootS7TeV_Chic1_FitFunctionLDME->SetLineWidth(4);
  ATLAS_RootS7TeV_Chic1_FitFunctionLDME->Draw("same");


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ============= FITTING ATLAS RootS 7 TeV DATA FOR LDME (Chic2)=========="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;


  TGraphAsymmErrors *grfData_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt=new TGraphAsymmErrors();
  //grfData_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt=Data_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt();
  grfData_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt=Data_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_ChiPt();
  grfData_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt->SetMarkerStyle(34);
  grfData_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt->SetMarkerColor(1);
  grfData_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt->SetMarkerSize(1.8);


  TF1 *ATLAS_RootS7TeV_Chic2_FitFunctionLDME = new TF1("ATLAS_RootS7TeV_Chic2_FitFunctionLDME", ATLAS_RootS7TeV_Chic2_FitLDME, 5.0, 30, 2);
  
  ATLAS_RootS7TeV_Chic2_FitFunctionLDME->SetLineColor(2);
  ATLAS_RootS7TeV_Chic2_FitFunctionLDME->FixParameter(0,1.0);     
    
  TFitResultPtr r2 = grfData_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt->Fit("ATLAS_RootS7TeV_Chic2_FitFunctionLDME","0S","MER", 10.0, 30.0);
  


  Double_t ATLAS_Chic2_RootS7TeV_Y0075_3P2_1 = ATLAS_RootS7TeV_Chic2_FitFunctionLDME->GetParameter(0);
  Double_t ATLAS_Chic2_RootS7TeV_Y0075_3S1_8 = ATLAS_RootS7TeV_Chic2_FitFunctionLDME->GetParameter(1);
  Double_t Err_ATLAS_Chic2_RootS7TeV_Y0075_3S1_8 = ATLAS_RootS7TeV_Chic2_FitFunctionLDME->GetParError(1);

  cout<<" ATLAS RootS 7 TeV Chic2 Data : "<<endl;
  cout<<"LDME : 3P2_1 "<< ATLAS_Chic2_RootS7TeV_Y0075_3P2_1 <<endl;
  cout<<"LDME : 3S1_8 "<< ATLAS_Chic2_RootS7TeV_Y0075_3S1_8 <<" pm: "<<Err_ATLAS_Chic2_RootS7TeV_Y0075_3S1_8<<endl;
 
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt->Draw("zAP");

  ATLAS_RootS7TeV_Chic2_FitFunctionLDME->SetLineWidth(4);
  ATLAS_RootS7TeV_Chic2_FitFunctionLDME->Draw("same");
 
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ============= FITTING CMS RootS 7 TeV DATA FOR LDME (ChiC2/ChiC1)=========="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;


  TGraphAsymmErrors *grfData_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt = new TGraphAsymmErrors();
  grfData_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt = Data_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt();

  //Double_t LHCb_RootS7TeV_RatioChiC2ChiC1_FitLDME(Double_t *x, Double_t *par)
  //Double_t CMS_RootS7TeV_RatioChiC2ChiC1_FitLDME(Double_t *x, Double_t *par)

  TF1 *CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME = new TF1("CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME", CMS_RootS7TeV_RatioChiC2ChiC1_FitLDME, 6.0, 30, 2);
  
  CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->SetLineColor(2);
  CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->FixParameter(0,1.0);     
  //CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->SetParameter(1,0.00123377);     
    

  TFitResultPtr r3 = grfData_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt->Fit("CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME","0S","MER", 8.0, 25.0);
  
  Double_t CMS_RatioChiC2ChiC1_RootS7TeV_Y0075_3P1_1 = CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->GetParameter(0);
  Double_t CMS_RatioChiC2ChiC1_RootS7TeV_Y0075_3S1_8 = CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->GetParameter(1);
  Double_t Err_CMS_RatioChiC2ChiC1_RootS7TeV_Y0075_3S1_8 = CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->GetParError(1);

  cout<<" CMS RootS 7 TeV RatioChiC2ChiC1 Data : "<<endl;
  cout<<"LDME : 3P1_1 "<< CMS_RatioChiC2ChiC1_RootS7TeV_Y0075_3P1_1 <<endl;
  cout<<"LDME : 3S1_8 "<< CMS_RatioChiC2ChiC1_RootS7TeV_Y0075_3S1_8 <<" pm: "<<Err_CMS_RatioChiC2ChiC1_RootS7TeV_Y0075_3S1_8<<endl;


  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLeftMargin(0.22);
  TAxis *Xaxis1 = grfData_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt->GetXaxis();
  Xaxis1->SetLimits(0.0,30.0);
  grfData_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt->GetYaxis()->SetRangeUser(0.0,1.0);
  grfData_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt->Draw("AP");
  CMS_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->Draw("same");
  







  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ============= FITTING LHCb RootS 7 TeV DATA FOR LDME (ChiC2/ChiC1)=========="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  TGraphAsymmErrors *grfData_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt = new TGraphAsymmErrors();
  grfData_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt = Data_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt();

  TF1 *LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME = new TF1("LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME", LHCb_RootS7TeV_RatioChiC2ChiC1_FitLDME, 4.0, 30, 2);
  
  LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->SetLineColor(2);
  LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->FixParameter(0,1.0);     
  // LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->SetParameter(1,0.00123377);     
  
  TFitResultPtr r4 = grfData_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt->Fit("LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME","0S","MER", 4.0, 30.0);
  
  Double_t LHCb_RatioChiC2ChiC1_RootS7TeV_Y0075_3P1_1 = LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->GetParameter(0);
  Double_t LHCb_RatioChiC2ChiC1_RootS7TeV_Y0075_3S1_8 = LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->GetParameter(1);
  Double_t Err_LHCb_RatioChiC2ChiC1_RootS7TeV_Y0075_3S1_8 = LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->GetParError(1);

  cout<<" LHCb RootS 7 TeV RatioChiC2ChiC1 Data : "<<endl;
  cout<<"LDME : 3P1_1 "<< LHCb_RatioChiC2ChiC1_RootS7TeV_Y0075_3P1_1 <<endl;
  cout<<"LDME : 3S1_8 "<< LHCb_RatioChiC2ChiC1_RootS7TeV_Y0075_3S1_8 <<" pm: "<<Err_LHCb_RatioChiC2ChiC1_RootS7TeV_Y0075_3S1_8<<endl;

  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLeftMargin(0.22);
  TAxis *Xaxis2 = grfData_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt->GetXaxis();
  Xaxis2->SetLimits(0.0,25.0);
  grfData_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt->GetYaxis()->SetRangeUser(0.0,1.5);
  grfData_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt->Draw("AP");
  LHCb_RootS7TeV_RatioChiC2ChiC1_FitFunctionLDME->Draw("same");






  //return;






  cout<<" ========================================================================== "<<endl;
  cout<<" =============        COMBINED FITTING   ================================== "<<endl;
  cout<<" ========================================================================== "<<endl;



  //==================================== Fit with TMiniut ========================//
  gr0=new TGraphAsymmErrors();
  gr0=Data_CDF_180_D2NDPtDy_Chic1Chic2ToJPsi_Y0006_Pt();

  gr1=new TGraphAsymmErrors();
  gr1=Data_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_ChiPt();

  gr2=new TGraphAsymmErrors();
  gr2=Data_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_ChiPt();

  gr3=new TGraphAsymmErrors();
  gr3=Data_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt();

  gr4=new TGraphAsymmErrors();
  gr4=CutGraph(Data_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt(),5.0);

  gr4_t =  Data_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt();
 
  //---------------------------------------------------------------------
  //     Blocks for fitting procedure
  //---------------------------------------------------------------------
  const Int_t npars = 2;
  TMinuit *gMinuit = new TMinuit(npars);  //initialize TMinuit with a maximum of 3 params
  gMinuit->SetFCN(fcn);
  
  Double_t arglist[10];
  Int_t ierflg = 0;
  arglist[0] = 1;
  gMinuit->mnexcm("SET ERR", arglist, 1, ierflg);
  
  // Set starting values and step sizes for parameters
  //static Double_t vstart[] = {1.0,0.0010,0.0010};
  //static Double_t step[]   = {0.1,0.0001,0.0001};

  static Double_t vstart[] = {1.0,0.0010};
  static Double_t step[]   = {0.1,0.0001};

  gMinuit->mnparm(0, "3P1_1", vstart[0], step[0], 0, 0, ierflg);
  gMinuit->mnparm(1, "3S1_8", vstart[1], step[1], 0, 0, ierflg);
  //gMinuit->mnparm(2, "3S1_8_Chi2", vstart[2], step[2], 0, 0, ierflg);

  //  gMinuit->mnparm(2, "3P2_1", vstart[2], step[2], 0, 0, ierflg);
  
  gMinuit->FixParameter(0);
  //gMinuit->FixParameter(2);
 
  //This is where the delta chi2 is defined
  //This is critical to getting the correct error estimates
  arglist[0] = 1.0;
  if (arglist[0]) gMinuit->mnexcm("SET ERR", arglist, 1, ierflg);
  
  // Now ready for minimization step
  arglist[0] = 500; //max 500
  arglist[1] = 0.01; // tolerance = 0.1
  gMinuit->mnexcm("MIGRAD", arglist, 2, ierflg);
  
  // Print results
  Double_t amin,edm,errdef;
  Int_t nvpar,nparx,icstat;
  gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);

  Int_t iuext;
  TString chnam;   // The name of the parameter
  Double_t val;    // The current (external) value of the parameter 
  Double_t errl[npars] = {0};   // The current estimate of the parameter uncertainty  
  Double_t xlolim; // The lower bound (or zero if no limits)
  Double_t xuplim; // The upper bound (or zero if no limits)
  Int_t iuint;     // The internal parameter number 
 
  Int_t i = 0;
  Double_t currentPar[npars] = {0};
  for (i=0; i< npars;i++) {
    gMinuit->mnpout(i, chnam, currentPar[i], errl[i], xlolim, xuplim, iuint);
  }
  
  Double_t Combined_3P1_1 = currentPar[0];
  Double_t Combined_3S1_8 = currentPar[1];
  //Double_t Combined_3S1_8_Chi2 = currentPar[2];
  Double_t Combined_3P2_1 = currentPar[0];
  Double_t Err_Combined_3S1_8 = errl[1];
  //Double_t Err_Combined_3S1_8_Chi2 = errl[2];

  
  cout<<endl<<endl;
  cout<<" TMiniut fitting perameters "<<endl;
  cout<<"LDME : 3P1_1 "<< Combined_3P1_1 <<" pm  "<<errl[0]<<endl;
  cout<<"LDME : 3S1_8 "<< Combined_3S1_8 <<" pm  "<< Err_Combined_3S1_8 <<endl;
  //cout<<"LDME : 3S1_8_Chi2 "<< Combined_3S1_8_Chi2  <<" pm  "<< Err_Combined_3S1_8_Chi2 <<endl;
  cout<<"LDME : 3P2_1 "<< Combined_3P2_1 <<" pm  "<<errl[0]<<endl;

  
  TF1 *fun_0=new TF1("fun_0",CDF_180_Chic1Chic2_FitLDME, 5.0, 30, 2); 	
  fun_0->FixParameter(0,currentPar[0]);
  fun_0->FixParameter(1,currentPar[1]);
  //fun_0->FixParameter(2,currentPar[2]);
  fun_0->SetLineColor(kBlack);
  fun_0->SetLineStyle(1);
  fun_0->SetLineWidth(2);

  gr0->Fit("fun_0","Q0","MER", 5, 20);

  
  TGraph *Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit=Scale_QCDSigma(grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit, Combined_3P1_1);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->SetLineColor(6);

  TGraph *Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,Combined_3S1_8);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(8);
  
  TLegend *lgd_DSigmaDPtDY_CDF_180_Chic1Chic2 = new TLegend(0.214,0.883,0.916,0.932);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->SetBorderSize(0);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->SetFillStyle(0);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->SetFillColor(0);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->SetTextSize(0.040);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->SetHeader("p#bar{p} #surds = 1.8 TeV, J/#psi from #chi_{c}, |y^{J/#psi}| #leq 0.6"); 
  
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->SetLineStyle(9);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->SetLineColor(4);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);

  TLegend *lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1 = new TLegend(0.622,0.58,0.897,0.858);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1->SetBorderSize(0);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1->SetFillStyle(0);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1->SetFillColor(0);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1->SetTextSize(0.040);
  

  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1->AddEntry(gr0,"CDF Data","P"); 
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1->AddEntry(fun_0,"Total","L"); 
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1->AddEntry(Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit,"^{3}P_{1}^{[1]}","L");  
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1->AddEntry(Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  
  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);

  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit=CutGraph(Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit,5.0);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr0->Draw("zAP");
  fun_0->SetLineWidth(4);
  fun_0->Draw("same");
 
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->Draw("Lsame");
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->Draw("same");
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(c)");
  gPad->SaveAs("Chic1_CDF_Fit.png");
  gPad->SaveAs("Chic1_CDF_Fit.pdf");



  TF1 *fun_1=new TF1("fun_1", ATLAS_RootS7TeV_Chic1_FitLDME, 5.0, 30, 2); 	
  fun_1->FixParameter(0,currentPar[0]);
  fun_1->FixParameter(1,currentPar[1]);
  fun_1->SetLineColor(kBlack);
  fun_1->SetLineStyle(1);
  fun_1->SetLineWidth(2);

  gr1->Fit("fun_1","Q0","MER", 5, 20);



  TGraph *Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit=Scale_QCDSigma(grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit,Combined_3P1_1);
  TGraph *Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit,Combined_3S1_8);
  


  Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit->SetLineStyle(9);
  Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit->SetLineColor(4);
  Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);


  Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit=CutGraph(Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit,5.0);
  Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);



  TLegend *lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1 = new TLegend(0.214,0.883,0.916,0.932);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1->SetBorderSize(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1->SetFillStyle(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1->SetFillColor(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1->SetTextSize(0.040);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1->SetHeader("pp #surds = 7 TeV, #chi_{c1}(1P), |y^{J/#psi}| #leq 0.75"); 
  
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->SetLineStyle(9);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->SetLineColor(4);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);

  TLegend *lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1 = new TLegend(0.622,0.58,0.897,0.858);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1->SetBorderSize(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1->SetFillStyle(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1->SetFillColor(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1->SetTextSize(0.040);
  

  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1->AddEntry(gr1,"ATLAS Data","P"); 
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1->AddEntry(fun_1,"Total","L"); 
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1->AddEntry(Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit,"^{3}P_{1}^{[1]}","L");  
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1->AddEntry(Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr1->Draw("zAP"); 
  fun_1->SetLineWidth(4);
  fun_1->Draw("same");
  Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit->Draw("Lsame");
  Out_grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1->Draw("same");
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic1_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(a)");
  gPad->SaveAs("Chic1_ATLAS_Fit.png");
  gPad->SaveAs("Chic1_ATLAS_Fit.pdf");




  TF1 *fun_2=new TF1("fun_2", ATLAS_RootS7TeV_Chic2_FitLDME, 5.0, 30, 2); 	
  fun_2->FixParameter(0,currentPar[0]);
  fun_2->FixParameter(1,currentPar[1]);
  fun_2->SetLineColor(kBlack);
  fun_2->SetLineStyle(1);
  fun_2->SetLineWidth(4);
  gr2->Fit("fun_2","Q0","MER", 5, 20);
  

  TGraph *Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit=Scale_QCDSigma(grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit,Combined_3P2_1);
  TGraph *Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit,Combined_3S1_8);

  Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit->SetLineStyle(9);
  Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit->SetLineColor(4);
  Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);


  Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit=CutGraph(Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit,5.0);
  Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);


  TLegend *lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2 = new TLegend(0.214,0.883,0.916,0.932);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2->SetBorderSize(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2->SetFillStyle(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2->SetFillColor(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2->SetTextSize(0.040);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2->SetHeader("pp #surds = 7 TeV, #chi_{c2}(1P), |y^{J/#psi}| #leq 0.75"); 
  
 
  TLegend *lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1 = new TLegend(0.622,0.58,0.897,0.858);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1->SetBorderSize(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1->SetFillStyle(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1->SetFillColor(0);
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1->SetTextSize(0.040);
  

  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1->AddEntry(gr2,"ATLAS Data","P"); 
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1->AddEntry(fun_2,"Total","L"); 
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1->AddEntry(Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit,"^{3}P_{2}^{[1]}","L");  
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1->AddEntry(Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr2->Draw("AP");
  fun_2->Draw("same");
  Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit->Draw("Lsame");
  Out_grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2->Draw("same");
  lgd_DSigmaDPtDY_ATLAS_7TeV_Chic2_1->Draw("same");

  tb->DrawLatex(0.23,0.18,"(b)");
  gPad->SaveAs("Chic2_ATLAS_Fit.png");
  gPad->SaveAs("Chic2_ATLAS_Fit.pdf");

  //TF1 *fun_t=new TF1("fun_t");
  //fun_t=



  TF1 *fun_3=new TF1("fun_3", CMS_RootS7TeV_RatioChiC2ChiC1_FitLDME, 5.0, 30, 2); 	
  fun_3->FixParameter(0,currentPar[0]);
  fun_3->FixParameter(1,currentPar[1]);
  //fun_3->FixParameter(2,currentPar[2]);
  fun_3->SetLineColor(kBlack);
  fun_3->SetLineStyle(1);
  fun_3->SetLineWidth(4);

  gr3->Fit("fun_3","Q0","MER", 6, 20);

  TLegend *lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1 = new TLegend(0.233,0.889,0.913,0.937);
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1->SetBorderSize(0);
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1->SetFillStyle(0);
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1->SetFillColor(0);
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1->SetTextSize(0.038);
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1->SetHeader("pp #surds = 7 TeV, #chi_{c2}(1P)/#chi_{c1}(1P), |y^{J/#psi}| #leq 1.0"); 
  
 
  TLegend *lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1_1 = new TLegend(0.60,0.73,0.88,0.85);
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1_1->SetBorderSize(0);
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1_1->SetFillStyle(0);
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1_1->SetFillColor(0);
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1_1->SetTextSize(0.040);
  

  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1_1->AddEntry(gr3,"CMS Data","P"); 
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1_1->AddEntry(fun_2,"Total","L"); 
  

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLeftMargin(0.22);
  TAxis *Xaxis_gr3 = gr3->GetXaxis();
  Xaxis_gr3->SetLimits(0.0,30.0);
  gr3->GetYaxis()->SetRangeUser(0.0,1.0);
  gr3->Draw("AP");
  fun_3->Draw("same");
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1->Draw("same");
  lgd_DSigmaDPtDY_CMS_7TeV_RatioChiC2Chic1_1->Draw("same");
  tb->DrawLatex(0.27,0.18,"(a)");
  gPad->SaveAs("Chic2Chic1_CMS_Fit.png");
  gPad->SaveAs("Chic2Chic1_CMS_Fit.pdf");




  TF1 *fun_4=new TF1("fun_4", LHCb_RootS7TeV_RatioChiC2ChiC1_FitLDME, 4.0, 30, 2); 	
  fun_4->FixParameter(0,currentPar[0]);
  fun_4->FixParameter(1,currentPar[1]);
  //fun_4->FixParameter(2,currentPar[2]);
  fun_4->SetLineColor(kBlack);
  fun_4->SetLineStyle(1);
  fun_4->SetLineWidth(4);
  gr4->Fit("fun_4","Q0","MER", 6, 20);



  TLegend *lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1 = new TLegend(0.233,0.889,0.913,0.937);
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1->SetBorderSize(0);
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1->SetFillStyle(0);
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1->SetFillColor(0);
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1->SetTextSize(0.036);
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1->SetHeader("pp #surds = 7 TeV, #chi_{c2}(1P)/#chi_{c1}(1P),2.5#leq y^{J/#psi} #leq4.0"); 
  
 
  TLegend *lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1_1 = new TLegend(0.60,0.73,0.88,0.85);
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1_1->SetBorderSize(0);
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1_1->SetFillStyle(0);
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1_1->SetFillColor(0);
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1_1->SetTextSize(0.040);
  

  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1_1->AddEntry(gr4,"LHCb Data","P"); 
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1_1->AddEntry(fun_2,"Total","L"); 

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLeftMargin(0.22);
  TAxis *Xaxis_gr4 = gr4->GetXaxis();
  Xaxis_gr4->SetLimits(0.0,30.0);
  gr4->GetYaxis()->SetRangeUser(0.0,1.6);
  gr4->Draw("AP");
  gr4_t->Draw("AP");
  fun_4->Draw("Csame");


  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1->Draw("same");
  lgd_DSigmaDPtDY_LHCb_7TeV_RatioChiC2Chic1_1->Draw("same");
  tb->DrawLatex(0.27,0.18,"(b)");
  gPad->SaveAs("Chic2Chic1_LHCb_Fit.png");
  gPad->SaveAs("Chic2Chic1_LHCb_Fit.pdf");


  cout<<"Chi Square  "<<CalcChi2(gr0,fun_0)<<"   "<<CalcChi2(gr1,fun_1)<<"   "<<CalcChi2(gr2,fun_2)<<"   "<<CalcChi2(gr3,fun_3)<<endl;
  cout<<"Chi Square  "<<CalcChi2(gr4,fun_4)<<endl;
  
  Double_t TotalChi2 = CalcChi2(gr0,fun_0) + CalcChi2(gr1,fun_1) + CalcChi2(gr2,fun_2) + CalcChi2(gr3,fun_3)+CalcChi2(gr4,fun_4);

  
  Double_t TotalNDF = (gr0->GetN() + gr1->GetN() + gr2->GetN() + gr3->GetN() + gr4->GetN()) - 2 ;

  cout<<" Total Chi2 "<<TotalChi2<<"/"<<TotalNDF<<"   "<<(TotalChi2/TotalNDF)<<endl;
  
  


  return;


}


Double_t CDF_180_Chic0_FitLDME(Double_t *x, Double_t *par)
{
  
  Double_t LDME_3P0_1 = par[0];
  Double_t LDME_3S1_8 = par[1];
  
  Double_t Sigma = LDME_3P0_1*grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3P0_1_Fit->Eval(x[0]) + LDME_3S1_8*grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]);
  
  return Sigma;
}


Double_t CDF_180_Chic1Chic2_FitLDME(Double_t *x, Double_t *par)
{
  Double_t LDME_3P1_1 = par[0];
  Double_t LDME_3S1_8 = par[1];
  //Double_t LDME_3S1_8_Chi2 = par[2];

  //Double_t Scale_Pt(Double_t ChiPt, Int_t Par)
  Double_t Pt = x[0];
  Double_t Pt1 =0.0;
  Double_t Pt2 =0.0;

  Pt1 = Scale_Pt(Pt,1);
  Pt2 = Scale_Pt(Pt,2);
  
  Double_t Sigma = LDME_3P1_1*grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Pt1) + LDME_3S1_8*grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt1) 
    + LDME_3P1_1*grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Pt2) + LDME_3S1_8*grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt2);

  //Double_t Sigma = LDME_3P1_1*grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Pt1) + LDME_3S1_8_Chi1*grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt1)+ 
  //LDME_3P1_1*grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Pt2) + LDME_3S1_8_Chi2*grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt2);


 

 return Sigma;
}


Double_t ATLAS_RootS7TeV_Chic1_FitLDME(Double_t *x, Double_t *par)
{
  Double_t LDME_3P1_1 = par[0];
  Double_t LDME_3S1_8 = par[1];
  //Double_t LDME_3S1_8_Chi2 = par[2];
  
  //Double_t Pt = x[0];
  //Double_t Pt1 =Scale_Pt(Pt,1);
  Double_t Pt1 = x[0];
  Double_t Sigma = LDME_3P1_1*grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Pt1) + LDME_3S1_8*grATLAS_Chic1_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt1);
  
  return Sigma;
}


Double_t ATLAS_RootS7TeV_Chic2_FitLDME(Double_t *x, Double_t *par)
{
  Double_t LDME_3P2_1 = par[0];
  Double_t LDME_3S1_8 = par[1];
  //Double_t LDME_3S1_8_Chi2 = par[2];
  
  //Double_t Pt = x[0];
  //Double_t Pt1 =Scale_Pt(Pt,2);
  Double_t Pt1 = x[0];
  Double_t Sigma = LDME_3P2_1*grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Pt1) + LDME_3S1_8*grATLAS_Chic2_RootS7TeV_Y0075_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt1);
  
  return Sigma;
}



Double_t CMS_RootS7TeV_RatioChiC2ChiC1_FitLDME(Double_t *x, Double_t *par)
{
  Double_t LDME_3P1_1 = par[0];
  Double_t LDME_3S1_8 = par[1];
  //Double_t LDME_3S1_8_Chi2 = par[2];
  Double_t LDME_3P2_1 = LDME_3P1_1; 

  //Double_t Scale_Pt(Double_t ChiPt, Int_t Par)
  Double_t Pt = x[0];
  Double_t Pt1 =0.0;
  Double_t Pt2 =0.0;

  Pt1 = Scale_Pt(Pt,1);
  Pt2 = Scale_Pt(Pt,2);
  
  //Pt1 = x[0];
  //Pt2 = x[0];
  Double_t Sigma_ChiC1 = LDME_3P1_1*grCMS_Chic1_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Pt1) + LDME_3S1_8*grCMS_Chic1_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt1);
  Double_t Sigma_ChiC2 = LDME_3P2_1*grCMS_Chic2_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Pt2) + LDME_3S1_8*grCMS_Chic2_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt2);
  
  //Double_t Sigma_ChiC1 = LDME_3P1_1*grCMS_Chic1_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Pt1) + LDME_3S1_8_Chi1*grCMS_Chic1_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt1);
  //Double_t Sigma_ChiC2 = LDME_3P2_1*grCMS_Chic2_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Pt2) + LDME_3S1_8_Chi2*grCMS_Chic2_RootS7TeV_Y1010_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt2);
  
  Double_t Sigma =  Sigma_ChiC2/Sigma_ChiC1;

 return Sigma;
}


Double_t LHCb_RootS7TeV_RatioChiC2ChiC1_FitLDME(Double_t *x, Double_t *par)
{
  Double_t LDME_3P1_1 = par[0];
  Double_t LDME_3S1_8 = par[1];
  //Double_t LDME_3S1_8_Chi2 = par[2];
  Double_t LDME_3P2_1 = LDME_3P1_1; 

  //Double_t Scale_Pt(Double_t ChiPt, Int_t Par)
  Double_t Pt = x[0];
  Double_t Pt1 =0.0;
  Double_t Pt2 =0.0;

  Pt1 = Scale_Pt(Pt,1);
  Pt2 = Scale_Pt(Pt,2);

  Double_t Sigma_ChiC1 = LDME_3P1_1*grLHCb_Chic1_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Pt1) + LDME_3S1_8*grLHCb_Chic1_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt1);
  Double_t Sigma_ChiC2 = LDME_3P2_1*grLHCb_Chic2_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Pt2) + LDME_3S1_8*grLHCb_Chic2_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt2);

  //Double_t Sigma_ChiC1 = LDME_3P1_1*grLHCb_Chic1_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Pt1) + LDME_3S1_8_Chi1*grLHCb_Chic1_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt1);
  //Double_t Sigma_ChiC2 = LDME_3P2_1*grLHCb_Chic2_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Pt2) + LDME_3S1_8_Chi2*grLHCb_Chic2_RootS7TeV_Y2045_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt2);
  
  Double_t Sigma =  Sigma_ChiC2/Sigma_ChiC1;

 return Sigma;
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



TGraph *Scale_QCDSigma_Pt(TGraph *InGraph, Double_t LDME, Int_t Par)
{
  
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph->GetN();++j){
    Double_t xx,yy,zz,xx1;

    InGraph->GetPoint(j,xx,yy);
    xx1=Scale_Pt(xx,Par);
    zz=LDME*yy;
    SGraph ->SetPoint(j,xx1,zz);  
    
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









Double_t Scale_Pt(Double_t JPsiPt, Int_t Par)
{

  Double_t ChiPt;
  Double_t MM = 0.0;
  Double_t CC = 0.0;


  if(Par ==0){MM=1.075; CC = 0.113;}
  if(Par ==1){MM=1.067; CC = 0.181;}
  if(Par ==2){MM=1.113; CC = 0.137;}

  ChiPt  = MM * JPsiPt + CC;

  
  return ChiPt;

}



 /*
Double_t Scale_Pt(Double_t JPsiPt, Int_t Par)
{
  Double_t MassJPsi=3.097;
  Double_t MassChic0=3.415;
  Double_t MassChic1=3.510;
  Double_t MassChic2=3.556;
  
  Double_t ChiPt;
  Double_t MM = 0.0;
  
  if(Par ==0){MM=MassChic0/MassJPsi;}
  if(Par ==1){MM=MassChic1/MassJPsi;}
  if(Par ==2){MM=MassChic2/MassJPsi;}
  
  ChiPt  = MM * JPsiPt;
 
  return ChiPt;


}
 */




Double_t fcn0(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag)
{
  const Int_t nbins = gr0->GetN();
  Int_t i;
  Double_t xx0[nbins];
  Double_t yy0[nbins];
  Double_t erryy0[nbins];
    
  for (Int_t j=0;j<nbins; j++) 
    {
      gr0->GetPoint(j,xx0[j],yy0[j]);
      erryy0[j]= gr0->GetErrorY(j);
    }

  //calculate chisquare
  Double_t chisq = 0;
  for (i=0;i<  nbins; i++) {
    Double_t delta  = (yy0[i]-CDF_180_Chic1Chic2_FitLDME(&xx0[i],par))/erryy0[i];
    chisq += delta*delta;
  }
  return chisq;
}


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
    Double_t delta  = (yy1[i]-ATLAS_RootS7TeV_Chic1_FitLDME(&xx1[i],par))/erryy1[i];
    chisq += delta*delta;
  }
  return chisq;
}



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
    Double_t delta  = (yy2[i]-ATLAS_RootS7TeV_Chic2_FitLDME(&xx2[i],par))/erryy2[i];
    chisq += delta*delta;
  }
  return chisq;
}



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
  for (i=0;i<  nbins; i++) {
    Double_t delta  = (yy3[i]-CMS_RootS7TeV_RatioChiC2ChiC1_FitLDME(&xx3[i],par))/erryy3[i];
    chisq += delta*delta;
  }
  return chisq;
}


Double_t fcn4(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag)
{
  const Int_t nbins = gr4->GetN();
  Int_t i;
  Double_t xx4[nbins];
  Double_t yy4[nbins];
  Double_t erryy4[nbins];
    
  for (Int_t j=0;j<nbins; j++) 
    {
      gr4->GetPoint(j,xx4[j],yy4[j]);
      erryy4[j]= gr4->GetErrorY(j);
    }

  //calculate chisquare
  Double_t chisq = 0;
  for (i=0;i<  nbins; i++) {
    Double_t delta  = (yy4[i]-LHCb_RootS7TeV_RatioChiC2ChiC1_FitLDME(&xx4[i],par))/erryy4[i];
    chisq += delta*delta;
  }
  return chisq;
}






void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
  
  f = fcn0(npar,gin,par, iflag) + fcn1(npar,gin,par, iflag) + fcn2(npar,gin,par, iflag) + fcn3(npar,gin,par, iflag) + fcn4(npar,gin,par, iflag);

  //f = fcn1(npar,gin,par, iflag) + fcn2(npar,gin,par, iflag) + fcn3(npar,gin,par, iflag) + fcn4(npar,gin,par, iflag);

  //f = fcn1(npar,gin,par, iflag) + fcn2(npar,gin,par, iflag);

  //f = fcn0(npar,gin,par, iflag) + fcn1(npar,gin,par, iflag) + fcn2(npar,gin,par, iflag);

  //f = fcn1(npar,gin,par, iflag) + fcn3(npar,gin,par, iflag) ;
  
}

























TGraphAsymmErrors *CutGraph(TGraph *InGraph, Double_t XMin)
{
  
  TGraphAsymmErrors *SGraph = new TGraphAsymmErrors; 
  const int NN = InGraph->GetN();
  
 Int_t i=-1;    
  for (int j=0; j < NN;++j){
    Double_t xx,yy;
    Double_t errlowxx,errlowyy;
    Double_t errhighxx,errhighyy;
    
    InGraph->GetPoint(j,xx,yy);
    errlowxx=InGraph->GetErrorXlow(j);
    errhighxx=InGraph->GetErrorXhigh(j);
    errlowyy=InGraph->GetErrorYlow(j);
    errhighyy=InGraph->GetErrorYhigh(j);
    
   
    if(xx>=XMin)
      {
	i=i+1;
	SGraph->SetPoint(i,xx,yy);  
	SGraph->SetPointError(i,errlowxx,errhighxx,errlowyy,errhighyy);  
      }
  }
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = SGraph;

  OutGraph->SetLineColor(InGraph->GetLineColor());
  OutGraph->SetLineStyle(InGraph->GetLineStyle());
  OutGraph->SetLineWidth(InGraph->GetLineWidth());
  
  OutGraph->SetMarkerColor(InGraph->GetMarkerColor());
  OutGraph->SetMarkerStyle(InGraph->GetMarkerStyle());
  OutGraph->SetMarkerSize(InGraph->GetMarkerSize());



  return OutGraph;
}




Double_t CalcChi2(TGraphAsymmErrors *InGrf, TF1 *InFunc)
{
  
  const Int_t nbins = InGrf->GetN();
  Int_t i;
  Double_t xx[nbins];
  Double_t yy[nbins];
  Double_t erryy[nbins];

 for (Int_t j=0;j<nbins; j++) 
    {
      InGrf->GetPoint(j,xx[j],yy[j]);
      erryy[j]= InGrf->GetErrorY(j);
      //cout<<InGrf->GetErrorY(j)<<"   "<<InGrf->GetErrorYlow(j)<<"   "<<InGrf->GetErrorYhigh(j)<<"  "<<InGrf->GetErrorYlow(j)+InGrf->GetErrorYhigh(j)<<
      //endl;
    }

  //calculate chisquare
  Double_t chisq = 0;
  for (i=0;i<nbins; i++) {
    //cout<<xx[i]<<"   "<<yy[i]<<"  "<<InFunc->Eval(xx[i])<<"   "<< (yy[i] -InFunc->Eval(xx[i]))/erryy[i]<< endl;
    Double_t delta  = (yy[i]-InFunc->Eval(xx[i]))/erryy[i];
    //cout<<delta<<endl;
    chisq += delta*delta;
  }
  

  return chisq;

}





///==================================================== Added new Data Graphs ==============================//
TGraphAsymmErrors *Data_CDF_180_D2NDPtDy_Chic1Chic2ToJPsi_Y0006_Pt()
{
  //Data Link
  //http://hepdata.cedar.ac.uk/view/ins440446
  
  const int NN = 11;
  
  Double_t p8319_d1x1y1_xval[NN] = {5.24, 5.74, 6.24, 6.74, 7.47, 8.47, 9.47, 10.91, 12.92,15.35, 18.38};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  
  Double_t p8319_d1x1y1_yval[NN] = {2.3, 1.66, 1.15, 0.781, 0.476, 0.239, 0.133, 0.0558, 0.0171,0.0059, 0.00154}; 
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.63, 0.44, 0.3, 0.2, 0.12, 0.06, 0.033, 0.014, 0.0047,0.0018, 5.7E-4};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.62, 0.43, 0.29, 0.19, 0.12, 0.058, 0.032, 0.014, 0.0046,0.0018, 5.6E-4};
  
  Double_t DeltaY = 1.2;
  
  for(int j=0;j<NN;j++){
    p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j])/DeltaY;
    p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j])/DeltaY;
    p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j])/DeltaY;
  }
   
  TGraphAsymmErrors *Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										       p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->SetMarkerStyle(24);
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->SetMarkerColor(1);
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->SetMarkerSize(1.8);
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetYaxis()->SetRangeUser(0.0001,10.0);
  
  TAxis *Xaxis1 = Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetXaxis();
  Xaxis1->SetLimits(4.0,22.0);

  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetYaxis()->CenterTitle();
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetXaxis()->CenterTitle();

  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt;
  return OutGraph;
  
}





TGraphAsymmErrors *Data_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_Pt()
{

  //   Differential cross-section for prompt  Chic1 production, measured in bins of p T .
 // Table 5
  const int NN = 5;
  
  Double_t p8319_d1x1y1_xval[NN] = {11.0, 12.9, 14.9, 16.9, 22.1};
  Double_t p8319_d1x1y1_xerrminus[NN] = {1, 0.9, 0.9, 0.9, 4.1};
  Double_t p8319_d1x1y1_xerrplus[NN] = {1, 1.1, 1.1, 1.1, 7.9};
  
  Double_t p8319_d1x1y1_yval[NN] = {218, 90, 37, 21, 4.8}; 

  


  Double_t p8319_d1x1y1_yerrminus[NN] = {9, 4, 2, 1, 0.2};
  Double_t p8319_d1x1y1_yerrplus[NN] = {9, 4, 2, 1, 0.2};


  Double_t p8319_d1x1y1_yerrminus_syst[NN] = {28, 11, 5, 3, 0.6};
  Double_t p8319_d1x1y1_yerrplus_syst[NN] = {28, 11, 5, 3, 0.6};
  

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t DeltaY = 1.5;
   
  
  Double_t Fac_pBarn2nBarn = 0.001;

  for(int j=0;j<NN;j++){
    p8319_d1x1y1_yval[j] =( (p8319_d1x1y1_yval[j])/DeltaY)*Fac_pBarn2nBarn;
   
    yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus[j]*p8319_d1x1y1_yerrminus[j] + p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j]);
    yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus[j]*p8319_d1x1y1_yerrplus[j] + p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j]); 


    yerr_minus[j]=(yerr_minus[j]/DeltaY)*Fac_pBarn2nBarn;
    yerr_plus[j]=(yerr_plus[j]/DeltaY)*Fac_pBarn2nBarn;

  


  }
   
  TGraphAsymmErrors *Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										       p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->SetMarkerStyle(25);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->SetMarkerColor(1);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->SetMarkerSize(1.8);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->GetYaxis()->SetRangeUser(0.0001,10.0);
  
  TAxis *Xaxis1 = Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,30.0);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->GetYaxis()->CenterTitle();
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->GetXaxis()->CenterTitle();
  
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->GetXaxis()->SetTitle("p_{T}^{J/#psi}[GeV/c]");
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt->GetYaxis()->SetTitle("#frac{B.d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
 
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_Pt;
  return OutGraph;
  
}




TGraphAsymmErrors *Data_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_Pt()
{
  //Differential cross-section for prompt  Chic2 production, measured in bins of p T .
  // Table 5 
  const int NN = 5;
  
  Double_t p8319_d1x1y1_xval[NN] = {11.0, 12.9, 14.9, 16.9, 22.1};
  Double_t p8319_d1x1y1_xerrminus[NN] = {1, 0.9, 0.9, 0.9, 4.1};
  Double_t p8319_d1x1y1_xerrplus[NN] = {1, 1.1, 1.1, 1.1, 7.9};
  
  Double_t p8319_d1x1y1_yval[NN] = {95, 40, 19, 10, 1.9}; 

  


  Double_t p8319_d1x1y1_yerrminus[NN] = {6, 3, 2, 1, 0.2};
  Double_t p8319_d1x1y1_yerrplus[NN] = {6, 3, 2, 1, 0.2};


  Double_t p8319_d1x1y1_yerrminus_syst[NN] = {12, 5, 2, 1, 0.2};
  Double_t p8319_d1x1y1_yerrplus_syst[NN] = {12, 5, 2, 1, 0.2};
  

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t DeltaY = 1.5;
  Double_t Fac_pBarn2nBarn = 0.001;
  
  for(int j=0;j<NN;j++){
    p8319_d1x1y1_yval[j] =( (p8319_d1x1y1_yval[j])/DeltaY)*Fac_pBarn2nBarn;
   
    yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus[j]*p8319_d1x1y1_yerrminus[j] + p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j]);
    yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus[j]*p8319_d1x1y1_yerrplus[j] + p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j]); 


    yerr_minus[j]=(yerr_minus[j]/DeltaY)*Fac_pBarn2nBarn;
    yerr_plus[j]=(yerr_plus[j]/DeltaY)*Fac_pBarn2nBarn;

  


  }
   
  TGraphAsymmErrors *Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										       p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->SetMarkerStyle(34);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->SetMarkerColor(1);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->SetMarkerSize(1.8);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->GetYaxis()->SetRangeUser(0.0001,10.0);
  
  TAxis *Xaxis1 = Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,30.0);
  
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->GetYaxis()->CenterTitle();
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->GetXaxis()->CenterTitle();

  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->GetXaxis()->SetTitle("p_{T}^{J/#psi}[GeV/c]");
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt->GetYaxis()->SetTitle("#frac{B.d^{2}#sigma}{dp_{T}dy}[nb/GeV]");

  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_Pt;
  return OutGraph;
  
}






TGraphAsymmErrors *Data_ATLAS_7TeV_D2NDPtDy_Chic1_Y0075_ChiPt()
{
  //Differential cross-section for prompt  Chic1 production, measured in bins of p T Chic .
  // Table 5 
  const int NN = 5;
  
  Double_t p8319_d1x1y1_xval[NN] = {12.9, 14.9, 16.9, 19.6, 25.0};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.9, 0.9, 0.9, 1.6, 3};
  Double_t p8319_d1x1y1_xerrplus[NN] = {1.1, 1.1, 1.1, 2.4, 5};
  
  Double_t p8319_d1x1y1_yval[NN] = {136, 71, 31, 15.4, 4.0}; 

  


  Double_t p8319_d1x1y1_yerrminus[NN] = {7, 3, 2, 0.8, 0.2};
  Double_t p8319_d1x1y1_yerrplus[NN] = {7, 3, 2, 0.8, 0.2};


  Double_t p8319_d1x1y1_yerrminus_syst[NN] = {16, 9, 4, 1.8, 0.5};
  Double_t p8319_d1x1y1_yerrplus_syst[NN] = {16, 9, 4, 1.8, 0.5};
  

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t DeltaY = 1.5;
  Double_t Fac_pBarn2nBarn = 0.001;
  
  for(int j=0;j<NN;j++){
    p8319_d1x1y1_yval[j] =( (p8319_d1x1y1_yval[j])/DeltaY)*Fac_pBarn2nBarn;
   
    yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus[j]*p8319_d1x1y1_yerrminus[j] + p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j]);
    yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus[j]*p8319_d1x1y1_yerrplus[j] + p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j]); 


    yerr_minus[j]=(yerr_minus[j]/DeltaY)*Fac_pBarn2nBarn;
    yerr_plus[j]=(yerr_plus[j]/DeltaY)*Fac_pBarn2nBarn;

  


  }
 TGraphAsymmErrors *Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										       p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
 Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->SetMarkerStyle(25);
 Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->SetMarkerColor(1);
 Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->SetMarkerSize(1.8);
 
 Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->GetYaxis()->SetTitleOffset(1.6);
 Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->GetYaxis()->SetRangeUser(0.0001,1.0);
  
  TAxis *Xaxis1 = Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->GetXaxis();
  Xaxis1->SetLimits(10.0,30.0);

  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->GetYaxis()->CenterTitle();
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->GetXaxis()->CenterTitle();



  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt->GetYaxis()->SetTitle("#frac{B.d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_7TeV_D2NDPtDy_PromptChic1_Y0075_ChiPt;
  return OutGraph;
  
}


TGraphAsymmErrors *Data_ATLAS_7TeV_D2NDPtDy_Chic2_Y0075_ChiPt()
{
  //Differential cross-section for prompt  Chic2 production, measured in bins of p T Chic .
  // Table 5 
  const int NN = 5;
  
  Double_t p8319_d1x1y1_xval[NN] = {12.9, 14.9, 16.9, 19.7, 25.0};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.9, 0.9, 0.9, 1.7, 3};
  Double_t p8319_d1x1y1_xerrplus[NN] = {1.1, 1.1, 1.1, 2.3, 5};
  
  Double_t p8319_d1x1y1_yval[NN] = {73, 29, 18, 7.0, 1.7};

  


  Double_t p8319_d1x1y1_yerrminus[NN] = {5, 2, 1, 0.6, 0.2};
  Double_t p8319_d1x1y1_yerrplus[NN] = {5, 2, 1, 0.6, 0.2};


  Double_t p8319_d1x1y1_yerrminus_syst[NN] = {9 , 4, 2, 0.9, 0.2};
  Double_t p8319_d1x1y1_yerrplus_syst[NN] = {9 , 4, 2, 0.9, 0.2};
  

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t DeltaY = 1.5;
  Double_t Fac_pBarn2nBarn = 0.001;
  
  for(int j=0;j<NN;j++){
    p8319_d1x1y1_yval[j] =( (p8319_d1x1y1_yval[j])/DeltaY)*Fac_pBarn2nBarn;
   
    yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus[j]*p8319_d1x1y1_yerrminus[j] + p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j]);
    yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus[j]*p8319_d1x1y1_yerrplus[j] + p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j]); 


    yerr_minus[j]=(yerr_minus[j]/DeltaY)*Fac_pBarn2nBarn;
    yerr_plus[j]=(yerr_plus[j]/DeltaY)*Fac_pBarn2nBarn;

  


  }
   
 TGraphAsymmErrors *Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										       p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
 Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->SetMarkerStyle(34);
 Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->SetMarkerColor(1);
 Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->SetMarkerSize(1.8);



  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->GetYaxis()->SetTitleOffset(1.6);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->GetYaxis()->SetRangeUser(0.0001,1.0);
  
  TAxis *Xaxis1 = Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->GetXaxis();
  Xaxis1->SetLimits(10.0,30.0);

  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->GetYaxis()->CenterTitle();
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->GetXaxis()->CenterTitle();


  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt->GetYaxis()->SetTitle("#frac{B.d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_7TeV_D2NDPtDy_PromptChic2_Y0075_ChiPt;
  return OutGraph;
}
  



TGraphAsymmErrors * Data_CMS_7TeV_D2NDPtDy_RatioChiC2ChiC1_Y1010_JPsiPt()
{
  
  //Ratio of prompt  Chic2.BR(ChiC2-->JPsi+Gamma)/Chic1.BR(ChiC1-->JPsi+Gamma) production, 
  //measured in bins of JPsi Pt, |y^{J/psi}| < 1.0 
  
  const int NN = 6;
  
  Double_t p8319_d1x1y1_xval[NN] = {8, 10, 12, 14.5, 18, 22.5};
  Double_t p8319_d1x1y1_xerrminus[NN] = {1, 1, 1, 1.5, 2, 2.5};
  Double_t p8319_d1x1y1_xerrplus[NN] = {1, 1, 1, 1.5, 2, 2.5};
  
  Double_t p8319_d1x1y1_yval[NN] = {0.451, 0.427, 0.421, 0.441, 0.365, 0.387};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.043, 0.024, 0.024, 0.025, 0.027, 0.042};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.043, 0.024, 0.024, 0.025, 0.027, 0.042};

  Double_t p8319_d1x1y1_yerrminus_syst[NN] = {0.025, 0.023, 0.017, 0.017, 0.016, 0.026};
  Double_t p8319_d1x1y1_yerrplus_syst[NN] = {0.025, 0.023, 0.017, 0.017, 0.016, 0.026};
  

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t DeltaY = 1.0;
   
  
  for(int j=0;j<NN;j++){

    p8319_d1x1y1_yval[j] =( (p8319_d1x1y1_yval[j])/DeltaY);
   
    yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus[j]*p8319_d1x1y1_yerrminus[j] + p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j]);
    yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus[j]*p8319_d1x1y1_yerrplus[j] + p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j]); 

    yerr_minus[j]=(yerr_minus[j]/DeltaY);
    yerr_plus[j]=(yerr_plus[j]/DeltaY);

  }
   

  TGraphAsymmErrors *Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt = new TGraphAsymmErrors(NN, p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
												 p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt->SetMarkerStyle(25);
  Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt->SetMarkerColor(1);
  Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt->SetMarkerSize(1.8);
  Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt->GetYaxis()->SetTitleOffset(1.8);
  Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt->GetYaxis()->CenterTitle();
  Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt->GetXaxis()->CenterTitle();
  Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt->GetXaxis()->SetTitle("p_{T}^{J/#psi}[GeV/c]");
  Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt->GetYaxis()->SetTitle("#frac{ #sigma(#chi_{C2})B(#chi_{C2})}{#sigma(#chi_{C1})B(#chi_{C1})}");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CMS_7TeV_D2NDPtDy_PromptChiC2ChiC1_Y1010_JPsiPt;
  /*
  OutGraph->GetYaxis()->SetRangeUser(0.0,1.0);
  TAxis *Xaxis1 = OutGraph->GetXaxis();
  Xaxis1->SetLimits(0.0,30.0);
  */

  return OutGraph;
}




TGraphAsymmErrors *Data_LHCb_7TeV_D2NDPtDy_RatioChi2ChiC1_Y2045_JPsiPt()
{
  const int NN = 10;
  Double_t p8319_d1x1y1_xval[NN] = {3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 10.0, 12.0, 14.5, 18.0 };
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1.5, 2};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1.5, 2};
  Double_t p8319_d1x1y1_yval[NN] = {1.037, 0.923, 0.795, 0.746, 0.692, 0.699, 0.625, 0.6, 0.675,  0.581};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.033, 0.029, 0.028, 0.032, 0.039, 0.044, 0.035, 0.057, 0.067, 0.096};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.033, 0.029, 0.028, 0.032, 0.039, 0.044, 0.035, 0.057, 0.067, 0.096};

  Double_t p8319_d1x1y1_yerrminus_syst[NN] = {0.060, 0.060, 0.048, 0.044, 0.040, 0.041, 0.036, 0.036, 0.051, 0.038};
  Double_t p8319_d1x1y1_yerrplus_syst[NN] = {0.060, 0.060, 0.048, 0.044, 0.040, 0.041, 0.036, 0.036, 0.051, 0.038};
  

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t DeltaY = 1.0;
   
  for(int j=0;j<NN;j++){
    p8319_d1x1y1_yval[j] =( (p8319_d1x1y1_yval[j])/DeltaY);
    yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus[j]*p8319_d1x1y1_yerrminus[j] + p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j]);
    yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus[j]*p8319_d1x1y1_yerrplus[j] + p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j]); 
    yerr_minus[j]=(yerr_minus[j]/DeltaY);
    yerr_plus[j]=(yerr_plus[j]/DeltaY);
  }
   

  TGraphAsymmErrors *Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
												    p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt->SetMarkerStyle(21);
  Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt->SetMarkerColor(1);
  Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt->SetMarkerSize(1.8);
  Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt->GetYaxis()->SetTitleOffset(1.6);
  Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt->GetYaxis()->SetRangeUser(0.0,1.5);
  
 
  Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt->GetYaxis()->CenterTitle();
  Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt->GetXaxis()->CenterTitle();

  Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt->GetXaxis()->SetTitle("p_{T}^{J/#psi}[GeV/c]");
  Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt->GetYaxis()->SetTitle("#frac{ #sigma(#chi_{C2})}{#sigma(#chi_{C1})}");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_LHCb_7TeV_D2NDPtDyRatio_PromptChiC2ChiC1_Y2045_JPsiPt;
  return OutGraph;
}


/*
Double_t finter(Double_t *x, Double_t *par)
{
    return f1->EvalPar(x,par)/f2->EvalPar(x,par);
}

Double_t fint(Double_t start,Double_t end) {                               
       TF1 *fint = new TF1("fint",finter,start,end,0);
       Double_t xint = fint->GetMinimumX();
       return xint;
}


int fint3 ()
{
   f1=new TF1("f1","x^2 + 4",0,10);
   f2=new TF1("f2","x + 3",0,10);
   cout << "x_int = " << fint(0,8) << endl;
}
*/

TGraph *ThRatio_ChiC2ChiC1(TGraph *InGraph1, Double_t Fac1, TGraph *InGraph2, Double_t Fac2, TGraph *InGraph3, Double_t Fac3, TGraph *InGraph4, Double_t Fac4)
{
  
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx1,yy1,zz1;
    Double_t xx2,yy2,zz2;
    Double_t xx3,yy3,zz3;
    Double_t xx4,yy4,zz4;

    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);

    InGraph3->GetPoint(j,xx3,yy3);
    InGraph4->GetPoint(j,xx4,yy4);

    zz1 = Fac1*yy1 + Fac2*yy2;
    zz2 = Fac3*yy3 + Fac4*yy4;

    //zz1 = Fac1*yy1;
    //zz2 = Fac3*yy3;

    zz3=zz2/zz1;

    SGraph->SetPoint(j,xx1,zz3);  
    
  }

  SGraph->SetLineStyle(7);
  SGraph->SetLineWidth(2);

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;
}



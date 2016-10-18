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
TFile *file_CMS_RootS7TeV_Y3SCrossSection =  new TFile("rootFiles/CMS/Y3SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CMS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CMS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CMS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CMS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CMS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//
TGraphAsymmErrors *Data_CMS_D2NDPtDy_Y3S_Y0012_Pt();



//================== ATLAS: open the calculated root file ===========================================//
TFile *file_ATLAS_RootS7TeV_Y3SCrossSection =  new TFile("rootFiles/ATLAS/Y3SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//
TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_Y3S_Y0012_Pt();


//================== LHCb: open the calculated root file ===========================================//
TFile *file_LHCb_RootS7TeV_Y3SCrossSection =  new TFile("rootFiles/LHCb/Y3SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_LHCb_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
TGraphAsymmErrors *Data_LHCb_D2NDPtDy_Y3S_Y2025_Pt();




//================== CDF: open the calculated root file ===========================================//
TFile *file_CDF_RootS180TeV_Y3SCrossSection =  new TFile("rootFiles/CDF/Y3SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CDF_RootS180TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CDF_RootS180TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS180TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CDF_RootS180TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CDF_RootS180TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CDF_RootS180TeV_Y3SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
TGraphAsymmErrors *Data_CDF_D2NDPtDy_Y3S_Y0004_Pt();


Double_t CMS_FitLDME(Double_t *x, Double_t *par);
Double_t ATLAS_FitLDME(Double_t *x, Double_t *par);
Double_t LHCb_FitLDME(Double_t *x, Double_t *par);
Double_t CDF_FitLDME(Double_t *x, Double_t *par);


//================ Global Fittings ================================//
TGraphAsymmErrors *gr0;
TGraphAsymmErrors *gr1;



Double_t fcn0(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn1(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);

TGraph *Scale_QCDSigma(TGraph *InGraph, Double_t LDME);
TGraph *Add_QCDSigma(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3,TGraph *InGraph4);
TGraphAsymmErrors *CutGraph(TGraph *InGraph, Double_t XMin);
Double_t CalcChi2(TGraphAsymmErrors *InGrf, TF1 *InFunc);
TGraph *ScaleGraph(TGraph *InGraph, Double_t ScaleFac);

const Double_t mC = 4.88;
const Double_t Y3SToMuMu = 0.0218;

void Y3SLDME()
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



  /*
  //======================== Checking Ratio ======================================//
  Double_t PT[200]; Double_t SDCS[200];
  Double_t SDCS1[200];
 
  Double_t PtMin = 2.0;
  Double_t PtMax = 100.0;
  Double_t PtStep = 0.5;
  Double_t NN = (PtMax - PtMin)/PtStep;

  for(int i=0;i<NN;i++){
    PT[i]=PtMin + i*PtStep;
    SDCS1[i]=2.0*mC*mC*CDFRatio_3PJ8_1S0_8(PT[i]);
    SDCS[i]=2.0*mC*mC*Ratio_3PJ8_1S0_8(PT[i]);
  }

  TGraph *grf_Ratio_3PJ_8_1S0_8 = new TGraph(NN,PT,SDCS);
  grf_Ratio_3PJ_8_1S0_8->GetYaxis()->SetRangeUser(0.0,10.0);

  grf_Ratio_3PJ_8_1S0_8->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grf_Ratio_3PJ_8_1S0_8->GetYaxis()->SetTitle("#frac{m_{c}^{2}*3PJ_8}{1S0_8}");

  TGraph *grf_CDFRatio_3PJ_8_1S0_8 = new TGraph(NN,PT,SDCS1);
  grf_CDFRatio_3PJ_8_1S0_8->SetLineColor(2);

  new TCanvas;
  gPad->SetLeftMargin(0.14);
  grf_Ratio_3PJ_8_1S0_8->Draw("AL");
  grf_CDFRatio_3PJ_8_1S0_8->Draw("Lsame");
  
  //return;
  */
  Double_t nbTopb = 1000.0;
  //================ scale for BR ================//
  grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=ScaleGraph(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,Y3SToMuMu*nbTopb);
  grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=ScaleGraph(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,Y3SToMuMu*nbTopb);
  grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=ScaleGraph(grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Y3SToMuMu*nbTopb);


  grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=ScaleGraph(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,Y3SToMuMu*nbTopb);
  grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=ScaleGraph(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,Y3SToMuMu*nbTopb);
  grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=ScaleGraph(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Y3SToMuMu*nbTopb);


  grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=ScaleGraph(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,Y3SToMuMu);
  grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=ScaleGraph(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,Y3SToMuMu);
  grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=ScaleGraph(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Y3SToMuMu);


  grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit=ScaleGraph(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit,Y3SToMuMu);
  grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit=ScaleGraph(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,Y3SToMuMu);
  grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit=ScaleGraph(grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Y3SToMuMu);


  //============================ Open a output text file ====================================//
  char OutTextFile[100];
  sprintf(OutTextFile,"LDME_Y3S.txt");
  ofstream dataFile(Form(OutTextFile),ios::app);


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING CMS DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  cout<<" getting Data Graph 1: "<<endl;
  TGraphAsymmErrors *grfData_CMS_D2NDPtDy_Y3S_Y0012_Pt=new TGraphAsymmErrors();
  grfData_CMS_D2NDPtDy_Y3S_Y0012_Pt=Data_CMS_D2NDPtDy_Y3S_Y0012_Pt();



  TF1 *CMSFitFunctionLDME = new TF1("CMSFitFunctionLDME", CMS_FitLDME, 10.0, 100, 3);
  CMSFitFunctionLDME->SetLineColor(2);


  //Double_t LDME_3S1_1 = par[0];  
  //Double_t LDME_1S0_8 = par[1];
  //Double_t LDME_3S1_8 = par[2];
  
  //  0       1     2     
 // 3S1_1, 1S0_8, 3S1_8 
  CMSFitFunctionLDME->FixParameter(0,1);                         

  grfData_CMS_D2NDPtDy_Y3S_Y0012_Pt->Fit("CMSFitFunctionLDME","0","MER", 20, 100);
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CMS_D2NDPtDy_Y3S_Y0012_Pt->Draw("zAP");
  CMSFitFunctionLDME->Draw("same");

  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING ATLAS DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  cout<<" getting Data Graph 1: "<<endl;
  TGraphAsymmErrors *grfData_ATLAS_D2NDPtDy_Y3S_Y0012_Pt=new TGraphAsymmErrors();
  grfData_ATLAS_D2NDPtDy_Y3S_Y0012_Pt=Data_ATLAS_D2NDPtDy_Y3S_Y0012_Pt();



  TF1 *ATLASFitFunctionLDME = new TF1("ATLASFitFunctionLDME", ATLAS_FitLDME, 10.0, 100, 3);
  ATLASFitFunctionLDME->SetLineColor(2);

  //  0       1     2     
  // 3S1_1, 1S0_8, 3S1_8
  ATLASFitFunctionLDME->FixParameter(0,1);                         
  grfData_ATLAS_D2NDPtDy_Y3S_Y0012_Pt->Fit("ATLASFitFunctionLDME","0","MER", 15, 70);
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_Y3S_Y0012_Pt->Draw("zAP");
  ATLASFitFunctionLDME->Draw("same");


 


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING LHCb DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;


  cout<<" getting Data Graph 1: "<<endl;
  TGraphAsymmErrors *grfData_LHCb_D2NDPtDy_Y3S_Y2025_Pt=new TGraphAsymmErrors();
  grfData_LHCb_D2NDPtDy_Y3S_Y2025_Pt=Data_LHCb_D2NDPtDy_Y3S_Y2025_Pt();


  TF1 *LHCbFitFunctionLDME = new TF1("LHCbFitFunctionLDME", LHCb_FitLDME, 5.0, 20, 3);
  LHCbFitFunctionLDME->SetLineColor(2);

  //  0       1     2     
 // 3S1_1, 1S0_8, 3S1_8 
  LHCbFitFunctionLDME->FixParameter(0,1);                         

  grfData_LHCb_D2NDPtDy_Y3S_Y2025_Pt->Fit("LHCbFitFunctionLDME","0","MER", 5, 15);
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_Y3S_Y2025_Pt->Draw("zAP");
  LHCbFitFunctionLDME->Draw("same");


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING CDF DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;


  cout<<" getting Data Graph "<<endl;
  TGraphAsymmErrors *grfData_CDF_D2NDPtDy_Y3S_Y0004_Pt=new TGraphAsymmErrors();
  grfData_CDF_D2NDPtDy_Y3S_Y0004_Pt=Data_CDF_D2NDPtDy_Y3S_Y0004_Pt();

  TF1 *CDFFitFunctionLDME = new TF1("CDFFitFunctionLDME", CDF_FitLDME, 5.0, 20, 3);
  CDFFitFunctionLDME->SetLineColor(2);

  //  0       1     2     
 // 3S1_1, 1S0_8, 3S1_8 
  CDFFitFunctionLDME->FixParameter(0,1);                         

  grfData_CDF_D2NDPtDy_Y3S_Y0004_Pt->Fit("CDFFitFunctionLDME","0","MER", 8, 20);
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_D2NDPtDy_Y3S_Y0004_Pt->Draw("zAP");
  CDFFitFunctionLDME->Draw("same");





  










 


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_Y3S_Y2025_Pt->Draw("zAP");
  grfData_CMS_D2NDPtDy_Y3S_Y0012_Pt->Draw("Psame");
  grfData_ATLAS_D2NDPtDy_Y3S_Y0012_Pt->Draw("Psame");
  grfData_CDF_D2NDPtDy_Y3S_Y0004_Pt->Draw("Psame");


  return;

  cout<<" ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ======================== COMBINED FITTING of ATLAS and CMS Data 7 TeV Data ================================="<<endl;
  cout<<" ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  gr0=new TGraphAsymmErrors();
  gr0=Data_CMS_D2NDPtDy_Y3S_Y0012_Pt();

  gr1=new TGraphAsymmErrors();
  gr1=CutGraph(Data_ATLAS_D2NDPtDy_Y3S_Y0012_Pt(),15);
    
  TGraphAsymmErrors *gr1_t =new TGraphAsymmErrors();
  gr1_t = Data_ATLAS_D2NDPtDy_Y3S_Y0012_Pt();

 //---------------------------------------------------------------------
  //     Blocks for fitting procedure
  //---------------------------------------------------------------------
  const Int_t npars = 3;
  TMinuit *gMinuit = new TMinuit(npars);  //initialize TMinuit with a maximum of 3 params
  gMinuit->SetFCN(fcn);
 
  //This is where the delta chi2 is defined
  //This is critical to getting the correct error estimates

  //I learned now that 'SET ERR' decides if you have a chi-squared (arglist[0]=1)
  //or loglikelihood fit (arglist[0]=0.5) -- if one does not consider the fcn return value explicitly.
 
  Double_t arglist[10];
  Int_t ierflg = 1.0;

  arglist[0] = 0.5;

  gMinuit->mnexcm("SET ERR", arglist, 1, ierflg);
  
  // Set starting values and step sizes for parameters
  
  static Double_t vstart[] = {1.0,0.0002,0.0513};  
  //static Double_t vstart[] = {2.0,0.0080,0.0033};
  //static Double_t vstart[] = {3.0,0.0080,0.0033};
  //static Double_t vstart[] = {0.5,0.0080,0.0033};

  //static Double_t vstart[] = {1.0,0.028,0.0018};
  static Double_t step[]   = {0.0001,0.00001,0.00001};

  gMinuit->mnparm(0, "3S1_1", vstart[0], step[0], 0, 0, ierflg);
  gMinuit->mnparm(1, "1S0_8", vstart[1], step[1], 0, 0, ierflg);
  gMinuit->mnparm(2, "3S1_8", vstart[2], step[2], 0, 0, ierflg);
  
  gMinuit->FixParameter(0);
  //gMinuit->SetErrorDef(1);
  //gMinuit->Print(1);

  // Now ready for minimization step
  arglist[0] = 500; //max 500
  arglist[1] = 0.1; // tolerance = 0.1
  gMinuit->mnexcm("MIGRAD", arglist, 2, ierflg);
  
  //gMinuit->mnexcm("HESSE", arglist, 2, ierflg);
  //gMinuit->mnexcm("MINOS", arglist, 2, ierflg);
  
  // Print results
  Double_t amin,edm,errdef;
  Int_t nvpar,nparx,icstat;
  gMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
  Int_t iuext;
  TString chnam;   // The name of the parameter
  Double_t val;    // The current (external) value of the parameter 
  Double_t errl[npars]={0};   // The current estimate of the parameter uncertainty  
  Double_t xlolim; // The lower bound (or zero if no limits)
  Double_t xuplim; // The upper bound (or zero if no limits)
  Int_t iuint;     // The internal parameter number 
 
 Int_t i = 0;
  Double_t currentPar[npars] = {0};
  for (i=0; i< npars;i++) {
    gMinuit->mnpout(i, chnam, currentPar[i], errl[i], xlolim, xuplim, iuint);
    cout<<chnam<<"   "<<currentPar[i]<<"  "<<errl[i]<<"  "<<xlolim<<"  "<<xuplim<<"  "<<iuint<<endl;

  }


  TF1 *fun_0=new TF1("fun_0",CMS_FitLDME, 10.0, 100, 3); 	
  for(Int_t i=0;i<3;i++){fun_0->FixParameter(i,currentPar[i]);}
  fun_0->SetLineColor(2);
  fun_0->SetLineStyle(1);
  fun_0->SetLineWidth(4);


  TF1 *fun_1=new TF1("fun_1",ATLAS_FitLDME, 15.0, 100, 3);
  for(Int_t i=0;i<3;i++){fun_1->FixParameter(i,currentPar[i]);}
  fun_1->SetLineColor(2);
  fun_1->SetLineStyle(1);
  fun_1->SetLineWidth(4);





  cout<<endl<<endl;
  cout<<" combined fitting perameters "<<endl;
  cout<<"LDME : 3S1_1 "<<currentPar[0]<<" \\pm "<<errl[0]<<endl;
  cout<<"LDME : 3S1_8 "<<currentPar[2]<<" \\pm "<<errl[2]<<endl;
  cout<<"LDME : M(1S0_8/5 + 3P0_8/mc2)  "<<currentPar[1]<<" \\pm "<<errl[1]<<endl;
  
  
  
  dataFile<<endl<<endl;
  dataFile<<" combined fitting perameters "<<endl;
  dataFile<<"LDME : 3S1_1 "<<currentPar[0]<<"\\pm"<<errl[0]<<endl;
  dataFile<<"LDME : 3S1_8 "<<currentPar[2]<<"\\pm"<<errl[2]<<endl;
  dataFile<<"LDME : M(1S0_8/5 + 3P0_8/mc2)  "<<currentPar[1]<<" \\pm "<<errl[1]<<endl;



  Double_t Comb_LDME_3S1_1 = currentPar[0];
  Double_t Comb_LDME_3S1_8 = currentPar[2];
  Double_t Comb_LDME_1S0_8= currentPar[1];

  gr0->Fit("fun_0","Q0","MER", 10, 100);
 
  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);
  
  
  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);

  
  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Comb_LDME_1S0_8);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);




  Double_t Fac_1S0_8_To_3PJ_8 = 5.0;
  
  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Scale_QCDSigma(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Fac_1S0_8_To_3PJ_8);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineStyle(9);


  TLegend *Comb_lgd_DSigmaDPtDY_Pt1 = new TLegend(0.20,0.87,0.90,0.93);
  Comb_lgd_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_DSigmaDPtDY_Pt1->SetHeader("pp #surds=7 TeV, #varUpsilon(3S), |y^{#varUpsilon(3S)}| #leq 1.2");
  
  TLegend *Comb_lgd_DSigmaDPtDY_Pt1_1 = new TLegend(0.62,0.48,0.89,0.86);
  Comb_lgd_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);
  Comb_lgd_DSigmaDPtDY_Pt1_1->AddEntry(gr0,"CMS Data","P");
  Comb_lgd_DSigmaDPtDY_Pt1_1->AddEntry(fun_0,"Total","L");
  Comb_lgd_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,10.0);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,10.0);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=CutGraph(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,10.0);


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  TAxis *gr0_xaxis = new TAxis();
  gr0_xaxis->SetLimits(0.0,100.0);
  gr0->GetYaxis()->SetRangeUser(0.0001,100.0);
  gr0->SetMarkerSize(1.8);
  gr0->SetMarkerStyle(24);
  gr0->SetMarkerColor(1);
  gr0->Draw("zAP");
  gr0->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_0->Draw("same");
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  Comb_lgd_DSigmaDPtDY_Pt1->Draw("same");
  Comb_lgd_DSigmaDPtDY_Pt1_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(a)");
  gPad->SaveAs("Plots/Y3S_CMS.pdf");
  gPad->SaveAs("Plots/Y3S_CMS.png");


  
  gr1_t->Fit("fun_1","Q0","MER", 10, 100);
  
  TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);

  TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);

  TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Comb_LDME_1S0_8);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);

 
  TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit= Scale_QCDSigma(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Fac_1S0_8_To_3PJ_8);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineStyle(9);
  

  TLegend *Comb_lgd_ATLAS_DSigmaDPtDY_Pt1 = new TLegend(0.347,0.885,0.892,0.935);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetHeader("pp #surds=7 TeV, #varUpsilon(3S), |y^{#varUpsilon(3S)}| #leq 1.2");

  TLegend *Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1 = new TLegend(0.580,0.527,0.924,0.878);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);

  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(gr1,"ATLAS Data","P");  
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(fun_1,"Total","L");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  


  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,15.0);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,15.0);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=CutGraph(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,15.0);




  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  
  gr1_t->GetYaxis()->SetRangeUser(0.0001,100.0);
  gr1_t->SetMarkerSize(1.8);
  gr1_t->SetMarkerColor(1);
  gr1_t->Draw("zAP");
  gr1_t->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_1->Draw("same");
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->Draw("same");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->Draw("same");
  
  tb->DrawLatex(0.23,0.18,"(b)");

  gPad->SaveAs("Plots/Y3S_ATLAS.pdf");
  gPad->SaveAs("Plots/Y3S_ATLAS.png");

 


Double_t TotalChi2 = CalcChi2(gr0,fun_0) + CalcChi2(gr1,fun_1);
  
  Double_t TotalNDF = (gr0->GetN() + gr1->GetN()) - 2 ;
  
  cout<<" Total Chi2 "<<TotalChi2<<"/"<<TotalNDF<<"   "<<(TotalChi2/TotalNDF)<<endl;












  return;







}


Double_t CMS_FitLDME(Double_t *x, Double_t *par)
{

 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 

  

  //Double_t Norm = par[3];
  /*
  Double_t LDME_3P0_8;
  Double_t LDME_3P1_8;
  Double_t LDME_3P2_8;

  LDME_3P0_8 = mC*mC*LDME_1S0_8;
  LDME_3P1_8=3.0*LDME_3P0_8;
  LDME_3P2_8=5.0*LDME_3P0_8;
  */

  //Double_t Sigma = (LDME_3S1_1*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_1S0_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]) + 
  //		    LDME_3S1_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) + LDME_3P0_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Eval(x[0]) + 
  //		    LDME_3P1_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Eval(x[0])+ LDME_3P2_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Eval(x[0]));
  
  
Double_t Sigma = LDME_3S1_1*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) 
    + LDME_1S0_8 * 5.0 * grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]);

  return Sigma;
  
}



Double_t ATLAS_FitLDME(Double_t *x, Double_t *par)
{

 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];

  /*
  Double_t LDME_3P0_8;
  Double_t LDME_3P1_8;
  Double_t LDME_3P2_8;

  LDME_3P0_8 = mC*mC*LDME_1S0_8;
  LDME_3P1_8=3.0*LDME_3P0_8;
  LDME_3P2_8=5.0*LDME_3P0_8;
  */
  //  Double_t Sigma = (LDME_3S1_1*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_1S0_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]) + 
  //LDME_3S1_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) + LDME_3P0_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Eval(x[0]) + 
  //		    LDME_3P1_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Eval(x[0])+ LDME_3P2_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Eval(x[0]));



  Double_t Sigma = LDME_3S1_1*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) 
    + LDME_1S0_8 * 5.0 * grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]);



  return Sigma;
  
}









Double_t LHCb_FitLDME(Double_t *x, Double_t *par)
{

 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  
  
  Double_t Sigma = LDME_3S1_1*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) 
    + LDME_1S0_8 * 5.0 * grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]);

  return Sigma;
  
}



Double_t CDF_FitLDME(Double_t *x, Double_t *par)
{

 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  
  
  Double_t Sigma = LDME_3S1_1*grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0]) 
    + LDME_1S0_8 * 5.0 * grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]);

  return Sigma;
  
}













//______________________________________________________________________________
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
    Double_t delta  = (yy0[i]-CMS_FitLDME(&xx0[i],par))/erryy0[i];
    chisq += delta*delta;
  }
  return chisq;
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
    Double_t delta  = (yy1[i]-ATLAS_FitLDME(&xx1[i],par))/erryy1[i];
    chisq += delta*delta;
  }
  return chisq;
}


//______________________________________________________________________________
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{


  f = fcn0(npar,gin, par, iflag) + fcn1(npar,gin, par, iflag);


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
      //cout<<InGrf->GetErrorY(j)<<"   "<<InGrf->GetErrorYlow(j)<<"   "<<InGrf->GetErrorYhigh(j)<<"  "<<InGrf->GetErrorYlow(j)+InGrf->GetErrorYhigh(j)<<endl;
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
  
  /*  
  OutGraph->SetLineColor(InGraph->GetLineColor());
  OutGraph->SetLineStyle(InGraph->GetLineStyle());
  OutGraph->SetLineWidth(InGraph->GetLineWidth());
  
  OutGraph->SetMarkerColor(InGraph->GetMarkerColor());
  OutGraph->SetMarkerStyle(InGraph->GetMarkerStyle());
  OutGraph->SetMarkerSize(InGraph->GetMarkerSize());
  */



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



TGraph *ScaleGraph(TGraph *InGraph, Double_t ScaleFac)
{
  TGraph *SGraph = new TGraph; 
  for (int j=0; j < InGraph->GetN();++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=yy*ScaleFac;
    SGraph->SetPoint(j,xx,zz);  
  }
 
  TGraph *OutGraph;
  OutGraph = SGraph;
  
  OutGraph->SetLineColor(InGraph->GetLineColor());
  OutGraph->SetLineStyle(InGraph->GetLineStyle());
  OutGraph->SetLineWidth(InGraph->GetLineWidth());
  OutGraph->SetMarkerColor(InGraph->GetMarkerColor());
  OutGraph->SetMarkerStyle(InGraph->GetMarkerStyle());
  OutGraph->SetMarkerSize(InGraph->GetMarkerSize());
  
  return OutGraph;
}


TGraphAsymmErrors *Data_CMS_D2NDPtDy_Y3S_Y0012_Pt()
{
const int NN = 22;
  
  Double_t p8319_d1x1y1_xval[NN] = {11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0, 
				    29.0, 31.0, 33.0, 35.0, 37.0, 39.0, 41.4, 44.4, 47.9, 52.4, 57.4, 64.6, 82.0};
  Double_t p8319_d1x1y1_xerrminus[NN] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 
					 1.0, 1.4, 1.4, 1.9, 2.4, 2.4, 4.6, 12.0};
  Double_t p8319_d1x1y1_xerrplus[NN] = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 
					1.6, 1.6, 2.1, 2.6, 2.6, 5.4, 18.0};
  
  Double_t p8319_d1x1y1_yval[NN] = {20882, 13947, 8909, 5873, 3842, 2648, 1713, 1124, 759, 588, 380, 286, 213, 176, 109, 86, 73, 38, 21, 20, 8.1, 2.3}; 

  Double_t percentage_yerrminus[NN] = {2204.6091764537314, 972.3970025401148, 520.8527819432283, 321.94541097055566, 201.695852173514, 138.2296581779757, 
				       84.35546707238363, 57.324, 44.65217061913116, 35.55334110881845, 29.41995241328578, 23.68107632689021, 15.374410232591037, 
				       12.891324214369911, 9.533606348072068, 7.012560445372289, 7.966036153570984, 3.739671108533476, 2.487946140896141, 
				       2.2643321311150446, 1.0873326078068293, 0.35898424756526576};
  Double_t percentage_yerrplus[NN] = {2204.6091764537314, 972.3970025401148, 520.8527819432283, 321.94541097055566, 201.695852173514, 138.2296581779757, 
				      84.35546707238363, 57.324, 44.65217061913116, 35.55334110881845, 29.41995241328578, 23.68107632689021, 15.374410232591037, 
				      12.891324214369911, 9.533606348072068, 7.012560445372289, 7.966036153570984, 3.739671108533476, 2.487946140896141, 
				      2.2643321311150446, 1.0873326078068293, 0.35898424756526576};

  Double_t percentage_yerrplus_syst[NN] = { 229.702, 139.47, 115.81700000000001, 82.222, 61.47200000000001, 47.664, 34.26, 26.976, 23.529, 
					    19.992, 17.099999999999998, 14.299999999999999, 11.289, 10.032, 8.175, 5.848, 5.256, 3.3059999999999996, 2.31, 
					    2.06, 0.9882, 0.322};
  Double_t percentage_yerrminus_syst[NN] = { 229.702, 139.47, 115.81700000000001, 82.222, 61.47200000000001, 47.664, 34.26, 26.976, 23.529, 
					     19.992, 17.099999999999998, 14.299999999999999, 11.289, 10.032, 8.175, 5.848, 5.256, 3.3059999999999996, 2.31, 
					     2.06, 0.9882, 0.322};
  
  Double_t proper_yerrminus[NN];
  Double_t proper_yerrplus[NN];
  Double_t proper_yerrminus_syst[NN];
  Double_t proper_yerrplus_syst[NN];

  for(int i =0;i<NN;i++)
    {
    proper_yerrminus[i] = percentage_yerrminus[i];
    proper_yerrplus[i] = percentage_yerrplus[i];

    proper_yerrminus_syst[i] = percentage_yerrminus_syst[i];
    proper_yerrplus_syst[i] = percentage_yerrplus_syst[i];
    }
   
  

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};

  Double_t FeftoBarnToPicoBarn = 0.001;
  Double_t DeltaY = 2.4;
  Double_t Fac =    FeftoBarnToPicoBarn/DeltaY; 

  for(int i=0;i<NN;i++)
    {
   
    p8319_d1x1y1_yval[i] =p8319_d1x1y1_yval[i]*Fac;
   
    yerr_minus[i]=TMath::Sqrt(proper_yerrminus[i]*proper_yerrminus[i] + proper_yerrminus_syst[i]*proper_yerrminus_syst[i]);
    yerr_plus[i]=TMath::Sqrt(proper_yerrplus[i]*proper_yerrplus[i] + proper_yerrplus_syst[i]*proper_yerrplus_syst[i]); 

    yerr_minus[i]=(yerr_minus[i]*Fac);
    yerr_plus[i]=(yerr_plus[i]*Fac);

  
    }
   
  TGraphAsymmErrors *Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										       p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerStyle(24);
  Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerColor(1);
  Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerSize(1.6);
  Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetTitleOffset(1.6);
  //Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetRangeUser(0.000001,0.1);
  Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetRangeUser(0.0001,100.0);
  
  TAxis *Xaxis1 = Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,100.0);

  Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->CenterTitle();
  Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis()->CenterTitle();

  Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetXaxis()->SetTitle("p_{T}[GeV]");
  Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}#timesB(#mu^{+}#mu^{-})[pb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CMS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt;
  return OutGraph;

}





TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_Y3S_Y0012_Pt()
{
  // D2(SIG)/DPT/DYRAP IN FB/GEV http://hepdata.cedar.ac.uk/view/ins1204994/first
  const int NN = 25;
  
  Double_t p8319_d1x1y1_xval[NN] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 34, 38, 45, 60};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 5, 10};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 5, 10};
  
  Double_t p8319_d1x1y1_yval[NN] = {6022.32, 14021.13, 20711.77, 20317.61, 19951.64, 18330.26, 17320.64, 14677.17, 
				    12151.44, 9357.40, 6510.87, 4765.10, 3157.02, 1992.37, 1334.81, 946.00, 610.91, 437.57, 
				    331.78, 208.81, 161.25, 85.68, 53.61, 19.27, 5.49}; 

  


  Double_t p8319_d1x1y1_yerrminus[NN] = {357.98, 537.42, 639.56, 820.97, 750.21, 762.74, 698.45, 583.39, 587.97, 401.56, 233.58, 
					 135.86, 73.70, 53.92, 40.56, 31.02, 24.73, 20.24, 17.80, 13.49, 12.29, 6.38, 4.99, 2.05, 0.71};
  
  Double_t p8319_d1x1y1_yerrplus[NN] = {357.98, 537.42, 639.56, 820.97, 750.21, 762.74, 698.45, 583.39, 587.97, 401.56, 233.58, 135.86, 
					73.70, 53.92, 40.56, 31.02, 24.73, 20.24, 17.80, 13.49, 12.29, 6.38, 4.99, 2.05, 0.71};


  Double_t p8319_d1x1y1_yerrminus_syst[NN] = {377.25, 756.51, 912.14, 1238.27, 992.47, 916.33, 2042.03, 1588.83, 1133.53, 649.90, 
					      423.86, 374.87, 78.24, 49.95, 23.23, 17.47, 12.08, 9.28, 7.97, 5.55, 4.58, 2.04, 1.48, 0.63, 0.73};
  
  Double_t p8319_d1x1y1_yerrplus_syst[NN] = {377.25, 756.51, 912.14, 1238.27, 992.47, 916.33, 2042.03, 1588.83, 1133.53, 649.90, 423.86, 374.87, 
					     78.24, 49.95, 23.23, 17.47, 12.08, 9.28, 7.97, 5.55, 4.58, 2.04, 1.48, 0.63, 0.73};

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
      
      yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus[j]*p8319_d1x1y1_yerrminus[j] + p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j]);
      yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus[j]*p8319_d1x1y1_yerrplus[j] + p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j]); 
      

      yerr_minus[j]=(yerr_minus[j]/DeltaY)*Fac;
      yerr_plus[j]=(yerr_plus[j]/DeltaY)*Fac;
      
  
    }
  
  TGraphAsymmErrors *Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
											 p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_ATLAS_7TeV_D2NDPtDy_PromptUps3S_Y012_Pt->SetMarkerStyle(25);
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




TGraphAsymmErrors *Data_CDF_D2NDPtDy_Y3S_Y0004_Pt()
{

  //http://lss.fnal.gov/archive/2002/pub/Pub-01-355-E.pdf
  //http://hepdata.cedar.ac.uk/view/ins569269/d3/root

  const int NN = 9;
  
  Double_t p8319_d1x1y1_xval[NN] = {0.58, 1.6, 2.5, 3.5, 4.9, 6.9, 8.8, 11.6, 15.8};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.58, 0.60, 0.5, 0.5, 0.90, 0.90, 0.80, 1.6, 1.8};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.42, 0.4, 0.5, 0.5, 1.1, 1.1, 1.2, 2.4, 4.2};
  
  Double_t p8319_d1x1y1_yval[NN] = {6.2, 10.3, 12.7, 14.4, 9.7, 5.8, 5.8, 2.1, 0.4}; 

  
  Double_t p8319_d1x1y1_yerrminus[NN] = {2.2516660498395407, 2.956349099818897, 3.10322412983658, 3.9458839313897713, 2.3748684174075834, 
					 1.6911534525287764, 1.3601470508735443, 0.574456264653803, 0.1469693845669907};
  
  Double_t p8319_d1x1y1_yerrplus[NN] = {2.2516660498395407, 2.956349099818897, 3.10322412983658, 3.9458839313897713, 2.3748684174075834, 1.6911534525287764, 
					1.3601470508735443, 0.574456264653803, 0.1469693845669907};

  Double_t p8319_d1x1y1_yerrminus_stat[NN] = {1.9, 2.7, 2.9, 3.3, 2.0, 1.5, 1.2, 0.5, 0.1};
  
  Double_t p8319_d1x1y1_yerrplus_stat[NN] = {1.9, 2.7, 2.9, 3.3, 2.0, 1.5, 1.2, 0.5, 0.1 };

  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};
  

/*
  Double_t DeltaY = 1;
  Double_t FeftoBarnToPicoBarn = 0.001;
  Double_t BR_Y3SToMuMu = 0.0218;
  Double_t Fac = FeftoBarnToPicoBarn;

  Fac =1;

  for(int j=0;j<NN;j++)
    {
      p8319_d1x1y1_yval[j] =((p8319_d1x1y1_yval[j])/DeltaY)*Fac;
      
      yerr_minus[j]=TMath::Sqrt(p8319_d1x1y1_yerrminus[j]*p8319_d1x1y1_yerrminus[j] + p8319_d1x1y1_yerrminus_syst[j]*p8319_d1x1y1_yerrminus_syst[j]);
      yerr_plus[j]=TMath::Sqrt(p8319_d1x1y1_yerrplus[j]*p8319_d1x1y1_yerrplus[j] + p8319_d1x1y1_yerrplus_syst[j]*p8319_d1x1y1_yerrplus_syst[j]); 
      

      yerr_minus[j]=(yerr_minus[j]/DeltaY)*Fac;
      yerr_plus[j]=(yerr_plus[j]/DeltaY)*Fac;
      
  
    }
  */
  
  for(int j=0;j<NN;j++)
    {
      yerr_minus[j]= p8319_d1x1y1_yerrminus[j];
      yerr_plus[j]=p8319_d1x1y1_yerrplus[j];
    }
  
  TGraphAsymmErrors *Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
											 p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->SetMarkerStyle(27);
  Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->SetMarkerColor(1);
  Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->SetMarkerSize(2.0);
  Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->GetYaxis()->SetRangeUser(0.0001,100);
  
  TAxis *Xaxis1 = Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
  
  Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->GetYaxis()->CenterTitle();
  Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->GetXaxis()->CenterTitle();
  
  Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->GetXaxis()->SetTitle("p_{T}[GeV]");
  Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}#timesB(#mu^{+}#mu^{-})[pb/GeV]");
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CDF_180TeV_D2NDPtDy_PromptUps3S_Y0040_Pt;
  return OutGraph;
  
}












TGraphAsymmErrors *Data_LHCb_D2NDPtDy_Y3S_Y2025_Pt()
{

  //http://arxiv.org/pdf/1202.6579.pdf
  //http://hepdata.cedar.ac.uk/view/ins1091071/d12/root

  const int NN = 15;
  
  Double_t p8319_d1x1y1_xval[NN] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 
				    9.5, 10.5, 11.5, 12.5, 13.5, 14.5};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
					 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 
					0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
  
  Double_t p8319_d1x1y1_yval[NN] = {7.0, 14.1, 17.6, 24.9, 16.7, 16.6, 22.2, 20.6, 13.7, 
				    11.3, 8.4, 8.7, 4.5, 2.4, 0.7}; 

  
  Double_t p8319_d1x1y1_yerrminus[NN] = {3.0166206257996713, 5.781003373117854, 5.847221562417487, 8.247423840206105, 5.61159513863928, 
					 5.119570294468081, 6.230569797378085, 5.993329625508679, 3.8716921365211876, 
					 3.0643106892089125, 2.5317977802344327, 2.238302928559939, 1.3601470508735443, 0.812403840463596, 0.4123105625617661};
  
  Double_t p8319_d1x1y1_yerrplus[NN] = {2.0074859899884734, 3.477067730142742, 3.6592348927063973, 4.972926703662543, 3.4985711369071804, 3.2878564445547194, 
					4.057092555020159, 3.7483329627982624, 2.643860813280457, 
					2.1977260975835913, 1.8466185312619388, 1.7117242768623688, 1.0954451150103324, 0.7348469228349533, 0.4123105625617661};

  Double_t p8319_d1x1y1_yerrminus_stat[NN] = {1.5, 2.2, 2.3, 2.7, 2.2, 2.1, 2.5, 2.4, 1.9, 
					      1.7, 1.5, 1.4, 1.0, 0.7, 0.4};
  
  Double_t p8319_d1x1y1_yerrplus_stat[NN] = {1.5, 2.2, 2.3, 2.7, 2.2, 2.1, 2.5, 2.4, 1.9, 
					     1.7, 1.5, 1.4, 1.0, 0.7, 0.4};
  Double_t yerr_plus[NN]={0.0};
  Double_t yerr_minus[NN]={0.0};
  
  for(int j=0;j<NN;j++)
    {
      yerr_minus[j]= p8319_d1x1y1_yerrminus[j];
      yerr_plus[j]=p8319_d1x1y1_yerrplus[j];
    }
  
  TGraphAsymmErrors *Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
											 p8319_d1x1y1_xerrplus, yerr_minus, yerr_plus);
  Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->SetMarkerStyle(28);
  Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->SetMarkerColor(1);
  Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->SetMarkerSize(1.6);
  Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->GetYaxis()->SetRangeUser(0.0001,100);
  
  TAxis *Xaxis1 = Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
  
  Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->GetYaxis()->CenterTitle();
  Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->GetXaxis()->CenterTitle();
  
  Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->GetXaxis()->SetTitle("p_{T}[GeV]");
  Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}#timesB(#mu^{+}#mu^{-})[pb/GeV]");
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_LHCb_7TeV_D2NDPtDy_PromptUps3S_Y2025_Pt;
  return OutGraph;
  
}



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
TFile *file_CDF_Chic0_RootS180TeV_CrossSection =  new TFile("CDF_Chic0_RootS180TeV_Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_CDF_Chic0_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_Chic0_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");



//================== CDF: 1.8 TeV  Chic1 calculated root file ===========================================//
TFile *file_CDF_Chic1_RootS180TeV_CrossSection =  new TFile("CDF_Chic1_RootS180TeV_Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_CDF_Chic1_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_Chic1_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");



//================== CDF: 1.8 TeV  Chic2 calculated root file ===========================================//
TFile *file_CDF_Chic2_RootS180TeV_CrossSection =  new TFile("CDF_Chic2_RootS180TeV_Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_CDF_Chic2_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_Chic2_RootS180TeV_CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");



//======== Data Graphs =============================//
TGraphAsymmErrors *Data_CDF_180_D2NDPtDy_Chic1Chic2ToJPsi_Y0006_Pt();

Double_t CDF_180_Chic1Chic2_FitLDME(Double_t *x, Double_t *par);
Double_t CDF_180_Chic0_FitLDME(Double_t *x, Double_t *par);


TGraph *Scale_QCDSigma(TGraph *InGraph, Double_t LDME);
TGraph *Add_QCDSigma(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3,TGraph *InGraph4);

Double_t Scale_Pt(Double_t JPsiPt, Int_t Par);

TGraphAsymmErrors *gr0;
Double_t fcn0(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);

const Double_t mC = 1.6;

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
  


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING CDF RootS 1.8 TeV DATA FOR LDME ================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  cout<<" getting CDF RootS 1.8 TeV Data  Graph : "<<endl;
  
  TGraphAsymmErrors *grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt=new TGraphAsymmErrors();
  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt=Data_CDF_180_D2NDPtDy_Chic1Chic2ToJPsi_Y0006_Pt();
  
  TF1 *CDF_180_Chic0_FitFunctionLDME = new TF1("CDF_180_Chic0_FitFunctionLDME", CDF_180_Chic0_FitLDME, 5.0, 20, 2);

  //TF1 *CDF_180_Chic0_FitFunctionLDME = new TF1("CDF_180_Chic0_FitFunctionLDME", CDF_180_Chic1Chic2_FitLDME, 5.0, 20, 3);
  

  CDF_180_Chic0_FitFunctionLDME->SetLineColor(2);
  CDF_180_Chic0_FitFunctionLDME->FixParameter(0,1.0);     
  CDF_180_Chic0_FitFunctionLDME->FixParameter(2,1.0);     

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

  //grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3P0_1_Fit;  
  //grCDF_Chic0_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit;
  


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
  
   
  TF1 *CDF_180_Chic1Chic2_FitFunctionLDME = new TF1("CDF_180_Chic1Chic2_FitFunctionLDME", CDF_180_Chic1Chic2_FitLDME, 5.0, 20, 3);
  
  CDF_180_Chic1Chic2_FitFunctionLDME->SetLineColor(2);
  CDF_180_Chic1Chic2_FitFunctionLDME->FixParameter(0,1.0);     
  CDF_180_Chic1Chic2_FitFunctionLDME->FixParameter(2,1.0);     

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
  
  Double_t CDF_180_Chic1Chic2_LDME_3P2_1 = CDF_180_Chic1Chic2_FitFunctionLDME->GetParameter(2);

  cout<<"LDME : 3P1_1 "<<CDF_180_Chic1Chic2_LDME_3P1_1<<endl;
  cout<<"LDME : 3S1_8 "<<CDF_180_Chic1Chic2_LDME_3S1_8<<" pm: "<<Err_CDF_180_Chic1Chic2_LDME_3S1_8<<endl;
  cout<<"LDME : 3P2_1 "<<CDF_180_Chic1Chic2_LDME_3P2_1<<endl;
  
  cout<<"Chi2/NDF : "<<CDF_180_Chic1Chic2_Chi2<<"/"<<CDF_180_Chic1Chic2_NDF<<" Prob: "<<CDF_180_Chic1Chic2_Prob<<endl<<endl;
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);

  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->Draw("zAP");
  CDF_180_Chic1Chic2_FitFunctionLDME->Draw("same");


  TGraph *Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit=Scale_QCDSigma(grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit,CDF_180_Chic1Chic2_LDME_3P1_1);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->SetLineColor(6);

  TGraph *Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,CDF_180_Chic1Chic2_LDME_3S1_8);
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(8);
  
  TLegend *lgd_DSigmaDPtDY_CDF_180_Chic1Chic2 = new TLegend(0.37,0.66,0.90,0.94);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->SetBorderSize(0);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->SetFillStyle(0);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->SetFillColor(0);
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->SetTextSize(0.04);

  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->AddEntry(grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt,"CDF J/#psi Data,#surds = 7 TeV ","P"); 
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->AddEntry(CDF_180_Chic1Chic2_FitFunctionLDME,"Total","L"); 
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->AddEntry(Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit,"^{3}P_{1}^{[1]}","L");  
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->AddEntry(Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->SetMarkerSize(1.8);
  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->SetMarkerStyle(24);
  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->SetMarkerColor(1);
  grfData_CDF_180_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->Draw("zAP");
  
  CDF_180_Chic1Chic2_FitFunctionLDME->Draw("same");
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->Draw("Lsame");
  Out_grCDF_Chic1Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_CDF_180_Chic1Chic2->Draw("same");
  
  gPad->SaveAs("Chic1_CDF_Fit.png");
  gPad->SaveAs("Chic1_CDF_Fit.pdf");


  //==================================== Fit with TMiniut ========================//
  gr0=new TGraphAsymmErrors();
  gr0=Data_CDF_180_D2NDPtDy_Chic1Chic2ToJPsi_Y0006_Pt();

  
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
  static Double_t vstart[] = {1.0,0.0010,1.0};
  static Double_t step[]   = {0.1,0.0001,0.1};

  gMinuit->mnparm(0, "3P1_1", vstart[0], step[0], 0, 0, ierflg);
  gMinuit->mnparm(1, "3S1_8", vstart[1], step[1], 0, 0, ierflg);
  gMinuit->mnparm(2, "3P2_1", vstart[2], step[2], 0, 0, ierflg);
  
  gMinuit->FixParameter(0);
  gMinuit->FixParameter(2);
 
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
  
  TF1 *fun_0=new TF1("fun_0",CDF_180_Chic1Chic2_FitLDME, 5.0, 20, 3); 	
  fun_0->SetParameters(currentPar);
  fun_0->SetLineColor(kBlack);
  fun_0->SetLineStyle(1);
  fun_0->SetLineWidth(2);

  cout<<endl<<endl;
  cout<<" TMiniut fitting perameters "<<endl;
  cout<<"LDME : 3P1_1 "<<currentPar[0]<<" pm  "<<errl[0]<<endl;
  cout<<"LDME : 3S1_8 "<<currentPar[1]<<" pm  "<<errl[1]<<endl;
  cout<<"LDME : 3P2_1 "<<currentPar[2]<<" pm  "<<errl[2]<<endl<<endl;


  gr0->Fit("fun_0","Q0","MER", 5, 20);
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr0->Draw("AP");
  fun_0->Draw("same");





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
  Double_t LDME_3P2_1 = par[2];

  //Double_t Scale_Pt(Double_t ChiPt, Int_t Par)
  Double_t Pt = x[0];
  Double_t Pt1 =0.0;
  Double_t Pt2 =0.0;

  Pt1 = Scale_Pt(Pt,1);
  Pt2 = Scale_Pt(Pt,2);

  Double_t Sigma = LDME_3P1_1*grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Pt1) + LDME_3S1_8*grCDF_Chic1_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt1)+ 
    LDME_3P2_1*grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Pt2) + LDME_3S1_8*grCDF_Chic2_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Pt2);
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
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->SetMarkerStyle(26);
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->SetMarkerColor(8);
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->SetMarkerSize(1.6);
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetYaxis()->SetRangeUser(0.0001,1000.0);
  
  TAxis *Xaxis1 = Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,22.0);
  
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CDF_196_D2NDPtDy_PromptChic1Chic2ToJPsi_Y0006_Pt;
  return OutGraph;
  
}



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


void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
  f = fcn0(npar,gin,par, iflag);

  
}































/*
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
    Double_t delta  = (yy3[i]-ATLAS8TeV_FitLDME(&xx3[i],par))/erryy3[i];
    chisq += delta*delta;
  }
  return chisq;
}

//______________________________________________________________________________
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
  for (i=0;i<nbins; i++) {
    Double_t delta  = (yy4[i]-CDF_FitLDME(&xx4[i],par))/erryy4[i];
    chisq += delta*delta;
  }
  return chisq;
}


//______________________________________________________________________________
Double_t fcn5(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag)
{ 
  
  const Int_t nbins = gr5->GetN();
  Int_t i;
  
  Double_t xx5[nbins]; 
  Double_t yy5[nbins];
  Double_t erryy5[nbins];

  for (Int_t j=0;j<nbins; j++) 
    {
      gr5->GetPoint(j,xx5[j],yy5[j]);
      erryy5[j]= gr5->GetErrorY(j);
    }

 //calculate chisquare
  Double_t chisq = 0;
  for (i=0;i<nbins; i++) {
    Double_t delta  = (yy5[i]-CDF_180_FitLDME(&xx5[i],par))/erryy5[i];
    chisq += delta*delta;
  }
  return chisq;
}


//______________________________________________________________________________
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
  f = fcn0(npar,gin,par, iflag) + fcn1(npar,gin, par, iflag) + fcn2(npar,gin, par, iflag) + fcn3(npar,gin, par, iflag);

  //f = fcn0(npar,gin,par, iflag) + fcn1(npar,gin, par, iflag) + fcn2(npar,gin, par, iflag) + fcn3(npar,gin, par, iflag)
  //+ fcn4(npar,gin, par, iflag) + fcn5(npar,gin, par, iflag);


}

*/











  /*
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ======== COMBINED FITTING of ATLAS 7 TeV, 8 TeV and CMS Data =================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  gr0=new TGraphAsymmErrors();
  gr0=Data_CMS_New_D2NDPtDy_PromptPsi2S_Y0012_Pt();

  gr1=new TGraphAsymmErrors();
  gr1=Data_CMS_Latest_D2NDPtDy_PromptPsi2S_Y0012_Pt();

  gr2=new TGraphAsymmErrors();
  gr2=Data_ATLAS_D2NDPtDy_PromptPsi2S_Y0025_Pt();

  gr3=new TGraphAsymmErrors();
  gr3=Data_ATLAS_RootS8TeV_D2NDPtDy_PromptPsi2S_Y0025_Pt();

  gr4=new TGraphAsymmErrors(); 
  gr4=Data_CDF_196_D2NDPtDy_PromptPsi2S_Y0006_Pt();

  gr5=new TGraphAsymmErrors(); 
  gr5=Data_CDF_180_D2NDPtDy_PromptPsi2S_Y0006_Pt();


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
 
  //This is where the delta chi2 is defined
  //This is critical to getting the correct error estimates
  arglist[0] = 1.0;
  if (arglist[0]) gMinuit->mnexcm("SET ERR", arglist, 1, ierflg);
  
  // Now ready for minimization step
  arglist[0] = 500; //max 500
  arglist[1] = 0.1; // tolerance = 0.1
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
  gl_mg->Add(gr0);
  gl_mg->Add(gr1);
  gl_mg->Add(gr2);
  //gl_mg->Add(gr3);
  gl_mg->SetTitle("title;p_{T}[GeV/c]; #frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");


  TF1 *fun_0=new TF1("fun_0",CMS_FitLDME, 5.0, 100, 3); 	
  fun_0->SetParameters(currentPar);
  fun_0->SetLineColor(kBlack);
  fun_0->SetLineStyle(1);
  fun_0->SetLineWidth(2);

  TF1 *fun_1=new TF1("fun_1",CMS_FitLDME, 5.0, 100, 3); 	
  fun_1->SetParameters(currentPar);
  fun_1->SetLineColor(kBlue);
  fun_1->SetLineStyle(1);
  fun_1->SetLineWidth(2);
    
  TF1 *fun_2=new TF1("fun_2",ATLAS_FitLDME, 5.0, 100, 3);
  fun_2->SetParameters(currentPar);
  fun_2->SetLineColor(kRed);
  fun_2->SetLineStyle(1);
  fun_2->SetLineWidth(4);
  
  
  TF1 *fun_3=new TF1("fun_3", ATLAS8TeV_FitLDME, 5.0, 100, 3);
  fun_3->SetParameters(currentPar);
  fun_3->SetLineColor(kGreen);
  fun_3->SetLineStyle(1);
  fun_3->SetLineWidth(4);
  
  TF1 *fun_4=new TF1("fun_4", CDF_FitLDME, 5.0, 30, 3);
  fun_4->SetParameters(currentPar);
  fun_4->SetLineColor(kGreen);
  fun_4->SetLineStyle(1);
  fun_4->SetLineWidth(4);

  TF1 *fun_5=new TF1("fun_5", CDF_180_FitLDME, 5.0, 30, 3);
  fun_5->SetParameters(currentPar);
  fun_5->SetLineColor(kGreen);
  fun_5->SetLineStyle(1);
  fun_5->SetLineWidth(4);


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
  cout<<"LDME : 3S1_8 "<<currentPar[2]<<endl<<endl;
  
  //============================ Calculate Chi2 For Combined fitting =====================//

  gr0->Fit("fun_0","Q0","MER", 5, 100);
  gr1->Fit("fun_1","Q0","MER", 5, 100);

  gr2->Fit("fun_2","Q0","MER", 5, 100);
  gr3->Fit("fun_3","Q0","MER", 5, 100);

  gr4->Fit("fun_4","Q0","MER", 5, 30);
  gr5->Fit("fun_5","Q0","MER", 5, 30);
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr0->Draw("AP");
  fun_0->Draw("same");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr1->Draw("AP");
  fun_1->Draw("same");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr2->Draw("AP");
  fun_2->Draw("same");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr3->Draw("AP");
  fun_3->Draw("same");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr4->Draw("AP");
  fun_4->Draw("same");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr5->Draw("AP");
  fun_5->Draw("same");


  cout<<"chi2/ndf "<<fun_1->GetChisquare()<<"/"<<fun_1->GetNDF()<<" Prob: "<<fun_1->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_2->GetChisquare()<<"/"<<fun_2->GetNDF()<<" Prob: "<<fun_2->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_3->GetChisquare()<<"/"<<fun_2->GetNDF()<<" Prob: "<<fun_3->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_4->GetChisquare()<<"/"<<fun_2->GetNDF()<<" Prob: "<<fun_4->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_5->GetChisquare()<<"/"<<fun_2->GetNDF()<<" Prob: "<<fun_5->GetProb()<<endl;
  */


/*
//================ Global Fittings ================================//
TGraphAsymmErrors *gr0;
TGraphAsymmErrors *gr1;
TGraphAsymmErrors *gr2;
TGraphAsymmErrors *gr3;
TGraphAsymmErrors *gr4;
TGraphAsymmErrors *gr5;

Double_t fcn0(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn1(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn2(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn3(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn4(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn5(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);
*/

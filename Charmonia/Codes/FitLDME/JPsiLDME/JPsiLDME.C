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

const Double_t mC = 1.6;
//==================== Common Branching Ratios =======================//
Double_t BRPsi2S2MuMu =0.0077;
Double_t BRPsi2S2JPsi =0.595;
Double_t BRJPsi2MuMu =0.0593;

/*
//=================== Fitted LDMEs ==================================//
//========= Our Values of fitted Psi(2S) LDME =========//
Double_t Psi2S_LDME_3S1_1 = 1.0;  
Double_t Psi2S_LDME_1S0_8 = 0.02639;
Double_t Psi2S_LDME_3S1_8 = 0.00190;

//Double_t Psi2S_LDME_1S0_8 = 0.02260;
//Double_t Psi2S_LDME_3S1_8 = 0.00210;

Double_t Psi2S_LDME_3P0_8 = mC*mC*Psi2S_LDME_1S0_8;
Double_t Psi2S_LDME_3P1_8 = 3.0*Psi2S_LDME_3P0_8;
Double_t Psi2S_LDME_3P2_8 = 5.0*Psi2S_LDME_3P0_8;

//========= Our Values of fitted Chic LDME =========//
Double_t Chic0_LDME_3P0_1 = 1.0;
Double_t Chic0_LDME_3S1_8 = 0.00156;

Double_t Chic1_LDME_3P1_1 = 1.0;
Double_t Chic1_LDME_3S1_8 = 0.00156;

Double_t Chic2_LDME_3P2_1 = 1.0;
Double_t Chic2_LDME_3S1_8 = 0.00156;
*/



//=================== Fitted LDMEs ==================================//
//========= Our Values of fitted Psi(2S) LDME =========//
Double_t Psi2S_LDME_3S1_1 = 1.0;  
Double_t Psi2S_LDME_3S1_8 = 0.00362;
Double_t Psi2S_LDME_1S0_8 = 0.022804;

//Double_t Psi2S_LDME_1S0_8 = 0.02260;
//Double_t Psi2S_LDME_3S1_8 = 0.00210;
Double_t Psi2S_LDME_3P0_8 = mC*mC*Psi2S_LDME_1S0_8;
Double_t Psi2S_LDME_3P1_8 = 3.0*Psi2S_LDME_3P0_8;
Double_t Psi2S_LDME_3P2_8 = 5.0*Psi2S_LDME_3P0_8;

//========= Our Values of fitted Chic LDME =========//
Double_t Chic1_LDME_3P1_1 = 1.0;
Double_t Chic1_LDME_3S1_8 = 0.011118;
//Double_t Chic1_LDME_3S1_8 = 0.00156;

Double_t Chic2_LDME_3P2_1 = 1.0;
Double_t Chic2_LDME_3S1_8 = 0.011118;
//Double_t Chic2_LDME_3S1_8 = 0.00156;

Double_t Chic0_LDME_3P0_1 = 1.0;
Double_t Chic0_LDME_3S1_8 = 0.11118;
//Double_t Chic0_LDME_3S1_8 = 0.00156;





//====================================================================================================//
//================================= CMS 7 TeV =======================================================//
//==================================================================================================//
//================== CMS_0009: open the calculated root file ===========================================//
TFile *file_CMS_0009_RootS7TeV_JPsiCrossSection =  new TFile("rootFiles/CMS_0009_RootS7TeV/JPsiCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CMS_0009_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//================================== root Files for FeedDown calculations =================================//
//================== Psi(2S): open the calculated root file ===========================================//
TFile *file_CMS_0009_RootS7TeV_Psi2SCrossSection =  new TFile("rootFiles/CMS_0009_RootS7TeV/Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_0009_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCMS_0009_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCMS_0009_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCMS_0009_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCMS_0009_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCMS_0009_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//====================================== Correcting ChiC feed down ===================================================//
//================== Chic0 open the calculated root file ===========================================//
TFile *file_CMS_0009_RootS7TeV_Chic0CrossSection =  new TFile("rootFiles/CMS_0009_RootS7TeV/Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_0009_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grCMS_0009_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
//================== Chic1 open the calculated root file ===========================================//
TFile *file_CMS_0009_RootS7TeV_Chic1CrossSection =  new TFile("rootFiles/CMS_0009_RootS7TeV/Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_0009_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grCMS_0009_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
//================== Chic2 open the calculated root file ===========================================//
TFile *file_CMS_0009_RootS7TeV_Chic2CrossSection =  new TFile("rootFiles/CMS_0009_RootS7TeV/Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_0009_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grCMS_0009_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_0009_RootS7TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");






Double_t CMS_0009_FitLDME(Double_t *x, Double_t *par);
Double_t CMS_0009_Psi2S_FeedDown(Double_t Pt);
Double_t CMS_0009_Chic0_FeedDown(Double_t Pt);
Double_t CMS_0009_Chic1_FeedDown(Double_t Pt);
Double_t CMS_0009_Chic2_FeedDown(Double_t Pt);
TGraphAsymmErrors *Data_CMS_New_D2NDPtDy_PrompJPsi_Y0009_Pt();

TGraph *Grf_CMS_0009_Psi2S_FeedDown(TGraph *InGraph);
TGraph *Grf_CMS_0009_ChiC_FeedDown(TGraph *InGraph, Int_t Par);




//================== CMS: open the calculated root file ===========================================//
TFile *file_CMS_RootS7TeV_JPsiCrossSection =  new TFile("rootFiles/CMS_RootS7TeV/CMS_RootS7TeV_Y0012_JPsiCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CMS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CMS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CMS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CMS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CMS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//
TGraphAsymmErrors *Data_CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt();
//================================== root Files for FeedDown calculations =================================//
//================== Psi(2S): open the calculated root file ===========================================//
TFile *file_CMS_RootS7TeV_Psi2SCrossSection =  new TFile("rootFiles/CMS_RootS7TeV/CMS_RootS7TeV_Y0012_Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCMS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCMS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCMS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCMS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCMS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CMS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//====================================== Correcting ChiC feed down ===================================================//
//================== Chic0 open the calculated root file ===========================================//
TFile *file_CMS_RootS7TeV_Chic0CrossSection =  new TFile("rootFiles/CMS_RootS7TeV/CMS_RootS7TeV_Y0012_Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_CMS_RootS7TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grCMS_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_RootS7TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic1 open the calculated root file ===========================================//
TFile *file_CMS_RootS7TeV_Chic1CrossSection =  new TFile("rootFiles/CMS_RootS7TeV/CMS_RootS7TeV_Y0012_Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_CMS_RootS7TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grCMS_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_RootS7TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic2 open the calculated root file ===========================================//
TFile *file_CMS_RootS7TeV_Chic2CrossSection =  new TFile("rootFiles/CMS_RootS7TeV/CMS_RootS7TeV_Y0012_Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCMS_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_CMS_RootS7TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grCMS_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CMS_RootS7TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

Double_t CMS_FitLDME(Double_t *x, Double_t *par);
Double_t CMS_Psi2S_FeedDown(Double_t Pt);
Double_t CMS_Chic0_FeedDown(Double_t Pt);
Double_t CMS_Chic1_FeedDown(Double_t Pt);
Double_t CMS_Chic2_FeedDown(Double_t Pt);

TGraph *Grf_CMS_Psi2S_FeedDown(TGraph *InGraph);
TGraph *Grf_CMS_ChiC_FeedDown(TGraph *InGraph, Int_t Par);


//====================================================================================================//
//================================= CDF 1.96 TeV =======================================================//
//==================================================================================================//
//================== CDF: open the calculated root file ===========================================//

TFile *file_CDF_RootS196TeV_JPsiCrossSection =  new TFile("rootFiles/CDF_RootS196TeV/JPsiCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CDF_RootS196TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CDF_RootS196TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS196TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CDF_RootS196TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CDF_RootS196TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CDF_RootS196TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");

//================================== root Files for FeedDown calculations =================================//
//================== Psi(2S): open the calculated root file ===========================================//
TFile *file_CDF_RootS196TeV_Psi2SCrossSection =  new TFile("rootFiles/CDF_RootS196TeV/Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS196TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCDF_RootS196TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCDF_RootS196TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCDF_RootS196TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCDF_RootS196TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCDF_RootS196TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CDF_RootS196TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//====================================== Correcting ChiC feed down ===================================================//
//================== Chic0 open the calculated root file ===========================================//
TFile *file_CDF_RootS196TeV_Chic0CrossSection =  new TFile("rootFiles/CDF_RootS196TeV/Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS196TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_CDF_RootS196TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grCDF_RootS196TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS196TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic1 open the calculated root file ===========================================//
TFile *file_CDF_RootS196TeV_Chic1CrossSection =  new TFile("rootFiles/CDF_RootS196TeV/Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS196TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_CDF_RootS196TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grCDF_RootS196TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS196TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic2 open the calculated root file ===========================================//
TFile *file_CDF_RootS196TeV_Chic2CrossSection =  new TFile("rootFiles/CDF_RootS196TeV/Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS196TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_CDF_RootS196TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grCDF_RootS196TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS196TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

Double_t CDF_FitLDME(Double_t *x, Double_t *par);
Double_t CDF_Psi2S_FeedDown(Double_t Pt);
Double_t CDF_Chic0_FeedDown(Double_t Pt);
Double_t CDF_Chic1_FeedDown(Double_t Pt);
Double_t CDF_Chic2_FeedDown(Double_t Pt);

TGraph *Grf_CDF_Psi2S_FeedDown(TGraph *InGraph);
TGraph *Grf_CDF_ChiC_FeedDown(TGraph *InGraph, Int_t Par);

TGraphAsymmErrors *Data_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt();



//====================================================================================================//
//================================= CDF 1.8 TeV =====================================================//
//==================================================================================================//
//================== CDF: open the calculated root file ===========================================//

TFile *file_CDF_RootS180TeV_JPsiCrossSection =  new TFile("rootFiles/CDF_RootS180TeV/JPsiCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CDF_RootS180TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CDF_RootS180TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS180TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CDF_RootS180TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CDF_RootS180TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CDF_RootS180TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");

//================================== root Files for FeedDown calculations =================================//
//================== Psi(2S): open the calculated root file ===========================================//
TFile *file_CDF_RootS180TeV_Psi2SCrossSection =  new TFile("rootFiles/CDF_RootS180TeV/Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS180TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_CDF_RootS180TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grCDF_RootS180TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_CDF_RootS180TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grCDF_RootS180TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS180TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grCDF_RootS180TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_CDF_RootS180TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grCDF_RootS180TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_CDF_RootS180TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grCDF_RootS180TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_CDF_RootS180TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//====================================== Correcting ChiC feed down ===================================================//
//================== Chic0 open the calculated root file ===========================================//
TFile *file_CDF_RootS180TeV_Chic0CrossSection =  new TFile("rootFiles/CDF_RootS180TeV/Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS180TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_CDF_RootS180TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grCDF_RootS180TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS180TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic1 open the calculated root file ===========================================//
TFile *file_CDF_RootS180TeV_Chic1CrossSection =  new TFile("rootFiles/CDF_RootS180TeV/Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS180TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_CDF_RootS180TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grCDF_RootS180TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS180TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic2 open the calculated root file ===========================================//
TFile *file_CDF_RootS180TeV_Chic2CrossSection =  new TFile("rootFiles/CDF_RootS180TeV/Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grCDF_RootS180TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_CDF_RootS180TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grCDF_RootS180TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_CDF_RootS180TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


Double_t CDF_RootS180TeV_FitLDME(Double_t *x, Double_t *par);
Double_t CDF_RootS180TeV_Psi2S_FeedDown(Double_t Pt);
Double_t CDF_RootS180TeV_Chic0_FeedDown(Double_t Pt);
Double_t CDF_RootS180TeV_Chic1_FeedDown(Double_t Pt);
Double_t CDF_RootS180TeV_Chic2_FeedDown(Double_t Pt);
TGraph *Grf_CDF_RootS180TeV_Psi2S_FeedDown(TGraph *InGraph);
TGraph *Grf_CDF_RootS180TeV_ChiC_FeedDown(TGraph *InGraph, Int_t Par);


TGraphAsymmErrors *Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt();

//====================================================================================================//
//================================= ATLAS 7 TeV =======================================================//
//==================================================================================================//
//================== ATLAS open the calculated root file ===========================================//

//================== ATLAS: open the calculated root file ===========================================//
TFile *file_ATLAS_RootS7TeV_JPsiCrossSection =  new TFile("rootFiles/ATLAS_RootS7TeV/JPsiCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//
TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt();

//================================== root Files for FeedDown calculations =================================//
//================== Psi(2S): open the calculated root file ===========================================//
TFile *file_ATLAS_RootS7TeV_Psi2SCrossSection =  new TFile("rootFiles/ATLAS_RootS7TeV/Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//====================================== Correcting ChiC feed down ===================================================//
//================== Chic0 open the calculated root file ===========================================//
TFile *file_ATLAS_RootS7TeV_Chic0CrossSection =  new TFile("rootFiles/ATLAS_RootS7TeV/Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_ATLAS_RootS7TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grATLAS_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic1 open the calculated root file ===========================================//
TFile *file_ATLAS_RootS7TeV_Chic1CrossSection =  new TFile("rootFiles/ATLAS_RootS7TeV/Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_ATLAS_RootS7TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grATLAS_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic2 open the calculated root file ===========================================//
TFile *file_ATLAS_RootS7TeV_Chic2CrossSection =  new TFile("rootFiles/ATLAS_RootS7TeV/Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_ATLAS_RootS7TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grATLAS_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS7TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

Double_t ATLAS_FitLDME(Double_t *x, Double_t *par);
Double_t ATLAS_Psi2S_FeedDown(Double_t Pt);
Double_t ATLAS_Chic0_FeedDown(Double_t Pt);
Double_t ATLAS_Chic1_FeedDown(Double_t Pt);
Double_t ATLAS_Chic2_FeedDown(Double_t Pt);

TGraph *Grf_ATLAS_Psi2S_FeedDown(TGraph *InGraph);
TGraph *Grf_ATLAS_ChiC_FeedDown(TGraph *InGraph, Int_t Par);



//====================================================================================================//
//================================= ATLAS 8 TeV =======================================================//
//==================================================================================================//
//================== ATLAS open the calculated root file ===========================================//

TFile *file_ATLAS_RootS8TeV_JPsiCrossSection =  new TFile("rootFiles/ATLAS_RootS8TeV/JPsiCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS_RootS8TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//


//================================== root Files for FeedDown calculations =================================//
//================== Psi(2S): open the calculated root file ===========================================//
TFile *file_ATLAS_RootS8TeV_Psi2SCrossSection =  new TFile("rootFiles/ATLAS_RootS8TeV/Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS8TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS_RootS8TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grATLAS_RootS8TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grATLAS_RootS8TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grATLAS_RootS8TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grATLAS_RootS8TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grATLAS_RootS8TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//====================================== Correcting ChiC feed down ===================================================//
//================== Chic0 open the calculated root file ===========================================//
TFile *file_ATLAS_RootS8TeV_Chic0CrossSection =  new TFile("rootFiles/ATLAS_RootS8TeV/Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS8TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_ATLAS_RootS8TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grATLAS_RootS8TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic1 open the calculated root file ===========================================//
TFile *file_ATLAS_RootS8TeV_Chic1CrossSection =  new TFile("rootFiles/ATLAS_RootS8TeV/Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS8TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_ATLAS_RootS8TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grATLAS_RootS8TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic2 open the calculated root file ===========================================//
TFile *file_ATLAS_RootS8TeV_Chic2CrossSection =  new TFile("rootFiles/ATLAS_RootS8TeV/Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grATLAS_RootS8TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_ATLAS_RootS8TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grATLAS_RootS8TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_RootS8TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

Double_t ATLAS_8TeV_FitLDME(Double_t *x, Double_t *par);
Double_t ATLAS_8TeV_Psi2S_FeedDown(Double_t Pt);
Double_t ATLAS_8TeV_Chic0_FeedDown(Double_t Pt);
Double_t ATLAS_8TeV_Chic1_FeedDown(Double_t Pt);
Double_t ATLAS_8TeV_Chic2_FeedDown(Double_t Pt);
TGraph *Grf_ATLAS_8TeV_ChiC_FeedDown(TGraph *InGraph, Int_t Par);
TGraph *Grf_ATLAS_8TeV_Psi2S_FeedDown(TGraph *InGraph);

TGraphAsymmErrors *Data_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt();



//====================================================================================================//
//================================= LHCb 7 TeV =======================================================//
//==================================================================================================//
//================== LHCb open the calculated root file ===========================================//

TFile *file_LHCb_RootS7TeV_JPsiCrossSection =  new TFile("rootFiles/LHCb_RootS7TeV/JPsiCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_LHCb_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_LHCb_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_LHCb_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_LHCb_RootS7TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//


//================================== root Files for FeedDown calculations =================================//
//================== Psi(2S): open the calculated root file ===========================================//
TFile *file_LHCb_RootS7TeV_Psi2SCrossSection =  new TFile("rootFiles/LHCb_RootS7TeV/Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grLHCb_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grLHCb_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grLHCb_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grLHCb_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grLHCb_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//====================================== Correcting ChiC feed down ===================================================//
//================== Chic0 open the calculated root file ===========================================//
TFile *file_LHCb_RootS7TeV_Chic0CrossSection =  new TFile("rootFiles/LHCb_RootS7TeV/Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_LHCb_RootS7TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grLHCb_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic1 open the calculated root file ===========================================//
TFile *file_LHCb_RootS7TeV_Chic1CrossSection =  new TFile("rootFiles/LHCb_RootS7TeV/Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_LHCb_RootS7TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grLHCb_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic2 open the calculated root file ===========================================//
TFile *file_LHCb_RootS7TeV_Chic2CrossSection =  new TFile("rootFiles/LHCb_RootS7TeV/Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_LHCb_RootS7TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grLHCb_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS7TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

Double_t LHCb_RootS7TeV_FitLDME(Double_t *x, Double_t *par);
Double_t LHCb_RootS7TeV_Psi2S_FeedDown(Double_t Pt);
Double_t LHCb_RootS7TeV_Chic0_FeedDown(Double_t Pt);
Double_t LHCb_RootS7TeV_Chic1_FeedDown(Double_t Pt);
Double_t LHCb_RootS7TeV_Chic2_FeedDown(Double_t Pt);

TGraph *Grf_LHCb_RootS7TeV_Psi2S_FeedDown(TGraph *InGraph);
TGraph *Grf_LHCb_RootS7TeV_ChiC_FeedDown(TGraph *InGraph, Int_t Par);

TGraphAsymmErrors *Data_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt();

//====================================================================================================//
//================================= LHCb 13 TeV =======================================================//
//==================================================================================================//
//================== LHCb open the calculated root file ===========================================//

TFile *file_LHCb_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/LHCb_RootS13TeV/JPsiCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_LHCb_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_LHCb_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_LHCb_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_LHCb_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_LHCb_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//======== Data Graphs =============================//


//================================== root Files for FeedDown calculations =================================//
//================== Psi(2S): open the calculated root file ===========================================//
TFile *file_LHCb_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/LHCb_RootS13TeV/Psi2SCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_LHCb_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grLHCb_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_LHCb_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grLHCb_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grLHCb_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_LHCb_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grLHCb_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_LHCb_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grLHCb_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_LHCb_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");
//====================================== Correcting ChiC feed down ===================================================//
//================== Chic0 open the calculated root file ===========================================//
TFile *file_LHCb_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/LHCb_RootS13TeV/Chic0_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_LHCb_RootS13TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grLHCb_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS13TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic1 open the calculated root file ===========================================//
TFile *file_LHCb_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/LHCb_RootS13TeV/Chic1_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_LHCb_RootS13TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grLHCb_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS13TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//================== Chic2 open the calculated root file ===========================================//
TFile *file_LHCb_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/LHCb_RootS13TeV/Chic2_1PCrossSection.root","R");
//================ Get All the graphs ===============================//
TGraph *grLHCb_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_LHCb_RootS13TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grLHCb_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_RootS13TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");

Double_t LHCb_RootS13TeV_FitLDME(Double_t *x, Double_t *par);
Double_t LHCb_RootS13TeV_Psi2S_FeedDown(Double_t Pt);
Double_t LHCb_RootS13TeV_Chic0_FeedDown(Double_t Pt);
Double_t LHCb_RootS13TeV_Chic1_FeedDown(Double_t Pt);
Double_t LHCb_RootS13TeV_Chic2_FeedDown(Double_t Pt);

TGraph *Grf_LHCb_RootS13TeV_Psi2S_FeedDown(TGraph *InGraph);
TGraph *Grf_LHCb_RootS13TeV_ChiC_FeedDown(TGraph *InGraph, Int_t Par);

TGraphAsymmErrors *Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt();



//================ Global Fittings ================================//
TGraphAsymmErrors *gr0;
TGraphAsymmErrors *gr1;
TGraphAsymmErrors *gr2;
TGraphAsymmErrors *gr3;
TGraphAsymmErrors *gr4;

TGraphAsymmErrors *gr5;
TGraphAsymmErrors *gr6;


TGraphAsymmErrors *gr7;

Double_t fcn0(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn1(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn2(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn3(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn4(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);

Double_t fcn5(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);
Double_t fcn6(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);

Double_t fcn7(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag);

void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag);




Double_t Scale_Pt(Double_t JPsiPt);
Double_t Scale_Chi_Pt(Double_t JPsiPt, Int_t Par);


TGraph *Scale_QCDSigma(TGraph *InGraph, Double_t LDME);


TGraph *Add_QCDSigma(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3,TGraph *InGraph4);
TGraph *Add_FeedDown_QCDSigma(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3, TF1 *InFunc);
TGraphAsymmErrors *CutGraph(TGraph *InGraph, Double_t XMin);
TGraph *Add_ChiC_FeedDown(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3);

Double_t CalcChi2(TGraphAsymmErrors *InGrf, TF1 *InFunc);


void JPsiLDME()
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
  //============================== Test New Data Graphs ================================//
  cout<<" getting CDF 1.8 TeV Data y [-0.6 -- 0.6]: "<<endl;
  TGraphAsymmErrors *grfData_CDF_180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt=new TGraphAsymmErrors();
  grfData_CDF_180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt=Data_CDF_180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt();

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Draw("zAP");


  cout<<" getting LHCb 7 TeV Data Graph [2.0 - 3.5]: "<<endl;

  TGraphAsymmErrors *grfData_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt =new TGraphAsymmErrors();
  grfData_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt=Data_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt();

 

  TGraphAsymmErrors *grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt =new TGraphAsymmErrors();
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt=Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt();

 new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt->Draw("zAP");
  grfData_CDF_180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Draw("zPsame");
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt->Draw("zPsame");
 //============================== Test New Data Graphs ================================//
  //  return;
  */


  //============================ Open a output text file ====================================//
  char OutTextFile[100];
  sprintf(OutTextFile,"LDME_JPsi.txt");
  ofstream dataFile(Form(OutTextFile),ios::app);

  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING CMS DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  cout<<" getting Data Graph 0009: "<<endl;
  TGraphAsymmErrors *grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt=new TGraphAsymmErrors();
  grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt= Data_CMS_New_D2NDPtDy_PrompJPsi_Y0009_Pt();
  
  TF1 *CMS_0009_FitFunctionLDME = new TF1("CMS_0009_FitFunctionLDME", CMS_0009_FitLDME, 5.0, 120, 3);
  CMS_0009_FitFunctionLDME->SetLineColor(2);
  CMS_0009_FitFunctionLDME->FixParameter(0,1);                         
  grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt->Fit("CMS_0009_FitFunctionLDME","Q0","MER", 6, 120);
  
  Double_t CMS_0009_Chi2 = CMS_0009_FitFunctionLDME->GetChisquare();
  Double_t CMS_0009_NDF = CMS_0009_FitFunctionLDME->GetNDF();
  Double_t CMS_0009_Prob = CMS_0009_FitFunctionLDME->GetProb();
  
  Double_t CMS_0009_LDME_3S1_1 = CMS_0009_FitFunctionLDME->GetParameter(0);
  Double_t CMS_0009_LDME_1S0_8 = CMS_0009_FitFunctionLDME->GetParameter(1);
  Double_t CMS_0009_LDME_3S1_8 = CMS_0009_FitFunctionLDME->GetParameter(2);
  
  Double_t CMS_0009_LDME_3P0_8 = CMS_0009_LDME_1S0_8*mC*mC;
  Double_t CMS_0009_LDME_3P1_8 = 3.0*CMS_0009_LDME_3P0_8;
  Double_t CMS_0009_LDME_3P2_8 = 5.0*CMS_0009_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<CMS_0009_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<CMS_0009_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<CMS_0009_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<CMS_0009_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<CMS_0009_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<CMS_0009_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<CMS_0009_Chi2<<"/"<<CMS_0009_NDF<<" Prob: "<<CMS_0009_Prob<<endl<<endl;
  /*
  dataFile<<"Fitting CMS_0009_ Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<CMS_0009_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<CMS_0009_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<CMS_0009_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<CMS_0009_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<CMS_0009_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<CMS_0009_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<CMS_0009_Chi2<<"/"<<CMS_0009_NDF<<" Prob: "<<CMS_0009_Prob<<endl<<endl;
  */


  TGraph *Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, CMS_0009_LDME_3S1_1);
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, CMS_0009_LDME_1S0_8);
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, CMS_0009_LDME_3S1_8);
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, CMS_0009_LDME_3P0_8);
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, CMS_0009_LDME_3P1_8);
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, CMS_0009_LDME_3P2_8);
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);


  TLegend *lgd_CMS_0009_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  
  lgd_CMS_0009_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_CMS_0009_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_CMS_0009_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_CMS_0009_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_CMS_0009_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_CMS_0009_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_CMS_0009_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_CMS_0009_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_CMS_0009_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_CMS_0009_DSigmaDPtDY_Pt->AddEntry(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt->Draw("zAP");  
  grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt->Draw("zAP");
  grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt->GetYaxis()->SetTitleOffset(1.6);
  grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  gPad->Update();
  CMS_0009_FitFunctionLDME->Draw("same");
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_CMS_0009_DSigmaDPtDY_Pt->Draw("same");
  
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt_All.pdf");
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt_All.png");



  TGraph *Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_CMS_0009_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_CMS_0009_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_CMS_0009_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_CMS_0009_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_CMS_0009_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_CMS_0009_DSigmaDPtDY_Pt1->AddEntry(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_CMS_0009_DSigmaDPtDY_Pt1->AddEntry(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_CMS_0009_DSigmaDPtDY_Pt1->AddEntry(Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt->Draw("zAP");
  grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  CMS_0009_FitFunctionLDME->Draw("same");
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_CMS_0009_DSigmaDPtDY_Pt1->Draw("same");
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.pdf");
  gPad->SaveAs("Plots/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.png");


  

  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING CMS DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  cout<<" getting Data Graph Latest: "<<endl;
  TGraphAsymmErrors *grfData_CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt=new TGraphAsymmErrors();
  grfData_CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt=Data_CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt();

  

  TMultiGraph *mg = new TMultiGraph();
  mg->Add(grfData_CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt);
  //mg->Add(grfData_CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt);
  mg->SetTitle("title;p_{T}[GeV/c]; #frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");

  TF1 *CMSFitFunctionLDME = new TF1("CMSFitFunctionLDME", CMS_FitLDME, 5.0, 120, 3);
  CMSFitFunctionLDME->SetLineColor(2);
  CMSFitFunctionLDME->FixParameter(0,1);                         
  mg->Fit("CMSFitFunctionLDME","Q0","MER", 6, 120);
  
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
  /*
  dataFile<<"Fitting CMS Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<CMS_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<CMS_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<CMS_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<CMS_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<CMS_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<CMS_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<CMS_Chi2<<"/"<<CMS_NDF<<" Prob: "<<CMS_Prob<<endl<<endl;
  */


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
  mg->GetYaxis()->SetTitleOffset(1.6);
  mg->GetYaxis()->SetRangeUser(0.0000001,100.0);

  gPad->Update();
  CMSFitFunctionLDME->Draw("same");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_Pt->Draw("same");
  
  gPad->SaveAs("Plots/CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt_All.pdf");
  gPad->SaveAs("Plots/CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt_All.png");


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
  mg->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  CMSFitFunctionLDME->Draw("same");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_DSigmaDPtDY_Pt1->Draw("same");

  gPad->SaveAs("Plots/CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt.pdf");
  gPad->SaveAs("Plots/CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt.png");

  return;

  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING CDF DATA 196 TeV FOR LDME ======================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  cout<<" getting CDF Data Graph "<<endl;
  //TGraphAsymmErrors *grfData_CDF_D2NDPtDy_PromptJPsi_Y0006_Pt=new TGraphAsymmErrors();
  //grfData_CDF_D2NDPtDy_PromptJPsi_Y0006_Pt=Data_CDF_D2NDPtDy_PromptJPsi_Y0006_Pt();
  

  TGraphAsymmErrors *grfData_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt=new TGraphAsymmErrors();
  grfData_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt=Data_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt();






  TF1 *CDFFitFunctionLDME = new TF1("CDFFitFunctionLDME", CDF_FitLDME, 5.0, 30, 3);
  CDFFitFunctionLDME->SetLineColor(2);
  CDFFitFunctionLDME->FixParameter(0,1);                         
  grfData_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Fit("CDFFitFunctionLDME","Q0","MER", 6, 20);
  
  Double_t CDF_Chi2 = CDFFitFunctionLDME->GetChisquare();
  Double_t CDF_NDF = CDFFitFunctionLDME->GetNDF();
  Double_t CDF_Prob = CDFFitFunctionLDME->GetProb();
  
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
  cout<<"Chi2/NDF : "<<CDF_Chi2<<"/"<<CDF_NDF<<" Prob: "<<CDF_Prob<<endl<<endl;
  /*
  dataFile<<"Fitting CDF Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<CDF_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<CDF_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<CDF_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<CDF_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<CDF_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<CDF_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<CDF_Chi2<<"/"<<CDF_NDF<<" Prob: "<<CDF_Prob<<endl<<endl;
  */

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

  TLegend *lgd_CDF_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  lgd_CDF_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_CDF_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_CDF_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_CDF_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_CDF_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_CDF_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_CDF_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_CDF_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_CDF_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_CDF_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Draw("zAP");
  grfData_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  CDFFitFunctionLDME->Draw("same");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  grfData_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Draw("zPsame");
  lgd_CDF_DSigmaDPtDY_Pt->Draw("same");

  gPad->SaveAs("Plots/Data_CDF_D2NDPtDy_PromptJPsi_Y0006_Pt_All.pdf");
  gPad->SaveAs("Plots/Data_CDF_D2NDPtDy_PromptJPsi_Y0006_Pt_All.png");



  TGraph *Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_CDF_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_CDF_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_CDF_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_CDF_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_CDF_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_CDF_DSigmaDPtDY_Pt1->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_CDF_DSigmaDPtDY_Pt1->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_CDF_DSigmaDPtDY_Pt1->AddEntry(Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Draw("zAP");
  grfData_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  CDFFitFunctionLDME->Draw("same");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  grfData_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Draw("zPsame");
  lgd_CDF_DSigmaDPtDY_Pt1->Draw("same");
  gPad->SaveAs("Plots/Data_CDF_D2NDPtDy_PromptJPsi_Y0006_Pt.pdf");
  gPad->SaveAs("Plots/Data_CDF_D2NDPtDy_PromptJPsi_Y0006_Pt.png");


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING CDF 180 TeV DATA FOR LDME ======================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  TGraphAsymmErrors *grfData_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt=new TGraphAsymmErrors();
  grfData_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt=Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt();


  cout<<" getting CDF 180 TeV Data Graph "<<endl;
  
  TF1 *CDF_RootS180TeV_FitFunctionLDME = new TF1("CDF_RootS180TeV_FitFunctionLDME", CDF_RootS180TeV_FitLDME, 5.0, 30, 3);
  CDF_RootS180TeV_FitFunctionLDME->SetLineColor(2);
  CDF_RootS180TeV_FitFunctionLDME->FixParameter(0,1);                         
  grfData_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Fit("CDF_RootS180TeV_FitFunctionLDME","Q0","MER", 6, 20);

  
  Double_t CDF_RootS180TeV_Chi2 = CDF_RootS180TeV_FitFunctionLDME->GetChisquare();
  Double_t CDF_RootS180TeV_NDF = CDF_RootS180TeV_FitFunctionLDME->GetNDF();
  Double_t CDF_RootS180TeV_Prob = CDF_RootS180TeV_FitFunctionLDME->GetProb();
  
  Double_t CDF_RootS180TeV_LDME_3S1_1 = CDF_RootS180TeV_FitFunctionLDME->GetParameter(0);
  Double_t CDF_RootS180TeV_LDME_1S0_8 = CDF_RootS180TeV_FitFunctionLDME->GetParameter(1);
  Double_t CDF_RootS180TeV_LDME_3S1_8 = CDF_RootS180TeV_FitFunctionLDME->GetParameter(2);
  
  Double_t CDF_RootS180TeV_LDME_3P0_8 = CDF_RootS180TeV_LDME_1S0_8*mC*mC;
  Double_t CDF_RootS180TeV_LDME_3P1_8 = 3.0*CDF_RootS180TeV_LDME_3P0_8;
  Double_t CDF_RootS180TeV_LDME_3P2_8 = 5.0*CDF_RootS180TeV_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<CDF_RootS180TeV_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<CDF_RootS180TeV_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<CDF_RootS180TeV_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<CDF_RootS180TeV_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<CDF_RootS180TeV_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<CDF_RootS180TeV_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<CDF_RootS180TeV_Chi2<<"/"<<CDF_RootS180TeV_NDF<<" Prob: "<<CDF_RootS180TeV_Prob<<endl<<endl;
  /*
  dataFile<<"Fitting CDF Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<CDF_RootS180TeV_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<CDF_RootS180TeV_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<CDF_RootS180TeV_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<CDF_RootS180TeV_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<CDF_RootS180TeV_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<CDF_RootS180TeV_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<CDF_RootS180TeV_Chi2<<"/"<<CDF_RootS180TeV_NDF<<" Prob: "<<CDF_RootS180TeV_Prob<<endl<<endl;
  */

  TGraph *Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit, CDF_RootS180TeV_LDME_3S1_1);
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit, CDF_RootS180TeV_LDME_1S0_8);
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit, CDF_RootS180TeV_LDME_3S1_8);
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit, CDF_RootS180TeV_LDME_3P0_8);
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit, CDF_RootS180TeV_LDME_3P1_8);
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit, CDF_RootS180TeV_LDME_3P2_8);
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  TLegend *lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->AddEntry(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Draw("zAP");
  grfData_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  CDF_RootS180TeV_FitFunctionLDME->Draw("same");
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
 
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt->Draw("same");

  gPad->SaveAs("Plots/Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt_All.pdf");
  gPad->SaveAs("Plots/Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt_All.png");



  TGraph *Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->Draw("zAP");
  grfData_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  CDF_RootS180TeV_FitFunctionLDME->Draw("same");
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  
  lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->Draw("same");
  gPad->SaveAs("Plots/Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt.pdf");
  gPad->SaveAs("Plots/Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt.png");


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING ATLAS DATA FOR LDME ================================"<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  cout<<" getting ATLAS Data Graph "<<endl;
  TGraphAsymmErrors *grfData_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt=new TGraphAsymmErrors();
  grfData_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt=Data_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt();
  

  TF1 *ATLASFitFunctionLDME = new TF1("ATLASFitFunctionLDME", ATLAS_FitLDME, 5.0, 120, 3);
  ATLASFitFunctionLDME->SetLineColor(2);
  ATLASFitFunctionLDME->FixParameter(0,1);                         
  grfData_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt->Fit("ATLASFitFunctionLDME","Q0","MER", 6, 120);
  
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
  /*
  dataFile<<"Fitting ATLAS Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<ATLAS_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<ATLAS_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<ATLAS_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<ATLAS_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<ATLAS_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<ATLAS_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<ATLAS_Chi2<<"/"<<ATLAS_NDF<<" Prob: "<<ATLAS_Prob<<endl<<endl;
  */


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

  TLegend *lgd_ATLAS_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  lgd_ATLAS_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_ATLAS_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_ATLAS_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_ATLAS_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_ATLAS_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLAS_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_ATLAS_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_ATLAS_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_ATLAS_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_ATLAS_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt->Draw("zAP");
  gPad->Update();
  ATLASFitFunctionLDME->Draw("same");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_ATLAS_DSigmaDPtDY_Pt->Draw("same");

  gPad->SaveAs("Plots/Data_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt_All.pdf");
  gPad->SaveAs("Plots/Data_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt_All.png");
 


  TGraph *Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_ATLAS_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_ATLAS_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_ATLAS_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_ATLAS_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_ATLAS_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_ATLAS_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLAS_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_ATLAS_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt->Draw("zAP");
  ATLASFitFunctionLDME->Draw("same");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_ATLAS_DSigmaDPtDY_Pt1->Draw("same");
  
  gPad->SaveAs("Plots/Data_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt.pdf");
  gPad->SaveAs("Plots/Data_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt.png");


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING ATLAS 8 TeV DATA FOR LDME ============================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  cout<<" getting ATLAS 8 TeV Data Graph "<<endl;
  TGraphAsymmErrors *grfData_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt=new TGraphAsymmErrors();
  grfData_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt=Data_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt();
  

  TF1 *ATLAS_8TeVFitFunctionLDME = new TF1("ATLAS_8TeVFitFunctionLDME", ATLAS_8TeV_FitLDME, 5.0, 120, 3);
  ATLAS_8TeVFitFunctionLDME->SetLineColor(2);
  ATLAS_8TeVFitFunctionLDME->FixParameter(0,1);                         
  grfData_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt->Fit("ATLAS_8TeVFitFunctionLDME","Q0","MER", 6, 120);
  
  Double_t ATLAS_8TeV_Chi2 = ATLAS_8TeVFitFunctionLDME->GetChisquare();
  Double_t ATLAS_8TeV_NDF = ATLAS_8TeVFitFunctionLDME->GetNDF();
  Double_t ATLAS_8TeV_Prob = ATLAS_8TeVFitFunctionLDME->GetProb();
  
  Double_t ATLAS_8TeV_LDME_3S1_1 = ATLAS_8TeVFitFunctionLDME->GetParameter(0);
  Double_t ATLAS_8TeV_LDME_1S0_8 = ATLAS_8TeVFitFunctionLDME->GetParameter(1);
  Double_t ATLAS_8TeV_LDME_3S1_8 = ATLAS_8TeVFitFunctionLDME->GetParameter(2);
  
  Double_t ATLAS_8TeV_LDME_3P0_8 = ATLAS_8TeV_LDME_1S0_8*mC*mC;
  Double_t ATLAS_8TeV_LDME_3P1_8 = 3.0*ATLAS_8TeV_LDME_3P0_8;
  Double_t ATLAS_8TeV_LDME_3P2_8 = 5.0*ATLAS_8TeV_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<ATLAS_8TeV_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<ATLAS_8TeV_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<ATLAS_8TeV_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<ATLAS_8TeV_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<ATLAS_8TeV_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<ATLAS_8TeV_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<ATLAS_8TeV_Chi2<<"/"<<ATLAS_8TeV_NDF<<" Prob: "<<ATLAS_8TeV_Prob<<endl<<endl;
  /*
  dataFile<<"Fitting ATLAS_8TeV Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<ATLAS_8TeV_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<ATLAS_8TeV_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<ATLAS_8TeV_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<ATLAS_8TeV_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<ATLAS_8TeV_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<ATLAS_8TeV_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<ATLAS_8TeV_Chi2<<"/"<<ATLAS_8TeV_NDF<<" Prob: "<<ATLAS_8TeV_Prob<<endl<<endl;
  */


  TGraph *Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit, ATLAS_8TeV_LDME_3S1_1);
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit, ATLAS_8TeV_LDME_1S0_8);
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit, ATLAS_8TeV_LDME_3S1_8);
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit, ATLAS_8TeV_LDME_3P0_8);
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit, ATLAS_8TeV_LDME_3P1_8);
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit, ATLAS_8TeV_LDME_3P2_8);
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  TLegend *lgd_ATLAS_8TeV_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->AddEntry(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt->Draw("zAP");
  gPad->Update();
  ATLAS_8TeVFitFunctionLDME->Draw("same");
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt->Draw("same");

 gPad->SaveAs("Plots/Data_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt_All.pdf");
 gPad->SaveAs("Plots/Data_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt_All.png");



  TGraph *Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt->Draw("zAP");
  ATLAS_8TeVFitFunctionLDME->Draw("same");
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->Draw("same");
  
  gPad->SaveAs("Plots/Data_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.pdf");
  gPad->SaveAs("Plots/Data_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.png");





  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING LHCb 13 TeV DATA FOR LDME ============================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  TGraphAsymmErrors *grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt =new TGraphAsymmErrors();
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt=Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt();

 
  TF1 *LHCb_RootS13TeV_FitFunctionLDME = new TF1("LHCb_RootS13TeV_FitFunctionLDME", LHCb_RootS13TeV_FitLDME, 6.0, 120, 3);
  LHCb_RootS13TeV_FitFunctionLDME->SetLineColor(2);
  LHCb_RootS13TeV_FitFunctionLDME->FixParameter(0,1);                         
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt->Fit("LHCb_RootS13TeV_FitFunctionLDME","Q0","MER", 6, 120);
  
  Double_t LHCb_RootS13TeV_Chi2 = LHCb_RootS13TeV_FitFunctionLDME->GetChisquare();
  Double_t LHCb_RootS13TeV_NDF = LHCb_RootS13TeV_FitFunctionLDME->GetNDF();
  Double_t LHCb_RootS13TeV_Prob = LHCb_RootS13TeV_FitFunctionLDME->GetProb();
  
  Double_t LHCb_RootS13TeV_LDME_3S1_1 = LHCb_RootS13TeV_FitFunctionLDME->GetParameter(0);
  Double_t LHCb_RootS13TeV_LDME_1S0_8 = LHCb_RootS13TeV_FitFunctionLDME->GetParameter(1);
  Double_t LHCb_RootS13TeV_LDME_3S1_8 = LHCb_RootS13TeV_FitFunctionLDME->GetParameter(2);
  
  Double_t LHCb_RootS13TeV_LDME_3P0_8 = LHCb_RootS13TeV_LDME_1S0_8*mC*mC;
  Double_t LHCb_RootS13TeV_LDME_3P1_8 = 3.0*LHCb_RootS13TeV_LDME_3P0_8;
  Double_t LHCb_RootS13TeV_LDME_3P2_8 = 5.0*LHCb_RootS13TeV_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<LHCb_RootS13TeV_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<LHCb_RootS13TeV_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<LHCb_RootS13TeV_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<LHCb_RootS13TeV_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<LHCb_RootS13TeV_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<LHCb_RootS13TeV_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<LHCb_RootS13TeV_Chi2<<"/"<<LHCb_RootS13TeV_NDF<<" Prob: "<<LHCb_RootS13TeV_Prob<<endl<<endl;
  /*
  dataFile<<"Fitting LHCb_RootS13TeV Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<LHCb_RootS13TeV_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<LHCb_RootS13TeV_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<LHCb_RootS13TeV_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<LHCb_RootS13TeV_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<LHCb_RootS13TeV_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<LHCb_RootS13TeV_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<LHCb_RootS13TeV_Chi2<<"/"<<LHCb_RootS13TeV_NDF<<" Prob: "<<LHCb_RootS13TeV_Prob<<endl<<endl;
  */


  TGraph *Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit, LHCb_RootS13TeV_LDME_3S1_1);
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit, LHCb_RootS13TeV_LDME_1S0_8);
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit, LHCb_RootS13TeV_LDME_3S1_8);
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit, LHCb_RootS13TeV_LDME_3P0_8);
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit, LHCb_RootS13TeV_LDME_3P1_8);
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit, LHCb_RootS13TeV_LDME_3P2_8);
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  TLegend *lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt->Draw("zAP");
  gPad->Update();
  LHCb_RootS13TeV_FitFunctionLDME->Draw("same");
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt->Draw("same");

 gPad->SaveAs("Plots/Data_LHCb_RootS13TeV_D2NDPtDy_PromptJPsi_Y0025_Pt_All.pdf");
 gPad->SaveAs("Plots/Data_LHCb_RootS13TeV_D2NDPtDy_PromptJPsi_Y0025_Pt_All.png");



  TGraph *Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt->Draw("zAP");
  LHCb_RootS13TeV_FitFunctionLDME->Draw("same");
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->Draw("same");
  
  gPad->SaveAs("Plots/Data_LHCb_RootS13TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.pdf");
  gPad->SaveAs("Plots/Data_LHCb_RootS13TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.png");


  //==============================================================================================================================//
  //==============================================================================================================================//
  //==============================================================================================================================//
  //==============================================================================================================================//

  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== FITTING LHCb 13 TeV DATA FOR LDME ============================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  TGraphAsymmErrors *grfData_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt =new TGraphAsymmErrors();
  grfData_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt=Data_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt();

 
  TF1 *LHCb_RootS7TeV_FitFunctionLDME = new TF1("LHCb_RootS7TeV_FitFunctionLDME", LHCb_RootS7TeV_FitLDME, 6.0, 120, 3);
  LHCb_RootS7TeV_FitFunctionLDME->SetLineColor(2);
  LHCb_RootS7TeV_FitFunctionLDME->FixParameter(0,1);                         
  grfData_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt->Fit("LHCb_RootS7TeV_FitFunctionLDME","Q0","MER", 6, 120);
  
  Double_t LHCb_RootS7TeV_Chi2 = LHCb_RootS7TeV_FitFunctionLDME->GetChisquare();
  Double_t LHCb_RootS7TeV_NDF = LHCb_RootS7TeV_FitFunctionLDME->GetNDF();
  Double_t LHCb_RootS7TeV_Prob = LHCb_RootS7TeV_FitFunctionLDME->GetProb();
  
  Double_t LHCb_RootS7TeV_LDME_3S1_1 = LHCb_RootS7TeV_FitFunctionLDME->GetParameter(0);
  Double_t LHCb_RootS7TeV_LDME_1S0_8 = LHCb_RootS7TeV_FitFunctionLDME->GetParameter(1);
  Double_t LHCb_RootS7TeV_LDME_3S1_8 = LHCb_RootS7TeV_FitFunctionLDME->GetParameter(2);
  
  Double_t LHCb_RootS7TeV_LDME_3P0_8 = LHCb_RootS7TeV_LDME_1S0_8*mC*mC;
  Double_t LHCb_RootS7TeV_LDME_3P1_8 = 3.0*LHCb_RootS7TeV_LDME_3P0_8;
  Double_t LHCb_RootS7TeV_LDME_3P2_8 = 5.0*LHCb_RootS7TeV_LDME_3P0_8;

  cout<<"LDME : 3S1_1 "<<LHCb_RootS7TeV_LDME_3S1_1<<endl;
  cout<<"LDME : 1S0_8 "<<LHCb_RootS7TeV_LDME_1S0_8<<endl;
  cout<<"LDME : 3S1_8 "<<LHCb_RootS7TeV_LDME_3S1_8<<endl;
  cout<<"LDME : 3P0_8 "<<LHCb_RootS7TeV_LDME_3P0_8<<endl;
  cout<<"LDME : 3P1_8 "<<LHCb_RootS7TeV_LDME_3P1_8<<endl;
  cout<<"LDME : 3P2_8 "<<LHCb_RootS7TeV_LDME_3P2_8<<endl<<endl;
  cout<<"Chi2/NDF : "<<LHCb_RootS7TeV_Chi2<<"/"<<LHCb_RootS7TeV_NDF<<" Prob: "<<LHCb_RootS7TeV_Prob<<endl<<endl;
  /*
  dataFile<<"Fitting LHCb_RootS7TeV Data"<<endl;
  dataFile<<"LDME : 3S1_1 "<<LHCb_RootS7TeV_LDME_3S1_1<<endl;
  dataFile<<"LDME : 1S0_8 "<<LHCb_RootS7TeV_LDME_1S0_8<<endl;
  dataFile<<"LDME : 3S1_8 "<<LHCb_RootS7TeV_LDME_3S1_8<<endl;
  dataFile<<"LDME : 3P0_8 "<<LHCb_RootS7TeV_LDME_3P0_8<<endl;
  dataFile<<"LDME : 3P1_8 "<<LHCb_RootS7TeV_LDME_3P1_8<<endl;
  dataFile<<"LDME : 3P2_8 "<<LHCb_RootS7TeV_LDME_3P2_8<<endl<<endl;
  dataFile<<"Chi2/NDF : "<<LHCb_RootS7TeV_Chi2<<"/"<<LHCb_RootS7TeV_NDF<<" Prob: "<<LHCb_RootS7TeV_Prob<<endl<<endl;
  */


  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, LHCb_RootS7TeV_LDME_3S1_1);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, LHCb_RootS7TeV_LDME_1S0_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, LHCb_RootS7TeV_LDME_3S1_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, LHCb_RootS7TeV_LDME_3P0_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, LHCb_RootS7TeV_LDME_3P1_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, LHCb_RootS7TeV_LDME_3P2_8);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  TLegend *lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt = new TLegend(0.50,0.50,0.88,0.94);
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->SetTextSize(0.03);
  
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}","L");
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,"^{3}P_{0}^{[8]}","L");
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,"^{3}P_{1}^{[8]}","L");
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit,"^{3}P_{2}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt->Draw("zAP");
  gPad->Update();
  LHCb_RootS7TeV_FitFunctionLDME->Draw("same");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->Draw("Lsame");
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt->Draw("same");

 gPad->SaveAs("Plots/Data_LHCb_RootS7TeV_D2NDPtDy_PromptJPsi_Y0025_Pt_All.pdf");
 gPad->SaveAs("Plots/Data_LHCb_RootS7TeV_D2NDPtDy_PromptJPsi_Y0025_Pt_All.png");



  TGraph *Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
  
  TLegend *lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1 = new TLegend(0.50,0.72,0.86,0.91);
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->SetBorderSize(0);
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->SetFillStyle(0);
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->SetFillColor(0);
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->SetTextSize(0.03);

  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->AddEntry(Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt->Draw("zAP");
  LHCb_RootS7TeV_FitFunctionLDME->Draw("same");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->Draw("same");
  
  gPad->SaveAs("Plots/Data_LHCb_RootS7TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.pdf");
  gPad->SaveAs("Plots/Data_LHCb_RootS7TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.png");


  //==============================================================================================================================//
  //==============================================================================================================================//
  //==============================================================================================================================//
  //==============================================================================================================================//
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== COMBINED FITTING CMS, ATLAS, LHCb, CDF DATA FOR LDME ====="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

  dataFile<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  dataFile<<" ===================== COMBINED FITTING CMS, ATLAS, LHCb, CDF DATA FOR LDME ====="<<endl;
  dataFile<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  gr0=new TGraphAsymmErrors();
  gr0=Data_CMS_New_D2NDPtDy_PrompJPsi_Y0009_Pt();
  gr0->SetMarkerColor(1);

  gr1=new TGraphAsymmErrors();
  gr1=Data_CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt();
  gr1->SetMarkerColor(1);

  gr2=new TGraphAsymmErrors();
  gr2=Data_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt();
  gr2->SetMarkerColor(1);

  gr3=new TGraphAsymmErrors();
  gr3=Data_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt();
  gr3->SetMarkerColor(1);

  
  gr4=new TGraphAsymmErrors(); 
  gr4=CutGraph(Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt(), 6.0);

  TGraph *gr4_t=new TGraphAsymmErrors();
  gr4_t=Data_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt();
  
  gr5=new TGraphAsymmErrors(); 
  gr5=CutGraph(Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt(),6.0);
  gr5->SetMarkerColor(1);

  TGraph *gr5_t=new TGraphAsymmErrors();
  gr5_t = Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt();


  gr6=new TGraphAsymmErrors(); 
  gr6=CutGraph(Data_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt(),6.0);

  TGraph *gr6_t=new TGraphAsymmErrors();
  gr6_t=Data_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt();

  gr7=new TGraphAsymmErrors(); 
  gr7=CutGraph(Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt(),6.0);

  TGraph *gr7_t=new TGraphAsymmErrors();
  gr7_t=Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt();

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

  static Double_t vstart[] = {1.0,0.0180,0.0013};
  //static Double_t vstart[] = {2.0,0.0180,0.0013};
  //static Double_t vstart[] = {3.0,0.0180,0.0013};
  //static Double_t vstart[] = {0.5,0.0180,0.0013};
  static Double_t step[]   = {0.0001,0.00001 , 0.00001};
  
  gMinuit->mnparm(0, "3S1_1", vstart[0], step[0], 0, 0, ierflg);
  gMinuit->mnparm(1, "1S0_8", vstart[1], step[1], 0, 0, ierflg);
  gMinuit->mnparm(2, "3S1_8", vstart[2], step[2], 0, 0, ierflg);
  gMinuit->FixParameter(0);
  
  //Int_t DefineParameter( Int_t parNo, const char *name, Double_t initVal, Double_t initErr, Double_t lowerLimit, Double_t upperLimit )
  //gMinuit->DefineParameter(1,"1S0_8",0.0180,0.0,0.0,10.0);
  
  
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
  Double_t errl[npars]={0};   // The current estimate of the parameter uncertainty  
  Double_t xlolim; // The lower bound (or zero if no limits)
  Double_t xuplim; // The upper bound (or zero if no limits)
  Int_t iuint;     // The internal parameter number 
  
  Int_t i = 0;
  Double_t currentPar[npars] = {0};
  for (i=0; i< npars;i++) {
    gMinuit->mnpout(i, chnam, currentPar[i], errl[i], xlolim, xuplim, iuint);
  }
  
  TMultiGraph *gl_mg = new TMultiGraph();
  gl_mg->Add(gr0);
  gl_mg->Add(gr1);
  gl_mg->Add(gr2);
  gl_mg->Add(gr3);
  gl_mg->Add(gr4);
  gl_mg->Add(gr5);
  gl_mg->Add(gr6);
  gl_mg->Add(gr7);
  gl_mg->SetTitle("title;p_{T}[GeV/c]; #frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
      
  TF1 *fun_0=new TF1("fun_0",CMS_0009_FitLDME, 5.0, 120, 3); 	
  for(Int_t i=0;i<3;i++){fun_0->FixParameter(i,currentPar[i]);}
  fun_0->SetLineColor(2);
  fun_0->SetLineStyle(1);
  fun_0->SetLineWidth(4);

  TF1 *fun_1=new TF1("fun_1",CMS_FitLDME, 5.0, 120, 3); 
  for(Int_t i=0;i<3;i++){fun_1->FixParameter(i,currentPar[i]);}	
  fun_1->SetLineColor(2);
  fun_1->SetLineStyle(1);
  fun_1->SetLineWidth(4);
    
  TF1 *fun_2=new TF1("fun_2",ATLAS_FitLDME, 5.0, 100, 3);
  for(Int_t i=0;i<3;i++){fun_2->FixParameter(i,currentPar[i]);}	
  //fun_2->FixParameters(currentPar);
  fun_2->SetLineColor(2);
  fun_2->SetLineStyle(1);
  fun_2->SetLineWidth(4);
  
  
  TF1 *fun_3=new TF1("fun_3", ATLAS_8TeV_FitLDME, 5.0, 120, 3);
  for(Int_t i=0;i<3;i++){fun_3->FixParameter(i,currentPar[i]);}	
  //fun_3->FixParameters(currentPar);
  fun_3->SetLineColor(2);
  fun_3->SetLineStyle(1);
  fun_3->SetLineWidth(4);
  
  TF1 *fun_4=new TF1("fun_4", CDF_FitLDME, 5.0, 30, 3);
  for(Int_t i=0;i<3;i++){fun_4->FixParameter(i,currentPar[i]);}	
  //fun_4->FixParameters(currentPar);
  fun_4->SetLineColor(2);
  fun_4->SetLineStyle(1);
  fun_4->SetLineWidth(4);



  TF1 *fun_5=new TF1("fun_5", CDF_RootS180TeV_FitLDME, 5.0, 30, 3);
  for(Int_t i=0;i<3;i++){fun_5->FixParameter(i,currentPar[i]);}	
  //fun_4->FixParameters(currentPar);
  fun_5->SetLineColor(2);
  fun_5->SetLineStyle(1);
  fun_5->SetLineWidth(4);
 

  
  TF1 *fun_6=new TF1("fun_6", LHCb_RootS7TeV_FitLDME, 5.0, 30, 3);
  for(Int_t i=0;i<3;i++){fun_6->FixParameter(i,currentPar[i]);}	
  fun_6->SetLineColor(2);
  fun_6->SetLineStyle(1);
  fun_6->SetLineWidth(4);

  TF1 *fun_7=new TF1("fun_7", LHCb_RootS13TeV_FitLDME, 5.0, 30, 3);
  for(Int_t i=0;i<3;i++){fun_7->FixParameter(i,currentPar[i]);}	
  //fun_4->FixParameters(currentPar);
  fun_7->SetLineColor(2);
  fun_7->SetLineStyle(1);
  fun_7->SetLineWidth(4);


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gl_mg->Draw("zAP");
  gl_mg->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_0->Draw("Csame");
  fun_1->Draw("Csame");
  fun_2->Draw("Csame");
  fun_3->Draw("Csame");
  fun_4->Draw("Csame");
  fun_5->Draw("Csame");
  fun_6->Draw("Csame");
  fun_7->Draw("Csame");

  cout<<endl<<endl;
  cout<<" combined fitting perameters "<<endl;
  cout<<"LDME : 3S1_1 "<<currentPar[0]<<" \\pm "<<errl[0]<<endl;
  cout<<"LDME : 3S1_8 "<<currentPar[2]<<" \\pm "<<errl[2]<<endl;
  cout<<"LDME : M_{J//Psi} (1S0_8/3 + 3P0_8/mC^2) "<<currentPar[1]<<" \\pm "<<errl[1]<<endl;

  //cout<<"LDME : 3P0_1 "<<currentPar[1]*mC*mC<<"\\pm"<<errl[1]*mC*mC<<endl;
  //cout<<"LDME : 3P1_1 "<<3.0*currentPar[1]*mC*mC<<"\\pm"<<3.0*errl[1]*mC*mC<<endl;
  //cout<<"LDME : 3P1_2 "<<5.0*currentPar[1]*mC*mC<<"\\pm"<<5.0*errl[1]*mC*mC<<endl<<endl;
  
  
  dataFile<<endl<<endl;
  dataFile<<" combined fitting perameters "<<endl;
  dataFile<<"LDME : 3S1_1 "<<currentPar[0]<<"\\pm"<<errl[0]<<endl;
  dataFile<<"LDME : 3S1_8 "<<currentPar[2]<<"\\pm"<<errl[2]<<endl;
  dataFile<<"LDME : M_{J//Psi} (1S0_8/3 + 3P0_8/mC^2) "<<currentPar[1]<<" \\pm "<<errl[1]<<endl;
  
  //dataFile<<"LDME : 3P0_1 "<<currentPar[1]*mC*mC<<"\\pm"<<errl[1]*mC*mC<<endl;
  //dataFile<<"LDME : 3P1_1 "<<3.0*currentPar[1]*mC*mC<<"\\pm"<<3.0*errl[1]*mC*mC<<endl;
  //dataFile<<"LDME : 3P1_2 "<<5.0*currentPar[1]*mC*mC<<"\\pm"<<5.0*errl[1]*mC*mC<<endl<<endl;

  Double_t Comb_LDME_3S1_1 = currentPar[0];
  Double_t Comb_LDME_3S1_8 = currentPar[2];
  Double_t Comb_LDME_1S0_8 = currentPar[1];


  Double_t Comb_LDME_3P0_8 = currentPar[1]*mC*mC;
  Double_t Comb_LDME_3P1_8 = 3.0*currentPar[1]*mC*mC;
  Double_t Comb_LDME_3P2_8 = 5.0*currentPar[1]*mC*mC;
 
  //============================ Calculate Chi2 For Combined fitting =====================//
  
  gr0->Fit("fun_0","Q0","MER", 6, 70);   //CMS 0009

  /*
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr0->Draw("AP");
  fun_0->Draw("same");
  gPad->SaveAs("Plots/Combined/Data_CMS_New.pdf");
  gPad->SaveAs("Plots/Combined/Data_CMS_New.png");
  */
  
  TGraph *Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);
  
  TGraph *Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);

  Double_t Fac_3PJ = 3.0;

  TGraph *Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,  Fac_3PJ*Comb_LDME_1S0_8);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineStyle(9);


  TGraph *Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=Grf_CMS_0009_Psi2S_FeedDown(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit);

  TGraph *Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=Add_ChiC_FeedDown(Grf_CMS_0009_ChiC_FeedDown(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,0), 
  										       Grf_CMS_0009_ChiC_FeedDown(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,1), 
  										       Grf_CMS_0009_ChiC_FeedDown(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,2));
  
  //TGraph *Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=Grf_CMS_0009_ChiC_FeedDown(grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,2);
 
  TLegend *Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1 = new TLegend(0.27,0.88,0.91,0.94);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1->SetHeader("pp #surds=7 TeV, Prompt J/#psi, |y^{J/#psi}| #leq 0.9");


  TLegend *Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1 = new TLegend(0.57,0.43,0.90,0.88);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->AddEntry(gr0,"CMS Data","P");
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->AddEntry(fun_0,"Total","L");
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,"J/#psi from #psi(2S)","L");
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,"J/#psi from #chi_{c}","L");
 

  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,5.0);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,5.0);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=CutGraph(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,5.0);
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=CutGraph(Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,5.0);



  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);

  gr0->GetYaxis()->SetRangeUser(0.000001,100);
  gr0->SetMarkerStyle(24);
  gr0->SetMarkerSize(1.8);
  gr0->Draw("zAP");
  gr0->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_0->Draw("same");
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown->Draw("Lsame");
  Comb_Out_grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown->Draw("Lsame");
  tb->DrawLatex(0.23,0.18,"(a)"); 
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1->Draw("same");
  Comb_lgd_CMS_0009_DSigmaDPtDY_Pt1_1->Draw("same");

  gPad->SaveAs("Plots/Combined/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.pdf");
  gPad->SaveAs("Plots/Combined/CMS_New_D2NDPtDy_PromptJPsi_Y0009_Pt.png");




  //return;




  gr1->Fit("fun_1","Q0","MER", 6, 120); //CMS Latest
  /*
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr1->Draw("AP");
  fun_1->Draw("same");
  gPad->SaveAs("Plots/Combined/Data_CMS_Latest.pdf");
  gPad->SaveAs("Plots/Combined/Data_CMS_Latest.png");
  */



  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);
  

  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);
  


  
  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,  Fac_3PJ*Comb_LDME_1S0_8);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineStyle(9);
  
  /*
  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, Comb_LDME_3P0_8);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, Comb_LDME_3P1_8);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, Comb_LDME_3P2_8);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);
  */
  
  //TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
  //										    Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  //Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  
    
  //TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_FeedDown_Fit=Add_FeedDown_QCDSigma(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,
  //											  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,
  //											  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,fun_1);
    

  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=Grf_CMS_Psi2S_FeedDown(grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit);
  
  TGraph *Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=Add_ChiC_FeedDown(Grf_CMS_ChiC_FeedDown(grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,0), 
										  Grf_CMS_ChiC_FeedDown(grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,1), 
										  Grf_CMS_ChiC_FeedDown(grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,2));

  TLegend *Comb_lgd_CMS_DSigmaDPtDY_Pt1 = new TLegend(0.24,0.88,0.90,0.92);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1->SetHeader("pp #surds=7 TeV, Prompt J/#psi, |y^{J/#psi}| #leq 1.2");

  TLegend *Comb_lgd_CMS_DSigmaDPtDY_Pt1_1 = new TLegend(0.55,0.36,0.91,0.86);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->AddEntry(gr1,"CMS Data","P");
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->AddEntry(fun_1,"Total","L");
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,"J/#psi from #psi(2S)","L");
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,"J/#psi from #chi_{c}","L");
 
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,5.0);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,5.0);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=CutGraph(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,5.0);
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=CutGraph(Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,5.0);
 
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gr1->SetMarkerSize(1.8);
  gr1->GetYaxis()->SetRangeUser(0.000001,100);
  gPad->SetLeftMargin(0.18);
  gr1->Draw("zAP");
  gr1->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_1->Draw("same");
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  //Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_FeedDown_Fit->Draw("Lsame");
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown->Draw("Lsame");
  Comb_Out_grCMS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown->Draw("Lsame");
  Comb_lgd_CMS_DSigmaDPtDY_Pt1->Draw("same");
  Comb_lgd_CMS_DSigmaDPtDY_Pt1_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(b)"); 
  gPad->SaveAs("Plots/Combined/CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt.pdf");
  gPad->SaveAs("Plots/Combined/CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt.png");



  
  gr2->Fit("fun_2","Q0","MER", 6, 100); //ATLAS 7 TeV
  /*
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr2->Draw("AP");
  fun_2->Draw("same");
  gPad->SaveAs("Plots/Combined/Data_ATLAS.pdf");
  gPad->SaveAs("Plots/Combined/Data_ATLAS.png");
  */

  TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);
  
  TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);

  TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Comb_LDME_1S0_8);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineStyle(9);


  //TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, Comb_LDME_3P0_8);
  //Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  //TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, Comb_LDME_3P1_8);
  //Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  //TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, Comb_LDME_3P2_8);
  //Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  
  //TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
  //										 Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  //Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  //Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineStyle(9);
  
 




  TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=Grf_ATLAS_Psi2S_FeedDown(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit);
  
  TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=Add_ChiC_FeedDown(Grf_ATLAS_ChiC_FeedDown(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,0), 
										  Grf_ATLAS_ChiC_FeedDown(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,1), 
										  Grf_ATLAS_ChiC_FeedDown(grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,2));

  //TGraph *Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_FeedDown_Fit=Add_FeedDown_QCDSigma(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,
  //										       Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,
  //										       Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,fun_2);
  

  TLegend *Comb_lgd_ATLAS_DSigmaDPtDY_Pt1 = new TLegend(0.24,0.86,0.90,0.95);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->SetHeader("pp #surds=7 TeV, Prompt J/#psi, |y^{J/#psi}| #leq 0.25");
  

  TLegend *Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1 = new TLegend(0.52,0.46,0.88,0.87);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(gr2,"ATLAS Data","P");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(fun_2,"Total","L");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,"J/#psi from #psi(2S)","L");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,"J/#psi from #chi_{c}","L");

  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,5.0);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,5.0);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=CutGraph(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,5.0);
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=CutGraph(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,5.0);

  //Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_FeedDown_Fit=CutGraph(Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_FeedDown_Fit,5.0);




  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr2->SetMarkerSize(1.8);
  gr2->GetYaxis()->SetRangeUser(0.000001,100);
  gr2->Draw("zAP");
  gr2->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_2->Draw("same");
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown->Draw("Lsame");
  Comb_Out_grATLAS_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown->Draw("Lsame");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1->Draw("same");
  Comb_lgd_ATLAS_DSigmaDPtDY_Pt1_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(c)");
  gPad->SaveAs("Plots/Combined/ATLAS_7TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.pdf");
  gPad->SaveAs("Plots/Combined/ATLAS_7TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.png");
  
  
 

  gr3->Fit("fun_3","Q0","MER", 6, 120); //ATLAS 8 TeV
  /*
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr3->Draw("AP");
  fun_3->Draw("same");
  gPad->SaveAs("Plots/Combined/Data_ATLAS_8TeV.pdf");
  gPad->SaveAs("Plots/Combined/Data_ATLAS_8TeV.png");
  */
  
  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);
  
  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);

  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Comb_LDME_1S0_8);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineStyle(9);  
  
  /*
  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit, Comb_LDME_3P0_8);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit, Comb_LDME_3P1_8);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit, Comb_LDME_3P2_8);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  
  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
										 Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);

  
  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_FeedDown_Fit=Add_FeedDown_QCDSigma(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit,
										       Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,
										       Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit,fun_3);
  */    

  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=Grf_ATLAS_8TeV_Psi2S_FeedDown(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit);
  
  TGraph *Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=Add_ChiC_FeedDown(Grf_ATLAS_8TeV_ChiC_FeedDown(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit,0), 
										  Grf_ATLAS_8TeV_ChiC_FeedDown(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit,1), 
										  Grf_ATLAS_8TeV_ChiC_FeedDown(grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit,2));

  TLegend *Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1 = new TLegend(0.24,0.86,0.90,0.95);
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->SetHeader("pp #surds=8 TeV, Prompt J/#psi, |y^{J/#psi}| #leq 0.25");



  TLegend *Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1 = new TLegend(0.52,0.46,0.88,0.87);
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);

  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->AddEntry(gr3,"ATLAS Data","P");
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->AddEntry(fun_3,"Total","L");
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,"J/#psi from #psi(2S)","L");
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,"J/#psi from #chi_{c}","L");

  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit,5.0);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit,5.0);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=CutGraph(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,5.0);
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=CutGraph(Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,5.0);


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr3->GetYaxis()->SetRangeUser(0.000001,100);
  gr3->SetMarkerSize(1.8);
  gr3->Draw("zAP");
  gr3->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_3->Draw("same");
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown->Draw("Lsame");
  Comb_Out_grATLAS_RootS8TeV_DSigmaDPtDY_Pt_ChiC_FeedDown->Draw("Lsame");
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1->Draw("same");
  Comb_lgd_ATLAS_8TeV_DSigmaDPtDY_Pt1_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(d)");
  gPad->SaveAs("Plots/Combined/ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.pdf");
  gPad->SaveAs("Plots/Combined/ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt.png");

  

  //========================================= gr4 ===============================================//
 
  gr4->Fit("fun_4","Q0","MER", 6, 30); //CDF
  /*
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr4->Draw("AP");
  fun_4->Draw("same");
  gr4_t->SetMarkerColor(1);
  gr4_t->Draw("zPsame");
  gPad->SaveAs("Plots/Combined/Data_CDF.pdf");
  gPad->SaveAs("Plots/Combined/Data_CDF.png");
  */
  
  TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);

  TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);


  TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Comb_LDME_1S0_8);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineStyle(9);

  /*
  TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit, Comb_LDME_3P0_8);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit, Comb_LDME_3P1_8);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit, Comb_LDME_3P2_8);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);
  
  TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
									    Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
									    Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
									    Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineStyle(9);
									    
									    
									    TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_FeedDown_Fit=Add_FeedDown_QCDSigma(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit,
											  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,
											  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit,fun_4);
    
  */


  TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=Grf_CDF_Psi2S_FeedDown(grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit);
  
  TGraph *Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=Add_ChiC_FeedDown(Grf_CDF_ChiC_FeedDown(grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,0), 
										    Grf_CDF_ChiC_FeedDown(grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,1), 
										    Grf_CDF_ChiC_FeedDown(grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,2));
  
  
  
  TLegend *Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1 = new TLegend(0.22,0.87,0.89,0.93);
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1->SetHeader("p#bar{p} #surds=1.96 TeV, Prompt J/#psi, |y^{J/#psi}| #leq 0.6");
  
  TLegend *Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1 = new TLegend(0.562,0.423,0.933,0.873);
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);
  
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->AddEntry(gr4_t,"CDF Data","P");
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->AddEntry(fun_4,"Total","L");
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,"J/#psi from #psi(2S)","L");
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,"J/#psi from #chi_{c}","L");
  
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit,5.0);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit,5.0);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=CutGraph(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,5.0);
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=CutGraph(Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,5.0);



  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  
  gr4_t->SetMarkerStyle(20);
  gr4_t->SetMarkerSize(1.8);
  gr4_t->SetMarkerColor(1);
  gr4_t->SetLineColor(1);
  gr4_t->Draw("zAP");
  gr4_t->GetYaxis()->SetRangeUser(0.001,1000);
  gr4_t->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_4->Draw("same");
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown->Draw("Lsame");
  Comb_Out_grCDF_RootS196TeV_DSigmaDPtDY_Pt_ChiC_FeedDown->Draw("Lsame");
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1->Draw("same"); 
  Comb_lgd_CDF_196TeV_DSigmaDPtDY_Pt1_1->Draw("same"); 
  tb->DrawLatex(0.23,0.18,"(b)");
  gPad->SaveAs("Plots/Combined/CDF_196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt.pdf");
  gPad->SaveAs("Plots/Combined/CDF_196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt.png");
  
 
  //==================================================================================================== gr5 ==========//


  gr5->Fit("fun_5","Q0","MER", 6, 30); //CDF 180
  
  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);

  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);
  
  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Comb_LDME_1S0_8);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineStyle(9);

  /*
  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit, Comb_LDME_3P0_8);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit, Comb_LDME_3P1_8);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit, Comb_LDME_3P2_8);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  
  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
										 Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineStyle(9);
  
  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_FeedDown_Fit=Add_FeedDown_QCDSigma(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit,
										       Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,
										       Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,fun_5);
  */  


  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=Grf_CDF_RootS180TeV_Psi2S_FeedDown(grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit);
  
  TGraph *Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=Add_ChiC_FeedDown(Grf_CDF_RootS180TeV_ChiC_FeedDown(grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit,0), 
										    Grf_CDF_RootS180TeV_ChiC_FeedDown(grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit,1), 
										    Grf_CDF_RootS180TeV_ChiC_FeedDown(grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit,2));




  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit,5.0);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit,5.0);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=CutGraph(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,5.0);
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=CutGraph(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,5.0);
  

  TLegend *Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1 = new TLegend(0.22,0.87,0.89,0.93);
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->SetHeader("p#bar{p} #surds=1.8 TeV, Prompt J/#psi, |y^{J/#psi}| #leq 0.6");


  TLegend *Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1 = new TLegend(0.554,0.416,0.924,0.866);
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);

  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->AddEntry(gr5_t,"CDF Data","P");
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->AddEntry(fun_5,"Total","L");
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,"J/#psi from #psi(2S)","L");
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,"J/#psi from #chi_{c}","L");


  /*
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr5->SetMarkerStyle(20);
  gr5->Draw("zAP");
  gr5->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_5->Draw("same");
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_FeedDown_Fit->Draw("Lsame");
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->Draw("same"); 
  */

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);

  gr5_t->SetMarkerColor(1);
  gr5_t->SetMarkerStyle(24);
  gr5_t->SetMarkerSize(1.8);
  gr5_t->GetXaxis()->SetRangeUser(4.0,22);
  gr5_t->GetYaxis()->SetRangeUser(0.001,1000);
  gr5_t->GetYaxis()->SetTitleOffset(1.6);

  gr5_t->Draw("zAP");
  fun_5->Draw("same");
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown->Draw("Lsame");
  Comb_Out_grCDF_RootS180TeV_DSigmaDPtDY_Pt_ChiC_FeedDown->Draw("Lsame");
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1->Draw("same"); 
  Comb_lgd_CDF_RootS180TeV_DSigmaDPtDY_Pt1_1->Draw("same"); 
  tb->DrawLatex(0.23,0.18,"(a)");
  gPad->Update();

  gPad->SaveAs("Plots/Combined/CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt.pdf");
  gPad->SaveAs("Plots/Combined/CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt.png");


 //=========================================================================================== gr6 ==========//


  gr6->Fit("fun_6","Q0","MER", 6, 30); //LHCb 7 TeV
  
  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);
  
  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);
  
  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Comb_LDME_1S0_8);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineStyle(9);

  /*
  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit, Comb_LDME_3P0_8);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit, Comb_LDME_3P1_8);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit, Comb_LDME_3P2_8);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  
  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
										Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineStyle(9);
  
  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_FeedDown_Fit=Add_FeedDown_QCDSigma(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,
											  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,
											  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,fun_6);
  */    




  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=Grf_LHCb_RootS7TeV_Psi2S_FeedDown(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit);
  
  TGraph *Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=Add_ChiC_FeedDown(Grf_LHCb_RootS7TeV_ChiC_FeedDown(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,0), 
										    Grf_LHCb_RootS7TeV_ChiC_FeedDown(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,1), 
										    Grf_LHCb_RootS7TeV_ChiC_FeedDown(grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,2));





  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,5.0);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,5.0);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=CutGraph(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,5.0);
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=CutGraph(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,5.0);



  TLegend *Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1 = new TLegend(0.20,0.88,0.91,0.92);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->SetHeader("pp #surds=7 TeV, Prompt J/#psi, 2.5 #leq y^{J/#psi} #leq 4.0");

  TLegend *Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1 = new TLegend(0.572,0.449,0.90,0.856);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->AddEntry(gr6_t,"LHCb Data","P");
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->AddEntry(fun_6,"Total","L");
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,"J/#psi from #psi(2S)","L");
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,"J/#psi from #chi_{c}","L");
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr6_t->SetMarkerSize(1.8);
  gr6_t->SetMarkerStyle(24);
  gr6_t->SetMarkerColor(1);
  gr6_t->GetYaxis()->SetRangeUser(0.01,1000);
  gr6_t->Draw("zAP");
  gr6_t->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_6->Draw("same");
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown->Draw("Lsame");
  Comb_Out_grLHCb_RootS7TeV_DSigmaDPtDY_Pt_ChiC_FeedDown->Draw("Lsame");
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1->Draw("same"); 
  Comb_lgd_LHCb_RootS7TeV_DSigmaDPtDY_Pt1_1->Draw("same"); 
  tb->DrawLatex(0.23,0.18,"(a)");
  gPad->SaveAs("Plots/Combined/LHCb_RootS7TeV_D2NDPtDy_PromptJPsi_Y2035_Pt.pdf");
  gPad->SaveAs("Plots/Combined/LHCb_RootS7TeV_D2NDPtDy_PromptJPsi_Y2035_Pt.png");




  //========================================================== gr7 ===============================================//

  gr7->Fit("fun_7","Q0","MER", 6, 30); //LHCb 13 TeV
  /*
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr7->Draw("AP");
  fun_7->Draw("same");
  gr7_t->Draw("ZPsame");
  gPad->SaveAs("Plots/Combined/Data_LHCb_RootS13TeV.pdf");
  gPad->SaveAs("Plots/Combined/Data_LHCb_RootS13TeV.png");
  */
  
  TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit, Comb_LDME_3S1_1);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineColor(1);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit->SetLineStyle(7);

  TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit, Comb_LDME_3S1_8);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineColor(6);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit->SetLineStyle(3);

  TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit, Comb_LDME_1S0_8);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineColor(4);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit->SetLineStyle(9);


  /*
  TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit, Comb_LDME_3P0_8);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit->SetLineColor(8);
  TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit, Comb_LDME_3P1_8);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit->SetLineColor(9);
  TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit=Scale_QCDSigma(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit, Comb_LDME_3P2_8);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit->SetLineColor(46);

  
    TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit=Add_QCDSigma(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit,Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P0_8_Fit,
										    Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P1_8_Fit,Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3P2_8_Fit);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineColor(4);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->SetLineStyle(9);
    
  TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_FeedDown_Fit=Add_FeedDown_QCDSigma(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit,
											  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit,
											  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit,fun_7);
    
  */


  TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=Grf_LHCb_RootS13TeV_Psi2S_FeedDown(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit);
  
  TGraph *Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=Add_ChiC_FeedDown(Grf_LHCb_RootS13TeV_ChiC_FeedDown(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit,0), 
										    Grf_LHCb_RootS13TeV_ChiC_FeedDown(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit,1), 
										    Grf_LHCb_RootS13TeV_ChiC_FeedDown(grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit,2));

  
  

  
  
  

  TLegend *Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1 = new TLegend(0.20,0.88,0.91,0.92);
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->SetBorderSize(0);
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->SetFillStyle(0);
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->SetFillColor(0);
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->SetTextSize(0.04);
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->SetHeader("pp #surds=13 TeV, Prompt J/#psi, 2.5 #leq y^{J/#psi} #leq 4.0");
  

  TLegend *Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1 = new TLegend(0.59,0.45,0.91,0.86);
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->SetBorderSize(0);
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->SetFillStyle(0);
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->SetFillColor(0);
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->SetTextSize(0.04);
  
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->AddEntry(gr7_t,"LHCb Data","P");
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->AddEntry(fun_7,"Total","L");
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit,"^{3}S_{1}^{[1]}","L");
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit,"^{1}S_{0}^{[8]}+^{3}P_{J}^{[8]}","L");
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit,"^{3}S_{1}^{[8]}","L");
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,"J/#psi from #psi(2S)","L");
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->AddEntry(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,"J/#psi from #chi_{c}","L");

 
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown=CutGraph(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,5.0);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_ChiC_FeedDown=CutGraph(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,5.0);
  /*
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  gr7->SetMarkerStyle(20);
  gr7->Draw("zAP");
  gr7->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_7->Draw("same");
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_3PJ_8_Fit->Draw("Lsame");
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_FeedDown_Fit->Draw("Lsame");
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->Draw("same"); 
  */

  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit=CutGraph(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit,5.0);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit=CutGraph(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit,5.0);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit,5.0);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown,5.0);
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit=CutGraph(Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_ChiC_FeedDown,5.0);


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);

  gr7_t->SetMarkerStyle(20);
  gr7_t->SetMarkerColor(1);
  gr7_t->SetMarkerSize(1.8);

  gr7_t->Draw("zAP");
  gr7_t->GetYaxis()->SetRangeUser(0.01,1000);
  gr7_t->GetYaxis()->SetTitleOffset(1.6);
  gPad->Update();
  fun_7->Draw("same");
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Draw("Lsame");
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Draw("Lsame");
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Draw("Lsame");
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_Psi2S_FeedDown->Draw("Lsame");
  Comb_Out_grLHCb_RootS13TeV_DSigmaDPtDY_Pt_ChiC_FeedDown->Draw("Lsame");
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1->Draw("same"); 
  Comb_lgd_LHCb_RootS13TeV_DSigmaDPtDY_Pt1_1->Draw("same"); 
  tb->DrawLatex(0.23,0.18,"(b)");
  gPad->SaveAs("Plots/Combined/LHCb_RootS13TeV_D2NDPtDy_PromptJPsi_Y2045_Pt.pdf");
  gPad->SaveAs("Plots/Combined/LHCb_RootS13TeV_D2NDPtDy_PromptJPsi_Y2045_Pt.png");



  //f = fcn0(npar,gin, par, iflag) + fcn1(npar,gin, par, iflag) + fcn2(npar,gin, par, iflag) + fcn3(npar,gin, par, iflag) + 
  //fcn4(npar,gin, par, iflag) + fcn5(npar,gin, par, iflag) + fcn6(npar,gin, par, iflag) + fcn7(npar,gin, par, iflag);

  cout<<"chi2/ndf "<<fun_0->GetChisquare()<<"/"<<fun_0->GetNDF()<<" Prob: "<<fun_0->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_1->GetChisquare()<<"/"<<fun_1->GetNDF()<<" Prob: "<<fun_1->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_2->GetChisquare()<<"/"<<fun_2->GetNDF()<<" Prob: "<<fun_2->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_3->GetChisquare()<<"/"<<fun_3->GetNDF()<<" Prob: "<<fun_3->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_4->GetChisquare()<<"/"<<fun_4->GetNDF()<<" Prob: "<<fun_4->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_5->GetChisquare()<<"/"<<fun_5->GetNDF()<<" Prob: "<<fun_5->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_6->GetChisquare()<<"/"<<fun_6->GetNDF()<<" Prob: "<<fun_6->GetProb()<<endl;
  cout<<"chi2/ndf "<<fun_7->GetChisquare()<<"/"<<fun_7->GetNDF()<<" Prob: "<<fun_7->GetProb()<<endl;
  cout<<endl<<endl;

  // CalcChi2(TGraphAsymmErrors *InGrf, TF1 *InFunc);


  cout<<"Chi Square  "<<CalcChi2(gr0,fun_0)<<"   "<<CalcChi2(gr1,fun_1)<<"   "<<CalcChi2(gr2,fun_2)<<"   "<<CalcChi2(gr3,fun_3)<<endl;
  cout<<"Chi Square  "<<CalcChi2(gr4,fun_4)<<"   "<<CalcChi2(gr5,fun_5)<<"   "<<CalcChi2(gr6,fun_6)<<"   "<<CalcChi2(gr7,fun_7)<<endl;
  
  Double_t TotalChi2 = CalcChi2(gr0,fun_0) + CalcChi2(gr1,fun_1) + CalcChi2(gr2,fun_2) + CalcChi2(gr3,fun_3)+CalcChi2(gr4,fun_4)
    + CalcChi2(gr5,fun_5) + CalcChi2(gr6,fun_6)+CalcChi2(gr7,fun_7);
  
  Double_t TotalNDF = (gr0->GetN() + gr1->GetN() + gr2->GetN() + gr3->GetN() + gr4->GetN() + gr5->GetN() + gr6->GetN() + gr7->GetN()) - 2 ;

  cout<<" Total Chi2 "<<TotalChi2<<"/"<<TotalNDF<<"   "<<(TotalChi2/TotalNDF)<<endl;
  
  dataFile<<" Total Chi2 "<<TotalChi2<<"/"<<TotalNDF<<"   "<<(TotalChi2/TotalNDF)<<endl;


   return;

}



Double_t CMS_0009_FitLDME(Double_t *x, Double_t *par)
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
  
  Double_t SigmaFeedDown = CMS_0009_Psi2S_FeedDown(x[0]) + CMS_0009_Chic0_FeedDown(x[0]) + CMS_0009_Chic1_FeedDown(x[0]) + CMS_0009_Chic2_FeedDown(x[0]);
  
  Double_t SigmaDirect = (LDME_3S1_1*grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])
			  + LDME_1S0_8*3.0*grCMS_0009_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]));

  Double_t Sigma = SigmaDirect + SigmaFeedDown;


  return Sigma;
  
}


Double_t CMS_0009_Psi2S_FeedDown(Double_t Pt)
{

  //Scale Psi2S Pt for JPsi
  Double_t Psi2SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Psi2S_LDME_3S1_1*grCMS_0009_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Psi2SPt) + Psi2S_LDME_3S1_8*grCMS_0009_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Psi2SPt)
		   + Psi2S_LDME_1S0_8*3.0*grCMS_0009_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Psi2SPt)); 
		      
  Double_t BRCorr =  1.0;
  Sigma = Sigma*BRCorr;
  
  return Sigma;
}





TGraph *Grf_CMS_0009_Psi2S_FeedDown(TGraph *InGraph)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=CMS_0009_Psi2S_FeedDown(xx);
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  OutGraph->SetLineColor(7);
  OutGraph->SetLineStyle(2);
  OutGraph->SetLineWidth(2.0);
    
  return OutGraph;
}


TGraph *Grf_CMS_0009_ChiC_FeedDown(TGraph *InGraph, Int_t Par)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
  
    if(Par ==0){zz=CMS_0009_Chic0_FeedDown(xx);}
    if(Par ==1){zz=CMS_0009_Chic1_FeedDown(xx);}
    if(Par ==2){zz=CMS_0009_Chic2_FeedDown(xx);}
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  return OutGraph;
}







Double_t CMS_0009_Chic0_FeedDown(Double_t Pt)
{
  Double_t Chic0Pt = Scale_Chi_Pt(Pt,0);
  Double_t Sigma = Chic0_LDME_3P0_1*grCMS_0009_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit->Eval(Chic0Pt) + 
    Chic0_LDME_3S1_8*grCMS_0009_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic0Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t CMS_0009_Chic1_FeedDown(Double_t Pt)
{
  Double_t Chic1Pt = Scale_Chi_Pt(Pt,1);
  Double_t Sigma = Chic1_LDME_3P1_1*grCMS_0009_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Chic1Pt) + 
    Chic1_LDME_3S1_8*grCMS_0009_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic1Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t CMS_0009_Chic2_FeedDown(Double_t Pt)
{
  Double_t Chic2Pt = Scale_Chi_Pt(Pt,2);
  Double_t Sigma = Chic2_LDME_3P2_1*grCMS_0009_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Chic2Pt) + 
    Chic2_LDME_3S1_8*grCMS_0009_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic2Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t CMS_FitLDME(Double_t *x, Double_t *par)
{

 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  Double_t SigmaFeedDown = CMS_Psi2S_FeedDown(x[0]) + CMS_Chic0_FeedDown(x[0]) + CMS_Chic1_FeedDown(x[0]) + CMS_Chic2_FeedDown(x[0]);
  
  Double_t SigmaDirect = (LDME_3S1_1*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grCMS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])
			  + LDME_1S0_8*3.0*grCMS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0])); 
 
  Double_t Sigma = SigmaDirect + SigmaFeedDown;


  return Sigma;
  
}


TGraph *Grf_CMS_Psi2S_FeedDown(TGraph *InGraph)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=CMS_Psi2S_FeedDown(xx);
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  OutGraph->SetLineColor(7);
  OutGraph->SetLineStyle(2);
  OutGraph->SetLineWidth(2.0);
    
  return OutGraph;
}


TGraph *Grf_CMS_ChiC_FeedDown(TGraph *InGraph, Int_t Par)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    if(Par ==0){zz=CMS_Chic0_FeedDown(xx);}
    if(Par ==1){zz=CMS_Chic1_FeedDown(xx);}
    if(Par ==2){zz=CMS_Chic2_FeedDown(xx);}
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  return OutGraph;
}



Double_t CMS_Psi2S_FeedDown(Double_t Pt)
{

  //Scale Psi2S Pt for JPsi
  Double_t Psi2SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Psi2S_LDME_3S1_1*grCMS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Psi2SPt) + Psi2S_LDME_3S1_8*grCMS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Psi2SPt)
		    + Psi2S_LDME_1S0_8*3.0*grCMS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Psi2SPt));  
  // Double_t BRCorr =  (BRPsi2S2JPsi*BRJPsi2MuMu)/BRPsi2S2MuMu;
  Double_t BRCorr =  1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t CMS_Chic0_FeedDown(Double_t Pt)
{
  Double_t Chic0Pt = Scale_Chi_Pt(Pt,0);
  Double_t Sigma = Chic0_LDME_3P0_1*grCMS_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit->Eval(Chic0Pt) + 
    Chic0_LDME_3S1_8*grCMS_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic0Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t CMS_Chic1_FeedDown(Double_t Pt)
{
  Double_t Chic1Pt = Scale_Chi_Pt(Pt,1);
  Double_t Sigma = Chic1_LDME_3P1_1*grCMS_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Chic1Pt) + 
    Chic1_LDME_3S1_8*grCMS_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic1Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}

Double_t CMS_Chic2_FeedDown(Double_t Pt)
{
  Double_t Chic2Pt = Scale_Chi_Pt(Pt,2);
  Double_t Sigma = Chic2_LDME_3P2_1*grCMS_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Chic2Pt) + 
    Chic2_LDME_3S1_8*grCMS_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic2Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


//==========================================================================================================================================//
//=============================================  CDF 196 FITTING FUNCTIONS ================================================================//
//=========================================================================================================================================//

Double_t CDF_FitLDME(Double_t *x, Double_t *par)
{
 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
  
  Double_t SigmaFeedDown = CDF_Psi2S_FeedDown(x[0]) + CDF_Chic0_FeedDown(x[0]) + CDF_Chic1_FeedDown(x[0]) + CDF_Chic2_FeedDown(x[0]);
  
  Double_t SigmaDirect = (LDME_3S1_1*grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grCDF_RootS196TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])+
			  LDME_1S0_8*3.0*grCDF_RootS196TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0])); 
		    
  
  Double_t Sigma = SigmaDirect + SigmaFeedDown;

  
  return Sigma;
  
}


Double_t CDF_Psi2S_FeedDown(Double_t Pt)
{

  //Scale Psi2S Pt for JPsi
  Double_t Psi2SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Psi2S_LDME_3S1_1*grCDF_RootS196TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Psi2SPt) + Psi2S_LDME_3S1_8*grCDF_RootS196TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Psi2SPt)
		    + Psi2S_LDME_1S0_8*3.0*grCDF_RootS196TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Psi2SPt)); 
  Double_t BRCorr =  1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}




Double_t CDF_Chic0_FeedDown(Double_t Pt)
{
  Double_t Chic0Pt = Scale_Chi_Pt(Pt,0);
  Double_t Sigma = Chic0_LDME_3P0_1*grCDF_RootS196TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit->Eval(Chic0Pt) + 
    Chic0_LDME_3S1_8*grCDF_RootS196TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic0Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t CDF_Chic1_FeedDown(Double_t Pt)
{
  Double_t Chic1Pt = Scale_Chi_Pt(Pt,1);
  Double_t Sigma = Chic1_LDME_3P1_1*grCDF_RootS196TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Chic1Pt) + 
    Chic1_LDME_3S1_8*grCDF_RootS196TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic1Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t CDF_Chic2_FeedDown(Double_t Pt)
{
  Double_t Chic2Pt = Scale_Chi_Pt(Pt,2);
  
  Double_t Sigma = Chic2_LDME_3P2_1*grCDF_RootS196TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Chic2Pt) + Chic2_LDME_3S1_8*grCDF_RootS196TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic2Pt);


  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}




TGraph *Grf_CDF_Psi2S_FeedDown(TGraph *InGraph)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=CDF_Psi2S_FeedDown(xx);
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  OutGraph->SetLineColor(7);
  OutGraph->SetLineStyle(2);
  OutGraph->SetLineWidth(2.0);
    
  return OutGraph;
}


TGraph *Grf_CDF_ChiC_FeedDown(TGraph *InGraph, Int_t Par)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    if(Par ==0){zz=CDF_Chic0_FeedDown(xx);}
    if(Par ==1){zz=CDF_Chic1_FeedDown(xx);}
    if(Par ==2){zz=CDF_Chic2_FeedDown(xx);}
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  return OutGraph;
}




//==========================================================================================================================================//
//=============================================  CDF 180 FITTING FUNCTIONS ================================================================//
//=========================================================================================================================================//

Double_t CDF_RootS180TeV_FitLDME(Double_t *x, Double_t *par)
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
  
  Double_t SigmaFeedDown = CDF_RootS180TeV_Psi2S_FeedDown(x[0]) + CDF_RootS180TeV_Chic0_FeedDown(x[0]) + CDF_RootS180TeV_Chic1_FeedDown(x[0]) + CDF_RootS180TeV_Chic2_FeedDown(x[0]);
  
  Double_t SigmaDirect = (LDME_3S1_1*grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) +  LDME_3S1_8*grCDF_RootS180TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])
			  +LDME_1S0_8*3.0*grCDF_RootS180TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0])); 
  
  Double_t Sigma = SigmaDirect + SigmaFeedDown;
  
  
  return Sigma;
  
}


         
Double_t CDF_RootS180TeV_Psi2S_FeedDown(Double_t Pt)
{

  //Scale Psi2S Pt for JPsi
  Double_t Psi2SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Psi2S_LDME_3S1_1*grCDF_RootS180TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Psi2SPt) + Psi2S_LDME_3S1_8*grCDF_RootS180TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Psi2SPt)
		    + Psi2S_LDME_1S0_8*3.0*grCDF_RootS180TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Psi2SPt) );

  
  Double_t BRCorr =  1.0;
  Sigma = Sigma*BRCorr;
  
  return Sigma;
}



Double_t CDF_RootS180TeV_Chic0_FeedDown(Double_t Pt)
{
  Double_t Chic0Pt = Scale_Chi_Pt(Pt,0);
  Double_t Sigma = Chic0_LDME_3P0_1*grCDF_RootS180TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit->Eval(Chic0Pt) + 
    Chic0_LDME_3S1_8*grCDF_RootS180TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic0Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t CDF_RootS180TeV_Chic1_FeedDown(Double_t Pt)
{
  Double_t Chic1Pt = Scale_Chi_Pt(Pt,1);
  Double_t Sigma = Chic1_LDME_3P1_1*grCDF_RootS180TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Chic1Pt) + 
    Chic1_LDME_3S1_8*grCDF_RootS180TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic1Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t CDF_RootS180TeV_Chic2_FeedDown(Double_t Pt)
{
  Double_t Chic2Pt = Scale_Chi_Pt(Pt,2);
  
  Double_t Sigma = Chic2_LDME_3P2_1*grCDF_RootS180TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Chic2Pt) + Chic2_LDME_3S1_8*grCDF_RootS180TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic2Pt);


  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}



TGraph *Grf_CDF_RootS180TeV_Psi2S_FeedDown(TGraph *InGraph)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=CDF_RootS180TeV_Psi2S_FeedDown(xx);
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  OutGraph->SetLineColor(7);
  OutGraph->SetLineStyle(2);
  OutGraph->SetLineWidth(2.0);
    
  return OutGraph;
}


TGraph *Grf_CDF_RootS180TeV_ChiC_FeedDown(TGraph *InGraph, Int_t Par)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    if(Par ==0){zz=CDF_RootS180TeV_Chic0_FeedDown(xx);}
    if(Par ==1){zz=CDF_RootS180TeV_Chic1_FeedDown(xx);}
    if(Par ==2){zz=CDF_RootS180TeV_Chic2_FeedDown(xx);}
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  return OutGraph;
}



//==========================================================================================================================================//
//==================================   ATLAS 7 TeV Fitting Functions   ====================================================================//
//=========================================================================================================================================//


Double_t ATLAS_FitLDME(Double_t *x, Double_t *par)
{

 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
 
  Double_t SigmaFeedDown = ATLAS_Psi2S_FeedDown(x[0]) + ATLAS_Chic0_FeedDown(x[0]) + ATLAS_Chic1_FeedDown(x[0]) + ATLAS_Chic2_FeedDown(x[0]);
  
  Double_t SigmaDirect = (LDME_3S1_1*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])
			  + LDME_1S0_8*3.0*grATLAS_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]) );

  
  Double_t Sigma = SigmaDirect + SigmaFeedDown;


  return Sigma;
  
}


Double_t ATLAS_Psi2S_FeedDown(Double_t Pt)
{

  //Scale Psi2S Pt for JPsi
  Double_t Psi2SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Psi2S_LDME_3S1_1*grATLAS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Psi2SPt) + Psi2S_LDME_3S1_8*grATLAS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Psi2SPt)
		    + Psi2S_LDME_1S0_8*3.0*grATLAS_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Psi2SPt)); 
  
  Double_t BRCorr =  1.0;
  Sigma = Sigma*BRCorr;
  
  return Sigma;
}




Double_t ATLAS_Chic0_FeedDown(Double_t Pt)
{
  Double_t Chic0Pt = Scale_Chi_Pt(Pt,0);
  Double_t Sigma = Chic0_LDME_3P0_1*grATLAS_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit->Eval(Chic0Pt) + 
    Chic0_LDME_3S1_8*grATLAS_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic0Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t ATLAS_Chic1_FeedDown(Double_t Pt)
{
  Double_t Chic1Pt = Scale_Chi_Pt(Pt,1);
  Double_t Sigma = Chic1_LDME_3P1_1*grATLAS_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Chic1Pt) + 
    Chic1_LDME_3S1_8*grATLAS_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic1Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t ATLAS_Chic2_FeedDown(Double_t Pt)
{
  Double_t Chic2Pt = Scale_Chi_Pt(Pt,2);
  Double_t Sigma = Chic2_LDME_3P2_1*grATLAS_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Chic2Pt) + 
    Chic2_LDME_3S1_8*grATLAS_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic2Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}



TGraph *Grf_ATLAS_Psi2S_FeedDown(TGraph *InGraph)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=ATLAS_Psi2S_FeedDown(xx);
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  OutGraph->SetLineColor(7);
  OutGraph->SetLineStyle(2);
  OutGraph->SetLineWidth(2.0);
    
  return OutGraph;
}


TGraph *Grf_ATLAS_ChiC_FeedDown(TGraph *InGraph, Int_t Par)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    if(Par ==0){zz=ATLAS_Chic0_FeedDown(xx);}
    if(Par ==1){zz=ATLAS_Chic1_FeedDown(xx);}
    if(Par ==2){zz=ATLAS_Chic2_FeedDown(xx);}
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  return OutGraph;
}










//=====================================================================================================================================//
//=====================================================================================================================================//



//==========================================================================================================================================//
//==================================   ATLAS 8 TeV Fitting Functions   ====================================================================//
//=========================================================================================================================================//


Double_t ATLAS_8TeV_FitLDME(Double_t *x, Double_t *par)
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
  
  Double_t SigmaFeedDown = ATLAS_8TeV_Psi2S_FeedDown(x[0]) + ATLAS_8TeV_Chic0_FeedDown(x[0]) + ATLAS_8TeV_Chic1_FeedDown(x[0]) + ATLAS_8TeV_Chic2_FeedDown(x[0]);
  
  Double_t SigmaDirect = (LDME_3S1_1*grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grATLAS_RootS8TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])
			  + LDME_1S0_8*3.0* grATLAS_RootS8TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]) );
  Double_t Sigma = SigmaDirect + SigmaFeedDown;
  
  return Sigma;
  
}


Double_t ATLAS_8TeV_Psi2S_FeedDown(Double_t Pt)
{

  //Scale Psi2S Pt for JPsi
  Double_t Psi2SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Psi2S_LDME_3S1_1*grATLAS_RootS8TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Psi2SPt) + Psi2S_LDME_3S1_8*grATLAS_RootS8TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Psi2SPt)
		    + Psi2S_LDME_1S0_8*3.0*grATLAS_RootS8TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Psi2SPt)); 

  Double_t BRCorr =  1.0;
  Sigma = Sigma*BRCorr;
  
  return Sigma;
}




Double_t ATLAS_8TeV_Chic0_FeedDown(Double_t Pt)
{
  Double_t Chic0Pt = Scale_Chi_Pt(Pt,0);
  Double_t Sigma = Chic0_LDME_3P0_1*grATLAS_RootS8TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit->Eval(Chic0Pt) + 
    Chic0_LDME_3S1_8*grATLAS_RootS8TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic0Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t ATLAS_8TeV_Chic1_FeedDown(Double_t Pt)
{
  Double_t Chic1Pt = Scale_Chi_Pt(Pt,1);
  Double_t Sigma = Chic1_LDME_3P1_1*grATLAS_RootS8TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Chic1Pt) + 
    Chic1_LDME_3S1_8*grATLAS_RootS8TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic1Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t ATLAS_8TeV_Chic2_FeedDown(Double_t Pt)
{
  Double_t Chic2Pt = Scale_Chi_Pt(Pt,2);
  Double_t Sigma = Chic2_LDME_3P2_1*grATLAS_RootS8TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Chic2Pt) + 
    Chic2_LDME_3S1_8*grATLAS_RootS8TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic2Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}




TGraph *Grf_ATLAS_8TeV_Psi2S_FeedDown(TGraph *InGraph)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=ATLAS_8TeV_Psi2S_FeedDown(xx);
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  OutGraph->SetLineColor(7);
  OutGraph->SetLineStyle(2);
  OutGraph->SetLineWidth(2.0);
    
  return OutGraph;
}


TGraph *Grf_ATLAS_8TeV_ChiC_FeedDown(TGraph *InGraph, Int_t Par)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    if(Par ==0){zz=ATLAS_8TeV_Chic0_FeedDown(xx);}
    if(Par ==1){zz=ATLAS_8TeV_Chic1_FeedDown(xx);}
    if(Par ==2){zz=ATLAS_8TeV_Chic2_FeedDown(xx);}
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  return OutGraph;
}






//=====================================================================================================================================//
//=====================================================================================================================================//
//==========================================================================================================================================//


//=========================================================================================================================================//
//==================================   LHCb 7 TeV Fitting Functions   ====================================================================//
//=======================================================================================================================================//

Double_t LHCb_RootS7TeV_FitLDME(Double_t *x, Double_t *par)
{

 
  Double_t LDME_3S1_1 = par[0];  
  Double_t LDME_1S0_8 = par[1];
  Double_t LDME_3S1_8 = par[2];
   
  Double_t SigmaFeedDown = LHCb_RootS7TeV_Psi2S_FeedDown(x[0]) + LHCb_RootS7TeV_Chic0_FeedDown(x[0]) + LHCb_RootS7TeV_Chic1_FeedDown(x[0]) + LHCb_RootS7TeV_Chic2_FeedDown(x[0]);
  
  Double_t SigmaDirect = (LDME_3S1_1*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])
			  + LDME_1S0_8*3.0*grLHCb_RootS7TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]));
 
  Double_t Sigma = SigmaDirect + SigmaFeedDown;


  return Sigma;
  
}


Double_t LHCb_RootS7TeV_Psi2S_FeedDown(Double_t Pt)
{

  //Scale Psi2S Pt for JPsi
  Double_t Psi2SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Psi2S_LDME_3S1_1*grLHCb_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Psi2SPt) + Psi2S_LDME_3S1_8*grLHCb_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Psi2SPt)
		    + Psi2S_LDME_1S0_8*3.0*grLHCb_RootS7TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Psi2SPt));
  Double_t BRCorr =  1.0;
  Sigma = Sigma*BRCorr;
  
  return Sigma;
}




Double_t LHCb_RootS7TeV_Chic0_FeedDown(Double_t Pt)
{
  Double_t Chic0Pt = Scale_Chi_Pt(Pt,0);
  Double_t Sigma = Chic0_LDME_3P0_1*grLHCb_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit->Eval(Chic0Pt) + 
    Chic0_LDME_3S1_8*grLHCb_RootS7TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic0Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t LHCb_RootS7TeV_Chic1_FeedDown(Double_t Pt)
{
  Double_t Chic1Pt = Scale_Chi_Pt(Pt,1);
  Double_t Sigma = Chic1_LDME_3P1_1*grLHCb_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Chic1Pt) + 
    Chic1_LDME_3S1_8*grLHCb_RootS7TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic1Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t LHCb_RootS7TeV_Chic2_FeedDown(Double_t Pt)
{
  Double_t Chic2Pt = Scale_Chi_Pt(Pt,2);
  Double_t Sigma = Chic2_LDME_3P2_1*grLHCb_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Chic2Pt) + 
    Chic2_LDME_3S1_8*grLHCb_RootS7TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic2Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}



TGraph *Grf_LHCb_RootS7TeV_Psi2S_FeedDown(TGraph *InGraph)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=LHCb_RootS7TeV_Psi2S_FeedDown(xx);
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  OutGraph->SetLineColor(7);
  OutGraph->SetLineStyle(2);
  OutGraph->SetLineWidth(2.0);
    
  return OutGraph;
}


TGraph *Grf_LHCb_RootS7TeV_ChiC_FeedDown(TGraph *InGraph, Int_t Par)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    if(Par ==0){zz=LHCb_RootS7TeV_Chic0_FeedDown(xx);}
    if(Par ==1){zz=LHCb_RootS7TeV_Chic1_FeedDown(xx);}
    if(Par ==2){zz=LHCb_RootS7TeV_Chic2_FeedDown(xx);}
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  return OutGraph;
}











//=====================================================================================================================================//
//=====================================================================================================================================//






//==========================================================================================================================================//
//==================================   LHCb 13 TeV Fitting Functions   ====================================================================//
//=========================================================================================================================================//

Double_t LHCb_RootS13TeV_FitLDME(Double_t *x, Double_t *par)
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
  
  Double_t SigmaFeedDown = LHCb_RootS13TeV_Psi2S_FeedDown(x[0]) + LHCb_RootS13TeV_Chic0_FeedDown(x[0]) + LHCb_RootS13TeV_Chic1_FeedDown(x[0]) + LHCb_RootS13TeV_Chic2_FeedDown(x[0]);
  
  Double_t SigmaDirect = (LDME_3S1_1*grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(x[0]) + LDME_3S1_8*grLHCb_RootS13TeV_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(x[0])
			  + LDME_1S0_8*3.0*grLHCb_RootS13TeV_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(x[0]));
  Double_t Sigma = SigmaDirect + SigmaFeedDown;


  return Sigma;
  
}


Double_t LHCb_RootS13TeV_Psi2S_FeedDown(Double_t Pt)
{

  //Scale Psi2S Pt for JPsi
  Double_t Psi2SPt = Scale_Pt(Pt);
  
  Double_t Sigma = (Psi2S_LDME_3S1_1*grLHCb_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit->Eval(Psi2SPt) + Psi2S_LDME_3S1_8*grLHCb_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Psi2SPt)
		    + Psi2S_LDME_1S0_8*3.0*grLHCb_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit->Eval(Psi2SPt));
  
  Double_t BRCorr =  1.0;
  Sigma = Sigma*BRCorr;
  
  return Sigma;
}




Double_t LHCb_RootS13TeV_Chic0_FeedDown(Double_t Pt)
{
  Double_t Chic0Pt = Scale_Chi_Pt(Pt,0);
  Double_t Sigma = Chic0_LDME_3P0_1*grLHCb_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit->Eval(Chic0Pt) + 
    Chic0_LDME_3S1_8*grLHCb_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic0Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t LHCb_RootS13TeV_Chic1_FeedDown(Double_t Pt)
{
  Double_t Chic1Pt = Scale_Chi_Pt(Pt,1);
  Double_t Sigma = Chic1_LDME_3P1_1*grLHCb_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit->Eval(Chic1Pt) + 
    Chic1_LDME_3S1_8*grLHCb_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic1Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}


Double_t LHCb_RootS13TeV_Chic2_FeedDown(Double_t Pt)
{
  Double_t Chic2Pt = Scale_Chi_Pt(Pt,2);
  Double_t Sigma = Chic2_LDME_3P2_1*grLHCb_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit->Eval(Chic2Pt) + 
    Chic2_LDME_3S1_8*grLHCb_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit->Eval(Chic2Pt);
  Double_t BRCorr = 1.0;
  Sigma = Sigma*BRCorr;
  return Sigma;
}





TGraph *Grf_LHCb_RootS13TeV_Psi2S_FeedDown(TGraph *InGraph)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    zz=LHCb_RootS13TeV_Psi2S_FeedDown(xx);
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  OutGraph->SetLineColor(7);
  OutGraph->SetLineStyle(2);
  OutGraph->SetLineWidth(2.0);
    
  return OutGraph;
}


TGraph *Grf_LHCb_RootS13TeV_ChiC_FeedDown(TGraph *InGraph, Int_t Par)
{
  
  TGraph *SGraph = new TGraph; 
  

  const int NN = InGraph->GetN();
  
  for (int j=0; j < NN; ++j){
    Double_t xx,yy,zz;
    InGraph->GetPoint(j,xx,yy);
    if(Par ==0){zz=LHCb_RootS13TeV_Chic0_FeedDown(xx);}
    if(Par ==1){zz=LHCb_RootS13TeV_Chic1_FeedDown(xx);}
    if(Par ==2){zz=LHCb_RootS13TeV_Chic2_FeedDown(xx);}
    SGraph->SetPoint(j,xx,zz);  
  }
  TGraph *OutGraph= new TGraph();
  OutGraph = SGraph;
  return OutGraph;
}

























//==================================================================================================================================//
//=================================================================================================================================//
//==================================================================================================================================//


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





//=====================================================================================================================================//
//=====================================================================================================================================//



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
    Double_t delta  = (yy0[i]-CMS_0009_FitLDME(&xx0[i],par))/erryy0[i];
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
    Double_t delta  = (yy3[i]-ATLAS_8TeV_FitLDME(&xx3[i],par))/erryy3[i];
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
    Double_t delta  = (yy5[i]-CDF_RootS180TeV_FitLDME(&xx5[i],par))/erryy5[i];
    chisq += delta*delta;
  }
    
  return chisq;
}

//______________________________________________________________________________

Double_t fcn6(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag)
{ 
  
  const Int_t nbins = gr6->GetN();
  Int_t i;
  
  Double_t xx6[nbins]; 
  Double_t yy6[nbins];
  Double_t erryy6[nbins];

  for (Int_t j=0;j<nbins; j++) 
    {
      gr6->GetPoint(j,xx6[j],yy6[j]);
      erryy6[j]= gr6->GetErrorY(j);
    }

 //calculate chisquare
  Double_t chisq = 0;
  for (i=0;i<nbins; i++) {
    Double_t delta  = (yy6[i]-LHCb_RootS7TeV_FitLDME(&xx6[i],par))/erryy6[i];
    chisq += delta*delta;
  }
  
  
  return chisq;
}



//______________________________________________________________________________

Double_t fcn7(Int_t &npar, Double_t *gin, Double_t *par, Int_t iflag)
{ 
  
  const Int_t nbins = gr7->GetN();
  Int_t i;
  
  Double_t xx7[nbins]; 
  Double_t yy7[nbins];
  Double_t erryy7[nbins];

  for (Int_t j=0;j<nbins; j++) 
    {
      gr7->GetPoint(j,xx7[j],yy7[j]);
      erryy7[j]= gr7->GetErrorY(j);
    }

 //calculate chisquare
  Double_t chisq = 0;
  for (i=0;i<nbins; i++) {
    Double_t delta  = (yy7[i]-LHCb_RootS13TeV_FitLDME(&xx7[i],par))/erryy7[i];
    chisq += delta*delta;
  }
  
  
  return chisq;
}




//______________________________________________________________________________
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
  //f = fcn1(npar,gin, par, iflag) + fcn2(npar,gin, par, iflag) + fcn3(npar,gin, par, iflag) + fcn4(npar,gin, par, iflag) + fcn0(npar,gin, par, iflag) ;


  f = fcn0(npar,gin, par, iflag) + fcn1(npar,gin, par, iflag) + fcn2(npar,gin, par, iflag) + fcn3(npar,gin, par, iflag) + 
  fcn4(npar,gin, par, iflag) + fcn5(npar,gin, par, iflag) + fcn6(npar,gin, par, iflag) + fcn7(npar,gin, par, iflag);

  //f = fcn4(npar,gin, par, iflag) ;


}




Double_t Scale_Pt(Double_t JPsiPt)
{
  Double_t Psi2SPt;
  Double_t MM = 0.0;
  Double_t CC = 0.0;
  MM=1.154; CC = 0.1413;
  Psi2SPt  = MM * JPsiPt + CC;
  return Psi2SPt;
}


Double_t Scale_Chi_Pt(Double_t JPsiPt, Int_t Par)
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





TGraph *Add_ChiC_FeedDown(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3)
{
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx1,yy1,zz;
    Double_t xx2,yy2;
    Double_t xx3,yy3;
    
    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);
    InGraph3->GetPoint(j,xx3,yy3);
    zz=yy1+yy2+yy3;
    SGraph->SetPoint(j,xx1,zz);  
  }
  
  SGraph->SetLineWidth(2);
  SGraph->SetLineColor(8);
  SGraph->SetLineStyle(10);

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;


}












TGraph *Add_FeedDown_QCDSigma(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3, TF1 *InFunc)
{
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx1,yy1,zz1;
    Double_t xx2,yy2,zz2;
    Double_t xx3,yy3;
    Double_t xx4,yy4;

    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);
    InGraph3->GetPoint(j,xx3,yy3);
    zz2=yy1+yy2+yy3;
    yy4=InFunc->Eval(xx1);
    zz1=yy4-zz2;
    SGraph->SetPoint(j,xx1,zz1);  
  }
  
  SGraph->SetLineWidth(2);
  SGraph->SetLineColor(8);
  SGraph->SetLineStyle(10);


  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;


}


TGraphAsymmErrors *Data_CMS_Latest_D2NDPtDy_PromptJPsi_Y0012_Pt()
{
  //
  const int NN = 31;

  // X value (pT)
  Double_t p8319_d1x1y1_xval[NN] = {10.50, 11.50, 12.50, 13.50, 14.50, 15.50, 16.50, 17.50, 18.50, 19.50, 20.50, 21.50, 22.50, 23.50, 24.50, 25.50, 26.50, 
				    27.50, 28.50, 29.50, 30.90, 32.90, 35.00, 37.00, 39.80, 43.80, 47.90, 54.20, 66.00, 82.90, 104.10};
  Double_t p8319_d1x1y1_xvallow[NN] = {10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 
					 29.0, 30.0, 32.0, 34.0, 36.0, 38.0, 42.0, 46.0, 50.0, 60.0, 75.0, 95.0};
  Double_t p8319_d1x1y1_xvalhigh[NN] = {11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 
					32.0, 34.0, 36.0, 38.0, 42.0, 46.0, 50.0, 60.0, 75.0, 95.0, 120.0};
  
  // Y Value (B*d2Sigma/dpTdy)  
  Double_t p8319_d1x1y1_yval[NN] = {1010.00000, 609.00000, 382.00000, 247.00000, 165.00000, 114.00000, 78.40000, 56.60000, 41.30000, 30.50000, 23.00000, 17.60000, 
				    13.50000, 10.50000, 8.35000, 6.75000, 5.35000, 4.31000, 3.57000, 2.86000, 2.21000, 1.55000, 1.11000, 0.82200, 0.53300, 0.30200, 
				    0.18600, 0.08750, 0.02780, 0.00797, 0.00196};
  Double_t p8319_d1x1y1_ystatminus[NN] = {1.40000, 0.90200, 0.61800, 0.45400, 0.34800, 0.27400, 0.22000, 0.17900, 0.14700, 0.12500, 0.10600, 0.09110, 0.07880, 
					  0.06830, 0.06020, 0.05360, 0.04720, 0.04220, 0.03790, 0.03380, 0.02080, 0.01730, 0.01460, 0.01250, 0.00704, 0.00533, 
					  0.00424, 0.00187, 0.00090, 0.00043, 0.00021};
  Double_t p8319_d1x1y1_ystatplus[NN] = {1.40000, 0.90200, 0.61800, 0.45400, 0.34800, 0.27400, 0.22000, 0.17900, 0.14700, 0.12500, 0.10600, 0.09110, 0.07880, 
					 0.06830, 0.06020, 0.05360, 0.04720, 0.04220, 0.03790, 0.03380, 0.02080, 0.01730, 0.01460, 0.01250, 0.00704, 0.00533, 
					 0.00424, 0.00187, 0.00090, 0.00043, 0.00021};
  
  Double_t p8319_d1x1y1_ysystminus1[NN] = {80.00000, 35.70000, 19.20000, 11.60000, 7.51000, 5.04000, 3.42000, 2.45000, 1.78000, 1.32000, 0.99800, 0.76400, 0.58500, 
					   0.45800, 0.36500, 0.29400, 0.23400, 0.18900, 0.15700, 0.12700, 0.09820, 0.06940, 0.05020, 0.05330, 0.03470, 0.01960, 
					   0.01210, 0.00950, 0.00308, 0.00089, 0.00022};
  Double_t p8319_d1x1y1_ysystplus1[NN] = {80.00000, 35.70000, 19.20000, 11.60000, 7.51000, 5.04000, 3.42000, 2.45000, 1.78000, 1.32000, 0.99800, 0.76400, 0.58500, 
					  0.45800, 0.36500, 0.29400, 0.23400, 0.18900, 0.15700, 0.12700, 0.09820, 0.06940, 0.05020, 0.05330, 0.03470, 0.01960, 0.01210, 
					  0.00950, 0.00308, 0.00089, 0.00022};
  Double_t p8319_d1x1y1_ysystminus2[NN] = {22.30000, 13.40000, 8.39000, 5.44000, 3.63000, 2.50000, 1.72000, 1.25000, 0.90800, 0.67200, 0.50600, 0.38700, 0.29700, 
					   0.23200, 0.18400, 0.14900, 0.11800, 0.09490, 0.07850, 0.06290, 0.04860, 0.03410, 0.02450, 0.01810, 0.01170, 0.00665, 
					   0.00408, 0.00192, 0.00061, 0.00017, 0.00004};
  Double_t p8319_d1x1y1_ysystplus2[NN] = {22.30000, 13.40000, 8.39000, 5.44000, 3.63000, 2.50000, 1.72000, 1.25000, 0.90800, 0.67200, 0.50600, 0.38700, 0.29700, 
					   0.23200, 0.18400, 0.14900, 0.11800, 0.09490, 0.07850, 0.06290, 0.04860, 0.03410, 0.02450, 0.01810, 0.01170, 0.00665, 
					  0.00408, 0.00192, 0.00061, 0.00017, 0.00004};

  Double_t p8319_d1x1y1_ysystminus[NN] = {0.0};
  Double_t p8319_d1x1y1_ysystplus[NN] = {0.0};
  
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] =  {0.0};

  Double_t p8319_d1x1y1_xerrminus[NN]={0.0};
  Double_t p8319_d1x1y1_xerrplus[NN]={0.0};


  Double_t pbTonb =1.0/1000.0;
  Double_t DeltaY = 1.0;

for(int j=0;j<NN;j++){
  

  p8319_d1x1y1_xerrminus[j] = p8319_d1x1y1_xval[j] - p8319_d1x1y1_xvallow[j]; 
  p8319_d1x1y1_xerrplus[j] = p8319_d1x1y1_xvalhigh[j]-p8319_d1x1y1_xval[j];


  p8319_d1x1y1_ysystminus[j] = TMath::Sqrt((p8319_d1x1y1_ysystminus1[j]*p8319_d1x1y1_ysystminus1[j])+(p8319_d1x1y1_ysystminus2[j]*p8319_d1x1y1_ysystminus2[j]));
  p8319_d1x1y1_ysystplus[j] = TMath::Sqrt((p8319_d1x1y1_ysystplus1[j]*p8319_d1x1y1_ysystplus1[j])+(p8319_d1x1y1_ysystplus2[j]*p8319_d1x1y1_ysystplus2[j]));
  
  p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j]) + (p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
  p8319_d1x1y1_yerrplus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j]) + (p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
  

  p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j]) + (p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
  p8319_d1x1y1_yerrplus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j]) + (p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
  
  p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_ystatminus[j]= (p8319_d1x1y1_ystatminus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_ystatplus[j]=(p8319_d1x1y1_ystatplus[j]*pbTonb)/DeltaY;
  }



  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->SetMarkerColor(kBlack);
  Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,100.0);
   
  Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->GetXaxis()->CenterTitle();
  Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->GetYaxis()->CenterTitle();
  Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CMS_D2NDPtDy_PromptJPsi_0012_Pt;
  return OutGraph;
  
}


TGraphAsymmErrors *Data_CMS_New_D2NDPtDy_PrompJPsi_Y0009_Pt()
{
  //This data is from 1111.1557
  const int NN = 10;

  Double_t p8319_d1x1y1_xval[NN] = {8.569, 9.515, 10.494, 11.485, 12.711, 14.206, 16.329, 21.77, 35.03, 52.7};
  Double_t p8319_d1x1y1_xvallow[NN]={8.00, 9.00, 10.00, 11.00, 12.00, 13.50, 15.00, 18.00, 30.00, 45.00};
  Double_t p8319_d1x1y1_xvalhigh[NN]={9.00, 10.00, 11.00, 12.00, 13.50, 15.00, 18.00, 30.00, 45.00, 70.00};

  //========== d2Sigma/dpT*dy  
  Double_t p8319_d1x1y1_yval[NN] = {2.540000, 1.560000, 0.960000, 0.612000, 0.351000, 0.184000, 0.084100, 0.013900, 0.000780, 0.000070};
  double p8319_d1x1y1_ystatminus[NN] = {0.070000, 0.030000, 0.020000, 0.012000, 0.006000, 0.004000, 0.001500, 0.000200, 0.000030, 0.000007};
  double p8319_d1x1y1_ystatplus[NN] = {0.070000, 0.030000, 0.020000, 0.012000, 0.006000, 0.004000, 0.001500, 0.000200, 0.000030, 0.000007};

  double p8319_d1x1y1_ysystminus1[NN] = {0.060000, 0.090000, 0.040000, 0.025000, 0.013000, 0.005000, 0.002400, 0.000500, 0.000030, 0.000017};
  double p8319_d1x1y1_ysystplus1[NN] = {0.060000, 0.090000, 0.040000, 0.025000, 0.013000, 0.005000, 0.002400, 0.000500, 0.000030, 0.000017};

  double p8319_d1x1y1_ysystminus2[NN] = {0.100000, 0.060000, 0.040000, 0.024000, 0.014000, 0.007000, 0.003400, 0.000600, 0.000030, 0.000003};
  double p8319_d1x1y1_ysystplus2[NN] = {0.100000, 0.060000, 0.040000, 0.024000, 0.014000, 0.007000, 0.003400, 0.000600, 0.000030, 0.000003};


  Double_t p8319_d1x1y1_xerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.0};

  double p8319_d1x1y1_ysystminus[NN] = {0.0};
  double p8319_d1x1y1_ysystplus[NN] = {0.0};

  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] = {0.0};

  //Double_t DeltaY = 2.4;
  
  for(int j=0;j<NN;j++){
    
    p8319_d1x1y1_xerrminus[j] = p8319_d1x1y1_xval[j] - p8319_d1x1y1_xvallow[j]; 
    p8319_d1x1y1_xerrplus[j] = p8319_d1x1y1_xvalhigh[j]-p8319_d1x1y1_xval[j];

    p8319_d1x1y1_ysystminus[j] = TMath::Sqrt((p8319_d1x1y1_ysystminus1[j]*p8319_d1x1y1_ysystminus1[j])+(p8319_d1x1y1_ysystminus2[j]*p8319_d1x1y1_ysystminus2[j]));
    p8319_d1x1y1_ysystplus[j] = TMath::Sqrt((p8319_d1x1y1_ysystplus1[j]*p8319_d1x1y1_ysystplus1[j])+(p8319_d1x1y1_ysystplus2[j]*p8319_d1x1y1_ysystplus2[j]));
    
    p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j]) + (p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
    p8319_d1x1y1_yerrplus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j]) + (p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
    
    p8319_d1x1y1_yval[j] = p8319_d1x1y1_yval[j];
    p8319_d1x1y1_yerrminus[j]= p8319_d1x1y1_yerrminus[j];
    p8319_d1x1y1_yerrplus[j]= p8319_d1x1y1_yerrplus[j];
  
  }
  
  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										 p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->SetMarkerStyle(21);
  Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->SetMarkerColor(4);
  Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
  
  Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->GetXaxis()->CenterTitle();
  Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->GetYaxis()->CenterTitle();  

  Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CMS_D2NDPtDy_PromptJPsi_0009_Pt;
  return OutGraph;
 
}



TGraphAsymmErrors *Data_CDF_RootS196TeV_D2NDPtDy_PromptJPsi_Y0006_Pt()
{
  //CDF Data 1.96 TeV |y^JPsi| < 0.6 
  //hep-ex/0412071

  //
  const int NN = 26;

  // X value (pT)
  Double_t p8319_d1x1y1_xval[NN] = {1.38, 1.63, 1.87, 2.13, 2.38, 2.62, 2.87, 3.12, 3.38, 3.62, 3.87, 4.12, 4.38, 4.62, 4.88, 5.24, 5.74, 6.24, 6.74, 7.45, 8.46, 
				    9.46, 10.80, 12.80, 15.40, 18.3};
  Double_t p8319_d1x1y1_xvallow[NN] = {1.25, 1.50, 1.75, 2.00, 2.25, 2.50, 2.75, 3.00, 3.25, 3.50, 3.75, 4.00, 4.25, 4.50, 4.75, 5.00, 5.50, 6.00, 6.50, 7.00, 8.00, 9.00, 
				       10.00, 12.00, 14.00, 17.00};
  Double_t p8319_d1x1y1_xvalhigh[NN] = {1.50, 1.75, 2.00, 2.25, 2.50, 2.75, 3.00, 3.25, 3.50, 3.75, 4.00, 4.25, 4.50, 4.75, 5.00, 5.50, 6.00, 6.50, 7.00, 8.00, 9.00, 10.00, 
					12.00, 14.00, 17.00, 20.00};
  
  // Y Value (B*dSigma/dpT)  
  Double_t p8319_d1x1y1_yval[NN] = {66.8000, 68.6000, 67.0000, 62.5000, 61.5000, 52.1000, 47.1000, 39.1000, 33.4000, 28.2000, 22.9000, 20.1000, 16.5000, 14.1000, 11.5000, 
				    8.9200, 6.2100, 4.2900, 2.9300, 1.8200, 0.8940, 0.4730, 0.2040, 0.0690, 0.0230, 0.0078};
  Double_t p8319_d1x1y1_ystatminus[NN] = {1.5000, 1.5000, 1.3000, 0.7000, 0.9000, 0.8000, 0.7000, 0.6000, 0.5000, 0.4000, 0.3000, 0.4000, 0.3000, 0.3000, 0.3000, 0.1300, 
					  0.1000, 0.0700, 0.0600, 0.0200, 0.0150, 0.0100, 0.0040, 0.0020, 0.0010, 0.0006};
  Double_t p8319_d1x1y1_ystatplus[NN] = {1.5000, 1.5000, 1.3000, 0.7000, 0.9000, 0.8000, 0.7000, 0.6000, 0.5000, 0.4000, 0.3000, 0.4000, 0.3000, 0.3000, 0.3000, 0.1300, 0.1000, 
					 0.0700, 0.0600, 0.0200, 0.0150, 0.0100, 0.0040, 0.0020, 0.0010, 0.0006};
  
  Double_t p8319_d1x1y1_ysystminus1[NN] = {9.2000, 8.2000, 7.9000, 7.5000, 7.3000, 5.2000, 4.4000, 3.0000, 2.8000, 2.1000, 1.6000, 1.5000, 1.2000, 1.0000, 0.8000, 0.5200, 
					   0.3700, 0.2400, 0.1700, 0.1100, 0.0470, 0.0240, 0.0100, 0.0030, 0.0010, 0.0006};
  Double_t p8319_d1x1y1_ysystplus1[NN] = {9.2000, 8.2000, 7.9000, 7.5000, 7.3000, 5.2000, 4.4000, 3.0000, 2.8000, 2.1000, 1.6000, 1.5000, 1.2000, 1.0000, 0.8000, 0.5200, 0.3700, 
					  0.2400, 0.1700, 0.1100, 0.0470, 0.0240, 0.0100, 0.0030, 0.0010, 0.0006};
  
  //======== 6.9 % ======================//
  Double_t Syst2 = 0.069;
  Double_t p8319_d1x1y1_ysystminus2[NN] = {0.0};
  Double_t p8319_d1x1y1_ysystplus2[NN] = {0.0};



  Double_t p8319_d1x1y1_ysystminus[NN] = {0.0};
  Double_t p8319_d1x1y1_ysystplus[NN] = {0.0};
  
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] =  {0.0};

  Double_t p8319_d1x1y1_xerrminus[NN]={0.0};
  Double_t p8319_d1x1y1_xerrplus[NN]={0.0};


  Double_t pbTonb =1.0;
  Double_t DeltaY = 1.2;

for(int j=0;j<NN;j++){
  


  p8319_d1x1y1_xerrminus[j] = p8319_d1x1y1_xval[j] - p8319_d1x1y1_xvallow[j]; 
  p8319_d1x1y1_xerrplus[j] = p8319_d1x1y1_xvalhigh[j]-p8319_d1x1y1_xval[j];

  p8319_d1x1y1_ysystminus2[j] = Syst2*p8319_d1x1y1_yval[j];
  p8319_d1x1y1_ysystplus2[j] = Syst2*p8319_d1x1y1_yval[j];


  p8319_d1x1y1_ysystminus[j] = TMath::Sqrt((p8319_d1x1y1_ysystminus1[j]*p8319_d1x1y1_ysystminus1[j])+(p8319_d1x1y1_ysystminus2[j]*p8319_d1x1y1_ysystminus2[j]));
  p8319_d1x1y1_ysystplus[j] = TMath::Sqrt((p8319_d1x1y1_ysystplus1[j]*p8319_d1x1y1_ysystplus1[j])+(p8319_d1x1y1_ysystplus2[j]*p8319_d1x1y1_ysystplus2[j]));
  
  p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j]) + (p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
  p8319_d1x1y1_yerrplus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j]) + (p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
  

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
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetRangeUser(0.001,1000.0);
  
  TAxis *Xaxis1 = Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,22.0);
   

  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis()->CenterTitle();
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->CenterTitle();

  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt;
  return OutGraph;
  
}






TGraphAsymmErrors *Data_CDF_RootS180TeV_D2NDPtDy_PromptJPsi_Y0006_Pt()
{
  // J/Psi and Psi(2S) at 1.8 TeV, CDF |y| < 0.6 inspire link
  //https://inspirehep.net/search?ln=en&ln=en&p=find+cn+cdf+and+date+1997+and+t+Production&of=hb&action_search=Search&sf=earliestdate&so=d&rm=&rg=25&sc=0

  const int NN = 11;

  // X value (pT)
  Double_t p8319_d1x1y1_xval[NN] = {5.24, 5.74, 6.24, 6.74, 7.47, 8.47, 9.47, 10.91, 12.92,15.35, 18.38};
  Double_t p8319_d1x1y1_xerrminus[NN] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  Double_t p8319_d1x1y1_xerrplus[NN] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  
  // Y Value (B*dSigma/dpT)  
  Double_t p8319_d1x1y1_yval[NN] = {7.9, 5.8, 4.08, 2.79, 1.73, 0.891, 0.51, 0.221, 0.0714, 0.0261, 0.0073};
  Double_t p8319_d1x1y1_yerrplus[NN] = {1.4, 1.0, 0.64, 0.42, 0.25, 0.12, 0.064, 0.026, 0.0083, 0.0029, 0.001};
  Double_t p8319_d1x1y1_yerrminus[NN] = {1.4, 1.0, 0.68, 0.45, 0.27, 0.14, 0.073, 0.031, 0.0097,0.0034, 0.0011};

  
  Double_t DeltaY = 1.2;

 
  for(int j=0;j<NN;j++){
  
  p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j])/DeltaY;
  p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j])/DeltaY;
  p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j])/DeltaY;
  
  }


  TGraphAsymmErrors *Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->SetMarkerStyle(22);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->SetMarkerColor(8);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->SetMarkerSize(1.6);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetRangeUser(0.001,1000.0);
  
  TAxis *Xaxis1 = Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,22.0);
   

  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis()->CenterTitle();
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->CenterTitle();

  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt;
  return OutGraph;
  
}



TGraphAsymmErrors *Data_ATLAS_D2NDPtDy_PromptJPsi_Y0025_Pt()
{
  //
  const int NN = 22;

  // X value (pT)
  Double_t p8319_d1x1y1_xval[NN] = {0.0};
  Double_t p8319_d1x1y1_xvallow[NN] = {8.00, 8.50, 9.00, 9.50, 10.00, 10.50, 11.00, 11.50, 12.00, 13.00, 14.00, 15.00, 16.00, 17.00, 
				       18.00, 20.00, 22.00, 24.00, 26.00, 30.00, 40.00, 60.00};
  Double_t p8319_d1x1y1_xvalhigh[NN] = {8.50, 9.00, 9.50, 10.00, 10.50, 11.00, 11.50, 12.00, 13.00, 14.00, 15.00, 16.00, 17.00, 18.00, 
					20.00, 22.00, 24.00, 26.00, 30.00, 40.00, 60.00, 100.00};
  
  Double_t Exp[NN]={1.0,1.0,1.0,1.0,1.0,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.01,0.01,0.01,0.01,0.01,0.001,0.001,0.001,0.0001,0.000001};


  // Y Value (B*dSigma/dpTdy)  
  Double_t p8319_d1x1y1_yval[NN] = {3.120, 2.526, 1.903, 1.465, 1.106, 8.471, 6.552, 5.117, 3.546, 2.315, 1.513, 1.039, 7.230, 5.171, 3.326, 
				    1.871, 1.110, 6.976, 3.690, 1.198, 1.500, 9.043};
  
  Double_t p8319_d1x1y1_ystatminus[NN] = {0.024, 0.016, 0.010, 0.008, 0.006, 0.053, 0.040, 0.037, 0.018, 0.014, 0.011, 0.009, 0.073, 0.062, 0.034, 
					  0.025, 0.019, 0.147, 0.078, 0.025, 0.066, 1.216};
  Double_t p8319_d1x1y1_ystatplus[NN] = {0.024, 0.016, 0.010, 0.008, 0.006, 0.053, 0.040, 0.037, 0.018, 0.014, 0.011, 0.009, 0.073, 0.062, 0.034, 
					 0.025, 0.019, 0.147, 0.078, 0.025, 0.066, 1.216};
  
  Double_t p8319_d1x1y1_ysystminus[NN] = {0.242, 0.170, 0.119, 0.089, 0.065, 0.487, 0.371, 0.280, 0.177, 0.121, 0.076, 0.055, 0.383, 0.279, 0.187, 0.107, 0.066, 
					   0.459, 0.263, 0.105, 0.216, 3.121};
  Double_t p8319_d1x1y1_ysystplus[NN] = {0.242, 0.170, 0.119, 0.089, 0.065, 0.487, 0.371, 0.280, 0.177, 0.121, 0.076, 0.055, 0.383, 0.279, 0.187, 0.107, 0.066, 0.459, 
					  0.263, 0.105, 0.216, 3.121};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] =  {0.0};

  Double_t p8319_d1x1y1_xerrminus[NN]={0.0};
  Double_t p8319_d1x1y1_xerrplus[NN]={0.0};


  Double_t pbTonb =1.0;
  Double_t DeltaY = 1.0;

for(int j=0;j<NN;j++){
  
  p8319_d1x1y1_xval[j] = 0.5*(p8319_d1x1y1_xvallow[j] + p8319_d1x1y1_xvalhigh[j]);  
  
  p8319_d1x1y1_yval[j] = p8319_d1x1y1_yval[j]*Exp[j];
  p8319_d1x1y1_ystatminus[j]= p8319_d1x1y1_ystatminus[j]*Exp[j];
  p8319_d1x1y1_ystatplus[j] = p8319_d1x1y1_ystatplus[j]*Exp[j]; 
  p8319_d1x1y1_ysystminus[j]=p8319_d1x1y1_ysystminus[j]*Exp[j];
  p8319_d1x1y1_ysystplus[j]=p8319_d1x1y1_ysystplus[j]*Exp[j];


  p8319_d1x1y1_xerrminus[j] = p8319_d1x1y1_xval[j] - p8319_d1x1y1_xvallow[j]; 
  p8319_d1x1y1_xerrplus[j] = p8319_d1x1y1_xvalhigh[j]-p8319_d1x1y1_xval[j];


  p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j]) + (p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
  p8319_d1x1y1_yerrplus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j]) + (p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
  
  p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_ystatminus[j]= (p8319_d1x1y1_ystatminus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_ystatplus[j]=(p8319_d1x1y1_ystatplus[j]*pbTonb)/DeltaY;
  }



  TGraphAsymmErrors *Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->SetMarkerStyle(34);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->SetMarkerColor(6);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->SetMarkerSize(1.6);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  
  TAxis *Xaxis1 = Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,100.0);
   

  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetXaxis()->CenterTitle();
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetYaxis()->CenterTitle();

  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt;
  return OutGraph;
  
}

//================ adding here 
TGraphAsymmErrors *Data_ATLAS_8TeV_D2NDPtDy_PromptJPsi_Y0025_Pt()
{
  //
  const int NN = 24;

  // X value (pT)
  Double_t p8319_d1x1y1_xval[NN] = {0.0};
  Double_t p8319_d1x1y1_xvallow[NN] = {8.00, 8.50, 9.00, 9.50, 10.00, 10.50, 11.00, 11.50, 12.00, 12.50, 13.00, 14.00, 15.00, 16.00, 17.00, 18.00, 
				       20.00, 22.00, 24.00, 26.00, 30.00, 35.00, 40.00, 60.00};
  Double_t p8319_d1x1y1_xvalhigh[NN] = {8.50, 9.00, 9.50, 10.00, 10.50, 11.00, 11.50, 12.00, 12.50, 13.00, 14.00, 15.00, 16.00, 17.00, 18.00, 20.00, 
					22.00, 24.00, 26.00, 30.00, 35.00, 40.00, 60.00, 110.00};
  
  Double_t Exp[NN]={1.0,1.0,1.0,1.0,1.0,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.01,0.01,0.01,0.01,0.01,0.001,0.001,0.001,0.0001,0.0001,0.00001};


  // Y Value (B*dSigma/dpTdy)  
  Double_t p8319_d1x1y1_yval[NN] = {3.249, 2.594, 1.997, 1.491, 1.135, 8.753, 6.843, 5.386, 4.291, 3.446, 2.536, 1.728, 1.213, 8.658, 6.268, 
				    4.095, 2.380, 1.440, 9.095, 4.966, 2.201, 9.747, 2.221, 1.147};
  Double_t p8319_d1x1y1_ystatminus[NN] = {0.008, 0.005, 0.003, 0.003, 0.002, 0.017, 0.014, 0.012, 0.010, 0.009, 0.005, 0.004, 0.004, 0.030, 
					  0.025, 0.014, 0.011, 0.008, 0.067, 0.035, 0.021, 0.139, 0.034, 0.051};
  Double_t p8319_d1x1y1_ystatplus[NN] = {0.008, 0.005, 0.003, 0.003, 0.002, 0.017, 0.014, 0.012, 0.010, 0.009, 0.005, 0.004, 0.004, 0.030, 
					 0.025, 0.014, 0.011, 0.008, 0.067, 0.035, 0.021, 0.139, 0.034, 0.051};
  
  Double_t p8319_d1x1y1_ysystminus[NN] = {0.617, 0.434, 0.300, 0.211, 0.145, 0.990, 0.704, 0.515, 0.385, 0.296, 0.204, 0.128, 0.083, 0.570, 
					  0.401, 0.245, 0.131, 0.073, 0.443, 0.236, 0.105, 0.515, 0.165, 0.223};
  Double_t p8319_d1x1y1_ysystplus[NN] = {0.617, 0.434, 0.300, 0.211, 0.145, 0.990, 0.704, 0.515, 0.385, 0.296, 0.204, 0.128, 0.083, 0.570, 
					 0.401, 0.245, 0.131, 0.073, 0.443, 0.236, 0.105, 0.515, 0.165, 0.223};

  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] =  {0.0};

  Double_t p8319_d1x1y1_xerrminus[NN]={0.0};
  Double_t p8319_d1x1y1_xerrplus[NN]={0.0};


  Double_t pbTonb =1.0;
  Double_t DeltaY = 1.0;

for(int j=0;j<NN;j++){
  
  p8319_d1x1y1_xval[j] = 0.5*(p8319_d1x1y1_xvallow[j] + p8319_d1x1y1_xvalhigh[j]);  
  
  p8319_d1x1y1_yval[j] = p8319_d1x1y1_yval[j]*Exp[j];
  p8319_d1x1y1_ystatminus[j]= p8319_d1x1y1_ystatminus[j]*Exp[j];
  p8319_d1x1y1_ystatplus[j] = p8319_d1x1y1_ystatplus[j]*Exp[j]; 
  p8319_d1x1y1_ysystminus[j]=p8319_d1x1y1_ysystminus[j]*Exp[j];
  p8319_d1x1y1_ysystplus[j]=p8319_d1x1y1_ysystplus[j]*Exp[j];


  p8319_d1x1y1_xerrminus[j] = p8319_d1x1y1_xval[j] - p8319_d1x1y1_xvallow[j]; 
  p8319_d1x1y1_xerrplus[j] = p8319_d1x1y1_xvalhigh[j]-p8319_d1x1y1_xval[j];


  p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatminus[j]*p8319_d1x1y1_ystatminus[j]) + (p8319_d1x1y1_ysystminus[j]*p8319_d1x1y1_ysystminus[j]));
  p8319_d1x1y1_yerrplus[j] = TMath::Sqrt( (p8319_d1x1y1_ystatplus[j]*p8319_d1x1y1_ystatplus[j]) + (p8319_d1x1y1_ysystplus[j]*p8319_d1x1y1_ysystplus[j]));
  
  p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_ystatminus[j]= (p8319_d1x1y1_ystatminus[j]*pbTonb)/DeltaY;
  p8319_d1x1y1_ystatplus[j]=(p8319_d1x1y1_ystatplus[j]*pbTonb)/DeltaY;
  }



  TGraphAsymmErrors *Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->SetMarkerStyle(25);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->SetMarkerColor(6);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->SetMarkerSize(1.6);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetYaxis()->SetRangeUser(0.0000001,100.0);
  
  TAxis *Xaxis1 = Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,120.0);
   
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetXaxis()->CenterTitle();
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetYaxis()->CenterTitle();

  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_ATLAS_D2NDPtDy_PromptJPsi_0025_Pt;
  return OutGraph;
  
}


TGraphAsymmErrors *Data_LHCb_D2NDPtDy_RootS7TeV_PromptJPsi_Y2035_Pt()
{

  //https://inspirehep.net/record/891233/export/hlxu

  const int NN = 14;
  // X value (pT)
  Double_t p8319_d1x1y1_xval[NN] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5,9.5, 10.5, 11.5, 12.5, 13.5};
  Double_t p8319_d1x1y1_xerrminus[NN]={0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};
  Double_t p8319_d1x1y1_xerrplus[NN]={0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5};

  
  Double_t p8319_d1x1y1_yval[NN] ={0.0};
  Double_t p8319_d1x1y1_yerrminus[NN] = {0.0};
  Double_t p8319_d1x1y1_yerrplus[NN] =  {0.0};






  // Y Value (dSigma/dpTdy)  [2.0-2.5]
  Double_t Deltay_1 = 0.5;
  Double_t p8319_d1x1y1_yval_1[NN] = {1091.0, 1495.0, 1225.0, 777.0, 424.0, 230.0, 116.0, 64.0, 37.0,19.3, 11.6, 6.7, 4.6, 2.9};
  Double_t p8319_d1x1y1_yerr_1[NN] = {276.9693123795486, 346.08813906286935, 196.27786426390523, 112.5433249908674, 60.4648658313239, 
				      32.55764119219941, 16.278820596099706, 8.602325267042627, 5.196152422706632, 2.7386127875258306, 
				      1.6093476939431082, 1.004987562112089, 0.7, 0.5099019513592785};
  


 // Y Value (dSigma/dpTdy)  [2.5-3.0]
  Double_t Deltay_2 = 0.5;
  Double_t p8319_d1x1y1_yval_2[NN] = {844.0, 1490.0, 1214.0, 719.0, 392.0, 206.0, 104.0, 57.0, 31.0, 17.4, 9.8, 5.9, 3.5, 2.6};
  Double_t p8319_d1x1y1_yerr_2[NN] = {173.72104075212076, 201.1815100847988, 162.0401184892186, 96.87620966986684, 53.45091205957107, 
				      28.231188426986208, 14.594519519326424, 7.681145747868608, 4.242640687119285, 2.362202362203543, 
				      1.3638181696985856, 0.8602325267042628, 0.5477225575051661, 0.37416573867739417};

// Y Value (dSigma/dpTdy)  [3.0-3.5]
  Double_t Deltay_3 = 0.5;
  Double_t p8319_d1x1y1_yval_3[NN] = {749.0, 1376.0, 1053.0, 611.0, 325.0, 167.0, 82.0, 44.0, 23.0, 12.6, 7.8, 4.5, 2.9, 1.3};
  Double_t p8319_d1x1y1_yerr_3[NN] = {109.38921336219582, 184.0217378463751, 140.46707799338606, 82.35289915965315, 44.034077712607996, 
				      22.64950330581225, 11.445523142259598, 6.164414002968976, 3.3166247903554, 1.74928556845359, 
				      1.0488088481701516, 0.6782329983125268, 0.45825756949558405, 0.30000000000000004};


  //BRJPsi2MuMu 

  Double_t DeltaY = 1.5;

  for(int j=0;j<NN;j++){

    p8319_d1x1y1_yval_1[j] = p8319_d1x1y1_yval_1[j]*Deltay_1;
    p8319_d1x1y1_yerr_1[j]= p8319_d1x1y1_yerr_1[j]*Deltay_1;

    p8319_d1x1y1_yval_2[j] = p8319_d1x1y1_yval_2[j]*Deltay_2;
    p8319_d1x1y1_yerr_2[j]= p8319_d1x1y1_yerr_2[j]*Deltay_2;

    p8319_d1x1y1_yval_3[j] = p8319_d1x1y1_yval_3[j]*Deltay_3;
    p8319_d1x1y1_yerr_3[j]= p8319_d1x1y1_yerr_3[j]*Deltay_3;

    p8319_d1x1y1_yval[j]= p8319_d1x1y1_yval_1[j] + p8319_d1x1y1_yval_2[j] + p8319_d1x1y1_yval_3[j];
    p8319_d1x1y1_yerrminus[j] = TMath::Sqrt( (p8319_d1x1y1_yerr_1[j]*p8319_d1x1y1_yerr_1[j]) 
					     + (p8319_d1x1y1_yerr_2[j]*p8319_d1x1y1_yerr_2[j]) + (p8319_d1x1y1_yerr_3[j]*p8319_d1x1y1_yerr_3[j])); 
    p8319_d1x1y1_yerrplus[j] = p8319_d1x1y1_yerrminus[j];

    p8319_d1x1y1_yval[j]= (p8319_d1x1y1_yval[j]/DeltaY)*BRJPsi2MuMu;
    p8319_d1x1y1_yerrminus[j] =(p8319_d1x1y1_yerrminus[j]/DeltaY)*BRJPsi2MuMu;
    p8319_d1x1y1_yerrplus[j] = (p8319_d1x1y1_yerrplus[j]/DeltaY)*BRJPsi2MuMu;

    
  }
  //==================================== BR*D2Sigma/DPt*DY ===============================================================//
 
  TGraphAsymmErrors *Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->SetMarkerStyle(20);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->SetMarkerColor(8);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->SetMarkerSize(1.6);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->GetYaxis()->SetRangeUser(0.001,100000.0);
  
  TAxis *Xaxis1 = Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,20.0);
   

  Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->GetXaxis()->CenterTitle();
  Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->GetYaxis()->CenterTitle();

  Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_LHCb_D2NDPtDy_PromptJPsi_2035_Pt;
  return OutGraph;
  
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
  
    p8319_d1x1y1_yval[j] = (BRJPsi2MuMu*p8319_d1x1y1_yval[j]*pbTonb)/DeltaY;
    p8319_d1x1y1_yerrminus[j]= (BRJPsi2MuMu*p8319_d1x1y1_yerrminus[j]*pbTonb)/DeltaY;
    p8319_d1x1y1_yerrplus[j]=(BRJPsi2MuMu*p8319_d1x1y1_yerrplus[j]*pbTonb)/DeltaY;
    
  }


  TGraphAsymmErrors *Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->SetMarkerStyle(22);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->SetMarkerColor(8);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->SetMarkerSize(1.6);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->GetYaxis()->SetRangeUser(0.001,10000.0);
  
  TAxis *Xaxis1 = Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,20.0);
   
  Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->GetXaxis()->CenterTitle();
  Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->GetYaxis()->CenterTitle();

  Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_LHCb_D2NDPtDy_PromptJPsi_2045_Pt;
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
  



  TGraphAsymmErrors *OutGraph= new TGraphAsymmErrors();

  OutGraph = SGraph;

  OutGraph->SetLineColor(InGraph->GetLineColor());
  OutGraph->SetLineStyle(InGraph->GetLineStyle());
  OutGraph->SetLineWidth(InGraph->GetLineWidth());

  OutGraph->SetMarkerColor(InGraph->GetMarkerColor());
  OutGraph->SetMarkerStyle(InGraph->GetMarkerStyle());
  OutGraph->SetMarkerSize(InGraph->GetMarkerSize());


  return OutGraph;





}

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

//const Double_t mC = 1.4;
const Double_t mC = 1.6;
//const Double_t mC = 1.8;


//=================== Fitted LDMEs ==================================//
//========= Our Values of fitted Psi(2S) LDME =========//
Double_t Psi2S_LDME_3S1_1 = 1.0;  
Double_t Psi2S_LDME_3S1_8 = 0.00362;
Double_t Psi2S_LDME_1S0_8 = 0.022804;
//========= Our Values of fitted Chic LDME =========//
Double_t Chic0_LDME_3P0_1 = 1.0;
Double_t Chic0_LDME_3S1_8 = 0.011118;

Double_t Chic1_LDME_3P1_1 = 1.0;
Double_t Chic1_LDME_3S1_8 = 0.011118;

Double_t Chic2_LDME_3P2_1 = 1.0;
Double_t Chic2_LDME_3S1_8 = 0.011118;
//========= Our Values of fitted Jsi LDME =========//
Double_t JPsi_LDME_3S1_1 = 1.0;  
Double_t JPsi_LDME_3S1_8 = 0.002055;
Double_t JPsi_LDME_1S0_8 = 0.06384;



/*
//=================== Fitted LDMEs ==================================//
//========= Our Values of fitted Jsi LDME =========//
Double_t JPsi_LDME_3S1_1 = 1.0;  
Double_t JPsi_LDME_1S0_8 = 0.06296;
Double_t JPsi_LDME_3S1_8 = 0.003168;
Double_t JPsi_LDME_3P0_8 = mC*mC*JPsi_LDME_1S0_8;
Double_t JPsi_LDME_3P1_8 = 3.0*JPsi_LDME_3P0_8;
Double_t JPsi_LDME_3P2_8 = 5.0*JPsi_LDME_3P0_8;
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
*/










/*
//=================== Fitted LDMEs ==================================//
//========= Our Values of fitted Jsi LDME =========//
Double_t JPsi_LDME_3S1_1 = 1.0;  
Double_t JPsi_LDME_1S0_8 = 0.018;
Double_t JPsi_LDME_3S1_8 = 0.0013;
Double_t JPsi_LDME_3P0_8 = mC*mC*JPsi_LDME_1S0_8;
Double_t JPsi_LDME_3P1_8 = 3.0*JPsi_LDME_3P0_8;
Double_t JPsi_LDME_3P2_8 = 5.0*JPsi_LDME_3P0_8;


//========= Our Values of fitted Psi(2S) LDME =========//
Double_t Psi2S_LDME_3S1_1 = 1.0;  
Double_t Psi2S_LDME_1S0_8 = 0.0080;
Double_t Psi2S_LDME_3S1_8 = 0.0033;
Double_t Psi2S_LDME_3P0_8 = mC*mC*Psi2S_LDME_1S0_8;
Double_t Psi2S_LDME_3P1_8 = 3.0*Psi2S_LDME_3P0_8;
Double_t Psi2S_LDME_3P2_8 = 5.0*Psi2S_LDME_3P0_8;
//========= Our Values of fitted Chic LDME =========//
Double_t Chic0_LDME_3P0_1 = 1.0;
Double_t Chic0_LDME_3S1_8 = 0.00187;

Double_t Chic1_LDME_3P1_1 = 1.0;
Double_t Chic1_LDME_3S1_8 = Chic0_LDME_3S1_8;

Double_t Chic2_LDME_3P2_1 = 1.0;
Double_t Chic2_LDME_3S1_8 = Chic0_LDME_3S1_8;
*/


//=========================== BR =================//
Double_t BR_JPsiToMuMu = 0.0593;
Double_t BR_Psi2SToMuMu = 0.0078;
Double_t BR_Psi2SToJPsi = 0.595;
Double_t BR_ChiC0ToJPsi = 0.0116;
Double_t BR_ChiC1ToJPsi = 0.344;
Double_t BR_ChiC2ToJPsi = 0.195;


//===================================== All the root Files 13 TeV =======================================//
Int_t Is5TeV =0;
TFile *file_LHCb_2045_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/13TeV/LHCb/JPsiCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/13TeV/LHCb/Psi2SCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/13TeV/LHCb/Chic0_1PCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/13TeV/LHCb/Chic1_1PCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/13TeV/LHCb/Chic2_1PCrossSection.root","R");

TFile *file_ATLAS_2525_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/13TeV/ATLAS/Nom/JPsiCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/13TeV/ATLAS/Nom/Psi2SCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/13TeV/ATLAS/Nom/Chic0_1PCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/13TeV/ATLAS/Nom/Chic1_1PCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/13TeV/ATLAS/Nom/Chic2_1PCrossSection.root","R");

TFile *file_ALICE_2045_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/13TeV/ALICE/Nom/JPsiCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/13TeV/ALICE/Nom/Psi2SCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/13TeV/ALICE/Nom/Chic0_1PCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/13TeV/ALICE/Nom/Chic1_1PCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/13TeV/ALICE/Nom/Chic2_1PCrossSection.root","R");






/*
//===================================== All the root Files 5 TeV =======================================//
Int_t Is5TeV = 1;
TFile *file_LHCb_2045_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/5TeV/LHCb/JPsiCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/5TeV/LHCb/Psi2SCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/5TeV/LHCb/Chic0_1PCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/5TeV/LHCb/Chic1_1PCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/5TeV/LHCb/Chic2_1PCrossSection.root","R");

TFile *file_ATLAS_2525_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/5TeV/ATLAS/Nom/JPsiCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/5TeV/ATLAS/Nom/Psi2SCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/5TeV/ATLAS/Nom/Chic0_1PCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/5TeV/ATLAS/Nom/Chic1_1PCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/5TeV/ATLAS/Nom/Chic2_1PCrossSection.root","R");

TFile *file_ALICE_2045_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/5TeV/ALICE/Nom/JPsiCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/5TeV/ALICE/Nom/Psi2SCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/5TeV/ALICE/Nom/Chic0_1PCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/5TeV/ALICE/Nom/Chic1_1PCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/5TeV/ALICE/Nom/Chic2_1PCrossSection.root","R");
*/

/*
//===================================== All the root Files 1.8 TeV =======================================//
Int_t Is5TeV = 2;
TFile *file_LHCb_2045_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/18TeV/LHCb/JPsiCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/18TeV/LHCb/Psi2SCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/18TeV/LHCb/Chic0_1PCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/18TeV/LHCb/Chic1_1PCrossSection.root","R");
TFile *file_LHCb_2045_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/18TeV/LHCb/Chic2_1PCrossSection.root","R");

TFile *file_ATLAS_2525_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/18TeV/ATLAS/Nom/JPsiCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/18TeV/ATLAS/Nom/Psi2SCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/18TeV/ATLAS/Nom/Chic0_1PCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/18TeV/ATLAS/Nom/Chic1_1PCrossSection.root","R");
TFile *file_ATLAS_2525_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/18TeV/ATLAS/Nom/Chic2_1PCrossSection.root","R");

TFile *file_ALICE_2045_RootS13TeV_JPsiCrossSection =  new TFile("rootFiles/18TeV/ALICE/Nom/JPsiCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Psi2SCrossSection =  new TFile("rootFiles/18TeV/ALICE/Nom/Psi2SCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Chic0CrossSection =  new TFile("rootFiles/18TeV/ALICE/Nom/Chic0_1PCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Chic1CrossSection =  new TFile("rootFiles/18TeV/ALICE/Nom/Chic1_1PCrossSection.root","R");
TFile *file_ALICE_2045_RootS13TeV_Chic2CrossSection =  new TFile("rootFiles/18TeV/ALICE/Nom/Chic2_1PCrossSection.root","R");
*/





//====================================================================================================//
//================================= LHCb 13TeV y[2.0-4.5] ===========================================//
//==================================================================================================//

//==================  JPsi Direct =========================================//

//================ Get All the graphs ===============================//
TGraph *grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");

//==================  Psi2S Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit");
TGraph *grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit");
TGraph *grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");
TGraph *grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit");
TGraph *grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit");
TGraph *grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit");

//==================  Chic0 Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grLHCb_2045_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit");
TGraph *grLHCb_2045_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//==================  Chic1 Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grLHCb_2045_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit");
TGraph *grLHCb_2045_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");


//==================  Chic2 Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grLHCb_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit");
TGraph *grLHCb_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_LHCb_2045_RootS13TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit");



//====================================================================================================//
//================================= ATLAS 13TeV y[-2.5 - 2.5] =======================================//
//==================================================================================================//

//==================  JPsi Direct =========================================//

//================ Get All the graphs ===============================//

TGraph *grATLAS_2525_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_JPsi_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit_ATLAS");

//==================  Psi2S Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit_ATLAS");

//==================  Chic0 Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grATLAS_2525_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ATLAS");


//==================  Chic1 Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grATLAS_2525_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ATLAS");


//==================  Chic2 Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grATLAS_2525_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit_ATLAS");
TGraph *grATLAS_2525_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ATLAS_2525_RootS13TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ATLAS");



//====================================================================================================//
//================================= ALICE 13TeV y[2.0 - 4.5] =======================================//
//==================================================================================================//

//==================  JPsi Direct =========================================//

//================ Get All the graphs ===============================//
TGraph *grALICE_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_JPsiCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit_ALICE");
//==================  Psi2S Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_1_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_1S0_8_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P0_8_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P1_8_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Psi2SCrossSection->Get("grDSigmaDPtDY_Pt_3P2_8_Fit_ALICE");
//==================  Chic0 Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grALICE_2045_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3P0_1_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Chic0CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ALICE");


//==================  Chic1 Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grALICE_2045_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3P1_1_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Chic1CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ALICE");


//==================  Chic2 Feed =========================================//

//================ Get All the graphs ===============================//
TGraph *grALICE_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3P2_1_Fit_ALICE");
TGraph *grALICE_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit =(TGraph*)file_ALICE_2045_RootS13TeV_Chic2CrossSection->Get("grDSigmaDPtDY_Pt_3S1_8_Fit_ALICE");



TGraphAsymmErrors *Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt();


TGraph *Add_DirectJPsi_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3);
TGraph *Add_FeedPsi2S_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3);
TGraph *Add_FeedChic0_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2);
TGraph *Add_FeedChic1_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2);
TGraph *Add_FeedChic2_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2);


TGraph *Add_PromptJPsi_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3,TGraph *InGraph4, TGraph *InGraph5);
TGraph *Add_DirectPsi2S_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3);




TGraphErrors *RatioGraph(TGraph *GraphIn1, TGraph *GraphIn2);
Double_t RError(Double_t A, Double_t eA, Double_t B, Double_t eB);
TGraph *CutGraph(TGraph *InGraph, Double_t XMin);




Double_t Scale_Pt(Double_t JPsiPt);
Double_t Scale_Chi_Pt(Double_t JPsiPt, Int_t Par);

Double_t Scale_Pt_ChiToJPsi(Double_t ChiPt, Int_t Par);
Double_t Scale_Pt_Psi2SToJPsi(Double_t Psi2SPt);

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
  
  TFile *Out_File;
  if(Is5TeV==0){Out_File =  new TFile("Out_JPsiCrossSection_13TeV.root","ReCreate");}
  if(Is5TeV==1){Out_File =  new TFile("Out_JPsiCrossSection_5TeV.root","ReCreate");}
  if(Is5TeV==2){Out_File =  new TFile("Out_JPsiCrossSection_18TeV.root","ReCreate");}
  /*
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== GETTING LHCb 13 TeV DATA DATA ==========================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
  TGraphAsymmErrors *grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt=new TGraphAsymmErrors();
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt=Data_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt();
  
 

  TGraph *Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi =Add_DirectJPsi_DSigmaDPt(grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_1_Fit,grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_1S0_8_Fit,
							    grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_8_Fit,grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P0_8_Fit,
							    grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P1_8_Fit,grLHCb_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3P2_8_Fit);


 
  TGraph *Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S =Add_FeedPsi2S_DSigmaDPt(grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit,grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit,
							    grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit,grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P0_8_Fit,
							    grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P1_8_Fit,grLHCb_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3P2_8_Fit);






  TGraph *Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0 =Add_FeedChic0_DSigmaDPt(grLHCb_2045_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit,grLHCb_2045_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit);

  TGraph *Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1 =Add_FeedChic1_DSigmaDPt(grLHCb_2045_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit,grLHCb_2045_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit);

  TGraph *Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2 =Add_FeedChic2_DSigmaDPt(grLHCb_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit,grLHCb_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit);



  TGraph *Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi= Add_PromptJPsi_DSigmaDPt(Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi,Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S,
											 Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0,Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1,
											 Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2);







  TLegend *lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045 = new TLegend(0.37,0.67,0.85,0.93);
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetBorderSize(0);
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetFillStyle(0);
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetFillColor(0);
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetTextSize(0.04);




  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->AddEntry(grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt,"LHCb Prompt J/#psi, 2.0 #leq y #leq 4.5","P");
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->AddEntry(Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi,"Prompt J/#psi","L");
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->AddEntry(Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi,"Direct J/#psi","L");
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->AddEntry(Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S,"J/#psi from #psi(2S)","L");
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->AddEntry(Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0,"J/#psi from #chi_{c0}","L");
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->AddEntry(Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1,"J/#psi from #chi_{c1}","L");
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->AddEntry(Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2,"J/#psi from #chi_{c2}","L");
  

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  grfData_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_Pt->Draw("zAP");
  Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi->Draw("sameL");
  Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S->Draw("sameL");
  Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0->Draw("sameL");
  Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1->Draw("sameL");
  Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2->Draw("sameL");
  Out_grLHCb_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->Draw("sameL");
  lgd_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->Draw("same");
  gPad->Update();
  gPad->SaveAs("Plots/Fig_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045.pdf");
  gPad->SaveAs("Plots/Fig_LHCb_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045.png");
*/


  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== GETTING ATLAS 13 TeV prediction ==========================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
 

  TGraph *Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi =Add_DirectJPsi_DSigmaDPt(grATLAS_2525_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_1_Fit,grATLAS_2525_RootS13TeV_JPsi_DSigmaDPtDY_Pt_1S0_8_Fit,
							    grATLAS_2525_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_8_Fit);


 
  TGraph *Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S =Add_FeedPsi2S_DSigmaDPt(grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit,grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit,
							    grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit);




  TGraph *Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0 =Add_FeedChic0_DSigmaDPt(grATLAS_2525_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit,grATLAS_2525_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit);

  TGraph *Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1 =Add_FeedChic1_DSigmaDPt(grATLAS_2525_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit,grATLAS_2525_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit);

  TGraph *Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2 =Add_FeedChic2_DSigmaDPt(grATLAS_2525_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit,grATLAS_2525_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit);



  TGraph *Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi= Add_PromptJPsi_DSigmaDPt(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi,Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S,
											 Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0,Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1,
											 Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2);



  Double_t GraphMin_ATLAS =5.0;

  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi=CutGraph(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi,GraphMin_ATLAS);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi=CutGraph(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi,GraphMin_ATLAS);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S=CutGraph(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S,GraphMin_ATLAS);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0=CutGraph(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0,GraphMin_ATLAS);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1=CutGraph(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1,GraphMin_ATLAS);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2=CutGraph(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2,GraphMin_ATLAS);

  TLegend *lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045 = new TLegend(0.25,0.88,0.91,0.91);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetBorderSize(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetFillStyle(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetFillColor(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetTextSize(0.04);
  if(Is5TeV ==0){lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetHeader("pp #surds=13 TeV, Prompt J/#psi, |y^{J/#psi}| #leq 2.5");}
  if(Is5TeV ==1){lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetHeader("pp #surds=5 TeV, Prompt J/#psi, |y^{J/#psi}| #leq 2.5");}
  if(Is5TeV ==2){lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetHeader("pp #surds=1.8 TeV, Prompt J/#psi, |y^{J/#psi}| #leq 2.5");}

  TLegend *lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1 = new TLegend(0.51,0.47,0.88,0.87);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->SetBorderSize(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->SetFillStyle(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->SetFillColor(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->SetTextSize(0.04);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi,"Prompt J/#psi","L");
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi,"Direct J/#psi","L");
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S,"J/#psi from #psi(2S)","L");
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0,"J/#psi from #chi_{c0}","L");
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1,"J/#psi from #chi_{c1}","L");
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2,"J/#psi from #chi_{c2}","L");
  

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetYaxis()->SetRangeUser(0.000001,100);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetXaxis()->SetRangeUser(0.0,100);

  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->SetLineWidth(4);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetYaxis()->SetTitleOffset(1.6);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  

  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->Draw("AL");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi->Draw("sameL");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S->Draw("sameL");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0->Draw("sameL");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1->Draw("sameL");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2->Draw("sameL");
 
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->Draw("same");
  lgd_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(a)");
  gPad->Update();
  if(Is5TeV ==0){
  gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2525.pdf");
  gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS13TeV_PromptJPsi_Y2525.png");
  }

  if(Is5TeV ==1){
  gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS5TeV_PromptJPsi_Y2525.pdf");
  gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS5TeV_PromptJPsi_Y2525.png");
  }

  if(Is5TeV ==2){
  gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS18TeV_PromptJPsi_Y2525.pdf");
  gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS18TeV_PromptJPsi_Y2525.png");
  }


  
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== GETTING ALICE 13 TeV prediction ==========================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  
 
  cout<<"1"<<endl;
  TGraph *Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi =Add_DirectJPsi_DSigmaDPt(grALICE_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_1_Fit,grALICE_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_1S0_8_Fit,
							    grALICE_2045_RootS13TeV_JPsi_DSigmaDPtDY_Pt_3S1_8_Fit);


  cout<<"2"<<endl;

 
  TGraph *Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S =Add_FeedPsi2S_DSigmaDPt(grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit,grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit,
							    grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit);



  cout<<"3"<<endl;


  TGraph *Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0 =Add_FeedChic0_DSigmaDPt(grALICE_2045_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3P0_1_Fit,grALICE_2045_RootS13TeV_Chic0_DSigmaDPtDY_Pt_3S1_8_Fit);
  cout<<"4"<<endl;
  TGraph *Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1 =Add_FeedChic1_DSigmaDPt(grALICE_2045_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3P1_1_Fit,grALICE_2045_RootS13TeV_Chic1_DSigmaDPtDY_Pt_3S1_8_Fit);
  cout<<"5"<<endl;
  


  cout<<"A"<<endl;
  cout<<grALICE_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit->GetN()<<endl;
  cout<<"B"<<endl;
  cout<<grALICE_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit->GetN()<<endl;
  cout<<"C"<<endl;


  TGraph *Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2 =Add_FeedChic2_DSigmaDPt(grALICE_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3P2_1_Fit,grALICE_2045_RootS13TeV_Chic2_DSigmaDPtDY_Pt_3S1_8_Fit);
  



  cout<<"6"<<endl;
  

  TGraph *Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi= Add_PromptJPsi_DSigmaDPt(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi,Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S,
											 Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0,Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1,
											 Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2);





  Double_t GraphMin_ALICE =5.0;

  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi=CutGraph(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi,GraphMin_ALICE);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi=CutGraph(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi,GraphMin_ALICE);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S=CutGraph(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S,GraphMin_ALICE);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0=CutGraph(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0,GraphMin_ALICE);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1=CutGraph(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1,GraphMin_ALICE);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2=CutGraph(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2,GraphMin_ALICE);


  TLegend *lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045 = new TLegend(0.20,0.89,0.83,0.93);
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetBorderSize(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetFillStyle(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetFillColor(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetTextSize(0.04);
  if(Is5TeV ==0){ lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetHeader("pp #surds=13 TeV,Prompt J/#psi, 2.0#leq y^{J/#psi} #leq4.5");}
  if(Is5TeV ==1){ lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetHeader("pp #surds=5 TeV,Prompt J/#psi, 2.0#leq y^{J/#psi} #leq4.5");}
  if(Is5TeV ==2){ lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->SetHeader("pp #surds=1.8 TeV,Prompt J/#psi, 2.0#leq y^{J/#psi} #leq4.5");}
  

  TLegend *lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1 = new TLegend(0.54,0.47,0.91,0.87);
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->SetBorderSize(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->SetFillStyle(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->SetFillColor(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->SetTextSize(0.04);
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi,"Prompt J/#psi","L");
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi,"Direct J/#psi","L");
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S,"J/#psi from #psi(2S)","L");
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0,"J/#psi from #chi_{c0}","L");
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1,"J/#psi from #chi_{c1}","L");
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->AddEntry(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2,"J/#psi from #chi_{c2}","L");
  

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetXaxis()->SetRangeUser(0.0,40);
  if(Is5TeV ==0)Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetYaxis()->SetRangeUser(0.00001,2000);
  if(Is5TeV ==1)Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetYaxis()->SetRangeUser(0.00001,200);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetYaxis()->SetTitleOffset(1.6);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->SetLineWidth(4);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi->Draw("AL");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectJPsi->Draw("sameL");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedPsi2S->Draw("sameL");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic0->Draw("sameL");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic1->Draw("sameL");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_FeedChic2->Draw("sameL");
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045->Draw("same");
  lgd_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(b)");
  gPad->Update();
  if(Is5TeV ==0){
  gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045.pdf");
  gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS13TeV_PromptJPsi_Y2045.png");
  }


 if(Is5TeV ==1){
  gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS5TeV_PromptJPsi_Y2045.pdf");
  gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS5TeV_PromptJPsi_Y2045.png");
  }

 if(Is5TeV ==2){
   gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS18TeV_PromptJPsi_Y2045.pdf");
   gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS18TeV_PromptJPsi_Y2045.png");
  }

  



  
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== GETTING Psi(2S) ATLAS 13 TeV prediction ================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;


  TGraph *Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S =Add_DirectPsi2S_DSigmaDPt(grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit,grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit,
											    grATLAS_2525_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit);




  TLegend *lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525 = new TLegend(0.19,0.88,0.91,0.94);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetBorderSize(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetFillStyle(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetFillColor(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetTextSize(0.04);
  
  if(Is5TeV ==0){lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetHeader("pp #surds=13 TeV, Prompt #psi(2S), |y^{#psi(2S)}| #leq 2.5");}
  if(Is5TeV ==1){lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetHeader("pp #surds=5 TeV, Prompt #psi(2S), |y^{#psi(2S)}| #leq 2.5");}
  if(Is5TeV ==2){lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetHeader("pp #surds=1.8 TeV, Prompt #psi(2S), |y^{#psi(2S)}| #leq 2.5");}
  



  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S=CutGraph(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S,5.0);


  TLegend *lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1 = new TLegend(0.57,0.80,0.88,0.86);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->SetBorderSize(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->SetFillStyle(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->SetFillColor(0);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->SetTextSize(0.04);
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->AddEntry(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S,"Total","L");


  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetYaxis()->SetTitleOffset(1.6);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetYaxis()->SetRangeUser(0.000001,10);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetXaxis()->SetRangeUser(0.0,100);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->SetLineColor(2);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->SetLineStyle(1);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->SetLineWidth(4);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->Draw("AL");
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->Draw("same");
  lgd_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(a)");
  gPad->Update(); 

  if(Is5TeV ==0){
    gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi_Y2525.pdf");
    gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi_Y2525.png");
  }

  if(Is5TeV ==1){
    gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS5TeV_DirectPsi_Y2525.pdf");
    gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS5TeV_DirectPsi_Y2525.png");
  }

  if(Is5TeV ==2){
    gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS18TeV_DirectPsi_Y2525.pdf");
    gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS18TeV_DirectPsi_Y2525.png");
  }

  
  
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<" ===================== GETTING Psi(2S) ALICE 13 TeV prediction ================="<<endl;
  cout<<" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;



  TGraph *Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S=Add_DirectPsi2S_DSigmaDPt(grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_1_Fit,grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_1S0_8_Fit,
											    grALICE_2045_RootS13TeV_Psi2S_DSigmaDPtDY_Pt_3S1_8_Fit);

    
  
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S=CutGraph(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S,5.0);

  
  TLegend *lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525 = new TLegend(0.20,0.87,0.90,0.92);
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetBorderSize(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetFillStyle(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetFillColor(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetTextSize(0.035);
  if(Is5TeV ==0){lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetHeader("pp #surds=13 TeV, Prompt #psi(2S), 2.0#leq y^{#psi(2S)} #leq4.5");}
  if(Is5TeV ==1){lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetHeader("pp #surds=5 TeV, Prompt #psi(2S), 2.0#leq y^{#psi(2S)} #leq4.5");}
  if(Is5TeV ==2){lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->SetHeader("pp #surds=1.8 TeV, Prompt #psi(2S), 2.0#leq y^{#psi(2S)} #leq4.5");}

  TLegend *lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1 = new TLegend(0.65,0.79,0.90,0.87);
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->SetBorderSize(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->SetFillStyle(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->SetFillColor(0);
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->SetTextSize(0.04);
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->AddEntry(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S,"Total","L");

  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->SetName("Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->SetTitle("Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S");

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetYaxis()->SetTitleOffset(1.6);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetXaxis()->SetRangeUser(0.0,40);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->GetYaxis()->SetRangeUser(0.00001,20);

  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->SetLineColor(2);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->SetLineStyle(1);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->SetLineWidth(4);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->Draw("AL");
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525->Draw("same");
  lgd_ALICE_D2NDPtDy_RootS13TeV_DirectPsi2S_Y2525_1->Draw("same");
  tb->DrawLatex(0.23,0.18,"(b)");
  gPad->Update();
  if(Is5TeV ==0){
    gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS13TeV_DirectPsi_Y2045.pdf");
    gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS13TeV_DirectPsi_Y2045.png");
  }

 if(Is5TeV ==1){
    gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS5TeV_DirectPsi_Y2045.pdf");
    gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS5TeV_DirectPsi_Y2045.png");
  }


 if(Is5TeV ==2){
    gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS18TeV_DirectPsi_Y2045.pdf");
    gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS18TeV_DirectPsi_Y2045.png");
  }






  //========================== Making Ratio Psi(2S)/JPsi ===========================//
  //  TGraphErrors *RatioGraph(TGraph *GraphIn1, TGraph *GraphIn2)


  TGraph *Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi = RatioGraph(Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S,Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi);
  

  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetName("Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetTitle("Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");

  TLegend *lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi = new TLegend(0.28,0.85,0.78,0.91);
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetBorderSize(0);
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetFillStyle(0);
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetFillColor(0);
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetTextSize(0.04);
  if(Is5TeV ==0){lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetHeader("pp #surds=13 TeV, |y| #leq 2.5");}
  if(Is5TeV ==1){lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetHeader("pp #surds=5 TeV, |y| #leq 2.5");}
  if(Is5TeV ==2){lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetHeader("pp #surds=1.8 TeV, |y| #leq 2.5");}

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLeftMargin(0.22);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetYaxis()->SetTitleOffset(1.8);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma^{#psi(2S)}}{dp_{T}dy}/B.#frac{d^{2}#sigma^{J/#psi}}{dp_{T}dy}");
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetYaxis()->SetRangeUser(0.0,0.1);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetXaxis()->SetRangeUser(0.0,70.0);

  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetLineColor(2);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetLineStyle(1);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetLineWidth(4);
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->Draw("AL");
  lgd_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->Draw("same");
  tb->DrawLatex(0.28,0.20,"(a)");
  //gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi_DirectJPsi_Y2525.pdf");
  //gPad->SaveAs("Plots/Fig_ATLAS_D2NDPtDy_RootS13TeV_DirectPsi_DirectJPsi_Y2525.png");



  TGraph *Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi = RatioGraph(Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S,Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptJPsi);
  
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetName("Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetTitle("Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi");

  TLegend *lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi = new TLegend(0.28,0.85,0.78,0.91);
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetBorderSize(0);
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetFillStyle(0);
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetFillColor(0);
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetTextSize(0.04);
  if(Is5TeV ==0){lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetHeader("pp #surds=13 TeV, 2.0 #leq y #leq 4.5");}
  if(Is5TeV ==1){lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetHeader("pp #surds=5 TeV, 2.0 #leq y #leq 4.5");}
  if(Is5TeV ==2){lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetHeader("pp #surds=1.8 TeV, 2.0 #leq y #leq 4.5");}

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLeftMargin(0.22);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetYaxis()->SetTitleOffset(1.8);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetYaxis()->SetTitle("B.#frac{d^{2}#sigma^{#psi(2S)}}{dp_{T}dy}/B.#frac{d^{2}#sigma^{J/#psi}}{dp_{T}dy}");
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetYaxis()->SetRangeUser(0.0,0.1);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->GetXaxis()->SetRangeUser(0.0,40.0);

  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetLineColor(2);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetLineStyle(1);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->SetLineWidth(4);
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->Draw("AL");
  lgd_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->Draw("same");
  tb->DrawLatex(0.28,0.20,"(b)");
  //gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS13TeV_DirectPsi_DirectJPsi_Y2045.pdf");
  //gPad->SaveAs("Plots/Fig_ALICE_D2NDPtDy_RootS13TeV_DirectPsi_DirectJPsi_Y2045.png");

  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_DirectPsi2S->Write();
  Out_grATLAS_2525_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->Write();
  Out_grALICE_2045_RootS13TeV_DSigmaDPtDY_Pt_PromptPsi2S_PromptJPsi->Write();
  Out_File->Write();

  


  return;





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
  
    p8319_d1x1y1_yval[j] = (p8319_d1x1y1_yval[j]*pbTonb* BR_JPsiToMuMu)/DeltaY;
    p8319_d1x1y1_yerrminus[j]= (p8319_d1x1y1_yerrminus[j]*pbTonb *BR_JPsiToMuMu)/DeltaY;
    p8319_d1x1y1_yerrplus[j]=(p8319_d1x1y1_yerrplus[j]*pbTonb *BR_JPsiToMuMu)/DeltaY;
    p8319_d1x1y1_ystatminus[j]= (p8319_d1x1y1_ystatminus[j]*pbTonb *BR_JPsiToMuMu)/DeltaY;
    p8319_d1x1y1_ystatplus[j]=(p8319_d1x1y1_ystatplus[j]*pbTonb *BR_JPsiToMuMu)/DeltaY;
  }


  TGraphAsymmErrors *Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt = new TGraphAsymmErrors(NN,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->SetMarkerStyle(20);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->SetMarkerColor(8);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->SetMarkerSize(1.6);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetRangeUser(0.001,300000.0);
  
  TAxis *Xaxis1 = Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,15.0);
   

  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  
  TGraphAsymmErrors *OutGraph;
  OutGraph = Grf_CDF_D2NDPtDy_PromptJPsi_0006_Pt;
  return OutGraph;
  
}





TGraph *Add_PromptJPsi_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3,TGraph *InGraph4, TGraph *InGraph5)
{
  
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx,yy;
    Double_t xx1,yy1;
    Double_t xx2,yy2;
    Double_t xx3,yy3;
    Double_t xx4,yy4;
    Double_t xx5,yy5;

    InGraph1->GetPoint(j,xx1,yy1);
    
    xx2 = xx1;
    xx3 = xx1;
    xx4 = xx1;
    xx5 = xx1;
    
    //xx2 = Scale_Pt(xx1);
    //xx3 = Scale_Chi_Pt(xx1,0);
    //xx4 = Scale_Chi_Pt(xx1,1);
    //xx5 = Scale_Chi_Pt(xx1,2);

    yy2 = InGraph2->Eval(xx2);
    yy3 = InGraph3->Eval(xx3);
    yy4 = InGraph4->Eval(xx4);
    yy5 = InGraph5->Eval(xx5);
   

    xx=xx1;
    yy=yy1+yy2+yy3+yy4+yy5;
    SGraph->SetPoint(j,xx,yy);  
    
  }

  SGraph->SetLineColor(2);
  SGraph->SetLineStyle(1);
  SGraph->SetLineWidth(2);

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;


}


TGraph *Add_DirectJPsi_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3)
{
  
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx,yy;
    Double_t xx1,yy1;
    Double_t xx2,yy2;
    Double_t xx3,yy3;
    Double_t xx4,yy4;
    Double_t xx5,yy5;
    Double_t xx6,yy6;

    Double_t Fac_1S0_8_To_3PJ_8 =3.0;

    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);
    InGraph3->GetPoint(j,xx3,yy3);
    
    //InGraph4->GetPoint(j,xx4,yy4);
    //InGraph5->GetPoint(j,xx5,yy5);
    //InGraph6->GetPoint(j,xx6,yy6);
   
    yy2 = yy2*Fac_1S0_8_To_3PJ_8;   
    
    yy1=yy1*JPsi_LDME_3S1_1;
    yy2=yy2*JPsi_LDME_1S0_8;
    yy3=yy3*JPsi_LDME_3S1_8;

    //yy4=yy4*JPsi_LDME_3P0_8;
    //yy5=yy5*JPsi_LDME_3P1_8;
    //yy6=yy6*JPsi_LDME_3P2_8;

    xx=xx1;
    yy=yy1+yy2+yy3;
    SGraph->SetPoint(j,xx,yy);  
    
  }

  SGraph->SetLineColor(4);
  SGraph->SetLineStyle(9);
  SGraph->SetLineWidth(2);
  

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;


}

TGraph *Add_FeedPsi2S_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3)
{
  
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx,yy;
    Double_t xx1,yy1;
    Double_t xx2,yy2;
    Double_t xx3,yy3;
    Double_t xx4,yy4;
    Double_t xx5,yy5;
    Double_t xx6,yy6;

    Double_t Fac_1S0_8_To_3PJ_8 =3.0;

    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);
    InGraph3->GetPoint(j,xx3,yy3);

    //InGraph4->GetPoint(j,xx4,yy4);
    //InGraph5->GetPoint(j,xx5,yy5);
    //InGraph6->GetPoint(j,xx6,yy6);
        
    yy2 = yy2*Fac_1S0_8_To_3PJ_8;   


    yy1=yy1*Psi2S_LDME_3S1_1;
    yy2=yy2*Psi2S_LDME_1S0_8;
    yy3=yy3*Psi2S_LDME_3S1_8;
    
    //yy4=yy4*Psi2S_LDME_3P0_8;
    //yy5=yy5*Psi2S_LDME_3P1_8;
    //yy6=yy6*Psi2S_LDME_3P2_8;
    
    xx=Scale_Pt_Psi2SToJPsi(xx1);
    //xx=xx1;

    yy=yy1+yy2+yy3;
    SGraph->SetPoint(j,xx,yy);  
    
  }

  SGraph->SetLineColor(6);
  SGraph->SetLineStyle(7);
  SGraph->SetLineWidth(2);

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;
}



TGraph *Add_FeedChic0_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2)
{
 
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx,yy;
    Double_t xx1,yy1;
    Double_t xx2,yy2;
 
    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);
        
    yy1=yy1*Chic0_LDME_3P0_1;
    yy2=yy2*Chic0_LDME_3S1_8;
        


    xx=Scale_Pt_ChiToJPsi(xx1,0);
    //xx=xx1;

    yy=yy1+yy2;
    SGraph->SetPoint(j,xx,yy);  
    
  }


  SGraph->SetLineColor(8);
  SGraph->SetLineStyle(2);
  SGraph->SetLineWidth(2);



  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;
}


TGraph *Add_FeedChic1_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2)
{
 
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx,yy;
    Double_t xx1,yy1;
    Double_t xx2,yy2;
 
    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);
        
    yy1=yy1*Chic1_LDME_3P1_1;
    yy2=yy2*Chic1_LDME_3S1_8;
        
    xx=Scale_Pt_ChiToJPsi(xx1,1);

    yy=yy1+yy2;
    SGraph->SetPoint(j,xx,yy);  
    
  }


  SGraph->SetLineColor(7);
  SGraph->SetLineStyle(6);
  SGraph->SetLineWidth(2);

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;
}


TGraph *Add_FeedChic2_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2)
{
 
  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx,yy;
    Double_t xx1,yy1;
    Double_t xx2,yy2;
 
    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);
        
    yy1=yy1*Chic2_LDME_3P2_1;
    yy2=yy2*Chic2_LDME_3S1_8;
        
    xx=Scale_Pt_ChiToJPsi(xx1,2);

    yy=yy1+yy2;
    SGraph->SetPoint(j,xx,yy);  
    
  }

  SGraph->SetLineColor(46);
  SGraph->SetLineStyle(3);
  SGraph->SetLineWidth(2);

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;
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



Double_t Scale_Pt_Psi2SToJPsi(Double_t Psi2SPt)
{
  Double_t JPsiPt;
  Double_t MM = 0.0;
  Double_t CC = 0.0;
  MM=1.154; CC = 0.1413;
  JPsiPt = (Psi2SPt - CC)/MM;
  return JPsiPt;
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



Double_t Scale_Pt_ChiToJPsi(Double_t ChiPt, Int_t Par)
{

  Double_t JPsiPt;
  Double_t MM = 0.0;
  Double_t CC = 0.0;
  if(Par ==0){MM=1.075; CC = 0.113;}
  if(Par ==1){MM=1.067; CC = 0.181;}
  if(Par ==2){MM=1.113; CC = 0.137;}
  JPsiPt = (ChiPt - CC)/MM;
  return JPsiPt;
}





TGraph *Add_DirectPsi2S_DSigmaDPt(TGraph *InGraph1, TGraph *InGraph2, TGraph *InGraph3)
{
  
  Double_t Fac = BR_Psi2SToMuMu/(BR_JPsiToMuMu*BR_Psi2SToJPsi);

  TGraph *SGraph = new TGraph; 
  
  for (int j=0; j < InGraph1->GetN();++j){

    Double_t xx,yy;
    Double_t xx1,yy1;
    Double_t xx2,yy2;
    Double_t xx3,yy3;
    Double_t Fac_1S0_8_to_3PJ_8 = 3.0;

    InGraph1->GetPoint(j,xx1,yy1);
    InGraph2->GetPoint(j,xx2,yy2);
    InGraph3->GetPoint(j,xx3,yy3);

    yy2 = Fac_1S0_8_to_3PJ_8*yy2; 
        
    yy1=yy1*Psi2S_LDME_3S1_1*Fac;
    yy2=yy2*Psi2S_LDME_1S0_8*Fac;
    yy3=yy3*Psi2S_LDME_3S1_8*Fac;

    
    

  xx=Scale_Pt_Psi2SToJPsi(xx1);
    //xx=xx1;

    yy=yy1+yy2+yy3;
    SGraph->SetPoint(j,xx,yy);  
    
  }

  SGraph->SetLineColor(6);
  SGraph->SetLineStyle(7);
  SGraph->SetLineWidth(2);

  TGraph *OutGraph;
  OutGraph = SGraph;
  return OutGraph;
}


TGraphErrors *RatioGraph(TGraph *GraphIn1, TGraph *GraphIn2)
{

  TGraphErrors *GraphRatio =new TGraphErrors();
  
  Double_t x1, y1,ye1;
  Double_t x2, y2,ye2;
  Double_t x, y,xe,ye;

            
  for(int j=0; j<GraphIn1->GetN();++j){
    
    GraphIn1->GetPoint(j,x1,y1);

    //ye1=GraphIn1->GetErrorY(j);
    //xe1=GraphIn1->GetErrorX(j);
    //cout<<"1 "<<xe1<<endl;

    GraphIn2->GetPoint(j,x2,y2);
    //ye2=GraphIn2->GetErrorY(j);
    //xe2=GraphIn2->GetErrorX(j);

    //cout<<"2 "<<xe2<<endl;

    x=x1;
    y=(y1/y2);
    xe=0.0;
    ye1=0.0;
    ye2=0.0;
    ye=RError(y1, ye1, y2, ye2);

    GraphRatio->SetPoint(j,x,y);
    GraphRatio->SetPointError(j,xe,ye);
  
  }
  
  /*
  GraphRatio->SetMarkerColor(4);
  GraphRatio->SetLineColor(4);
  GraphRatio->SetMarkerStyle(21);
  GraphRatio->SetMarkerSize(1.5);
  //GraphRatio->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  //GraphRatio->GetYaxis()->SetTitle("R_{FB}(#psi(2S)}/#psi(1S))");
  GraphRatio->GetYaxis()->SetTitleOffset(1.4);
  GraphRatio->GetYaxis()->SetRangeUser(0.0,1.5);
  //TAxis *Xaxis = GraphRatio->GetXaxis();
  //Xaxis->SetLimits(0.0,30.0);
  //cout<<" out "<<endl;
  */

  TGraphErrors *OutGraph;
  OutGraph = GraphRatio;
  return OutGraph;
}




//Ratio Error
Double_t RError(Double_t A, Double_t eA, Double_t B, Double_t eB){
  Double_t eR =0.0;
  Double_t f=0;
  Double_t fA=0;
  Double_t fB=0;
  f=A/B;
  fA=eA/A;
  fB=eB/B;
  eR=  f*sqrt(fA*fA + fB*fB);
  //eR = f*sqrt(fA*fA + fB*fB - 2*(fA*fB)*correl);
  return eR;
}




TGraph *CutGraph(TGraph *InGraph, Double_t XMin)
{
  
  TGraph *SGraph = new TGraph; 
  const int NN = InGraph->GetN();
  
 Int_t i=-1;    
  for (int j=0; j < NN;++j){
    Double_t xx,yy;
           
    InGraph->GetPoint(j,xx,yy);
            
   
    if(xx>=XMin)
      {
	i=i+1;
	SGraph->SetPoint(i,xx,yy);  
      }
  }
  



  TGraph *OutGraph= new TGraph();

  OutGraph = SGraph;

  OutGraph->SetLineColor(InGraph->GetLineColor());
  OutGraph->SetLineStyle(InGraph->GetLineStyle());
  OutGraph->SetLineWidth(InGraph->GetLineWidth());

  OutGraph->SetMarkerColor(InGraph->GetMarkerColor());
  OutGraph->SetMarkerStyle(InGraph->GetMarkerStyle());
  OutGraph->SetMarkerSize(InGraph->GetMarkerSize());


  return OutGraph;





}

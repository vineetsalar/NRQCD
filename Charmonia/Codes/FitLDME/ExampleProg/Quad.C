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
Double_t AddQuad(Double_t e, Double_t e1, Double_t e2, Double_t e3);
void Quad()
{

  /*
  cout<<"NLO Error Psi(2S) ====================="<<endl;
  cout<<" LDME 3S1_8 "<< AddQuad(0.00190313,0.00190883,0.00191452,0.00190029)<<endl;  
  cout<<" LDME 1S0_8 "<< AddQuad(0.0263926,0.0262009,0.0260091,0.0264885)<<endl;  


  cout<<"NLO Error JPsi ====================="<<endl;
  cout<<" LDME 3S1_8 "<< AddQuad(0.00352395,0.00352813,0.0035323,0.00352186)<<endl;  
  cout<<" LDME 1S0_8 "<< AddQuad(0.0511515,0.0509201,0.0506887,0.0512672)<<endl;  
  */
  
  Double_t Old_Psi2S_3S1_8 = 0.00190;
  Double_t Err1_Old_Psi2S_3S1_8 = 0.00002;
  Double_t Err2_Old_Psi2S_3S1_8 = 0.00001;
  Double_t NLOErr_Old_Psi2S_3S1_8 = (Err2_Old_Psi2S_3S1_8/Old_Psi2S_3S1_8)*100;  

  Double_t Old_Psi2S_1S0_8 = 0.0264;
  Double_t Err1_Old_Psi2S_1S0_8 = 0.0003;
  Double_t Err2_Old_Psi2S_1S0_8 = 0.0004;
  
  Double_t Fac_1S0_8_To_M = 4.0/3.0;

  Double_t Old_M_Psi2S = Fac_1S0_8_To_M*Old_Psi2S_1S0_8;
  Double_t Err1_Old_M_Psi2S = Fac_1S0_8_To_M*Err1_Old_Psi2S_1S0_8;
  Double_t Err2_Old_M_Psi2S = Fac_1S0_8_To_M*Err2_Old_Psi2S_1S0_8;
  Double_t NLOErr_Old_M_Psi2S = (Err2_Old_M_Psi2S/Old_M_Psi2S)*100;

  cout<<"Old_Psi2S_3S1_8: "<<   Old_Psi2S_3S1_8 << " pm "<< Err1_Old_Psi2S_3S1_8 <<" pm "<<Err2_Old_Psi2S_3S1_8 <<"  "<<NLOErr_Old_Psi2S_3S1_8<<"%"<<endl;
  cout<<"Old_M_Psi2S: "<<  Old_M_Psi2S << " pm "<< Err1_Old_M_Psi2S <<" pm "<< Err2_Old_M_Psi2S<<"  "<<NLOErr_Old_M_Psi2S<<"%"<<endl<<endl;


  Double_t Psi2S_3S1_8 = 0.00362;
  Double_t Err1_Psi2S_3S1_8 = 0.00006;
  Double_t Err2_Psi2S_3S1_8 = (Psi2S_3S1_8* NLOErr_Old_Psi2S_3S1_8)/100.0;

  Double_t M_Psi2S = 0.022804;
  Double_t Err1_M_Psi2S = 0.00028;
  Double_t Err2_M_Psi2S = (M_Psi2S*NLOErr_Old_M_Psi2S)/100.0;



  cout<<"Psi2S_3S1_8: "<<   Psi2S_3S1_8 << " pm "<< Err1_Psi2S_3S1_8 <<" pm "<<Err2_Psi2S_3S1_8 <<endl;
  cout<<"M_Psi2S: "<<  M_Psi2S << " pm "<< Err1_M_Psi2S <<" pm "<< Err2_M_Psi2S<<endl;
  cout<<endl<<endl<<endl<<endl;











  Double_t Old_JPsi_3S1_8 = 0.00352;
  Double_t Err1_Old_JPsi_3S1_8 = 0.00006;
  Double_t Err2_Old_JPsi_3S1_8 = 0.00001;
  Double_t NLOErr_Old_JPsi_3S1_8 = (Err2_Old_JPsi_3S1_8/Old_JPsi_3S1_8)*100;  

  Double_t Old_JPsi_1S0_8 = 0.05115;
  Double_t Err1_Old_JPsi_1S0_8 = 0.00117;
  Double_t Err2_Old_JPsi_1S0_8 = 0.0005;
  

  



  Double_t Old_M_JPsi = Fac_1S0_8_To_M*Old_JPsi_1S0_8;
  Double_t Err1_Old_M_JPsi = Fac_1S0_8_To_M*Err1_Old_JPsi_1S0_8;
  Double_t Err2_Old_M_JPsi = Fac_1S0_8_To_M*Err2_Old_JPsi_1S0_8;
  Double_t NLOErr_Old_M_JPsi = (Err2_Old_M_JPsi/Old_M_JPsi)*100;

  cout<<"Old_JPsi_3S1_8: "<<   Old_JPsi_3S1_8 << " pm "<< Err1_Old_JPsi_3S1_8 <<" pm "<<Err2_Old_JPsi_3S1_8 <<"  "<<NLOErr_Old_JPsi_3S1_8<<"%"<<endl;
  cout<<"Old_M_JPsi: "<<  Old_M_JPsi << " pm "<< Err1_Old_M_JPsi <<" pm "<< Err2_Old_M_JPsi<<"  "<<NLOErr_Old_M_JPsi<<"%"<<endl;

  Double_t JPsi_3S1_8 = 0.002055;
  Double_t Err1_JPsi_3S1_8 = 0.0001388;
  Double_t Err2_JPsi_3S1_8 = (JPsi_3S1_8* NLOErr_Old_JPsi_3S1_8)/100.0;

  Double_t M_JPsi = 0.06384;
  Double_t Err1_M_JPsi = 0.00106;
  Double_t Err2_M_JPsi = (M_JPsi*NLOErr_Old_M_JPsi)/100.0;



  cout<<"JPsi_3S1_8: "<<   JPsi_3S1_8 << " pm "<< Err1_JPsi_3S1_8 <<" pm "<<Err2_JPsi_3S1_8 <<endl;
  cout<<"M_JPsi: "<<  M_JPsi << " pm "<< Err1_M_JPsi <<" pm "<< Err2_M_JPsi<<endl;
  cout<<endl<<endl<<endl<<endl;


}


Double_t AddQuad(Double_t e, Double_t e1, Double_t e2, Double_t e3)
{


  Double_t a = e-e1;
  Double_t b = e-e2;
  Double_t c = e-e3;


  Double_t e_Out = TMath::Sqrt((a*a)+(b*b)+(c*c));

  return e_Out;


}

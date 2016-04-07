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

  cout<<"NLO Error Psi(2S) ====================="<<endl;
  cout<<" LDME 3S1_8 "<< AddQuad(0.00190313,0.00190883,0.00191452,0.00190029)<<endl;  
  cout<<" LDME 1S0_8 "<< AddQuad(0.0263926,0.0262009,0.0260091,0.0264885)<<endl;  


  cout<<"NLO Error JPsi ====================="<<endl;
  cout<<" LDME 3S1_8 "<< AddQuad(0.00352395,0.00352813,0.0035323,0.00352186)<<endl;  
  cout<<" LDME 1S0_8 "<< AddQuad(0.0511515,0.0509201,0.0506887,0.0512672)<<endl;  




}


Double_t AddQuad(Double_t e, Double_t e1, Double_t e2, Double_t e3)
{


  Double_t a = e-e1;
  Double_t b = e-e2;
  Double_t c = e-e3;


  Double_t e_Out = TMath::Sqrt((a*a)+(b*b)+(c*c));

  return e_Out;


}

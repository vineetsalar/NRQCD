#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
#include "TH1F.h"
#include <TMath.h>
#include <TLegend.h>
#include "TCanvas.h"
#include <TPad.h>
#include "TStyle.h"
#include<cstdlib>
#include<cmath>
#include "TGraphErrors.h"
#include "TLegend.h"
#include <fstream>
#include <stdlib.h>
#include "TMath.h"
#include "TRandom3.h"
#include "TF1.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "LHAPDF/LHAPDF.h"
#include <TSystem.h>
#include <iterator>
#include <iostream>
#include <cstdlib>

#include <string>
#include <vector>
#include <map>

using namespace std;
using namespace LHAPDF;

//=========================== Global Variables ============================//
const Double_t pi = TMath::Pi();
const Double_t hbarc = 0.197327;
const Double_t hbarc2 = hbarc*hbarc;
const Double_t RootS = 7000.0;

const Double_t mC = 1.5;
const Double_t mC2 = mC*mC;
const Double_t mC3 = mC*mC*mC;
const Double_t mJPsi = 3.096916;
const Double_t mJPsi2 = mJPsi*mJPsi;
const Double_t mJPsi3 = mJPsi*mJPsi2;
const Double_t mJPsi4 = mJPsi2*mJPsi2;

const Double_t OO_QQbar_3S1_1_JPsi=1.2/mC3;   //GeV^3
const Double_t OO_QQbar_1S0_8_JPsi=0.018/mC3;   //GeV^3
const Double_t OO_QQbar_3S1_8_JPsi=0.0013/mC3;  




const Double_t OO_QQbar_3S1_1_Psi2S=0.76/mC3; //GeV^3 





// For Parton Distribution Function
Double_t DSigmaDPtDy(Double_t Pt, Double_t Y);

Double_t GetAlphaS(Double_t Q);
Double_t quark_function(int nf, Double_t x, Double_t Qsquare);
Double_t SSPlusTTPlusUU(Double_t Xa, Double_t Pt, Double_t Y);

Double_t Sum_GG_DSigmaDt(Double_t Xa, Double_t Pt, Double_t Y);


Double_t DSigmaDt_GG_QQbar_3S1_1(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDt_GG_QQbar_1S0_8(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDt_GG_QQbar_3S1_8(Double_t Xa, Double_t Pt, Double_t Y);


void QuarkoniaProd_NRQCD()
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

  //TBAR = -6, BBAR = -5, CBAR = -4, SBAR = -3, 
  //UBAR = -2, DBAR = -1, GLUON = 0, DOWN = 1, 
  //UP = 2, STRANGE = 3, CHARM = 4, BOTTOM = 5, 
  //TOP = 6, PHOTON = 7 


  
  //export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/vineet/LHAPDF/lib
  //gSystem->Load("libLHAPDF.so");
  //.include /home/vineet/LHAPDF/include

  Double_t Mz = 91.188; // Mz=Mass of Z boson

  const int SUBSET = 0;
  //const string NAME = "cteq5l";

  const string NAME = "CT10";
  
  LHAPDF::initPDFSet(NAME, LHAPDF::LHGRID, SUBSET);
  
  cout << "alphas(mJPsi) = " << LHAPDF::alphasPDF(mJPsi) << endl;
  cout << "qcdlam4    = " << LHAPDF::getLam4(SUBSET) << endl;
  cout << "qcdlam5    = " << LHAPDF::getLam5(SUBSET) << endl;
  cout << "orderPDF   = " << LHAPDF::getOrderPDF() << endl;
  cout << "xmin       = " << LHAPDF::getXmin(SUBSET) << endl;
  cout << "xmax       = " << LHAPDF::getXmax(SUBSET) << endl;
  cout << "q2min      = " << LHAPDF::getQ2min(SUBSET) << endl;
  cout << "q2max      = " << LHAPDF::getQ2max(SUBSET) << endl;
  cout << "orderalfas = " << LHAPDF::getOrderAlphaS() << endl;
  cout << "num flav   = " << LHAPDF::getNf() << endl;
  cout << "name       = " << NAME << endl;
  cout << "number     = " << LHAPDF::numberPDF() << endl;
  cout << endl;  
 

  LHAPDF::initPDF(SUBSET);

  //return;

  cout<<" value of d quark : "<<quark_function(1, 0.01, 100)<<endl;

  //============================ Graph of Gluon Diss Functions ==================//  
  Double_t AXX[10000]={0.0};

  Double_t GluonDissFunc_Q1[10000]={0.0};
  Double_t UpQuarkDissFunc_Q1[10000]={0.0};
  Double_t DownQuarkDissFunc_Q1[10000]={0.0};

  Double_t XX =0.0;
  Double_t XXMin = 0.0001;
  Double_t XXMax = 1.0;
  Double_t XXStep = 0.001;

  Int_t NNXX = (XXMax-XXMin)/XXStep;

  for(Int_t i=0;i<NNXX;i++)
    {
      XX=XXMin + i*XXStep;
      AXX[i]=XX;
      GluonDissFunc_Q1[i]=0.1*XX*quark_function(0, XX, mJPsi2);
      DownQuarkDissFunc_Q1[i]=XX*quark_function(1, XX, mJPsi2);
      UpQuarkDissFunc_Q1[i]=XX*quark_function(2, XX, mJPsi2);


    }


  TGraph *grGluonDissFunc_Q1 = new TGraph(NNXX,AXX,GluonDissFunc_Q1);
  grGluonDissFunc_Q1->SetName("grGluonDissFunc_Q1");
  grGluonDissFunc_Q1->SetTitle("grGluonDissFunc_Q1");
  grGluonDissFunc_Q1->SetLineWidth(2);
  grGluonDissFunc_Q1->SetLineColor(1);
  grGluonDissFunc_Q1->GetXaxis()->SetTitle("x");
  grGluonDissFunc_Q1->GetYaxis()->SetTitle("xf(x,Q^{2})");

 
  TGraph *grUpQuarkDissFunc_Q1 = new TGraph(NNXX,AXX,UpQuarkDissFunc_Q1);
  grUpQuarkDissFunc_Q1->SetName("grUpQuarkDissFunc_Q1");
  grUpQuarkDissFunc_Q1->SetTitle("grUpQuarkDissFunc_Q1");
  grUpQuarkDissFunc_Q1->SetLineWidth(2);
  grUpQuarkDissFunc_Q1->SetLineColor(2);
  grUpQuarkDissFunc_Q1->GetXaxis()->SetTitle("x");
  grUpQuarkDissFunc_Q1->GetYaxis()->SetTitle("xf(x,Q^{2})");




 TGraph *grDownQuarkDissFunc_Q1 = new TGraph(NNXX,AXX,DownQuarkDissFunc_Q1);
  grDownQuarkDissFunc_Q1->SetName("grDownQuarkDissFunc_Q1");
  grDownQuarkDissFunc_Q1->SetTitle("grDownQuarkDissFunc_Q1");
  grDownQuarkDissFunc_Q1->SetLineWidth(2);
  grDownQuarkDissFunc_Q1->SetLineColor(4);
  grDownQuarkDissFunc_Q1->GetXaxis()->SetTitle("x");
  grDownQuarkDissFunc_Q1->GetYaxis()->SetTitle("xf(x,Q^{2})");


  TLegend *lgd_diss = new TLegend(0.68,0.72,0.85,0.91);
  lgd_diss->SetBorderSize(0);
  lgd_diss->SetFillStyle(0);
  lgd_diss->SetFillColor(0);
  lgd_diss->SetTextSize(0.03);

  lgd_diss->AddEntry(grGluonDissFunc_Q1,"g/10","L");
  lgd_diss->AddEntry(grUpQuarkDissFunc_Q1,"u","L");
  lgd_diss->AddEntry(grDownQuarkDissFunc_Q1,"d","L");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogx(1);
  gPad->SetLeftMargin(0.16);
  grGluonDissFunc_Q1->GetYaxis()->SetTitleOffset(1.6);
  grGluonDissFunc_Q1->Draw("AC");
  grUpQuarkDissFunc_Q1->Draw("CSame");
  grDownQuarkDissFunc_Q1->Draw("CSame");
  lgd_diss->Draw("same");

  

  Double_t Pt = 0.0;
  
  Double_t PtMin = 4.0;
  Double_t PtMax = 70.0;
  Double_t PtStep = 0.5;
  Int_t NNPt = (PtMax - PtMin)/PtStep;


  Double_t APt[1000]={0.0};
  Double_t DSigmaDPtDY_Pt[1000]={0.0};
 
  Double_t DSigmaDt_Pt[1000]={0.0};
  
  Double_t SPlusTPlusU[1000]={0.0};

  cout<<" Pt "<<"    "<<" SIgma Dt"<<"     "<<"DSigmaDPtDY_Pt"<<endl;



  for(Int_t i =0;i<NNPt;i++)
    {
      Pt = PtMin+ (i*PtStep);
      APt[i]=Pt;
      
      DSigmaDt_Pt[i]=Sum_GG_DSigmaDt(0.2,Pt,1.0);
      
      DSigmaDPtDY_Pt[i]=DSigmaDPtDy(Pt,1.0);
      
      SPlusTPlusU[i]=SSPlusTTPlusUU(0.2, Pt, 1.0);


      cout<<APt[i]<<"     "<<DSigmaDt_Pt[i]<<"  "<<DSigmaDPtDY_Pt[i]<<"   "<<SPlusTPlusU[i]<<endl;
    }
  



  TGraph *grSPlusTPlusU = new TGraph(NNPt,APt,SPlusTPlusU);
  grSPlusTPlusU->SetName("grSPlusTPlusU");
  grSPlusTPlusU->SetTitle("grSPlusTPlusU");
  grSPlusTPlusU->SetLineWidth(2);
  grSPlusTPlusU->SetLineColor(2);
  grSPlusTPlusU->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grSPlusTPlusU->GetYaxis()->SetTitle("s+t+u");

  grSPlusTPlusU->GetYaxis()->SetRangeUser(0.0,20);

  new TCanvas; 
  gPad->SetTicks();
  //gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grSPlusTPlusU->GetYaxis()->SetTitleOffset(1.6);
  grSPlusTPlusU->Draw("AL");




  //return;


  TGraph *grDSigmaDt_Pt = new TGraph(NNPt,APt,DSigmaDt_Pt);
  grDSigmaDt_Pt->SetName("grDSigmaDt_Pt");
  grDSigmaDt_Pt->SetTitle("grDSigmaDt_Pt");
  grDSigmaDt_Pt->SetLineWidth(2);
  grDSigmaDt_Pt->SetLineColor(2);
  grDSigmaDt_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grDSigmaDt_Pt->GetYaxis()->SetTitle("d#sigma/dt(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDt_Pt->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDt_Pt->Draw("AL");





  TGraph *grDSigmaDPtDY_Pt = new TGraph(NNPt,APt,DSigmaDPtDY_Pt);
  grDSigmaDPtDY_Pt->SetName("grDSigmaDPtDY_Pt");
  grDSigmaDPtDY_Pt->SetTitle("grDSigmaDPtDY_Pt");
  grDSigmaDPtDY_Pt->SetLineWidth(2);
  grDSigmaDPtDY_Pt->SetLineColor(2);
  grDSigmaDPtDY_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grDSigmaDPtDY_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDPtDY_Pt->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDPtDY_Pt->Draw("AL");



  Double_t Rap = 0.0;
  
  Double_t RapMin = -5.0;
  Double_t RapMax = 5.0;
  Double_t RapStep = 0.1;
  Int_t NNRap = (RapMax - RapMin)/RapStep;


  Double_t ARap[1000]={0.0};
  Double_t DSigmaDPtDY_Rap[1000]={0.0};
  Double_t DSigmaDt_Rap[1000]={0.0};
  
  
  cout<<" Rap "<<"    "<<" SIgma Dt"<<"     "<<"DSigmaDPtDY_Rap"<<endl;



  for(Int_t i =0;i<NNRap;i++)
    {
      Rap = RapMin + (i*RapStep);
      ARap[i]=Rap;
      
      DSigmaDt_Rap[i]=Sum_GG_DSigmaDt(0.2,4.0,Rap);
      DSigmaDPtDY_Rap[i]=DSigmaDPtDy(4.0,Rap);
      
      cout<<ARap[i]<<"     "<<DSigmaDt_Rap[i]<<"  "<<DSigmaDPtDY_Rap[i]<<endl;
    }
  



  TGraph *grDSigmaDt_Rap = new TGraph(NNRap,ARap,DSigmaDt_Rap);
  grDSigmaDt_Rap->SetName("grDSigmaDt_Rap");
  grDSigmaDt_Rap->SetTitle("grDSigmaDt_Rap");
  grDSigmaDt_Rap->SetLineWidth(2);
  grDSigmaDt_Rap->SetLineColor(2);
  grDSigmaDt_Rap->GetXaxis()->SetTitle("y");
  grDSigmaDt_Rap->GetYaxis()->SetTitle("d#sigma/dt(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDt_Rap->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDt_Rap->Draw("AL");





  TGraph *grDSigmaDPtDY_Rap = new TGraph(NNRap,ARap,DSigmaDPtDY_Rap);
  grDSigmaDPtDY_Rap->SetName("grDSigmaDPtDY_Rap");
  grDSigmaDPtDY_Rap->SetTitle("grDSigmaDPtDY_Rap");
  grDSigmaDPtDY_Rap->SetLineWidth(2);
  grDSigmaDPtDY_Rap->SetLineColor(2);
  grDSigmaDPtDY_Rap->GetXaxis()->SetTitle("y");
  grDSigmaDPtDY_Rap->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDPtDY_Rap->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDPtDY_Rap->Draw("AL");






  return;
  
 
}
  
  


Double_t DSigmaDPtDy(Double_t Pt, Double_t Y)
{
  //   quark_function(Int_t nf, Double_t x,Double_t Qsquare)

  Double_t Xa = 0.0;
  Double_t Xb = 0.0;
  Double_t Ga = 0.0;
  Double_t Gb = 0.0;

  Double_t Mt = TMath::Sqrt( Pt*Pt + mJPsi2);
  
  Double_t MuFSquare = Mt*Mt;

  Double_t XaMin =  (RootS*Mt*TMath::Exp(Y) - mJPsi2)/(RootS*(RootS - Mt*TMath::Exp(-Y))); 
  
  Double_t XaMax = 1.0;
  
  Double_t XaStep = 0.001;

  Int_t NNXa = (XaMax - XaMin)/XaStep;

  Double_t Val =0.0;
  Double_t Sum =0.0;
  
  for(Int_t i =0 ; i<NNXa; i++)
    
    {

      Xa = XaMin + (i*XaStep);

      Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 

      Ga = quark_function(0,Xa,MuFSquare);
      Gb = quark_function(0,Xb,MuFSquare);
      
      Sum = Sum + Ga*Gb*Sum_GG_DSigmaDt(Xa,Pt,Y); 

      //cout<<Xa<<"   "<<Ga<<"   "<<Gb<<"    "<<endl;


    }
  
 
   
  Val = Sum;
  

  return Val*XaStep;

}




Double_t GetAlphaS(Double_t Q)
{

  Double_t AlphaS =0.0;
  AlphaS = LHAPDF::alphasPDF(Q);

  return AlphaS;


}

Double_t Sum_GG_DSigmaDt(Double_t Xa, Double_t Pt, Double_t Y)
{

  Double_t Mt = TMath::Sqrt(mJPsi2 + Pt*Pt);
  

  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 

  Double_t Term1 = DSigmaDt_GG_QQbar_3S1_1(Xa, Pt, Y)*OO_QQbar_3S1_1_JPsi;

  Double_t Term2 = DSigmaDt_GG_QQbar_1S0_8(Xa, Pt, Y)*OO_QQbar_1S0_8_JPsi;

  Double_t Term3 = DSigmaDt_GG_QQbar_3S1_8(Xa, Pt, Y)*OO_QQbar_3S1_8_JPsi;
  
  Double_t MtTerm = Xa*Xb/(Xa - (Mt*TMath::Exp(Y)/RootS));

  Double_t Sum = 2.0*Pt*MtTerm*(Term1+Term2+Term3);
  
  Sum =Term3;

  Double_t Fac = hbarc2*10000000.0; //GeV^{-3} to nb/GeV
   
  return Fac*Sum;

}



Double_t DSigmaDt_GG_QQbar_3S1_1(Double_t Xa, Double_t Pt, Double_t Y)
{

  Double_t Mt = TMath::Sqrt(mJPsi2+Pt*Pt);
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 

  Double_t SS = Xa*Xb*RootS*RootS;
  Double_t TT = mJPsi2 - Xa*RootS*Mt*TMath::Exp(-Y);
  Double_t UU = mJPsi2 - Xb*RootS*Mt*TMath::Exp(Y);


  //Double_t AlphaS = 0.41;
  
  Double_t AlphaS = GetAlphaS(Mt);
  Double_t R02 = 0.49; 


  Double_t Constt = 5.0*pi*AlphaS*AlphaS*AlphaS*R02/(9.0*mJPsi*SS*SS);
  Double_t Term1 = mJPsi2/((SS-mJPsi2)*(SS-mJPsi2)*(TT-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2)*(UU-mJPsi2));
  Double_t Term2 = SS*SS*(SS-mJPsi2)*(SS-mJPsi2) + TT*TT*(TT-mJPsi2)*(TT-mJPsi2) + UU*UU*(UU-mJPsi2)*(UU-mJPsi2);

  Double_t Value =0.0;

  Value = Constt*Term1*Term2;
  return Value;
}



Double_t DSigmaDt_GG_QQbar_1S0_8(Double_t Xa, Double_t Pt, Double_t Y)
{
  Double_t Mt = TMath::Sqrt(mJPsi2+Pt*Pt);
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 
  
  Double_t SS = Xa*Xb*RootS*RootS;
  Double_t TT = mJPsi2 - Xa*RootS*Mt*TMath::Exp(-Y);
  Double_t UU = mJPsi2 - Xb*RootS*Mt*TMath::Exp(Y);
  
  Double_t SS2 = SS*SS;
  Double_t TT2 = TT*TT;
  Double_t UU2 = UU*UU;

  Double_t AlphaS = GetAlphaS(Mt);

  
  Double_t Constt = 5.0*TMath::Power((4.0*pi*AlphaS),3)/(16.0*mJPsi);
 
  Double_t Term1 = SS2*(SS-mJPsi2)*(SS-mJPsi2) + SS*TT*UU*(mJPsi2-2.0*SS) + TT*UU*TT*UU;
 
  Double_t Term2Num = (SS2 - mJPsi2*SS + mJPsi4)*(SS2 - mJPsi2*SS + mJPsi4) - TT*UU*(2.0*TT2 + 3.0*TT*UU + 2.0*UU2);
  
  Double_t Term2Deno = SS*TT*UU*( (SS-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2)*(SS-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2));
  
  Double_t Term2 =  Term2Num/Term2Deno;

  Double_t Amp = Constt*Term1*Term2;
  
  Double_t Val = Amp/(16.0*pi*SS2);


  return Val;

}



Double_t DSigmaDt_GG_QQbar_3S1_8(Double_t Xa, Double_t Pt, Double_t Y)
{
  Double_t Mt = TMath::Sqrt(mJPsi2+Pt*Pt);
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 
  
  Double_t SS = Xa*Xb*RootS*RootS;
  Double_t TT = mJPsi2 - Xa*RootS*Mt*TMath::Exp(-Y);
  Double_t UU = mJPsi2 - Xb*RootS*Mt*TMath::Exp(Y);
  
  Double_t SS2 = SS*SS;
  Double_t TT2 = TT*TT;
  Double_t UU2 = UU*UU;

  Double_t AlphaS = GetAlphaS(Mt);

  Double_t Constt = -((4.0*pi*AlphaS)* (4.0*pi*AlphaS)*(4.0*pi*AlphaS))/(144.0*mJPsi3);

  Double_t Term1 = 2.0*mJPsi2*SS*(TT2 + UU2)*TT*UU/((SS-mJPsi2)*(SS-mJPsi2));
  Double_t Term2 = 27.0*(SS*TT + TT*UU + UU*SS) - 19.0*mJPsi4/((SS-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2)*(SS-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2));

  Double_t H0_Amp = Constt*Term1*Term2;


  Double_t Term3 = SS2*( TMath::Power((SS-mJPsi2),4) + TT2*TT2 + UU2*UU2 + 2.0*mJPsi4*TMath::Power((TT*UU/SS),2))/TMath::Power((SS-mJPsi2),2);
  Double_t Term4 = (27.0*(SS*TT + TT*UU + UU*SS) - 19.0*mJPsi4)/((SS-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2)*(SS-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2));

  Double_t H1_Amp = Constt*Term3*Term4;

  Double_t  Amp = H0_Amp + H1_Amp; 

  Double_t Val = Amp/(16.0*pi*SS2);

  return Val;

}




Double_t quark_function(Int_t nf, Double_t x, Double_t Qsquare)
{
  Double_t  Q=TMath::Sqrt(Qsquare);
  
  Double_t xFx = 0.0;

  if ( ( x > 0.00000001 && x < 1.0 ) && (Q<100000 && Q > 0.3) ) xFx =  LHAPDF::xfx(x, Q, nf);  
  
  return xFx/x;
  
}




/*
Double_t PartonSigmaGG(Double_t QSquare)
{
  Double_t Q = TMath::Sqrt(QSquare);
  
  Double_t AlphaS=GetAlphaS(Q);

  Double_t Gamma = 4.0*mC2/QSquare;

  Double_t Sigma =0.0;

  Double_t Term1 = pi*AlphaS*AlphaS/(3.0*QSquare);
  Double_t Term2 = (1+Gamma+(Gamma*Gamma/16.0))*TMath::Log( (1.0+TMath::Sqrt(1-Gamma))/(1.0-TMath::Sqrt(1-Gamma)));
  Double_t Term3 = TMath::Sqrt(1-Gamma)*(7.0/4.0 + (31.0*Gamma/16.0) );

  Sigma = Term1 * ( Term2 -Term3 );

  return Sigma;

}
*/





Double_t SSPlusTTPlusUU(Double_t Xa, Double_t Pt, Double_t Y)
{

  Double_t Mt = TMath::Sqrt(mJPsi2+Pt*Pt);
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 
  
  Double_t SS = Xa*Xb*RootS*RootS;
  Double_t TT = mJPsi2 - Xa*RootS*Mt*TMath::Exp(-Y);
  Double_t UU = mJPsi2 - Xb*RootS*Mt*TMath::Exp(Y);
  
  Double_t Value = SS + TT + UU;

  return Value;



}

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
const Double_t mC = 1.5;
const Double_t mC2 = mC*mC;
const Double_t mJPsi = 3.096916;
const Double_t mJPsi2 = mJPsi*mJPsi;
const Double_t pi = TMath::Pi();





// For Parton Distribution Function
Double_t DSigmaDPtDy(Double_t Pt, Double_t Y, Double_t RootS);
Double_t PartonSigmaGG(Double_t QSquare);
Double_t GetAlphaS(Double_t Q);
Double_t quark_function(int nf, Double_t x, Double_t Qsquare);

void QuarkoniaProd_NRQCD()
{
  gStyle->SetCanvasDefH(600);
  gStyle->SetCanvasDefW(600);
  gStyle->SetOptStat(0);
  gStyle->SetLineWidth(0);
  gStyle->SetOptDate(0);
  gStyle->SetOptFit(0);
  gStyle->SetFillColor(0);
  gStyle->SetCanvasColor(10);
  gStyle->SetPadBorderMode(0);
  gStyle->SetPadColor(0);
  gStyle->SetTitleFillColor(0);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(1); 
  gStyle->SetOptFit(1);
  
  //export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/vineet/LHAPDF/lib
  //gSystem->Load("libLHAPDF.so");
  //.include /home/vineet/LHAPDF/include

  Double_t Mz = 91.188; // Mz=Mass of Z boson

  const int SUBSET = 0;
  const string NAME = "cteq5l";
  
  LHAPDF::initPDFSet(NAME, LHAPDF::LHGRID, SUBSET);
  
  cout << "alphas(mz) = " << LHAPDF::alphasPDF(Mz) << endl;
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

  cout<<" value of d quark : "<<quark_function(1, 0.01, 100)<<endl;

  Double_t Rap = 0.0;
  
  Double_t RapMin = 0.0;
  Double_t RapMax = 6.0;
  Double_t RapStep = 0.5;
  Int_t NNRap = (RapMax - RapMin)/RapStep;

  Double_t YY[100]={0.0};
  Double_t DSigmaDPtDY_YY[100]={0.0};
  
  Double_t RootS = 2760;


  cout<<" YY "<<"    "<<"DSigmaDPtDY_YY"<<endl;

  for(Int_t i =0;i<NNRap;i++)
    {

      Rap = RapMin+ (i*RapStep);
      YY[i]=Rap;
      DSigmaDPtDY_YY[i]=DSigmaDPtDy(0.00001, Rap,RootS);

      cout<<YY[i]<<"     "<<DSigmaDPtDY_YY[i]<<endl;
    }
  
  TGraph *grDSigmaDPtDY_YY = new TGraph(NNRap,YY,DSigmaDPtDY_YY);
  grDSigmaDPtDY_YY->SetName("grDSigmaDPtDY_YY");
  grDSigmaDPtDY_YY->SetTitle("grDSigmaDPtDY_YY");
  grDSigmaDPtDY_YY->SetLineWidth(2);
  grDSigmaDPtDY_YY->SetLineColor(2);
  grDSigmaDPtDY_YY->GetXaxis()->SetTitle("y");
  grDSigmaDPtDY_YY->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  grDSigmaDPtDY_YY->Draw("AL");





  return;
  
 
}
  
  


Double_t DSigmaDPtDy(Double_t Pt, Double_t Y, Double_t RootS)
{
  //   quark_function(Int_t nf, Double_t x,Double_t Qsquare)

  Double_t Xa =0.0;
  Double_t Xb =0.0;
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
  Double_t Term =0.0;

  for(Int_t i =0 ; i<NNXa; i++)
    
    {
      Xa = XaMin + (i*XaStep);
      Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(RootS - Mt*TMath::Exp(Y))); 

      Ga = quark_function(0,Xa,MuFSquare);
      Gb = quark_function(0,Xb,MuFSquare);
      Term = Xa*Xb/(Xa - (Mt*TMath::Exp(Y)/RootS));

      Sum = Sum + Ga*Gb*Term; 

    }
  
 
  Val = Sum*2.0*Pt*PartonSigmaGG(MuFSquare);
  
  return Val*XaStep;


}












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







Double_t quark_function(Int_t nf, Double_t x,Double_t Qsquare)
{
  Double_t  Q=TMath::Sqrt(Qsquare);
  
  Double_t xFx = 0.0;

  if ( ( x > 0.00000001 && x < 1.0 ) && (Q<100000 && Q > 0.3) ) xFx =  LHAPDF::xfx(x, Q, nf);  
  
  return xFx/x;
  
}


Double_t GetAlphaS(Double_t Q)
{

  Double_t AlphaS =0.0;
  AlphaS = LHAPDF::alphasPDF(Q);

  return AlphaS;


}

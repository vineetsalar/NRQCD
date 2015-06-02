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
#include "TGraphAsymmErrors.h"
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
#include "TLatex.h"
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



/*
//JPsi %%%%%%%%%%%%%%%%%%%%%%%%%%%%
Int_t QQbarVar =1;
const Double_t mC = 1.5;
const Double_t mC2 = mC*mC;
const Double_t mC3 = mC*mC*mC;
const Double_t mJPsi = 3.096916;
const Double_t mJPsi2 = mJPsi*mJPsi;
const Double_t mJPsi3 = mJPsi*mJPsi2;
const Double_t mJPsi4 = mJPsi2*mJPsi2;
const Double_t OO_QQbar_3S1_1_JPsi=1.2;   //GeV^3
const Double_t OO_QQbar_1S0_8_JPsi=0.018;   //GeV^3
const Double_t OO_QQbar_3S1_8_JPsi=0.0013;  //GeV^3
const Double_t OO_QQbar_3P0_8_JPsi=0.018*mC2; //GeV^5 
*/


/*
//Psi2S %%%%%%%%%%%%%%%%%%%%%%%%%%%%
Int_t QQbarVar =2;
const Double_t mC = 1.5;
const Double_t mC2 = mC*mC;
const Double_t mC3 = mC*mC*mC;
const Double_t mJPsi = 3.686109;
const Double_t mJPsi2 = mJPsi*mJPsi;
const Double_t mJPsi3 = mJPsi*mJPsi2;
const Double_t mJPsi4 = mJPsi2*mJPsi2;

const Double_t OO_QQbar_3S1_1_JPsi=0.76; //GeV^3 
const Double_t OO_QQbar_1S0_8_JPsi=0.0080;   //GeV^3
const Double_t OO_QQbar_3S1_8_JPsi=0.0033;  //GeV^3
const Double_t OO_QQbar_3P0_8_JPsi=0.0080*mC2; //GeV^5 
*/



// Chic0 %%%%%%%%%%%%%%%%%%%%%%%%%%%%
Int_t QQbarVar = 3;
const Double_t mC = 1.5;
const Double_t mC2 = mC*mC;
const Double_t mC3 = mC*mC*mC;
const Double_t mJPsi = 3.41475;
const Double_t mJPsi2 = mJPsi*mJPsi;
const Double_t mJPsi3 = mJPsi*mJPsi2;
const Double_t mJPsi4 = mJPsi2*mJPsi2;

const Double_t OO_QQbar_3S1_1_JPsi=0.0;          //GeV^3 
const Double_t OO_QQbar_1S0_8_JPsi=0.0;       //GeV^3
const Double_t OO_QQbar_3S1_8_JPsi=0.0;      //GeV^3
const Double_t OO_QQbar_3P0_8_JPsi=0.0;  //GeV^5 

const Double_t OO_QQbar_3P0_1_Chic=0.054*mC2;        
const Double_t OO_QQbar_3S1_8_Chic=0.00187*mC2;        









// For Parton Distribution Function
Double_t GetAlphaS(Double_t Q);
Double_t quark_function(int nf, Double_t x, Double_t Qsquare);
Double_t SSPlusTTPlusUU(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDPtDy(Double_t Pt, Double_t Y);
Double_t DSigmaDt_IntX(Double_t Pt, Double_t Y, Int_t Parton1, Int_t Parton2);

Double_t DSigmaDPtDy_qg(Double_t Pt, Double_t Y);
Double_t DSigmaDPtDy_UG(Double_t Pt, Double_t Y);
Double_t DSigmaDPtDy_DG(Double_t Pt, Double_t Y);

Double_t Sum_qg_DSigmaDt(Double_t Xa, Double_t Pt, Double_t Y);

Double_t DSigmaDt_qg_QQbar_1S0_8(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDt_qg_QQbar_3S1_8(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDt_qg_QQbar_3P0_8(Double_t Xa, Double_t Pt, Double_t Y);


Double_t DSigmaDPtDy_qqbar(Double_t Pt, Double_t Y);
Double_t DSigmaDPtDy_UUbar(Double_t Pt, Double_t Y);
Double_t DSigmaDPtDy_DDbar(Double_t Pt, Double_t Y);

Double_t Sum_qq_DSigmaDt(Double_t Xa, Double_t Pt, Double_t Y);

Double_t DSigmaDt_qq_QQbar_1S0_8(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDt_qq_QQbar_3S1_8(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDt_qq_QQbar_3P0_8(Double_t Xa, Double_t Pt, Double_t Y);



Double_t DSigmaDPtDy_GG(Double_t Pt, Double_t Y);

Double_t Sum_GG_DSigmaDt(Double_t Xa, Double_t Pt, Double_t Y);

Double_t DSigmaDt_GG_QQbar_3S1_1(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDt_GG_QQbar_1S0_8(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDt_GG_QQbar_3S1_8(Double_t Xa, Double_t Pt, Double_t Y);
Double_t DSigmaDt_GG_QQbar_3P0_8(Double_t Xa, Double_t Pt, Double_t Y);





//========= Data Functions ============================//
void Draw_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt(TLegend *lgd);
void Draw_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt(TLegend *lgd);




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


  //UBAR = -2,
  //UP = 2,


  //================ Out Root File ===================//
  TFile *OutFile;

  if(QQbarVar ==1){OutFile = new TFile("JPsiCrossSection.root","Recreate");}
  if(QQbarVar ==2){OutFile = new TFile("Psi2SCrossSection.root","Recreate");}
  if(QQbarVar ==3){OutFile = new TFile("Chic0_1PCrossSection.root","Recreate");}
  if(QQbarVar ==4){OutFile = new TFile("Chic1_1PCrossSection.root","Recreate");}
  if(QQbarVar ==5){OutFile = new TFile("Chic2_1PCrossSection.root","Recreate");}






  //export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/vineet/LHAPDF/lib
  //gSystem->Load("libLHAPDF.so");
  //.include /home/vineet/LHAPDF/include


  
  Double_t Mz = 91.188; // Mz=Mass of Z boson

  const int SUBSET = 0;
  //const string NAME = "cteq5l";

  const string NAME = "CT10";
  
  LHAPDF::initPDFSet(NAME, LHAPDF::LHGRID, SUBSET);
  
  cout << "alphas(Z0) = " << LHAPDF::alphasPDF(Mz) << endl;
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

  // cout<<" value of d quark : "<<quark_function(1, 0.01, 100)<<endl;

  //============================ Graph of Gluon Diss Functions ==================//  
  Double_t AXX[10000]={0.0};

  Double_t GluonDissFunc_Q1[10000]={0.0};
  Double_t UpQuarkDissFunc_Q1[10000]={0.0};
  Double_t DownQuarkDissFunc_Q1[10000]={0.0};

  Double_t UpBarQuarkDissFunc_Q1[10000]={0.0};

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
      UpBarQuarkDissFunc_Q1[i]=XX*quark_function(-2, XX, mJPsi2);

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



  TGraph *grUpBarQuarkDissFunc_Q1 = new TGraph(NNXX,AXX,UpBarQuarkDissFunc_Q1);
  grUpBarQuarkDissFunc_Q1->SetName("grUpBarQuarkDissFunc_Q1");
  grUpBarQuarkDissFunc_Q1->SetTitle("grUpBarQuarkDissFunc_Q1");
  grUpBarQuarkDissFunc_Q1->SetLineWidth(2);
  grUpBarQuarkDissFunc_Q1->SetLineColor(2);
  grUpBarQuarkDissFunc_Q1->GetXaxis()->SetTitle("x");
  grUpBarQuarkDissFunc_Q1->GetYaxis()->SetTitle("xf(x,Q^{2})");



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
  lgd_diss->AddEntry(grUpBarQuarkDissFunc_Q1,"#bar{u}","L");
  //lgd_diss->AddEntry(grDownQuarkDissFunc_Q1,"d","L");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogx(1);
  gPad->SetLeftMargin(0.16);
  grGluonDissFunc_Q1->GetYaxis()->SetTitleOffset(1.6);
  grGluonDissFunc_Q1->GetYaxis()->SetRangeUser(0.0,2.0);
  grGluonDissFunc_Q1->Draw("AC");
  grUpQuarkDissFunc_Q1->Draw("CSame");
  grUpBarQuarkDissFunc_Q1->Draw("CSame");

  grDownQuarkDissFunc_Q1->Draw("CSame");
  lgd_diss->Draw("same");



  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogx(1);
  gPad->SetLeftMargin(0.16);
  grGluonDissFunc_Q1->GetYaxis()->SetTitleOffset(1.6);
  grGluonDissFunc_Q1->GetYaxis()->SetRangeUser(0.0,2.0);
  grGluonDissFunc_Q1->Draw("AC");
  grUpQuarkDissFunc_Q1->Draw("CSame");
  grUpBarQuarkDissFunc_Q1->SetLineColor(4);
  grUpBarQuarkDissFunc_Q1->Draw("CSame");
  lgd_diss->Draw("same");

  //return;

  Double_t AQQ[10000]={0.0};
  Double_t AAlphaS[10000]={0.0};
 
  Double_t QQ =0.0;
  Double_t QQMin = 1.0;
  Double_t QQMax = 1000.0;
  Double_t QQStep = 0.5;

  Int_t NNQQ = (QQMax-QQMin)/QQStep;

  for(Int_t i=0;i<NNQQ;i++)
    {
      QQ=QQMin + i*QQStep;
      AQQ[i]=QQ;
      AAlphaS[i]=GetAlphaS(QQ);

    }

  
  TGraph *grAlphaSVsQ = new TGraph(NNQQ,AQQ,AAlphaS);
  grAlphaSVsQ->SetName("grAlphaSVsQ");
  grAlphaSVsQ->SetTitle("grAlphaSVsQ");
  grAlphaSVsQ->SetLineWidth(2);
  grAlphaSVsQ->SetLineColor(2);
  grAlphaSVsQ->GetXaxis()->SetTitle("Q(GeV)");
  grAlphaSVsQ->GetYaxis()->SetTitle("#alpha_{s}(Q)");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogx(1);
  gPad->SetLeftMargin(0.16);
  grAlphaSVsQ->GetYaxis()->SetTitleOffset(1.6);
  grAlphaSVsQ->Draw("AC");


  //return;


  

  Double_t SPlusTPlusU[1000]={0.0};

  Double_t APt[1000]={0.0};

  Double_t DSigmaDPtDY_Pt[1000]={0.0};
 
  
  Double_t DSigmaDt_GG_Pt[1000]={0.0};
  Double_t DSigmaDt_qq_Pt[1000]={0.0};
  Double_t DSigmaDt_qg_Pt[1000]={0.0};

  Double_t Pt = 0.0;
  
  Double_t PtMin = 4.0;
  Double_t PtMax = 70.0;
  Double_t PtStep = 0.5;
  Int_t NNPt = (PtMax - PtMin)/PtStep;


 
  cout<<"APt: "<<"    "<<"DSigmaDt_GG_Pt: "<<"    "<<"DSigmaDt_qq_Pt: "<<"    "<<"DSigmaDt_qg_Pt: "<<"    "<<"DSigmaDPtDY_Pt: "<<endl;
  



  for(Int_t i =0;i<NNPt;i++)
    {
      Pt = PtMin+ (i*PtStep);
      APt[i]=Pt;
      SPlusTPlusU[i]=SSPlusTTPlusUU(0.2, Pt, 1.0);

      DSigmaDPtDY_Pt[i]= DSigmaDPtDy(Pt,1.0);
     
      DSigmaDt_GG_Pt[i]=Sum_GG_DSigmaDt(0.1,Pt,1.0);
      
      DSigmaDt_qq_Pt[i]=Sum_qq_DSigmaDt(0.2,Pt,1.0);

      DSigmaDt_qg_Pt[i]=Sum_qg_DSigmaDt(0.2,Pt,1.0);
      
      cout<<APt[i]<<"    "<<DSigmaDt_GG_Pt[i]<<"    "<<DSigmaDt_qq_Pt[i]<<"    "<<DSigmaDt_qg_Pt[i]<<"    "<<DSigmaDPtDY_Pt[i]<<endl;
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




  
  TGraph *grDSigmaDt_GG_Pt = new TGraph(NNPt,APt,DSigmaDt_GG_Pt);
  grDSigmaDt_GG_Pt->SetName("grDSigmaDt_GG_Pt");
  grDSigmaDt_GG_Pt->SetTitle("grDSigmaDt_GG_Pt");
  grDSigmaDt_GG_Pt->SetLineWidth(2);
  grDSigmaDt_GG_Pt->SetLineColor(2);
  grDSigmaDt_GG_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grDSigmaDt_GG_Pt->GetYaxis()->SetTitle("d#sigma^{gg #rightarrow Q#bar{Q}g}/d#hat{t}(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDt_GG_Pt->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDt_GG_Pt->Draw("AL");



  TGraph *grDSigmaDt_qq_Pt = new TGraph(NNPt,APt,DSigmaDt_qq_Pt);
  grDSigmaDt_qq_Pt->SetName("grDSigmaDt_qq_Pt");
  grDSigmaDt_qq_Pt->SetTitle("grDSigmaDt_qq_Pt");
  grDSigmaDt_qq_Pt->SetLineWidth(2);
  grDSigmaDt_qq_Pt->SetLineColor(2);
  grDSigmaDt_qq_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grDSigmaDt_qq_Pt->GetYaxis()->SetTitle("d#sigma^{q#bar{q} #rightarrow Q#bar{Q}g}/d#hat{t}(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDt_qq_Pt->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDt_qq_Pt->Draw("AL");

  
  TGraph *grDSigmaDt_qg_Pt = new TGraph(NNPt,APt,DSigmaDt_qg_Pt);
  grDSigmaDt_qg_Pt->SetName("grDSigmaDt_qg_Pt");
  grDSigmaDt_qg_Pt->SetTitle("grDSigmaDt_qg_Pt");
  grDSigmaDt_qg_Pt->SetLineWidth(2);
  grDSigmaDt_qg_Pt->SetLineColor(2);
  grDSigmaDt_qg_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grDSigmaDt_qg_Pt->GetYaxis()->SetTitle("d#sigma^{qg #rightarrow Q#bar{Q}g}/d#hat{t}(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDt_qg_Pt->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDt_qg_Pt->Draw("AL");



  TGraph *grDSigmaDPtDY_Pt = new TGraph(NNPt,APt,DSigmaDPtDY_Pt);
  grDSigmaDPtDY_Pt->SetName("grDSigmaDPtDY_Pt");
  grDSigmaDPtDY_Pt->SetTitle("grDSigmaDPtDY_Pt");
  grDSigmaDPtDY_Pt->SetLineWidth(2);
  grDSigmaDPtDY_Pt->SetLineColor(2);
  grDSigmaDPtDY_Pt->GetXaxis()->SetTitle("p_{T}(GeV/c)");
  grDSigmaDPtDY_Pt->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");

  TLegend *lgd_DSigmaDPtDY_Pt = new TLegend(0.40,0.80,0.88,0.93);
  lgd_DSigmaDPtDY_Pt->SetBorderSize(0);
  lgd_DSigmaDPtDY_Pt->SetFillStyle(0);
  lgd_DSigmaDPtDY_Pt->SetFillColor(0);
  lgd_DSigmaDPtDY_Pt->SetTextSize(0.03);

  
  new TCanvas; 
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Draw_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt(lgd_DSigmaDPtDY_Pt);
  
  lgd_DSigmaDPtDY_Pt->AddEntry(grDSigmaDPtDY_Pt,"NRQCD, prompt J/#psi","L");
  grDSigmaDPtDY_Pt->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDPtDY_Pt->Draw("Lsame");
  lgd_DSigmaDPtDY_Pt->Draw("same");


  //return;

 



  Double_t Rap = 0.0;
  
  Double_t RapMin = -5.0;
  Double_t RapMax = 5.0;
  Double_t RapStep = 0.1;
  Int_t NNRap = (RapMax - RapMin)/RapStep;


  Double_t ARap[1000]={0.0};
  Double_t DSigmaDPtDY_Rap[1000]={0.0};


  Double_t DSigmaDt_GG_Rap[1000]={0.0};
  Double_t DSigmaDt_qq_Rap[1000]={0.0};
  Double_t DSigmaDt_qg_Rap[1000]={0.0};

  cout<<" Rap "<<"    "<<" SIgma Dt"<<"     "<<"DSigmaDPtDY_Rap"<<endl;



  for(Int_t i =0;i<NNRap;i++)
    {
      Rap = RapMin + (i*RapStep);
      
      ARap[i]=Rap;
      DSigmaDPtDY_Rap[i]=DSigmaDPtDy(4.0,Rap);
      
      DSigmaDt_GG_Rap[i]=Sum_GG_DSigmaDt(0.2,4.0,Rap);
      DSigmaDt_qq_Rap[i]=Sum_qq_DSigmaDt(0.2,4.0,Rap);
      DSigmaDt_qg_Rap[i]=Sum_qg_DSigmaDt(0.2,4.0,Rap);
      
      cout<<ARap[i]<<"     "<<DSigmaDt_GG_Rap[i]<<"  "<<DSigmaDt_qq_Rap[i]<<"   "<<DSigmaDt_qg_Rap[i]<<"   "<<DSigmaDPtDY_Rap[i]<<"   "<<endl;
    }
  

  TGraph *grDSigmaDt_GG_Rap = new TGraph(NNRap,ARap,DSigmaDt_GG_Rap);
  grDSigmaDt_GG_Rap->SetName("grDSigmaDt_Rap");
  grDSigmaDt_GG_Rap->SetTitle("grDSigmaDt_Rap");
  grDSigmaDt_GG_Rap->SetLineWidth(2);
  grDSigmaDt_GG_Rap->SetLineColor(2);
  grDSigmaDt_GG_Rap->GetXaxis()->SetTitle("y");
  grDSigmaDt_GG_Rap->GetYaxis()->SetTitle("d#sigma^{gg #rightarrow Q#bar{Q}g}/d#hat{t}(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  //gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDt_GG_Rap->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDt_GG_Rap->Draw("AL");



 TGraph *grDSigmaDt_qq_Rap = new TGraph(NNRap,ARap,DSigmaDt_qq_Rap);
  grDSigmaDt_qq_Rap->SetName("grDSigmaDt_Rap");
  grDSigmaDt_qq_Rap->SetTitle("grDSigmaDt_Rap");
  grDSigmaDt_qq_Rap->SetLineWidth(2);
  grDSigmaDt_qq_Rap->SetLineColor(2);
  grDSigmaDt_qq_Rap->GetXaxis()->SetTitle("y");
  grDSigmaDt_qq_Rap->GetYaxis()->SetTitle("d#sigma^{q#bar{q} #rightarrow Q#bar{Q}g}/d#hat{t}(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  //gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDt_qq_Rap->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDt_qq_Rap->Draw("AL");


  TGraph *grDSigmaDt_qg_Rap = new TGraph(NNRap,ARap,DSigmaDt_qg_Rap);
  grDSigmaDt_qg_Rap->SetName("grDSigmaDt_Rap");
  grDSigmaDt_qg_Rap->SetTitle("grDSigmaDt_Rap");
  grDSigmaDt_qg_Rap->SetLineWidth(2);
  grDSigmaDt_qg_Rap->SetLineColor(2);
  grDSigmaDt_qg_Rap->GetXaxis()->SetTitle("y");
  grDSigmaDt_qg_Rap->GetYaxis()->SetTitle("d#sigma^{qg #rightarrow Q#bar{Q}q}/d#hat{t}(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  //gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDt_qg_Rap->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDt_qg_Rap->Draw("AL");






  TGraph *grDSigmaDPtDY_Rap = new TGraph(NNRap,ARap,DSigmaDPtDY_Rap);
  grDSigmaDPtDY_Rap->SetName("grDSigmaDPtDY_Rap");
  grDSigmaDPtDY_Rap->SetTitle("grDSigmaDPtDY_Rap");
  grDSigmaDPtDY_Rap->SetLineWidth(2);
  grDSigmaDPtDY_Rap->SetLineColor(2);
  grDSigmaDPtDY_Rap->GetXaxis()->SetTitle("y");
  grDSigmaDPtDY_Rap->GetYaxis()->SetTitle("d^{2}#sigma/dp_{T}dy(nb/GeV)");

  new TCanvas; 
  gPad->SetTicks();
  //gPad->SetLogy(1);
  gPad->SetLeftMargin(0.16);
  grDSigmaDPtDY_Rap->GetYaxis()->SetTitleOffset(1.6);
  grDSigmaDPtDY_Rap->Draw("AL");



  grGluonDissFunc_Q1->Write();
  grUpQuarkDissFunc_Q1->Write();
  grUpBarQuarkDissFunc_Q1->Write();
  grDownQuarkDissFunc_Q1->Write();
  grAlphaSVsQ->Write();
  grSPlusTPlusU->Write();
  grDSigmaDt_GG_Pt->Write();
  grDSigmaDt_qq_Pt->Write();
  grDSigmaDt_qg_Pt->Write();
  grDSigmaDPtDY_Pt->Write();
  grDSigmaDt_GG_Rap->Write();
  grDSigmaDt_qq_Rap->Write();
  grDSigmaDt_qg_Rap->Write();
  grDSigmaDPtDY_Rap->Write();
  
  OutFile->Close();

  return;
  
 
}
  
  







//===============================================================================
// q+g --> QQbar + q partonic cross sections
//===============================================================================
//OO_QQbar_3S1_1_JPsi, OO_QQbar_1S0_8_JPsi, OO_QQbar_3S1_8_JPsi, OO_QQbar_3P0_8_JPsi




Double_t DSigmaDPtDy(Double_t Pt, Double_t Y)
{
  

  //Double_t Value =  DSigmaDPtDy_qg(Pt, Y) + DSigmaDPtDy_qqbar(Pt, Y) +  DSigmaDPtDy_GG(Pt, Y);

  Double_t Value =    DSigmaDt_IntX(Pt, Y,2,0) +   DSigmaDt_IntX(Pt, Y,1,0) +  DSigmaDt_IntX(Pt, Y,2,-2)  +     DSigmaDt_IntX(Pt, Y,1,-1)+  DSigmaDt_IntX(Pt, Y, 0, 0);


  return Value;


}


Double_t DSigmaDt_IntX(Double_t Pt, Double_t Y, Int_t Parton1, Int_t Parton2)
{

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
  Double_t SumDSigmaDt = 0.0;  

  for(Int_t i =0 ; i<NNXa; i++)
    
    {

      Xa = XaMin + (i*XaStep);

      Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 

      Ga = quark_function(Parton1,Xa,MuFSquare);
      Gb = quark_function(Parton2,Xb,MuFSquare);
      
      if(Parton1 ==0 && Parton2 ==0){SumDSigmaDt = Sum_GG_DSigmaDt(Xa,Pt,Y);} 
      if( (Parton1 ==0 || Parton2 ==0) && (Parton1 != Parton2) ){SumDSigmaDt = Sum_qg_DSigmaDt(Xa,Pt,Y);} 
      if(Parton1 !=0 && Parton2 !=0){SumDSigmaDt = Sum_qq_DSigmaDt(Xa,Pt,Y);} 

      Sum = Sum + Ga*Gb*SumDSigmaDt; 

      //cout<<Xa<<"   "<<Ga<<"   "<<Gb<<"    "<<endl;


    }
  
   
  Val = Sum;
  

  return Val*XaStep;



}







Double_t DSigmaDPtDy_qg(Double_t Pt, Double_t Y)
{
  Double_t Val =  DSigmaDPtDy_UG(Pt, Y) + DSigmaDPtDy_DG(Pt, Y);
  return Val;
}




Double_t DSigmaDPtDy_UG(Double_t Pt, Double_t Y)
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

      Ga = quark_function(2,Xa,MuFSquare);
      Gb = quark_function(0,Xb,MuFSquare);
      
      Sum = Sum + Ga*Gb*Sum_qg_DSigmaDt(Xa,Pt,Y); 

      //cout<<Xa<<"   "<<Ga<<"   "<<Gb<<"    "<<endl;


    }
  
   
  Val = Sum;
  

  return Val*XaStep;

}



Double_t DSigmaDPtDy_DG(Double_t Pt, Double_t Y)
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

      Ga = quark_function(1,Xa,MuFSquare);
      Gb = quark_function(0,Xb,MuFSquare);
      
      Sum = Sum + Ga*Gb*Sum_qg_DSigmaDt(Xa,Pt,Y); 

      //cout<<Xa<<"   "<<Ga<<"   "<<Gb<<"    "<<endl;

    }
  
   
  Val = Sum;
  

  return Val*XaStep;

}





Double_t Sum_qg_DSigmaDt(Double_t Xa, Double_t Pt, Double_t Y)
{

  Double_t Mt = TMath::Sqrt(mJPsi2 + Pt*Pt);
  
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 

  Double_t Term2 = DSigmaDt_qg_QQbar_1S0_8(Xa, Pt, Y)*OO_QQbar_1S0_8_JPsi;

  Double_t Term3 = DSigmaDt_qg_QQbar_3S1_8(Xa, Pt, Y)*OO_QQbar_3S1_8_JPsi;

  Double_t Term4 = DSigmaDt_qg_QQbar_3P0_8(Xa, Pt, Y)*OO_QQbar_3P0_8_JPsi;
  
  Double_t MtTerm = Xa*Xb/(Xa - (Mt*TMath::Exp(Y)/RootS));

  Double_t Sum = 2.0*Pt*MtTerm*(Term2+Term3+Term4);

     
  Double_t Fac = hbarc2*10000000.0; //GeV^{-3} to nb/GeV
   
  return Fac*Sum;

}


Double_t DSigmaDt_qg_QQbar_1S0_8(Double_t Xa, Double_t Pt, Double_t Y)
{
  Double_t Mt = TMath::Sqrt(mJPsi2+Pt*Pt);
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 
  
  Double_t SS = Xa*Xb*RootS*RootS;
  Double_t TT = mJPsi2 - Xa*RootS*Mt*TMath::Exp(-Y);
  Double_t UU = mJPsi2 - Xb*RootS*Mt*TMath::Exp(Y);
  
  Double_t SS2 = SS*SS;
  Double_t UU2 = UU*UU;
  
  Double_t AlphaS = GetAlphaS(Mt);


  Double_t Constt = -5.0*TMath::Power((4.0*pi*AlphaS),3.0)/(72.0*mJPsi);

  Double_t Num = SS2 + UU2;
  Double_t Deno = TT*(TT-mJPsi2)*(TT-mJPsi2);

  Double_t Amp = Constt*Num/Deno;

  Double_t Val =  Amp/(16.0*pi*SS2);
 
  return Val;

}


Double_t DSigmaDt_qg_QQbar_3S1_8(Double_t Xa, Double_t Pt, Double_t Y)
{
  Double_t Mt = TMath::Sqrt(mJPsi2+Pt*Pt);
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 
  
  Double_t SS = Xa*Xb*RootS*RootS;
  Double_t TT = mJPsi2 - Xa*RootS*Mt*TMath::Exp(-Y);
  Double_t UU = mJPsi2 - Xb*RootS*Mt*TMath::Exp(Y);
  
  Double_t SS2 = SS*SS;
  Double_t UU2 = UU*UU;
  
  Double_t AlphaS = GetAlphaS(Mt);
  
  Double_t Constt = -TMath::Power((4.0*pi*AlphaS),3.0)/(108*mJPsi3);

  Double_t Term1 = mJPsi2*TT*(4.0*(SS2+UU2)-SS*UU);
  
  Double_t Term2 = (SS-mJPsi2)*(TT-mJPsi2)*(SS-mJPsi2)*(TT-mJPsi2);

  Double_t Amp_h0 = 2.0*Constt*Term1/Term2;


  Double_t Term3 =(SS2+UU2+2.0*mJPsi2*TT)*(SS-mJPsi2)*(SS-mJPsi2) - 2.0*mJPsi2*SS*TT*UU;

  Double_t Term4 = 4.0*(SS2+UU2)-(SS*UU);
  
  Double_t Amp_h1 = Constt*Term3*Term4/(SS*UU*Term2);

  Double_t Amp = Amp_h0 + Amp_h1;

  Double_t Val = Amp/(16.0*pi*SS2);

  return Val;

}


Double_t DSigmaDt_qg_QQbar_3P0_8(Double_t Xa, Double_t Pt, Double_t Y)
{
  Double_t Mt = TMath::Sqrt(mJPsi2+Pt*Pt);
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 
  
  Double_t SS = Xa*Xb*RootS*RootS;
  Double_t TT = mJPsi2 - Xa*RootS*Mt*TMath::Exp(-Y);
  Double_t UU = mJPsi2 - Xb*RootS*Mt*TMath::Exp(Y);
  
  Double_t SS2 = SS*SS;
  Double_t UU2 = UU*UU;
  
  Double_t AlphaS = GetAlphaS(Mt);
  
  Double_t Constt = -5.0*TMath::Power((4.0*pi*AlphaS),3)/(54.0*mJPsi3);

  Double_t Term1 = (TT-3.0*mJPsi2)*(TT-3.0*mJPsi2)*(SS2+UU2);
  Double_t Term2 = TT*TMath::Power(TT-mJPsi2,4.0);

  Double_t Amp = Constt*Term1/Term2;

  Double_t Val = Amp/(16.0*pi*SS2);

  return Val;
  
}




//===============================================================================
// q+q_bar--> QQbar + g partonic cross sections
//===============================================================================
//OO_QQbar_3S1_1_JPsi, OO_QQbar_1S0_8_JPsi, OO_QQbar_3S1_8_JPsi, OO_QQbar_3P0_8_JPsi


Double_t DSigmaDPtDy_qqbar(Double_t Pt, Double_t Y)
{
  Double_t Val =  DSigmaDPtDy_UUbar(Pt, Y) + DSigmaDPtDy_UUbar(Pt, Y);
  return Val;
}




Double_t DSigmaDPtDy_UUbar(Double_t Pt, Double_t Y)
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

      Ga = quark_function(2,Xa,MuFSquare);
      Gb = quark_function(-2,Xb,MuFSquare);
      
      Sum = Sum + Ga*Gb*Sum_qq_DSigmaDt(Xa,Pt,Y); 

      //cout<<Xa<<"   "<<Ga<<"   "<<Gb<<"    "<<endl;


    }
  
   
  Val = Sum;
  

  return Val*XaStep;

}



Double_t DSigmaDPtDy_DDbar(Double_t Pt, Double_t Y)
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

      Ga = quark_function(1,Xa,MuFSquare);
      Gb = quark_function(-1,Xb,MuFSquare);
      
      Sum = Sum + Ga*Gb*Sum_qq_DSigmaDt(Xa,Pt,Y); 

      //cout<<Xa<<"   "<<Ga<<"   "<<Gb<<"    "<<endl;

    }
  
   
  Val = Sum;
  

  return Val*XaStep;

}






Double_t Sum_qq_DSigmaDt(Double_t Xa, Double_t Pt, Double_t Y)
{

  Double_t Mt = TMath::Sqrt(mJPsi2 + Pt*Pt);
  
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 

  //Double_t Term1 = DSigmaDt_GG_QQbar_3S1_1(Xa, Pt, Y)*OO_QQbar_3S1_1_JPsi;

  Double_t Term2 = DSigmaDt_qq_QQbar_1S0_8(Xa, Pt, Y)*OO_QQbar_1S0_8_JPsi;

  Double_t Term3 = DSigmaDt_qq_QQbar_3S1_8(Xa, Pt, Y)*OO_QQbar_3S1_8_JPsi;

  Double_t Term4 = DSigmaDt_qq_QQbar_3P0_8(Xa, Pt, Y)*OO_QQbar_3P0_8_JPsi;
  
  Double_t MtTerm = Xa*Xb/(Xa - (Mt*TMath::Exp(Y)/RootS));

  Double_t Sum = 2.0*Pt*MtTerm*(Term2+Term3+Term4);


    
  Double_t Fac = hbarc2*10000000.0; //GeV^{-3} to nb/GeV
   
  return Fac*Sum;

}


Double_t DSigmaDt_qq_QQbar_1S0_8(Double_t Xa, Double_t Pt, Double_t Y)
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


  Double_t Constt = 5.0*TMath::Power((4.0*pi*AlphaS),3.0)/(27.0*mJPsi);

  Double_t Num = TT2 + UU2;
  Double_t Deno = SS*(SS-mJPsi2)*(SS-mJPsi2);

  Double_t Amp = Constt*Num/Deno;

  Double_t Val =  Amp/(16.0*pi*SS2);
 
  return Val;

}


Double_t DSigmaDt_qq_QQbar_3S1_8(Double_t Xa, Double_t Pt, Double_t Y)
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
  
  Double_t Constt = TMath::Power((4.0*pi*AlphaS),3.0)/(81.0*mJPsi3);

  Double_t Term1 = mJPsi2*SS/(TMath::Power(SS-mJPsi2,4));
  
  Double_t Term2 = 4.0*(TT2+UU2)-TT*UU;

  Double_t Amp_h0 = 8.0*Constt*Term1*Term2;


  Double_t Term3 =(SS2+mJPsi4)/TMath::Power(SS-mJPsi2,4.0);

  Double_t Term4 = (TT2+UU2)/(TT*UU);

  Double_t Amp_h1 = 2.0*Constt*Term3*Term4*Term2;


  Double_t Amp = Amp_h0 + Amp_h1;

  Double_t Val = Amp/(16.0*pi*SS2);

  return Val;

}


Double_t DSigmaDt_qq_QQbar_3P0_8(Double_t Xa, Double_t Pt, Double_t Y)
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
  
  Double_t Constt = 20.0*TMath::Power((4.0*pi*AlphaS),3.0)/(81.0*mJPsi3);

  Double_t Term1 = (SS-3.0*mJPsi2)*(SS-3.0*mJPsi2)*(TT2+UU2);
  Double_t Term2 = SS*TMath::Power(SS-mJPsi2,4.0);

  Double_t Amp = Constt*Term1/Term2;

  Double_t Val = Amp/(16.0*pi*SS2);

  return Val;

  
}



//==================================================================================
// g+g-->QQbar + g partonic cross sections
//==================================================================================



Double_t DSigmaDPtDy_GG(Double_t Pt, Double_t Y)
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





Double_t Sum_GG_DSigmaDt(Double_t Xa, Double_t Pt, Double_t Y)
{

  Double_t Mt = TMath::Sqrt(mJPsi2 + Pt*Pt);
  
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 

  Double_t Term1 = DSigmaDt_GG_QQbar_3S1_1(Xa, Pt, Y)*OO_QQbar_3S1_1_JPsi;

  Double_t Term2 = DSigmaDt_GG_QQbar_1S0_8(Xa, Pt, Y)*OO_QQbar_1S0_8_JPsi;

  Double_t Term3 = DSigmaDt_GG_QQbar_3S1_8(Xa, Pt, Y)*OO_QQbar_3S1_8_JPsi;

  Double_t Term4 = DSigmaDt_GG_QQbar_3P0_8(Xa, Pt, Y)*OO_QQbar_3P0_8_JPsi;
  
  Double_t MtTerm = Xa*Xb/(Xa - (Mt*TMath::Exp(Y)/RootS));

  Double_t Sum = 2.0*Pt*MtTerm*(Term1+Term2+Term3);

  
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

  Double_t Constt = -(TMath::Power((4.0*pi*AlphaS),3))/(144.0*mJPsi3);

  Double_t Term1 = 2.0*mJPsi2*SS*(TT2 + UU2)*TT*UU/((SS-mJPsi2)*(SS-mJPsi2));
  
  Double_t Term2 = (27.0*(SS*TT + TT*UU + UU*SS) - 19.0*mJPsi4)/((SS-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2)*(SS-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2));

  Double_t H0_Amp = Constt*Term1*Term2;


  Double_t Term3 = (SS2*(TMath::Power((SS-mJPsi2),4) + TT2*TT2 + UU2*UU2 + 2.0*mJPsi4*TMath::Power((TT*UU/SS),2)))/TMath::Power((SS-mJPsi2),2);
  
 
  Double_t H1_Amp = Constt*Term3*Term2;

  Double_t  Amp = H0_Amp + H1_Amp; 

  Double_t Val = Amp/(16.0*pi*SS2);

  return Val;

}


Double_t DSigmaDt_GG_QQbar_3P0_8(Double_t Xa, Double_t Pt, Double_t Y)
{
  Double_t Mt = TMath::Sqrt(mJPsi2+Pt*Pt);
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 
  
  Double_t SS = Xa*Xb*RootS*RootS;

  Double_t TT = mJPsi2 - Xa*RootS*Mt*TMath::Exp(-Y);
  Double_t UU = mJPsi2 - Xb*RootS*Mt*TMath::Exp(Y);

  Double_t ZZ = TMath::Sqrt(TT*UU);  

  Double_t SS2 = SS*SS;
  Double_t SS4 = SS2*SS2;
  
  Double_t ZZ2 = ZZ*ZZ;
  Double_t ZZ4 = ZZ2*ZZ2;

  Double_t AlphaS = GetAlphaS(Mt);

  Double_t Constt = 5.0*TMath::Power((4.0*pi*AlphaS),3.0)/(12.0*mJPsi3);

  Double_t Term1 = SS2*ZZ4*TMath::Power((SS2 -ZZ2),4);
 

  Double_t Term2 = mJPsi2*SS*ZZ2*TMath::Power((SS2 -ZZ2),2)*(3.0*SS2 - 2.0*ZZ2)*(2.0*SS4 - 6.0*SS2*ZZ2 + 3.0*ZZ4);

  Double_t Term3 = mJPsi4*(9.0*SS4*SS4*SS4 - 84.0*SS4*SS4*SS2*ZZ2 + 265.0*SS4*SS4*ZZ4 - 382.0*SS4*SS2*ZZ4*ZZ2 + 276.0*SS4*ZZ4*ZZ4 - 88.0*SS2*ZZ4*ZZ4*ZZ2 + 9.0*ZZ4*ZZ4*ZZ4);

  Double_t Term4 = mJPsi4*mJPsi2*SS*(54.0*SS4*SS4*SS2 - 357.0*SS4*SS4*ZZ2 + 844.0*SS4*SS2*ZZ4 - 898.0*SS4*ZZ4*ZZ2* + 439.0*SS2*ZZ4*ZZ4 - 81.0*ZZ4*ZZ4*ZZ2);

  Double_t Term5 = mJPsi4*mJPsi4*(153.0*SS4*SS4*SS2 - 798.0*SS4*SS4*ZZ2 + 1415.0*SS4*SS2*ZZ4 - 1041.0*SS4*ZZ4*ZZ2* + 301.0*SS2*ZZ4*ZZ4 - 18.0*ZZ4*ZZ4*ZZ2);

  Double_t Term6 = mJPsi4*mJPsi4*mJPsi2*SS*(270.0*SS4*SS4 - 1089.0*SS4*SS2*ZZ2 + 1365.0*SS4*ZZ4 - 616.0*SS2*ZZ4*ZZ2* + 87.0*ZZ4*ZZ4);

  Double_t Term7 = mJPsi4*mJPsi4*mJPsi4*(324.0*SS4*SS4 - 951.0*SS4*SS2*ZZ2 + 769.0*SS4*ZZ4 - 189.0*SS2*ZZ4*ZZ2* + 9.0*ZZ4*ZZ4);

  Double_t Term8 = 9.0*mJPsi4*mJPsi4*mJPsi4*mJPsi2*SS*(6.0*SS2 - ZZ2)*(5.0*SS4 - 9.0*SS2*ZZ2 + 3.0*ZZ4);

  Double_t Term9 = 3.0*mJPsi4*mJPsi4*mJPsi4*mJPsi4*SS2*(51.0*SS4 - 59.0*SS2*ZZ2 + 12.0*ZZ4);

  Double_t Term10 = 27.0*mJPsi4*mJPsi4*mJPsi4*mJPsi4*mJPsi2*SS2*SS*(2.0*SS2 - ZZ2);

  Double_t Term11 = 9.0*mJPsi4*mJPsi4*mJPsi4*mJPsi4*mJPsi4*SS2*SS2;

  Double_t Term12 = SS*ZZ2*TMath::Power((SS-mJPsi2),4.0)*TMath::Power((SS*mJPsi2+ZZ2),4);

  

  Double_t Amp = Constt * (Term1 + Term2 + Term3 - Term4 + Term5 - Term6 + Term7 - Term8 + Term9 - Term10 + Term11) / Term12;

  
  Double_t Val = Amp/(16.0*pi*SS2);

  return Val; 

}



//============================================= Chi_c Functions ===================================//



//=================== gg --> QQbar g functions ==================================================//

Double_t DSigmaDt_GG_QQbar_3P0_1(Double_t Xa, Double_t Pt, Double_t Y)
{

  Double_t Mt = TMath::Sqrt(mJPsi2+Pt*Pt);
  Double_t Xb = (Xa*RootS*Mt*TMath::Exp(-Y)-mJPsi2)/(RootS*(Xa*RootS - Mt*TMath::Exp(Y))); 

  Double_t SS = Xa*Xb*RootS*RootS;
  Double_t TT = mJPsi2 - Xa*RootS*Mt*TMath::Exp(-Y);
  Double_t UU = mJPsi2 - Xb*RootS*Mt*TMath::Exp(Y);

  
  Double_t AlphaS = GetAlphaS(Mt);
  Double_t R02 = 0.49; 


  Double_t Constt = 5.0*pi*AlphaS*AlphaS*AlphaS*R02/(9.0*mJPsi*SS*SS);
  Double_t Term1 = mJPsi2/((SS-mJPsi2)*(SS-mJPsi2)*(TT-mJPsi2)*(TT-mJPsi2)*(UU-mJPsi2)*(UU-mJPsi2));
  Double_t Term2 = SS*SS*(SS-mJPsi2)*(SS-mJPsi2) + TT*TT*(TT-mJPsi2)*(TT-mJPsi2) + UU*UU*(UU-mJPsi2)*(UU-mJPsi2);

  Double_t Value =0.0;

  Value = Constt*Term1*Term2;
  return Value;
}
















//================ Test Functions ===========================//

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




Double_t quark_function(Int_t nf, Double_t x, Double_t Qsquare)
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

//==============================================================================================//
//=========================== DATA FUNCTIONS ===================================================//
//=============================================================================================//


void Draw_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt(TLegend *lgd)
{
  
  Double_t p8319_d1x1y1_xval[10] = { 8.569, 9.515, 10.494, 11.485, 12.711, 14.206, 16.329, 21.77, 35.03, 52.7 };
  
  Double_t p8319_d1x1y1_xerrminus[10] = { 0.5690000000000008, 0.5150000000000006, 0.4939999999999998, 0.48499999999999943, 
				       0.7110000000000003, 0.7059999999999995, 1.3290000000000006, 3.7699999999999996, 
				      5.030000000000001, 7.700000000000003 };
  Double_t p8319_d1x1y1_xerrplus[10] = { 0.43099999999999916, 0.48499999999999943, 0.5060000000000002, 0.5150000000000006, 
				      0.7889999999999997, 0.7940000000000005, 1.6709999999999994, 8.23, 9.969999999999999,
				      17.299999999999997 };
  Double_t p8319_d1x1y1_yval[10] = { 2.54, 1.56, 0.96, 0.612, 0.351, 0.184, 0.0841, 0.0139, 7.8E-4, 7.0E-5 };

  Double_t p8319_d1x1y1_yerrminus[10] = { 0.13601470508735444, 0.11224972160321824, 0.06, 0.0366742416417845, 0.020024984394500785, 
				      0.009486832980505138, 0.004423799272118932, 8.062257748298549E-4, 5.1961524227066324E-5, 
				      1.862793601019716E-5 };
  Double_t p8319_d1x1y1_yerrplus[10] = { 0.13601470508735444, 0.11224972160321824, 0.06, 0.0366742416417845, 0.020024984394500785, 
				     0.009486832980505138, 0.004423799272118932, 8.062257748298549E-4, 5.1961524227066324E-5,
				     1.862793601019716E-5 };
  Double_t p8319_d1x1y1_ystatminus[10] = { 0.07, 0.03, 0.02, 0.012, 0.006, 0.004, 0.0015, 2.0E-4, 3.0E-5, 7.0E-6 };
  Double_t p8319_d1x1y1_ystatplus[10] = { 0.07, 0.03, 0.02, 0.012, 0.006, 0.004, 0.0015, 2.0E-4, 3.0E-5, 7.0E-6 };


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt = new TGraphAsymmErrors(10,p8319_d1x1y1_xval, p8319_d1x1y1_yval, p8319_d1x1y1_xerrminus, 
										  p8319_d1x1y1_xerrplus, p8319_d1x1y1_yerrminus, p8319_d1x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->SetMarkerColor(kBlack+0);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt->Draw("AP");

  
  TBox *SystErr[10];
 
  for(int j=0;j<10;j++){
    SystErr[j] = new TBox(p8319_d1x1y1_xval[j]-0.5, p8319_d1x1y1_yval[j]-p8319_d1x1y1_ystatminus[j], p8319_d1x1y1_xval[j]+0.5, p8319_d1x1y1_yval[j]+p8319_d1x1y1_ystatplus[j]);
  }
  for(int j=0;j<10;j++){
    SystErr[j]->SetFillStyle(9001);
    SystErr[j]->SetLineColor(kBlack);
    SystErr[j]->Draw("same"); 
  }
  


  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  tb->DrawLatex(0.21,0.25,"pp #sqrt{s_{_{NN}}} = 7.0 TeV");
  tb->DrawLatex(0.21,0.20,"|y| #leq 0.9");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptJPsi_Y0009_Pt,"CMS prompt J/#psi", "P");
  
  
  
}


void Draw_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt(TLegend *lgd)
{
  
  double p8319_d2x1y1_xval[6] = { 8.524, 9.491, 10.921, 13.312, 18.95, 34.7 };
  double p8319_d2x1y1_xerrminus[6] = { 0.5239999999999991, 0.49099999999999966, 0.9209999999999994, 1.3119999999999994, 3.9499999999999993, 4.700000000000003 };
  double p8319_d2x1y1_xerrplus[6] = { 0.47600000000000087, 0.5090000000000003, 1.0790000000000006, 1.6880000000000006, 11.05, 10.299999999999997 };
  double p8319_d2x1y1_yval[6] = { 2.62, 1.55, 0.75, 0.248, 0.0264, 6.7E-4 };
  double p8319_d2x1y1_yerrminus[6] = { 0.1972308292331602, 0.14317821063276354, 0.053851648071345036, 0.01746424919657298, 0.0014352700094407323, 8.366600265340756E-5 };
  double p8319_d2x1y1_yerrplus[6] = { 0.1972308292331602, 0.14317821063276354, 0.053851648071345036, 0.01746424919657298, 0.0014352700094407323, 8.366600265340756E-5 };
  double p8319_d2x1y1_ystatminus[6] = { 0.08, 0.05, 0.02, 0.006, 6.0E-4, 6.0E-5 };
  double p8319_d2x1y1_ystatplus[6] = { 0.08, 0.05, 0.02, 0.006, 6.0E-4, 6.0E-5 };


  TGraphAsymmErrors *Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt = new TGraphAsymmErrors(6,p8319_d2x1y1_xval, p8319_d2x1y1_yval, p8319_d2x1y1_xerrminus, 
										  p8319_d2x1y1_xerrplus, p8319_d2x1y1_yerrminus, p8319_d2x1y1_yerrplus);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->SetMarkerStyle(20);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->SetMarkerColor(kBlack+0);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->SetMarkerSize(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetYaxis()->SetTitleOffset(1.6);
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetYaxis()->SetRangeUser(0.000001,10000.0);
  
  TAxis *Xaxis1 = Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetXaxis();
  Xaxis1->SetLimits(0.0,70.0);
   

  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetXaxis()->SetTitle("p_{T}[GeV/c]");
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dp_{T}dy}[nb/GeV]");
  
  Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt->Draw("AP");

  
  TBox *SystErr[6];
 
  for(int j=0;j<6;j++){
    SystErr[j] = new TBox(p8319_d2x1y1_xval[j]-0.5, p8319_d2x1y1_yval[j]-p8319_d2x1y1_ystatminus[j], p8319_d2x1y1_xval[j]+0.5, p8319_d2x1y1_yval[j]+p8319_d2x1y1_ystatplus[j]);
  }
  for(int j=0;j<6;j++){
    SystErr[j]->SetFillStyle(9001);
    SystErr[j]->SetLineColor(kBlack);
    SystErr[j]->Draw("same"); 
  }
  

  TLatex *tb= new TLatex;
  tb->SetNDC(); 
  tb->SetTextAlign(12);
  tb->SetTextColor(1);
  tb->SetTextSize(0.040);
  tb->DrawLatex(0.21,0.25,"pp #sqrt{s_{_{NN}}} = 7.0 TeV");
  tb->DrawLatex(0.21,0.20,"0.9 #leq |y| #leq 1.2");
 
  lgd->AddEntry(Grf_CMS_D2NDPtDy_PromptJPsi_Y0912_Pt,"CMS prompt J/#psi", "P");
  
   
}

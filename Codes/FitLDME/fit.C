#include "TMinuit.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TGraphErrors.h"
#include "TAxis.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TMath.h"

// Valeri Fine 07/08/2009 (for Vitali Okorokov)
// 1. Points for linear function 

/*
const int nPoints1 = 5;
Double_t ux1[5]={1.0, 10.0, 20.0, 30.0, 40.0}; 
Double_t uy1[5]={10000, 1100, 105, 12, 2};
Double_t ex1[] = {0.0,0.0,0.0,0.0,0.0};
Double_t ey1[] = {10.0,10.0,10.0,1.0,0.2};
//
const int nPoints2 = 5;
Double_t x2[5]={1.0, 10.0, 20.0, 30.0, 40.0}; 
Double_t y2[5]={12000, 2000, 110, 20, 6};
Double_t ex2[5] = {0.0,0.0,0.0,0.0,0.0};
Double_t ey2[5] = {10.0,10.0,10.0,1.0,0.2};
*/

TGraphErrors *gr1;
TGraphErrors *gr2;

Double_t myFunc_1(Double_t *xp, Double_t *par) 
{
  // ------- approximation function -------
  Double_t x=*xp;
  return par[0]*TMath::Exp(-par[1]*x);
}

//-------------------------------------------------------------------
// 2. Quadratic function 
//------------------------------------------------------------------- 
Double_t myFunc_2(Double_t *xp, Double_t *par) 
{
  // ------- approximation function -------
  Double_t x=*xp;
  return par[0]*TMath::Exp(-par[1]*x - par[2]*x*x);
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
    Double_t delta  = (yy1[i]-myFunc_1(&xx1[i],par))/erryy1[i];
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
    //Double_t delta  = (y2[i]-myFunc_2(&x2[i],par))/ey2[i];
    Double_t delta  = (yy2[i]-myFunc_2(&xx2[i],par))/erryy2[i];
    chisq += delta*delta;
  }
  return chisq;
}

//______________________________________________________________________________
void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
  f = fcn1(npar,gin,par, iflag) + fcn2(npar,gin, par, iflag);
}


//-------------------------------------------------------------------
//
void fit()
//void SimultFit_MyTest()
{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gStyle->SetPadGridX(0);
  gStyle->SetPadGridY(0);
  gStyle->SetOptDate(0);
  gStyle->SetOptFit(1111);
  

  TCanvas *c1 = new TCanvas("c1","Simultaneous fit: test",800,800);
  c1->SetBorderSize(0);
  c1->SetFillStyle(4000);

  // ------------>Primitives in pad: c1_1
  TPad *c1_1 = new TPad("c1_1", "c1_1",0.01,0.01,0.99,0.99);
  c1_1->Draw();
  c1_1->cd();
  c1_1->SetTopMargin(0.03);
  c1_1->SetBottomMargin(0.14);
  c1_1->SetRightMargin(0.06);
  c1_1->SetLeftMargin(0.11);




  const int nPoints1 = 5;
  Double_t x1[]={1.0, 10.0, 20.0, 30.0, 40.0}; 
  Double_t y1[]={10000, 1100, 105, 12, 2};
  Double_t ex1[] = {0.0,0.0,0.0,0.0,0.0};
  Double_t ey1[] = {10.0,10.0,10.0,1.0,0.2};
  gr1 = new TGraphErrors(nPoints1,x1,y1,ex1,ey1);
  gr1->SetMarkerStyle(20);
  gr1->SetMarkerSize(1.4);
  gr1->SetMarkerColor(kBlue);
  gr1->SetLineColor(kBlue);
  gr1->SetFillColor(0);
  gr1->SetLineWidth(2);

  const int nPoints2 = 5;
  Double_t x2[]={1.0, 10.0, 20.0, 30.0, 40.0}; 
  Double_t y2[]={12000, 2000, 110, 20, 6};
  Double_t ex2[5] = {0.0,0.0,0.0,0.0,0.0};
  Double_t ey2[5] = {10.0,10.0,10.0,1.0,0.2};
  gr2 = new TGraphErrors(nPoints2,x2,y2,ex2,ey2);
  gr2->SetMarkerStyle(21);
  gr2->SetMarkerSize(1.2);
  gr2->SetMarkerColor(kRed);
  gr2->SetLineColor(kRed);
  gr2->SetFillColor(0);
  gr2->SetLineWidth(2);


  // create a MultiGraph
  TMultiGraph *mg1 = new TMultiGraph();
  mg1->SetTitle("");   
  mg1->Add(gr1);
  mg1->Add(gr2);
  mg1->Draw("AP");
  gPad->SetLogy(1);
  // X-axis
  TAxis *axisx1=mg1->GetXaxis();
  axisx1->SetTickLength(0.025);
  axisx1->SetLabelSize(0.045);
  axisx1->SetTitle("x");
  axisx1->SetTitleSize(0.05);
  axisx1->SetTitleOffset(0.9);
  axisx1->Draw();
  gPad->SetTickx();
  axisx1->Draw();
  gPad->SetTickx();
  // Y-axis
  TAxis *axisy1=mg1->GetYaxis();
  //   axisy1->SetRangeUser(0.,5.);
  axisy1->SetLabelSize(0.055);
  axisy1->SetTickLength(0.017);
  // axisy1->SetNdivisions(804);
  axisy1->SetTitle("y");
  axisy1->SetTitleSize(0.065);
  axisy1->SetTitleOffset(0.65);
  axisy1->Draw();
  gPad->SetTicky();
  


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
  static Double_t vstart[] = {10000, 1,  0};
  static Double_t step[]   = {0.1, 0.1 , 0.1};

  gMinuit->mnparm(0, "a0", vstart[0], step[0], 0, 0, ierflg);
  gMinuit->mnparm(1, "a1", vstart[1], step[1], 0, 0, ierflg);
  gMinuit->mnparm(2, "a2", vstart[2], step[2], 0, 0, ierflg);
  
  // Now ready for minimization step
  arglist[0] = 1000;
  arglist[1] = 1.;
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

  // 1. Linear function
  TF1 *fun_1=new TF1("fun_1",myFunc_1, 0.0, 40.0, 2); 	
  fun_1->SetParameters(currentPar);
  fun_1->SetLineColor(kBlue);
  fun_1->SetLineStyle(1);
  fun_1->SetLineWidth(2);
  //     mg1->Add(new TGraph(fun_1));
  fun_1->Draw("same");
  
  TF1 *fun_2=new TF1("fun_2",myFunc_2, 0.0, 40.0, 3);
  fun_2->SetParameters(currentPar);
  fun_2->SetLineColor(kRed);
  fun_2->SetLineStyle(1);
  fun_2->SetLineWidth(4);
  //     mg1->Add(new TGraph(fun_2));
  fun_2->Draw("same");

  TLegend *legend = new TLegend(0.52,0.95,0.95,0.85);
  legend->AddEntry(gr1,Form("%f * Exp(-%fx)", currentPar[0], currentPar[1]));
  legend->AddEntry(gr2,Form("%f * Exp(-%fx - %fx^2)", currentPar[0], currentPar[1], currentPar[2]));
  legend->Draw();
  //-
  c1_1->Modified();
  c1->cd();
  c1->Modified();
  //
  c1->Update();
}


















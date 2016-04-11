// myFitMINUIT.C
// S. Stave
// July, 2009
// --------------------------------------------------
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
#include "TH2F.h"
#include "TSystem.h"
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

TH2F *h_chi2;

Char_t Tag[2][255];
Double_t var[2], verr[2];
Double_t err_mat[2][2];

//0: x, 1: y, 2: yerr
Double_t dat[3][5];
Int_t n_dat=5;



void fcn(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par,
         Int_t iflag ) {
  Double_t sum=0;

  //Calculate chi2
  for (int i=0;i<n_dat;i++){
    sum+=pow((dat[1][i]-(par[0]*dat[0][i]+par[1]))/dat[2][i],2.0);
  }
  
  f=sum;

}

Double_t chi2(Double_t par[]){
  Double_t sum=0;
  
  //Calculate chi2
  for (int i=0;i<n_dat;i++){
    sum+=pow((dat[1][i]-(par[0]*dat[0][i]+par[1]))/dat[2][i],2.0);
  }
  
  return sum;

}



void myFitMINUIT(){
  gSystem->Load("libMinuit.so");
  TCanvas *c2 = new TCanvas("c2","Chi2",100,100,800,600);
  TCanvas *c1 = new TCanvas("c1","Fit",50,50,800,600);
  c1->SetFillColor(0);
  c2->SetFillColor(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptDate(0);
  gStyle->SetPalette(1);

  //Example data points
  //These could be loaded using ifstream or from a TGraph or histogram
  //Usually faster to load the data into an array
  dat[0][0]=1;
  dat[1][0]=1.1;
  dat[2][0]=0.2;
  dat[0][1]=2;
  dat[1][1]=1.9;
  dat[2][1]=0.2;
  dat[0][2]=3;
  dat[1][2]=3.2;
  dat[2][2]=0.2;
  dat[0][3]=4;
  dat[1][3]=4.1;
  dat[2][3]=0.2;
  dat[0][4]=5;
  dat[1][4]=4.9;
  dat[2][4]=0.2;

  //Set parameter names, starting values and initial step size
  Char_t PARM_NAMES[2][255]={"m","b"};
  Double_t PARM_START[2]={1,1};
  Double_t PARM_STEP[2]={0.1,0.1};


  //Initialize the TMinuit object with 2 fitting parameters
  //Can handle over 20
  TMinuit *gMinuit= new TMinuit(2);
  gMinuit->SetFCN( fcn );

  Double_t arglist[10];
  Int_t ivarbl,ierflg;
  Double_t bnd1, bnd2;

  /*
  arglist[0]=-1;
  gMinuit->mnexcm("SET PRINT", arglist, 1, ierflg);
  arglist[0]=1;
  gMinuit->mnexcm("SET NOWarnings", arglist, 1, ierflg);
  */

  /* set starting values and steps */
  Int_t i,j;
  for (i=0; i<2; i++) {
    gMinuit->mnparm( i, PARM_NAMES[i], PARM_START[i], PARM_STEP[i], 
		     0, 0, ierflg );
  }

  //This is where the delta chi2 is defined
  //This is critical to getting the correct error estimates
  arglist[0] = 1.0;
  if (arglist[0]) gMinuit->mnexcm("SET ERR", arglist, 1, ierflg);

  arglist[0] = 1000;            // do at least 1000 function calls
  arglist[1] = 0.1;             // tolerance = 0.1

  gMinuit->mnexcm("MIGRAD", arglist, 2, ierflg );

  //for (i=0; i<2; i++) {
  //gMinuit->mnpout( i, Tag[i], var[i], verr[i], bnd1, bnd2, ivarbl);
  //}

  //Get error matrix
  gMinuit->mnemat(&err_mat[0][0],2);


  for (i=0;i<2;i++){
    printf("%s: %f +/- %f\n",PARM_NAMES[i],var[i],verr[i]);
  }

  printf("Error matrix:\n");
  for (i=0;i<2;i++){
    printf("%f %f\n",err_mat[0][i],err_mat[1][i]);
  }

  TGraphErrors *gr=new TGraphErrors(n_dat,dat[0],dat[1],0,dat[2]);

  gr->SetMarkerStyle(8);
  gr->SetMarkerSize(0.5);
  gr->SetMarkerColor(2);
  gr->SetLineColor(2);

  TH2F *h = new TH2F("h","Fit Example",100,0,6,100,0,10);

  h->SetXTitle("X Axis [units]");
  h->SetYTitle("Y Axis [units]");

  TF1 *f1 = new TF1("f1","[0]*x+[1]",0,5);
  f1->SetParameters(var[0],var[1]);
  f1->SetLineWidth(1);
  f1->SetLineColor(3);


  TLegend *leg = new TLegend(0.8,0.8,0.98,0.98);
  leg->AddEntry(gr,"Data","P");
  leg->AddEntry(f1,"Fit","L");

  c1->cd();
  h->Draw();
  gr->Draw("P");
  f1->Draw("Lsame");
  leg->Draw();

  h_chi2=new TH2F("h_chi2","#chi^2",100,0.6,1.4,100,-1,2);

  Double_t par[2];

  for (i=1;i<=h_chi2->GetNbinsX();i++){
    for (j=1;j<=h_chi2->GetNbinsY();j++){
      par[0]=h_chi2->GetXaxis()->GetBinCenter(i);
      par[1]=h_chi2->GetYaxis()->GetBinCenter(j);

      h_chi2->SetBinContent(i,j,chi2(par));
    }
  }

  c2->cd();
  //  h_chi2->SetMaximum(30);
  //  h_chi2->Draw("surf2z");
  h_chi2->Draw("colz");
  gPad->SetLogz();
}

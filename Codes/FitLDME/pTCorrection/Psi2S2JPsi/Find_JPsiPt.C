#include "TCanvas.h"
#include "TROOT.h"
#include "TAxis.h"
#include "TH1.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TF1.h"
#include "TH1I.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TMath.h"
#include "TVector3.h"
#include "TString.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TLatex.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;

double pol1(double *x, double *par)
{
  double pol = par[0] + par[1]*x[0];
  return pol;
}

void Find_JPsiPt()
{
  double pt_bound[200] = {0.0};
  double PT[200], DelPT[200];
  double YPT[200], DelYPT[200];
  
  int Nptbin = 120;
  //int Nptbin = 70;
  
  double step =0.1;
  
  cout<<" pT Bins "<<endl;
  for (Int_t ih = 0; ih < Nptbin; ih++) {
    pt_bound[ih] = 0 + step*ih;
    pt_bound[ih+1] = 0 + step*(ih+1);
    
    PT[ih] = (pt_bound[ih] + pt_bound[ih+1])/2.0;
    DelPT[ih] = (pt_bound[ih+1] - pt_bound[ih])/2.0;
    
    cout<<PT[ih]<<"    "<<DelPT[ih]<<endl;

  }
  

  char namePt[500];
  
  TFile *fpT = new TFile("Psi2s5M_pythia.root");
  
  //
  //TH2D *JPt_BPt = (TH2D*)fpT->Get("Chic1VsJPsi_Pt");
  //TH2D *JPt_BPt = (TH2D*)fpT->Get("Psi2SVsJPsi_Pt");
  TH2D *JPt_BPt = (TH2D*)fpT->Get("Psi2SVsChic0_Pt");

  new TCanvas;
  JPt_BPt->Draw("colz");

  TH1D *service = (TH1D*)JPt_BPt->ProjectionX("service");
  TAxis *xaxis = service->GetXaxis();

  for(int i=0;i<service->GetSize();i++)
    {
      Double_t binCenter = xaxis->GetBinCenter(i);
      cout<<binCenter<<endl;

    }

  
  //return;

  //service->Draw();
  cout<<" service  "<<service<<endl;

  int pt_bin_bound[200];

  TH1D *ProfY_BPt[200];

  
  for (Int_t ih = 0; ih < Nptbin; ih++) {
  
    pt_bin_bound[ih] = service->FindBin(pt_bound[ih]);
    pt_bin_bound[ih+1] = service->FindBin(pt_bound[ih+1]);
    
    sprintf(namePt,"BPt_%d",ih);
    
    //ProfY_BPt[ih] = (TH1D*)JPt_BPt->ProjectionY(namePt, pt_bin_bound[ih], pt_bin_bound[ih+1]-1,"e");
    
    ProfY_BPt[ih] = (TH1D*)JPt_BPt->ProjectionY(namePt, pt_bin_bound[ih], pt_bin_bound[ih+1],"e");
    YPT[ih] = ProfY_BPt[ih]->GetMean();
    DelYPT[ih] = ProfY_BPt[ih]->GetRMS();
    
    cout<< YPT[ih] <<" /pm "<<  DelYPT[ih]<< endl<<endl;

  }
  
  TGraphErrors *gr_BpTvsJpT = new TGraphErrors(Nptbin, PT, YPT, DelPT, DelYPT);
  TF1 *func_BpTvsJpT = new TF1("pol1", pol1, 0, 20, 2); 
  func_BpTvsJpT->SetLineColor(2);
  gr_BpTvsJpT->Fit("pol1","","",0,20);
  gr_BpTvsJpT->GetXaxis()->SetRangeUser(0,20);
  gr_BpTvsJpT->GetXaxis()->SetTitle("J/#psi p_{T}");
  gr_BpTvsJpT->GetYaxis()->SetTitle("#psi(2S) p_{T}");
  new TCanvas;
  gr_BpTvsJpT->Draw("ap");
  func_BpTvsJpT->Draw("same");
}

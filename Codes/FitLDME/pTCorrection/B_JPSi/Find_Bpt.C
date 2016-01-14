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

void Find_Bpt()
{
  
  double BpT[100]={0},BpTEr[100]={0},JpT[100]={0};
  double BpTPlus[100]={0},BpTMinus[100]={0};
  
  //double a0 = 0.604865,a0Er = 0.00790439,a1 = 1.03837, a1Er = 0.00381658;
  //double a0 = 0.680535 ,a0Er =0.00465789 ,a1 =0.978251 , a1Er =0.0010945 ; //pol1
  //double a0 =0.767454,a0Er =0.00637919 ,a1 =0.926482, a1Er =0.00281732; // pol2

  // Acceptance
  //double a0 =0.627337,a0Er =0.0049568,a1 =1.02592, a1Er =0.0010564; // pol1
  //double a0 =0.742605,a0Er =0.00714768 ,a1 =0.957962, a1Er =0.00321474; // pol2

  //New Acceptance
  //double a0 = 0.718407,a0Er =0.0106664 ,a1 =1.1037, a1Er =0.00138381; //pol1
  double a0 =0.491983 ,a0Er =0.0178676 ,a1 =1.1242, a1Er =0.00296712; //pol1
  
  char OutTextFile[100]; 
  sprintf(OutTextFile,"Find_BpT.txt");
  ofstream dataFile(Form(OutTextFile),ios::app);

  for(int i=1;i<=30;i++)
    {
      BpT[i] = a0 + a1*i; 
      BpTPlus[i] = a0 + a0Er + (a1+a1Er)*i; 
      BpTMinus[i] = a0 - a0Er + (a1-a1Er)*i; 
      BpTEr[i] = (BpTPlus[i]-BpTMinus[i])/2.0;
      
      //dataFile<<setprecision(4);
      //if(i==1)dataFile<<" J/#psi pT  "<<" B pT   "<<endl;
      //dataFile<<i<<"    &"<<BpT[i]<<" /pm "<<BpTEr[i]<<endl;
      
      //cout<<i<<"    &"<<BpT[i]<<" /pm "<<BpTEr[i]<<endl;
      //cout<<"==============================================="<<endl;
    }
  
  // Pt bin sizes

  double pt_bound[100] = {0.0};
  double PT[100], DelPT[100];
  double YPT[100], DelYPT[100];

  int Nptbin = 20;
  double step =0.5;

  for (Int_t ih = 0; ih < Nptbin; ih++) {
    pt_bound[ih] = 1 + step*ih;
    pt_bound[ih+1] = 1 + step*(ih+1);
    PT[ih] = (pt_bound[ih] + pt_bound[ih+1])/2.0;
    DelPT[ih] = (pt_bound[ih+1] - pt_bound[ih])/2.0;
  }

  char namePt[500];
  char text[100],text1[100],text2[100];

  TFile *fpT = new TFile("hist1.root");
  //  TH2D *JPt_BPt = (TH2D*)fpT->Get("JpTBpTAccpt");
  TH2D *JPt_BPt = (TH2D*)fpT->Get("JpTBpT");
  
  new TCanvas;
  JPt_BPt->Draw("colz");

  TH1D *service = (TH1D*)JPt_BPt->ProjectionX("service");
  
  //service->Draw();
  //cout<<" service  "<<service<<endl;

  int pt_bin_bound[100];

  TH1D *ProfY_BPt[100];

  cout<<"  J/psi pT  " << "  B pT Mean  "<< "  BpT RMS  " <<endl;
  dataFile<<"  J/psi pT  " << "  B pT Mean  "<< "  BpT RMS  " <<endl;

  for (Int_t ih = 0; ih < Nptbin; ih++) {
  
    
    pt_bin_bound[ih] = service->FindBin(pt_bound[ih]);
    //cout<<" pt_bin_bound[ih]  "<<pt_bin_bound[ih]<<endl;
    
    pt_bin_bound[ih+1] = service->FindBin(pt_bound[ih+1]);
    //cout<<" pt_bin_bound[ih+1]  "<<pt_bin_bound[ih+1] -1<<endl;
    
    sprintf(namePt,"BPt_%d",ih);
    
    ProfY_BPt[ih] = (TH1D*)JPt_BPt->ProjectionY(namePt, pt_bin_bound[ih], pt_bin_bound[ih+1]-1);
    sprintf(text," %.1f-%.1f ",  service->GetBinLowEdge(pt_bin_bound[ih]), 
	      service->GetBinLowEdge(pt_bin_bound[ih+1]-1)+service->GetBinWidth(pt_bin_bound[ih+1]));
    
    dataFile<<setprecision(2);

    cout<< text <<"  "<< ProfY_BPt[ih]->GetMean()<<" /pm "<< ProfY_BPt[ih]->GetRMS()<< endl<<endl;

    YPT[ih] = ProfY_BPt[ih]->GetMean();
    DelYPT[ih] = ProfY_BPt[ih]->GetRMS();

    cout<< text <<"  "<< YPT[ih] <<" /pm "<<  DelYPT[ih]<< endl<<endl;

    sprintf(text1," %.1f ", YPT[ih]);
    sprintf(text2," %.1f ", DelYPT[ih]);
    dataFile<< text <<"  &"<< text1<<" /pm   "<< text2<< endl<<endl;

    /*
    if(ih ==1 || ih ==4 ||ih ==5 ||ih == 9 ||ih ==14 ||ih ==19 || ih ==29)
      {
	new TCanvas;
	ProfY_BPt[ih]->Draw();
      }
    */
  }
  
  dataFile.close();


  /* TGraphErrors *gr_BpTvsJpT = new TGraphErrors(Nptbin, PT, YPT, DelPT, DelYPT);
  TF1 *func_BpTvsJpT = new TF1("pol1", pol1, 0, 24, 2); 
  func_BpTvsJpT->SetLineColor(2);
  gr_BpTvsJpT->Fit("pol1","","",0,24);
  gr_BpTvsJpT->GetXaxis()->SetRangeUser(0,25);
  // gr_BpTvsJpT->GetYaxis()->SetRangeUser(0,25);
  gr_BpTvsJpT->Draw("ap");
  func_BpTvsJpT->Draw("same");
  */

  TGraphErrors *gr_BpTvsJpT = new TGraphErrors(Nptbin, PT, YPT, DelPT, DelYPT);
  TF1 *func_BpTvsJpT = new TF1("pol1", pol1, 0, 10, 2); 
  func_BpTvsJpT->SetLineColor(2);
  gr_BpTvsJpT->Fit("pol1","","",0,6);
  gr_BpTvsJpT->GetXaxis()->SetRangeUser(0,10);
  gr_BpTvsJpT->Draw("ap");
  func_BpTvsJpT->Draw("same");
}

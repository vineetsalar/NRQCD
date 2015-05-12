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
#ifndef __CINT__
#endif
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

// For Parton Distribution Function
double quark_function(int nf, double x, double Qsquare);

void LHAPDF_Partha()
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




  return;
  
 
}
  
  

Double_t quark_function(int nf, double x,double Qsquare)
{
  double  Q=TMath::Sqrt(Qsquare);
  
  double xFx = 0.0;
  if ( ( x > 0.00000001 && x < 1.0 ) && (Q<100000 && Q > 0.3) ) xFx =  LHAPDF::xfx(x, Q, nf);  
  
  return xFx;
  
}

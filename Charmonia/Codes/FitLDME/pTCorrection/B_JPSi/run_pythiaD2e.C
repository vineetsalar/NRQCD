#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

//ROOT
#include "TSystem.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TRandom.h"
#include "TObjArray.h"
#include "TClonesArray.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TParticle.h"
#include "TPythia6.h"
#include "TMCParticle.h"
#include "TParticlePDG.h"
#include "/home/kapil/root/include/TPythia6.h"

using namespace std;

int run_pythiaD2e(int numberEvents =1000000, TString OutFile = "oscar.input")
{
  //TROOT root("pythia","run pythia");

  ofstream foutd(OutFile);
  foutd<<"# OSC1999A"<<endl;
  foutd<<"# final_id_p_x"<<endl;
  foutd<<"# EXODUS event generator in full event mode"<<endl;
  foutd<<"#"<<endl;
  
  const int MAXDIM = 10000; // No. of particles in an event.
  
  int pid[10000];
  double px[10000], py[10000], pz[10000], energy[10000], mass[10000];
  double vx[10000], vy[10000], vz[10000], time[10000]; 
  //  int dim_count = 0;
  const double mm_to_fm = 1e12;
  
  // CREATE PYTHIA OBJECT
  // =====================
  
  TPythia6 pythia;
  
  // ================================================================
  // INITIALIZATION SECTION: SET ANY PYTHIA INPUT PARAMETERS HERE 
  // ================================================================
  
  Char_t  targ[10] = "p";        // target 
  Char_t  proj[10] = "p";	 // projectile
  double rootS = 200;            // center of mass energy at rhic

  pythia.SetMSTP(51,7);       // Set structure function  // 8 -> CTEQ 5M1 (MS) (NLO!)
                              //  4 -> GRV 94L (Leading Order)
                              //  7 -> CTEQ 5L (Leading Order) !Default!

  pythia.SetMSTP(32,8);                     // Q^2 = s_hat  !Default=8!
  pythia.SetMSTP(91,1);                     // Use Gaussian Kt distribution

  pythia.SetPARP(91,2.0);                  // set width of kT gaussian 1.5 !Default=2!
  pythia.SetPARP(93,5.0);                  // Kt cut off  5 !Default=5!
  pythia.SetCKIN(3,0);                     // min Pt  0 !Default=0!
  
  // Switching On the processes to generate
  pythia.SetMSEL(0);                        // Global process turned off{run is in full user control}
  pythia.SetMSUB(81,1);                      // Turn On subprocess qqbar->Q Qbar
  pythia.SetMSUB(82,1);                        // Turn On subprocess gg->Q Qbar 
  //  pythia.SetMSUB(96,0);                   // Turn OFF subprocess 
  pythia.SetMSTP(7,4);                       // 4 is for charm quark(charm q production)

  pythia.SetPMAS(pythia.Pycomp(4),1,1.3);  // Set charm quark mass to 1.3 GeV

  // Turn off all decay channels 
  //     for (Int_t idc=1; idc<=4285; idc++) pythia.SetMDME(idc,1,0);
  
  // Decay channels
  //  pythia.SetMDME(673,1,1); // e+ nu_e Kbar0
  //  pythia.SetMDME(674,1,1); // e+ nu_e K*bar0

  for (Int_t idc=673; idc<=683; idc++) pythia.SetMDME(idc,1,1);  // turn ON electron decay channels for D+/-
  for (Int_t idc=684; idc<=694; idc++) pythia.SetMDME(idc,1,0);  // turn OFF muon decay channels for D+/-
  for (Int_t idc=695; idc<=735; idc++) pythia.SetMDME(idc,1,0);  // turn OFF hadron decay channels for D+/-

  for (Int_t idc=819; idc<=823; idc++) pythia.SetMDME(idc,1,1);  // turn ON electron decay channels for Ds+/-
  for (Int_t idc=824; idc<=828; idc++) pythia.SetMDME(idc,1,0);  // turn OFF muon decay channels for Ds+/-
  for (Int_t idc=828; idc<=850; idc++) pythia.SetMDME(idc,1,0);  // turn OFF hadron decay channels for Ds+/-
  
  for (Int_t idc=747; idc<=754; idc++) pythia.SetMDME(idc,1,1);  // turn ON electron decay channels for D0/bar
  for (Int_t idc=755; idc<=762; idc++) pythia.SetMDME(idc,1,0);  // turn OFF muon decay channels for D0/bar

  pythia.SetMDME(763,1,0);                                      // K- pi+
  for (Int_t idc=764; idc<=807; idc++) pythia.SetMDME(idc,1,0);  // turn OFF hadron decay channels for D0/bar
  
  // Projectile, Target and center of mass energy

  pythia.Initialize("CMS", targ, proj, rootS);   // simulates RHIC energies
  
  // ===========================================
  // END OF THE INITIALIZATION SECTION
  // ===========================================
  
  // set the random seed
  // Int_t seed = (Int_t)(time(NULL)/3);
  int seed = 123456789;
  if ( (seed>=0) && (seed<=900000000) ) {
    pythia.SetMRPY(1, seed);			// set seed
    pythia.SetMRPY(2, 0);			// use new seed
  }
  else {
    cout << "error: time " << seed << " is not valid" << endl;
    exit(2);
  }
  
  // If you want to see the list of all decay channels
  // pythia.Pylist(12);
       

  //Define styles

  gStyle->SetCanvasDefH(600);
  gStyle->SetCanvasDefW(600);

  gStyle->SetOptDate(0);
  gStyle->SetOptTitle(0);
  //  gStyle->SetOptStat(0);
  gStyle->SetCanvasColor(0);

  gStyle->SetPadBorderMode(0);
  gStyle->SetPadColor(0);  

  gStyle->SetPadLeftMargin(0.13);
  gStyle->SetPadBottomMargin(0.10);
  gStyle->SetPadTopMargin(0.03);
  gStyle->SetPadRightMargin(0.04);

  gStyle->SetTitleOffset(1.2,"x");
  gStyle->SetTitleOffset(1.3,"y");
  gStyle->SetTitleOffset(1.3,"z");

  gStyle->SetTitleSize(.04, "xyz");

  gStyle->SetPalette(1);


  // Define Histograms here

  TH1F *hMass1 = new TH1F("hMass1", "hMass1", 100,0,4);
  hMass1->GetXaxis()->SetTitle("Invariant Mass M for Kpi pair");
  hMass1->GetYaxis()->SetTitle("Entries");
  hMass1->GetXaxis()->CenterTitle();
  hMass1->GetYaxis()->CenterTitle();
  hMass1->SetLineColor(4);

  TH1F *hMass2 = new TH1F("hMass2", "hMass2", 100,0,4);
  hMass2->GetXaxis()->SetTitle("Invariant Mass M for Kpi pair");
  hMass2->GetYaxis()->SetTitle("Entries");
  hMass2->SetLineColor(2);

  TH1F *hMass3 = new TH1F("hMass3", "hMass3", 100,0,4);
  hMass3->GetXaxis()->SetTitle("Invariant Mass M for Kpi pair");
  hMass3->GetYaxis()->SetTitle("Entries");
  hMass3->GetXaxis()->CenterTitle();
  hMass3->GetYaxis()->CenterTitle();
  hMass3->SetLineColor(2);


  TH1F *ppt1 = new TH1F("ppt1", "ppt1", 100,0,180);
  ppt1->GetXaxis()->SetTitle("Angle between  K pi  ");
  ppt1->GetYaxis()->SetTitle("Entries");
  ppt1->GetXaxis()->CenterTitle();
  ppt1->GetYaxis()->CenterTitle();
  ppt1->SetLineColor(4);
  
  TH1F *ppt2 = new TH1F("ppt2", "ppt2", 100,0,180);
  ppt2->GetXaxis()->SetTitle("Angle between  K pi  ");
  ppt2->GetYaxis()->SetTitle("Entries");
  ppt2->SetLineColor(2);
  
  TH1F *ppt3 = new TH1F("ppt3", "ppt3", 100,0,180);
  ppt3->GetXaxis()->SetTitle("Angle between  K pi  ");
  ppt3->GetYaxis()->SetTitle("Entries");
  ppt3->GetXaxis()->CenterTitle();
  ppt3->GetYaxis()->CenterTitle();
  ppt3->SetLineColor(2);


  // Jpsi means electron and B means D here
  TH2F *JpTBpT = new TH2F("JpTBpT", "JpTBpT", 500, 0,50, 500,0,50);
  JpTBpT->GetXaxis()->SetTitle("Electron p_{T}(GeV) ");
  JpTBpT->GetYaxis()->SetTitle(" D meson p_{T}(GeV)");
  JpTBpT->GetXaxis()->CenterTitle(); 
  JpTBpT->GetYaxis()->CenterTitle();
  JpTBpT->SetLineColor(2);




  float RadtoDeg = 180/(TMath::ATan(1)*4);

  // ===========================================
  // CREATE ROOT OUTPUT FILE AND DEFINE T TREE
  // ===========================================
  TFile*rootfile = new TFile("pythia.root", "recreate");
  TClonesArray *particleArray = new TClonesArray();
  TMCParticle  *particle = new TMCParticle();
  
  int eventNo =0;
  TTree *evTree = new TTree("evTree", "Event tree");
  evTree->Branch("particle", "TMCParticle", &particle);
  evTree->Branch("evt", &eventNo, "evt/I"); 

  TParticle *tepart;
  TMCParticle *pe;  // parent particle

  int pdgcode, idparent, parentPDG, mode=0;
  
  float pxx, pyy, pzz, ener, vxx, vyy, vzz, pt, vertex, etat, phit, mp1, mp2, charge;
 
  float pt1,pt2,eta1,eta2,phi1,phi2, minv,px1,px2,py1,py2,pz1,pz2,ppt,theta1,theta;
  
  int nTpart = 0;
  int nDeventsEX =0;
  int nKpi = 0;

  int paracc[10000];

  // START THE MAIN EVENT LOOP
  // ==========================
  int event;

  for (event=1; eventNo < numberEvents; event++) {

    bool isDevent =0;
    int dim_count = 0;
    bool isEle = 0, isPos = 0, isPiplus = 0, isPiminus = 0, isKplus = 0, isKminus = 0;
    bool isD=0, isDbar=0;
    
    if(event%1000 == 0){
      cout<<"number of events trials: "<<event << "  Selected events:  " << eventNo <<endl;
    }
    
    //////// Generate Event ///////
    pythia.GenerateEvent();
    // Store only final state charged particles
    // pythia.Pylist(1); // 1->Event history
    // pythia.Pyedit(4); // 4->Stores only charged particles

    // Get list of particle and global event information
    particleArray = (TClonesArray *)pythia.ImportParticles();
    Int_t numParticles = particleArray->GetEntries();        // get number of generated particles
    
    //hard code to start from 2, so as to remove the first two input protons
    for (Int_t i=2; i<numParticles; i++) {
      if(dim_count>=MAXDIM) {cout<<"Reaching maximum dimension!"<<endl; break;}
      particle = (TMCParticle *)particleArray->At(i);     // get the particle information
      pdgcode = particle->GetKF();
      
      pxx = particle->GetPx();
      pyy = particle->GetPy();
      pzz = particle->GetPz();
      ener = particle->GetEnergy();
      pt = sqrt(pxx*pxx + pyy*pyy);  // Particle pT 
      vxx = particle->GetVx();
      vyy = particle->GetVy();
      vzz = particle->GetVz();
      vertex = sqrt(vxx*vxx + vyy*vyy + vzz*vzz);

           
      TParticle *tparticle = new TParticle(pdgcode, 1, parentPDG, 0, 0, 0, pxx, pyy, pzz, ener, vxx, vyy, vzz, particle->GetTime());
      etat = tparticle->Eta();
      phit = tparticle->Phi();
     

      // Parent ID
      idparent = particle->GetParent()-1;
      if(idparent <0) idparent =0;
      pe = (TMCParticle *)particleArray->At(idparent);
      parentPDG = pe->GetKF();
      double Dpx = pe->GetPx();
      double Dpy = pe->GetPy();
      double Dpz = pe->GetPz();
      double Dpt = TMath::Sqrt(Dpx*Dpx+Dpy*Dpy);
      if (parentPDG == 421 || parentPDG == 411 || parentPDG == 431) isD = 1;
      if (parentPDG == -421 || parentPDG == -411 || parentPDG == -431) isDbar = 1;
      
      // Get Charge and stability of the particle	
      TParticlePDG  *tparticlepdg = tparticle->GetPDG(mode);
      charge=tparticlepdg->Charge()/3.0;
      bool stable=tparticlepdg->Stable();
 
      delete tparticle;
      
      // Cuts will go here /////////////////////////////////////

      int absPDG = abs(pdgcode);      

      if(vertex < 900 && abs(pdgcode) < 1000 ) // base cuts
      if(stable && (charge == -1 || charge ==1)) {
	//	if(TMath::Abs(etat) <=0.5)  // Eta accaptance
	//	  if( (phit > 0 && phit < 1.5) || (phit > 1.5  && phit < 4.5) || (phit> 5.0))
	if(absPDG==11 || absPDG == 421 || absPDG == 411 || absPDG == 431)
        {
	  if(pdgcode==-11 && (parentPDG == 421 || parentPDG == 411 || parentPDG == 431)) isPos=1;
	  if(pdgcode==321 && parentPDG == -421) isKplus = 1;
	  if(pdgcode==-211 && parentPDG == -421) isPiminus = 1;
	  
	  if(pdgcode==11 && (parentPDG == -421 || parentPDG == -411 || parentPDG == -431)) isEle=1;
	  if(pdgcode==-321 && parentPDG == 421) isKminus = 1;
	  if(pdgcode==211 && parentPDG == 421) isPiplus = 1;
	  
	  // Fill electron and pT
	  bool isDD =0;
	  if(pdgcode==-11 && (parentPDG == 421 || parentPDG == 411 || parentPDG == 431)) isDD=1;
	  bool isDDbar =0;
	  if(pdgcode==11 && (parentPDG == -421 || parentPDG == -411 || parentPDG == -431)) isDDbar=1;

	  if(isDD || isDDbar) {
	    //  cout << pdgcode <<"    " << parentPDG << "    " << pt << "   " << Dpt << endl;
	    JpTBpT->Fill(pt,Dpt);
	  }
	  paracc[dim_count] =i;
	  pid[dim_count] = pdgcode;
	  px[dim_count] = pxx;
	  py[dim_count] = pyy;
	  pz[dim_count] = pzz;
	  energy[dim_count] = ener;
	  mass[dim_count] = particle->GetMass();
	  vx[dim_count] = vxx * mm_to_fm;
	  vy[dim_count] = vyy * mm_to_fm;
	  vz[dim_count] = vzz * mm_to_fm;
	  time[dim_count] = particle->GetTime() * mm_to_fm;
	  //	time[dim_count] = vertex;
	  dim_count++; 
	} // end of acceptance cut
      }//end of base cuts
    }// end of loop on particles in event
    
    
    if(isD || isDbar) {
      nDeventsEX++;
    }

    if( (isKplus && isPiminus ) || (isKminus && isPiplus ) ) {
      nKpi++;
    }

    if( (isPos && isKplus && isPiminus ) || (isEle && isKminus && isPiplus ) ) {
      isDevent = 1;
    }

    ////////////////////////////////////
    //  Electron trigger 
    if(isPos || isEle) {
      isDevent = 1;
    }
    ////////////////////////////////////

    
    if(isDevent) { 
      foutd << "0" << setw(6) << dim_count << endl;
      for(int ip=0; ip<dim_count; ip++)	
	{
	  particle = (TMCParticle *)particleArray->At(paracc[ip]); 
	  evTree->Fill();
	  foutd
	    << setw(3)
	    << ip+1 << "  "
	    << setw(6) << setprecision(6)
	    << pid[ip] << "  "
	    << setw(6) << setprecision(6)
	    << eventNo +1 << "  "
	    << setw(10) << setprecision(6)
	    << px[ip] << "  "
	    << setw(10) << setprecision(6)
	    << py[ip] << "  "
	    << setw(10) << setprecision(6)
	    << pz[ip] << "  "
	    << setw(10) << setprecision(6)
	    << energy[ip] << "  "
	    << setw(10) << setprecision(6)
	    << mass[ip] << "  "
	    << setw(12)
	    << vx[ip] << "  "
	    << setw(12)
	    << vy[ip] << "  "
	    << setw(12)
	    << vz[ip] << "  "
	    << setw(12)
	    << time[ip]
	    << endl;
	}//for int ip ........
      foutd << "0     0" << endl;
      nTpart = nTpart + dim_count;
      eventNo++;
    }//if isD........
  } // event loop
  
  evTree->Write();
  rootfile->Close();


  TCanvas *JBpT = new TCanvas("JBpT","JBpT",600,600);
  JpTBpT->Draw("colz");

  TFile *histfile = new TFile("hist1.root", "recreate");
  JpTBpT->Write();

  histfile->Close();
  
  cout << " Total particles = " << nTpart << endl;
  cout << " Total Number of events trials= " << event << endl;  
  cout << " Total Number of D0 or D0bar events = " << nDeventsEX << endl;
  cout << " Total Number of D events going to Kpi = " << nKpi << endl;
  cout << " Total Number of D events going to e = " << eventNo << endl;
  
  return 0;
}


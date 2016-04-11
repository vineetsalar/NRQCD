#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <ctime>
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
#include "TMCParticle.h"
#include "TParticlePDG.h"
#include "/home/vineet/root/include/TPythia6.h"
using namespace std;

bool IsAccept(Double_t pt, Double_t eta);

int run_pythia_Chic2JPsi(int numberEvents = 100000)
{
  // CREATE PYTHIA OBJECT
  // =====================
  TPythia6 pythia;
  // ================================================================
  // INITIALIZATION SECTION: SET ANY PYTHIA INPUT PARAMETERS HERE 
  // ================================================================
  
  Char_t  targ[10] = "p";        // target 
  Char_t  proj[10] = "p";	 // projectile
  double rootS = 1800;            // center of mass energy at CDF
  pythia.SetMSTP(51,7);       // Set structure function  // 8 -> CTEQ 5M1 (MS) (NLO!)
                               //  4 -> GRV 94L (Leading Order)
                              //  7 -> CTEQ 5L (Leading Order) !Default!
  pythia.SetMSTP(32,8);                     // Q^2 = s_hat  !Default=8!
  pythia.SetMSTP(91,1);                     // Use Gaussian Kt distribution

  pythia.SetPARP(91,2.0);                  // set width of kT gaussian 1.5 !Default=2!
  pythia.SetPARP(93,5.0);                  // Kt cut off  5 !Default=5!
  pythia.SetCKIN(3,0);                     // min Pt  0 !Default=0!
  
  // Switching On the processes to generate
  pythia.SetMSEL(0);                             // Global process turned off{run is in full user control}
  
  pythia.SetMSUB(81,0);                       // Turn On subprocess qqbar->Q Qbar
  pythia.SetMSUB(82,0);                          // Turn On subprocess gg->Q Qbar 
  
  pythia.SetMSUB(87,1);                          //g+g-->Chic0+g
  pythia.SetMSUB(88,1);                          //g+g-->Chic1+g 
  pythia.SetMSUB(89,1);                          //g+g-->Chic2+g 

  pythia.SetMSUB(104,1);                         //g+g-->Chic0 
  pythia.SetMSUB(105,1);                         //g+g-->Chic2 

// pythia.SetMSUB(96,0);                      // Turn OFF subprocess 
  pythia.SetMSTP(7,4);                           // 4 is for charm quark  
  //pythia.SetPMAS(pythia.Pycomp(4),1,1.6);  // Set charm quark mass to 1.6 GeV
  
  //Turn off all decay channels 
  //for (Int_t idc=1; idc<=4285; idc++){pythia.SetMDME(idc,1,0);}


  //Chic decay channels 
  //pythia.SetMDME(1501,1,1);          //Chic0 --> J/psi + gamma    
  //pythia.SetMDME(1502,1,0);          //Chic0 --> randm + randm 

  //pythia.SetBRAT(1501,1.0);   // 
  //pythia.SetBRAT(1502,0.0);   // 

  pythia.SetMDME(1555,1,1);          //Chic1 --> J/psi + gamma    
  pythia.SetMDME(1556,1,0);          //Chic1 --> randm + randm 

  pythia.SetMDME(861,1,1);           //Chic2 --> J/psi + gamma    
  pythia.SetMDME(862,1,0);          //Chic2 --> randm + randm

  // Force J/Psi decays to mumu 
  pythia.SetMDME(858,1,0);                  // Truned OFF J/psi -->e+ + e-
  pythia.SetMDME(859,1,1);                  // Truned ON J/psi -->mu+ + mu-
  pythia.SetMDME(860,1,0);                  // Truned OFF J/psi -->ranflv +ranflv


  //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
  // Projectile, Target and center of mass energy
  
  pythia.Initialize("CMS", targ, proj,rootS);   // simulates CDF energies
  
  // ===========================================
  // END OF THE INITIALIZATION SECTION
  // ===========================================
  
  //  set the random seed
  //  Int_t seed = (Int_t)(time(NULL)/3);

  //  Int_t seed = 2345678;
  Int_t seed = 123456782;

  if ( (seed>=0) && (seed<=900000000) ) {
    pythia.SetMRPY(1, seed);			// set seed
    pythia.SetMRPY(2, 0);			// use new seed
  }
  else {
    cout << "error: time " << seed << " is not valid" << endl;
    exit(2);
  }
  

  // If you want to see the list of all decay channels
  //pythia.Pylist(12);

  
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
  TH1D *Chic0_Pt = new TH1D("Chic0_Pt","Chic0_Pt",200,0.0,20.0);  
  Chic0_Pt->GetXaxis()->SetTitle("#chi_{c0} p_{T} (GeV/c)");
  Chic0_Pt->GetYaxis()->SetTitle("Entries");
  Chic0_Pt->SetName("Chic0_Pt");
  Chic0_Pt->SetTitle("Chic0_Pt");

  TH1D *Chic0JPsi_Pt = new TH1D("Chic0JPsi_Pt","Chic0JPsi_Pt",200,0.0,20.0);  
  Chic0JPsi_Pt->GetXaxis()->SetTitle("J/#psi p_{T} (GeV/c)");
  Chic0JPsi_Pt->GetYaxis()->SetTitle("Entries");
  Chic0JPsi_Pt->SetName("Chic0JPsi_Pt");
  Chic0JPsi_Pt->SetTitle("Chic0JPsi_Pt");

  TH2D *Chic0VsJPsi_Pt = new TH2D("Chic0VsJPsi_Pt","Chic0VsJPsi_Pt",200,0.0,20.0,200,0.0,20.0);  
  Chic0VsJPsi_Pt->GetXaxis()->SetTitle("J/#psi p_{T} (GeV/c)");
  Chic0VsJPsi_Pt->GetYaxis()->SetTitle("#chi_{c0} p_{T} (GeV/c)");
  Chic0VsJPsi_Pt->SetName("Chic0VsJPsi_Pt");
  Chic0VsJPsi_Pt->SetName("Chic0VsJPsi_Pt");
  
  

  // Define Histograms here
  TH1D *Chic1_Pt = new TH1D("Chic1_Pt","Chic1_Pt",200,0.0,20.0);  
  Chic1_Pt->GetXaxis()->SetTitle("#chi_{c0} p_{T} (GeV/c)");
  Chic1_Pt->GetYaxis()->SetTitle("Entries");
  Chic1_Pt->SetName("Chic1_Pt");
  Chic1_Pt->SetTitle("Chic1_Pt");

  TH1D *Chic1JPsi_Pt = new TH1D("Chic1JPsi_Pt","Chic1JPsi_Pt",200,0.0,20.0);  
  Chic1JPsi_Pt->GetXaxis()->SetTitle("J/#psi p_{T} (GeV/c)");
  Chic1JPsi_Pt->GetYaxis()->SetTitle("Entries");
  Chic1JPsi_Pt->SetName("Chic1JPsi_Pt");
  Chic1JPsi_Pt->SetTitle("Chic1JPsi_Pt");

  TH2D *Chic1VsJPsi_Pt = new TH2D("Chic1VsJPsi_Pt","Chic1VsJPsi_Pt",200,0.0,20.0,200,0.0,20.0);  
  Chic1VsJPsi_Pt->GetXaxis()->SetTitle("J/#psi p_{T} (GeV/c)");
  Chic1VsJPsi_Pt->GetYaxis()->SetTitle("#chi_{c1} p_{T} (GeV/c)");
  Chic1VsJPsi_Pt->SetName("Chic1VsJPsi_Pt");
  Chic1VsJPsi_Pt->SetName("Chic1VsJPsi_Pt");

  
  // Define Histograms here
  TH1D *Chic2_Pt = new TH1D("Chic2_Pt","Chic2_Pt",200,0.0,20.0);  
  Chic2_Pt->GetXaxis()->SetTitle("#chi_{c0} p_{T} (GeV/c)");
  Chic2_Pt->GetYaxis()->SetTitle("Entries");
  Chic2_Pt->SetName("Chic2_Pt");
  Chic2_Pt->SetTitle("Chic2_Pt");

  TH1D *Chic2JPsi_Pt = new TH1D("Chic2JPsi_Pt","Chic2JPsi_Pt",200,0.0,20.0);  
  Chic2JPsi_Pt->GetXaxis()->SetTitle("J/#psi p_{T} (GeV/c)");
  Chic2JPsi_Pt->GetYaxis()->SetTitle("Entries");
  Chic2JPsi_Pt->SetName("Chic2JPsi_Pt");
  Chic2JPsi_Pt->SetTitle("Chic2JPsi_Pt");

  TH2D *Chic2VsJPsi_Pt = new TH2D("Chic2VsJPsi_Pt","Chic2VsJPsi_Pt",200,0.0,20.0,200,0.0,20.0);  
  Chic2VsJPsi_Pt->GetXaxis()->SetTitle("J/#psi p_{T} (GeV/c)");
  Chic2VsJPsi_Pt->GetYaxis()->SetTitle("#chi_{c2} p_{T} (GeV/c)");
  Chic2VsJPsi_Pt->SetName("Chic2VsJPsi_Pt");
  Chic2VsJPsi_Pt->SetName("Chic2VsJPsi_Pt");




  // Define Histograms here
  TH1D *Mu_Pt = new TH1D("Mu_Pt","Mu_Pt",200,0.0,20.0);  
  Mu_Pt->GetXaxis()->SetTitle("Mu p_{T} (GeV/c)");
  Mu_Pt->GetYaxis()->SetTitle("Entries");

  
  float RadtoDeg = 180/(TMath::ATan(1)*4);
  
  // ===========================================
  // CREATE ROOT OUTPUT FILE AND DEFINE T TREE
  // ===========================================
  TFile *rootfile = new TFile("pythia.root", "recreate");
  
  TClonesArray *particleArray = new TClonesArray();
  TMCParticle  *particle = new TMCParticle();
  
  int eventNo =0;
  TTree *evTree = new TTree("evTree", "Event tree");
  evTree->Branch("particle", "TMCParticle", &particle);
  evTree->Branch("evt", &eventNo, "evt/I"); 
  
  TMCParticle *Parent;      //parent particle
  TMCParticle *Particle;   //particle
  TMCParticle *Dau1;      //daughter1
  TMCParticle *Dau2;     //daughter2
 

  Int_t parent_position,dau1_position,dau2_position;
  Int_t id,  parent_id, dau1_id, dau2_id;
  Int_t mode=0;
  
  
  Double_t P, Px, Py, Pz, E, Pt, Rapidity, Eta;
  Double_t Par_P, Par_Px, Par_Py, Par_Pz, Par_E,Par_Pt, Par_Rapidity, Par_Eta;
  
  Double_t Dau1_P, Dau1_Px, Dau1_Py, Dau1_Pz, Dau1_E, Dau1_Pt, Dau1_Rapidity, Dau1_Eta;
  Double_t Dau2_P, Dau2_Px, Dau2_Py, Dau2_Pz, Dau2_E, Dau2_Pt, Dau2_Rapidity, Dau2_Eta;
    
   
  // ==========================
  Int_t event;

  Int_t CountChic0 = 0;
  Int_t CountChic1 = 0;
  Int_t CountChic2 = 0;

  for(event=1; eventNo < numberEvents ; event++) {
   

    //////// Generate Event ///////
    pythia.GenerateEvent();
    // Store only final state charged particles
    //pythia.Pylist(1); // 1->Event history
    // 12->A list of decay channels with current IDC
    //pythia.Pyedit(4); // 4->Stores only charged particles

    // Get list of particle and global event information
    particleArray = (TClonesArray *)pythia.ImportParticles();
    Int_t numParticles = particleArray->GetEntries();        // get number of generated particles
    
    if(event%1000==0){cout<<" Total "<< numParticles <<"  particles are produced in  event "<< event<<endl;}
    //hard code to start from 2,so as to remove the first two input protons
    
    CountChic0 = 0;
    CountChic1 = 0;
    CountChic2 = 0;
    
    for (Int_t i=2; i<numParticles; i++) 
      {
	
	Particle = (TMCParticle *)particleArray->At(i);
	id = Particle->GetKF();
	
	//=================== Get Particle Variables ===========================//
	Px = Particle->GetPx();
	Py = Particle->GetPy();
	Pz = Particle->GetPz();
	E = Particle->GetEnergy();

	P = TMath::Sqrt(Px*Px + Py*Py + Pz*Pz);
	Pt = TMath::Sqrt(Px*Px + Py*Py);
	Rapidity = 0.5*TMath::Log((E + Pz)/(E - Pz));
	Eta =  0.5*TMath::Log((P + Pz)/(P - Pz));

	//=================== Get Parent Variables ===========================//
	//Get parent of particle
        parent_position = Particle->GetParent()-1;
	if(parent_position<0) parent_position =0;
	Parent = (TMCParticle *)particleArray->At(parent_position);
	parent_id = Parent->GetKF();
	
	Par_Px = Parent->GetPx();
	Par_Py = Parent->GetPy();
	Par_Pz = Parent->GetPz();
	Par_E = Parent->GetEnergy();
	
	Par_P = TMath::Sqrt(Par_Px*Par_Px + Par_Py*Par_Py + Par_Pz*Par_Pz);
	Par_Pt = TMath::Sqrt(Par_Px*Par_Px + Par_Py*Par_Py);
	Par_Rapidity = 0.5*TMath::Log((Par_E + Par_Pz)/(Par_E - Par_Pz));
	Par_Eta =  0.5*TMath::Log((Par_P + Par_Pz)/(Par_P - Par_Pz));

	//=================== Get Daughters Variables ===========================//
	//Get first daughter of the particle
	dau1_position = Particle->GetFirstChild()-1;
	if(dau1_position<0) dau1_position=0;
	Dau1 = (TMCParticle *)particleArray->At(dau1_position);
	dau1_id= Dau1->GetKF();
	Dau1_Px = Dau1->GetPx();
	Dau1_Py = Dau1->GetPy();
	Dau1_Pz = Dau1->GetPz();
	Dau1_E = Dau1->GetEnergy();
	Dau1_Pt = TMath::Sqrt( Dau1_Px*Dau1_Px + Dau1_Py*Dau1_Py );
	Dau1_P  = TMath::Sqrt( Dau1_Px*Dau1_Px + Dau1_Py*Dau1_Py + Dau1_Pz*Dau1_Pz );
	Dau1_Rapidity =  0.5*TMath::Log((Dau1_E + Dau1_Pz)/(Dau1_E - Dau1_Pz));
	Dau1_Eta =  0.5*TMath::Log((Dau1_P + Dau1_Pz)/(Dau1_P - Dau1_Pz));
	//Get second daughter of the particle
	dau2_position = Particle->GetLastChild()-1;
	if(dau2_position<0) dau2_position=0;
	Dau2 = (TMCParticle *)particleArray->At(dau2_position);
	dau2_id = Dau2->GetKF();
	Dau2_Px = Dau2->GetPx();
	Dau2_Py = Dau2->GetPy();
	Dau2_Pz = Dau2->GetPz();
	Dau2_E = Dau2->GetEnergy();
	Dau2_Pt = TMath::Sqrt( Dau2_Px*Dau2_Px + Dau2_Py*Dau2_Py );
	Dau2_P  = TMath::Sqrt( Dau2_Px*Dau2_Px + Dau2_Py*Dau2_Py + Dau2_Pz*Dau2_Pz );
	Dau2_Rapidity =  0.5*TMath::Log((Dau2_E + Dau2_Pz)/(Dau2_E - Dau2_Pz));
	Dau2_Eta =  0.5*TMath::Log((Dau2_P + Dau2_Pz)/(Dau2_P - Dau2_Pz));

	//=============================== Make Signal ======================================//
	Int_t Dau1_Accept = 0;
	Int_t Dau2_Accept = 0;
	Int_t IsSignal = 0;	
	
	Int_t PDG_JPsi = 443;

	Int_t PDG_Chic0 = 10441;
	Int_t PDG_Chic1 = 20443;
	Int_t PDG_Chic2 = 445;

	Int_t PDG_MuPlus = -13;
	Int_t PDG_MuMinus = 13;
 



	//Fill the histograms

	//if( (TMath::Abs(dau1_id) == 13 && TMath::Abs(dau2_id) == 13) &&  id == PDG_JPsi && parent_id == PDG_Chic0) 
	//if( id == PDG_JPsi && parent_id == PDG_Chic0) 

	//Chic0;
	if( id == PDG_JPsi && parent_id == PDG_Chic0) 
	  {
	    
	    if(IsAccept(Dau1_Pt, Dau1_Eta)==1){Dau1_Accept =1;}
	    if(IsAccept(Dau2_Pt, Dau2_Eta)==1){Dau2_Accept =1;}
	    if(Dau1_Accept == 1 && Dau2_Accept == 1){IsSignal =1;}
	    
	    IsSignal =1;
	    if(IsSignal ==1){Chic0JPsi_Pt->Fill(Pt);}
	    if(IsSignal ==1){Chic0_Pt->Fill(Par_Pt);}
	    if(IsSignal ==1){Chic0VsJPsi_Pt->Fill(Pt,Par_Pt);}
	    if(IsSignal ==1){CountChic0=1;}
	  }

	IsSignal =0;
	//Chic1;
	if( id == PDG_JPsi && parent_id == PDG_Chic1) 
	  {
	    
	    if(IsAccept(Dau1_Pt, Dau1_Eta)==1){Dau1_Accept =1;}
	    if(IsAccept(Dau2_Pt, Dau2_Eta)==1){Dau2_Accept =1;}
	    if(Dau1_Accept == 1 && Dau2_Accept == 1){IsSignal =1;}
	    
	    IsSignal =1;
	    if(IsSignal ==1){Chic1JPsi_Pt->Fill(Pt);}
	    if(IsSignal ==1){Chic1_Pt->Fill(Par_Pt);}
	    if(IsSignal ==1){Chic1VsJPsi_Pt->Fill(Pt,Par_Pt);}
	    if(IsSignal ==1){CountChic1=1;}
	  }


	IsSignal =0;
	//Chic1;
	if( id == PDG_JPsi && parent_id == PDG_Chic2) 
	  {
	    
	    if(IsAccept(Dau1_Pt, Dau1_Eta)==1){Dau1_Accept =1;}
	    if(IsAccept(Dau2_Pt, Dau2_Eta)==1){Dau2_Accept =1;}
	    if(Dau1_Accept == 1 && Dau2_Accept == 1){IsSignal =1;}
	    
	    IsSignal =1;
	    if(IsSignal ==1){Chic2JPsi_Pt->Fill(Pt);}
	    if(IsSignal ==1){Chic2_Pt->Fill(Par_Pt);}
	    if(IsSignal ==1){Chic2VsJPsi_Pt->Fill(Pt,Par_Pt);}
	    if(IsSignal ==1){CountChic2=1;}
	  }



      } // Particle loop

    if(CountChic1==1) {eventNo++;}
    if(event%1000 == 0){
      cout<<"number of events trials: "<< event << "  Selected events:  " << eventNo <<endl;
    }

  }  //Event loop




  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Chic0JPsi_Pt->Draw();
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Chic0_Pt->Draw();
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLeftMargin(0.18);
  Chic0VsJPsi_Pt->Draw("colz");

 
 

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Chic1JPsi_Pt->Draw();
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Chic1_Pt->Draw();
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLeftMargin(0.18);
  Chic1VsJPsi_Pt->Draw("colz");

 
 

  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Chic2JPsi_Pt->Draw();
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLogy(1);
  gPad->SetLeftMargin(0.18);
  Chic2_Pt->Draw();
  
  new TCanvas;
  gPad->SetTicks();
  gPad->SetLeftMargin(0.18);
  Chic2VsJPsi_Pt->Draw("colz");

 

  Chic0JPsi_Pt->Write();
  Chic0_Pt->Write();
  Chic0VsJPsi_Pt->Write();
  
  Chic1JPsi_Pt->Write();
  Chic1_Pt->Write();
  Chic1VsJPsi_Pt->Write();
  
  Chic2JPsi_Pt->Write();
  Chic2_Pt->Write();
  Chic2VsJPsi_Pt->Write();


  rootfile->Close();





  return 0;
}


bool IsAccept(Double_t pt, Double_t eta)
{
  
  return ( fabs(eta) < 0.6 && pt > 0.0);
}




//TMCParticle to TParticle conversion
//Particle::TParticle(pdg,status,mother1,mother2,daughter1,daughter2,px,py,pz,etot,vx,vy,vz,time) 
//TParticle *tparticleB = new TParticle(parentPDG, 1,0, 0, 0, 0, Bpx,Bpy,Bpz,Ben,Bvx,Bvy,Bvz,pB->GetTime());

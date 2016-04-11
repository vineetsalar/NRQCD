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

//#include "/home/pshukla/root/v5-14-00/pythia6/inc/TMCParticle6.h"
#include "/home/kapil/root/include/TPythia6.h"

using namespace std;

bool IsAccept(Double_t pt, Double_t eta);

int run_pythiaBpTJpsipTNew(int numberEvents = 5000, TString OutFile = "oscar.input")
{
  //TROOT root("pythia","run pythia");
  //  gROOT->Reset();
  //  gSystem->Load("libEG");
  //  gSystem->Load("libPythia6");
  //  gSystem->Load("libEGPythia6"); 
  
  ofstream foutd(OutFile);
  foutd<<"# OSC1999A"<<endl;
  foutd<<"# final_id_p_x"<<endl;
  foutd<<"# EXODUS event generator in full event mode"<<endl;
  foutd<<"#"<<endl;
  
  const int MAXDIM = 10000; // No. of particles in an event.
  
  int pid[10000],ppid[10000],gppid[10000];
  double px[10000], py[10000], pz[10000], energy[10000], mass[10000];
  double vx[10000], vy[10000], vz[10000], time[10000]; 
  double aBpt[10000], aBeta[10000], avertex[10000], apt[10000],aetat[10000],aBrap[10000];
  double ajpt[10000], ajeta[10000], ajrap[10000];
  
  const double mm_to_fm = 1e12;
  
  // CREATE PYTHIA OBJECT
  // =====================
  
  TPythia6 pythia;
  
  // ================================================================
  // INITIALIZATION SECTION: SET ANY PYTHIA INPUT PARAMETERS HERE 
  // ================================================================
  
  Char_t  targ[10] = "p";        // target 
  Char_t  proj[10] = "p";	 // projectile
  double rootS = 2760;            // center of mass energy at LHC

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
  pythia.SetMSUB(81,1);                       // Turn On subprocess qqbar->Q Qbar
  pythia.SetMSUB(82,1);                          // Turn On subprocess gg->Q Qbar 
  // pythia.SetMSUB(96,0);                      // Turn OFF subprocess 
  pythia.SetMSTP(7,5);                           // 5 is for beauty quark(beauty q production)
  
  pythia.SetPMAS(pythia.Pycomp(5),1,4.75);  // Set beauty quark mass to 4.5 GeV
  
  // Turn off all decay channels 
  //     for (Int_t idc=1; idc<=4285; idc++) pythia.SetMDME(idc,1,0);


  //decay channels for B meson:
  // ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,

  //   511 B0 decay channels
  for (Int_t idc=863; idc<=888; idc++) pythia.SetMDME(idc,1,0);  // turn OFF all decay channels for B0/B0bar
  
  pythia.SetMDME(889,1,1);                               //  J/psi +  K      
  pythia.SetMDME(890,1,1);                              //   J/Psi + (K0)*
  pythia.SetMDME(891,1,1);                             //  0.001900    chi_1c   K0 
  pythia.SetMDME(892,1,1);                             //  0.002500    chi_1c   K*0   

  for (Int_t idc=893; idc<=898; idc++) pythia.SetMDME(idc,1,0);  // turn OFF  reamining decay channels for B0

  //  521 B+ decay channels 
  for (Int_t idc=908; idc<=933; idc++) pythia.SetMDME(idc,1,0);  // turn OFF  decay channels for B+/-

  pythia.SetMDME(934,1,1);                                       //B+ -->J/Psi + K+
  pythia.SetMDME(935,1,1);                                       //B+ -->J/Psi + (K+)*
  pythia.SetMDME(936,1,1);                            //  0.001900    chi_1c     K+    
  pythia.SetMDME(937,1,1);                            //  0.002500    chi_1c     K*+            

  for (Int_t idc=938; idc<=943; idc++) pythia.SetMDME(idc,1,0);  // turn OFF remaining decay channels for B+/-

  //  531 Bs decay channels
  for (Int_t idc=953; idc<=979; idc++) pythia.SetMDME(idc,1,0);  // turn OFF decay channels for Bs/Bs_bar
  
  pythia.SetMDME(980,1,1);                                       //Bs -->J/Psi + eta
  pythia.SetMDME(981,1,1);                                       //Bs -->J/Psi + etaPrime
  pythia.SetMDME(982,1,1);                                       //Bs -->J/Psi + phi
  pythia.SetMDME(983,1,1);                     // 0.001000    chi_1c      eta 
  pythia.SetMDME(984,1,1);                     // 0.000900    chi_1c      eta_           
  pythia.SetMDME(985,1,1);                     // 0.002500    chi_1c      phi  ,   

  for (Int_t idc=986; idc<=991; idc++) pythia.SetMDME(idc,1,0);  // turn OFF decay channels for Bs/Bs_bar

  // 541 Bc+
  for (Int_t idc=997; idc<=1000; idc++) pythia.SetMDME(idc,1,0);     // turn OFF decay channels for Bc+

  pythia.SetMDME(1001,1,1);            // 0.035000   nu_e            e+              J/psi
  pythia.SetMDME(1002,1,0);           // 0.012000    nu_mu     mu+    eta_c
  pythia.SetMDME(1003,1,1);           // 0.035000    nu_mu     mu+    J/psi
  pythia.SetMDME(1004,1,0);
  pythia.SetMDME(1005,1,1);           // 0.007000    nu_tau          tau+            J/psi  */

  for (Int_t idc=1006; idc<=1027; idc++) pythia.SetMDME(idc,1,0);    // turn OFF decay channels for Bc+
  
  // 5122  Lambda_b0       Lambda_bbar0 
 
  pythia.SetMDME(1219,1,0);           // turn OFF decay channels for Lambda_b0
  pythia.SetMDME(1220,1,0);           // nu_mubar        mu-             Lambda_c+   
  for (Int_t idc=1221; idc<=1227; idc++) pythia.SetMDME(idc,1,0);    // turn OFF decay channels for Lambda_b0

  pythia.SetMDME(1228,1,0);           // 0.002200    J/psi           Lambda0     ',  
  pythia.SetMDME(1229,1,0);           // 0.004400    chi_1c          Lambda0    ',
  for (Int_t idc=1230; idc<=1235; idc++) pythia.SetMDME(idc,1,0);    // turn OFF decay channels for Lambda_b0

  // Change of b->Chi_1c and Force Chi_1c decay to J/psi 
  pythia.SetBRAT(891,0.000519);   // B0->Chi_1c 0.001900*0.273000
  pythia.SetBRAT(892,0.000683);   // B0->Chi_1c 0.002500*0.273000
  pythia.SetBRAT(936,0.000683);   // B+->Chi_1c 0.002500*0.273000
  pythia.SetBRAT(937,0.002500);   // B+->Chi_1c 0.001900*0.273000  

  pythia.SetBRAT(983,0.000273);   // Bs->Chi_1c 0.001000*0.273000
  pythia.SetBRAT(984,0.000246);   // Bs->Chi_1c 0.000900*0.273000
  pythia.SetBRAT(985,0.000683);   // Bs->Chi_1c 0.002500*0.273000
  //pythia.SetBRAT(1229,0.001201);  // Lambda_b0->Chi_1c+lambda0 0.004400*0.273000
  
  pythia.SetMDME(1555,1,1);       // 0.273000    J/psi           gamma ',
  pythia.SetMDME(1556,1,0);       // 0.727000    rndmflav        rndmflavbar ',
  
  // Force J/Psi decays to mumu 
  pythia.SetMDME(858,1,0);                  // Truned OFF J/psi -->e+ + e-
  pythia.SetMDME(859,1,1);                  // Truned ON J/psi -->mu+ + mu-
  pythia.SetMDME(860,1,0);                  // Truned OFF J/psi -->ranflv +ranflv

  //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
  // Projectile, Target and center of mass energy
  
  pythia.Initialize("CMS", targ, proj,rootS);   // simulates RHIC energies
  
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
  
  TH1F *Jpsiv = new TH1F("Jpsiv", "Jpsiv", 100,0,10);
  Jpsiv ->GetXaxis()->SetTitle("vertex distribution of Jpsi from B decay ");
  Jpsiv->GetYaxis()->SetTitle("Entries");
  Jpsiv->GetXaxis()->CenterTitle(); 
  Jpsiv->GetYaxis()->CenterTitle();
  Jpsiv->SetLineColor(4);
  
  
  TH1F *Jpsivt = new TH1F("Jpsivt", "Jpsivt", 50,-0.5,10);
  Jpsivt ->GetXaxis()->SetTitle("Vt disstribution of Jpsi from B decay");
  Jpsivt->GetYaxis()->SetTitle("Entries");
  Jpsivt->GetXaxis()->CenterTitle(); 
  Jpsivt->GetYaxis()->CenterTitle();
  Jpsivt->SetLineColor(4);
 
  
  TH1F *Jpsivz = new TH1F("Jpsivz", "Jpsivz", 100,-10,10);
  Jpsivz->GetXaxis()->SetTitle("Vz disstribution of Jpsi");
  Jpsivz->GetYaxis()->SetTitle("Entries");
  Jpsivz->GetXaxis()->CenterTitle(); 
  Jpsivz->GetYaxis()->CenterTitle();
  Jpsivz->SetLineColor(4);
  
  TH1F *JpTransv = new TH1F("JpTransv", "JpTransv", 100,0,50);
  JpTransv->GetXaxis()->SetTitle("J/#psi p_{T}(GeV)");
  JpTransv->GetYaxis()->SetTitle("Entries");
  JpTransv->GetXaxis()->CenterTitle(); 
  JpTransv->GetYaxis()->CenterTitle();
  JpTransv->SetLineColor(2);

  
  TH1F *BpTransv = new TH1F("BpTransv", "BpTransv", 100,0,50);
  BpTransv->GetXaxis()->SetTitle(" B meson p_{T}(GeV)");
  BpTransv->GetYaxis()->SetTitle("Entries");
  BpTransv->GetXaxis()->CenterTitle(); 
  BpTransv->GetYaxis()->CenterTitle();
  BpTransv->SetLineColor(2);
  

  TH2F *JpTBpT = new TH2F("JpTBpT", "JpTBpT", 80,0,40,80,0,40);
  JpTBpT->GetXaxis()->SetTitle("J/#psi p_{T}(GeV) ");
  JpTBpT->GetYaxis()->SetTitle(" B meson p_{T}(GeV)");
  JpTBpT->GetXaxis()->CenterTitle(); 
  JpTBpT->GetYaxis()->CenterTitle();
  JpTBpT->SetLineColor(2);

  TH1F *JPtAccept = new TH1F("JpTAccept", "JpT", 100,0,50);
  JPtAccept->GetXaxis()->SetTitle("J/#psi p_{T}(GeV)");
  JPtAccept->GetYaxis()->SetTitle("Entries");
  JPtAccept->GetXaxis()->CenterTitle(); 
  JPtAccept->GetYaxis()->CenterTitle();
  JPtAccept->SetLineColor(2);

  
  TH1F *BPtAccept = new TH1F("BPtAccept", "BPt", 100,0,50);
  BPtAccept->GetXaxis()->SetTitle(" B meson p_{T}(GeV)");
  BPtAccept->GetYaxis()->SetTitle("Entries");
  BPtAccept->GetXaxis()->CenterTitle(); 
  BPtAccept->GetYaxis()->CenterTitle();
  BPtAccept->SetLineColor(2);
  

  TH2F *JpTBpTAccpt = new TH2F("JpTBpTAccpt", "JBpT", 80,0,40,80,0,40);
  JpTBpTAccpt->GetXaxis()->SetTitle("J/#psi p_{T}(GeV) ");
  JpTBpTAccpt->GetYaxis()->SetTitle(" B meson p_{T}(GeV)");
  JpTBpTAccpt->GetXaxis()->CenterTitle(); 
  JpTBpTAccpt->GetYaxis()->CenterTitle();
  JpTBpTAccpt->SetLineColor(2);




  TH1F *RapB = new TH1F("RapB", "RapB", 50,-5,5);
  RapB->GetXaxis()->SetTitle("Eta of B meson");
  RapB->GetYaxis()->SetTitle("Entries");
  RapB->GetXaxis()->CenterTitle();
  RapB->GetYaxis()->CenterTitle();
  RapB->SetLineColor(2);
  
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
  
  TParticle *tepart;
  TMCParticle *pB;  // Gparent particle
  TMCParticle *pJpsi;  // parent particle
  TMCParticle *Mu1;
  TMCParticle *Mu2;
 
  int pdgcode, pdgcodexp, idparent, parentPDG, idgparent, gparentPDG,Dpdg1,Dpdg2,idgdaughter1,idgdaughter2,mode=0;
  float px1, py1, pz1, ener1, vx1, vy1, vz1, pt1, vertex1, fcharge,jvx,jvy,jvz,jv,jvt,jpx,jpy,jpz,jpt,jeta, jRap;
  float px2, py2, pz2, ener2, vx2, vy2, vz2, pt2, vertex2, charge;
  float BRap,Bpx,Bpy,Bpz,Bpt,Beta,Bvx,Bvy,Bvz,Ben;
  
  int nTpart = 0;
  int nDeventsEX =0;
  
  int paracc[10000];
  
  // START THE MAIN EVENT LOOP
  // ==========================
  int event;
  
  for(event=1; eventNo <numberEvents;event++) {
    //Real
    TObjArray muPlus;
    TObjArray muMinus;
    // Real + Background
    TObjArray BmuPlus;
    TObjArray BmuMinus;
    
    int dimuon_count = 0;
    bool isSignal = 0;
    int nplus =0;
    int nminus =0;
    int nJpsi =0;
    int parentStatus=0;
    double etaPlus, pTplus, etaMinus,pTMinus;


    //////// Generate Event ///////
    pythia.GenerateEvent();
    // Store only final state charged particles
    //pythia.Pylist(1); // 1->Event history
                       // 12->A list of decay channels with current IDC
    //pythia.Pyedit(4); // 4->Stores only charged particles
    
    // Get list of particle and global event information
    particleArray = (TClonesArray *)pythia.ImportParticles();
    Int_t numParticles = particleArray->GetEntries();        // get number of generated particles
    //cout<<"  numParticles  "<<numParticles<<endl;
    

    //hard code to start from 2,so as to remove the first two input protons
    for (Int_t i=2; i<numParticles; i++) {
      if(dimuon_count>=MAXDIM) {cout<<"Reaching maximum dimension!"<<endl; break;}
      particle = (TMCParticle *)particleArray->At(i);     // get the particle information
      pdgcode = particle->GetKF();
      
      if(pdgcode == 443) {
	jvx = particle->GetVx(); 
	jvy = particle->GetVy(); 
	jvz = particle->GetVz();    
	jv  = TMath::Sqrt(jvx*jvx +jvy*jvy +jvz*jvz);
	jvt = TMath::Sqrt(jvx*jvx +jvy*jvy );
	
	jpx = particle->GetPx();
	jpy = particle->GetPy();
	jpz = particle->GetPz();
	jpt = TMath::Sqrt(jpx*jpx+jpy*jpy);
      }
      
      // Parent

      //cout<<" pdgcode   "<<pdgcode<<endl;
      //cout<<"========================="<<i<<"========================"<<endl;

      // Parent ID
      idparent = particle->GetParent()-1;
      if(idparent <0) idparent =0;
      pB = (TMCParticle *)particleArray->At(idparent);
      parentPDG = 0;
      parentPDG = pB->GetKF();
      
      int Ppdg = parentPDG;
      bool parentB = 0;
      Bpt = -100;
      Beta = -100;
      if(fabs(Ppdg)==511 || fabs(Ppdg) ==521 || fabs(Ppdg) == 531 || fabs(Ppdg) == 541 || Ppdg == 20443){parentB=1;}
     
      if(pdgcode == 443 && parentB){
	Bpx = pB->GetPx();
	Bpy = pB->GetPy();
	Bpz = pB->GetPz();
	Bpt = TMath::Sqrt(Bpx*Bpx+Bpy*Bpy);
	Bvx = pB->GetVx();
	Bvy = pB->GetVy();
	Bvz = pB->GetVz();
	Ben = pB->GetEnergy();
	TParticle *tparticleB = new TParticle(parentPDG, 1,0, 0, 0, 0, Bpx,Bpy,Bpz,Ben,Bvx,Bvy,Bvz,pB->GetTime()); 
	Beta =tparticleB->Eta();
	BRap=tparticleB->Y();
	delete tparticleB;
      }

      //cout<<"----------------------------------------------------"<<endl;
      //pJpsi->Print();
      //cout<<"----------------------------------------------------"<<endl;
      //cout<<"----------------------------------------------------"<<endl;
      //if(parentPDG == 443 && gparentB) {
      //if((fabs(pdgcode) == 13) && parentPDG == 443) {
      
      if(pdgcode == 443  && parentB) {
	BpTransv->Fill(Bpt);
	JpTransv->Fill(jpt);
	JpTBpT->Fill(jpt,Bpt);
      }
	
      // Daughter ID
      //if(pdgcode == 443 && parentB){
      idgdaughter1 = particle->GetFirstChild()-1;
      if(idgdaughter1 <0) idgdaughter1 =0;
      Mu1 = (TMCParticle *)particleArray->At(idgdaughter1);
      Dpdg1=0;
      Dpdg1 = Mu1->GetKF();

      idgdaughter2 = particle->GetLastChild()-1;
      if(idgdaughter2 <0) idgdaughter2 =0;
      Mu2 = (TMCParticle *)particleArray->At(idgdaughter2);
      Dpdg2=0;
      Dpdg2 = Mu2->GetKF();
            
      //cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
      //pB->Print();
      // cout<<" Dpdg1 "<<Dpdg1<<"  Dpdg2  "<<Dpdg2<<endl;
      //cout<<" pdgcode   "<<gparentPDG<<endl;
      
      TParticle *t1particle;
      TParticlePDG  *t1particlepdg;
      TParticle *t2particle;
      TParticlePDG  *t2particlepdg;

      bool stable =0,fstable=0,PosIn=0,NegIn=0;

      px1 = Mu1->GetPx();
      py1 = Mu1->GetPy();
      pz1 = Mu1->GetPz();
      ener1 = Mu1->GetEnergy(); 
      pt1 = sqrt(px1*px1 + py1*py1);
      vx1 = Mu1->GetVx();
      vy1 = Mu1->GetVy();
      vz1 = Mu1->GetVz();
      vertex1 = sqrt(vx1*vx1 + vy1*vy1 + vz1*vz1);

      px2 = Mu2->GetPx();
      py2 = Mu2->GetPy();
      pz2 = Mu2->GetPz();
      ener2 = Mu2->GetEnergy(); 
      pt2 = sqrt(px2*px2 + py2*py2);
      vx2 = Mu2->GetVx();
      vy2 = Mu2->GetVy();
      vz2 = Mu2->GetVz();
      vertex2 = sqrt(vx2*vx2 + vy2*vy2 + vz2*vz2);

      //tparticle = new TParticle(pdgcode, 1, parentPDG, 0, 0, 0, pxx, pyy, pzz, ener, vxx, vyy, vzz, particle->GetTime());
      t1particle = new TParticle(Dpdg1, 1, pdgcode, 0, 0, 0, px1, py1, pz1, ener1, vx1, vy1, vz1, Mu1->GetTime());
      t2particle = new TParticle(Dpdg2, 1, pdgcode, 0, 0, 0, px2, py2, pz2, ener2, vx2, vy2, vz2, Mu2->GetTime());
      t1particlepdg = t1particle->GetPDG(mode);
      t2particlepdg = t2particle->GetPDG(mode);
      
      if(fabs(Dpdg1) == 13 && pdgcode==443 && parentB){
	etaPlus = t1particle->Eta();
	pTplus = pt1;
	nplus++;
      }

      if(fabs(Dpdg2) == 13 && pdgcode==443 && parentB){
	etaMinus = t2particle->Eta();
	pTMinus = pt2;
	nminus++;
      }
      
      if(IsAccept(pTplus,etaPlus)) {PosIn=1;}
      if(IsAccept(pTMinus,etaMinus)) {NegIn=1;}
      
      // Get Charge and stability of the particle	
      if(pdgcode == 443 && parentB) {
	fcharge =t1particlepdg->Charge()/3.0;
	charge =t2particlepdg->Charge()/3.0;
	fstable=t1particlepdg->Stable();
	stable=t2particlepdg->Stable();

	//cout<<"================================================="<<endl;
	//cout<<" pdgcode   "<<pdgcode<<endl;
	//cout<<" idparent  "<<idparent<<endl;
	//cout<<" parentpdg   "<<parentPDG<<endl;
      }
      
      delete t1particle;
      delete t2particle;
      
      if(fabs(pdgcode) < 1000) // base cuts
	if(stable && (charge == -1 || charge ==1) && (PosIn==1 && NegIn==1)) isSignal = 1;
      if(isSignal && pdgcode == 443  && parentB)
	{ 
	  BPtAccept->Fill(Bpt);
	  JPtAccept->Fill(jpt);
	  JpTBpTAccpt->Fill(jpt,Bpt);
	}//Acceptance cut 
    }// end of loop on particles in event
    
    //nTpart = nTpart + dimuon_count;
    //cout<<"================================================="<<endl;
    //cout<<" nTpart   "<<nTpart<<" dimuon_count  "<<dimuon_count<<endl;
    
    if(nplus == nminus) {eventNo++;}

    if(event%10 == 0){
      cout<<"number of events trials: "<<event << "  Selected events:  " << eventNo <<endl;
    }
    
  }//event loop
  
  //evTree->Write();
  rootfile->Close();
  
  TFile *histfile = new TFile("hist1.root", "recreate");
   

  TCanvas *BpT = new TCanvas("BpT","BpT",600,600);
  BpTransv->Draw();
  gPad->Print("ptb.gif");
  
  TCanvas *JpT = new TCanvas("JpT","JpT",600,600);
  JpTransv->Draw();
  gPad->Write("JpT");
  
  TCanvas *JBpT = new TCanvas("JBpT","JBpT",600,600);
  JpTBpT->Draw("colz");

  TCanvas *BpTAcc = new TCanvas("BpTAcc","BpTAcc",600,600);
  BPtAccept->Draw();
  gPad->Print("ptb.gif");
  
  TCanvas *JpTAcc = new TCanvas("JpTAcc","JpTAcc",600,600);
  JPtAccept->Draw();
  gPad->Write("JpT");
  
  TCanvas *JBpTAcc = new TCanvas("JBpTAcc","JBpTAcc",600,600);
  JpTBpTAccpt->Draw("colz");


  BpTransv->Write();
  JpTransv->Write();
  JpTBpT->Write();
  RapB->Write();
  JpTBpTAccpt->Write();


  histfile->Close();
  
  cout << " Total particles = " << nTpart << endl;
  cout << " Total Number of trials = " << event -1 << endl;  
  cout << " Total Number of events = " << eventNo << endl;

  return 0;
}

bool IsAccept(Double_t pt, Double_t eta)
{
  //return (fabs(eta) < 2.4); 
  return (fabs(eta) < 2.4 &&
  	  (    ( fabs(eta) < 1.0 && pt >= 3.4 ) ||
  	       (  1.0 <= fabs(eta) && fabs(eta) < 1.5 && pt >= 5.8-2.4*fabs(eta) ) ||
  	       (  1.5 <= fabs(eta) && pt >= 3.3667 - 7.0/9.0*fabs(eta)) ));
}


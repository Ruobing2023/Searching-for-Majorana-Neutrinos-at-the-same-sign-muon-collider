/*
This macro is used to produce the ntuple.root,
storing useful informations we need
//root -b -q ntuple_chain.C\(\"WW\"\)  
*/
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/classes/SortableObject.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/classes/DelphesClasses.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/external/ExRootAnalysis/ExRootTreeReader.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/external/ExRootAnalysis/ExRootTreeWriter.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/external/ExRootAnalysis/ExRootTreeBranch.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/external/ExRootAnalysis/ExRootResult.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/external/ExRootAnalysis/ExRootClassifier.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/external/ExRootAnalysis/ExRootFilter.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/external/ExRootAnalysis/ExRootProgressBar.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/external/ExRootAnalysis/ExRootConfReader.h"
#include "/Users/ruobing/MG5_aMC_v3_4_2/Delphes/external/ExRootAnalysis/ExRootTask.h"


//------------------------------------------------------------------------------

double deltaPhi(const double& phi1, const double& phi2)
{
        double deltaphi = fabs(phi1 - phi2);
        if (deltaphi > 3.141592654) deltaphi = 6.283185308 - deltaphi;
        return deltaphi;
}

double deltaEta(const double& eta1, const double& eta2)
{
        double deltaeta = fabs(eta1 - eta2);
        return deltaeta;
}

double deltaR(const double& eta1, const double& phi1,
                const double& eta2, const double& phi2)
{
        double deltaphi = deltaPhi(phi1, phi2);
        double deltaeta = deltaEta(eta1, eta2);
        double deltar = sqrt(deltaphi*deltaphi + deltaeta*deltaeta);
        return deltar;
}

//------------------------------------------------------------------------------

class ExRootResult;
class ExRootTreeReader;

//------------------------------------------------------------------------------

void AnalyseEvents(ExRootTreeReader *treeReader, TString filename)
{
  // create a root file to store the variables
  TFile file(filename, "recreate");
  TTree *tree = new TTree("tree", "keep events after cuts");
  double SF=1.0;
  if(filename.Contains("signal")==1) {SF= 0.4107/10000.;}/////XS:fb
  if(filename.Contains("bkg1-wwmumu")==1) {SF= 0.2382/10000.;}
  if(filename.Contains("bkg2-wmuvm")==1) {SF= 330./10000.;}
  if(filename.Contains("bkg3-zwmuvm")==1) {SF= 5168./10000.;}
  if(filename.Contains("bkg4-zzmumu")==1) {SF= 0.03265/10000.;}
  if(filename.Contains("bkg5-zmumu")==1) {SF=54.48/10000.;}

/*  int inputNum=0;
  int event;
  //int numJettot, numFJettot, numbJet;
  int numMu, numLep , numGen;
//  double ptFJet,etaFJet,phiFJet,massFJet;
  double ptMu, etaMu, phiMu, ptll; 
  double ptMu[99],etaMu[99],phiMu[99],chargeMu[99];
  double ptMu_gen,etaMu_gen,phiMu_gen,chargeMu_gen;
 // int numEl, numMu;
 // double t0FJet, t1FJet, t2FJet, t3FJet, t4FJet;
  double MMass = 0.105000 ;*/

  int inputNum=0;
  int event;
//  int numJettot, numJet, numbJet;
//  double ptJet[99],etaJet[99],phiJet[99],massJet[99];
//  double ptBJet[99],etaBJet[99],phiBJet[99],massBJet[99];
  double met,meta,mll,ptll,p1,p2,costheta,pt1,pt2;//,etaMu1,etaMu2,phiMu1,phiMu2;
  int  numMu, numLep,numGen,numEl;
  double ptMu[99],etaMu[99],phiMu[99],chargeMu[99],px[99],py[99],pz[99],E[99],ptEl[99],etaEl[99],phiEl[99],chargeEl[99];
  
  tree->Branch("event", &event, "event/I");
  tree->Branch("SF", &SF, "SF/D");
  tree->Branch("numMu", &numMu, "numMu/I");
  tree->Branch("met",&met,"met/D");
  tree->Branch("meta",&meta,"meta/D");
 // tree->Branch("numLep", &numLep, "numLep/I");
  tree->Branch("costheta",&costheta,"costheta/D");
  tree->Branch("mll", &mll, "mll/D");
  tree->Branch("ptll", &ptll, "ptll/D");
  tree->Branch("ptMu", &ptMu, "ptMu/D");
  tree->Branch("etaMu", &etaMu, "etaMu/D");
  tree->Branch("phiMu", &phiMu, "phiMu/D");
//  tree->Branch("ptEl",&ptEl,"ptEl/D");
//  tree->Branch("etaEl",&etaEl,"etaEl/D");
//  tree->Branch("phiEl",&phiEl,"phiEl/D");
  tree->Branch("pt1",&pt1,"pt1/D");
  tree->Branch("pt2",&pt2,"pt2/D");
 

  TClonesArray *branchEvent = treeReader->UseBranch("Event");
  TClonesArray *branchGenParticle = treeReader->UseBranch("Particle");
  TClonesArray *branchElectron = treeReader->UseBranch("Electron");
  TClonesArray *branchMuon = treeReader->UseBranch("Muon");
//  TClonesArray *branchParticle = treeReader->UseBranch("Particle");
  //TClonesArray *branchJet = treeReader->UseBranch("Jet");
  //TClonesArray *branchFJet = treeReader->UseBranch("FatJet");
  TClonesArray *branchMET = treeReader->UseBranch("MissingET");
//  TClonesArray *branchEta = treeReader->UseBranch("MissingET");

  Long64_t numberOfEntries = treeReader->GetEntries();
  inputNum = numberOfEntries;
  cout << "** Chain contains " << numberOfEntries << " events" << endl;

  for(int count=0; count < numberOfEntries; count++) {
      //initiate branch members
 
     event=-1; met=-99.0;meta=-99.; mll=-99.0; ptll=-99.0;  numMu=-1;numEl=-1; costheta=-99;
     p1=-99;p2=-99;pt1=-99.;pt2=-99.;//etaMu1=-99.;etaMu2=-99.;phiMu1=-99.;phiMu2=-99.;//pxMu_gen=-99.0;pyMu_gen=-99.0;pzMu_gen=-99.0;
     numGen=-1;numLep=-1;//ptMu1=-99.;etaMu1=-99.;phiMu1=-99.;
    
     //********************************************************************
   for(int i=0; i<99; i++)
      {
       
          ptMu[i]=-99;etaMu[i]=-99;phiMu[i]=-99;chargeMu[i]=-99;
	   ptEl[i]=-99;etaEl[i]=-99;phiEl[i]=-99;chargeEl[i]=-99;
	  px[i]=-99;py[i]=-99;pz[i]=-99;E[i]=-99;
      }

      treeReader->ReadEntry(count) ;
      //********************************************************************


      Event* ev = (Event*)branchEvent->At(0);
      event=ev->Number;
    
      MissingET* Met = (MissingET *) branchMET->At(0);
      met=Met->MET;
      numMu=branchMuon->GetEntries();
      numGen=branchGenParticle->GetEntries();
      numEl=branchElectron->GetEntries();
      numLep=numEl+numMu;
 //     nparticles=branchParticle->GetEntries();
// Preselection Cuts1:  veto additional soft lepton.

        if(numMu!=2)continue;
    //  if(mll>50.0)continue;
     // if(ptll >= 30.0)continue;

      Muon* M[99] ;
      Electron* El[99];
      int mark2=0;

      for(int j=0; j<numMu; j++)
      {
         M[j]=(Muon*)branchMuon->At(j);
		  if(M[j]->PT>30.0&&abs(M[j]->Eta)<=2.5){
	  ptMu[mark2]=M[j]->PT;
             etaMu[mark2]=M[j]->Eta;
             phiMu[mark2]=M[j]->Phi;
             chargeMu[mark2]=M[j]->Charge;
	     mark2++;
	  }
	  
  }
// Preselection Cuts1:  2 and only 2 good muons
      if(mark2!=2)continue;

      float MMass = 0.105000 ;
      float MMass2 = 0.10500/207;
      TLorentzVector l1,l2,l3,l4;
      
      l1.SetPtEtaPhiM(ptMu[1],etaMu[1],phiMu[1],MMass);
      l2.SetPtEtaPhiM(ptMu[0],etaMu[0],phiMu[0],MMass);
     // mll=(l1+l2+l3+l4).M();
     // ptll = (l1+l2+l3+l4).Pt();
      if(l1.Pt()>l2.Pt()){
      pt1 = l1.Pt();
      pt2 = l2.Pt();
      mll = (l1+l2).M();
      ptll = (l1+l2).Pt();
      }
      if(l1.Pt()<l2.Pt()){
      pt1 = l2.Pt();
      pt2 = l1.Pt();
       mll = (l1+l2).M();
      ptll = (l1+l2).Pt();
      }

double p1, p2, constheta;

p1 = sqrt(pow(l1.Pt(),2)+pow(l1.Pz(),2));
p2 = sqrt(pow(l2.Pt(),2)+pow(l2.Pz(),2));
costheta = (l1.Px()*l2.Px()+l1.Py()*l2.Py()+l1.Pz()*l2.Pz())/(p1*p2);
       
     
      
 
 //////////////////////////////////////////////////////////////////////////////
 tree->Fill();
   // end of chain loop
  //tree->Print();
}
  file.Write();
}


//------------------------------------------------------------------------------

void ntuple_chain(char* filename)
{
  gSystem->Load("/Users/ruobing/MG5_aMC_v3_4_2/Delphes/libDelphes");
  //THStack *stack;
  TChain *chain = new TChain("Delphes");

  TString buffer = filename;
  cout<<buffer<<endl;
  TString IFile =  buffer + ".root";
  TString OFile =  "ntuple_" + buffer+".root";

  chain->Add(IFile);
  ExRootTreeReader *treeReader1 = new ExRootTreeReader(chain);
  ExRootResult *result1 = new ExRootResult();
  AnalyseEvents(treeReader1, OFile);

  cout << "** Exiting..." << endl;

  delete result1;
  delete treeReader1;
  delete chain;
}

//------------------------------------------------------------------------------

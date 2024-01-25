/*void smallntuple_chain(char* datafilename)
{i
  TString buffer = datafilename;
  cout<<buffer<<endl;*/
{
	vector<TString> files;
	files.push_back("signal");
	files.push_back("bkg1-wwmumu");
	files.push_back("bkg2-wmuvm");
	files.push_back("bkg3-zwmuvm");
	files.push_back("bkg4-zzmumu");
	files.push_back("bkg5-zmumu");

	const int nfiles = files.size();
	cout<<"file size "<<nfiles<<endl;
  for(int i=0;i<nfiles;i++){
  TString IFile =  "ntuple_" + files.at(i)+".root";
  TFile *ifile = new TFile(IFile);
  TTree *tree = (TTree*)ifile->Get("tree");
  int nentries = tree->GetEntries();

  int numMu;
  double ptMu,ptEl,etaMu,phiMu,met,mll,ptll,SF,costheta,meta,pt1,pt2;//etaMu1,etaMu2,phiMu1,phiMu2;
//  double ptMu[2],etaMu[2],phiMu[2];
 

  tree->SetBranchAddress("costheta",&costheta);
  tree->SetBranchAddress("numMu", &numMu);
  tree->SetBranchAddress("mll", &mll);
  tree->SetBranchAddress("ptll", &ptll);
  tree->SetBranchAddress("ptMu", &ptMu);
//  tree->SetBranchAddress("ptEl", &ptEl);
//  tree->SetBranchAddress("phiMu", &phiMu);
  tree->SetBranchAddress("SF",&SF); 
  tree->SetBranchAddress("pt1",&pt1);
  tree->SetBranchAddress("pt2",&pt2);
  tree->SetBranchAddress("met",&met);
//  tree->SetBranchAddress("meta",&meta);
/*  tree->SetBranchAddress("etaMu1",&etaMu1);
  tree->SetBranchAddress("etaMu2",&etaMu2);
  tree->SetBranchAddress("phiMu1",&phiMu1);
  tree->SetBranchAddress("phiMu2",&phiMu2);*/


  TString OFile =  "small"+files.at(i)+".root";
  TFile  *ofile=new TFile(OFile, "recreate");
  TTree *otree = new TTree("tree1","keep events after cut1");
  
//  double ptMu1,ptMu2,etaMu1,etaMu2,phiMu1,phiMu2;
  double detall, dphill;

  otree->Branch("costheta",&costheta,"costheta/D");
  otree->Branch("mll", &mll, "mll/D");
  otree->Branch("ptll", &ptll, "ptll/D");
  otree->Branch("SF", &SF, "SF/D");
  otree->Branch("pt1", &pt1, "pt1/D");
  otree->Branch("pt2", &pt2, "pt2/D");
  otree->Branch("ptMu", &ptMu, "ptMu/D");
//  otree->Branch("ptEl", &ptEl, "ptEl/D");
//  otree->Branch("phiMu1", &phiMu1, "phiMu1/D");
//  otree->Branch("phiMu2", &phiMu2, "phiMu2/D");
//  otree->Branch("detall", &detall, "detall/D");
  otree->Branch("met",&met,"met/D");
//  otree->Branch("meta",&meta,"meta/D");
//  otree->Branch("dphill", &dphill, "dphill/D");

    for(int j=0; j<nentries; j++)
    {
      tree->GetEntry(j);
      //std::cout<<numMu<<std::endl;
      if(pt1<=30.)continue;
      if(pt2<=50.)continue;
      if(mll<=50.0)continue;
      if(ptll<=50.)continue;
      if(costheta>=-0.20)continue;
      if(met<=30.)continue;
     // if(numMu!=2) continue;
//      if(mll>200)continue;
  /*    int ii=0, jj=1;
      
      if(ptMu[0]<ptMu[1]) {ii=1,jj=0;}
     
      ptMu1=ptMu[ii];
      etaMu1=etaMu[ii];
      phiMu1=phiMu[ii];
      ptMu2=ptMu[jj];
      etaMu2=etaMu[jj];
      phiMu2=phiMu[jj];*/
  //    detall=fabs(etaMu1-etaMu2);
//      dphill=deltaPhi(phiMu1,phiMu2);
      
      otree->Fill();
      
    }
   ofile->Write();
  }
}

double deltaPhi(const double& phi1, const double& phi2)
{
        double deltaphi = fabs(phi1 - phi2);
        if (deltaphi > 3.141592654) deltaphi = 6.283185308 - deltaphi;
        return deltaphi;
}

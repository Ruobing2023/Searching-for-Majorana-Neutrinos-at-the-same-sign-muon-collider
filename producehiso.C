
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
  TString IFile =  "small" + files.at(i)+".root";
  TFile *ifile = new TFile(IFile);
  TTree *tree = (TTree*)ifile->Get("tree1");

 //       int nentries1 = (int)tree1->GetEntries();
        int nentries1 = tree->GetEntries();
 //        double lumi=100.;
  //       int numMu;
        double ptMu,ptEl,met,mll,ptll,SF,costheta,meta,pt1,pt2;//etaMu1,etaMu2,phiMu1,phiMu2;
        cout<<"Sample = "<<files.at(i)<<" "<<"nentries1 = "<<nentries1<<endl;
         tree->SetBranchAddress("costheta",&costheta);
//      	 tree->SetBranchAddress("numMu", &numMu);
 	 tree->SetBranchAddress("mll", &mll);
	 tree->SetBranchAddress("ptll", &ptll);
 	 tree->SetBranchAddress("pt1", &pt1);
	 tree->SetBranchAddress("pt2", &pt2);
	// tree->SetBranchAddress("phiMu", &phiMu);
	 tree->SetBranchAddress("SF",&SF);
	 tree->SetBranchAddress("ptMu",&ptMu);
//	 tree->SetBranchAddress("ptEl",&ptEl);
	 tree->SetBranchAddress("met",&met);
//	 tree->SetBranchAddress("meta",&meta);
        double invmll, weight;
       
	TString OFile =  "cut2"+files.at(i)+".root";
	TFile  *ofile=new TFile(OFile, "recreate");
  	TTree *otree = new TTree(files.at(i),"keep events after cut1");
        
	otree->Branch("mll",&mll,"mll/D");
        otree->Branch("SF",&SF,"SF/D");
	otree->Branch("ptll",&ptll,"ptll/D");
	otree->Branch("costheta",&costheta,"costheta/D");
        otree->Branch("pt1",&pt1,"pt1/D");
	otree->Branch("pt2",&pt2,"pt2/D");
	otree->Branch("met",&met,"met/D");

//        TH1F *PTA1   = new TH1F(hname," ",40,0,1000);
//	TH1F *PTA2   = new TH1F(hname1," ",40,0,500);
//	TH1F *PTA3   = new TH1F(hname2," ",40,-1,1);
       // PTA1->Sumw2();

        for(int j=0; j<nentries1; j++)
        {
         tree->GetEntry(j);
       if(mll<=100.)continue;
       if(ptll<=120.)continue;
       if(costheta>=-0.95)continue;
       if(met<=100.)continue;
       if(pt1<=120.)continue;
       if(pt2<=100.||pt2>=450.)continue;
    //   weight = SF;
      // sum = SF*lumi;

       otree->Fill();
	}
       ofile->Write();
  }

  }
  
// TString  OFile = "j1.root";

 



void cutcounting2(){
// cut couting based on Ntuple
   Double_t lumi = 1000.;

   TString Sig_name = "signal";
  
   TString Bkg_name[5] = {"bkg1-wwmumu","bkg2-wmuvm","bkg3-zwmuvm","bkg4-zzmumu","bkg5-zmumu"};
//   TString massCut[4] = {"Mllpm300","Mllpm200","Mllpm100","Mllpm50"};
//   Double_t cut[4] = {300.,200.,100,50};
   double SF;

   TFile * input1 = new TFile ("j1.root");
   input1->cd("");


  double sum_sig,sum_bkg;

 
        sum_sig=0.0;
        sum_bkg=0.0;
   
           TTree *Outtree1 = (TTree*)input1->Get(Sig_name);
           int nentries1 = (int)Outtree1->GetEntries();
           Outtree1->SetBranchAddress("SF",&SF);
           
           for (int in=0;in<nentries1;in++){
           Outtree1->GetEntry(in);
            
                sum_sig+=SF*lumi;

           }

       for(int i=0;i<5;i++){
           TTree *Outtree2 = (TTree*)input1->Get(Bkg_name[i]);
           int nentries2 = (int)Outtree2->GetEntries();
           Outtree2->SetBranchAddress("SF",&SF);
          
           for (int in=0;in<nentries2;in++){
           Outtree2->GetEntry(in);
            
                sum_bkg+=SF*lumi;
              
            }
     }
     //  std::cout<<massCut[i_massCut]<<std::endl;
//       std::cout<<sum_sig<<" "<<sum_bkg1<<" "<<sum_bkg2<<" "<<sum_bkg3<<" "<<sum_bkg4<<" "<<sum_bkg5<<std::endl;
        std::cout<<sum_sig<<" "<<sum_bkg<<std::endl;
        
//       std::cout<<TMath::Sqrt(2*((sum_sig+sum_bkg)*TMath::Log(1+(sum_sig/sum_bkg))-sum_sig))<<" "<<std::endl;
       std::cout<<sum_sig/TMath::Sqrt(sum_bkg)<<" "<<std::endl;
     


   }



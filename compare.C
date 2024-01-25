{
#include "TAxis.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TNtupleD.h"
#include <stdio.h>
#include <stdlib.h>
//#include <vector.h>



	TFile * input1 = new TFile ("ntuple_signal.root");
        input1->cd("");
        TTree *Outtree1 = (TTree*)input1->Get("tree");

        TFile * input2 = new TFile ("ntuple_bkg1-wwmumu.root");
        input2->cd("");
        TTree *Outtree2 = (TTree*)input2->Get("tree");

        TFile * input3 = new TFile ("ntuple_bkg2-wmuvm.root");
        input3->cd("");
        TTree *Outtree3 = (TTree*)input3->Get("tree");

        TFile * input4 = new TFile ("ntuple_bkg3-zwmuvm.root");
        input4->cd("");
        TTree *Outtree4 = (TTree*)input4->Get("tree");

	TFile * input5 = new TFile ("ntuple_bkg4-zzmumu.root");
        input5->cd("");
        TTree *Outtree5 = (TTree*)input5->Get("tree");

	TFile * input6 = new TFile ("ntuple_bkg5-zmumu.root");
        input6->cd("");
        TTree *Outtree6 = (TTree*)input6->Get("tree");
	
/*	TFile * input6 = new TFile ("ntuple_d1TeV.root");
        input6->cd("");
        TTree *Outtree6 = (TTree*)input6->Get("tree");
	
	TFile * input7 = new TFile ("ntuple_d500GeV.root");
        input7->cd("");
        TTree *Outtree7 = (TTree*)input7->Get("tree");

	TFile * input8 = new TFile ("ntuple_d2TeV.root");
        input8->cd("");
        TTree *Outtree8 = (TTree*)input8->Get("tree");

	TFile * input9 = new TFile ("ntuple_d5TeV.root");
        input9->cd("");
        TTree *Outtree9 = (TTree*)input9->Get("tree");*/
 
 
       int nentries1 = (int)Outtree1->GetEntries();
       cout<<"nentries1 = "<<nentries1<<endl;
   
       int nentries2 = (int)Outtree2->GetEntries();
       cout<<"nentries2 = "<<nentries2<<endl;
   
       int nentries3 = (int)Outtree3->GetEntries();
       cout<<"nentries3 = "<<nentries3<<endl;
   
       int nentries4 = (int)Outtree4->GetEntries();
       cout<<"nentries4 = "<<nentries4<<endl;
   
       int nentries5 = (int)Outtree5->GetEntries();
        cout<<"nentries5 = "<<nentries5<<endl;
   
       int nentries6 = (int)Outtree6->GetEntries();
       cout<<"nentries6 = "<<nentries6<<endl;
/*        int nentries7 = (int)Outtree7->GetEntries();
       cout<<"nentries7 = "<<nentries7<<endl;
        int nentries8 = (int)Outtree8->GetEntries();
       cout<<"nentries8 = "<<nentries8<<endl;
        int nentries9 = (int)Outtree9->GetEntries();
       cout<<"nentries9 = "<<nentries9<<endl;
   */
       TH1D *PTA1   = new TH1D("a"," ",20,-1.5,1.5);
//       PTA1->Sumw2();
       TH1D *PTA2   = new TH1D("b"," ",20,-1.5,1.5);
  //     PTA2->Sumw2();
       TH1D *PTA3   = new TH1D("c"," ",20,-1.5,1.5);
  //     PTA3->Sumw2();
       TH1D *PTA4   = new TH1D("d"," ",20,-1.5,1.5);
       TH1D *PTA5   = new TH1D("e"," ",20,-1.5,1.5);
       TH1D *PTA6   = new TH1D("f"," ",20,-1.5,1.5);
//       TH1D *PTA7   = new TH1D("g"," ",40,0,1000);
//       TH1D *PTA8   = new TH1D("h"," ",40,0,1000);
//       TH1D *PTA9   = new TH1D("i"," ",40,0,1000);
  

      // double ;	
        double mll1,mll2,mll3,mll4,mll5,mll6;
       Outtree1->SetBranchAddress("costheta"    ,&mll1);
       Outtree2->SetBranchAddress("costheta"    ,&mll2);
       Outtree3->SetBranchAddress("costheta"    ,&mll3);
       Outtree4->SetBranchAddress("costheta"    ,&mll4);
       Outtree5->SetBranchAddress("costheta"    ,&mll5);
       Outtree6->SetBranchAddress("costheta"    ,&mll6);
//       Outtree7->SetBranchAddress("mll"    ,&mllMu7);
//       Outtree5->SetBranchAddress("mll"    ,&mllMu8);
//       Outtree6->SetBranchAddress("mll"    ,&mllMu9);

   double L = 1000. ; 
     for(int i=0; i<nentries1; i++)
     {
         Outtree1->GetEntry(i);
         PTA1->Fill(mll1,0.4107*L/float(nentries1));
     } 

      for(int i=0; i<nentries2; i++)
     {
         Outtree2->GetEntry(i);
         PTA2->Fill(mll2,0.2382*L/float(nentries2));
     } 

       for(int i=0; i<nentries3; i++)
     {
         Outtree3->GetEntry(i);
         PTA3->Fill(mll3,330*L/float(nentries3));
     }   
        for(int i=0; i<nentries4; i++)
     {
         Outtree4->GetEntry(i);
         PTA4->Fill(mll4,5.68*L/float(nentries4));
     }

        for(int i=0; i<nentries5; i++)
     {
         Outtree5->GetEntry(i);
         PTA5->Fill(mll5,0.03265*L/float(nentries5));
     }

        for(int i=0; i<nentries6; i++)
     {
         Outtree6->GetEntry(i);
         PTA6->Fill(mll6,54.48*L/float(nentries6));
     }

/*	 for(int i=0; i<nentries6; i++)
     {
         Outtree6->GetEntry(i);
         PTA6->Fill(mll6,175.4/float(nentries6));
     }
	  for(int i=0; i<nentries7; i++)
     {
         Outtree7->GetEntry(i);
         PTA7->Fill(mllMu7,42.4/float(nentries7));
     }
	   for(int i=0; i<nentries8; i++)
     {
         Outtree8->GetEntry(i);
         PTA8->Fill(mllMu8,21.29/float(nentries8));
     }
	    for(int i=0; i<nentries9; i++)
     {
         Outtree9->GetEntry(i);
         PTA9->Fill(mllMu9,4.356/float(nentries9));
     }*/

      TCanvas *c01 = new TCanvas("c01","",700,600);
      c01->SetLogy();
//      PTA3->SetTitle("the  distribution of mu+");
      PTA3->GetXaxis()->SetTitle("cos#theta_{ll}");
      PTA3->GetYaxis()->SetTitle("Number of Entries");
//      PTA3->GetXaxis()->CenterTitle();
//     PTA3->GetYaxis()->CenterTitle();
      PTA3->SetStats(false);
      PTA3->SetMinimum(1);
      PTA3->SetMaximum(100000000);
      PTA3->SetLineColor(4);
      PTA3->SetLineWidth(3);
      PTA3->SetMarkerStyle(20);
      PTA3->GetXaxis()->SetTitleOffset(1.4);
      PTA3->Draw("HIST e");

      PTA2->SetLineColor(2);
      PTA2->SetLineWidth(3);
      PTA2->SetMarkerStyle(21);
      PTA2->SetStats(false);
      PTA2->Draw("HIST e sames");
  
      PTA1->SetLineColor(1);
      PTA1->SetLineWidth(3);
      PTA1->SetMarkerStyle(22);
      PTA1->SetStats(false);
      PTA1->Draw("HIST e sames");

      PTA4->SetLineColor(3);
      PTA4->SetLineWidth(3);
      PTA4->SetMarkerStyle(23);
      PTA4->SetStats(false);
      PTA4->Draw("HIST e sames");

      PTA5->SetLineColor(7);
      PTA5->SetLineWidth(3);
      PTA5->SetMarkerStyle(24);
      PTA5->SetStats(false);
      PTA5->Draw("HIST e sames");

      PTA6->SetLineColor(6);
      PTA6->SetLineWidth(3);
      PTA6->SetMarkerStyle(25);
      PTA6->SetStats(false);
      PTA6->Draw("HIST e sames");
      
/*      PTA7->SetLineColor(8);
      PTA7->SetLineWidth(3);
      PTA7->SetMarkerStyle(26);
      PTA7->SetStats(false);
      PTA7->Draw("HIST e sames");

      PTA8->SetLineColor(9);
      PTA8->SetLineWidth(3);
      PTA8->SetMarkerStyle(27);
      PTA8->SetStats(false);
      PTA8->Draw("HIST e sames");
      
      PTA9->SetLineColor(11);
      PTA9->SetLineWidth(3);
      PTA9->SetMarkerStyle(28);
      PTA9->SetStats(false);
      PTA9->Draw("HIST e sames");*/

     TLegend *l1 = new TLegend(0.76,0.74,0.89,0.89);
     l1->SetNColumns(2);
     l1->SetBorderSize(1);
     l1->SetFillColor(0);
     l1->AddEntry(PTA1,"#mu^{+}#mu^{+}");
     l1->AddEntry(PTA2,"W^{+}W^{+}#nu_{#mu}~#nu_{#mu}~");
     l1->AddEntry(PTA3,"W^{+}#mu^{+}#nu_{#mu}~");
     l1->AddEntry(PTA4,"ZW^{+}#mu^{+}#nu_{#mu}~");
     l1->AddEntry(PTA5,"ZZ#mu^{+}#mu^{+}");
     l1->AddEntry(PTA6,"Z#mu^{+}#mu^{+}");
//     l1->AddEntry(PTA7,"mN1=500GeV");
//     l1->AddEntry(PTA8,"mN1=2TeV");
//     l1->AddEntry(PTA9,"mN1=5TeV");
     l1->Draw("Sames");

      TLatex *t = new TLatex();
     t->SetNDC();
     t->SetTextAlign(23);
     t->SetTextFont(64);
     t->SetTextSizePixels(20);
     t->DrawLatex(0.55,0.90,"the distribution of MET");
     t->Draw();

     c01->SaveAs("compare-pthh.png");

}

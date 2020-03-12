#include <stdio.h>

void hist1 () {
	TH1D *h1  = new TH1D("h1", "Ten Bins", 10, 0, 10);
	TH1D *h2 = new TH1D("h2", "100 Bins", 100, 0, 10);
	TH1D *h3  = new TH1D("h3", "1000 Bins", 1000, 0, 10);
	for(int i=0; i<1000; i++) {
		h1->Fill( gRandom->Gaus(5,2));//Inserting Gaussian dist with mean = 5 and std =2
		h2->Fill( gRandom->Gaus(5,2));//Inserting Gaussian dist with mean = 5 and std =2
		h3->Fill( gRandom->Gaus(5,2));//Inserting Gaussian dist with mean = 5 and std =2
	}
	h1->SetXTitle("X");
	h1->SetYTitle("Counts");
	h1->SetMinimum(0);
	h1->SetFillColor(kBlue-7);
	//Mean depends on # of bins!
	//Mean in legend is the weighted average of all the bin centers
	//RMS is standard deviation
	//h1->SetStats(0); gets rid of stats
	
	gStyle->SetOptStat(111111);

	TCanvas *c1 = new TCanvas("c1", "First histogram!", 50, 50, 700, 700);
	c1->Divide(3,1);
	c1->cd(1);
	h1->Draw();

	c1->cd(2);
	h2->Draw();

	c1->cd(3);
	h3->Draw();
}

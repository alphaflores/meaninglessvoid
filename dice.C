#include <stdio.h>
#include <iostream>

void dice () {
	TCanvas *c1 = new TCanvas("c1","My Canvas", 0, 0, 700, 700);
	c1->Divide(2,1);
	TH1I *h1 = new TH1I("h1", "One Die", 6, 0.5, 6.5);
	//When plotting integers, offset bins by half a bin so integers are centered
	TH1I *h2 = new TH1I("h2", "Sum of two dice probability", 12, 0.5, 12.5);


	//Roll each dice 10000 times and add
	for (int i=0; i<10000; i++) {
		int r1 = gRandom->Integer(6)+1;
		int r2 = gRandom->Integer(6)+1;
		h1->Fill(r1);
		h2->Fill(r1+r2);
	}

	h1->SetMinimum(0);
	h2->SetMinimum(0);

	c1->cd(1);
	h1->Draw();

	c1->cd(2);
	h2->Draw();

	cout << "Counts for sum of two dice " << endl;
	for(int i=1; i<= h2->GetNbinsX(); i++) {
		cout << "Bin content" << i << "\t" << h2->GetBinContent(i) << endl;
	}
}

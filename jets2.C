/*
 *
 * 1 Calculate and plot pt distribution of all pions
 * 2 Calculate and plot phi angle in pt plane of all pions
 * 3 Calculate and plot phi angle difference between high
 * trigger pt particle pt > 4 Gev/c
 * 4 How many particles are in a jet?
 * Hint: Jet identification is one particle with pt > 4 Gev/c
 */


#include <stdio.h>
#include <iostream>
#include <TMath.h>
#define PI 3.14159

//Function for transverse momentum
//
double px,py,pt;
double transp (double px, double py) {
	pt = sqrt(pow(px,2.)+pow(py,2.));
	return pt;
}
double phi;
double calphi(double px, double py) {
	double phi = atan2(py,px);
	return phi;
}
double triggerphi,assophi,deltaphi;
double caldeltaphi(double triggerphi, double assophi) {
	double deltaphi = triggerphi - assophi;
	if (deltaphi<-PI/2) {deltaphi += 2*PI;}
	if (deltaphi>=3*PI/2) {deltaphi -= 2*PI;}
	return deltaphi;
}

double p,pz,etta;
double caletta(double px, double py, double pz) {
	p = sqrt(pow(px,2.)+pow(py,2.)+pow(pz,2.));
	etta = -(1.0/2.0)*log((p-pz)/(p+pz));
	return etta;
}

double trigetta,assoetta,deltaetta;
double caldeltaetta(double trigetta, double assoetta) {
	double deltaetta = trigetta - assoetta;
	return deltaetta;
}

//Function for phi angle in pt plane

//Function for phi angle difference between high trigger pt particle



void jets2() {

//	double transp(double px, double py);


	TString dir = gSystem->UnixPathName(__FILE__);
	dir.ReplaceAll("jets2.C","");
	dir.ReplaceAll("/./","/");
	ifstream in;
	in.open("ascii_file.txt");

	TFile *f = new TFile("jets2.root","RECREATE");

	//Declare variables
	double px, py, pz, pt, phi, triggerphi, assophi, deltaphi;
	int n,event;
	int i=0;
	int j=0;
	float x,y,z;
	int nlines = 0;
	int nhighpt = 0;
	int part_numtrig;
	int part_numasso;
	int event_numtrig;
	int event_numasso;
	double pxtrig;
	double pytrig;
	double pztrig;
	double pttrig;
	double pxasso;
	double pyasso;
	double pzasso;
	double phi1,phi2;
	double etta,etta1,etta2;
	double trigetta, assoetta, deltaetta;
	int lowpt = 0;
	int assopt = 0;
	bool highpt;

	//Functions
	double transp(double px, double py);
	double calphi(double px, double py);
	double caldeltaphi(double triggerphi, double assophi);
	double caletta(double px, double py, double pz);
	double caldeltaetta(double trigetta, double assoetta);

	//Create TNtuple to store particle data
	TNtuple *ntuple1 = new TNtuple("ntuple1","Pion data", "n:event:x:y:z");


	// Create pt distribution histogram
	TH1F *h1 = new TH1F("h1","Pt distribution histogram",1000,0.01,30);
	gStyle->SetOptStat(111111);
	h1->SetXTitle("Pt (GeV/c)");
	h1->SetYTitle("Count");
	h1->SetMinimum(0);

	// Create phi distribution histogram
	TH1F *h2 = new TH1F("h2","Phi distribution histogram",250,-PI,PI);
	h2->SetXTitle("Phi");
	h2->SetYTitle("Count");
	h2->SetMinimum(0);

	// Plot phi angle difference between all associate and trigger particles
	// in same event
	TH1F *h3 = new TH1F("h3","Delta phi distribution histogram",250,-PI/2,3*PI/2);
	h3->SetXTitle("Delta Phi");
	h3->SetYTitle("Count");
	h3->SetMinimum(0);
//	h3->Rebin(5);

	//Determine the # of particles in a jet
	TH1F *h4 = new TH1F("h4","Number of jet particles",250,0,30);
	h4->SetXTitle("Jet Pt");
	h4->SetYTitle("Jet Count");
	h4->SetMinimum(0);

	//Plot etta distribution
	TH1F *h5 = new TH1F("h5","Eta distribution",250,-10,10);
	h5->SetXTitle("Eta");
	h5->SetYTitle("Count");
	h5->SetMinimum(0);

	//Plot delta phi and delta etta 2D distribution
	TH2F *h6 = new TH2F("h6","Phi and eta distribution",250,-PI/2,3*PI/2,250,-10,10);
	h6->SetXTitle("Delta Phi");
	h6->SetYTitle("Delta Eta");
	h6->SetMinimum(0);

	//Delta Eta distribution

	TH1F *h7 = new TH1F("h7","Delta Eta distribution",250,-10,10);
	h7->SetXTitle("Delta eta");
	h7->SetYTitle("Count");
	h7->SetMinimum(0);


	while(nlines<=1379) {
		in >> n >> event >> x >> y >> z;
		if (!in.good()) break;

		//NTuple
		ntuple1->Fill(n,event,x,y,z);

		//Array
		int arrayn[1379];
		int arrayevent[n];
		double arrayx[n];
		double arrayy[n];
		double arrayz[n];
		double arrayp[n];
		
		int h=0;
		int l=0;

		arrayevent[n] = event;
		arrayx[n] = x;
		arrayy[n] = y;
		arrayz[n] = z;
		pt = transp(arrayx[n],arrayy[n]);
		h1->Fill(pt);//Pt dist plot
//		cout << "px = " << px << endl;
//		cout << "pt = " << pt << endl;
	
		//Fill phi distribution histogram
		phi = calphi(arrayx[n],arrayy[n]);
		h2->Fill(phi);
	//	cout << "Number of partcles = " << n << endl;

		//Calculate etta
		//arrayp[n] = fullp(arrayx[n],arrayy[n],arrayz[n]);
		etta = caletta(arrayx[n],arrayy[n],arrayz[n]);
		h5->Fill(etta);

		nlines++;
		
		//Fill plot with phi and etta
		//Plot 2D cartesian plot with phi and etta distribution
		TGraph *gr1 = new TGraph();
//		gr1->GetHistogram(h2);
//		gr1->GetHisogram(h5);

		if (n<=1379;n++) {
			if(pt>=4.&&n<=1379) {
			highpt = true;
			nhighpt++;
			event_numtrig = event;
			event_numtrig++;
			part_numtrig = n;
			part_numtrig++;
			pxtrig = x;
			pxtrig++;
			pytrig = y;
			pytrig++;
			pztrig = z;
			pztrig++;
			pttrig = transp(pxtrig,pytrig);
			h4->Fill(pttrig);
			phi1 = calphi(pxtrig,pytrig);
			etta1 = caletta(pxtrig,pytrig,pztrig);
		//	arrayh[h] = phi;
			//cout << "Number of high pt = " << nhighpt << endl;
			//cout << "Particle number of high pt =  " << part_numtrig << endl;
			}

			else if(pt<=4.&&pt>=1.&&n<=1379) {
			highpt = false;
			assopt++;
			event_numasso = event;
			event_numasso++;
			part_numasso = n;
			part_numasso++;
			pxasso = x;
			pxasso++;
			pyasso = y;
			pyasso++;
			pzasso = z;
			pzasso++;
			phi2 = calphi(pxasso,pyasso);
			etta2 = caletta(pxasso,pyasso,pzasso);
		//	arrayg[g] = phi;
			//cout << "Number of associate particles = " << assopt << endl;
			//cout << "Particle number of asso pt = " << part_numasso << endl;
//			cout << "Phi 2 = " << phi2 << endl;
			}
			
			if(event<=200) {
		
				if(event_numtrig==event_numasso) {
			
				deltaphi = caldeltaphi(phi1,phi2);
				h3->Fill(deltaphi);
				//h3->Fit("gaus");
				//TF1 *f2 = h3->GetFunction("gaus");
				deltaetta = caldeltaetta(etta1,etta2);
				h6->Fill(deltaphi,deltaetta);
				h7->Fill(deltaetta);
			//	cout << "Delta phi = " << deltaphi << endl;
		
				}	
				
			}//if event


		}//if
		
		
	}//while

	//Set up canvas
	TCanvas *c1 = new TCanvas("c1", "Individual distribution",0,0,1000,1000);
	c1->Divide(4,1);

	//Histogram for part 1
	c1->cd(1);
	h1->Draw();

	//Histogram for part 2
	c1->cd(2);
	h2->Draw();
	
	//Histogram for part 3
	TCanvas *c2 = new TCanvas("c2", "Delta Phi",0,0,800,800);
	h3->Draw();
	TF1 *f1 = new TF1("f1", "gaus",-PI/2,PI/2);
	h3->Fit("f1","R");
	TF1 *f2 = new TF1("f2", "gaus",PI/2,3*PI/2);
//	h3->Fit("f2","R");
	//f1->Draw();

	//Histogram for part 4
	c1->cd(3);
	h4->Draw();

	//Histogram for Etta
	c1->cd(4);
	h5->Draw();

	//Histogram for Delta etta and delta phi
	TCanvas *c3 = new TCanvas("c3", "2D Histogram",0,0,800,800);
	h6->Draw("surf1");

	//
	TCanvas *c4 = new TCanvas("c4", "Delta eta  Histogram",0,0,800,800);
	h7->Draw();
	//Numerical outputs and errors
	

	double errorhighpt = sqrt(nhighpt);
	cout << "Number of jet particles = " << nhighpt << " +/- " << errorhighpt << endl;
	
	in.close();
	
}


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>


#include "TH1.h"
#include "TFile.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TKey.h"
#include "TCanvas.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TF1.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TError.h"
#include "TPaletteAxis.h"
#include "TPaveText.h"
//#include "../interface/readFiles.cc"


using namespace std;

// macro to take 2 TH2D's and get the best expected limit from each bin, 
//output combined TH2D of limits & th2d to show which bin they came from
TString ToString(double num)
{
  ostringstream start;
  double num_2dp = int(num*100); 
  start<<num_2dp/100;
  TString start1=start.str();
  return start1;
}



int main()
{
  Double_t l1[5]  = {40,50,60,80,100};
  Double_t off[5] = {62.0 , 70.9 , 83.7 , 103, 123.6};
  
  Int_t n=5;
  TGraph*   jet    =  new TGraph(n, l1, off);
  jet->SetTitle("; L1 threshold [GeV]; 95\% efficiency [GeV]"); 
  jet->GetXaxis()->SetTitleSize(0.045);
  jet->GetXaxis()->SetTitleOffset(0.9);
  jet->GetXaxis()->SetTitleFont(42);
  jet->GetYaxis()->SetLabelFont(42);
  jet->GetYaxis()->SetLabelOffset(0.007);
  jet->GetYaxis()->SetLabelSize(0.03);
  jet->GetYaxis()->SetTitleSize(0.045);
  jet->GetYaxis()->SetTitleOffset(0.9);
  jet->GetYaxis()->SetTitleFont(42);
 
  
  TCanvas c1;
  c1.SetGrid();

  jet->SetLineColor(kRed);
  jet->SetLineWidth(2);
  jet->SetMarkerColor(kBlue);
  jet->SetMarkerStyle(21);
  jet->Draw("AP");
  
  TF1 *fit = new TF1("fit","pol1",1,1 );
  jet->Fit("fit");

  cout<<"fit: y="<<fit->GetParameter(1) <<"x + "<<fit->GetParameter(0) <<" "<<endl;
  
  TPaveText *text1 = new TPaveText(40,114,60,124);
  text1->SetFillColor(0);
  text1->AddText("Line of best fit:");
  text1->AddText("y = "+ToString(fit->GetParameter(1))+"x + "+ToString(fit->GetParameter(0)));
  text1->SetTextSize(0.04);
  text1->SetTextFont(42);
 
  text1->Draw("same");
  c1.Print("jet_95threshold_conv.pdf");




   return 0;
}

void scale(TH1D* h)
{

  double area = h->Integral(0,-1);
  h->Scale(1/area);

  return;
}

void plot(){

  TCanvas c1;

  TString fname1 = "SUMBGD_zjets_WZTauAnalysis_3.root";
  TFile* f1 = TFile::Open(fname1);
  
  TString fname2 = "SUMBGD_znunu_WZTauAnalysis_3.root";
  TFile* f2 = TFile::Open(fname2);
  

  // TFile f2* = new TFile("SUMBGD_znunu_WZTauAnalysis_3.root",'r');

  TH1D* h1 = (TH1D*) f1->Get("MetGenRatio");
  TH1D* h2 = (TH1D*) f2->Get("MetGenRatio");

  c1.SetLogy();
  h1->SetLineColor(kRed);
  h2->SetLineColor(kBlue);

  h1->SetStats(0);

  //normalise to unit area
  scale(h1);
  scale(h2);
  
  TLatex * tex = new TLatex(0.15,0.81,"#font[41]{CMS Simulation}");
  tex->SetNDC();
  tex->SetTextSize(0.045);
  tex->SetLineWidth(2);
  
  TLegend * leg2 = new TLegend(0.68, 0.6, 0.85, 0.85);
  leg2->SetFillColor(0);    leg2->SetShadowColor(0);
  leg2->SetBorderSize(0);   leg2->SetTextFont(42);
  leg2->SetTextSize(0.041);  

  leg2->AddEntry(h1,"Z(#mu#mu)", "l");
  leg2->AddEntry(h2,"Z(#nu#nu)", "l");

  c1.SetBottomMargin(0.15);
  h1->SetTitle(";E_{T}^{miss, #mu}/p_{T}(Z);a.u.");
  h1->GetXaxis()->SetTitleSize(0.041);
  h1->GetYaxis()->SetTitleSize(0.041);


  h1->Draw();
  h2->Draw("same");
  leg2->Draw();
  tex->Draw();
  
  c1.Print("ratioMETnoMu_GenZpT.eps");

}

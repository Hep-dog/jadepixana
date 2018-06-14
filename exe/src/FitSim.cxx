#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TH1.h"
#include "TLegend.h"
#include "TMath.h"
#include "TSpectrum.h"
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

// ADC/e
std::vector<Double_t> Charge2ADC()
{
  std::vector<Double_t> par;
  par = { 2.09058, 1.8527, 1.34034, 2.14249, 1.68305, 1.02989, 2.07139, 1.49872, 1.02843 };
  return par;
}

std::vector<Double_t> InitSrParameters(Int_t sector)
{
  std::vector<Double_t> par;
  switch (sector) {
  case 1:
    par = { 100, 400, 5000, 8000 };
    return par;
  case 2:
    par = { 100, 400, 5000, 8000 };
    return par;
  case 3:
    par = { 100, 300, 4000, 6000 };
    return par;
  case 4:
    par = { 100, 400, 4000, 8000 };
    return par;
  case 5:
    par = { 100, 400, 4000, 8000 };
    return par;
  case 6:
    par = { 100, 300, 4000, 6000 };
    return par;
  case 7:
    par = { 100, 400, 4000, 8000 };
    return par;
  case 8:
    par = { 100, 400, 4000, 8000 };
    return par;
  case 9:
    par = { 100, 300, 4000, 6000 };
    return par;
  }
}

std::vector<Double_t> SensorParameters(Int_t sector)
{
  std::vector<Double_t> par;
  switch (sector) {
  case 1:
    par = { 4, 30 };
    return par;
  case 2:
    par = { 8, 30 };
    return par;
  case 3:
    par = { 15, 30 };
    return par;
  case 4:
    par = { 4, 20 };
    return par;
  case 5:
    par = { 8, 20 };
    return par;
  case 6:
    par = { 15, 20 };
    return par;
  case 7:
    par = { 4, 15 };
    return par;
  case 8:
    par = { 8, 15 };
    return par;
  case 9:
    par = { 15, 15 };
    return par;
  }
}

Double_t DoubleGaussFun(Double_t* x, Double_t* par)
{
  Double_t result = par[0] * TMath::Gaus(x[0], par[1], par[2]);
  result += par[3] * TMath::Gaus(x[0], par[4], par[5]);
  return result;
}

Double_t GetPeaksX(TH1D* h)
{
  auto h_clone = (TH1D*)h->Clone("h_clone");
  Int_t npeaks = 20;
  std::unique_ptr<TSpectrum> s = std::make_unique<TSpectrum>(npeaks);
  Int_t nfound = s->Search(h_clone, 1, "", 0.1);
  auto xpeaks = s->GetPositionX();
  auto ypeaks = s->GetPositionY();
  auto pos = std::distance(ypeaks, std::max_element(ypeaks, ypeaks + nfound));
  Double_t xp = xpeaks[pos];
  return xp;
}

std::vector<Double_t> InitialFeParameters(Int_t sector)
{
  std::vector<Double_t> par;
  switch (sector) {
  case 1:
    par = { 3360, 3500, 3700, 3900 };
    return par;
  case 2:
    par = { 3000, 3100, 3250, 3500 };
    return par;
  case 3:
    par = { 2160, 2300, 2350, 2500 };
    return par;
  case 4:
    par = { 3450, 3600, 3800, 3950 };
    return par;
  case 5:
    par = { 2700, 2850, 3000, 3150 };
    return par;
  case 6:
    par = { 1650, 1750, 1800, 1950 };
    return par;
  case 7:
    par = { 3300, 3500, 3650, 3850 };
    return par;
  case 8:
    par = { 2400, 2550, 2650, 2750 };
    return par;
  case 9:
    par = { 1650, 1750, 1800, 1920 };
    return par;
  }
}

void print_usage()
{
  printf("NAME\n\tFitPeaks - \n");
  printf("\nJadePixAna\n\tFitPeaks -c -s -e\n ");
}

int main(int argc, char** argv)
{
  if (argc < 2) {
    print_usage();
    return -1;
  }

  std::string opt_data_rebin = "2";
  std::string opt_sim_rebin = "5";
  std::string opt_cut_bin = "5";
  std::string opt_output_file = "WeakFe.root";
  std::string opt_data_in_path = "output/WeakFe_all.root";
  std::string opt_sim_in_path = "output/WeakFe_all.root";

  for (int i = 1; i < argc; i++) {
    std::string opt(argv[i]);
    if (opt == "-rd") {
      if (i + 1 < argc) {
        i++;
        opt_data_rebin = argv[i];
      }
    }
    if (opt == "-rs") {
      if (i + 1 < argc) {
        i++;
        opt_sim_rebin = argv[i];
      }
    }
    if (opt == "-id") {
      if (i + 1 < argc) {
        i++;
        opt_data_in_path = argv[i];
      }
    }
    if (opt == "-is") {
      if (i + 1 < argc) {
        i++;
        opt_sim_in_path = argv[i];
      }
    }
    if (opt == "-cb") {
      if (i + 1 < argc) {
        i++;
        opt_cut_bin = argv[i];
      }
    }
    if (opt == "-o") {
      if (i + 1 < argc) {
        i++;
        opt_output_file = argv[i];
      }
    }
  }

  int data_rebin = static_cast<int>(std::stoul(opt_data_rebin));
  int sim_rebin = static_cast<int>(std::stoul(opt_sim_rebin));
  int cut_bin = static_cast<int>(std::stoul(opt_cut_bin));
  TString out_path = opt_output_file;
  TString data_in_path = opt_data_in_path;
  TString sim_in_path = opt_sim_in_path;

  auto data_infile = new TFile(data_in_path);
  if (!data_infile->IsOpen()) {
    std::cerr << "cannot open infile" << std::endl;
    return 1;
  }
  auto sim_infile = new TFile(sim_in_path);
  if (!sim_infile->IsOpen()) {
    std::cerr << "cannot open infile" << std::endl;
    return 1;
  }

  auto output_file = new TFile(out_path, "RECREATE");

  const int CLUSSIZE = 25;
  for (Int_t iSize = 1; iSize <= CLUSSIZE; iSize++) {
    auto data_hist_name = Form("A1/Projection1/npixels_cluster5x5_adc_A1_%dpixels", iSize);
    std::cout << data_hist_name << std::endl;
    auto data_h_cluster = dynamic_cast<TH1D*>(data_infile->Get(data_hist_name));
    data_h_cluster->Rebin(data_rebin);

    auto sim_hist_name = Form("ClusteringJadePix/detector_10/clusterSignal%d_d10", iSize);
    std::cout << sim_hist_name << std::endl;
    auto sim_h_cluster = dynamic_cast<TH1D*>(sim_infile->Get(sim_hist_name));
    sim_h_cluster->Rebin(sim_rebin);
    for (int i = 0; i < cut_bin; i++) {
      sim_h_cluster->SetBinContent(i, 0);
    }

    TString cname = Form("clus_size_%d", iSize);
    auto c1 = new TCanvas(cname, cname, 10, 10, 800, 600);

    auto data_h_cluster_clone = (TH1D*)data_h_cluster->Clone("data_h_cluster_clone");
    auto sim_h_cluster_clone = (TH1D*)sim_h_cluster->Clone("sim_h_cluster_clone");

    data_h_cluster_clone->Scale(1 / data_h_cluster_clone->GetMaximum());
    data_h_cluster_clone->Draw("HIST");
    data_h_cluster_clone->SetLineColor(kBlue);
    sim_h_cluster_clone->Scale(1 / sim_h_cluster_clone->GetMaximum());
    sim_h_cluster_clone->Draw("HIST,SAME");
    sim_h_cluster_clone->SetLineColor(kRed);

    data_h_cluster_clone->SetTitle("");

    auto lg = new TLegend(0.1, 0.7, 0.48, 0.9);
    lg->AddEntry(data_h_cluster_clone, Form("data-clus_size%d", iSize), "l");
    lg->AddEntry(sim_h_cluster_clone, Form("sim-clus_size%d", iSize), "l");
    lg->Draw();

    output_file->cd();
    c1->Write();
  }
  data_infile->Close();
  sim_infile->Close();
  output_file->Close();

  return 0;
}

#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TH1.h"
#include <iostream>
#include <utility>
#include <vector>

Double_t DoubleGaussFun(Double_t* x, Double_t* par)
{
  Double_t result = par[0] * TMath::Gaus(x[0], par[1], par[2]);
  result += par[3] * TMath::Gaus(x[0], par[4], par[5]);
  return result;
}

std::vector<Double_t> InitialParameters(Int_t sector)
{
  std::vector<Double_t> par;
  switch (sector) {
  case 1:
    par = { 1400, 3400, 300, 200, 3700, 400 };
    return par;
  case 2:
    par = { 2500, 3100, 300, 250, 3350, 400 };
    return par;
  case 3:
    par = { 4800, 2200, 300, 500, 2450, 400 };
    return par;
  }
}

std::vector<Double_t> InitialRange(Int_t sector)
{
  std::vector<Double_t> ran;
  switch (sector) {
  case 1:
    ran = { 3400, 3900 };
    return ran;
  case 2:
    ran = { 3000, 3450 };
    return ran;
  case 3:
    ran = { 2160, 2500 };
    return ran;
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

  std::string opt_start = "1";
  std::string opt_end = "2";
  std::string opt_output_file = "WeakFe.root";
  std::string opt_in_path = "output/WeakFe_all.root";
  std::string opt_source_name = "WeakFe";

  for (int i = 1; i < argc; i++) {
    std::string opt(argv[i]);
    if (opt == "-s") {
      if (i + 1 < argc) {
        i++;
        opt_start = argv[i];
      }
    }
    if (opt == "-e") {
      if (i + 1 < argc) {
        i++;
        opt_end = argv[i];
      }
    }
    if (opt == "-n") {
      if (i + 1 < argc) {
        i++;
        opt_source_name = argv[i];
      }
    }
    if (opt == "-i") {
      if (i + 1 < argc) {
        i++;
        opt_in_path = argv[i];
      }
    }
    if (opt == "-o") {
      if (i + 1 < argc) {
        i++;
        opt_output_file = argv[i];
      }
    }
  }

  int start = static_cast<int>(std::stoul(opt_start));
  int end = static_cast<int>(std::stoul(opt_end));
  TString out_path = opt_output_file;
  TString in_path = opt_in_path;
  std::string source_name = opt_source_name;

  auto infile = new TFile(in_path);
  if (!infile->IsOpen()) {
    std::cerr << "cannot open infile" << std::endl;
    return 1;
  }

  auto output_file = new TFile(out_path, "RECREATE");

  if (source_name == "WeakFe") {
    for (Int_t iSector = start; iSector < end; iSector++) {
      std::cout << "============> Sector " << iSector << std::endl;
      auto h_seed = dynamic_cast<TH1F*>(infile->Get(Form("seed_hist_A%d", iSector)));
      h_seed->Rebin(5);

      TString cname = Form("seed_hist_A%d", iSector);
      auto c1 = new TCanvas(cname, cname, 10, 10, 800, 600);

      auto h_seed_clone = (TH1D*)h_seed->Clone("h_seed_clone");

      auto par = InitialParameters(iSector);
      Double_t* para = &par[0];
      auto range = InitialRange(iSector);

      auto fit = new TF1("fit", DoubleGaussFun, range.at(0), range.at(1), 6);
      fit->SetParameters(para);
      fit->SetNpx(1000);
      h_seed_clone->Fit("fit", "RQ");
      Double_t gpar[6];
      fit->GetParameters(&gpar[0]);
      std::cout << "ka: " << gpar[1] << " kb: " << gpar[4] << std::endl;

      h_seed_clone->SetTitle("");
      h_seed_clone->GetXaxis()->SetTitle("ADC");
      h_seed_clone->GetYaxis()->SetTitle("Events");

      output_file->cd();
      c1->Write();
    }
  } else if (source_name == "Sr") {
    for (Int_t iSector = start; iSector < end; iSector++) {
      std::cout << "============> Sector " << iSector << std::endl;
      auto h_cluster = dynamic_cast<TH1F*>(infile->Get(Form("cluster_hist_A%d", iSector)));
      h_cluster->Rebin(80);

      TString cname = Form("cluster_hist_A%d", iSector);
      auto c1 = new TCanvas(cname, cname, 10, 10, 800, 600);

      auto h_cluster_clone = (TH1D*)h_cluster->Clone("h_cluster_clone");

      auto fitlandau = new TF1(Form("fitlandau%d", iSector), "landau", 500, 10000);

      h_cluster_clone->Draw();
      h_cluster_clone->Fit(Form("fitlandau%d", iSector), "RQ");

      h_cluster_clone->SetTitle("");
      h_cluster_clone->GetXaxis()->SetTitle("ADC");
      h_cluster_clone->GetYaxis()->SetTitle("Events");

      output_file->cd();
      c1->Write();
    }
  }

  infile->Close();
  output_file->Close();

  return 0;
}

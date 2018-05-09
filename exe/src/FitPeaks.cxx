#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TH1.h"
#include <iostream>
#include <utility>
#include <vector>

Double_t DoubleGaussFun(Double_t* x, Double_t* par)
{
  Double_t result = par[0] + par[1] * x[0];
  result += par[2] * TMath::Gaus(x[0], par[3], par[4]);
  return result;
}

std::pair<std::vector<Double_t>, std::vector<Double_t> > InitialParameters(Int_t sector)
{
  std::vector<Double_t> parA;
  std::vector<Double_t> parB;
  switch (sector) {
  case 1:
    parA = { 100, -0.5, 1400, 3400, 100, 200 };
    parB = { 100, -0.5, 400, 3700, 200, 100 };
    return std::make_pair(parA, parB);
  case 2:
    parA = { 100, -0.5, 1400, 3000, 100, 200 };
    parB = { 100, -0.5, 400, 3300, 200, 100 };
    return std::make_pair(parA, parB);
  case 3:
    parA = { 100, -0.5, 1400, 2200, 100, 200 };
    parB = { 100, -0.5, 400, 2500, 200, 100 };
    return std::make_pair(parA, parB);
  }
}

std::pair<std::vector<Double_t>, std::vector<Double_t> > InitialRange(Int_t sector)
{
  std::vector<Double_t> ranA;
  std::vector<Double_t> ranB;
  switch (sector) {
  case 1:
    ranA = { 3350, 3500 };
    ranB = { 3600, 3900 };
    return std::make_pair(ranA, ranB);
  case 2:
    ranA = { 3000, 3100 };
    ranB = { 3200, 3500 };
    return std::make_pair(ranA, ranB);
  case 3:
    ranA = { 2150, 2300 };
    ranB = { 2350, 2500 };
    return std::make_pair(ranA, ranB);
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
      Double_t* parA = &par.first[0];
      Double_t* parB = &par.first[0];
      auto range = InitialRange(iSector);

      auto fitA = new TF1("fitA", DoubleGaussFun, range.first.at(0), range.first.at(1), 6);
      fitA->SetParameters(parA);
      fitA->SetNpx(1000);
      h_seed_clone->Fit("fitA", "RQ");
      Double_t gparA[6];
      fitA->GetParameters(&gparA[0]);
      std::cout << "ka: " << gparA[3] << std::endl;

      auto fitB = new TF1("fitB", DoubleGaussFun, range.second.at(0), range.second.at(1), 6);
      fitB->SetParameters(parB);
      fitB->SetNpx(1000);
      h_seed_clone->Fit("fitB", "RQ+");
      Double_t gparB[6];
      fitB->GetParameters(&gparB[0]);
      std::cout << "kb: " << gparB[3] << std::endl;

      h_seed_clone->SetTitle("");
      h_seed_clone->GetXaxis()->SetTitle("ADC");
      h_seed_clone->GetYaxis()->SetTitle("Events");

      output_file->cd();
      c1->Write();
    }
  }else if(source_name == "Sr"){
    for (Int_t iSector = start; iSector < end; iSector++) {
      std::cout << "============> Sector " << iSector << std::endl;
      auto h_cluster = dynamic_cast<TH1D*>(infile->Get(Form("A%d/clus_adc_A%d", iSector,iSector)));
      h_cluster->Rebin(100);

      TString cname = Form("cluster_hist_A%d", iSector);
      auto c1 = new TCanvas(cname, cname, 10, 10, 800, 600);

      auto h_cluster_clone = (TH1D*)h_cluster->Clone("h_cluster_clone");

      auto fitlandau = new TF1(Form("fitlandau%d",iSector),"landau",200,8000);

      h_cluster_clone->Draw();
      h_cluster_clone->Fit(Form("fitlandau%d",iSector), "RQ");
      
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

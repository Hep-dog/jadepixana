#include "TAxis.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TGraph.h"
#include "TLegend.h"
#include <iostream>
#include <utility>
#include <vector>

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
    auto c1 = new TCanvas("clus_size_Mean_ADC", "clus_size_Mean_ADC", 10, 10, 800, 600);
    auto lg = new TLegend(0.1, 0.7, 0.48, 0.9);
    for (Int_t iSector = start; iSector < end; iSector++) {
      std::cout << "============> Sector " << iSector << std::endl;
      if ((iSector != 1) && (iSector != 4) && (iSector != 7))
        continue;
      auto gname = Form("A%d/clus_size_Mean_ADC_A%d", iSector, iSector);
      std::cout << gname << std::endl;
      auto g_clus = dynamic_cast<TGraph*>(infile->Get(gname));

      if (iSector == 1) {
        g_clus->Draw("ALP");
      } else {
        g_clus->Draw("SAME,LP");
      }

      g_clus->SetTitle("");
      g_clus->SetMarkerColor(iSector % 8 + 1);
      g_clus->SetMarkerStyle(iSector % 8 + 2);
      g_clus->SetLineColor(iSector % 8 + 1);
      g_clus->GetXaxis()->SetTitle("Number of pixels in a cluster");
      g_clus->GetYaxis()->SetTitle("Mean of charge collection peak[ADC]");
      g_clus->GetYaxis()->SetRangeUser(0, 4000);
      lg->AddEntry(g_clus, Form("A%d", iSector), "lp");
    }

    lg->Draw();
    c1->Update();
    output_file->cd();
    c1->Write();

    auto c2 = new TCanvas("clus_size_CCE", "clus_size_CCE", 10, 10, 800, 600);
    auto lge = new TLegend(0.1, 0.7, 0.48, 0.9);
    for (Int_t iSector = start; iSector < end; iSector++) {
      std::cout << "============> Sector " << iSector << std::endl;
      if ((iSector != 1) && (iSector != 4) && (iSector != 7))
        continue;
      auto gname = Form("A%d/clus_size_CCE_A%d", iSector, iSector);
      std::cout << gname << std::endl;
      auto g_clus = dynamic_cast<TGraph*>(infile->Get(gname));

      if (iSector == 1) {
        g_clus->Draw("ALP");
      } else {
        g_clus->Draw("SAME,LP");
      }

      g_clus->SetTitle("");
      g_clus->SetMarkerColor(iSector % 8 + 1);
      g_clus->SetMarkerStyle(iSector % 8 + 2);
      g_clus->SetLineColor(iSector % 8 + 1);
      g_clus->GetXaxis()->SetTitle("Number of pixels in a cluster");
      g_clus->GetYaxis()->SetTitle("CCE [%]");
      g_clus->GetYaxis()->SetRangeUser(0, 120);
      lge->AddEntry(g_clus, Form("A%d", iSector), "lp");
    }
    lge->Draw();
    c2->Update();
    output_file->cd();
    c2->Write();
  } else if (source_name == "Sr") {
    auto c1 = new TCanvas("clus_size_MPV_ADC", "clus_size_MPV_ADC", 10, 10, 800, 600);
    auto lg = new TLegend(0.1, 0.7, 0.48, 0.9);
    for (Int_t iSector = start; iSector < end; iSector++) {
      if ((iSector == 5) || (iSector == 6))
        continue;
      std::cout << "============> Sector " << iSector << std::endl;
      auto gname = Form("A%d/clus_size_MPV_ADC_A%d", iSector, iSector);
      std::cout << gname << std::endl;
      auto g_clus = dynamic_cast<TGraph*>(infile->Get(gname));

      if (iSector == 1) {
        g_clus->Draw("ALP");
      } else {
        g_clus->Draw("SAME,LP");
      }

      g_clus->SetTitle("");
      g_clus->SetMarkerColor(iSector % 8 + 1);
      g_clus->SetMarkerStyle(iSector % 8 + 2);
      g_clus->SetLineColor(iSector % 8);
      g_clus->GetXaxis()->SetTitle("Number of pixels in a cluster");
      g_clus->GetYaxis()->SetTitle("MPV [ADC]");
      g_clus->GetYaxis()->SetRangeUser(0, 4000);
      lg->AddEntry(g_clus, Form("A%d", iSector), "lp");
    }

    lg->Draw();
    c1->Update();
    output_file->cd();
    c1->Write();

    auto c2 = new TCanvas("clus_size_MPV_Charge", "clus_size_MPV_Charge", 10, 10, 800, 600);
    auto lge = new TLegend(0.1, 0.7, 0.48, 0.9);
    for (Int_t iSector = start; iSector < end; iSector++) {
      std::cout << "============> Sector " << iSector << std::endl;
      if ((iSector == 5) || (iSector == 6))
        continue;
      auto gname = Form("A%d/clus_size_MPV_Charge_A%d", iSector, iSector);
      std::cout << gname << std::endl;
      auto g_clus = dynamic_cast<TGraph*>(infile->Get(gname));

      if (iSector == 1) {
        g_clus->Draw("ALP");
      } else {
        g_clus->Draw("SAME,LP");
      }

      g_clus->SetTitle("");
      g_clus->SetMarkerColor(iSector % 8 + 1);
      g_clus->SetMarkerStyle(iSector % 8 + 2);
      g_clus->SetLineColor(iSector % 8);
      g_clus->GetXaxis()->SetTitle("Number of pixels in a cluster");
      g_clus->GetYaxis()->SetTitle("MPV [e]");
      g_clus->GetYaxis()->SetRangeUser(0, 3000);
      lge->AddEntry(g_clus, Form("A%d", iSector), "lp");
    }

    lge->Draw();
    c2->Update();
    output_file->cd();
    c2->Write();
  }

  infile->Close();
  output_file->Close();

  return 0;
}

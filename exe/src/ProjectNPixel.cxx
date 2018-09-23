#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TTree.h>
#include <iostream>
#include <string>
#include <vector>

void print_usage()
{
  printf("NAME\n\tHistTest - \n");
  printf("\nJadePixAna\n\tHistTest -cs -ce -n\n ");
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
  std::string opt_in_path = "output";
  std::string opt_source_name = "WeakFe";
  std::string opt_clus_size = "25";

  for (int i = 1; i < argc; i++) {
    std::string opt(argv[i]);
    if (opt == "-cs") {
      if (i + 1 < argc) {
        i++;
        opt_start = argv[i];
      }
    }
    if (opt == "-ce") {
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
    if (opt == "-size") {
      if (i + 1 < argc) {
        i++;
        opt_clus_size = argv[i];
      }
    }
  }

  int start = static_cast<int>(std::stoul(opt_start));
  int end = static_cast<int>(std::stoul(opt_end));
  int clus_size = static_cast<int>(std::stoul(opt_clus_size));
  TString out_path = opt_output_file;
  std::string in_path = opt_in_path;
  std::string source_name = opt_source_name;

  auto output_file = new TFile(out_path, "RECREATE");

  for (int i = start; i < end; i++) {

    std::cout << "---------> " << i << " <------------" << std::endl;
    if(i == 5 || i == 6){
      continue; 
    }
    TString infile_name = Form("%s/%s%d.root", in_path.c_str(), source_name.c_str(), i);

    std::cout << "---------> Processing file " << infile_name << std::endl;
    auto infile = new TFile(infile_name);

    auto hist_clus_size_adc = dynamic_cast<TH2D*>(infile->Get(Form("clus_size_adc_A%d", i)));
    auto hist_npixels_cluster5x5_adc = dynamic_cast<TH2D*>(infile->Get(Form("npixels_cluster5x5_adc_A%d", i)));
    auto hist_seed_adc = dynamic_cast<TH1D*>(infile->Get(Form("seed_adc_A%d", i)));
    auto hist_clus_adc = dynamic_cast<TH1D*>(infile->Get(Form("clus_adc_A%d", i)));
    auto hist_cluster5x5_adc = dynamic_cast<TH1D*>(infile->Get(Form("cluster5x5_adc_A%d", i)));

    auto sub_dir = output_file->mkdir(Form("A%d", i));

    auto sub_pro_dir = sub_dir->mkdir(Form("Projection%d", i));
    auto c1 = new TCanvas(Form("C_A%d", i), Form("C_A%d", i), 800, 600);
    for (Int_t iBin = 1; iBin <= clus_size; iBin++) {
      auto hpr = dynamic_cast<TH1D*>(hist_clus_size_adc->ProjectionX("", iBin, iBin));
      hpr->SetName(Form("clus_size_adc_A%d_size%d", i, iBin));

      auto hpr_npix = dynamic_cast<TH1D*>(hist_npixels_cluster5x5_adc->ProjectionY("", iBin + 1, iBin + 1));
      hpr_npix->SetName(Form("npixels_cluster5x5_adc_A%d_%dpixels", i, iBin));

      sub_pro_dir->cd();
      hpr->Write();
      hpr_npix->Write();

      if (iBin == 1) {
        //hpr->Draw();
        hpr_npix->Draw();
        hpr_npix->SetLineColor(iBin % 8);
        //hpr_npix->GetYaxis()->SetRangeUser(0, 8000);
        hpr_npix->GetXaxis()->SetTitle("ADC");
      } else {
        //hpr->Draw("same");
        hpr_npix->Draw("same");
        hpr_npix->SetLineColor(iBin % 8);
      }
    }

    sub_dir->cd();
    hist_clus_size_adc->Write();
    hist_npixels_cluster5x5_adc->Write();
    hist_seed_adc->Write();
    hist_clus_adc->Write();
    hist_cluster5x5_adc->Write();
    c1->Write();
    infile->Close();
  }

  output_file->Close();

  std::cout << "File saved as: \n"
            << out_path << std::endl;

  return 0;
}

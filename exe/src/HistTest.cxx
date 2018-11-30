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
  printf("\nJadePixAna\n\tHistTest -c -s -e\n ");
}

int main(int argc, char** argv)
{
  if (argc < 2) {
    print_usage();
    return -1;
  }

  std::string opt_start = "1";
  std::string opt_end = "2";
  std::string opt_chip_number = "1";
  std::string opt_output_file = "WeakFe.root";
  std::string opt_in_path = "output";
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
    if (opt == "-c") {
      if (i + 1 < argc) {
        i++;
        opt_chip_number = argv[i];
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
  int chip_number = static_cast<int>(std::stoul(opt_chip_number));
  TString out_path = opt_output_file;
  std::string in_path = opt_in_path;
  std::string source_name = opt_source_name;

  auto output_file = new TFile(out_path, "RECREATE");
  std::vector<TFile*> infile;

  TH2D* output_hist_clus_size_adc;
  TH2D* output_hist_npixels_cluster5x5_adc;
  TH1D* output_hist_seed_adc;
  TH1D* output_hist_clus_adc;
  TH1D* output_hist_cluster5x5_adc;

  for (int i = start; i < end; i++) {

    std::cout << "---------> " << i << " <------------" << std::endl;
    TString infile_name = Form("%s/%s%d_%d.root", in_path.c_str(), source_name.c_str(), chip_number, i);
    infile.push_back(new TFile(infile_name));
    std::cout << "---------> Processing file " << infile_name << std::endl;
  }

  auto base_file = infile.back();

  auto hist_clus_size_adc = dynamic_cast<TH2D*>(base_file->Get("clus_size_adc"));
  auto hist_npixels_cluster5x5_adc = dynamic_cast<TH2D*>(base_file->Get("npixels_cluster5x5_adc"));
  auto hist_seed_adc = dynamic_cast<TH1D*>(base_file->Get("seed_adc"));
  auto hist_clus_adc = dynamic_cast<TH1D*>(base_file->Get("clus_adc"));
  auto hist_cluster5x5_adc = dynamic_cast<TH1D*>(base_file->Get("cluster5x5_adc"));

  output_hist_clus_size_adc = (TH2D*)hist_clus_size_adc->Clone();
  output_hist_clus_size_adc->SetName(Form("clus_size_adc_A%d", chip_number));

  output_hist_npixels_cluster5x5_adc = (TH2D*)hist_npixels_cluster5x5_adc->Clone();
  output_hist_npixels_cluster5x5_adc->SetName(Form("npixels_cluster5x5_adc_A%d", chip_number));

  output_hist_seed_adc = (TH1D*)hist_seed_adc->Clone();
  output_hist_seed_adc->SetName(Form("seed_adc_A%d", chip_number));

  output_hist_clus_adc = (TH1D*)hist_clus_adc->Clone();
  output_hist_clus_adc->SetName(Form("clus_adc_A%d", chip_number));

  output_hist_cluster5x5_adc = (TH1D*)hist_cluster5x5_adc->Clone();
  output_hist_cluster5x5_adc->SetName(Form("cluster5x5_adc_A%d", chip_number));
  infile.pop_back();

  for (auto& fin : infile) {
    auto in_hist_clus_size_adc = dynamic_cast<TH2D*>(fin->Get("clus_size_adc"));
    auto in_hist_npixels_cluster5x5_adc = dynamic_cast<TH2D*>(fin->Get("npixels_cluster5x5_adc"));
    auto in_hist_seed_adc = dynamic_cast<TH1D*>(fin->Get("seed_adc"));
    auto in_hist_clus_adc = dynamic_cast<TH1D*>(fin->Get("clus_adc"));
    auto in_hist_cluster5x5_adc = dynamic_cast<TH1D*>(fin->Get("cluster5x5_adc"));

    auto clone_clus_size_adc = (TH2D*)in_hist_clus_size_adc->Clone();
    auto clone_npixels_cluster5x5_adc = (TH2D*)in_hist_npixels_cluster5x5_adc->Clone();
    auto clone_seed_adc = (TH1D*)in_hist_seed_adc->Clone();
    auto clone_clus_adc = (TH1D*)in_hist_clus_adc->Clone();
    auto clone_cluster5x5_adc = (TH1D*)in_hist_cluster5x5_adc->Clone();

    output_hist_clus_size_adc->Add(clone_clus_size_adc);
    output_hist_npixels_cluster5x5_adc->Add(clone_npixels_cluster5x5_adc);
    output_hist_seed_adc->Add(clone_seed_adc);
    output_hist_clus_adc->Add(clone_clus_adc);
    output_hist_cluster5x5_adc->Add(clone_cluster5x5_adc);
  }

  output_file->cd();
  output_hist_clus_size_adc->Write();
  output_hist_npixels_cluster5x5_adc->Write();
  output_hist_seed_adc->Write();
  output_hist_clus_adc->Write();
  output_hist_cluster5x5_adc->Write();
  output_file->Close();

  for (auto& fin : infile)
    fin->Close();

  std::cout << "File saved as: \n"
            << out_path << std::endl;

  return 0;
}

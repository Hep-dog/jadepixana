#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#include <iostream>
#include <string>
#include <vector>

void GetHist(int istart, int iend, std::string in_path, TString out_path)
{
  auto output_file = new TFile(out_path, "RECREATE");

  for (int i = istart; i < iend; i++) {

    std::cout << "---------> " << i << " <------------" << std::endl;
    TString infile_name = Form("%s/WeakFe_CHIPA%d.root", in_path.c_str(), i);

    std::cout << "---------> Processing file " << infile_name << std::endl;
    auto fin = new TFile(infile_name);
    auto cluster_tree = dynamic_cast<TTree*>(fin->Get("clusters"));

    TString seed_hist_name = Form("seed_hist_A%d",i);
    cluster_tree->Draw("seed_adc >> hist_seed(5000,0,5000)");
    auto seed_hist = dynamic_cast<TH1F*>(gDirectory->Get("hist_seed"));
    seed_hist->SetName(seed_hist_name);

    output_file->cd();
    seed_hist->Write();

    TString clus_hist_name = Form("cluster_hist_A%d",i);
    cluster_tree->Draw("cluster_adc >> hist_clus(5000,0,5000)");
    auto clus_hist = dynamic_cast<TH1F*>(gDirectory->Get("hist_clus"));
    clus_hist->SetName(clus_hist_name);

    output_file->cd();
    clus_hist->Write();
    fin->Close();
  }

  output_file->Close();
}

void print_usage()
{
  printf("NAME\n\tAddTest - \n");
  printf("\nJadePixAna\n\tAddTest -cs -ce\n ");
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
  TString output_file = opt_output_file;
  std::string in_path = opt_in_path;

  GetHist(start, end, in_path, output_file);

  std::cout << "File saved as: \n"
            << output_file << std::endl;

  return 0;
}

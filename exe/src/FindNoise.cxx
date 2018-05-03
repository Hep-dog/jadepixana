#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include <iostream>
#include <utility>
#include <vector>

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

  for (Int_t iSector = start; iSector < end; iSector++) {
    std::cout << "============> Sector " << iSector << std::endl;

    auto sub_dir = infile->GetDirectory(Form("A%d", iSector));
    sub_dir->cd();

    auto h2_mean_name = Form("hist_mean_A%d", iSector);
    auto h2_mean = new TH2F(h2_mean_name, h2_mean_name, 48, 0, 48, 16, 0, 16);
    auto h2_rms_name = Form("hist_rms_A%d", iSector);
    auto h2_rms = new TH2F(h2_rms_name, h2_rms_name, 48, 0, 48, 16, 0, 16);
    const int m_nx = 16;
    const int m_ny = 48;
    for (Int_t ix = 0; ix < m_nx; ix++)
      for (Int_t iy = 0; iy < m_ny; iy++) {
        auto h_base = dynamic_cast<TH1F*>(sub_dir->Get(Form("base_hist_A%d_pix%d_%d", iSector, ix, iy)));
        h2_mean->Fill(iy, ix, h_base->GetMean());
        h2_rms->Fill(iy, ix, h_base->GetRMS());
      }

    output_file->cd();
    h2_mean->Write();
    h2_rms->Write();
  }
  infile->Close();
  output_file->Close();

  return 0;
}

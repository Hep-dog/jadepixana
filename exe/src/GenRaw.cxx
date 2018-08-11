#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <iostream>
#include <string>
#include <vector>

void GetHist(int cut, std::string enbale_raw_plot, std::string in_path, TString out_path)
{
  auto output_file = new TFile(out_path, "RECREATE");

  std::cout << "---------> Processing file " << in_path << std::endl;
  auto fin = new TFile(in_path.c_str());
  if (!fin->IsOpen()) {
    std::cerr << "Wrong file!!! " << std::endl;
    return;
  }
  auto cluster_tree = dynamic_cast<TTree*>(fin->Get("clusters"));
  auto nevents = cluster_tree->GetEntries();
  std::cout << "Total events: " << nevents << std::endl;

  using IntVec = std::vector<int>;
  using ShortVec = std::vector<int16_t>;

  TTreeReader theReader("clusters", fin);
  TTreeReaderValue<ShortVec> rawRV(theReader, "raw_adc");
  TTreeReaderValue<ShortVec> cdsRV(theReader, "cds_adc");

  const int m_nx = 16;
  const int m_ny = 96;
  const int pix_arrays = m_nx * m_ny;

  auto raw_sub_dir = output_file->mkdir("raw");
  auto cds_sub_dir = output_file->mkdir("cds");
  int counts = 0;
  while (theReader.Next()) {

    if (counts % static_cast<int>(nevents * 0.02) == 0)
      std::cout << "--------> "
                << std::setprecision(3) << std::fixed << counts * 100.0 / nevents
                << "% <--------" << std::endl;

    counts++;

    TString cds_hist_name = Form("cds_number%d", counts);
    auto cds_hist = std::make_shared<TH2F>(cds_hist_name, cds_hist_name, m_ny, 1, m_ny, m_nx, 1, m_nx);
    auto cds = cdsRV.Get();
    if (cds->size() != m_nx * m_ny) {
      continue;
    }

    bool enbale_plot = false;
    for (Int_t ix = 0; ix < m_nx; ix++)
      for (Int_t iy = 0; iy < m_ny; iy++) {
        auto pos = ix + m_nx * iy;
        auto value = (*cds).at(pos);
        if (value > cut) {
          enbale_plot = true;
        }
        cds_hist->SetBinContent(iy + 1, ix + 1, value);
      }

    if (enbale_plot) {
      cds_sub_dir->cd();
      cds_hist->Write();
    }

    TString raw_hist_name = Form("raw_number%d", counts);
    auto raw_hist = std::make_shared<TH2F>(raw_hist_name, raw_hist_name, m_ny, 1, m_ny, m_nx, 1, m_nx);

    auto raw = rawRV.Get();
    if (raw->size() != m_nx * m_ny) {
      continue;
    }

    for (Int_t ix = 0; ix < m_nx; ix++)
      for (Int_t iy = 0; iy < m_ny; iy++) {
        auto pos = ix + m_nx * iy;
        auto value = (*raw).at(pos);
        raw_hist->SetBinContent(iy + 1, ix + 1, value);
      }

    if (enbale_raw_plot != "false") {
      raw_sub_dir->cd();
      raw_hist->Write();
    }
  }

  fin->Close();

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

  std::string opt_output_file = "WeakFe.root";
  std::string opt_in_path = "output";
  std::string opt_thr = "500";
  std::string opt_enbale_raw_plot = "true";

  for (int i = 1; i < argc; i++) {
    std::string opt(argv[i]);
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
    if (opt == "-c") {
      if (i + 1 < argc) {
        i++;
        opt_thr = argv[i];
      }
    }
    if (opt == "-e") {
      if (i + 1 < argc) {
        i++;
        opt_enbale_raw_plot = argv[i];
      }
    }
  }

  TString output_file = opt_output_file;
  std::string in_path = opt_in_path;
  int cut = static_cast<int>(std::stol(opt_thr));
  std::string enbale_raw_plot = opt_enbale_raw_plot;

  GetHist(cut, enbale_raw_plot, in_path, output_file);

  std::cout << "File saved as: \n"
            << output_file << std::endl;

  return 0;
}

#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <iostream>
#include <string>
#include <vector>

void GetHist(int nbins, std::string in_path, TString out_path)
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

  using IntVec = std::vector<int>;
  using ShortVec = std::vector<int16_t>;

  TTreeReader theReader("clusters", fin);
  TTreeReaderValue<ShortVec> baseRV(theReader, "base_adc");

  const int m_nx = 16;
  const int m_ny = 48;
  const int pix_arrays = m_nx * m_ny;
  std::shared_ptr<TH1F> base_hist[pix_arrays];
  for (Int_t ix = 0; ix < m_nx; ix++)
    for (Int_t iy = 0; iy < m_ny; iy++) {
      auto pos = ix + m_nx * iy;
      TString hist_name = Form("base_hist_pix%d_%d", ix, iy);
      base_hist[pos] = std::make_shared<TH1F>(hist_name, hist_name, 1000, -500, 500);
    }

  int counts = 0;
  while (theReader.Next()) {

    if (counts % static_cast<int>(nevents * 0.02) == 0)
      std::cout << "--------> "
                << std::setprecision(3) << std::fixed << counts * 100.0 / nevents
                << "% <--------" << std::endl;
    counts++;
    auto base = baseRV.Get();
    if (base->size() != m_nx * m_ny) {
      continue;
    }

    for (Int_t ix = 0; ix < m_nx; ix++)
      for (Int_t iy = 0; iy < m_ny; iy++) {
        auto pos = ix + m_nx * iy;
        auto value = (*base).at(pos);
        base_hist[pos]->Fill(value);
      }
  }

  auto h2_mean_name = Form("hist_mean");
  auto h2_mean = new TH2F(h2_mean_name, h2_mean_name, m_ny, 0, m_ny, m_nx, 0, m_nx);
  auto h2_rms_name = Form("hist_rms");
  auto h2_rms = new TH2F(h2_rms_name, h2_rms_name, m_ny, 0, m_ny, m_nx, 0, m_nx);
  for (Int_t ix = 0; ix < m_nx; ix++)
    for (Int_t iy = 0; iy < m_ny; iy++) {
      auto pos = ix + m_nx * iy;
      h2_mean->Fill(iy, ix, base_hist[pos]->GetMean());
      h2_rms->Fill(iy, ix, base_hist[pos]->GetRMS());
    }

  output_file->cd();
  for (Int_t ix = 0; ix < m_nx; ix++)
    for (Int_t iy = 0; iy < m_ny; iy++) {
      auto pos = ix + m_nx * iy;
      base_hist[pos]->Write();
    }
  h2_mean->Write();
  h2_rms->Write();

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

  std::string opt_nbins = "5000";
  std::string opt_output_file = "WeakFe.root";
  std::string opt_in_path = "output";

  for (int i = 1; i < argc; i++) {
    std::string opt(argv[i]);
    if (opt == "-n") {
      if (i + 1 < argc) {
        i++;
        opt_nbins = argv[i];
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

  int nbins = static_cast<int>(std::stoul(opt_nbins));
  TString output_file = opt_output_file;
  std::string in_path = opt_in_path;

  GetHist(nbins, in_path, output_file);

  std::cout << "File saved as: \n"
            << output_file << std::endl;

  return 0;
}

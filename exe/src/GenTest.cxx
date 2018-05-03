#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#include <TTreeReader.h>
#include <iostream>
#include <string>
#include <vector>

void GetHist(int istart, int iend, int nbins, std::string in_path, std::string source_name, TString out_path)
{
  auto output_file = new TFile(out_path, "RECREATE");

  for (int i = istart; i < iend; i++) {

    std::cout << "---------> " << i << " <------------" << std::endl;
    TString infile_name = Form("%s/%s_CHIPA%d.root", in_path.c_str(), source_name.c_str(), i);

    std::cout << "---------> Processing file " << infile_name << std::endl;
    auto fin = new TFile(infile_name);
    auto cluster_tree = dynamic_cast<TTree*>(fin->Get("clusters"));
    auto nevents = cluster_tree->GetEntries();

    using IntVec = std::vector<int>;
    using ShortVec = std::vector<int16_t>;

    TTreeReader theReader("clusters", fin);
    TTreeReaderValue<IntVec> seedRV(theReader, "seed_adc");
    TTreeReaderValue<IntVec> clusRV(theReader, "cluster_adc");
    TTreeReaderValue<ShortVec> baseRV(theReader, "base_adc");

    TString seed_hist_name = Form("seed_hist_A%d", i);
    TString clus_hist_name = Form("cluster_hist_A%d", i);

    auto seed_hist = new TH1F(seed_hist_name, seed_hist_name, nbins, 0, nbins);
    auto clus_hist = new TH1F(clus_hist_name, clus_hist_name, nbins, 0, nbins);

    const int m_nx = 16;
    const int m_ny = 48;
    const int pix_arrays = m_nx * m_ny;
    std::shared_ptr<TH1F> base_hist[pix_arrays];
    for (Int_t ix = 0; ix < m_nx; ix++)
      for (Int_t iy = 0; iy < m_ny; iy++) {
        auto pos = ix + m_nx * iy;
        TString hist_name = Form("base_hist_A%d_pix%d_%d", i, ix, iy);
        base_hist[pos] = std::make_shared<TH1F>(hist_name, hist_name, 1000, -500, 500);
      }

    int counts = 0;
    while (theReader.Next()) {

      if (counts % static_cast<int>(nevents * 0.02) == 0)
        std::cout << "--------> "
                  << std::setprecision(3) << std::fixed << counts * 100.0 / nevents
                  << "% <--------" << std::endl;

      auto seed = seedRV.Get();
      for (auto& adc : *seed) {
        seed_hist->Fill(adc);
      }

      auto clus = clusRV.Get();
      for (auto& adc : *clus) {
        clus_hist->Fill(adc);
      }

      counts++;

      auto base = baseRV.Get();
      if (base->size() != 768) {
        continue;
      }

      for (Int_t ix = 0; ix < m_nx; ix++)
        for (Int_t iy = 0; iy < m_ny; iy++) {
          auto pos = ix + m_nx * iy;
          auto value = (*base).at(pos);
          base_hist[pos]->Fill(value);
        }
    }

    output_file->cd();
    seed_hist->Write();
    clus_hist->Write();

    auto sub_dir = output_file->mkdir(Form("A%d",i));
    sub_dir->cd();
    for (Int_t ix = 0; ix < m_nx; ix++)
      for (Int_t iy = 0; iy < m_ny; iy++) {
        auto pos = ix + m_nx * iy;
        base_hist[pos]->Write();
      }

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
  std::string opt_nbins = "5000";
  std::string opt_chip_number = "1";
  std::string opt_output_file = "WeakFe.root";
  std::string opt_in_path = "output";
  std::string opt_source_name = "WeakFe";

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
    if (opt == "-nb") {
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
    if (opt == "-n") {
      if (i + 1 < argc) {
        i++;
        opt_source_name = argv[i];
      }
    }
  }

  int start = static_cast<int>(std::stoul(opt_start));
  int end = static_cast<int>(std::stoul(opt_end));
  int nbins = static_cast<int>(std::stoul(opt_nbins));
  int chip_number = static_cast<int>(std::stoul(opt_chip_number));
  TString output_file = opt_output_file;
  std::string in_path = opt_in_path;
  std::string source_name = opt_source_name;

  GetHist(start, end, nbins, in_path, source_name, output_file);

  std::cout << "File saved as: \n"
            << output_file << std::endl;

  return 0;
}

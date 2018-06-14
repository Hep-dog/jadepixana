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
  std::cout << "Total events: " << nevents << std::endl;

  using IntVec = std::vector<int>;
  using Size_tVec = std::vector<size_t>;
  using ShortVec = std::vector<int16_t>;

  TTreeReader theReader("clusters", fin);
  TTreeReaderValue<Size_tVec> baseRV(theReader, "cluster_size");

  auto hist_clus_size = new TH1F("clus_size_hist","clus_size_hist", 25, 0, 25);

  int counts = 0;
  while (theReader.Next()) {

    if (counts % static_cast<int>(nevents * 0.02) == 0)
      std::cout << "--------> "
        << std::setprecision(3) << std::fixed << counts * 100.0 / nevents
        << "% <--------" << std::endl;
    counts++;
    auto clus_size_vec = baseRV.Get();
    for(auto &size : *clus_size_vec){
      hist_clus_size->Fill(size);
    }
  }

  output_file->cd();
  hist_clus_size->Write();
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

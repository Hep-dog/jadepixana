#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TTree.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

void AddTree(int istart, int iend, int chip_number, std::string in_path, std::string source_name,TString out_path)
{
  auto output_file = new TFile(out_path, "RECREATE");
  auto chain = std::make_shared<TChain>("clusters");

  for (int i = istart; i < iend; i++) {

    std::cout << "---------> " << i << " <------------" << std::endl;
    TString infile_name = Form("%s/%s%d_%d.root", in_path.c_str(), source_name.c_str(),chip_number, i);

    std::cout << "---------> Processing file " << infile_name << std::endl;
    chain->Add(infile_name);
  }

  chain->LoadTree(0);
  auto out_tree_clone = chain->GetTree()->CloneTree(0);

  std::cout << "---------> Copying tree content " << std::endl;
  auto nevents = chain->GetEntries();
  for (Int_t i = 0; i < nevents; i++) {
    if (i % static_cast<int>(nevents*0.02) == 0)
      std::cout << "--------> " 
                << std::setprecision(3) << std::fixed << i * 100.0 / nevents 
                << "% <--------" << std::endl;

    chain->GetEvent(i);
    out_tree_clone->Fill();
  }
  out_tree_clone->Write();
  output_file->Close();
}

void print_usage()
{
  printf("NAME\n\tAddTest - \n");
  printf("\nJadePixAna\n\tAddTest -c -s -e\n ");
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
    if (opt == "-i") {
      if (i + 1 < argc) {
        i++;
        opt_in_path = argv[i];
      }
    }
    if (opt == "-n") {
      if (i + 1 < argc) {
        i++;
        opt_source_name = argv[i];
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
  std::string source_name = opt_source_name;

  AddTree(start, end, chip_number, in_path, source_name, output_file);

  std::cout << "File saved as: \n"
            << output_file << std::endl;

  return 0;
}

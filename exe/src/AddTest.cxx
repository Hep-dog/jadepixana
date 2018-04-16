#include <TFile.h>
#include <TChain.h>
#include <TTree.h>
#include <TH1.h>
#include <iostream>
#include <string>
#include <vector>

void AddTree(int istart, int iend, int chip_number, std::string in_path, TString out_path){

  auto outputFile = new TFile(out_path, "RECREATE");
  auto output_tree = std::make_shared<TTree>("clusters", "Seed information for JadePix1" );

  auto chain = std::make_shared<TChain>("clusters");

  std::vector<int> output_seed_adc; 
  std::vector<int> output_clus_adc; 
  output_tree->Branch("seed",&output_seed_adc);
  output_tree->Branch("cluster",&output_clus_adc);

  for(int i=istart; i<iend; i++){
    
    std::cout << "---------> " << i << " <------------" << std::endl;
    TString infile_name =  Form("%s/WeakFe_CHIPA%d_%d.root",in_path.c_str(),chip_number,i);

    std::cout << "---------> Processing file " << infile_name << std::endl;
    chain->Add(infile_name);
  }

  std::vector<int>* input_seed_adc=0;
  std::vector<int>* input_clus_adc=0;
  chain->SetBranchAddress("seed_adc",&input_seed_adc);
  chain->SetBranchAddress("cluster_adc",&input_clus_adc);

  for(Int_t i=0; i<chain->GetEntries();i++)
  {
    chain->GetEvent(i);
    output_seed_adc.clear();
    for(auto& seed : (*input_seed_adc)){
      output_seed_adc.push_back(seed);
    }

    output_clus_adc.clear();
    for(auto& clus : (*input_clus_adc)){
      output_clus_adc.push_back(clus);
    }

    output_tree->Fill();
  }
  output_tree->Write();
  outputFile->Close();
}

void print_usage(){
  printf("NAME\n\tAddTest - \n");
  printf("\nJadePixAna\n\tAddTest -c -s -e\n ");

}

int main(int argc, char** argv) {
  if (argc < 2) {
    print_usage() ;
    return -1;
  }

  std::string opt_start = "1";
  std::string opt_end = "2";
  std::string opt_chip_number = "1";
  std::string opt_outputFile = "WeakFe.root";
  std::string opt_in_path = "output";

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
    if (opt == "-o") {
      if (i + 1 < argc) {
        i++;
        opt_outputFile = argv[i];
      }
    }
  }

  int start = static_cast<int>(std::stoul(opt_start));
  int end = static_cast<int>(std::stoul(opt_end));
  int chip_number = static_cast<int>(std::stoul(opt_chip_number));
  TString outputFile = opt_outputFile;
  std::string in_path = opt_in_path;

  AddTree(start,end,chip_number,in_path,outputFile);

  std::cout << "File saved as: \n" << outputFile << std::endl;

  return 0;
}


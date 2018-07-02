{
  //auto output_file = new TFile("May_Sr90_Size.root", "RECREATE");

  //for (Int_t iSector = 1; iSector < 8; iSector++) {
  //  if (iSector == 5 || iSector == 6)
  //    continue;

  //  std::cout << " ==========> Processing: CHIPA" << iSector << std::endl;
  //  auto fin = TFile::Open(Form("output/May_Sr90_Size_CHIPA%d.root", iSector));
  //  if (!fin->IsOpen()) {
  //    std::cerr << "Wrong file!!! " << std::endl;
  //  }

  //  auto hist_size = (TH1F*)fin->Get("clus_size_hist");
  //  auto hist_size_clone = (TH1F*)hist_size->Clone();
  //  hist_size_clone->SetName(Form("clus_size_CHIPA%d", iSector));
  //  hist_size_clone->SetTitle(Form("clus_size_CHIPA%d", iSector));
  //  output_file->cd();
  //  hist_size_clone->Write();

  //  fin->Close();
  //}
  //output_file->Close();

  auto output_file = new TFile("May_Sr_Size_CHIPAll_1.root", "RECREATE");

  std::vector<int> thrVec = { 100, 150, 200, 250, 300, 350, 400, 450, 500 };
  std::vector<int> sectorVec = { 1, 2, 3, 4, 7 };
  for (Int_t iSector = 0; iSector < 5; iSector++)
    for (Int_t iTHR = 0; iTHR < 9; iTHR++) {

      std::cout << Form(" ==========> Processing: CHIPA%d Threshold %d", sectorVec.at(iSector), thrVec.at(iTHR)) << std::endl;
      //auto fin = TFile::Open(Form("output/ClusterSize/WeakFeTHR%d_Size_CHIPA%d_1.root", thrVec.at(iTHR), sectorVec.at[iSector]));
      auto fin = TFile::Open(Form("output/ClusterSize/May_SrTHR%d_Size_CHIPA%d_1.root", thrVec.at(iTHR), sectorVec.at(iSector)));
      if (!fin->IsOpen()) {
        std::cerr << "Wrong file!!! " << std::endl;
      }

      auto hist_size = (TH1F*)fin->Get("clus_size_hist");
      auto hist_size_clone = (TH1F*)hist_size->Clone();
      hist_size_clone->SetName(Form("clus_size_thr%d_CHIPA%d", thrVec.at(iTHR), sectorVec.at(iSector)));
      hist_size_clone->SetTitle(Form("clus_size_thr%d_CHIPA%d", thrVec.at(iTHR), sectorVec.at(iSector)));
      output_file->cd();
      hist_size_clone->Write();

      fin->Close();
    }
  output_file->Close();
}

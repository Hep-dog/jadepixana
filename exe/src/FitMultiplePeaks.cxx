#include <TCanvas.h>
#include <TF1.h>
#include <TFile.h>
#include <TGraph.h>
#include <TH1.h>
#include <TMath.h>
#include <TPaveStats.h>
#include <TSpectrum.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

// ADC/e
std::vector<Double_t> Charge2ADC()
{
  std::vector<Double_t> par;
  par = { 2.09058, 1.8527, 1.34034, 2.14249, 1.68305, 1.02989, 2.07139, 1.49872, 1.02843 };
  return par;
}

std::vector<Double_t> GetNoise()
{
  std::vector<Double_t> noiseVec;
  noiseVec = { 7.806, 8.197, 10.44, 7.428, 8.554, 12.527, 7.503, 9.383, 12.64 };
  return noiseVec;
}

std::vector<Double_t> InitSrParameters(Int_t sector)
{
  std::vector<Double_t> par;
  switch (sector) {
  case 1:
    par = { 100, 400, 5000, 8000 };
    return par;
  case 2:
    par = { 100, 400, 5000, 8000 };
    return par;
  case 3:
    par = { 100, 300, 4000, 6000 };
    return par;
  case 4:
    par = { 100, 400, 4000, 8000 };
    return par;
  case 5:
    par = { 100, 400, 4000, 8000 };
    return par;
  case 6:
    par = { 100, 300, 4000, 6000 };
    return par;
  case 7:
    par = { 100, 400, 4000, 8000 };
    return par;
  case 8:
    par = { 100, 400, 4000, 8000 };
    return par;
  case 9:
    par = { 100, 300, 4000, 6000 };
    return par;
  }
}

std::vector<Double_t> SensorParameters(Int_t sector)
{
  std::vector<Double_t> par;
  switch (sector) {
  case 1:
    par = { 4, 30 };
    return par;
  case 2:
    par = { 8, 30 };
    return par;
  case 3:
    par = { 15, 30 };
    return par;
  case 4:
    par = { 4, 20 };
    return par;
  case 5:
    par = { 8, 20 };
    return par;
  case 6:
    par = { 15, 20 };
    return par;
  case 7:
    par = { 4, 15 };
    return par;
  case 8:
    par = { 8, 15 };
    return par;
  case 9:
    par = { 15, 15 };
    return par;
  }
}

Double_t DoubleGaussFun(Double_t* x, Double_t* par)
{
  Double_t result = par[0] * TMath::Gaus(x[0], par[1], par[2]);
  result += par[3] * TMath::Gaus(x[0], par[4], par[5]);
  return result;
}

Double_t GetPeaksX(TH1D* h)
{
  auto h_clone = (TH1D*)h->Clone("h_clone");
  Int_t npeaks = 20;
  std::unique_ptr<TSpectrum> s = std::make_unique<TSpectrum>(npeaks);
  Int_t nfound = s->Search(h_clone, 1, "", 0.1);
  auto xpeaks = s->GetPositionX();
  auto ypeaks = s->GetPositionY();
  auto pos = std::distance(ypeaks, std::max_element(ypeaks, ypeaks + nfound));
  Double_t xp = xpeaks[pos];
  return xp;
}

std::vector<Double_t> InitialFeParameters(Int_t sector)
{
  std::vector<Double_t> par;
  switch (sector) {
  case 1:
    par = { 3360, 3500, 3700, 3900 };
    return par;
  case 2:
    par = { 3000, 3100, 3250, 3500 };
    return par;
  case 3:
    par = { 2160, 2300, 2350, 2500 };
    return par;
  case 4:
    par = { 3450, 3600, 3800, 3950 };
    return par;
  case 5:
    par = { 2700, 2850, 3000, 3150 };
    return par;
  case 6:
    par = { 1650, 1750, 1800, 1950 };
    return par;
  case 7:
    par = { 3300, 3500, 3650, 3850 };
    return par;
  case 8:
    par = { 2400, 2550, 2650, 2750 };
    return par;
  case 9:
    par = { 1650, 1750, 1800, 1920 };
    return par;
  }
}

std::vector<Double_t> InitialFeNDParameters(Int_t sector)
{
  std::vector<Double_t> par;
  switch (sector) {
  case 1:
    par = { 11200, 11800, 12400, 13000 };
    return par;
  case 2:
    par = { 9800, 10200, 10800, 11200 };
    return par;
  case 3:
    par = { 7000, 7400, 7800, 8100 };
    return par;
  }
}

TPaveText* GetStats(std::vector<double>& pstats)
{
  TPaveText* pt = new TPaveText(0.78, 0.775, 0.98, 0.935, "brNDC");
  pt->SetBorderSize(1);
  pt->SetFillColor(0);
  pt->SetTextAlign(12);
  pt->SetTextFont(42);
  pt->AddText(Form("Entries = %.0f", pstats[0]));
  pt->AddText(Form("k_{#alpha} = %.0f #pm %.0f", pstats[1], pstats[2]));
  pt->AddText(Form("k_{#beta} = %.0f #pm %.0f", pstats[3], pstats[4]));
  pt->AddText(Form("collection peak = %.0f", pstats[5]));
  //pt->AddText(Form("CCE = %.2f%%", pstats[6]));

  return pt;
}

void print_usage()
{
  printf("NAME\n\tFitPeaks - \n");
  printf("\nJadePixAna\n\tFitPeaks -c -s -e\n ");
}

int main(int argc, char** argv)
{
  if (argc < 2) {
    print_usage();
    return -1;
  }

  std::string opt_start = "1";
  std::string opt_end = "2";
  std::string opt_data_rebin = "2";
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
    if (opt == "-r") {
      if (i + 1 < argc) {
        i++;
        opt_data_rebin = argv[i];
      }
    }
  }

  int start = static_cast<int>(std::stoul(opt_start));
  int end = static_cast<int>(std::stoul(opt_end));
  int data_rebin = static_cast<int>(std::stoul(opt_data_rebin));
  TString out_path = opt_output_file;
  TString in_path = opt_in_path;
  std::string source_name = opt_source_name;

  auto infile = new TFile(in_path);
  if (!infile->IsOpen()) {
    std::cerr << "cannot open infile" << std::endl;
    return 1;
  }

  auto output_file = new TFile(out_path, "RECREATE");

  if (source_name == "WeakFe") {
    const int SECTORS = end - start;
    Double_t Sectors[SECTORS];
    Double_t Seed_ka_ADC[SECTORS];
    Double_t Seed_kb_ADC[SECTORS];
    Double_t Gain[SECTORS];
    Double_t Factor[SECTORS];
    std::vector<std::pair<double, double>> data;
    for (Int_t iSector = start; iSector < end; iSector++) {
      std::cout << "============> Sector " << iSector << std::endl;
      Sectors[iSector - start] = iSector;
      const int CLUSSIZE = 25;
      Double_t clus_size[CLUSSIZE];
      Double_t Mean[CLUSSIZE];
      Double_t CCE[CLUSSIZE];
      auto sensor_par = SensorParameters(iSector);
      Factor[iSector - start] = sensor_par.at(1) / sensor_par.at(0);
      auto subdir = output_file->mkdir(Form("A%d", iSector));
      for (Int_t iSize = 1; iSize <= CLUSSIZE; iSize++) {
        clus_size[iSize - 1] = iSize;
        auto hist_name = Form("A%d/Projection%d/npixels_cluster5x5_adc_A%d_%dpixels", iSector, iSector, iSector, iSize);
        std::cout << hist_name << std::endl;
        auto h_cluster = dynamic_cast<TH1D*>(infile->Get(hist_name));
        h_cluster->Rebin(data_rebin);

        TString cname = Form("clus_size_adc_A%d_size%d", iSector, iSize);
        auto c1 = new TCanvas(cname, cname, 10, 10, 800, 600);

        auto h_cluster_clone = (TH1D*)h_cluster->Clone("h_cluster_clone");

        h_cluster_clone->Draw();

        std::vector<double> pstats;
        pstats.push_back(h_cluster_clone->GetEntries());
        if (iSize == 1) {
          auto init_calib_peak_range = InitialFeParameters(iSector);
          auto fitA = new TF1("fitA", "gaus", init_calib_peak_range.at(0), init_calib_peak_range.at(1));
          h_cluster_clone->Fit("fitA", "RQ");
          Double_t parA[3];
          fitA->GetParameters(&parA[0]);
          std::cout << "Ka Mean: " << parA[1] << std::endl;
          Seed_ka_ADC[iSector - start] = parA[1];
          pstats.push_back(parA[1]);
          pstats.push_back(parA[2]);
          Gain[iSector - start] = parA[1] / 1640;

          auto fitB = new TF1("fitB", "gaus", init_calib_peak_range.at(2), init_calib_peak_range.at(3));
          h_cluster_clone->Fit("fitB", "RQ+");
          Double_t parB[3];
          fitB->GetParameters(&parB[0]);
          std::cout << "Kb Mean: " << parB[1] << std::endl;
          pstats.push_back(parB[1]);
          pstats.push_back(parB[2]);
          Seed_kb_ADC[iSector - start] = parB[1];
        }
        std::cout << "Sector: " << iSector << "Gain : " << Gain[iSector - start] << std::endl;

        auto init_highest_peakX = GetPeaksX(h_cluster_clone);

        auto fitgaus = new TF1(Form("fitgaus%d", iSector), "gaus", init_highest_peakX - 100, init_highest_peakX + 100);

        h_cluster_clone->Fit(Form("fitgaus%d", iSector), "RQ+");

        h_cluster_clone->SetTitle("");
        h_cluster_clone->GetXaxis()->SetTitle("ADC");
        h_cluster_clone->GetYaxis()->SetTitle("Events");

        Double_t par[3];
        fitgaus->GetParameters(&par[0]);
        std::cout << "Mean: " << par[1] << std::endl;
        Mean[iSize - 1] = par[1];
        CCE[iSize - 1] = par[1] / Seed_ka_ADC[iSector - start] * 100;

        if (iSize == 1) {
          pstats.push_back(par[1]);
          pstats.push_back(par[1] / Seed_ka_ADC[iSector - start] * 100);
          auto pt = GetStats(pstats);
          pt->Draw("SAME");
        }
        subdir->cd();
        c1->Write();
      }

      int npixels = CLUSSIZE;
      TString gname = Form("clus_size_Mean_ADC_A%d", iSector);
      auto g_clus_Mean = new TGraph(npixels, clus_size, Mean);
      g_clus_Mean->Draw("AC*");
      g_clus_Mean->SetName(gname);
      subdir->cd();
      g_clus_Mean->Write();

      TString gename = Form("clus_size_CCE_A%d", iSector);
      auto ge_clus_CCE = new TGraph(npixels, clus_size, CCE);
      ge_clus_CCE->Draw("P*");
      ge_clus_CCE->SetName(gename);
      subdir->cd();
      ge_clus_CCE->Write();

      data.push_back({ Factor[iSector - start], Gain[iSector - start] });
    }

    auto cgain = new TCanvas("cgain", "cgain", 100, 10, 800, 600);
    int nsectors = SECTORS;
    auto ggain = new TGraph(nsectors, Sectors, Gain);
    ggain->Draw("AC*");
    output_file->cd();
    cgain->Write();

    std::sort(data.begin(), data.end(), [](auto& l, auto& r) { return l.first < r.first; });
    Double_t factor_data[SECTORS];
    Double_t gain_data[SECTORS];
    int i = 0;
    for (auto& d : data) {
      factor_data[i] = d.first;
      gain_data[i] = d.second;
      i++;
    }

    auto cg = new TCanvas("cg", "cg", 100, 10, 800, 600);
    auto gga = new TGraph(nsectors, factor_data, gain_data);
    gga->Draw("AC*");
    output_file->cd();
    cg->Write();

  } else if (source_name == "WeakFeND") {
    const int SECTORS = end - start;
    Double_t Sectors[SECTORS];
    Double_t Seed_ka_ADC[SECTORS];
    Double_t Seed_kb_ADC[SECTORS];
    Double_t Gain[SECTORS];
    Double_t Factor[SECTORS];
    std::vector<std::pair<double, double>> data;
    for (Int_t iSector = start; iSector < end; iSector++) {
      std::cout << "============> Sector " << iSector << std::endl;
      Sectors[iSector - start] = iSector;
      const int CLUSSIZE = 25;
      Double_t clus_size[CLUSSIZE];
      Double_t Mean[CLUSSIZE];
      Double_t CCE[CLUSSIZE];
      auto sensor_par = SensorParameters(iSector);
      Factor[iSector - start] = sensor_par.at(1) / sensor_par.at(0);
      auto subdir = output_file->mkdir(Form("A%d", iSector));
      for (Int_t iSize = 1; iSize <= CLUSSIZE; iSize++) {
        clus_size[iSize - 1] = iSize;
        auto hist_name = Form("A%d/Projection%d/npixels_cluster5x5_adc_A%d_%dpixels", iSector, iSector, iSector, iSize);
        std::cout << hist_name << std::endl;
        auto h_cluster = dynamic_cast<TH1D*>(infile->Get(hist_name));
        h_cluster->Rebin(data_rebin);

        TString cname = Form("clus_size_adc_A%d_size%d", iSector, iSize);
        auto c1 = new TCanvas(cname, cname, 10, 10, 800, 600);
        auto h_cluster_clone = (TH1D*)h_cluster->Clone("h_cluster_clone");
        h_cluster_clone->Draw();

        std::vector<double> pstats;
        pstats.push_back(h_cluster_clone->GetEntries());
        if (iSize == 1) {
          auto init_calib_peak_range = InitialFeNDParameters(iSector);
          auto fitA = new TF1("fitA", "gaus", init_calib_peak_range.at(0), init_calib_peak_range.at(1));
          h_cluster_clone->Fit("fitA", "RQ");
          Double_t parA[3];
          fitA->GetParameters(&parA[0]);
          std::cout << "Ka Mean: " << parA[1] << std::endl;
          pstats.push_back(parA[1]);
          pstats.push_back(parA[2]);

          Seed_ka_ADC[iSector - start] = parA[1];
          Gain[iSector - start] = parA[1] / 1640;

          auto fitB = new TF1("fitB", "gaus", init_calib_peak_range.at(2), init_calib_peak_range.at(3));
          h_cluster_clone->Fit("fitB", "RQ+");
          Double_t parB[3];
          fitB->GetParameters(&parB[0]);
          std::cout << "Kb Mean: " << parB[1] << std::endl;
          pstats.push_back(parB[1]);
          pstats.push_back(parB[2]);

          Seed_kb_ADC[iSector - start] = parB[1];
        }
        std::cout << "Sector: " << iSector << "Gain : " << Gain[iSector - start] << std::endl;

        auto init_highest_peakX = GetPeaksX(h_cluster_clone);

        auto fitgaus = new TF1(Form("fitgaus%d", iSector), "gaus", init_highest_peakX - 300, init_highest_peakX + 300);

        h_cluster_clone->Fit(Form("fitgaus%d", iSector), "RQ+");

        h_cluster_clone->SetTitle("");
        h_cluster_clone->GetXaxis()->SetTitle("ADC");
        h_cluster_clone->GetYaxis()->SetTitle("Events");

        Double_t par[3];
        fitgaus->GetParameters(&par[0]);
        std::cout << "Mean: " << par[1] << std::endl;
        Mean[iSize - 1] = par[1];
        CCE[iSize - 1] = par[1] / Seed_ka_ADC[iSector - start] * 100;

        if (iSize == 1) {
          pstats.push_back(par[1]);
          pstats.push_back(par[1] / Seed_ka_ADC[iSector - start] * 100);

          for (auto& stats : pstats) {
            std::cout << stats << std::endl;
          }
          auto pt = GetStats(pstats);
          pt->Draw("SAME");
        }

        subdir->cd();
        c1->Write();
      }

      int npixels = CLUSSIZE;
      TString gname = Form("clus_size_Mean_ADC_A%d", iSector);
      auto g_clus_Mean = new TGraph(npixels, clus_size, Mean);
      g_clus_Mean->Draw("AC*");
      g_clus_Mean->SetName(gname);
      subdir->cd();
      g_clus_Mean->Write();

      TString gename = Form("clus_size_CCE_A%d", iSector);
      auto ge_clus_CCE = new TGraph(npixels, clus_size, CCE);
      ge_clus_CCE->Draw("P*");
      ge_clus_CCE->SetName(gename);
      subdir->cd();
      ge_clus_CCE->Write();

      data.push_back({ Factor[iSector - start], Gain[iSector - start] });
    }

    auto cgain = new TCanvas("cgain", "cgain", 100, 10, 800, 600);
    int nsectors = SECTORS;
    auto ggain = new TGraph(nsectors, Sectors, Gain);
    ggain->Draw("AC*");
    output_file->cd();
    cgain->Write();

    std::sort(data.begin(), data.end(), [](auto& l, auto& r) { return l.first < r.first; });
    Double_t factor_data[SECTORS];
    Double_t gain_data[SECTORS];
    int i = 0;
    for (auto& d : data) {
      factor_data[i] = d.first;
      gain_data[i] = d.second;
      i++;
    }

    auto cg = new TCanvas("cg", "cg", 100, 10, 800, 600);
    auto gga = new TGraph(nsectors, factor_data, gain_data);
    gga->Draw("AC*");
    output_file->cd();
    cg->Write();
  } else if (source_name == "Sr") {
    for (Int_t iSector = start; iSector < end; iSector++) {
      std::cout << "============> Sector " << iSector << std::endl;
      if (iSector == 5 || iSector == 6)
        continue;
      Double_t clus_size[25];
      Double_t MPV[25];
      Double_t MPV_Charge[25];
      Double_t S2N[25];
      auto init_par = InitSrParameters(iSector);
      auto subdir = output_file->mkdir(Form("A%d", iSector));
      for (Int_t iSize = 1; iSize <= 25; iSize++) {
        clus_size[iSize - 1] = iSize;
        auto hist_name = Form("A%d/Projection%d/npixels_cluster5x5_adc_A%d_%dpixels", iSector, iSector, iSector, iSize);
        std::cout << hist_name << std::endl;
        auto h_cluster = dynamic_cast<TH1D*>(infile->Get(hist_name));
        h_cluster->Rebin(init_par.at(0));

        TString cname = Form("clus_size_adc_A%d_size%d", iSector, iSize);
        auto c1 = new TCanvas(cname, cname, 10, 10, 800, 600);

        auto h_cluster_clone = (TH1D*)h_cluster->Clone("h_cluster_clone");

        TF1* fitlandau;
        if (iSize == 1) {
          fitlandau = new TF1(Form("fitlandau%d", iSector), "landau", init_par.at(1), init_par.at(2));
        } else {
          fitlandau = new TF1(Form("fitlandau%d", iSector), "landau", init_par.at(1), init_par.at(3));
        }

        h_cluster_clone->Draw();
        h_cluster_clone->Fit(Form("fitlandau%d", iSector), "RQ");

        h_cluster_clone->SetTitle("");
        h_cluster_clone->GetXaxis()->SetTitle("ADC");
        h_cluster_clone->GetYaxis()->SetTitle("Events");

        Double_t par[3];
        fitlandau->GetParameters(&par[0]);
        std::cout << "MPV: " << par[1] << std::endl;
        MPV[iSize - 1] = par[1];
        MPV_Charge[iSize - 1] = par[1] / Charge2ADC().at(iSector - 1);
        S2N[iSize - 1] = par[1] / GetNoise().at(iSector - 1);

        subdir->cd();
        c1->Write();
      }

      TString gname = Form("clus_size_MPV_ADC_A%d", iSector);
      auto g_clus_MPV = new TGraph(25, clus_size, MPV);
      g_clus_MPV->Draw("AC*");
      g_clus_MPV->SetName(gname);
      subdir->cd();
      g_clus_MPV->Write();

      TString gename = Form("clus_size_MPV_Charge_A%d", iSector);
      auto ge_clus_MPV = new TGraph(25, clus_size, MPV_Charge);
      ge_clus_MPV->Draw("AC*");
      ge_clus_MPV->SetName(gename);
      subdir->cd();
      ge_clus_MPV->Write();

      TString gs2nname = Form("clus_size_signal_to_noise_A%d", iSector);
      auto ge_clus_S2N = new TGraph(25, clus_size, S2N);
      ge_clus_S2N->Draw("AC*");
      ge_clus_S2N->SetName(gs2nname);
      subdir->cd();
      ge_clus_S2N->Write();
    }
  }

  infile->Close();
  output_file->Close();

  return 0;
}

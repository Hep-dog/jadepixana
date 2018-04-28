#include "JadeAnalysis.hh"

JadeAnalysis::JadeAnalysis(const JadeOption& opt)
    : m_opt(opt)
    , m_ev_n(0)
    , m_ev_print(0)
    , m_base_count(0)
    , m_base_numbers(1000)
{
  m_ev_print = m_opt.GetIntValue("PRINT_EVENT_N");
  m_seed_cut = m_opt.GetIntValue("SEED_CUT");
  m_neigh_cut = m_opt.GetIntValue("NEIGHGBOR_CUT");
  m_clus_cut = m_opt.GetIntValue("CLUSTER_CUT");
  m_clus_size = m_opt.GetIntValue("CLUSTER_SIZE");
  m_distance_cut = m_opt.GetFloatValue("DISTANCE_CUT");
  m_base_cut = m_opt.GetIntValue("BASE_CUT");
  m_base_numbers = m_opt.GetIntValue("BASE_NUMBERS");
  m_enable_raw_data_write = m_opt.GetBoolValue("ENABLE_RAW_DATA_WRITE");
  m_enable_hit_map_write = m_opt.GetBoolValue("ENABLE_HIT_MAP_WRITE");
  m_hist_nbins = m_opt.GetIntValue("HIST_NBINS");
  m_serial_orders = m_opt.GetIntValue("SERIAL_ORDERS");
}

JadeAnalysis::~JadeAnalysis()
{
  Reset();
}

void JadeAnalysis::Open()
{
  m_disable_file_write = m_opt.GetBoolValue("DISABLE_FILE_WRITE");
  if (m_disable_file_write)
    return;
  std::string path = m_opt.GetStringValue("PATH");
  std::string data_path = path + ".root";
  m_fd = TFile::Open(data_path.c_str(), "RECREATE");
  if (!m_fd->IsOpen()) {
    std::cerr << "JadeAnalysis: Failed to open/create file: " << data_path << "\n";
    throw;
  }
  m_tree_adc = std::make_shared<TTree>("clusters", "information for jadepix");
  m_tree_adc->Branch("seed_adc", &m_output_seed_adc);
  m_tree_adc->Branch("cluster_adc", &m_output_clus_adc);
  m_tree_adc->Branch("cluster_size", &m_output_clus_size);
  m_tree_adc->Branch("base_adc", &m_output_base_adc);
  m_tree_adc->Branch("pileup_counts", &m_output_pileup_counts);
  if (m_enable_raw_data_write) {
    m_tree_adc->Branch("cds_adc", &m_cds_adc);
    m_tree_adc->Branch("raw_adc", &m_raw_adc);
  }
  if (m_enable_hit_map_write) {
    m_tree_adc->Branch("hit_map", &m_hit);
  }

  m_hist2_clus_size_adc = std::make_shared<TH2D>("clus_size_adc", "clus_size_adc",
      m_hist_nbins, 0, m_hist_nbins, m_clus_size * m_clus_size, 1, m_clus_size * m_clus_size);
  m_hist_serial_order_counts = std::make_shared<TH1D>("serial_order_counts", "serial_order_counts",
      m_serial_orders, 0, m_serial_orders);
}

void JadeAnalysis::Reset()
{
  Close();
  m_ev_n = 0;
}

void JadeAnalysis::Close()
{
  if (m_disable_file_write)
    return;
  if (m_fd->IsOpen()) {
    m_tree_adc->Write();
    m_hist2_clus_size_adc->Write();
    m_fd->Close();
  }
}

void JadeAnalysis::Analysis(JadeDataFrameSP df)
{
  if ((m_ev_print != 0) && (m_ev_n % m_ev_print == 0)) {
    std::cout << "============ " << m_ev_n << " ==================" << std::endl;
    //df->Print(std::cout);
  }

  if (m_disable_file_write)
    return;

  m_trigger_serial_order = df->GetTriggerSerialOrder();

  if (m_trigger_serial_order == 0) {
    m_ev_n++;
    return;
  }

  if (m_enable_raw_data_write) {
    m_cds_adc.clear();
    m_raw_adc.clear();
    m_cds_adc = df->GetFrameCDS();
    m_raw_adc = df->GetFrameData();
  }

  m_output_base_adc.clear();
  if (m_base_count < m_base_numbers) {
    auto cds_adc = df->GetFrameCDS();
    if (std::none_of(cds_adc.begin(), cds_adc.end(),
            [=](auto& cds) { return cds > m_base_cut ? true : false; })) {
      m_output_base_adc.swap(cds_adc);
      m_base_count++;
    }
  }

  m_clus = std::make_shared<JadeCluster>(df);
  m_clus->SetSeedTHR(m_seed_cut);
  m_clus->SetNeighbourTHR(m_neigh_cut);
  m_clus->SetClusterTHR(m_clus_cut);
  m_clus->SetClusterSize(m_clus_size);
  m_clus->SetDistanceCut(m_distance_cut);
  m_clus->FindSeed();
  m_clus->FindPileUp();
  m_clus->FindCluster();

  auto pileup_counts = m_clus->GetPileUpCounts();
  m_output_pileup_counts.clear();
  if (pileup_counts > 0)
    m_output_pileup_counts.push_back(pileup_counts);

  auto seed_adc = m_clus->GetSeedADC();
  //std::cout << "seed ADC: " << std::endl;
  m_output_seed_adc.clear();
  if (!seed_adc.empty()) {
    for (auto& adc : seed_adc) {
      //std::cout << '\t' << adc;
      m_output_seed_adc.push_back(adc);
    }
    //std::cout << '\n';
  }

  auto clus_adc = m_clus->GetClusterADC();
  //std::cout << "cluster ADC: " << std::endl;
  m_output_clus_adc.clear();
  for (auto& adc : clus_adc) {
    //std::cout << '\t' << adc;
    m_output_clus_adc.push_back(adc);
  }

  //std::cout << '\n';

  //std::cout << "cluster ADC: " << std::endl;

  auto clus_size = m_clus->GetClusterSize();
  //std::cout << "cluster ADC: " << std::endl;
  m_output_clus_size.clear();
  for (auto& size : clus_size) {
    //std::cout << '\t' << adc;
    m_output_clus_size.push_back(size);
  }
  //std::cout << '\n';

  if (m_enable_hit_map_write) {
    auto center = m_clus->GetCenterOfGravity();
    //std::cout << "center with size: " << center.size() << std::endl;
    m_hit.clear();
    for (auto& pos : center) {
      //std::cout << "\t(" << pos.first << ", " << pos.second << ")\t";
      m_hit.push_back(pos);
    }
    //std::cout << '\n';
  }

  m_tree_adc->Fill();

  for (int i = 0; i < clus_adc.size(); i++) {
    m_hist2_clus_size_adc->Fill(clus_adc.at(i), clus_size.at(i));
  };

  for (int i = 0; i < clus_adc.size(); i++) {
    m_hist_serial_order_counts->Fill(m_trigger_serial_order);
  };

  m_ev_n++;
}

#ifndef JADE_JADECLUSTER_HH
#define JADE_JADECLUSTER_HH

#include "JadeDataFrame.hh"
#include "JadeSystem.hh"

#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <numeric>

class DLLEXPORT JadeCluster {
  public:
    JadeCluster();
    JadeCluster(JadeDataFrameSP df);
    virtual ~JadeCluster();
    void SetSeedTHR(int16_t thr);
    void SetClusterTHR(int16_t thr);
    void SetNeighbourTHR(int16_t thr);
    void SetClusterSize(size_t size);
    void SetClusterFixSize(size_t size);
    void SetDistanceCut(double cut);
    bool IsInEdge(size_t x, size_t y) const;
    bool IsInMatrix(size_t x, size_t y) const;
    bool IsInMask(size_t x, size_t y) const;
    bool IsMax(size_t x, size_t y);
    void SetPixelMask(size_t x, size_t y);
    int16_t GetPixelADC(size_t x, size_t y);
    int16_t GetPixelADC(std::pair<size_t, size_t> coord);
    std::vector<size_t> GetClusterSize();
    std::vector<int16_t> GetSeedADC();
    std::vector<int16_t> GetClusterADC();
    std::vector<int16_t> GetFixWindowClusterADC();
    std::vector<std::vector<int16_t>> GetNPixelsADC();
    int GetPileUpCounts();
    double GetDistance(std::pair<size_t, size_t> p1, std::pair<size_t, size_t> p2);
    virtual void FindSeed();
    virtual void FindSeedCoord();
    virtual void FindPileUp();
    virtual void FindCluster();
    virtual void FindFixWindowCluster();
    virtual std::vector<std::pair<size_t, size_t> > GetSeedCoord();
    virtual std::vector<std::pair<double, double> > GetCenterOfGravity();
    virtual std::vector<double> GetXCenterOfGravity();
    virtual std::vector<double> GetYCenterOfGravity();

  private:
    struct seed {
      std::pair<size_t, size_t> coord;
      int16_t adc;
    };
    struct cluster {
      std::vector<size_t> xCoord;
      std::vector<size_t> yCoord;
      std::vector<int16_t> adc;
      std::vector<int16_t> npix_adc;
      int16_t total_adc;
      size_t size;
    };

    std::vector<seed> GetSeed();
    std::vector<cluster> GetCluster();
    std::vector<cluster> GetFixWindowCluster();

  private:
    uint16_t m_offset_x;
    uint16_t m_offset_y;
    uint16_t m_n_x;
    uint16_t m_n_y;
    std::vector<int16_t> m_frame_adc;
    std::vector<bool> m_pixel_can_be_used;
    int16_t m_seed_thr;
    int16_t m_cluster_thr;
    int16_t m_neigh_thr;
    size_t m_size;
    size_t m_fix_size;
    double m_distance_cut;
    std::vector<seed> m_seed;
    std::vector<cluster> m_cluster;
    std::vector<cluster> m_fix_window_cluster;
    std::vector<std::pair<size_t, size_t>> m_seed_coord;

    bool m_is_seed_find;
    bool m_is_cluster_find;
    bool m_is_fix_cluster_find;
    int m_pileup_counts;
};

using JadeClusterSP = std::shared_ptr<JadeCluster>;

#endif

# Run

  ```
  RunTest -c sample.json
  ```

# Draw Option from TTree

  ```
  cluster->Draw("[(x+m_nx*y)]") 
  clusters->Draw("hit_map.first:hit_map.second >> hist2(48,0,48,16,0,16)", "", "COLZ")
  ```

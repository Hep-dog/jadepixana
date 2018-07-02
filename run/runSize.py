import subprocess
import time
import argparse
import sys
import os
import distutils.util


for j in [1,2,3,4,7]:
    for i in [100,150,200,250,300,350,400,450,500]:
        cmd = "GenClusSize -i output/ClusterSize/May_SrTHR"+str(i)+"_CHIPA"+ str(j)+ \
            "_1.root -o May_SrTHR" +str(i)+ "_Size_CHIPA"+str(j)+"_1.root"
        subprocess.call(cmd, shell=True)

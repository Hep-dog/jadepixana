#!/opt/JadePixDAQ/dependencies/anaconda3/bin/python

import subprocess
import time
import argparse
import sys
import os

parser = argparse.ArgumentParser(description='JadePix Analysis')

parser.add_argument('--cs',
                    action='store',
                    dest='chip_number_start',
                    default=1,
                    type=int,
                    help='chip number start')

parser.add_argument('--ce',
                    action='store',
                    dest='chip_number_end',
                    default=1,
                    type=int,
                    help='chip number end')

ARGS = parser.parse_args()

def add():
  for i in range(ARGS.chip_number_start, ARGS.chip_number_end):
    cmd = "AddTest -c " + str(i) +" -s 1 -e 61 -n Sr -i output -o output/Sr_CHIPA" + str(i) + ".root"
    subprocess.run(cmd, shell=True)
    time.sleep(1)

def noise():
  for i in range(ARGS.chip_number_start, ARGS.chip_number_end):
    if(i==5 or i==6):
      continue
    cmd = "hep_sub -g atlas -o /scratchfs/atlas/chenlj/jadepix/log/noise_A"+str(i)+".log -e /scratchfs/atlas/chenlj/jadepix/log/error_A"+str(i)+".log script/job_noise_A"+str(i)+".sh"
    print(cmd)
    subprocess.run(cmd, shell=True)
    time.sleep(1)


def main():
  #add()
  noise()

if __name__ == "__main__":
  main()

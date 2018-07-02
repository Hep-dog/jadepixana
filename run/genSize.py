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

def genSize():
    for i in range(ARGS.chip_number_start, ARGS.chip_number_end):
        cmd = "GenClusSize -i output/May_WeakFe_Tree_CHIPA" \
        + str(i) + ".root -o May_WeakFe_Size_CHIPA"+ str(i)+ ".root"
        print(cmd)
        subprocess.run(cmd, shell=True)
        time.sleep(0.1)

if __name__ == "__main__":
    genSize()

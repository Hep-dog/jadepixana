#!/besfs/groups/higgs/users/chenlj/software/anaconda3/bin/python

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

parser.add_argument('--mode',
                    action='store',
                    dest='mode',
                    default='Hist',
                    type=str,
                    help='mode')


ARGS = parser.parse_args()

chip_number = [1,2,3,4,7]

def add():
    for i in range(ARGS.chip_number_start, ARGS.chip_number_end):
        cmd = "AddTest -c " + str(i) +" -s 1 -e 7 -n WeakFe_ND -i output -o output/WeakFe_ND_Tree_CHIPA" + str(i) + ".root"
        subprocess.run(cmd, shell=True)
        time.sleep(1)

def addHist():
    #for i in range(ARGS.chip_number_start, ARGS.chip_number_end):
    for i in chip_number:
        cmd = "HistTest -c " + str(i) +" -s 1 -e 13 -n RC1_WeakFe -i output -o output/RC1_WeakFe_CHIPA" + str(i) + ".root"

        subprocess.run(cmd, shell=True)
        time.sleep(1)


def main():
    if(ARGS.mode == 'Hist'):
        addHist()
    else:
        add()

if __name__ == "__main__":
    main()

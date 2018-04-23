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


def main():
    add()

if __name__ == "__main__":
    main()

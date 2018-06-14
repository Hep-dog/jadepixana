#!/opt/JadePixDAQ/dependencies/anaconda3/bin/python
import subprocess
import time
import argparse
import sys
import os

parser = argparse.ArgumentParser(description='JadePix Analysis')

Gain = [
    2.091,
    1.852,
    1.340,
    2.143,
    1.683,
    1.030,
    2.071,
    1.499,
    1.029
]

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

def genNoise():
    for i in range(ARGS.chip_number_start, ARGS.chip_number_end):
        cmd = "GenNoise -g " + str(Gain[i-1]) + " -i output/May_WeakFe_Tree_CHIPA" \
        + str(i) + ".root -o Noise_May_WeakFe_CHIPA"+ str(i)+ ".root"
        print(cmd)
        subprocess.run(cmd, shell=True)
        time.sleep(0.1)

if __name__ == "__main__":
    genNoise()

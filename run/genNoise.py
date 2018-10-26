#!/opt/JadePixDAQ/dependencies/anaconda3/bin/python
import subprocess
import time
import argparse
import sys
import os

parser = argparse.ArgumentParser(description='JadePix Analysis')

Old_Gain = [
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
GainA = [
    6.996341463,
    6.087195122,
    4.361585366,
    7.099390244,
    1,
    1,
    6.81402439,
]

GainB = [
    6.615243902,
    7.414634146,
    5.138414634,
    7.221341463,
    1,
    1,
    7.47804878,
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

parser.add_argument('--matrix',
                    action='store',
                    dest='matrix',
                    default="A",
                    type=str,
                    help='matrix')

ARGS = parser.parse_args()

def genNoise():
    for i in range(ARGS.chip_number_start, ARGS.chip_number_end):
        if(i==5 or i==6):
            continue
        if(ARGS.matrix=="A"):
            cmd = "GenNoise -g " + str(GainA[i-1]) + " -i output/WeakFe_CHIPA_NO5_A" \
                + str(i) + "_1.root -o Noise_WeakFe_CHIPA_NO5_A"+ str(i)+ ".root"
        elif(ARGS.matrix=="B"):
            cmd = "GenNoise -g " + str(GainB[i-1]) + " -i output/WeakFe_CHIPB_NO1_B" \
                + str(i) + "_1.root -o Noise_WeakFe_CHIPB_NO1_B"+ str(i)+ ".root"
        else:
            print("Check input")
            exit()

        print(cmd)
        subprocess.run(cmd, shell=True)
        time.sleep(0.1)

if __name__ == "__main__":
    genNoise()

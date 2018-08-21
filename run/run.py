#!/besfs/groups/higgs/users/chenlj/software/anaconda3/bin/python

import subprocess
import time
import argparse
import sys
import os
import distutils.util

parser = argparse.ArgumentParser(description='JadePix Analysis')
parser.add_argument('-s',
                    action='store',
                    dest='start',
                    default=1,
                    type=int,
                    help='start analysis file')

parser.add_argument('-e',
                    action='store',
                    dest='end',
                    default=2,
                    type=int,
                    help='end analysis file')

parser.add_argument('-c',
                    action='store',
                    dest='chip_number',
                    default=1,
                    type=int,
                    help='chip number')

parser.add_argument('-cs',
                    action='store',
                    dest='chip_start',
                    default=1,
                    type=int,
                    help='chip start number')

parser.add_argument('-ce',
                    action='store',
                    dest='chip_end',
                    default=1,
                    type=int,
                    help='chip end number')

parser.add_argument('-n',
                    action='store',
                    dest='source_name',
                    default=1,
                    type=str,
                    help='source_name')

parser.add_argument('--debug',
                    action='store',
                    dest='debug_mode',
                    default='false',
                    type=distutils.util.strtobool,
                    help='debug mode')

ARGS = parser.parse_args()

def job_text(i,chip_number):
    try:
        JADEPIXANA_DIR = os.environ["JADEPIXANA_DIR"]
        JADEPIXANA_ENV_SHELL = os.environ["JADEPIXANA_ENV_SHELL"]
    except KeyError:
        print("Please set the environment variable JADEPIXANA_DIR \
              JADEPIXANA_ENV_SHELL")
        sys.exit(1)

    text ='''
#!/bin/bash

cd {0}/run
source {0}/etc/{1}
RunTest -c config/{2}_A{3}_run{4}.json
'''.format(JADEPIXANA_DIR, JADEPIXANA_ENV_SHELL, \
           ARGS.source_name,str(chip_number), str(i).zfill(5))

    return text

def gen_job(i,chip_number):
    job_file_name = "script/"+ARGS.source_name+"_A" + str(chip_number) \
        + "_job_" + str(i) + ".sh"
    job_file = open(job_file_name,"w")
    job_file.write(job_text(i,chip_number))
    job_file.close()
    subprocess.call("chmod u+x " + job_file_name, shell=True)

    return job_file_name

def sub_job(i, chip_number, job_file):
    job_cmd = "hep_sub -g atlas -mem 4000 -o /scratchfs/atlas/chenlj/jadepix/log/" \
        + ARGS.source_name+"_A" \
        + str(chip_number) +"_run" + str(i).zfill(5) \
        + ".log -e  /scratchfs/atlas/chenlj/jadepix/log/" \
        + ARGS.source_name+"_A" \
        + str(chip_number) + "_err" + str(i).zfill(5) + ".log " + job_file

    print(job_cmd)
    if(not ARGS.debug_mode):
        subprocess.call(job_cmd, shell=True)

def run_chip_sub_job():
    for chip in range(ARGS.chip_start, ARGS.chip_end):
        for i in range(ARGS.start, ARGS.end):
            print("================== start >>>>>>>>>>\n")
            job_file = gen_job(i,chip)
            sub_job(i, chip, job_file)
            time.sleep(1)
            print("\n<<<<<<<<<<<<<<<<<< end ==============\n\n")

def run_sub_job():
    for i in range(ARGS.start, ARGS.end):
        print("================== start >>>>>>>>>>\n")
        job_file = gen_job(i,ARGS.chip_number)
        sub_job(i, ARGS.chip_number, job_file)
        time.sleep(1)
        print("\n<<<<<<<<<<<<<<<<<< end ==============\n\n")

def main():
    if(ARGS.source_name == "Noise"):
        run_chip_sub_job()
    else:
        run_sub_job()

if __name__ == "__main__":
    main()

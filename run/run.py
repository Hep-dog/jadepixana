#!/besfs/groups/higgs/users/chenlj/software/anaconda3/bin/python

import subprocess
import time
import argparse
import sys

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

ARGS = parser.parse_args()

def main():
    for i in range(ARGS.start, ARGS.end):

      print("================== start >>>>>>>>>>\n")

      job_file = "script/CHIPA" + str(ARGS.chip_number) + "_job_" + str(i) + ".sh"

      copy_cmd = "cp job.sh " + job_file

      subprocess.call(copy_cmd, shell=True)

      cmd = "sed -n 5p " + job_file

      str_cmd = str(subprocess.check_output(cmd, shell=True),'utf-8')

      run_num = str_cmd.split()[-1].split("/")[-1].split(".")[-2]

      rep_cmd = "sed -i 5s/" + run_num + "/CHIPA" + str(ARGS.chip_number) + "_run" + str(i).zfill(5) + "/g " + job_file

      subprocess.call(rep_cmd, shell=True)

      print(str(subprocess.check_output(cmd, shell=True),'utf-8'))

      run_cmd = "hep_sub -g atlas -o log/CHIPA"+ str(ARGS.chip_number) +"_run" + str(i).zfill(5) \
          + ".log -e log/CHIPA" + str(ARGS.chip_number) + "_err" + str(i).zfill(5) + ".log " + job_file

      print(run_cmd)
      subprocess.call(run_cmd, shell=True)
      time.sleep(1)

      print("\n<<<<<<<<<<<<<<<<<< end ==============\n\n")


if __name__ == "__main__":
    main()

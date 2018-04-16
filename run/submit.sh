#!/usr/bin/env bash

# Main driver to submit 
# Author: 
#      Chen Liejian <chenlj@ihep.ac.cn> 
# Created [2018-04-10 Tue 18:00]


usage() {
    printf "NAME\n\tsubmit.sh - Main driver to submit\n"
    printf "\nSYNOPSIS\n"
    printf "\n\t%-5s\n" "./submit.sh [OPTION]"
    printf "\nOPTIONS\n"
    printf "\n\t%-9s  %-40s"  "0.1"      "[Run JadePix Analysis]" 
    printf "\n\t%-9s  %-40s"  "0.1.1"    "Run Weak Fe ana" 
}


if [[ $# -eq 0 ]]; then
    usage
    printf "\nPlease enter your option: "
    read option
else
    option=$1
fi

case $option in

    # --------------------------------------------------------------------------
    #  0.1 allpix-squared (v1.1.0)
    # --------------------------------------------------------------------------

    0.1) echo "Simulating jadepix1..."
         ;;
    0.1.1) echo "Running jadepix1 conf files..."
      python run.py 
      ;;

esac

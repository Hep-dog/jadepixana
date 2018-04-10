#!/bin/bash
#PBS -N jadepixAna
#PBS -q atlass6q
#PBS -e /scratchfs/atlas/chenlj/error.log
#PBS -o /scratchfs/atlas/chenlj/run.log

cd /besfs/groups/higgs/users/chenlj/jadepixana/run
source ../etc/lxplus_setup.sh
./submit.sh 0.1.1

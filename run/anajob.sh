#!/bin/bash

cd /besfs/groups/higgs/users/chenlj/jadepixana/run
source ../etc/lxplus_setup.sh
./ana.py --cs=4 --ce=8 --mode=TREE

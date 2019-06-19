#export CXX=/usr/bin/g++
#export CC=/usr/bin/gcc

source /home/jiyizi/Software/root/build/bin/thisroot.sh
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib

export PATH=/home/jiyizi/Software/anaconda3/bin:$PATH

export PATH=$PATH:/home/jiyizi/Software/jadepixana/bin
export JADEPIXANA_DIR=/home/jiyizi/Software/jadepixana
export JADEPIXANA_ENV_SHELL=local_setup.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/jiyizi/Software/jadepixana/lib

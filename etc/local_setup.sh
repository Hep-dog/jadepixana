export CXX=/usr/bin/g++
export CC=/usr/bin/gcc

source /usr/local/bin/thisroot.sh
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib

export PATH=$PATH:${HOME}/Documents/Code/jadepixana/bin
export JADEPIXANA_DIR=${HOME}/Documents/Code/jadepixana
export JADEPIXANA_ENV_SHELL=local_setup.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${HOME}/Documents/Code/jadepixana/lib

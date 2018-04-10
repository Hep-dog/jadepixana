export CXX=/usr/bin/g++
export CC=/usr/bin/gcc

source /opt/allpix/root/install/bin/thisroot.sh
export PATH=$ROOTSYS/bin:$PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib

export PATH=$PATH:${HOME}/jadepixana/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${HOME}/jadepixana/lib

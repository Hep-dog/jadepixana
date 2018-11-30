source /besfs/groups/higgs/users/chenlj/software/build_env.sh
export PATH=/besfs/groups/higgs/users/chenlj/jadepixana/bin:$PATH
export PATH=/afs/ihep.ac.cn/soft/common/sysgroup/hep_job/bin:$PATH

export JADEPIXANA_DIR=/besfs/groups/higgs/users/chenlj/jadepixana
export JADEPIXANA_ENV_SHELL=lxplus_setup.sh

#ROOT6
export PATH=/besfs/groups/higgs/users/chenlj/software/root/install/bin:$PATH
export LD_LIBRARY_PATH=/besfs/groups/higgs/users/chenlj/software/root/install/lib:$LD_LIBRARY_PATH


#source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Gcc/gcc484_x86_64_slc6/setup.sh
#source /cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/root/6.06.02-x86_64-slc6-gcc48-opt/bin/thisroot.sh
export CC=/opt/rh/devtoolset-4/root/usr/bin/gcc
export CXX=/opt/rh/devtoolset-4/root/usr/bin/g++
#export CC=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Gcc/gcc484_x86_64_slc6/slc6/gcc48/bin/gcc
#export CXX=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase/x86_64/Gcc/gcc484_x86_64_slc6/slc6/gcc48/bin/g++

#export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
#alias setupATLAS='source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh'

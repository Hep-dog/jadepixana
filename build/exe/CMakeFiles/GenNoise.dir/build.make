# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jiyizi/Software/jadepixana

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jiyizi/Software/jadepixana/build

# Include any dependencies generated for this target.
include exe/CMakeFiles/GenNoise.dir/depend.make

# Include the progress variables for this target.
include exe/CMakeFiles/GenNoise.dir/progress.make

# Include the compile flags for this target's objects.
include exe/CMakeFiles/GenNoise.dir/flags.make

exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o: exe/CMakeFiles/GenNoise.dir/flags.make
exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o: ../exe/src/GenNoise.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jiyizi/Software/jadepixana/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o"
	cd /home/jiyizi/Software/jadepixana/build/exe && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o -c /home/jiyizi/Software/jadepixana/exe/src/GenNoise.cxx

exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GenNoise.dir/src/GenNoise.cxx.i"
	cd /home/jiyizi/Software/jadepixana/build/exe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jiyizi/Software/jadepixana/exe/src/GenNoise.cxx > CMakeFiles/GenNoise.dir/src/GenNoise.cxx.i

exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GenNoise.dir/src/GenNoise.cxx.s"
	cd /home/jiyizi/Software/jadepixana/build/exe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jiyizi/Software/jadepixana/exe/src/GenNoise.cxx -o CMakeFiles/GenNoise.dir/src/GenNoise.cxx.s

exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o.requires:

.PHONY : exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o.requires

exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o.provides: exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o.requires
	$(MAKE) -f exe/CMakeFiles/GenNoise.dir/build.make exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o.provides.build
.PHONY : exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o.provides

exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o.provides.build: exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o


# Object files for target GenNoise
GenNoise_OBJECTS = \
"CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o"

# External object files for target GenNoise
GenNoise_EXTERNAL_OBJECTS =

exe/GenNoise: exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o
exe/GenNoise: exe/CMakeFiles/GenNoise.dir/build.make
exe/GenNoise: core/libjadecore.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libCore.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libImt.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libRIO.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libNet.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libHist.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libGraf.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libGraf3d.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libGpad.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libROOTDataFrame.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libTree.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libTreePlayer.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libRint.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libPostscript.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libMatrix.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libPhysics.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libMathCore.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libThread.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libMultiProc.so
exe/GenNoise: /home/jiyizi/Software/root/build/lib/libSpectrum.so
exe/GenNoise: exe/CMakeFiles/GenNoise.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jiyizi/Software/jadepixana/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GenNoise"
	cd /home/jiyizi/Software/jadepixana/build/exe && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GenNoise.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
exe/CMakeFiles/GenNoise.dir/build: exe/GenNoise

.PHONY : exe/CMakeFiles/GenNoise.dir/build

exe/CMakeFiles/GenNoise.dir/requires: exe/CMakeFiles/GenNoise.dir/src/GenNoise.cxx.o.requires

.PHONY : exe/CMakeFiles/GenNoise.dir/requires

exe/CMakeFiles/GenNoise.dir/clean:
	cd /home/jiyizi/Software/jadepixana/build/exe && $(CMAKE_COMMAND) -P CMakeFiles/GenNoise.dir/cmake_clean.cmake
.PHONY : exe/CMakeFiles/GenNoise.dir/clean

exe/CMakeFiles/GenNoise.dir/depend:
	cd /home/jiyizi/Software/jadepixana/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jiyizi/Software/jadepixana /home/jiyizi/Software/jadepixana/exe /home/jiyizi/Software/jadepixana/build /home/jiyizi/Software/jadepixana/build/exe /home/jiyizi/Software/jadepixana/build/exe/CMakeFiles/GenNoise.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : exe/CMakeFiles/GenNoise.dir/depend


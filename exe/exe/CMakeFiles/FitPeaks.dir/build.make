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
CMAKE_BINARY_DIR = /home/jiyizi/Software/jadepixana/exe

# Include any dependencies generated for this target.
include exe/CMakeFiles/FitPeaks.dir/depend.make

# Include the progress variables for this target.
include exe/CMakeFiles/FitPeaks.dir/progress.make

# Include the compile flags for this target's objects.
include exe/CMakeFiles/FitPeaks.dir/flags.make

exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o: exe/CMakeFiles/FitPeaks.dir/flags.make
exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o: src/FitPeaks.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jiyizi/Software/jadepixana/exe/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o"
	cd /home/jiyizi/Software/jadepixana/exe/exe && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o -c /home/jiyizi/Software/jadepixana/exe/src/FitPeaks.cxx

exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.i"
	cd /home/jiyizi/Software/jadepixana/exe/exe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jiyizi/Software/jadepixana/exe/src/FitPeaks.cxx > CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.i

exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.s"
	cd /home/jiyizi/Software/jadepixana/exe/exe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jiyizi/Software/jadepixana/exe/src/FitPeaks.cxx -o CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.s

exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o.requires:

.PHONY : exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o.requires

exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o.provides: exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o.requires
	$(MAKE) -f exe/CMakeFiles/FitPeaks.dir/build.make exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o.provides.build
.PHONY : exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o.provides

exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o.provides.build: exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o


# Object files for target FitPeaks
FitPeaks_OBJECTS = \
"CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o"

# External object files for target FitPeaks
FitPeaks_EXTERNAL_OBJECTS =

exe/FitPeaks: exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o
exe/FitPeaks: exe/CMakeFiles/FitPeaks.dir/build.make
exe/FitPeaks: exe/CMakeFiles/FitPeaks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jiyizi/Software/jadepixana/exe/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FitPeaks"
	cd /home/jiyizi/Software/jadepixana/exe/exe && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FitPeaks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
exe/CMakeFiles/FitPeaks.dir/build: exe/FitPeaks

.PHONY : exe/CMakeFiles/FitPeaks.dir/build

exe/CMakeFiles/FitPeaks.dir/requires: exe/CMakeFiles/FitPeaks.dir/src/FitPeaks.cxx.o.requires

.PHONY : exe/CMakeFiles/FitPeaks.dir/requires

exe/CMakeFiles/FitPeaks.dir/clean:
	cd /home/jiyizi/Software/jadepixana/exe/exe && $(CMAKE_COMMAND) -P CMakeFiles/FitPeaks.dir/cmake_clean.cmake
.PHONY : exe/CMakeFiles/FitPeaks.dir/clean

exe/CMakeFiles/FitPeaks.dir/depend:
	cd /home/jiyizi/Software/jadepixana/exe && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jiyizi/Software/jadepixana /home/jiyizi/Software/jadepixana/exe /home/jiyizi/Software/jadepixana/exe /home/jiyizi/Software/jadepixana/exe/exe /home/jiyizi/Software/jadepixana/exe/exe/CMakeFiles/FitPeaks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : exe/CMakeFiles/FitPeaks.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010

# Include any dependencies generated for this target.
include soco2010/CMakeFiles/shifted_griewank.dir/depend.make

# Include the progress variables for this target.
include soco2010/CMakeFiles/shifted_griewank.dir/progress.make

# Include the compile flags for this target's objects.
include soco2010/CMakeFiles/shifted_griewank.dir/flags.make

soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o: soco2010/CMakeFiles/shifted_griewank.dir/flags.make
soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o: soco2010/shifted_griewank.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o"
	cd /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010 && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o -c /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010/shifted_griewank.cc

soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.i"
	cd /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010 && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010/shifted_griewank.cc > CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.i

soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.s"
	cd /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010 && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010/shifted_griewank.cc -o CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.s

soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o.requires:

.PHONY : soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o.requires

soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o.provides: soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o.requires
	$(MAKE) -f soco2010/CMakeFiles/shifted_griewank.dir/build.make soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o.provides.build
.PHONY : soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o.provides

soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o.provides.build: soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o


# Object files for target shifted_griewank
shifted_griewank_OBJECTS = \
"CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o"

# External object files for target shifted_griewank
shifted_griewank_EXTERNAL_OBJECTS =

soco2010/libshifted_griewank.so: soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o
soco2010/libshifted_griewank.so: soco2010/CMakeFiles/shifted_griewank.dir/build.make
soco2010/libshifted_griewank.so: soco2010/CMakeFiles/shifted_griewank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libshifted_griewank.so"
	cd /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shifted_griewank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
soco2010/CMakeFiles/shifted_griewank.dir/build: soco2010/libshifted_griewank.so

.PHONY : soco2010/CMakeFiles/shifted_griewank.dir/build

soco2010/CMakeFiles/shifted_griewank.dir/requires: soco2010/CMakeFiles/shifted_griewank.dir/shifted_griewank.cc.o.requires

.PHONY : soco2010/CMakeFiles/shifted_griewank.dir/requires

soco2010/CMakeFiles/shifted_griewank.dir/clean:
	cd /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010 && $(CMAKE_COMMAND) -P CMakeFiles/shifted_griewank.dir/cmake_clean.cmake
.PHONY : soco2010/CMakeFiles/shifted_griewank.dir/clean

soco2010/CMakeFiles/shifted_griewank.dir/depend:
	cd /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010 /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010 /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010 /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010 /Users/Arthur18/Documents/UGR-GII/4toCurso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/soco2010/CMakeFiles/shifted_griewank.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : soco2010/CMakeFiles/shifted_griewank.dir/depend


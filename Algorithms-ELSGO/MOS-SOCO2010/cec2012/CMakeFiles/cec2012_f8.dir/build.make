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
CMAKE_SOURCE_DIR = "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010"

# Include any dependencies generated for this target.
include cec2012/CMakeFiles/cec2012_f8.dir/depend.make

# Include the progress variables for this target.
include cec2012/CMakeFiles/cec2012_f8.dir/progress.make

# Include the compile flags for this target's objects.
include cec2012/CMakeFiles/cec2012_f8.dir/flags.make

cec2012/f8.cc: cec2012/template.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Creating f8.cc file"
	cd "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012" && sed s/XXX/8/g /Users/Arthur18/Documents/UGR-GII/4to\ Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012/template.cc > f8.cc

cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o: cec2012/CMakeFiles/cec2012_f8.dir/flags.make
cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o: cec2012/f8.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o"
	cd "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012" && /Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cec2012_f8.dir/f8.cc.o -c "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012/f8.cc"

cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cec2012_f8.dir/f8.cc.i"
	cd "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012/f8.cc" > CMakeFiles/cec2012_f8.dir/f8.cc.i

cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cec2012_f8.dir/f8.cc.s"
	cd "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012/f8.cc" -o CMakeFiles/cec2012_f8.dir/f8.cc.s

cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o.requires:

.PHONY : cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o.requires

cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o.provides: cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o.requires
	$(MAKE) -f cec2012/CMakeFiles/cec2012_f8.dir/build.make cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o.provides.build
.PHONY : cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o.provides

cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o.provides.build: cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o


# Object files for target cec2012_f8
cec2012_f8_OBJECTS = \
"CMakeFiles/cec2012_f8.dir/f8.cc.o"

# External object files for target cec2012_f8
cec2012_f8_EXTERNAL_OBJECTS =

cec2012/libcec2012_f8.so: cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o
cec2012/libcec2012_f8.so: cec2012/CMakeFiles/cec2012_f8.dir/build.make
cec2012/libcec2012_f8.so: gaeda/libgaeda.so
cec2012/libcec2012_f8.so: cec2012/CMakeFiles/cec2012_f8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library libcec2012_f8.so"
	cd "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cec2012_f8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cec2012/CMakeFiles/cec2012_f8.dir/build: cec2012/libcec2012_f8.so

.PHONY : cec2012/CMakeFiles/cec2012_f8.dir/build

cec2012/CMakeFiles/cec2012_f8.dir/requires: cec2012/CMakeFiles/cec2012_f8.dir/f8.cc.o.requires

.PHONY : cec2012/CMakeFiles/cec2012_f8.dir/requires

cec2012/CMakeFiles/cec2012_f8.dir/clean:
	cd "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012" && $(CMAKE_COMMAND) -P CMakeFiles/cec2012_f8.dir/cmake_clean.cmake
.PHONY : cec2012/CMakeFiles/cec2012_f8.dir/clean

cec2012/CMakeFiles/cec2012_f8.dir/depend: cec2012/f8.cc
	cd "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010" "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012" "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010" "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012" "/Users/Arthur18/Documents/UGR-GII/4to Curso/TFG-AdvancedMetaheuristicsForBigOpt/UGR-GII-TFG/Algorithms-ELSGO/MOS-SOCO2010/cec2012/CMakeFiles/cec2012_f8.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : cec2012/CMakeFiles/cec2012_f8.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/tdt/TA/project2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tdt/TA/project2/build

# Include any dependencies generated for this target.
include src/CMakeFiles/libalu.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/libalu.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/libalu.dir/flags.make

src/CMakeFiles/libalu.dir/alu.o: src/CMakeFiles/libalu.dir/flags.make
src/CMakeFiles/libalu.dir/alu.o: ../src/alu.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tdt/TA/project2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/CMakeFiles/libalu.dir/alu.o"
	cd /home/tdt/TA/project2/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libalu.dir/alu.o -c /home/tdt/TA/project2/src/alu.cpp

src/CMakeFiles/libalu.dir/alu.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libalu.dir/alu.i"
	cd /home/tdt/TA/project2/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tdt/TA/project2/src/alu.cpp > CMakeFiles/libalu.dir/alu.i

src/CMakeFiles/libalu.dir/alu.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libalu.dir/alu.s"
	cd /home/tdt/TA/project2/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tdt/TA/project2/src/alu.cpp -o CMakeFiles/libalu.dir/alu.s

src/CMakeFiles/libalu.dir/alu.o.requires:
.PHONY : src/CMakeFiles/libalu.dir/alu.o.requires

src/CMakeFiles/libalu.dir/alu.o.provides: src/CMakeFiles/libalu.dir/alu.o.requires
	$(MAKE) -f src/CMakeFiles/libalu.dir/build.make src/CMakeFiles/libalu.dir/alu.o.provides.build
.PHONY : src/CMakeFiles/libalu.dir/alu.o.provides

src/CMakeFiles/libalu.dir/alu.o.provides.build: src/CMakeFiles/libalu.dir/alu.o

# Object files for target libalu
libalu_OBJECTS = \
"CMakeFiles/libalu.dir/alu.o"

# External object files for target libalu
libalu_EXTERNAL_OBJECTS =

src/liblibalu.a: src/CMakeFiles/libalu.dir/alu.o
src/liblibalu.a: src/CMakeFiles/libalu.dir/build.make
src/liblibalu.a: src/CMakeFiles/libalu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library liblibalu.a"
	cd /home/tdt/TA/project2/build/src && $(CMAKE_COMMAND) -P CMakeFiles/libalu.dir/cmake_clean_target.cmake
	cd /home/tdt/TA/project2/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libalu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/libalu.dir/build: src/liblibalu.a
.PHONY : src/CMakeFiles/libalu.dir/build

src/CMakeFiles/libalu.dir/requires: src/CMakeFiles/libalu.dir/alu.o.requires
.PHONY : src/CMakeFiles/libalu.dir/requires

src/CMakeFiles/libalu.dir/clean:
	cd /home/tdt/TA/project2/build/src && $(CMAKE_COMMAND) -P CMakeFiles/libalu.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/libalu.dir/clean

src/CMakeFiles/libalu.dir/depend:
	cd /home/tdt/TA/project2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tdt/TA/project2 /home/tdt/TA/project2/src /home/tdt/TA/project2/build /home/tdt/TA/project2/build/src /home/tdt/TA/project2/build/src/CMakeFiles/libalu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/libalu.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/seminar_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/seminar_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/seminar_3.dir/flags.make

CMakeFiles/seminar_3.dir/pair_tuple.cpp.o: CMakeFiles/seminar_3.dir/flags.make
CMakeFiles/seminar_3.dir/pair_tuple.cpp.o: ../pair_tuple.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/seminar_3.dir/pair_tuple.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/seminar_3.dir/pair_tuple.cpp.o -c /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/pair_tuple.cpp

CMakeFiles/seminar_3.dir/pair_tuple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seminar_3.dir/pair_tuple.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/pair_tuple.cpp > CMakeFiles/seminar_3.dir/pair_tuple.cpp.i

CMakeFiles/seminar_3.dir/pair_tuple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seminar_3.dir/pair_tuple.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/pair_tuple.cpp -o CMakeFiles/seminar_3.dir/pair_tuple.cpp.s

# Object files for target seminar_3
seminar_3_OBJECTS = \
"CMakeFiles/seminar_3.dir/pair_tuple.cpp.o"

# External object files for target seminar_3
seminar_3_EXTERNAL_OBJECTS =

seminar_3: CMakeFiles/seminar_3.dir/pair_tuple.cpp.o
seminar_3: CMakeFiles/seminar_3.dir/build.make
seminar_3: CMakeFiles/seminar_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable seminar_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/seminar_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/seminar_3.dir/build: seminar_3

.PHONY : CMakeFiles/seminar_3.dir/build

CMakeFiles/seminar_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/seminar_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/seminar_3.dir/clean

CMakeFiles/seminar_3.dir/depend:
	cd /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3 /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3 /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/cmake-build-debug /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/cmake-build-debug /Users/dlefimov/Documents/OIMP_seminars_cpp/196/seminar3/cmake-build-debug/CMakeFiles/seminar_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/seminar_3.dir/depend


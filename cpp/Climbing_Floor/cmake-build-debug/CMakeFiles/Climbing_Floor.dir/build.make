# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /Users/sokiwar/CLionProjects/Climbing_Floor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sokiwar/CLionProjects/Climbing_Floor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Climbing_Floor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Climbing_Floor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Climbing_Floor.dir/flags.make

CMakeFiles/Climbing_Floor.dir/main.cpp.o: CMakeFiles/Climbing_Floor.dir/flags.make
CMakeFiles/Climbing_Floor.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sokiwar/CLionProjects/Climbing_Floor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Climbing_Floor.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Climbing_Floor.dir/main.cpp.o -c /Users/sokiwar/CLionProjects/Climbing_Floor/main.cpp

CMakeFiles/Climbing_Floor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Climbing_Floor.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sokiwar/CLionProjects/Climbing_Floor/main.cpp > CMakeFiles/Climbing_Floor.dir/main.cpp.i

CMakeFiles/Climbing_Floor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Climbing_Floor.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sokiwar/CLionProjects/Climbing_Floor/main.cpp -o CMakeFiles/Climbing_Floor.dir/main.cpp.s

# Object files for target Climbing_Floor
Climbing_Floor_OBJECTS = \
"CMakeFiles/Climbing_Floor.dir/main.cpp.o"

# External object files for target Climbing_Floor
Climbing_Floor_EXTERNAL_OBJECTS =

Climbing_Floor: CMakeFiles/Climbing_Floor.dir/main.cpp.o
Climbing_Floor: CMakeFiles/Climbing_Floor.dir/build.make
Climbing_Floor: CMakeFiles/Climbing_Floor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sokiwar/CLionProjects/Climbing_Floor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Climbing_Floor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Climbing_Floor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Climbing_Floor.dir/build: Climbing_Floor

.PHONY : CMakeFiles/Climbing_Floor.dir/build

CMakeFiles/Climbing_Floor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Climbing_Floor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Climbing_Floor.dir/clean

CMakeFiles/Climbing_Floor.dir/depend:
	cd /Users/sokiwar/CLionProjects/Climbing_Floor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sokiwar/CLionProjects/Climbing_Floor /Users/sokiwar/CLionProjects/Climbing_Floor /Users/sokiwar/CLionProjects/Climbing_Floor/cmake-build-debug /Users/sokiwar/CLionProjects/Climbing_Floor/cmake-build-debug /Users/sokiwar/CLionProjects/Climbing_Floor/cmake-build-debug/CMakeFiles/Climbing_Floor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Climbing_Floor.dir/depend


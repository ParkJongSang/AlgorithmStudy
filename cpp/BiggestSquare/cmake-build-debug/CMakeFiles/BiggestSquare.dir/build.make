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
CMAKE_SOURCE_DIR = /Users/sokiwar/CLionProjects/BiggestSquare

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sokiwar/CLionProjects/BiggestSquare/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BiggestSquare.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BiggestSquare.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BiggestSquare.dir/flags.make

CMakeFiles/BiggestSquare.dir/main.cpp.o: CMakeFiles/BiggestSquare.dir/flags.make
CMakeFiles/BiggestSquare.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sokiwar/CLionProjects/BiggestSquare/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BiggestSquare.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BiggestSquare.dir/main.cpp.o -c /Users/sokiwar/CLionProjects/BiggestSquare/main.cpp

CMakeFiles/BiggestSquare.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BiggestSquare.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sokiwar/CLionProjects/BiggestSquare/main.cpp > CMakeFiles/BiggestSquare.dir/main.cpp.i

CMakeFiles/BiggestSquare.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BiggestSquare.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sokiwar/CLionProjects/BiggestSquare/main.cpp -o CMakeFiles/BiggestSquare.dir/main.cpp.s

# Object files for target BiggestSquare
BiggestSquare_OBJECTS = \
"CMakeFiles/BiggestSquare.dir/main.cpp.o"

# External object files for target BiggestSquare
BiggestSquare_EXTERNAL_OBJECTS =

BiggestSquare: CMakeFiles/BiggestSquare.dir/main.cpp.o
BiggestSquare: CMakeFiles/BiggestSquare.dir/build.make
BiggestSquare: CMakeFiles/BiggestSquare.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sokiwar/CLionProjects/BiggestSquare/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BiggestSquare"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BiggestSquare.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BiggestSquare.dir/build: BiggestSquare

.PHONY : CMakeFiles/BiggestSquare.dir/build

CMakeFiles/BiggestSquare.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BiggestSquare.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BiggestSquare.dir/clean

CMakeFiles/BiggestSquare.dir/depend:
	cd /Users/sokiwar/CLionProjects/BiggestSquare/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sokiwar/CLionProjects/BiggestSquare /Users/sokiwar/CLionProjects/BiggestSquare /Users/sokiwar/CLionProjects/BiggestSquare/cmake-build-debug /Users/sokiwar/CLionProjects/BiggestSquare/cmake-build-debug /Users/sokiwar/CLionProjects/BiggestSquare/cmake-build-debug/CMakeFiles/BiggestSquare.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BiggestSquare.dir/depend


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
CMAKE_SOURCE_DIR = /Users/sokiwar/CLionProjects/PrintStar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sokiwar/CLionProjects/PrintStar/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PrintStar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PrintStar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PrintStar.dir/flags.make

CMakeFiles/PrintStar.dir/main.cpp.o: CMakeFiles/PrintStar.dir/flags.make
CMakeFiles/PrintStar.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sokiwar/CLionProjects/PrintStar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PrintStar.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PrintStar.dir/main.cpp.o -c /Users/sokiwar/CLionProjects/PrintStar/main.cpp

CMakeFiles/PrintStar.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PrintStar.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sokiwar/CLionProjects/PrintStar/main.cpp > CMakeFiles/PrintStar.dir/main.cpp.i

CMakeFiles/PrintStar.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PrintStar.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sokiwar/CLionProjects/PrintStar/main.cpp -o CMakeFiles/PrintStar.dir/main.cpp.s

# Object files for target PrintStar
PrintStar_OBJECTS = \
"CMakeFiles/PrintStar.dir/main.cpp.o"

# External object files for target PrintStar
PrintStar_EXTERNAL_OBJECTS =

PrintStar: CMakeFiles/PrintStar.dir/main.cpp.o
PrintStar: CMakeFiles/PrintStar.dir/build.make
PrintStar: CMakeFiles/PrintStar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sokiwar/CLionProjects/PrintStar/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PrintStar"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PrintStar.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PrintStar.dir/build: PrintStar

.PHONY : CMakeFiles/PrintStar.dir/build

CMakeFiles/PrintStar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PrintStar.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PrintStar.dir/clean

CMakeFiles/PrintStar.dir/depend:
	cd /Users/sokiwar/CLionProjects/PrintStar/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sokiwar/CLionProjects/PrintStar /Users/sokiwar/CLionProjects/PrintStar /Users/sokiwar/CLionProjects/PrintStar/cmake-build-debug /Users/sokiwar/CLionProjects/PrintStar/cmake-build-debug /Users/sokiwar/CLionProjects/PrintStar/cmake-build-debug/CMakeFiles/PrintStar.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PrintStar.dir/depend


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
CMAKE_SOURCE_DIR = /Users/sokiwar/CLionProjects/Gear

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sokiwar/CLionProjects/Gear/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Gear.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Gear.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Gear.dir/flags.make

CMakeFiles/Gear.dir/main.cpp.o: CMakeFiles/Gear.dir/flags.make
CMakeFiles/Gear.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sokiwar/CLionProjects/Gear/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Gear.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Gear.dir/main.cpp.o -c /Users/sokiwar/CLionProjects/Gear/main.cpp

CMakeFiles/Gear.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gear.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sokiwar/CLionProjects/Gear/main.cpp > CMakeFiles/Gear.dir/main.cpp.i

CMakeFiles/Gear.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gear.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sokiwar/CLionProjects/Gear/main.cpp -o CMakeFiles/Gear.dir/main.cpp.s

# Object files for target Gear
Gear_OBJECTS = \
"CMakeFiles/Gear.dir/main.cpp.o"

# External object files for target Gear
Gear_EXTERNAL_OBJECTS =

Gear: CMakeFiles/Gear.dir/main.cpp.o
Gear: CMakeFiles/Gear.dir/build.make
Gear: CMakeFiles/Gear.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sokiwar/CLionProjects/Gear/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Gear"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Gear.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Gear.dir/build: Gear

.PHONY : CMakeFiles/Gear.dir/build

CMakeFiles/Gear.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Gear.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Gear.dir/clean

CMakeFiles/Gear.dir/depend:
	cd /Users/sokiwar/CLionProjects/Gear/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sokiwar/CLionProjects/Gear /Users/sokiwar/CLionProjects/Gear /Users/sokiwar/CLionProjects/Gear/cmake-build-debug /Users/sokiwar/CLionProjects/Gear/cmake-build-debug /Users/sokiwar/CLionProjects/Gear/cmake-build-debug/CMakeFiles/Gear.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Gear.dir/depend


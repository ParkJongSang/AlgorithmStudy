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
CMAKE_SOURCE_DIR = /Users/sokiwar/CLionProjects/StickerScore

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sokiwar/CLionProjects/StickerScore/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/StickerScore.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StickerScore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StickerScore.dir/flags.make

CMakeFiles/StickerScore.dir/main.cpp.o: CMakeFiles/StickerScore.dir/flags.make
CMakeFiles/StickerScore.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sokiwar/CLionProjects/StickerScore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StickerScore.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StickerScore.dir/main.cpp.o -c /Users/sokiwar/CLionProjects/StickerScore/main.cpp

CMakeFiles/StickerScore.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StickerScore.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sokiwar/CLionProjects/StickerScore/main.cpp > CMakeFiles/StickerScore.dir/main.cpp.i

CMakeFiles/StickerScore.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StickerScore.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sokiwar/CLionProjects/StickerScore/main.cpp -o CMakeFiles/StickerScore.dir/main.cpp.s

# Object files for target StickerScore
StickerScore_OBJECTS = \
"CMakeFiles/StickerScore.dir/main.cpp.o"

# External object files for target StickerScore
StickerScore_EXTERNAL_OBJECTS =

StickerScore: CMakeFiles/StickerScore.dir/main.cpp.o
StickerScore: CMakeFiles/StickerScore.dir/build.make
StickerScore: CMakeFiles/StickerScore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sokiwar/CLionProjects/StickerScore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StickerScore"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StickerScore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StickerScore.dir/build: StickerScore

.PHONY : CMakeFiles/StickerScore.dir/build

CMakeFiles/StickerScore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StickerScore.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StickerScore.dir/clean

CMakeFiles/StickerScore.dir/depend:
	cd /Users/sokiwar/CLionProjects/StickerScore/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sokiwar/CLionProjects/StickerScore /Users/sokiwar/CLionProjects/StickerScore /Users/sokiwar/CLionProjects/StickerScore/cmake-build-debug /Users/sokiwar/CLionProjects/StickerScore/cmake-build-debug /Users/sokiwar/CLionProjects/StickerScore/cmake-build-debug/CMakeFiles/StickerScore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/StickerScore.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/paulmauviel/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/paulmauviel/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5457.51/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/paulmauviel/mauville/gamejam01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/paulmauviel/mauville/gamejam01/cmake-build-debug

# Include any dependencies generated for this target.
include engine/external/SDL/CMakeFiles/SDL2main.dir/depend.make
# Include the progress variables for this target.
include engine/external/SDL/CMakeFiles/SDL2main.dir/progress.make

# Include the compile flags for this target's objects.
include engine/external/SDL/CMakeFiles/SDL2main.dir/flags.make

engine/external/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o: engine/external/SDL/CMakeFiles/SDL2main.dir/flags.make
engine/external/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o: ../engine/external/SDL/src/main/dummy/SDL_dummy_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object engine/external/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o"
	cd /Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o -c /Users/paulmauviel/mauville/gamejam01/engine/external/SDL/src/main/dummy/SDL_dummy_main.c

engine/external/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.i"
	cd /Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/paulmauviel/mauville/gamejam01/engine/external/SDL/src/main/dummy/SDL_dummy_main.c > CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.i

engine/external/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.s"
	cd /Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/paulmauviel/mauville/gamejam01/engine/external/SDL/src/main/dummy/SDL_dummy_main.c -o CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.s

# Object files for target SDL2main
SDL2main_OBJECTS = \
"CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o"

# External object files for target SDL2main
SDL2main_EXTERNAL_OBJECTS =

engine/external/SDL/libSDL2maind.a: engine/external/SDL/CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o
engine/external/SDL/libSDL2maind.a: engine/external/SDL/CMakeFiles/SDL2main.dir/build.make
engine/external/SDL/libSDL2maind.a: engine/external/SDL/CMakeFiles/SDL2main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/paulmauviel/mauville/gamejam01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libSDL2maind.a"
	cd /Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL && $(CMAKE_COMMAND) -P CMakeFiles/SDL2main.dir/cmake_clean_target.cmake
	cd /Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
engine/external/SDL/CMakeFiles/SDL2main.dir/build: engine/external/SDL/libSDL2maind.a
.PHONY : engine/external/SDL/CMakeFiles/SDL2main.dir/build

engine/external/SDL/CMakeFiles/SDL2main.dir/clean:
	cd /Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL && $(CMAKE_COMMAND) -P CMakeFiles/SDL2main.dir/cmake_clean.cmake
.PHONY : engine/external/SDL/CMakeFiles/SDL2main.dir/clean

engine/external/SDL/CMakeFiles/SDL2main.dir/depend:
	cd /Users/paulmauviel/mauville/gamejam01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/paulmauviel/mauville/gamejam01 /Users/paulmauviel/mauville/gamejam01/engine/external/SDL /Users/paulmauviel/mauville/gamejam01/cmake-build-debug /Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL /Users/paulmauviel/mauville/gamejam01/cmake-build-debug/engine/external/SDL/CMakeFiles/SDL2main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : engine/external/SDL/CMakeFiles/SDL2main.dir/depend


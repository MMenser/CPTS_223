# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/masonmenser/CPTS_223/MA3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/masonmenser/CPTS_223/MA3/build

# Include any dependencies generated for this target.
include CMakeFiles/MA3.exec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MA3.exec.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MA3.exec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MA3.exec.dir/flags.make

CMakeFiles/MA3.exec.dir/main.cpp.o: CMakeFiles/MA3.exec.dir/flags.make
CMakeFiles/MA3.exec.dir/main.cpp.o: ../main.cpp
CMakeFiles/MA3.exec.dir/main.cpp.o: CMakeFiles/MA3.exec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masonmenser/CPTS_223/MA3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MA3.exec.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MA3.exec.dir/main.cpp.o -MF CMakeFiles/MA3.exec.dir/main.cpp.o.d -o CMakeFiles/MA3.exec.dir/main.cpp.o -c /home/masonmenser/CPTS_223/MA3/main.cpp

CMakeFiles/MA3.exec.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MA3.exec.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masonmenser/CPTS_223/MA3/main.cpp > CMakeFiles/MA3.exec.dir/main.cpp.i

CMakeFiles/MA3.exec.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MA3.exec.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masonmenser/CPTS_223/MA3/main.cpp -o CMakeFiles/MA3.exec.dir/main.cpp.s

CMakeFiles/MA3.exec.dir/TwitterData.cpp.o: CMakeFiles/MA3.exec.dir/flags.make
CMakeFiles/MA3.exec.dir/TwitterData.cpp.o: ../TwitterData.cpp
CMakeFiles/MA3.exec.dir/TwitterData.cpp.o: CMakeFiles/MA3.exec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masonmenser/CPTS_223/MA3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MA3.exec.dir/TwitterData.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MA3.exec.dir/TwitterData.cpp.o -MF CMakeFiles/MA3.exec.dir/TwitterData.cpp.o.d -o CMakeFiles/MA3.exec.dir/TwitterData.cpp.o -c /home/masonmenser/CPTS_223/MA3/TwitterData.cpp

CMakeFiles/MA3.exec.dir/TwitterData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MA3.exec.dir/TwitterData.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masonmenser/CPTS_223/MA3/TwitterData.cpp > CMakeFiles/MA3.exec.dir/TwitterData.cpp.i

CMakeFiles/MA3.exec.dir/TwitterData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MA3.exec.dir/TwitterData.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masonmenser/CPTS_223/MA3/TwitterData.cpp -o CMakeFiles/MA3.exec.dir/TwitterData.cpp.s

# Object files for target MA3.exec
MA3_exec_OBJECTS = \
"CMakeFiles/MA3.exec.dir/main.cpp.o" \
"CMakeFiles/MA3.exec.dir/TwitterData.cpp.o"

# External object files for target MA3.exec
MA3_exec_EXTERNAL_OBJECTS =

MA3.exec: CMakeFiles/MA3.exec.dir/main.cpp.o
MA3.exec: CMakeFiles/MA3.exec.dir/TwitterData.cpp.o
MA3.exec: CMakeFiles/MA3.exec.dir/build.make
MA3.exec: CMakeFiles/MA3.exec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/masonmenser/CPTS_223/MA3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MA3.exec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MA3.exec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MA3.exec.dir/build: MA3.exec
.PHONY : CMakeFiles/MA3.exec.dir/build

CMakeFiles/MA3.exec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MA3.exec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MA3.exec.dir/clean

CMakeFiles/MA3.exec.dir/depend:
	cd /home/masonmenser/CPTS_223/MA3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/masonmenser/CPTS_223/MA3 /home/masonmenser/CPTS_223/MA3 /home/masonmenser/CPTS_223/MA3/build /home/masonmenser/CPTS_223/MA3/build /home/masonmenser/CPTS_223/MA3/build/CMakeFiles/MA3.exec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MA3.exec.dir/depend


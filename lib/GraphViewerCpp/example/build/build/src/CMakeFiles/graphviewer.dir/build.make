# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /snap/cmake/834/bin/cmake

# The command to remove a file.
RM = /snap/cmake/834/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build

# Include any dependencies generated for this target.
include build/src/CMakeFiles/graphviewer.dir/depend.make

# Include the progress variables for this target.
include build/src/CMakeFiles/graphviewer.dir/progress.make

# Include the compile flags for this target's objects.
include build/src/CMakeFiles/graphviewer.dir/flags.make

build/src/CMakeFiles/graphviewer.dir/graphviewer.cpp.o: build/src/CMakeFiles/graphviewer.dir/flags.make
build/src/CMakeFiles/graphviewer.dir/graphviewer.cpp.o: ../../src/graphviewer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object build/src/CMakeFiles/graphviewer.dir/graphviewer.cpp.o"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphviewer.dir/graphviewer.cpp.o -c /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/graphviewer.cpp

build/src/CMakeFiles/graphviewer.dir/graphviewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphviewer.dir/graphviewer.cpp.i"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/graphviewer.cpp > CMakeFiles/graphviewer.dir/graphviewer.cpp.i

build/src/CMakeFiles/graphviewer.dir/graphviewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphviewer.dir/graphviewer.cpp.s"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/graphviewer.cpp -o CMakeFiles/graphviewer.dir/graphviewer.cpp.s

build/src/CMakeFiles/graphviewer.dir/node.cpp.o: build/src/CMakeFiles/graphviewer.dir/flags.make
build/src/CMakeFiles/graphviewer.dir/node.cpp.o: ../../src/node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object build/src/CMakeFiles/graphviewer.dir/node.cpp.o"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphviewer.dir/node.cpp.o -c /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/node.cpp

build/src/CMakeFiles/graphviewer.dir/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphviewer.dir/node.cpp.i"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/node.cpp > CMakeFiles/graphviewer.dir/node.cpp.i

build/src/CMakeFiles/graphviewer.dir/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphviewer.dir/node.cpp.s"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/node.cpp -o CMakeFiles/graphviewer.dir/node.cpp.s

build/src/CMakeFiles/graphviewer.dir/edge.cpp.o: build/src/CMakeFiles/graphviewer.dir/flags.make
build/src/CMakeFiles/graphviewer.dir/edge.cpp.o: ../../src/edge.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object build/src/CMakeFiles/graphviewer.dir/edge.cpp.o"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphviewer.dir/edge.cpp.o -c /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/edge.cpp

build/src/CMakeFiles/graphviewer.dir/edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphviewer.dir/edge.cpp.i"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/edge.cpp > CMakeFiles/graphviewer.dir/edge.cpp.i

build/src/CMakeFiles/graphviewer.dir/edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphviewer.dir/edge.cpp.s"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/edge.cpp -o CMakeFiles/graphviewer.dir/edge.cpp.s

build/src/CMakeFiles/graphviewer.dir/lines.cpp.o: build/src/CMakeFiles/graphviewer.dir/flags.make
build/src/CMakeFiles/graphviewer.dir/lines.cpp.o: ../../src/lines.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object build/src/CMakeFiles/graphviewer.dir/lines.cpp.o"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphviewer.dir/lines.cpp.o -c /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/lines.cpp

build/src/CMakeFiles/graphviewer.dir/lines.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphviewer.dir/lines.cpp.i"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/lines.cpp > CMakeFiles/graphviewer.dir/lines.cpp.i

build/src/CMakeFiles/graphviewer.dir/lines.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphviewer.dir/lines.cpp.s"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/lines.cpp -o CMakeFiles/graphviewer.dir/lines.cpp.s

build/src/CMakeFiles/graphviewer.dir/fpsmonitor.cpp.o: build/src/CMakeFiles/graphviewer.dir/flags.make
build/src/CMakeFiles/graphviewer.dir/fpsmonitor.cpp.o: ../../src/fpsmonitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object build/src/CMakeFiles/graphviewer.dir/fpsmonitor.cpp.o"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphviewer.dir/fpsmonitor.cpp.o -c /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/fpsmonitor.cpp

build/src/CMakeFiles/graphviewer.dir/fpsmonitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphviewer.dir/fpsmonitor.cpp.i"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/fpsmonitor.cpp > CMakeFiles/graphviewer.dir/fpsmonitor.cpp.i

build/src/CMakeFiles/graphviewer.dir/fpsmonitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphviewer.dir/fpsmonitor.cpp.s"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src/fpsmonitor.cpp -o CMakeFiles/graphviewer.dir/fpsmonitor.cpp.s

# Object files for target graphviewer
graphviewer_OBJECTS = \
"CMakeFiles/graphviewer.dir/graphviewer.cpp.o" \
"CMakeFiles/graphviewer.dir/node.cpp.o" \
"CMakeFiles/graphviewer.dir/edge.cpp.o" \
"CMakeFiles/graphviewer.dir/lines.cpp.o" \
"CMakeFiles/graphviewer.dir/fpsmonitor.cpp.o"

# External object files for target graphviewer
graphviewer_EXTERNAL_OBJECTS =

../../lib/libgraphviewer.a: build/src/CMakeFiles/graphviewer.dir/graphviewer.cpp.o
../../lib/libgraphviewer.a: build/src/CMakeFiles/graphviewer.dir/node.cpp.o
../../lib/libgraphviewer.a: build/src/CMakeFiles/graphviewer.dir/edge.cpp.o
../../lib/libgraphviewer.a: build/src/CMakeFiles/graphviewer.dir/lines.cpp.o
../../lib/libgraphviewer.a: build/src/CMakeFiles/graphviewer.dir/fpsmonitor.cpp.o
../../lib/libgraphviewer.a: build/src/CMakeFiles/graphviewer.dir/build.make
../../lib/libgraphviewer.a: build/src/CMakeFiles/graphviewer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library ../../../../lib/libgraphviewer.a"
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && $(CMAKE_COMMAND) -P CMakeFiles/graphviewer.dir/cmake_clean_target.cmake
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphviewer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
build/src/CMakeFiles/graphviewer.dir/build: ../../lib/libgraphviewer.a

.PHONY : build/src/CMakeFiles/graphviewer.dir/build

build/src/CMakeFiles/graphviewer.dir/clean:
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src && $(CMAKE_COMMAND) -P CMakeFiles/graphviewer.dir/cmake_clean.cmake
.PHONY : build/src/CMakeFiles/graphviewer.dir/clean

build/src/CMakeFiles/graphviewer.dir/depend:
	cd /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/src /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src /home/dmfr/Documents/Superior/2S2/CAL/GraphViewerCpp/example/build/build/src/CMakeFiles/graphviewer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : build/src/CMakeFiles/graphviewer.dir/depend


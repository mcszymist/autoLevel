# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /opt/CLion/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/CLion/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zym/Desktop/CS411/autoLevel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zym/Desktop/CS411/autoLevel/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/autoLevel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/autoLevel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/autoLevel.dir/flags.make

CMakeFiles/autoLevel.dir/house.cpp.o: CMakeFiles/autoLevel.dir/flags.make
CMakeFiles/autoLevel.dir/house.cpp.o: ../house.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zym/Desktop/CS411/autoLevel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/autoLevel.dir/house.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autoLevel.dir/house.cpp.o -c /home/zym/Desktop/CS411/autoLevel/house.cpp

CMakeFiles/autoLevel.dir/house.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autoLevel.dir/house.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zym/Desktop/CS411/autoLevel/house.cpp > CMakeFiles/autoLevel.dir/house.cpp.i

CMakeFiles/autoLevel.dir/house.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autoLevel.dir/house.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zym/Desktop/CS411/autoLevel/house.cpp -o CMakeFiles/autoLevel.dir/house.cpp.s

CMakeFiles/autoLevel.dir/jack.cpp.o: CMakeFiles/autoLevel.dir/flags.make
CMakeFiles/autoLevel.dir/jack.cpp.o: ../jack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zym/Desktop/CS411/autoLevel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/autoLevel.dir/jack.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autoLevel.dir/jack.cpp.o -c /home/zym/Desktop/CS411/autoLevel/jack.cpp

CMakeFiles/autoLevel.dir/jack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autoLevel.dir/jack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zym/Desktop/CS411/autoLevel/jack.cpp > CMakeFiles/autoLevel.dir/jack.cpp.i

CMakeFiles/autoLevel.dir/jack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autoLevel.dir/jack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zym/Desktop/CS411/autoLevel/jack.cpp -o CMakeFiles/autoLevel.dir/jack.cpp.s

CMakeFiles/autoLevel.dir/emu.cpp.o: CMakeFiles/autoLevel.dir/flags.make
CMakeFiles/autoLevel.dir/emu.cpp.o: ../emu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zym/Desktop/CS411/autoLevel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/autoLevel.dir/emu.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autoLevel.dir/emu.cpp.o -c /home/zym/Desktop/CS411/autoLevel/emu.cpp

CMakeFiles/autoLevel.dir/emu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autoLevel.dir/emu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zym/Desktop/CS411/autoLevel/emu.cpp > CMakeFiles/autoLevel.dir/emu.cpp.i

CMakeFiles/autoLevel.dir/emu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autoLevel.dir/emu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zym/Desktop/CS411/autoLevel/emu.cpp -o CMakeFiles/autoLevel.dir/emu.cpp.s

CMakeFiles/autoLevel.dir/sensor.cpp.o: CMakeFiles/autoLevel.dir/flags.make
CMakeFiles/autoLevel.dir/sensor.cpp.o: ../sensor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zym/Desktop/CS411/autoLevel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/autoLevel.dir/sensor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autoLevel.dir/sensor.cpp.o -c /home/zym/Desktop/CS411/autoLevel/sensor.cpp

CMakeFiles/autoLevel.dir/sensor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autoLevel.dir/sensor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zym/Desktop/CS411/autoLevel/sensor.cpp > CMakeFiles/autoLevel.dir/sensor.cpp.i

CMakeFiles/autoLevel.dir/sensor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autoLevel.dir/sensor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zym/Desktop/CS411/autoLevel/sensor.cpp -o CMakeFiles/autoLevel.dir/sensor.cpp.s

CMakeFiles/autoLevel.dir/SerialPort.cpp.o: CMakeFiles/autoLevel.dir/flags.make
CMakeFiles/autoLevel.dir/SerialPort.cpp.o: ../SerialPort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zym/Desktop/CS411/autoLevel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/autoLevel.dir/SerialPort.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autoLevel.dir/SerialPort.cpp.o -c /home/zym/Desktop/CS411/autoLevel/SerialPort.cpp

CMakeFiles/autoLevel.dir/SerialPort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autoLevel.dir/SerialPort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zym/Desktop/CS411/autoLevel/SerialPort.cpp > CMakeFiles/autoLevel.dir/SerialPort.cpp.i

CMakeFiles/autoLevel.dir/SerialPort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autoLevel.dir/SerialPort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zym/Desktop/CS411/autoLevel/SerialPort.cpp -o CMakeFiles/autoLevel.dir/SerialPort.cpp.s

CMakeFiles/autoLevel.dir/main.cpp.o: CMakeFiles/autoLevel.dir/flags.make
CMakeFiles/autoLevel.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zym/Desktop/CS411/autoLevel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/autoLevel.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autoLevel.dir/main.cpp.o -c /home/zym/Desktop/CS411/autoLevel/main.cpp

CMakeFiles/autoLevel.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autoLevel.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zym/Desktop/CS411/autoLevel/main.cpp > CMakeFiles/autoLevel.dir/main.cpp.i

CMakeFiles/autoLevel.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autoLevel.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zym/Desktop/CS411/autoLevel/main.cpp -o CMakeFiles/autoLevel.dir/main.cpp.s

# Object files for target autoLevel
autoLevel_OBJECTS = \
"CMakeFiles/autoLevel.dir/house.cpp.o" \
"CMakeFiles/autoLevel.dir/jack.cpp.o" \
"CMakeFiles/autoLevel.dir/emu.cpp.o" \
"CMakeFiles/autoLevel.dir/sensor.cpp.o" \
"CMakeFiles/autoLevel.dir/SerialPort.cpp.o" \
"CMakeFiles/autoLevel.dir/main.cpp.o"

# External object files for target autoLevel
autoLevel_EXTERNAL_OBJECTS =

autoLevel: CMakeFiles/autoLevel.dir/house.cpp.o
autoLevel: CMakeFiles/autoLevel.dir/jack.cpp.o
autoLevel: CMakeFiles/autoLevel.dir/emu.cpp.o
autoLevel: CMakeFiles/autoLevel.dir/sensor.cpp.o
autoLevel: CMakeFiles/autoLevel.dir/SerialPort.cpp.o
autoLevel: CMakeFiles/autoLevel.dir/main.cpp.o
autoLevel: CMakeFiles/autoLevel.dir/build.make
autoLevel: CMakeFiles/autoLevel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zym/Desktop/CS411/autoLevel/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable autoLevel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/autoLevel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/autoLevel.dir/build: autoLevel

.PHONY : CMakeFiles/autoLevel.dir/build

CMakeFiles/autoLevel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/autoLevel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/autoLevel.dir/clean

CMakeFiles/autoLevel.dir/depend:
	cd /home/zym/Desktop/CS411/autoLevel/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zym/Desktop/CS411/autoLevel /home/zym/Desktop/CS411/autoLevel /home/zym/Desktop/CS411/autoLevel/cmake-build-debug /home/zym/Desktop/CS411/autoLevel/cmake-build-debug /home/zym/Desktop/CS411/autoLevel/cmake-build-debug/CMakeFiles/autoLevel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/autoLevel.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\GitHW\Yuqing_LC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GitHW\Yuqing_LC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Yuqing_LC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Yuqing_LC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Yuqing_LC.dir/flags.make

CMakeFiles/Yuqing_LC.dir/main.cpp.obj: CMakeFiles/Yuqing_LC.dir/flags.make
CMakeFiles/Yuqing_LC.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHW\Yuqing_LC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Yuqing_LC.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Yuqing_LC.dir\main.cpp.obj -c C:\GitHW\Yuqing_LC\main.cpp

CMakeFiles/Yuqing_LC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Yuqing_LC.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHW\Yuqing_LC\main.cpp > CMakeFiles\Yuqing_LC.dir\main.cpp.i

CMakeFiles/Yuqing_LC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Yuqing_LC.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHW\Yuqing_LC\main.cpp -o CMakeFiles\Yuqing_LC.dir\main.cpp.s

# Object files for target Yuqing_LC
Yuqing_LC_OBJECTS = \
"CMakeFiles/Yuqing_LC.dir/main.cpp.obj"

# External object files for target Yuqing_LC
Yuqing_LC_EXTERNAL_OBJECTS =

Yuqing_LC.exe: CMakeFiles/Yuqing_LC.dir/main.cpp.obj
Yuqing_LC.exe: CMakeFiles/Yuqing_LC.dir/build.make
Yuqing_LC.exe: CMakeFiles/Yuqing_LC.dir/linklibs.rsp
Yuqing_LC.exe: CMakeFiles/Yuqing_LC.dir/objects1.rsp
Yuqing_LC.exe: CMakeFiles/Yuqing_LC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GitHW\Yuqing_LC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Yuqing_LC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Yuqing_LC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Yuqing_LC.dir/build: Yuqing_LC.exe

.PHONY : CMakeFiles/Yuqing_LC.dir/build

CMakeFiles/Yuqing_LC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Yuqing_LC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Yuqing_LC.dir/clean

CMakeFiles/Yuqing_LC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GitHW\Yuqing_LC C:\GitHW\Yuqing_LC C:\GitHW\Yuqing_LC\cmake-build-debug C:\GitHW\Yuqing_LC\cmake-build-debug C:\GitHW\Yuqing_LC\cmake-build-debug\CMakeFiles\Yuqing_LC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Yuqing_LC.dir/depend

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
CMAKE_COMMAND = /usr/local/cmake-3.12.4/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake-3.12.4/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/travis/build/alexhamster/homework_4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/travis/build/alexhamster/homework_4

# Include any dependencies generated for this target.
include CMakeFiles/test_ip_print.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_ip_print.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_ip_print.dir/flags.make

CMakeFiles/test_ip_print.dir/test_ip_print.cpp.o: CMakeFiles/test_ip_print.dir/flags.make
CMakeFiles/test_ip_print.dir/test_ip_print.cpp.o: test_ip_print.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/travis/build/alexhamster/homework_4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_ip_print.dir/test_ip_print.cpp.o"
	/usr/local/clang-7.0.0/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_ip_print.dir/test_ip_print.cpp.o -c /home/travis/build/alexhamster/homework_4/test_ip_print.cpp

CMakeFiles/test_ip_print.dir/test_ip_print.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_ip_print.dir/test_ip_print.cpp.i"
	/usr/local/clang-7.0.0/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/travis/build/alexhamster/homework_4/test_ip_print.cpp > CMakeFiles/test_ip_print.dir/test_ip_print.cpp.i

CMakeFiles/test_ip_print.dir/test_ip_print.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_ip_print.dir/test_ip_print.cpp.s"
	/usr/local/clang-7.0.0/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/travis/build/alexhamster/homework_4/test_ip_print.cpp -o CMakeFiles/test_ip_print.dir/test_ip_print.cpp.s

# Object files for target test_ip_print
test_ip_print_OBJECTS = \
"CMakeFiles/test_ip_print.dir/test_ip_print.cpp.o"

# External object files for target test_ip_print
test_ip_print_EXTERNAL_OBJECTS =

test_ip_print: CMakeFiles/test_ip_print.dir/test_ip_print.cpp.o
test_ip_print: CMakeFiles/test_ip_print.dir/build.make
test_ip_print: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so
test_ip_print: libip_lib.a
test_ip_print: CMakeFiles/test_ip_print.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/travis/build/alexhamster/homework_4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_ip_print"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_ip_print.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_ip_print.dir/build: test_ip_print

.PHONY : CMakeFiles/test_ip_print.dir/build

CMakeFiles/test_ip_print.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_ip_print.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_ip_print.dir/clean

CMakeFiles/test_ip_print.dir/depend:
	cd /home/travis/build/alexhamster/homework_4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/travis/build/alexhamster/homework_4 /home/travis/build/alexhamster/homework_4 /home/travis/build/alexhamster/homework_4 /home/travis/build/alexhamster/homework_4 /home/travis/build/alexhamster/homework_4/CMakeFiles/test_ip_print.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_ip_print.dir/depend

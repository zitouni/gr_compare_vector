# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zitouni/git/workspace/gr_compare_vector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zitouni/git/workspace/gr_compare_vector/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/qa_howto_compare_vector_cci.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/qa_howto_compare_vector_cci.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/qa_howto_compare_vector_cci.dir/flags.make

lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o: lib/CMakeFiles/qa_howto_compare_vector_cci.dir/flags.make
lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o: ../lib/qa_howto_compare_vector_cci.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zitouni/git/workspace/gr_compare_vector/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o"
	cd /home/zitouni/git/workspace/gr_compare_vector/build/lib && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o -c /home/zitouni/git/workspace/gr_compare_vector/lib/qa_howto_compare_vector_cci.cc

lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.i"
	cd /home/zitouni/git/workspace/gr_compare_vector/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zitouni/git/workspace/gr_compare_vector/lib/qa_howto_compare_vector_cci.cc > CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.i

lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.s"
	cd /home/zitouni/git/workspace/gr_compare_vector/build/lib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zitouni/git/workspace/gr_compare_vector/lib/qa_howto_compare_vector_cci.cc -o CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.s

lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o.requires:
.PHONY : lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o.requires

lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o.provides: lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o.requires
	$(MAKE) -f lib/CMakeFiles/qa_howto_compare_vector_cci.dir/build.make lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o.provides.build
.PHONY : lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o.provides

lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o.provides.build: lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o

# Object files for target qa_howto_compare_vector_cci
qa_howto_compare_vector_cci_OBJECTS = \
"CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o"

# External object files for target qa_howto_compare_vector_cci
qa_howto_compare_vector_cci_EXTERNAL_OBJECTS =

lib/qa_howto_compare_vector_cci: lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o
lib/qa_howto_compare_vector_cci: lib/libgnuradio-howto.so
lib/qa_howto_compare_vector_cci: /usr/lib/libboost_unit_test_framework-mt.so
lib/qa_howto_compare_vector_cci: /usr/local/lib/libgruel.so
lib/qa_howto_compare_vector_cci: /usr/local/lib/libgnuradio-core.so
lib/qa_howto_compare_vector_cci: lib/CMakeFiles/qa_howto_compare_vector_cci.dir/build.make
lib/qa_howto_compare_vector_cci: lib/CMakeFiles/qa_howto_compare_vector_cci.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable qa_howto_compare_vector_cci"
	cd /home/zitouni/git/workspace/gr_compare_vector/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qa_howto_compare_vector_cci.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/qa_howto_compare_vector_cci.dir/build: lib/qa_howto_compare_vector_cci
.PHONY : lib/CMakeFiles/qa_howto_compare_vector_cci.dir/build

lib/CMakeFiles/qa_howto_compare_vector_cci.dir/requires: lib/CMakeFiles/qa_howto_compare_vector_cci.dir/qa_howto_compare_vector_cci.cc.o.requires
.PHONY : lib/CMakeFiles/qa_howto_compare_vector_cci.dir/requires

lib/CMakeFiles/qa_howto_compare_vector_cci.dir/clean:
	cd /home/zitouni/git/workspace/gr_compare_vector/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/qa_howto_compare_vector_cci.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/qa_howto_compare_vector_cci.dir/clean

lib/CMakeFiles/qa_howto_compare_vector_cci.dir/depend:
	cd /home/zitouni/git/workspace/gr_compare_vector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zitouni/git/workspace/gr_compare_vector /home/zitouni/git/workspace/gr_compare_vector/lib /home/zitouni/git/workspace/gr_compare_vector/build /home/zitouni/git/workspace/gr_compare_vector/build/lib /home/zitouni/git/workspace/gr_compare_vector/build/lib/CMakeFiles/qa_howto_compare_vector_cci.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/qa_howto_compare_vector_cci.dir/depend


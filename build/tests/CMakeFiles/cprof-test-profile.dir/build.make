# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/edsiper/c/cprofiles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edsiper/c/cprofiles/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/cprof-test-profile.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/cprof-test-profile.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/cprof-test-profile.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/cprof-test-profile.dir/flags.make

tests/CMakeFiles/cprof-test-profile.dir/profile.c.o: tests/CMakeFiles/cprof-test-profile.dir/flags.make
tests/CMakeFiles/cprof-test-profile.dir/profile.c.o: /home/edsiper/c/cprofiles/tests/profile.c
tests/CMakeFiles/cprof-test-profile.dir/profile.c.o: tests/CMakeFiles/cprof-test-profile.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/cprof-test-profile.dir/profile.c.o"
	cd /home/edsiper/c/cprofiles/build/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/cprof-test-profile.dir/profile.c.o -MF CMakeFiles/cprof-test-profile.dir/profile.c.o.d -o CMakeFiles/cprof-test-profile.dir/profile.c.o -c /home/edsiper/c/cprofiles/tests/profile.c

tests/CMakeFiles/cprof-test-profile.dir/profile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cprof-test-profile.dir/profile.c.i"
	cd /home/edsiper/c/cprofiles/build/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/tests/profile.c > CMakeFiles/cprof-test-profile.dir/profile.c.i

tests/CMakeFiles/cprof-test-profile.dir/profile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cprof-test-profile.dir/profile.c.s"
	cd /home/edsiper/c/cprofiles/build/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/tests/profile.c -o CMakeFiles/cprof-test-profile.dir/profile.c.s

# Object files for target cprof-test-profile
cprof__test__profile_OBJECTS = \
"CMakeFiles/cprof-test-profile.dir/profile.c.o"

# External object files for target cprof-test-profile
cprof__test__profile_EXTERNAL_OBJECTS =

tests/cprof-test-profile: tests/CMakeFiles/cprof-test-profile.dir/profile.c.o
tests/cprof-test-profile: tests/CMakeFiles/cprof-test-profile.dir/build.make
tests/cprof-test-profile: src/libcprofiles.a
tests/cprof-test-profile: lib/mpack/libmpack.a
tests/cprof-test-profile: lib/cfl/src/libcfl.a
tests/cprof-test-profile: lib/fluent-otel-proto/src/libfluent-otel-proto.a
tests/cprof-test-profile: lib/cfl/lib/xxhash/cmake_unofficial/libxxhash.a
tests/cprof-test-profile: tests/CMakeFiles/cprof-test-profile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cprof-test-profile"
	cd /home/edsiper/c/cprofiles/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cprof-test-profile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/cprof-test-profile.dir/build: tests/cprof-test-profile
.PHONY : tests/CMakeFiles/cprof-test-profile.dir/build

tests/CMakeFiles/cprof-test-profile.dir/clean:
	cd /home/edsiper/c/cprofiles/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/cprof-test-profile.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/cprof-test-profile.dir/clean

tests/CMakeFiles/cprof-test-profile.dir/depend:
	cd /home/edsiper/c/cprofiles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edsiper/c/cprofiles /home/edsiper/c/cprofiles/tests /home/edsiper/c/cprofiles/build /home/edsiper/c/cprofiles/build/tests /home/edsiper/c/cprofiles/build/tests/CMakeFiles/cprof-test-profile.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/cprof-test-profile.dir/depend


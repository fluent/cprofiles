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
include lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/progress.make

# Include the compile flags for this target's objects.
include lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/src/fluent-otel.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.o -MF CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.o.d -o CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/src/fluent-otel.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/src/fluent-otel.c > CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/src/fluent-otel.c -o CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/protobuf-c/protobuf-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/protobuf-c/protobuf-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/protobuf-c/protobuf-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/protobuf-c/protobuf-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/common/v1/common.pb-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/common/v1/common.pb-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/common/v1/common.pb-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/common/v1/common.pb-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.s

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/flags.make
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.o: /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.o: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.o"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.o -MF CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.o.d -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.o -c /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.i"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c > CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.i

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.s"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/edsiper/c/cprofiles/lib/fluent-otel-proto/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c -o CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.s

# Object files for target fluent-otel-proto
fluent__otel__proto_OBJECTS = \
"CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.o" \
"CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.o"

# External object files for target fluent-otel-proto
fluent__otel__proto_EXTERNAL_OBJECTS =

lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/fluent-otel.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/protobuf-c/protobuf-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/common/v1/common.pb-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/resource/v1/resource.pb-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/trace/v1/trace.pb-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/trace/v1/trace_service.pb-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/logs/v1/logs.pb-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/logs/v1/logs_service.pb-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/metrics/v1/metrics.pb-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/collector/metrics/v1/metrics_service.pb-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/__/proto_c/opentelemetry/proto/profiles/v1development/profiles.pb-c.c.o
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/build.make
lib/fluent-otel-proto/src/libfluent-otel-proto.a: lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/edsiper/c/cprofiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C static library libfluent-otel-proto.a"
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && $(CMAKE_COMMAND) -P CMakeFiles/fluent-otel-proto.dir/cmake_clean_target.cmake
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fluent-otel-proto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/build: lib/fluent-otel-proto/src/libfluent-otel-proto.a
.PHONY : lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/build

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/clean:
	cd /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src && $(CMAKE_COMMAND) -P CMakeFiles/fluent-otel-proto.dir/cmake_clean.cmake
.PHONY : lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/clean

lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/depend:
	cd /home/edsiper/c/cprofiles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edsiper/c/cprofiles /home/edsiper/c/cprofiles/lib/fluent-otel-proto/src /home/edsiper/c/cprofiles/build /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src /home/edsiper/c/cprofiles/build/lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/fluent-otel-proto/src/CMakeFiles/fluent-otel-proto.dir/depend


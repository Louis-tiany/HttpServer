# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/louis/code/project/HttpServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/louis/code/project/HttpServer/build

# Utility rule file for examples.

# Include the progress variables for this target.
include thirdparty/rapidjson/example/CMakeFiles/examples.dir/progress.make

thirdparty/rapidjson/example/CMakeFiles/examples: bin/capitalize
thirdparty/rapidjson/example/CMakeFiles/examples: bin/condense
thirdparty/rapidjson/example/CMakeFiles/examples: bin/filterkey
thirdparty/rapidjson/example/CMakeFiles/examples: bin/filterkeydom
thirdparty/rapidjson/example/CMakeFiles/examples: bin/jsonx
thirdparty/rapidjson/example/CMakeFiles/examples: bin/lookaheadparser
thirdparty/rapidjson/example/CMakeFiles/examples: bin/messagereader
thirdparty/rapidjson/example/CMakeFiles/examples: bin/parsebyparts
thirdparty/rapidjson/example/CMakeFiles/examples: bin/pretty
thirdparty/rapidjson/example/CMakeFiles/examples: bin/prettyauto
thirdparty/rapidjson/example/CMakeFiles/examples: bin/schemavalidator
thirdparty/rapidjson/example/CMakeFiles/examples: bin/serialize
thirdparty/rapidjson/example/CMakeFiles/examples: bin/simpledom
thirdparty/rapidjson/example/CMakeFiles/examples: bin/simplereader
thirdparty/rapidjson/example/CMakeFiles/examples: bin/simplepullreader
thirdparty/rapidjson/example/CMakeFiles/examples: bin/simplewriter
thirdparty/rapidjson/example/CMakeFiles/examples: bin/sortkeys
thirdparty/rapidjson/example/CMakeFiles/examples: bin/tutorial


examples: thirdparty/rapidjson/example/CMakeFiles/examples
examples: thirdparty/rapidjson/example/CMakeFiles/examples.dir/build.make

.PHONY : examples

# Rule to build all files generated by this target.
thirdparty/rapidjson/example/CMakeFiles/examples.dir/build: examples

.PHONY : thirdparty/rapidjson/example/CMakeFiles/examples.dir/build

thirdparty/rapidjson/example/CMakeFiles/examples.dir/clean:
	cd /home/louis/code/project/HttpServer/build/thirdparty/rapidjson/example && $(CMAKE_COMMAND) -P CMakeFiles/examples.dir/cmake_clean.cmake
.PHONY : thirdparty/rapidjson/example/CMakeFiles/examples.dir/clean

thirdparty/rapidjson/example/CMakeFiles/examples.dir/depend:
	cd /home/louis/code/project/HttpServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/louis/code/project/HttpServer /home/louis/code/project/HttpServer/thirdparty/rapidjson/example /home/louis/code/project/HttpServer/build /home/louis/code/project/HttpServer/build/thirdparty/rapidjson/example /home/louis/code/project/HttpServer/build/thirdparty/rapidjson/example/CMakeFiles/examples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : thirdparty/rapidjson/example/CMakeFiles/examples.dir/depend

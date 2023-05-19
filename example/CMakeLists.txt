#
SET (THE_PROJECT perf-timer-example)

cmake_minimum_required(VERSION 3.26)

PROJECT(${THE_PROJECT} VERSION 1.0.0 DESCRIPTION "example of usage of perf-timer")

# C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

SET (CMAKE_EXPORT_COMPILE_COMMANDS on)
SET (CMAKE_VERBOSE_MAKEFILE on )

# Set the variable source_files to the list of names of your C++ source code
SET(source_files
   example.cpp
)

SET(CMAKE_BUILD_TYPE RELEASE) # Debug, Release, RelWithDebInfo, MinSizeRel

# Build a program called '${THE_PROJECT}' from the source files we specified above
ADD_EXECUTABLE(${THE_PROJECT} ${source_files})

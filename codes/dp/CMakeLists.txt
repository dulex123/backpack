# --------------------------------------------------------------------------- #
# This script takes care of creating build configurations for new files that
# are added in Clion.
#
# It is best used when combined with Ctrl+R shortcut for refreshing CMake
# which is a necessary step since Cmake doesn't know when new file is added.
# --------------------------------------------------------------------------- #

cmake_minimum_required(VERSION 3.3)
project(algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Get all files from current directory
file(GLOB SOURCE_FILES [RELATIVE] *.cpp)

foreach(sourcefile ${SOURCE_FILES})
    # Strip path, leave only filename
    get_filename_component( nomen ${sourcefile} NAME)
    string(REPLACE ".cpp" "" testname ${nomen})
    add_executable( ${testname} ${nomen} )
endforeach(sourcefile ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.8)
project(GeeksForGeeks)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES dp/TripletsWithPerfectCubeSum.cpp dp/MaximumSumBitonicSubarray.cpp dp/MaximumSumBitonicSubsequence.cpp)
add_executable(GeeksForGeeks ${SOURCE_FILES})
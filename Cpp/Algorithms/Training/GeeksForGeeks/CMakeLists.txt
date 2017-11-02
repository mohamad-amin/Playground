cmake_minimum_required(VERSION 3.8)
project(GeeksForGeeks)

set(CMAKE_CXX_STANDARD 11)

file(GLOB DP "dp/*.cpp")
file(GLOB GRAPH "graph/*.cpp")
file(GLOB GEOMETRIC "geometric/*.cpp")

add_executable(GeeksForGeeks ${DP} ${GRAPH} ${GEOMETRIC})

cmake_minimum_required(VERSION 3.15)
project(Vector)

set(CMAKE_CXX_STANDARD 17)

add_executable(VectorTests VectorLabTests.cpp ../src/VectorFunctions.cpp)
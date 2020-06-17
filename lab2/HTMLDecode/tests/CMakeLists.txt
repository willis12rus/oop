cmake_minimum_required(VERSION 3.16)
project(HTMLDecode)

set(CMAKE_CXX_STANDARD 17)

add_executable(HTMLDecode.Tests HTMLDecode.Tests.cpp ../src/HTMLDecodeFunction.cpp)
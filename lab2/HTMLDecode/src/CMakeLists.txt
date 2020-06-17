cmake_minimum_required(VERSION 3.16)
project(HTMLDecode)

set(CMAKE_CXX_STANDARD 17)

add_executable(HTMLDecode main.cpp HTMLDecodeFunction.cpp HTMLDecodeFunction.h)
cmake_minimum_required(VERSION 3.21)
project(PROJEKT_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(PROJEKT_1 main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,100000000")
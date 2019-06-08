cmake_minimum_required(VERSION 2.8)
project(tmp)

add_executable(tmp main.cpp)
set(cmake_make_program ninja)
set(cmake_cxx_flags "${CMAKE_CXX_FLAGS} -std=c++14")
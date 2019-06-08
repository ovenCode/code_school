cmake_minimum_required(version 2.8)
project(project2)

add_executable(engine Z211_Anthony_Bosca_lab3.cpp)
set(cmake_make_program ninja)
set(cmake_cxx_flags "${CMAKE_CXX_FLAGS} -std=c++14")
cmake_minimum_required(VERSION 3.8)
project(assignment2)

add_executable(assignment2 main.cpp Graph.h Graph.cpp)
set(QMAKE_CXXFLAGS "-std=c++11" -Wall -Werror -pedantic )
cmake_minimum_required(VERSION 3.10)
project(8-puzzle-search)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(run
    src/main.cpp
    src/problem.cpp
    src/state.cpp
    src/menu.cpp
    src/search.cpp
)
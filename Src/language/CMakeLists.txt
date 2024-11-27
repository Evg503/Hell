cmake_minimum_required(VERSION 3.22)

        # specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(Lang Lexer.cpp)

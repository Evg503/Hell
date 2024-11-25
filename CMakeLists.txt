cmake_minimum_required(VERSION 3.22)

project(Hell 
        VERSION 0.0.0.0
        HOMEPAGE_URL example.com/Hell
        LANGUAGES CXX C
        DESCRIPTION "No description yet"
        )

        # specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Hell Src/main.cpp)
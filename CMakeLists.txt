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

find_package(GTest REQUIRED)

include_directories(./include)

add_subdirectory(Src/language)
add_subdirectory(Test)

set(CPP_SOURCE Src/main.cpp)

add_executable(${PROJECT_NAME} ${CPP_SOURCE})
target_link_libraries(${PROJECT_NAME} Lang)


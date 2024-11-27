cmake_minimum_required(VERSION 3.22)

find_package(GTest REQUIRED)

project(TestHell 
        VERSION 0.0.0.0
        HOMEPAGE_URL example.com/Hell
        LANGUAGES CXX C
        DESCRIPTION "No description yet"
        )

        # specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(TestHell TestParser.cpp)
include_directories(./include)


enable_testing()


target_link_libraries(
    TestHell
    Lang
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TestHell)
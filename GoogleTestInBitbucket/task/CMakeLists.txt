cmake_minimum_required(VERSION 3.5)
project(task)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 14)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(mytest main.cpp Implementation.cpp Declaration.h) 

target_link_libraries(mytest ${GTEST_LIBRARIES} pthread)

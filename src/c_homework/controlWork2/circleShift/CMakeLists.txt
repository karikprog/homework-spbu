cmake_minimum_required(VERSION 3.25)
project(palindrom C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -g")

add_library(Test testCircleShift.c)

add_executable(app circleShift.c)
target_link_libraries(app PRIVATE Test)

cmake_minimum_required(VERSION 3.25)
project(palindrom C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -g")

add_library(List list.c)
add_library(Test testPalindrom.c)

add_executable(app palindrom.c)
target_link_libraries(app PRIVATE List)
target_link_libraries(app PRIVATE Test)
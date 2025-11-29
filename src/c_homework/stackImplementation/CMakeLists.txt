cmake_minimum_required(VERSION 3.25)
project(stack C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -g")

add_library(Stack stack.c)


add_executable(shuntingYard shuntingYard.c)
target_link_libraries(shuntingYard PRIVATE Stack)
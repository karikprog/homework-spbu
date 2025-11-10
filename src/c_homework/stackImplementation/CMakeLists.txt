cmake_minimum_required(VERSION 3.25)
project(stack C)

option(BUILD_BRACKED_BALANCE "Build bracked balance program" OFF)
option(BUILD_SHUNTING_YARD "Build Shunting yard program" OFF)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -g")

add_library(Stack stack.c)

if(BUILD_BRACKED_BALANCE)
    set(TARGET_NAME brackedB)
    set(SOURCES brackedBalance.c)
elseif(BUILD_SHUNTING_YARD)
    set(TARGET_NAME shuntingY)
    set(SOURCES shuntingYard.c)
else()
    message(FATAL_ERROR "You must specify BUILD_BRACKED_BALANCE or BUILD_SHUNTING_YARD")
endif()

add_executable(${TARGET_NAME} ${SOURCES})
target_link_libraries(${TARGET_NAME} PRIVATE Stack)
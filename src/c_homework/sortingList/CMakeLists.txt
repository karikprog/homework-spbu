cmake_minimum_required(VERSION 3.10)
project(MySortingListProject C)

enable_testing()

add_library(List linkedList.c)
target_include_directories(
    List 
    PUBLIC 
    . 
)

add_library(Tests tests/testSortingList.c)
target_include_directories(
    Tests
    PUBLIC 
    tests
)
add_library(SortingList sortingList.c)

target_link_libraries(SortingList PUBLIC List)
target_link_libraries(Tests PUBLIC List)


add_executable(app main.c)

target_link_libraries(app PRIVATE SortingList)
target_link_libraries(app PRIVATE Tests)


add_test(
    NAME SortingAndLinkedListTests
    COMMAND app --test
)
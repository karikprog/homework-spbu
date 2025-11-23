cmake_minimum_required(VERSION 3.10)
project(MySortingListProject C)

enable_testing()


include_directories(
    .
    tests
) 


add_executable(
    app

    linkedList.c
    sortingList.c

    tests/testSortingList.c 
)

add_test(
    NAME SortingAndLinkedListTests
    COMMAND app --test
)
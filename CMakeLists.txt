cmake_minimum_required(VERSION 3.20)
project(sort)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

add_executable(tests
    tests.cpp
    LoggedValue.cpp
    Counters.cpp
)

enable_testing()
add_test(NAME test COMMAND tests)

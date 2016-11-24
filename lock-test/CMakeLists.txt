cmake_minimum_required (VERSION 2.8.11)
project (lock-test)
set (CMAKE_CXX_FLAGS "-std=c++14 -O3 -g -pedantic -Wall -Wextra -pthread")
add_executable (testLock testLock.cpp SpinLock.cpp)

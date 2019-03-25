cmake_minimum_required(VERSION 2.8)

set(CXX_FLAGS
    -g
    -Wall
    -std=c++11
    -D_PTHREADS
    -Wno-unused-parameter
    -O2
    -finline-functions
)

add_subdirectory(src)

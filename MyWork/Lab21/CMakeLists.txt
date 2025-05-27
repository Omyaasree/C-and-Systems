cmake_minimum_required(VERSION 3.31)
project(Lab21 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab21 primechecker.c
        fifo.h
        fifo.c)

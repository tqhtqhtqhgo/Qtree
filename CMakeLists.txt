cmake_minimum_required(VERSION 3.15)
project(Qtree C)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -lldb")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g -lm ")
add_executable(Qtree qtree.h tmp.c main.c )

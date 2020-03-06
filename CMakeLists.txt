cmake_minimum_required(VERSION 3.15)
project(Qtree C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g")

add_executable(Qtree treeStructure.h buildTree.h writeTree.h writeTree.c main.c buildTree.c)

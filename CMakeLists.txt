cmake_minimum_required(VERSION 4.3)
project(linkedlist C)

set(CMAKE_C_STANDARD 11)

add_executable(linkedlist main.c
        linkedlist.h
        linkedlist.c)

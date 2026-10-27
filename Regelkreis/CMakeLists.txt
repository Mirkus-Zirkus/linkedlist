cmake_minimum_required(VERSION 4.3)
project(Regelkreis C)

set(CMAKE_C_STANDARD 11)

add_executable(Regelkreis main.c
        zweipunktregler.c
        ReglerHeader.h)

cmake_minimum_required(VERSION 3.25)
project(DatenTypen C)

set(CMAKE_C_STANDARD 11)

add_executable(DatenTypen main.c
        LinkedList/linkedlist.h
        LinkedList/linkedlist.c
        DoubleLinkedList/double_linkedlist.h
        DoubleLinkedList/double_linkedlist.c)

add_executable(BitwiseOperation main.c)
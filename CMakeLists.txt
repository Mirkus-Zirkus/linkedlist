cmake_minimum_required(VERSION 4.3)
project(DatenTypen C)

set(CMAKE_C_STANDARD 11)

add_executable(linkedlist main.c
        LinkedList/linkedlist.h
        LinkedList/linkedlist.c
        DoubleLinkedList/double_linkedlist.h
        DoubleLinkedList/double_linkedlist.c)

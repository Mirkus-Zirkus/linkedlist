//
// Created by mirko on 9/16/26.
//

#ifndef DOUBLE_LINKEDLIST_H
#define DOUBLE_LINKEDLIST_H
#include <stdbool.h>

typedef struct dll_node_t {
    double data;
    struct dll_node_t *next;
    struct dll_node_t *prev;
} dll_node_t;

typedef struct {
    dll_node_t* head;
    dll_node_t* tail;
    int size;
} LinkedList;

bool dll_push(dll_node_t **head, double data);
bool dll_pop(dll_node_t **head, double *result_data);
bool dll_insert_at(dll_node_t **head, double data, int index);
bool dll_remove_at(dll_node_t **head, int index, double *result_data);
bool dll_insert_at_end(dll_node_t **head, double data);
bool dll_remove_at_end(dll_node_t **head, double *result_data);
bool dll_search(dll_node_t **head, double data, dll_node_t **result_node);
bool dll_clear(dll_node_t **head);

#endif // DOUBLE_LINKEDLIST_H
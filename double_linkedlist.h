//
// Created by mirko on 9/16/26.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <stdbool.h>

typedef struct node_t {
    double data;
    struct node_t *next;
    struct node_t *prev;
} node_t;

typedef struct {
    node_t* head;
    node_t* tail;
    int size;
} LinkedList;


bool dll_push(node_t **head, double data);
bool dll_pop(node_t **head, double *result_data);
bool dll_insert_at(node_t **head, double data, int index);
bool dll_remove_at(node_t **head, int index, double *result_data);
bool dll_insert_at_end(node_t **head, double data);
bool dll_remove_at_end(node_t **head, double *result_data);
bool dll_search(node_t **head, double data, node_t **result_node);
bool dll_clear(node_t **head);

#endif //LINKED
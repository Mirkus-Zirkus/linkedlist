//
// Created by mirko on 9/16/26.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <stdbool.h>

typedef struct node_t {
    double data;
    struct node_t *next;
} node_t;




bool ll_push(node_t **head, double data);
bool ll_pop(node_t **head, double *result_data);
bool ll_insert_at(node_t **head, double data, int index);
bool ll_remove_at(node_t **head, int index, double *result_data);
bool ll_insert_at_end(node_t **head, double data);
bool ll_remove_at_end(node_t **head, double *result_data);
bool ll_search(node_t **head, double data, node_t **result_node);
bool ll_clear(node_t **head);

#endif //LINKEDLIST_LINKEDLIST_H
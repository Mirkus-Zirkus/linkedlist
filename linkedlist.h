//
// Created by mirko on 9/16/26.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <limits.h>

typedef struct node_t {
    double data;
    struct node_t *next;
} node_t;

typedef struct array {
    double array[INT_MAX];
} array_t;

void push(node_t **head, double data);
double pop(node_t **head);
void insert_at(node_t **head, double data, int index);
double remove_at(node_t **head, int index);
void insert_at_end(node_t **head, double data);
double remove_at_end(node_t **head);
node_t *search(node_t **head, double data);
array_t export(node_t **head);


#endif //LINKEDLIST_LINKEDLIST_H

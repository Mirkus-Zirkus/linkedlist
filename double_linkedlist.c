#include "double_linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

bool dll_push(node_t **head, double data) {
    if (head == NULL) {
        return false;
    }
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return false;
    }
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = new_node;
    }

    *head = new_node;
    return true;
}

bool dll_pop(node_t **head, double *data) {
    if (*head == NULL) {
        return false;
    }
    node_t *temp = *head;
    if (data != NULL) {
        *data = temp->data;
    }
    *head = temp->next;
    *temp->next->prev = NULL;
    free(temp);
    return true;

}

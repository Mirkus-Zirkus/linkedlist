#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void push(node_t **head, double data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

double pop(node_t **head) {
    if (*head == NULL) {
        return 0.0;
    }
    node_t *temp = *head;
    double data = temp->data;
    *head = temp->next;
    free(temp);
    return data;
}

void insert_at(node_t **head, double data, int index) {
    if (index < 1) {
        return;
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }
    new_node->data = data;

    if (index == 1) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    node_t *current = *head;
    for (int i = 1; i < index - 1; i++) {
        if (current == NULL) {
            free(new_node);
            return;
        }
        current = current->next;
    }

    if (current == NULL) {
        free(new_node);
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
}



void insert_at_end(node_t **head, double data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    new_node->data = data;
    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;

}

double remove_at_end(node_t **head) {
    if (head == NULL || *head == NULL) {
        return 0.0;
    }
    node_t *current = *head;

    if (current->next == NULL) {
        double data = current->data;
        free(current);
        *head = NULL;
        return data;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    node_t *last = current->next;
    double data = last->data;

    free(last);
    current->next = NULL;
    return data;
}

double remove_at(node_t **head, int index) {
    if (index < 1) {
        return 0.0;
    }

    if (index == 1) {
        return pop(head);
    }

    if (*head == NULL) {
        return 0.0;
    }

    node_t *current = *head;
    for (int i = 1; i < index - 1; i++) {
        if (current->next == NULL) {
            return 0.0;
        }
        current = current->next;
    }
    node_t *to_remove = current->next;
    if (to_remove == NULL) {
        return 0.0;
    }
    double data = to_remove->data;
    current->next = to_remove->next;
    free(to_remove);

    return data;
}


node_t *search(node_t **head, double data) {
    if (head == NULL) {
        return NULL;
    }
    node_t *current = *head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

array_t export (node_t **head) {
    array_t result;
    if (head == NULL) {
        return result;
    }
    node_t *current = *head;
    for (int i = 0; current != NULL; i++) {
        current->data = result.array[i];
    }
    return result;
}

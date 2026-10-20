#include "double_linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

bool dll_push(dll_node_t **head, double data) {
    if (head == NULL) {
        return false;
    }
    dll_node_t *new_node = malloc(sizeof(dll_node_t));
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

bool dll_pop(dll_node_t **head, double *data) {
    if (head == NULL || *head == NULL) {
        return false;
    }
    dll_node_t *temp = *head;
    if (data != NULL) {
        *data = temp->data;
    }
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    return true;
}

bool dll_insert_at(dll_node_t **head, double data, int index) {
    if (head == NULL || index < 1) {
        return false;
    }

    dll_node_t *new_node = malloc(sizeof(dll_node_t));
    if (new_node == NULL) {
        return false;
    }
    new_node->data = data;

    if (index == 1) {
        new_node->next = *head;
        new_node->prev = NULL;
        if (*head != NULL) {
            (*head)->prev = new_node;
        }
        *head = new_node;
        return true;
    }

    dll_node_t *current = *head;
    for (int i = 1; i < index - 1; i++) {
        if (current == NULL) {
            free(new_node);
            return false;
        }
        current = current->next;
    }

    if (current == NULL) {
        free(new_node);
        return false;
    }

    new_node->next = current->next;
    new_node->prev = current;

    if (current->next != NULL) {
        current->next->prev = new_node;
    }

    current->next = new_node;

    return true;
}

bool dll_insert_at_end(dll_node_t **head, double data) {
    if (head == NULL) {
        return false;
    }

    dll_node_t *new_node = malloc(sizeof(dll_node_t));
    if (new_node == NULL) {
        return false;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return true;
    }

    dll_node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    return true;
}

bool dll_remove_at_end(dll_node_t **head, double *result_data) {
    if (head == NULL || *head == NULL) {
        return false;
    }

    dll_node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (result_data != NULL) {
        *result_data = current->data;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(current);
    return true;
}

bool dll_remove_at(dll_node_t **head, int index, double *result_data) {
    if (head == NULL || index < 1) {
        return false;
    }

    if (index == 1) {
        return dll_pop(head, result_data);
    }

    if (*head == NULL) {
        return false;
    }

    dll_node_t *current = *head;
    for (int i = 1; i < index - 1; i++) {
        if (current->next == NULL) {
            return false;
        }
        current = current->next;
    }
    dll_node_t *to_remove = current->next;
    if (to_remove == NULL) {
        return false;
    }
    if (result_data != NULL) {
        *result_data = to_remove->data;
    }

    current->next = to_remove->next;
    if (to_remove->next != NULL) {
        to_remove->next->prev = current;
    }

    free(to_remove);
    return true;
}

bool dll_search(dll_node_t **head, double data, dll_node_t **result_node) {
    if (head == NULL) {
        return false;
    }
    dll_node_t *current = *head;
    while (current != NULL) {
        if (current->data == data) {
            if (result_node != NULL) {
                *result_node = current;
            }
            return true;
        }
        current = current->next;
    }
    return false;
}

bool dll_clear(dll_node_t **head) {
    if (head == NULL) {
        return false;
    }
    dll_node_t *current = *head;
    dll_node_t *next_node = NULL;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    *head = NULL;
    return true;
}

bool dll_export(dll_node_t **head, int *out_size, double **array) {
    if (head == NULL || out_size == NULL || array == NULL) {
        return false;
    }
    int count = 0;
    dll_node_t *current = *head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    *out_size = count;
    if (count == 0) {
        *array = NULL;
        return false;
    }
    *array = malloc(count * sizeof(double));
    if (*array == NULL) {
        *out_size = 0;
        return false;
    }

    current = *head;
    for (int i = 0; i < count; i++) {
        (*array)[i] = current->data;
        current = current->next;
    }
    return true;
}
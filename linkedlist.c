#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ll_push(node_t **head, double data) {
    if (head == NULL) {
        return false;
    }
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return false;
    }

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    return true;
}

bool ll_pop(node_t **head, double *result_data) {
    if (head == NULL || *head == NULL) {
        return false;
    }
    node_t *temp = *head;
    if (result_data != NULL) {
        *result_data = temp->data;
    }
    *head = temp->next;
    free(temp);
    return true;
}

bool ll_insert_at(node_t **head, double data, int index) {
    if (head == NULL || index < 1) {
        return false;
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return false;
    }
    new_node->data = data;

    if (index == 1) {
        new_node->next = *head;
        *head = new_node;
        return true;
    }

    node_t *current = *head;
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
    current->next = new_node;
    return true;
}

bool ll_insert_at_end(node_t **head, double data) {
    if (head == NULL) {
        return false;
    }

    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return false;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return true;
    }

    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return true;
}

bool ll_remove_at_end(node_t **head, double *result_data) {
    if (head == NULL || *head == NULL) {
        return false;
    }
    node_t *current = *head;

    if (current->next == NULL) {
        if (result_data != NULL) {
            *result_data = current->data;
        }
        free(current);
        *head = NULL;
        return true;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    node_t *last = current->next;
    if (result_data != NULL) {
        *result_data = last->data;
    }

    free(last);
    current->next = NULL;
    return true;
}

bool ll_remove_at(node_t **head, int index, double *result_data) {
    if (head == NULL || index < 1) {
        return false;
    }

    if (index == 1) {
        return ll_pop(head, result_data);
    }

    if (*head == NULL) {
        return false;
    }

    node_t *current = *head;
    for (int i = 1; i < index - 1; i++) {
        if (current->next == NULL) {
            return false;
        }
        current = current->next;
    }
    node_t *to_remove = current->next;
    if (to_remove == NULL) {
        return false;
    }
    if (result_data != NULL) {
        *result_data = to_remove->data;
    }
    current->next = to_remove->next;
    free(to_remove);

    return true;
}

bool ll_search(node_t **head, double data, node_t **result_node) {
    if (head == NULL) {
        return false;
    }
    node_t *current = *head;
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

bool ll_clear(node_t **head) {
    if (head == NULL) {
        return false;
    }
    node_t *current = *head;
    node_t *previous = *head;
    while (*head != NULL) {

    }

}

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void) {
    node_t *head = NULL;
    double data;
    node_t *found_node = NULL;

    ll_insert_at_end(&head, 67);
    ll_push(&head, 1.0);
    ll_push(&head, 2.0);
    ll_push(&head, 3.0);
    ll_push(&head, 4.0);
    ll_insert_at(&head, 5.0, 3);

    printf("\n");
    ll_search(&head, 2, &found_node);

    if (ll_search(&head, 5, &found_node)) {
        printf("SEARCH: %f\n", found_node->data);
    }

    if (ll_remove_at_end(&head, &data)) {
        printf("REMOVED %f\n", data);
    }

    while (ll_pop(&head, &data)) {
        printf("POPPED: %f\n", data);
    }

    return 0;
}

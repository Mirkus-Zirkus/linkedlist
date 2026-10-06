#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void) {
    node_t *head = NULL;
    push(&head, 1.0);
    push(&head, 2.0);
    push(&head, 3.0);
    push(&head, 4.0);
    insert_at(&head, 5.0, 3);
    insert_at_end(&head, 67);

    printf("SEARCH: %f\n", search(&head, 5)->data);;
    printf("REMOVED %f\n", remove_at_end(&head));
    printf("POPPED: %f\n", pop(&head));
    printf("POPPED: %f\n", pop(&head));
    printf("POPPED: %f\n", pop(&head));
    printf("POPPED: %f\n", pop(&head));
    printf("POPPED: %f\n", pop(&head));
    printf("POPPED: %f\n", pop(&head));
    printf("POPPED: %f\n", pop(&head));

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "DoubleLinkedList/double_linkedlist.h"
#include "LinkedList/linkedlist.h"

void print_list(node_t *head) {
    node_t *current = head;
    printf("Singly Liste: ");
    while (current != NULL) {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_dll_list(dll_node_t *head) {
    dll_node_t *current = head;
    printf("Double Liste: ");
    while (current != NULL) {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    //TEST DER EINFACHEN LINKED LIST
    node_t *head = NULL;
    double val = 0.0;

    printf("=== VALIDIERUNG: SINGLY LINKED LIST ===\n");
    printf("Fuege 10.50 am Anfang ein:\n");
    ll_push(&head, 10.5);
    print_list(head);

    printf("Fuege 20.75 am Ende ein:\n");
    ll_insert_at_end(&head, 20.75);
    print_list(head);

    printf("Loesche Element am Ende:\n");
    ll_remove_at_end(&head, &val);
    printf("Geloeschter Wert: %.2f\n", val);
    print_list(head);

    ll_clear(&head);
    printf("\n");


    // TEST DER DOUBLE LINKED LIST
    dll_node_t *dll_head = NULL;

    printf("=== VALIDIERUNG: DOUBLE LINKED LIST ===\n");

    printf("Fuege 10.50 am Ende ein:\n");
    dll_insert_at_end(&dll_head, 10.5);
    print_dll_list(dll_head);

    printf("Fuege 20.75 am Ende ein:\n");
    dll_insert_at_end(&dll_head, 20.75);
    print_dll_list(dll_head);

    printf("Loesche Element an Index 1 (entfernen von hinten):\n");
    dll_remove_at_end(&dll_head, &val);
    printf("Geloeschter Wert: %.2f\n", val);
    print_dll_list(dll_head);

    dll_clear(&dll_head);
    printf("\n");


    // 3. PERFORMANCE-BENCHMARK (VERGLEICH)

    printf("=== PERFORMANCE-BENCHMARK ===\n");

    int N = 10000;
    clock_t start, end;
    double cpu_time;

    start = clock();
    for (int i = 0; i < N; i++) {
        ll_insert_at_end(&head, (double)i);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Singly - Einfuegen am Ende (%d Elemente): %.4f Sekunden\n", N, cpu_time);

    start = clock();
    for (int i = 0; i < N; i++) {
        dll_insert_at_end(&dll_head, (double)i);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Double - Einfuegen am Ende (%d Elemente): %.4f Sekunden\n", N, cpu_time);

    ll_clear(&head);
    dll_clear(&dll_head);

    return 0;
}
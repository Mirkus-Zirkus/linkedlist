#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

void print_list(node_t *head) {
    node_t *current = head;
    printf("Liste: ");
    while (current != NULL) {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node_t *head = NULL;
    double val = 0.0;

    // Validirung
    printf("VALIDIERUNG \n");

    printf("Fuege 10.50 am Anfang ein:\n");
    ll_push(&head, 10.5);
    print_list(head);

    printf("Fuege 20.75 am Ende ein:\n");
    ll_insert_at_end(&head, 20.75);
    print_list(head);

    printf("Fuege 15.00 an Index 2 ein:\n");
    ll_insert_at(&head, 15.0, 2);
    print_list(head);

    printf("Loesche Element an Index 2:\n");
    ll_remove_at(&head, 2, &val);
    printf("Geloeschter Wert: %.2f\n", val);
    print_list(head);

    while (head != NULL) {
        ll_pop(&head, &val);
    }
    printf("\n");

    // Perfomance-Benchmark
    printf("PERFORMANCE-BENCHMARK\n");

    int N = 10000; // Anzahl der Durchläufe
    clock_t start, end;
    double cpu_time;

    start = clock();
    for (int i = 0; i < N; i++) {
        ll_push(&head, (double)i);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Einfuegen am Anfang (%d Elemente): %.4f Sekunden\n", N, cpu_time);

    while (head != NULL) {
        ll_pop(&head, &val);
    }

    start = clock();
    for (int i = 0; i < N; i++) {
        ll_insert_at_end(&head, (double)i);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Einfuegen am Ende (%d Elemente): %.4f Sekunden\n", N, cpu_time);

    node_t *result = NULL;
    start = clock();
    for (int i = 0; i < N; i++) {
        ll_search(&head, (double)(N / 2), &result);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Suchen (%d Durchlaeufe): %.4f Sekunden\n", N, cpu_time);

    start = clock();
    for (int i = 0; i < N; i++) {
        ll_remove_at_end(&head, &val);
    }
    end = clock();
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Von hinten entfernen (%d Elemente): %.4f Sekunden\n", N, cpu_time);

    return 0;
}
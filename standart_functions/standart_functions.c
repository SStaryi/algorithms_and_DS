//
// Created by Artyom on 15.10.2023.
//

#include "standart_functions.h"

void swap(void *a, void *b, int size) {
    char *pa = a;
    char *pb = b;
    for (int i = 0; i < size; i++, pa++, pb++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
    }
}

void generate_random_array(int *array, const size_t size) {
    srand(time(0));

    for (size_t i = 0; i < size; i++)
        array[i] = rand() % 10000;
}

bool is_ordered(int *array, size_t size) {
    for (size_t i = 1; i < size; i++)
        if (array[i] < array[i - 1])
            return false;

    return true;
}


void output_array(int *array, size_t size) {
    printf("[");

    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);

        if (i < size - 1)
            printf(", ");
    }

    printf("]\n");
}

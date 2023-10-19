//
// Created by Artyom on 19.10.2023.
//

#include "test_searches.h"

void test_linear_search() {
    printf("Linear search test...\n");

    // Генерация рандомного массива из остатков от деления рандомного числа на 100
    size_t size = 30;
    long long *arr1 = (long long *) malloc(sizeof(long long) * size);
    generate_random_array(arr1, size);

    // Остаток не может быть отрицательным
    assert(linear_search(arr1, size, -1) == -1);
    free(arr1);
    printf("TEST 1 OK!\n");

    long long arr2[] = {88, 72, 95, 56, 1, 45, 95, 27, 6, 96,
                        95, 27, 92, 9, 66, 28, 87, 61, 40,
                        84, 76, 81, 35, 80, 49, 75, 29, 90,
                        74, 5};

    assert(linear_search(arr2, size, 1) == 4);
    printf("TEST 2 OK!\n");

    printf("\n");
}

void test_fast_linear_search() {
    printf("Fast linear search test...\n");

    // Генерация рандомного массива из остатков от деления рандомного числа на 100
    size_t size = 30;
    long long *arr1 = (long long *) malloc(sizeof(long long) * size);
    generate_random_array(arr1, size);

    // Остаток не может быть отрицательным
    assert(fast_linear_search(arr1, size, -1) == -1);
    free(arr1);
    printf("TEST 1 OK!\n");

    long long arr2[] = {88, 72, 95, 56, 1, 45, 95, 27, 6, 96,
                        95, 27, 92, 9, 66, 28, 87, 61, 40,
                        84, 76, 81, 35, 80, 49, 75, 29, 90,
                        74, 5};

    assert(fast_linear_search(arr2, size, 1) == 4);
    printf("TEST 2 OK!\n");

    printf("\n");
}

void test_binary_search() {
    printf("Binary search test...\n");

    // Генерация рандомного массива из остатков от деления рандомного числа на 100
    size_t size = 30;
    int *arr1 = (int *) malloc(sizeof(int) * size);
    generate_random_array(arr1, size);
    output_array(arr1, size);
    qsort(arr1, size, sizeof(long long), compare_ints);
    output_array(arr1, size);
    printf("%d\n", is_ordered(arr1, size));
    // Остаток не может быть отрицательным
    assert(binary_search(arr1, size, -1) == -1);
    free(arr1);
    printf("TEST 1 OK!\n");

    long long arr2[] = {88, 72, 95, 56, 1, 45, 95, 27, 6, 96,
                        95, 27, 92, 9, 66, 28, 87, 61, 40,
                        84, 76, 81, 35, 80, 49, 75, 29, 90,
                        74, 5};

    qsort(arr2, size, sizeof(long long), compare_ints);

    assert(binary_search(arr2, size, 1) == 0);
    printf("TEST 2 OK!\n");

    printf("\n");
}

void test_block_search() {
    printf("Block search test...\n");

    // Генерация рандомного массива из остатков от деления рандомного числа на 100
    size_t size = 30;
    long long *arr1 = (long long *) malloc(sizeof(long long) * size);
    generate_random_array(arr1, size);
    qsort(arr1, size, sizeof(long long), compare_ints);

    // Остаток не может быть отрицательным
    assert(block_search(arr1, size, -1) == -1);
    free(arr1);
    printf("TEST 1 OK!\n");

    long long arr2[] = {88, 72, 95, 56, 1, 45, 95, 27, 6, 96,
                        95, 27, 92, 9, 66, 28, 87, 61, 40,
                        84, 76, 81, 35, 80, 49, 75, 29, 90,
                        74, 5};

    qsort(arr2, size, sizeof(long long), compare_ints);

    assert(block_search(arr2, size, 1) == 0);
    printf("TEST 2 OK!\n");

    printf("\n");
}
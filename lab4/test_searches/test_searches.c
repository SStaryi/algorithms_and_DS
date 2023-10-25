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

void test_fast_linear_search_for_a_sorted_array() {
    printf("Fast linear search for a sorted array test...\n");

    size_t size = 30;
    long long arr1[] = {1, 2, 3, 5, 7, 8, 10, 12, 14, 15,
                        16, 17, 18, 20, 21, 22, 23, 24,
                        25, 26, 27, 28, 29, 30, 31, 32,
                        33, 34, 35, 36};

    assert(fast_linear_search_for_a_sorted_array(arr1, size, -1) == -1);

    printf("TEST 1 OK!\n");

    long long arr2[] = {1, 5, 6, 9, 27, 27, 28, 29, 35,
                        40, 45, 49, 56, 61, 66, 72, 74,
                        75, 76, 80, 81, 84, 87, 88, 90,
                        92, 95, 95, 95, 96};

    assert(fast_linear_search_for_a_sorted_array(arr2, size, 1) == 0);
    printf("TEST 2 OK!\n");

    printf("\n");
}

void test_binary_search() {
    printf("Binary search test...\n");

    size_t size = 30;
    long long arr1[] = {1, 2, 3, 5, 7, 8, 10, 12, 14, 15,
                        16, 17, 18, 20, 21, 22, 23, 24,
                        25, 26, 27, 28, 29, 30, 31, 32,
                        33, 34, 35, 36};

    assert(binary_search(arr1, size, -1) == -1);

    printf("TEST 1 OK!\n");

    long long arr2[] = {1, 5, 6, 9, 27, 27, 28, 29, 35,
                        40, 45, 49, 56, 61, 66, 72, 74,
                        75, 76, 80, 81, 84, 87, 88, 90,
                        92, 95, 95, 95, 96};

    assert(binary_search(arr2, size, 1) == 0);
    printf("TEST 2 OK!\n");

    printf("\n");
}

void test_block_search() {
    printf("Block search test...\n");

    size_t size = 30;
    long long arr1[] = {1, 2, 3, 5, 7, 8, 10, 12, 14, 15,
                        16, 17, 18, 20, 21, 22, 23, 24,
                        25, 26, 27, 28, 29, 30, 31, 32,
                        33, 34, 35, 36};

    assert(block_search(arr1, size, -1) == -1);

    printf("TEST 1 OK!\n");

    long long arr2[] = {1, 5, 6, 9, 27, 27, 28, 29, 35,
                        40, 45, 49, 56, 61, 66, 72, 74,
                        75, 76, 80, 81, 84, 87, 88, 90,
                        92, 95, 95, 95, 96};

    assert(block_search(arr2, size, 1) == 0);
    printf("TEST 2 OK!\n");

    printf("\n");
}
//
// Created by Artyom on 19.10.2023.
//

#include "searches_for_tcf.h"

long long linear_search_for_tcf(const long long const *arr, const size_t size, const long long x) {
    long long number_of_comparisons = 0;

    for (long long i = 0; i < size; i++) {
        number_of_comparisons += 2;

        if (arr[i] == x)
            return number_of_comparisons;
    }

    return number_of_comparisons + 1;
}

long long fast_linear_search_for_tcf(long long *arr, const size_t size, const long long x) {
    long long new_size = size + 1;
    realloc(arr, new_size * sizeof(long long));

    long long i = 0;
    long long number_of_comparisons = 1;

    while (arr[i] != x) {
        number_of_comparisons++;
        i++;
    }

    return number_of_comparisons + 1;
}

long long binary_search_in_a_subarray_for_tcf(long long *arr, long long left, long long right,
                                              const long long x) {
    long long max_index = right;
    long long number_of_comparisons = 1;

    while (right - left > 1) {
        long long middle = left + (right - left) / 2;

        number_of_comparisons += 2;

        if (arr[middle] > x)
            right = middle;
        else
            left = middle;
    }

    return number_of_comparisons + 1;
}

long long binary_search_for_tcf(long long *arr, const size_t size, const long long x) {
    return binary_search_in_a_subarray_for_tcf(arr, -1, size, x);
}

long long block_search_for_tcf(long long *arr, const size_t size, const long long x) {
    long long number_of_comparisons = 1;

    if (arr[0] > x)
        return number_of_comparisons;

    long long block = sqrt(size);
    long long i = 0;

    number_of_comparisons++;

    while (i < size) {
        number_of_comparisons += 2;

        if (arr[i] > x) {
            break;
        }

        i += block;
    }

    return number_of_comparisons + binary_search_in_a_subarray_for_tcf(arr, i - block - 1, i, x);
}
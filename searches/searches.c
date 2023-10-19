//
// Created by Artyom on 19.10.2023.
//

#include "searches.h"

long long linear_search(const long long const *arr, const size_t size, const long long x) {
    for (long long i = 0; i < size; i++)
        if (arr[i] == x)
            return i;

    return -1;
}

long long fast_linear_search(long long *arr, const size_t size, const long long x) {
    arr[size] = x;

    long long i = 0;

    while (arr[i] != x)
        i++;

    return i != size ? i : -1;
}

long long binary_search_in_a_subarray(long long *arr, long long left, long long right,
                                      const long long x) {
    long long max_index = right;

    while (right - left > 1) {
        long long middle = left + (right - left) / 2;

        if (arr[middle] > x)
            right = middle;
        else
            left = middle;
    }

    return right != max_index ? right : -1;
}

long long binary_search(long long *arr, const size_t size, const long long x) {
    return binary_search_in_a_subarray(arr, -1, size, x);
}

long long block_search(long long *arr, const size_t size, const long long x) {
    if (arr[0] > x)
        return -1;

    long long block = sqrt(size);
    long long i = 0;

    while (i < size) {
        if (arr[i] > x)
            break;

        i += block;
    }

    return binary_search_in_a_subarray(arr, i - block - 1, i, x);
}
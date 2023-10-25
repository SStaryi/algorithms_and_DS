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

long long fast_linear_search_for_a_sorted_array(long long *arr, const size_t size, const long long x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x)
            return i;

        if (arr[i] > x)
            return -1;
    }

    return -1;
}

long long binary_search_in_a_subarray(long long *arr, long long left, long long right,
                                      const long long x) {
    if (right >= left) {
        long long mid = left + (right - left) / 2;

        // Если элемент находится в середине
        if (arr[mid] == x)
            return mid;

        // Если элемент меньше, чем mid, то он может быть только в левом подмассиве
        if (arr[mid] > x)
            return binary_search_in_a_subarray(arr, left, mid - 1, x);

        // В противном случае элемент может быть только в правом подмассиве
        return binary_search_in_a_subarray(arr, mid + 1, right, x);
    }

    // Возвращаем -1, если элемент не найден
    return -1;
}

long long binary_search(long long *arr, const size_t size, const long long x) {
    return binary_search_in_a_subarray(arr, 0, size - 1, x);
}

long long block_search(long long *arr, const size_t size, const long long x) {
    // Вычисляем размер блока для поиска
    long long block_size = sqrt(size);

    // Находим блок, в котором находится искомый элемент
    long long i;
    for (i = 0; i < size; i += block_size)
        if (arr[i] > x)
            break;

    // Выполняем линейный поиск в найденном блоке
    for (long long j = i - block_size; j < i; ++j)
        if (arr[j] == x)
            return j;

    // Возвращаем -1, если элемент не найден
    return -1;
}
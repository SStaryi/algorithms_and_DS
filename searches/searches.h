//
// Created by Artyom on 19.10.2023.
//

#ifndef ALGORITMS_AND_DS_SEARCHES_H
#define ALGORITMS_AND_DS_SEARCHES_H

#include <stdio.h>
#include <math.h>

// Линейный поиск элемента x в массиве arr размера size
long long linear_search(const long long const *arr, const size_t size, const long long x);

// Быстрый линейный поиск элемента x в массиве arr размера size
long long fast_linear_search(long long *arr, const size_t size, const long long x);

// Бинарный поиск элемента x в подмассиве массива arr от элемента arr[left] до элемента arr[right].
// Подмассив должен быть упорядочен
long long binary_search_in_a_subarray(long long *arr, long long left, long long right,
                                      const long long x);

// Бинарный поиск элемента x в массиве arr размера size. Массив должке быть упорядочен
long long binary_search(long long *arr, const size_t size, const long long x);

// Блочный поиск элемента x в массиве arr размера size. Массив должен быть отсортирован
long long block_search(long long *arr, const size_t size, const long long x);

#endif //ALGORITMS_AND_DS_SEARCHES_H

//
// Created by Artyom on 19.10.2023.
//

#ifndef ALGORITMS_AND_DS_SEARCHES_FOR_TCF_H
#define ALGORITMS_AND_DS_SEARCHES_FOR_TCF_H

#include <stdio.h>
#include <malloc.h>
#include <math.h>

// Возвращает количество операций сравнения проведённых в функции linear_search
long long linear_search_for_tcf(const long long const *arr, const size_t size, const long long x);

// Возвращает количество операций сравнения проведённых в функции fast_linear_search
long long fast_linear_search_for_tcf(long long *arr, const size_t size, const long long x);

// Возвращает количество операций сравнения проведённых в функции binary_search_in_a_subarray
long long binary_search_in_a_subarray_for_tcf(long long *arr, long long left, long long right,
                                              const long long x);

// Возвращает количество операций сравнения проведённых в функции binary_search
long long binary_search_for_tcf(long long *arr, const size_t size, const long long x);

// Возвращает количество операций сравнения проведённых в функции block_search
long long block_search_for_tcf(long long *arr, const size_t size, const long long x);

#endif //ALGORITMS_AND_DS_SEARCHES_FOR_TCF_H

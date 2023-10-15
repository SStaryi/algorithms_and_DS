//
// Created by Artyom on 15.10.2023.
//

#ifndef ALGORITMS_AND_DS_SORTS_H
#define ALGORITMS_AND_DS_SORTS_H

#include <stdbool.h>

#include "../standart_functions/standart_functions.h"

/* функция сортировки включением  */
long long sis(int A[], int nn);

/*функция сортировки выбором  */
long long str_sel(int A[], int nn);

/*  функция сортировки обменом  */
long long bbl_sort(int A[], int nn);

/* функция улучшенной сортировки обменом 1 */
long long bbl_sort1(int arr[], int n);

/* функция улучшенной сортировки обменом 2 */
long long bbl_sort2(int arr[], int n);

// Функция для сортировки массива методом Шелла
long long shell_sort(int arr[], int n);

/* функция сортировки Хоара (быстрая сортировка) */
long long hoar_sort(int arr[], int high);

/* пирамидальная функция сортировки  */
long long heap_sort(int A[], int nn);

#endif //ALGORITMS_AND_DS_SORTS_H

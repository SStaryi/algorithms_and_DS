//
// Created by Artyom on 15.10.2023.
//

#ifndef ALGORITMS_AND_DS_STANDART_FUNCTIONS_H
#define ALGORITMS_AND_DS_STANDART_FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Функция для обмена двух элементов массива
void swap(void *a, void *b, int size);

// Функция генерации рандомного массива размера size
void generate_random_array(int *array, const size_t size);

// Возвращает 'истину', если массив отсортирован, иначе -- 'ложь'
bool is_ordered(int *array, size_t size);

// Выводит массив array размера size
void output_array(int *array, size_t size);

#endif //ALGORITMS_AND_DS_STANDART_FUNCTIONS_H

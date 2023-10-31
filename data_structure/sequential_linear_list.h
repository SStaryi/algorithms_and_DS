// sequential_linear_list.h
#ifndef SEQUENTIAL_LINEAR_LIST_H
#define SEQUENTIAL_LINEAR_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef long long base_type; // Замените на нужный тип данных

typedef struct {
    base_type *array; // Массив для хранения элементов списка
    size_t size; // Текущий размер списка
    size_t capacity; // Текущая вместимость списка
    size_t ptr; // Указатель на текущий элемент
} SequentialLinearList;

const short list_ok = 0;
const short list_not_mem = 1; // Ошибка выделения памяти
const short list_under = 2;
const short list_eEnd = 3;
short list_error;

// Создает новый список с заданной начальной вместимостью.
SequentialLinearList *create_list(size_t initial_capacity);

// Удаляет список и освобождает выделенную под него память.
void delete_list(SequentialLinearList *list);

// Вставляет элемент в указанную позицию.
void insert(SequentialLinearList *list, base_type element, size_t position);

// Удаляет элемент из указанной позиции.
void erase(SequentialLinearList *list, size_t position);

// Возвращает элемент из указанной позиции.
base_type get(SequentialLinearList *list, size_t position);

// Перемещает указатель на n позиций (может быть отрицательным).
void move_ptr(SequentialLinearList *list, base_type n);

// Перемещает указатель на указанную позицию.
void move_to(SequentialLinearList *list, size_t position);

// Возвращает количество элементов в списке.
size_t count(SequentialLinearList *list);

// Проверяет, является ли список полным.
bool full_list(SequentialLinearList *list);

// Проверяет, является ли текущий элемент последним в списке.
bool end_list(SequentialLinearList *list);

// Копирует все элементы из списка src в список dest
void copy_list(SequentialLinearList *dest, SequentialLinearList *src);

#endif // SEQUENTIAL_LINEAR_LIST_H

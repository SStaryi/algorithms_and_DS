// sequential_linear_list.h
#ifndef SEQUENTIAL_LINEAR_LIST_H
#define SEQUENTIAL_LINEAR_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

typedef long long base_type; // Замените на нужный тип данных

typedef struct SequentialLinearList {
    base_type *array; // Массив для хранения элементов списка
    size_t size; // Текущий размер списка
    size_t capacity; // Текущая вместимость списка
    size_t ptr; // Указатель на текущий элемент
} SequentialLinearList;

extern const short list_ok;
extern const short list_not_mem; // Ошибка выделения памяти
extern const short list_under;
extern const short list_end;
extern short list_error;

// Создает новый список с заданной начальной вместимостью.
SequentialLinearList *create_list(size_t initial_capacity);

// Удаляет список и освобождает выделенную под него память.
void delete_list(SequentialLinearList *list);

// Вставляет элемент в указанную позицию.
void insert(SequentialLinearList *list, base_type element, size_t position);

// Удаляет элемент из указанной позиции.
void erase(SequentialLinearList *list, size_t position);

// Функция для инициализации списка значениями из массива
void init_list(SequentialLinearList *list, base_type *array, size_t size);

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

// Заполняет список элементами, введенными пользователем
void input_list(SequentialLinearList *list);

// Выводит все элементы списка
void output_list(SequentialLinearList *list);

#endif // SEQUENTIAL_LINEAR_LIST_H

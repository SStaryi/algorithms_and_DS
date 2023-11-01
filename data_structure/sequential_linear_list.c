//
// Created by Artyom on 31.10.2023.
//

#include "sequential_linear_list.h"

SequentialLinearList *create_list(size_t initial_capacity) {
    SequentialLinearList *list = (SequentialLinearList *) malloc(sizeof(SequentialLinearList));

    if (list == NULL) {
        //Ошибка выделения памяти для списка
        list_error = list_not_mem;

        return NULL;
    }

    list->array = (base_type *) malloc(initial_capacity * sizeof(base_type));

    if (list->array == NULL) {
        // Ошибка выделения памяти для массива
        free(list);
        list_error = list_not_mem;

        return NULL;
    }

    list->size = 0;
    list->capacity = initial_capacity;
    list->ptr = 0; // Устанавливаем указатель на начало списка
    list_error = list_ok;

    return list;
}

void delete_list(SequentialLinearList *list) {
    free(list->array);
    free(list);
}

void insert(SequentialLinearList *list, base_type element, size_t position) {
    if (position > list->size) {
        // Позиция вставки выходит за пределы списка
        list_error = list_under;

        return;
    }

    if (list->size == list->capacity) {
        list->capacity *= 2;
        base_type *newArray = (base_type *) realloc(list->array, list->capacity *
                                                                 sizeof(base_type));

        if (newArray == NULL) {
            // Ошибка выделения памяти для расширения списка
            list_error = list_not_mem;

            return;
        }

        list->array = newArray;
    }

    for (size_t i = list->size; i > position; --i)
        list->array[i] = list->array[i - 1];

    list->array[position] = element;
    ++list->size;

    if (position <= list->ptr)
        ++list->ptr; // Обновляем указатель, если вставка была перед ним

    list_error = list_ok;
}

void erase(SequentialLinearList *list, size_t position) {
    if (position >= list->size) {
        // Позиция удаления выходит за пределы списка
        list_error = list_under;

        return;
    }

    for (size_t i = position; i < list->size - 1; ++i)
        list->array[i] = list->array[i + 1];

    --list->size;

    if (position < list->ptr)
        --list->ptr; // Обновляем указатель, если удаление было перед ним

    list_error = list_ok;
}

void init_list(SequentialLinearList *list, base_type *array, size_t size) {
    // Удаляем все текущие элементы из списка
    while (list->size > 0) {
        erase(list, 0);

        if (list_error != list_ok) {
            list_error = list_under;

            return;
        }
    }

    // Добавляем элементы из массива в список
    for (size_t i = 0; i < size; i++) {
        insert(list, array[i], i);

        if (list_error != list_ok) {
            list_error = list_not_mem;

            return;
        }
    }

    list_error = list_ok;
}

base_type get(SequentialLinearList *list, size_t position) {
    if (position >= list->size) {
        // Позиция получения выходит за пределы списка
        list_error = list_under;

        return list_error;
    }

    list_error = list_ok;

    return list->array[position];
}

void move_ptr(SequentialLinearList *list, base_type n) {
    base_type new_position = (base_type) list->ptr + n; // Вычисляем новую позицию указателя

    if (new_position < 0 || new_position >= (int) list->size) {
        // Новая позиция указателя выходит за пределы списка
        list_error = list_under;

        return;
    }

    list->ptr = (size_t) new_position;
    list_error = list_ok;
}

void move_to(SequentialLinearList *list, size_t position) {
    if (position >= list->size) {
        // Позиция перемещения указателя выходит за пределы списка
        list_error = list_under;

        return;
    }

    list->ptr = position;
    list_error = list_ok;
}

size_t count(SequentialLinearList *list) {
    return list->size;
}

bool full_list(SequentialLinearList *list) {
    return list->size == list->capacity ? 1 : 0;
}

bool end_list(SequentialLinearList *list) {
    return list->ptr == list->size - 1 ? 1 : 0;
}

void copy_list(SequentialLinearList *dest, SequentialLinearList *src) {
    if (dest->capacity < src->size) {
        base_type *new_array = (base_type *) realloc(dest->array, src->size *
                                                                  sizeof(base_type));

        if (new_array == NULL) {
            // Ошибка выделения памяти для копирования списка
            list_error = list_not_mem;

            return;
        }

        dest->array = new_array;
        dest->capacity = src->size;
    }

    for (size_t i = 0; i < src->size; ++i)
        dest->array[i] = src->array[i];

    dest->size = src->size;
    dest->ptr = src->ptr;
    list_error = list_ok;
}

void input_list(SequentialLinearList *list) {
    if (list == NULL) {
        // Список не существует
        list_error = list_under;

        return;
    }

    size_t size = list->size;

    base_type *array = (base_type *) malloc(size * sizeof(base_type));

    if (array == NULL) {
        // Ошибка выделения памяти
        list_error = list_not_mem;

        return;
    }

    // Ввод элементов
    for (size_t i = 0; i < size; i++)
        scanf("%lld", &array[i]);

    init_list(list, array, size);

    if (list_error != list_ok) {
        free(array);

        return;
    }

    free(array);
    list_error = list_ok;
}

void output_list(SequentialLinearList *list) {
    if (list == NULL) {
        // Список не существует
        list_error = list_under;

        return;
    }

    if (list->size == 0) {
        // Список пуст
        list_error = list_under;

        return;
    }

    // Элементы списка
    for (size_t i = 0; i < list->size; i++)
        printf("%lld ", list->array[i]);

    printf("\n");

    list_error = list_ok;
}

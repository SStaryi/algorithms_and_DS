#include "table.h"

int table_error = 0;

void init_table(Table *t, unsigned size_mem, unsigned size_el) {
    // Инициализация таблицы
    t = (Table *) malloc(size_mem * sizeof(Table));

    if (t == NULL) {
        table_error = TABLE_NOT_MEM;

        return;
    }

    // Инициализация каждого элемента в таблице
    for (unsigned i = 0; i < size_mem; i++) {
        t[i] = (Node *) malloc(size_el * sizeof(Node));

        if (t[i] == NULL) {
            table_error = TABLE_NOT_MEM;

            return;
        }
    }

    table_error = TABLE_OK;
}

int empty_table(Table *t) {
    // Проверка, является ли указатель на таблицу NULL
    if (t == NULL)
        return 1;

    // Проверка, является ли корень дерева NULL
    if (*t == NULL)
        return 1;

    // В противном случае таблица не пуста
    return 0;
}

int put_table(Table *t, void *e, T_Key key, func f) {
    // Проверка, является ли указатель на таблицу NULL
    if (t == NULL)
        return 1;

    // Создание нового узла с данными e
    Node *new_node = create_node((base_type) e);

    // Проверка, был ли узел успешно создан
    if (new_node == NULL)
        return 1;

    // Если таблица пуста, вставляем новый узел в качестве корня
    if (*t == NULL) {
        *t = new_node;

        return 0;
    }

    // В противном случае используем функцию f для определения позиции вставки
    Node *current = *t;

    while (current != NULL)
        if (f((void *) &current->data, e) <= 0) {
            if (current->next == NULL) {
                current->next = new_node;

                return 0;
            }

            current = current->next;
        } else {
            new_node->next = current->next;
            current->next = new_node;

            return 0;
        }

    // В случае ошибки возвращаем 1
    return 1;
}

int get_table(Table *t, void *e, T_Key key, func f) {
    // Проверка, является ли указатель на таблицу NULL
    if (t == NULL)
        return 1;

    // Поиск элемента с ключом key
    Node *current = *t;

    while (current != NULL) {
        if (!f((void *) &current->data, &key)) {
            // Если элемент найден, копируем его в e и возвращаем 0
            *(base_type *) e = current->data;

            return 0;
        }

        current = current->next;
    }

    // Если элемент не найден, возвращаем 1
    return 1;
}

int read_table(Table *t, void *e, T_Key key, func f) {
    // Проверка, является ли указатель на таблицу NULL
    if (t == NULL)
        return 1;

    // Поиск элемента с ключом key
    Node *current = *t;

    while (current != NULL) {
        if (!f((void *) &current->data, &key)) {
            // Если элемент найден, копируем его в e и возвращаем 0
            *(base_type *) e = current->data;

            return 0;
        }

        current = current->next;
    }

    // Если элемент не найден, возвращаем 1
    return 1;
}

int write_table(Table *t, void *e, T_Key key, func f) {
    // Проверка, является ли указатель на таблицу NULL
    if (t == NULL)
        return 1;

    // Поиск элемента с ключом key
    Node *current = *t;

    while (current != NULL) {
        if (!f((void *) &current->data, &key)) {
            // Если элемент найден, заменяем его значение на e и возвращаем 0
            current->data = *(base_type *) e;

            return 0;
        }

        current = current->next;
    }

    // Если элемент не найден, возвращаем 1
    return 1;
}

void done_table(Table *t) {
    // Проверка, является ли указатель на таблицу NULL
    if (t == NULL)
        return;

    // Освобождение памяти, занятой каждым узлом в таблице
    Node *current = *t;

    while (current != NULL) {
        Node *next = current->next;

        free(current);
        current = next;
    }

    // Установка указателя на таблицу в NULL
    *t = NULL;
}

// singly_linked_list.h
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long base_type; // Замените на нужный тип данных

typedef struct Node {
    base_type data; // Данные для хранения в узле
    struct Node *next; // Указатель на следующий узел
} Node;

extern const short list_ok_singly;
extern const short list_not_mem_singly; // Ошибка выделения памяти
extern const short list_under_singly;
extern const short list_end_singly;
extern short list_error_singly;

// Создает новый узел с заданными данными и возвращает указатель на него.
Node *create_node(base_type data);

// Вставляет новый узел с заданными данными в конец списка.
void insert_singly(Node **head, base_type data);

// Удаляет первый узел с заданными данными из списка.
void delete(Node **head, base_type data);

// Возвращает указатель на первый узел с заданными данными.
Node *find(Node *head, base_type data);

// Выводит все элементы списка.
void print_list(Node *head);

#endif // SINGLY_LINKED_LIST_H
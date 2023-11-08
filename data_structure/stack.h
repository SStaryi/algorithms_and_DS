// stack.h
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "singly_linked_list.h"

typedef struct Stack {
    Node *top; // Указатель на вершину стека
} Stack;

extern const short list_ok_stack;
extern const short list_not_mem_stack; // Ошибка выделения памяти
extern const short list_under_stack;
extern short list_error_stack;

// Создает новый стек и возвращает указатель на него.
Stack *init_stack();

// Добавляет элемент на вершину стека.
void put_stack(Stack *stack, base_type data);

// Удаляет элемент с вершины стека и возвращает его.
base_type get_stack(Stack *stack);

// Возвращает элемент с вершины стека без его удаления.
base_type read_stack(Stack *stack);

// Проверяет, пуст ли стек.
bool empty_stack(Stack *stack);

// Удаляет стек и освобождает выделенную под него память.
void done_stack(Stack *stack);

#endif // STACK_H
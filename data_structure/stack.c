// stack.c

#include "stack.h"

const short list_ok_stack = 0;
const short list_not_mem_stack = 1; // Ошибка выделения памяти
const short list_under_stack = 2;
short list_error_stack = -1;

Stack *init_stack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));

    if (stack == NULL) {
        // Ошибка выделения памяти
        list_error_stack = list_not_mem_stack;

        return NULL;
    }

    stack->top = NULL;
    list_error_stack = list_ok_stack;

    return stack;
}

void put_stack(Stack *stack, base_type data) {
    Node *new_node = create_node(data);

    if (new_node == NULL)
        // Ошибка выделения памяти
        return;

    new_node->next = stack->top;
    stack->top = new_node;
}

base_type get_stack(Stack *stack) {
    if (stack->top == NULL) {
        // Стек пуст
        list_error_stack = list_under_stack;

        return -1; // Возвращаем -1 или другое значение, которое не может быть в стеке
    }

    Node *temp = stack->top;
    base_type data = temp->data;

    stack->top = temp->next;

    free(temp);

    return data;
}

base_type read_stack(Stack *stack) {
    if (stack->top == NULL) {
        // Стек пуст
        list_error_stack = list_under_stack;

        return -1; // Возвращаем -1 или другое значение, которое не может быть в стеке
    }

    return stack->top->data;
}

bool empty_stack(Stack *stack) {
    return (stack->top == NULL);
}

void done_stack(Stack *stack) {
    Node *current = stack->top;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(stack);
}
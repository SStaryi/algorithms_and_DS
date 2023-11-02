// stack.c

#include "stack.h"

const short stack_ok = 0;
const short stack_not_mem = 1; // Ошибка выделения памяти
const short stack_under = 2;
short stack_error = -1;

Stack *init_stack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));

    if (stack == NULL) {
        // Ошибка выделения памяти
        stack_error = stack_not_mem;

        return NULL;
    }

    stack->top = NULL;
    stack_error = stack_ok;

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
        stack_error = stack_under;

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
        stack_error = stack_under;

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
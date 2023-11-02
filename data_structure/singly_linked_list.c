// singly_linked_list.c

#include "singly_linked_list.h"

const short list_ok = 0;
const short list_not_mem = 1; // Ошибка выделения памяти
const short list_under = 2;
const short list_end = 3;
short list_error = -1;

Node *create_node(base_type data) {
    Node *new_node = (Node *) malloc(sizeof(Node));

    if (new_node == NULL) {
        // Ошибка выделения памяти
        list_error = list_not_mem;

        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    list_error = list_ok;

    return new_node;
}

void insert(Node **head, base_type data) {
    Node *new_node = create_node(data);

    if (new_node == NULL)
        // Ошибка выделения памяти
        return;

    if (*head == NULL) {
        *head = new_node;

        return;
    }

    Node *current = *head;

    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
}

void delete(Node **head, base_type data) {
    if (*head == NULL) {
        // Список пуст
        list_error = list_under;

        return;
    }

    Node *current = *head;
    Node *previous = NULL;

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // Элемент не найден в списке
        list_error = list_end;

        return;
    }

    if (previous == NULL)
        // Элемент находится в начале списка
        *head = current->next;
    else
        previous->next = current->next;

    free(current);
}

Node *find(Node *head, base_type data) {
    Node *current = head;

    while (current != NULL && current->data != data)
        current = current->next;

    if (current == NULL) {
        // Элемент не найден в списке
        list_error = list_end;

        return NULL;
    }

    return current;
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%lld ", current->data);

        current = current->next;
    }

    printf("\n");
}